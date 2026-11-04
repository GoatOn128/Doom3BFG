/*
===========================================================================

Doom 3 BFG Edition GPL Source Code
Copyright (C) 1993-2012 id Software LLC, a ZeniMax Media company.

This file is part of the Doom 3 BFG Edition GPL Source Code ("Doom 3 BFG Edition Source Code").

Doom 3 BFG Edition Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Doom 3 BFG Edition Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Doom 3 BFG Edition Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 BFG Edition Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning the license or the applicable additional terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#include "precompiled.h"
#pragma hdrstop

#include "tr_local.h"

#include "CinematicCin.h"

#if defined( _MSC_VER )
	#include <xaudio2.h>
	#include "../sound/XAudio2/XA2_CinematicAudio.h"
#endif

#undef nullptr
#include "libbinkdec/include/BinkDecoder.h"

extern idCVar s_noSound;
extern idCVar s_playCinematicAudio;

/*

The .cin container, the order-1 Huffman codec and the per frame audio
layout are ported from client/cl_cin.c of the Quake II 3.21 source
release (references/quake2), Copyright (C) 1997-2001 Id Software, Inc.,
licensed under the GPLv2 or later, which is compatible with this GPLv3
codebase.

*/

const float CIN_FRAMERATE			= 14.0f;		// fixed in the format
const int CIN_MAX_COMPRESSED		= 0x20000;		// same limit as the original decoder
const int CIN_HEADER_SIZE			= 20;			// width, height, s_rate, s_width, s_channels
const int CIN_HUFF_TABLE_SIZE		= 256 * 256;		// one count row per codebook row

/*
==============
idCinematicCin::idCinematicCin
==============
*/
idCinematicCin::idCinematicCin() {
	animationLength = 0;
	startTime = 0;
	frameRate = CIN_FRAMERATE;
	CIN_WIDTH = CIN_HEIGHT = 0;
	status = FMV_EOF;
	looping = false;
	iFile = NULL;
	image = NULL;
	compressed = NULL;
	samples = NULL;
	memset( palette, 0, sizeof( palette ) );
	hnodes1 = NULL;
	memset( numhnodes1, 0, sizeof( numhnodes1 ) );
	memset( h_used, 0, sizeof( h_used ) );
	memset( h_count, 0, sizeof( h_count ) );
	framePos = -1;
	hasFrame = false;
	s_rate = s_width = s_channels = 0;
	cinematicAudio = NULL;

	img = globalImages->AllocStandaloneImage( "_cinematicCin" );
	if ( img != NULL ) {
		idImageOpts opts;
		opts.format = FMT_RGBA8;
		opts.colorFormat = CFM_DEFAULT;
		opts.width = 32;
		opts.height = 32;
		opts.numLevels = 1;
		img->AllocImage( opts, TF_LINEAR, TR_REPEAT );
	}
}

/*
==============
idCinematicCin::~idCinematicCin
==============
*/
idCinematicCin::~idCinematicCin() {
	Close();

	delete img;
	img = NULL;

	if ( cinematicAudio ) {
		cinematicAudio->ShutdownAudio();
		delete cinematicAudio;
		cinematicAudio = NULL;
	}
}

/*
==============
idCinematicCin::InitFromFile
==============
*/
bool idCinematicCin::InitFromFile( const char *qpath, bool looping ) {
	byte	header[CIN_HEADER_SIZE];
	int		width, height, rate, widthBytes, channels;

	status = FMV_EOF;
	animationLength = 100000;		// the format stores no duration, so report a large one like the roq player does
	startTime = 0;
	frameRate = CIN_FRAMERATE;
	this->looping = looping;

	if ( strstr( qpath, "/" ) == NULL && strstr( qpath, "\\" ) == NULL ) {
		fileName.Format( "video/%s", qpath );
	} else {
		fileName = qpath;
	}

	iFile = fileSystem->OpenFileRead( fileName );
	if ( !iFile ) {
		return false;
	}

	if ( iFile->Read( header, CIN_HEADER_SIZE ) != CIN_HEADER_SIZE ) {
		Close();
		return false;
	}

	width		= header[0] + ( header[1] << 8 ) + ( header[2] << 16 ) + ( header[3] << 24 );
	height		= header[4] + ( header[5] << 8 ) + ( header[6] << 16 ) + ( header[7] << 24 );
	rate		= header[8] + ( header[9] << 8 ) + ( header[10] << 16 ) + ( header[11] << 24 );
	widthBytes	= header[12] + ( header[13] << 8 ) + ( header[14] << 16 ) + ( header[15] << 24 );
	channels	= header[16] + ( header[17] << 8 ) + ( header[18] << 16 ) + ( header[19] << 24 );

	if ( width < 16 || width > 2048 || height < 16 || height > 2048
		|| rate < 0 || rate > 48000
		|| ( rate > 0 && ( widthBytes < 1 || widthBytes > 2 || channels < 1 || channels > 2 ) ) ) {
		common->Warning( "idCinematicCin: bad header in '%s'", fileName.c_str() );
		Close();
		return false;
	}

	CIN_WIDTH = width;
	CIN_HEIGHT = height;
	s_rate = rate;
	s_width = widthBytes;
	s_channels = channels;

	framePos = -1;
	hasFrame = false;
	memset( palette, 0, sizeof( palette ) );

	image = (byte *)Mem_Alloc( CIN_WIDTH * CIN_HEIGHT * 4, TAG_ROQ );
	compressed = (byte *)Mem_Alloc( CIN_MAX_COMPRESSED, TAG_ROQ );
	samples = (byte *)Mem_Alloc( ( s_rate / 14 + 2 ) * 2 * 2, TAG_ROQ );

	if ( !Huff1TableInit() ) {
		Close();
		return false;
	}

	// the per frame audio chunks go through the same cinematic voice the bink player uses
	if ( s_rate > 0 && s_playCinematicAudio.GetBool() ) {
		AudioInfo cinAudioInfo;
		cinAudioInfo.sampleRate = s_rate;
		cinAudioInfo.nChannels = s_channels;
		cinAudioInfo.idealBufferSize = 0;
		cinematicAudio = new( TAG_AUDIO ) idCinematicAudio_XAudio2;
		cinematicAudio->InitAudio( &cinAudioInfo );
	}

	common->Printf( S_COLOR_GRAY "  ...cin file: " S_COLOR_WHITE "'%s'\n", fileName.c_str() );

	status = FMV_PLAY;
	ImageForTime( 0 );
	status = ( looping ) ? FMV_PLAY : FMV_IDLE;

	return true;
}

/*
==============
idCinematicCin::AnimationLength
==============
*/
int idCinematicCin::AnimationLength() {
	return animationLength;
}

/*
==============
idCinematicCin::GetStartTime
==============
*/
int idCinematicCin::GetStartTime() {
	return startTime;
}

/*
==============
idCinematicCin::ResetTime
==============
*/
void idCinematicCin::ResetTime( int time ) {
	startTime = time;
	status = FMV_PLAY;
}

/*
==============
idCinematicCin::IsPlaying
==============
*/
bool idCinematicCin::IsPlaying() const {
	return ( status == FMV_PLAY );
}

/*
==============
idCinematicCin::ExportToTGA
==============
*/
void idCinematicCin::ExportToTGA( bool skipExisting ) {
}

/*
==============
idCinematicCin::GetFrameRate
==============
*/
float idCinematicCin::GetFrameRate() const {
	return frameRate;
}

/*
==============
idCinematicCin::Close
==============
*/
void idCinematicCin::Close() {
	if ( iFile ) {
		fileSystem->CloseFile( iFile );
		iFile = NULL;
	}

	if ( image ) {
		Mem_Free( (void *)image );
		image = NULL;
	}
	if ( compressed ) {
		Mem_Free( (void *)compressed );
		compressed = NULL;
	}
	if ( samples ) {
		Mem_Free( (void *)samples );
		samples = NULL;
	}
	if ( hnodes1 ) {
		Mem_Free( (void *)hnodes1 );
		hnodes1 = NULL;
	}

	framePos = -1;
	hasFrame = false;
	status = FMV_EOF;

	fileName = "";
}

/*
==============
idCinematicCin::CinReset

Rewinds to the first frame, after the 64k huffman codebook.
==============
*/
void idCinematicCin::CinReset() {
	if ( iFile ) {
		iFile->Seek( CIN_HEADER_SIZE + CIN_HUFF_TABLE_SIZE, FS_SEEK_SET );
	}

	framePos = -1;
	hasFrame = false;

	if ( cinematicAudio ) {
		cinematicAudio->ResetAudio();
	}

	status = FMV_LOOPED;
}

/*
==============
idCinematicCin::SmallestNode1
==============
*/
int idCinematicCin::SmallestNode1( int numhnodes ) {
	int best = 99999999;
	int bestnode = -1;

	for ( int i = 0; i < numhnodes; i++ ) {
		if ( h_used[i] ) {
			continue;
		}
		if ( !h_count[i] ) {
			continue;
		}
		if ( h_count[i] < best ) {
			best = h_count[i];
			bestnode = i;
		}
	}

	if ( bestnode == -1 ) {
		return -1;
	}

	h_used[bestnode] = true;
	return bestnode;
}

/*
==============
idCinematicCin::Huff1TableInit

Reads the 64k counts table and builds one node tree per codebook
row.  Ported from Huff1TableInit in Quake II's cl_cin.c.
==============
*/
bool idCinematicCin::Huff1TableInit() {
	byte	counts[256];

	hnodes1 = (int *)Mem_Alloc( 256 * 256 * 2 * sizeof( int ), TAG_ROQ );
	memset( hnodes1, 0, 256 * 256 * 2 * sizeof( int ) );

	for ( int prev = 0; prev < 256; prev++ ) {
		memset( h_count, 0, sizeof( h_count ) );
		memset( h_used, 0, sizeof( h_used ) );

		// read a row of counts
		if ( iFile->Read( counts, 256 ) != 256 ) {
			return false;
		}
		for ( int j = 0; j < 256; j++ ) {
			h_count[j] = counts[j];
		}

		// build the nodes
		int numhnodes = 256;
		int *nodebase = hnodes1 + prev * 256 * 2;

		while ( numhnodes != 511 ) {
			int *node = nodebase + ( numhnodes - 256 ) * 2;

			// pick two lowest counts
			node[0] = SmallestNode1( numhnodes );
			if ( node[0] == -1 ) {
				break;	// no more
			}
			node[1] = SmallestNode1( numhnodes );
			if ( node[1] == -1 ) {
				break;
			}

			h_count[numhnodes] = h_count[node[0]] + h_count[node[1]];
			numhnodes++;
		}

		numhnodes1[prev] = numhnodes - 1;
	}

	return true;
}

/*
==============
idCinematicCin::ReadNextFrame

Reads one frame: an optional palette chunk, a size prefixed order-1
huffman block and the raw audio samples for this frame.  Ported from
SCR_ReadNextFrame in Quake II's cl_cin.c.
==============
*/
bool idCinematicCin::ReadNextFrame() {
	byte	inbuf[4];
	int		command, size;

	int frame = framePos + 1;

	if ( iFile->Read( inbuf, 4 ) != 4 ) {
		return false;	// end of file
	}
	command = inbuf[0] + ( inbuf[1] << 8 ) + ( inbuf[2] << 16 ) + ( inbuf[3] << 24 );

	if ( command == 2 ) {
		return false;	// last frame marker
	}

	if ( command == 1 ) {
		// a palette chunk follows
		if ( iFile->Read( palette, 768 ) != 768 ) {
			return false;
		}
	}

	// size prefixed huffman block
	if ( iFile->Read( inbuf, 4 ) != 4 ) {
		return false;
	}
	size = inbuf[0] + ( inbuf[1] << 8 ) + ( inbuf[2] << 16 ) + ( inbuf[3] << 24 );
	if ( size < 1 || size > CIN_MAX_COMPRESSED ) {
		common->Warning( "idCinematicCin: bad compressed frame size %d in '%s'", size, fileName.c_str() );
		return false;
	}
	if ( iFile->Read( compressed, size ) != size ) {
		return false;
	}

	// raw audio chunk for this frame
	if ( s_rate > 0 ) {
		int start = frame * s_rate / 14;
		int end = ( frame + 1 ) * s_rate / 14;
		int count = end - start;
		int bytes = count * s_width * s_channels;
		if ( bytes > 0 ) {
			if ( iFile->Read( samples, bytes ) != bytes ) {
				return false;
			}
			if ( cinematicAudio != NULL && !s_noSound.GetBool() ) {
				// the provider takes ownership of the buffer and frees it when the voice is done with it
				int16 *audioBuffer = (int16 *)Mem_Alloc( count * s_channels * 2, TAG_AUDIO );
				if ( s_width == 2 ) {
					memcpy( audioBuffer, samples, count * s_channels * 2 );
				} else {
					// 8-bit unsigned to 16-bit
					for ( int i = 0; i < count * s_channels; i++ ) {
						audioBuffer[i] = (int16)( ( ( int )samples[i] - 128 ) << 8 );
					}
				}
				cinematicAudio->PlayAudio( ( uint8 * )audioBuffer, count * s_channels * 2 );
			}
		}
	}

	// decode the block and expand the palette indices to RGBA
	int count = compressed[0] + ( compressed[1] << 8 ) + ( compressed[2] << 16 ) + ( compressed[3] << 24 );
	if ( count != CIN_WIDTH * CIN_HEIGHT ) {
		common->Warning( "idCinematicCin: frame %d decodes %d pixels, expected %d in '%s'", frame, count, CIN_WIDTH * CIN_HEIGHT, fileName.c_str() );
		return false;
	}

	const byte *input = compressed + 4;
	int *hnodesbase = hnodes1 - 256 * 2;	// nodes 0-255 aren't stored
	int *hnodes = hnodesbase;
	int nodenum = numhnodes1[0];
	int remaining = count;
	int pixIdx = 0;

	while ( remaining ) {
		int inbyte = *input++;
		// one input byte feeds up to eight bit steps
		for ( int bit = 0; bit < 8 && remaining; bit++ ) {
			if ( nodenum < 256 ) {
				hnodes = hnodesbase + ( nodenum << 9 );
				image[pixIdx*4+0] = palette[nodenum*3+0];
				image[pixIdx*4+1] = palette[nodenum*3+1];
				image[pixIdx*4+2] = palette[nodenum*3+2];
				image[pixIdx*4+3] = 255;
				pixIdx++;
				remaining--;
				nodenum = numhnodes1[nodenum];
				if ( !remaining ) {
					break;
				}
			}
			nodenum = hnodes[nodenum*2 + ( inbyte & 1 )];
			inbyte >>= 1;
		}
	}

	int consumed = (int)( input - compressed );
	if ( consumed != size && consumed != size + 1 ) {
		common->Printf( "Decompression overread by %i\n", consumed - size );
	}

	framePos = frame;
	hasFrame = true;

	return true;
}

/*
==============
idCinematicCin::ImageForTime
==============
*/
cinData_t idCinematicCin::ImageForTime( int milliseconds ) {
	cinData_t	cinData;

	if ( milliseconds <= 0 ) {
		milliseconds = Sys_Milliseconds();
	}

	memset( &cinData, 0, sizeof( cinData ) );

	if ( r_skipVideo.GetBool() || status == FMV_EOF || status == FMV_IDLE ) {
		return cinData;
	}

	if ( !iFile ) {
		return cinData;
	}

	if ( ( !hasFrame ) || startTime == -1 ) {
		if ( startTime == -1 ) {
			CinReset();
		}
		startTime = milliseconds;
	}

	int desiredFrame = ( ( milliseconds - startTime ) * frameRate ) / 1000.0f;
	if ( desiredFrame < 0 ) {
		desiredFrame = 0;
	}

	if ( desiredFrame < framePos ) {
		CinReset();
		status = FMV_PLAY;
	}

	if ( hasFrame && desiredFrame == framePos ) {
		cinData.imageWidth = CIN_WIDTH;
		cinData.imageHeight = CIN_HEIGHT;
		cinData.status = status;
		cinData.image = img;
		return cinData;
	}

	// decode forward frame by frame, every frame plays its audio chunk
	while ( framePos < desiredFrame ) {
		if ( !ReadNextFrame() ) {
			status = FMV_EOF;
			break;
		}
	}

	if ( status == FMV_LOOPED || status == FMV_EOF ) {
		if ( looping ) {
			CinReset();
			startTime = milliseconds;
			status = FMV_PLAY;
			if ( !ReadNextFrame() ) {
				status = FMV_IDLE;
				return cinData;
			}
		} else {
			hasFrame = false;
			status = FMV_IDLE;
			return cinData;
		}
	}

	cinData.imageWidth = CIN_WIDTH;
	cinData.imageHeight = CIN_HEIGHT;
	cinData.status = status;

	if ( img != NULL ) {
		if ( img->GetUploadWidth() != CIN_WIDTH || img->GetUploadHeight() != CIN_HEIGHT ) {
			idImageOpts opts = img->GetOpts();
			opts.width = CIN_WIDTH;
			opts.height = CIN_HEIGHT;
			img->AllocImage( opts, TF_LINEAR, TR_REPEAT );
		}
		img->SubImageUpload( 0, 0, 0, 0, CIN_WIDTH, CIN_HEIGHT, image );
	}

	hasFrame = true;
	cinData.image = img;

	return cinData;
}
