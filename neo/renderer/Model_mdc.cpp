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

If you have questions concerning this license or the applicable additional terms, please contact in writing to id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================

MDC (compressed MD3) support ported from the Wolfenstein: Enemy Territory
GPL Source Code (Copyright (C) 1999-2010 id Software LLC, a ZeniMax Media
company), mostly from R_LoadMDC in src/renderer/tr_model.c, the decode macro
R_MDC_DecodeXyzCompressed in src/renderer/tr_local.h and the compressed
frame decode in LerpCMeshVertexes in src/renderer/tr_surface.c. The ET
source is GPLv3 like this engine and is also vendored in this repository
under references/etwolf.

*/

#include "precompiled.h"
#pragma hdrstop

#include "tr_local.h"
#include "Model_local.h"
#include "Model_md3.h"
#include "Model_mdc.h"


// the 256 vertex normals the compressed frames index into, from the Enemy
// Territory src/renderer/anorms256.h
static const float mdcAnorms[256][3] = {
{1.000000f, 0.000000f, 0.000000f},
{0.980785f, 0.195090f, 0.000000f},
{0.923880f, 0.382683f, 0.000000f},
{0.831470f, 0.555570f, 0.000000f},
{0.707107f, 0.707107f, 0.000000f},
{0.555570f, 0.831470f, 0.000000f},
{0.382683f, 0.923880f, 0.000000f},
{0.195090f, 0.980785f, 0.000000f},
{-0.000000f, 1.000000f, 0.000000f},
{-0.195090f, 0.980785f, 0.000000f},
{-0.382683f, 0.923880f, 0.000000f},
{-0.555570f, 0.831470f, 0.000000f},
{-0.707107f, 0.707107f, 0.000000f},
{-0.831470f, 0.555570f, 0.000000f},
{-0.923880f, 0.382683f, 0.000000f},
{-0.980785f, 0.195090f, 0.000000f},
{-1.000000f, -0.000000f, 0.000000f},
{-0.980785f, -0.195090f, 0.000000f},
{-0.923880f, -0.382683f, 0.000000f},
{-0.831470f, -0.555570f, 0.000000f},
{-0.707107f, -0.707107f, 0.000000f},
{-0.555570f, -0.831469f, 0.000000f},
{-0.382684f, -0.923880f, 0.000000f},
{-0.195090f, -0.980785f, 0.000000f},
{0.000000f, -1.000000f, 0.000000f},
{0.195090f, -0.980785f, 0.000000f},
{0.382684f, -0.923879f, 0.000000f},
{0.555570f, -0.831470f, 0.000000f},
{0.707107f, -0.707107f, 0.000000f},
{0.831470f, -0.555570f, 0.000000f},
{0.923880f, -0.382683f, 0.000000f},
{0.980785f, -0.195090f, 0.000000f},
{0.980785f, 0.000000f, -0.195090f},
{0.956195f, 0.218245f, -0.195090f},
{0.883657f, 0.425547f, -0.195090f},
{0.766809f, 0.611510f, -0.195090f},
{0.611510f, 0.766809f, -0.195090f},
{0.425547f, 0.883657f, -0.195090f},
{0.218245f, 0.956195f, -0.195090f},
{-0.000000f, 0.980785f, -0.195090f},
{-0.218245f, 0.956195f, -0.195090f},
{-0.425547f, 0.883657f, -0.195090f},
{-0.611510f, 0.766809f, -0.195090f},
{-0.766809f, 0.611510f, -0.195090f},
{-0.883657f, 0.425547f, -0.195090f},
{-0.956195f, 0.218245f, -0.195090f},
{-0.980785f, -0.000000f, -0.195090f},
{-0.956195f, -0.218245f, -0.195090f},
{-0.883657f, -0.425547f, -0.195090f},
{-0.766809f, -0.611510f, -0.195090f},
{-0.611510f, -0.766809f, -0.195090f},
{-0.425547f, -0.883657f, -0.195090f},
{-0.218245f, -0.956195f, -0.195090f},
{0.000000f, -0.980785f, -0.195090f},
{0.218245f, -0.956195f, -0.195090f},
{0.425547f, -0.883657f, -0.195090f},
{0.611510f, -0.766809f, -0.195090f},
{0.766809f, -0.611510f, -0.195090f},
{0.883657f, -0.425547f, -0.195090f},
{0.956195f, -0.218245f, -0.195090f},
{0.923880f, 0.000000f, -0.382683f},
{0.892399f, 0.239118f, -0.382683f},
{0.800103f, 0.461940f, -0.382683f},
{0.653281f, 0.653281f, -0.382683f},
{0.461940f, 0.800103f, -0.382683f},
{0.239118f, 0.892399f, -0.382683f},
{-0.000000f, 0.923880f, -0.382683f},
{-0.239118f, 0.892399f, -0.382683f},
{-0.461940f, 0.800103f, -0.382683f},
{-0.653281f, 0.653281f, -0.382683f},
{-0.800103f, 0.461940f, -0.382683f},
{-0.892399f, 0.239118f, -0.382683f},
{-0.923880f, -0.000000f, -0.382683f},
{-0.892399f, -0.239118f, -0.382683f},
{-0.800103f, -0.461940f, -0.382683f},
{-0.653282f, -0.653281f, -0.382683f},
{-0.461940f, -0.800103f, -0.382683f},
{-0.239118f, -0.892399f, -0.382683f},
{0.000000f, -0.923880f, -0.382683f},
{0.239118f, -0.892399f, -0.382683f},
{0.461940f, -0.800103f, -0.382683f},
{0.653281f, -0.653282f, -0.382683f},
{0.800103f, -0.461940f, -0.382683f},
{0.892399f, -0.239117f, -0.382683f},
{0.831470f, 0.000000f, -0.555570f},
{0.790775f, 0.256938f, -0.555570f},
{0.672673f, 0.488726f, -0.555570f},
{0.488726f, 0.672673f, -0.555570f},
{0.256938f, 0.790775f, -0.555570f},
{-0.000000f, 0.831470f, -0.555570f},
{-0.256938f, 0.790775f, -0.555570f},
{-0.488726f, 0.672673f, -0.555570f},
{-0.672673f, 0.488726f, -0.555570f},
{-0.790775f, 0.256938f, -0.555570f},
{-0.831470f, -0.000000f, -0.555570f},
{-0.790775f, -0.256938f, -0.555570f},
{-0.672673f, -0.488726f, -0.555570f},
{-0.488725f, -0.672673f, -0.555570f},
{-0.256938f, -0.790775f, -0.555570f},
{0.000000f, -0.831470f, -0.555570f},
{0.256938f, -0.790775f, -0.555570f},
{0.488725f, -0.672673f, -0.555570f},
{0.672673f, -0.488726f, -0.555570f},
{0.790775f, -0.256938f, -0.555570f},
{0.707107f, 0.000000f, -0.707107f},
{0.653281f, 0.270598f, -0.707107f},
{0.500000f, 0.500000f, -0.707107f},
{0.270598f, 0.653281f, -0.707107f},
{-0.000000f, 0.707107f, -0.707107f},
{-0.270598f, 0.653282f, -0.707107f},
{-0.500000f, 0.500000f, -0.707107f},
{-0.653281f, 0.270598f, -0.707107f},
{-0.707107f, -0.000000f, -0.707107f},
{-0.653281f, -0.270598f, -0.707107f},
{-0.500000f, -0.500000f, -0.707107f},
{-0.270598f, -0.653281f, -0.707107f},
{0.000000f, -0.707107f, -0.707107f},
{0.270598f, -0.653281f, -0.707107f},
{0.500000f, -0.500000f, -0.707107f},
{0.653282f, -0.270598f, -0.707107f},
{0.555570f, 0.000000f, -0.831470f},
{0.481138f, 0.277785f, -0.831470f},
{0.277785f, 0.481138f, -0.831470f},
{-0.000000f, 0.555570f, -0.831470f},
{-0.277785f, 0.481138f, -0.831470f},
{-0.481138f, 0.277785f, -0.831470f},
{-0.555570f, -0.000000f, -0.831470f},
{-0.481138f, -0.277785f, -0.831470f},
{-0.277785f, -0.481138f, -0.831470f},
{0.000000f, -0.555570f, -0.831470f},
{0.277785f, -0.481138f, -0.831470f},
{0.481138f, -0.277785f, -0.831470f},
{0.382683f, 0.000000f, -0.923880f},
{0.270598f, 0.270598f, -0.923880f},
{-0.000000f, 0.382683f, -0.923880f},
{-0.270598f, 0.270598f, -0.923880f},
{-0.382683f, -0.000000f, -0.923880f},
{-0.270598f, -0.270598f, -0.923880f},
{0.000000f, -0.382683f, -0.923880f},
{0.270598f, -0.270598f, -0.923880f},
{0.195090f, 0.000000f, -0.980785f},
{-0.000000f, 0.195090f, -0.980785f},
{-0.195090f, -0.000000f, -0.980785f},
{0.000000f, -0.195090f, -0.980785f},
{0.980785f, 0.000000f, 0.195090f},
{0.956195f, 0.218245f, 0.195090f},
{0.883657f, 0.425547f, 0.195090f},
{0.766809f, 0.611510f, 0.195090f},
{0.611510f, 0.766809f, 0.195090f},
{0.425547f, 0.883657f, 0.195090f},
{0.218245f, 0.956195f, 0.195090f},
{-0.000000f, 0.980785f, 0.195090f},
{-0.218245f, 0.956195f, 0.195090f},
{-0.425547f, 0.883657f, 0.195090f},
{-0.611510f, 0.766809f, 0.195090f},
{-0.766809f, 0.611510f, 0.195090f},
{-0.883657f, 0.425547f, 0.195090f},
{-0.956195f, 0.218245f, 0.195090f},
{-0.980785f, -0.000000f, 0.195090f},
{-0.956195f, -0.218245f, 0.195090f},
{-0.883657f, -0.425547f, 0.195090f},
{-0.766809f, -0.611510f, 0.195090f},
{-0.611510f, -0.766809f, 0.195090f},
{-0.425547f, -0.883657f, 0.195090f},
{-0.218245f, -0.956195f, 0.195090f},
{0.000000f, -0.980785f, 0.195090f},
{0.218245f, -0.956195f, 0.195090f},
{0.425547f, -0.883657f, 0.195090f},
{0.611510f, -0.766809f, 0.195090f},
{0.766809f, -0.611510f, 0.195090f},
{0.883657f, -0.425547f, 0.195090f},
{0.956195f, -0.218245f, 0.195090f},
{0.923880f, 0.000000f, 0.382683f},
{0.892399f, 0.239118f, 0.382683f},
{0.800103f, 0.461940f, 0.382683f},
{0.653281f, 0.653281f, 0.382683f},
{0.461940f, 0.800103f, 0.382683f},
{0.239118f, 0.892399f, 0.382683f},
{-0.000000f, 0.923880f, 0.382683f},
{-0.239118f, 0.892399f, 0.382683f},
{-0.461940f, 0.800103f, 0.382683f},
{-0.653281f, 0.653281f, 0.382683f},
{-0.800103f, 0.461940f, 0.382683f},
{-0.892399f, 0.239118f, 0.382683f},
{-0.923880f, -0.000000f, 0.382683f},
{-0.892399f, -0.239118f, 0.382683f},
{-0.800103f, -0.461940f, 0.382683f},
{-0.653282f, -0.653281f, 0.382683f},
{-0.461940f, -0.800103f, 0.382683f},
{-0.239118f, -0.892399f, 0.382683f},
{0.000000f, -0.923880f, 0.382683f},
{0.239118f, -0.892399f, 0.382683f},
{0.461940f, -0.800103f, 0.382683f},
{0.653281f, -0.653282f, 0.382683f},
{0.800103f, -0.461940f, 0.382683f},
{0.892399f, -0.239117f, 0.382683f},
{0.831470f, 0.000000f, 0.555570f},
{0.790775f, 0.256938f, 0.555570f},
{0.672673f, 0.488726f, 0.555570f},
{0.488726f, 0.672673f, 0.555570f},
{0.256938f, 0.790775f, 0.555570f},
{-0.000000f, 0.831470f, 0.555570f},
{-0.256938f, 0.790775f, 0.555570f},
{-0.488726f, 0.672673f, 0.555570f},
{-0.672673f, 0.488726f, 0.555570f},
{-0.790775f, 0.256938f, 0.555570f},
{-0.831470f, -0.000000f, 0.555570f},
{-0.790775f, -0.256938f, 0.555570f},
{-0.672673f, -0.488726f, 0.555570f},
{-0.488725f, -0.672673f, 0.555570f},
{-0.256938f, -0.790775f, 0.555570f},
{0.000000f, -0.831470f, 0.555570f},
{0.256938f, -0.790775f, 0.555570f},
{0.488725f, -0.672673f, 0.555570f},
{0.672673f, -0.488726f, 0.555570f},
{0.790775f, -0.256938f, 0.555570f},
{0.707107f, 0.000000f, 0.707107f},
{0.653281f, 0.270598f, 0.707107f},
{0.500000f, 0.500000f, 0.707107f},
{0.270598f, 0.653281f, 0.707107f},
{-0.000000f, 0.707107f, 0.707107f},
{-0.270598f, 0.653282f, 0.707107f},
{-0.500000f, 0.500000f, 0.707107f},
{-0.653281f, 0.270598f, 0.707107f},
{-0.707107f, -0.000000f, 0.707107f},
{-0.653281f, -0.270598f, 0.707107f},
{-0.500000f, -0.500000f, 0.707107f},
{-0.270598f, -0.653281f, 0.707107f},
{0.000000f, -0.707107f, 0.707107f},
{0.270598f, -0.653281f, 0.707107f},
{0.500000f, -0.500000f, 0.707107f},
{0.653282f, -0.270598f, 0.707107f},
{0.555570f, 0.000000f, 0.831470f},
{0.481138f, 0.277785f, 0.831470f},
{0.277785f, 0.481138f, 0.831470f},
{-0.000000f, 0.555570f, 0.831470f},
{-0.277785f, 0.481138f, 0.831470f},
{-0.481138f, 0.277785f, 0.831470f},
{-0.555570f, -0.000000f, 0.831470f},
{-0.481138f, -0.277785f, 0.831470f},
{-0.277785f, -0.481138f, 0.831470f},
{0.000000f, -0.555570f, 0.831470f},
{0.277785f, -0.481138f, 0.831470f},
{0.481138f, -0.277785f, 0.831470f},
{0.382683f, 0.000000f, 0.923880f},
{0.270598f, 0.270598f, 0.923880f},
{-0.000000f, 0.382683f, 0.923880f},
{-0.270598f, 0.270598f, 0.923880f},
{-0.382683f, -0.000000f, 0.923880f},
{-0.270598f, -0.270598f, 0.923880f},
{0.000000f, -0.382683f, 0.923880f},
{0.270598f, -0.270598f, 0.923880f},
{0.195090f, 0.000000f, 0.980785f},
{-0.000000f, 0.195090f, 0.980785f},
{-0.195090f, -0.000000f, 0.980785f},
{0.000000f, -0.195090f, 0.980785f},
};

/*
=================
MDC_EncodeNormal

Inverse of MD3_DecodeNormal, packs a unit normal into the lat/lng byte pair
the MD3 layout stores per vertex.
=================
*/
static short MDC_EncodeNormal( const idVec3 &n ) {
	float lng = idMath::ACos( idMath::ClampFloat( -1.0f, 1.0f, n.z ) );
	// keep the assert in idMath::ATan away from the two poles
	float lat = 0.0f;
	if ( idMath::Fabs( n.x ) > 1e-4f || idMath::Fabs( n.y ) > 1e-4f ) {
		lat = idMath::ATan( n.y, n.x );
		if ( lat < 0.0f ) {
			lat += idMath::TWO_PI;
		}
	}
	return (short)( ( idMath::Ftoi( lat * ( 128.0f / idMath::PI ) ) << 8 ) | ( idMath::Ftoi( lng * ( 128.0f / idMath::PI ) ) & 255 ) );
}

/*
=================
MDC_LoadHeader

Loads an MDC file, decodes the compressed frames and tags and stores the
result in a synthesized MD3 layout block that the idRenderModelMD3 path
consumes unchanged. The block is freed by PurgeModel like an MD3 block.
=================
*/
static bool MDC_LoadHeader( const char *fileName, md3Header_t **headerOut, ID_TIME_T *timestamp ) {
	void			*buffer = NULL;
	int				fileLen;
	int				i, j, k;
	int				version;

	*headerOut = NULL;

	fileLen = fileSystem->ReadFile( fileName, &buffer, timestamp );
	if ( fileLen <= 0 ) {
		return false;
	}

	const mdcHeader_t *pinmodel = (const mdcHeader_t *)buffer;

	if ( LittleInt( pinmodel->ident ) != MDC_IDENT ) {
		common->Warning( "MDC_LoadHeader: %s has the wrong ident", fileName );
		fileSystem->FreeFile( buffer );
		return false;
	}

	version = LittleInt( pinmodel->version );
	if ( version != MDC_VERSION ) {
		common->Warning( "MDC_LoadHeader: %s has wrong version (%i should be %i)", fileName, version, MDC_VERSION );
		fileSystem->FreeFile( buffer );
		return false;
	}

	const int numFrames = LittleInt( pinmodel->numFrames );
	if ( numFrames < 1 ) {
		common->Warning( "MDC_LoadHeader: %s has no frames", fileName );
		fileSystem->FreeFile( buffer );
		return false;
	}

	if ( LittleInt( pinmodel->ofsEnd ) > fileLen ) {
		common->Warning( "MDC_LoadHeader: %s has a bad ofsEnd", fileName );
		fileSystem->FreeFile( buffer );
		return false;
	}

	const int numTags = LittleInt( pinmodel->numTags );
	const int numSurfaces = LittleInt( pinmodel->numSurfaces );

	// walk the surfaces once to validate them and size the synthesized block
	int totalSize = ( int )sizeof( md3Header_t );
	totalSize += numFrames * ( int )sizeof( md3Frame_t );
	totalSize += numFrames * numTags * ( int )sizeof( md3Tag_t );

	if ( numSurfaces > 0 && LittleInt( pinmodel->ofsSurfaces ) + ( int )sizeof( mdcSurface_t ) > fileLen ) {
		common->Warning( "MDC_LoadHeader: %s has a bad ofsSurfaces", fileName );
		fileSystem->FreeFile( buffer );
		return false;
	}

	const mdcSurface_t *surf = (const mdcSurface_t *)( (const byte *)buffer + LittleInt( pinmodel->ofsSurfaces ) );
	for ( i = 0; i < numSurfaces; i++ ) {
		const int ofsEnd = LittleInt( surf->ofsEnd );
		if ( ofsEnd < (int)sizeof( mdcSurface_t ) || ( (const byte *)surf - (const byte *)buffer ) + ofsEnd > fileLen ) {
			common->Warning( "MDC_LoadHeader: %s has a bad surface ofsEnd", fileName );
			fileSystem->FreeFile( buffer );
			return false;
		}
		const int numVerts = LittleInt( surf->numVerts );
		const int numTriangles = LittleInt( surf->numTriangles );
		const int numShaders = LittleInt( surf->numShaders );
		if ( numVerts > SHADER_MAX_VERTEXES ) {
			common->Error( "MDC_LoadHeader: %s has more than %i verts on a surface (%i)", fileName, SHADER_MAX_VERTEXES, numVerts );
		}
		if ( numTriangles * 3 > SHADER_MAX_INDEXES ) {
			common->Error( "MDC_LoadHeader: %s has more than %i triangles on a surface (%i)", fileName, SHADER_MAX_INDEXES / 3, numTriangles );
		}
		if ( LittleInt( surf->numBaseFrames ) < 1 ) {
			common->Warning( "MDC_LoadHeader: %s has a surface with no base frames", fileName );
			fileSystem->FreeFile( buffer );
			return false;
		}
		totalSize += ( int )sizeof( md3Surface_t );
		totalSize += numShaders * ( int )sizeof( md3Shader_t );
		totalSize += numTriangles * ( int )sizeof( md3Triangle_t );
		totalSize += numVerts * ( int )sizeof( md3St_t );
		totalSize += numVerts * numFrames * ( int )sizeof( md3XyzNormal_t );

		surf = (const mdcSurface_t *)( (const byte *)surf + ofsEnd );
	}

	// build the synthesized MD3 block
	md3Header_t *header = (md3Header_t *)Mem_Alloc( totalSize, TAG_MODEL );
	memset( header, 0, totalSize );

	int ofs = ( int )sizeof( md3Header_t );

	header->ident = MD3_IDENT;
	header->version = MD3_VERSION;
	memcpy( header->name, pinmodel->name, MAX_MD3PATH );
	header->name[MAX_MD3PATH-1] = '\0';
	header->flags = LittleInt( pinmodel->flags );
	header->numFrames = numFrames;
	header->numTags = numTags;
	header->numSurfaces = numSurfaces;
	header->numSkins = LittleInt( pinmodel->numSkins );

	// the frames are layout identical to MD3, copy them over swapped
	header->ofsFrames = ofs;
	const md3Frame_t *inFrame = (const md3Frame_t *)( (const byte *)buffer + LittleInt( pinmodel->ofsFrames ) );
	md3Frame_t *outFrame = (md3Frame_t *)( (byte *)header + header->ofsFrames );
	for ( i = 0; i < numFrames; i++, inFrame++, outFrame++ ) {
		for ( j = 0; j < 3; j++ ) {
			outFrame->bounds[0][j] = LittleFloat( inFrame->bounds[0][j] );
			outFrame->bounds[1][j] = LittleFloat( inFrame->bounds[1][j] );
			outFrame->localOrigin[j] = LittleFloat( inFrame->localOrigin[j] );
		}
		outFrame->radius = LittleFloat( inFrame->radius );
		memcpy( outFrame->name, inFrame->name, sizeof( outFrame->name ) );
	}
	ofs += numFrames * ( int )sizeof( md3Frame_t );

	// the tags are stored compressed, decode them into MD3 tags
	header->ofsTags = ofs;
	const mdcTagName_t *tagNames = (const mdcTagName_t *)( (const byte *)buffer + LittleInt( pinmodel->ofsTagNames ) );
	const mdcTag_t *inTag = (const mdcTag_t *)( (const byte *)buffer + LittleInt( pinmodel->ofsTags ) );
	md3Tag_t *outTag = (md3Tag_t *)( (byte *)header + header->ofsTags );
	for ( i = 0; i < numFrames * numTags; i++, inTag++, outTag++ ) {
		memcpy( outTag->name, tagNames[i % numTags].name, MAX_MD3PATH );
		outTag->name[MAX_MD3PATH-1] = '\0';
		for ( j = 0; j < 3; j++ ) {
			outTag->origin[j] = LittleShort( inTag->xyz[j] ) * MD3_XYZ_SCALE;
		}
		const idAngles angles( LittleShort( inTag->angles[0] ) * MDC_TAG_ANGLE_SCALE,
								LittleShort( inTag->angles[1] ) * MDC_TAG_ANGLE_SCALE,
								LittleShort( inTag->angles[2] ) * MDC_TAG_ANGLE_SCALE );
		const idMat3 axis = angles.ToMat3();
		outTag->axis[0] = axis[0];
		outTag->axis[1] = axis[1];
		outTag->axis[2] = axis[2];
	}
	ofs += numFrames * numTags * ( int )sizeof( md3Tag_t );

	// decode the surfaces
	header->ofsSurfaces = ofs;
	header->ofsEnd = totalSize;

	surf = (const mdcSurface_t *)( (const byte *)buffer + LittleInt( pinmodel->ofsSurfaces ) );
	byte *dst = (byte *)header + header->ofsSurfaces;
	for ( i = 0; i < numSurfaces; i++ ) {
		md3Surface_t *out = (md3Surface_t *)dst;
		int ofsCur = ( int )sizeof( md3Surface_t );

		const int numVerts = LittleInt( surf->numVerts );
		const int numTriangles = LittleInt( surf->numTriangles );
		const int numShaders = LittleInt( surf->numShaders );
		const int numBaseFrames = LittleInt( surf->numBaseFrames );
		const int numCompFrames = LittleInt( surf->numCompFrames );

		out->ident = 0;
		memcpy( out->name, surf->name, MAX_MD3PATH );
		out->name[MAX_MD3PATH-1] = '\0';
		out->flags = LittleInt( surf->flags );
		out->numFrames = numFrames;
		out->numShaders = numShaders;
		out->numVerts = numVerts;
		out->numTriangles = numTriangles;

		// lowercase the surface name so skin compares are faster
		int slen = (int)strlen( out->name );
		for ( j = 0; j < slen; j++ ) {
			out->name[j] = tolower( out->name[j] );
		}
		// strip off a trailing _1 or _2, this is a crutch for q3data being a mess
		slen = (int)strlen( out->name );
		if ( slen > 2 && out->name[slen-2] == '_' ) {
			out->name[slen-2] = 0;
		}

		// register the shaders
		out->ofsShaders = ofsCur;
		const mdcShaderFile_t *inShader = (const mdcShaderFile_t *)( (const byte *)surf + LittleInt( surf->ofsShaders ) );
		md3Shader_t *outShader = (md3Shader_t *)( dst + out->ofsShaders );
		for ( j = 0; j < numShaders; j++, inShader++, outShader++ ) {
			memcpy( outShader->name, inShader->name, MAX_MD3PATH );
			outShader->name[MAX_MD3PATH-1] = '\0';
			outShader->shader = declManager->FindMaterial( outShader->name );
		}
		ofsCur += numShaders * ( int )sizeof( md3Shader_t );

		// triangles
		out->ofsTriangles = ofsCur;
		const md3Triangle_t *inTri = (const md3Triangle_t *)( (const byte *)surf + LittleInt( surf->ofsTriangles ) );
		md3Triangle_t *outTri = (md3Triangle_t *)( dst + out->ofsTriangles );
		for ( j = 0; j < numTriangles; j++, inTri++, outTri++ ) {
			outTri->indexes[0] = LittleInt( inTri->indexes[0] );
			outTri->indexes[1] = LittleInt( inTri->indexes[1] );
			outTri->indexes[2] = LittleInt( inTri->indexes[2] );
		}
		ofsCur += numTriangles * ( int )sizeof( md3Triangle_t );

		// texture coords
		out->ofsSt = ofsCur;
		const md3St_t *inSt = (const md3St_t *)( (const byte *)surf + LittleInt( surf->ofsSt ) );
		md3St_t *outSt = (md3St_t *)( dst + out->ofsSt );
		for ( j = 0; j < numVerts; j++, inSt++, outSt++ ) {
			outSt->st[0] = LittleFloat( inSt->st[0] );
			outSt->st[1] = LittleFloat( inSt->st[1] );
		}
		ofsCur += numVerts * ( int )sizeof( md3St_t );

		// decode the vertexes of every frame, base frames are stored as plain
		// MD3 data, compressed frames expand into a delta from their base frame
		out->ofsXyzNormals = ofsCur;
		md3XyzNormal_t *outXyz = (md3XyzNormal_t *)( dst + out->ofsXyzNormals );

		const md3XyzNormal_t *baseXyz = (const md3XyzNormal_t *)( (const byte *)surf + LittleInt( surf->ofsXyzNormals ) );
		const mdcXyzCompressed_t *compXyz = (const mdcXyzCompressed_t *)( (const byte *)surf + LittleInt( surf->ofsXyzCompressed ) );
		const short *baseFrames = (const short *)( (const byte *)surf + LittleInt( surf->ofsFrameBaseFrames ) );
		const short *compFrames = (const short *)( (const byte *)surf + LittleInt( surf->ofsFrameCompFrames ) );

		for ( j = 0; j < numFrames; j++ ) {
			const int baseFrame = LittleShort( baseFrames[j] );
			const int compFrame = numCompFrames > 0 ? LittleShort( compFrames[j] ) : -1;
			if ( baseFrame < 0 || baseFrame >= numBaseFrames || compFrame >= numCompFrames ) {
				common->Warning( "MDC_LoadHeader: %s has a bad frame table on surface %i", fileName, i );
				Mem_Free( header );
				fileSystem->FreeFile( buffer );
				return false;
			}

			const md3XyzNormal_t *base = baseXyz + baseFrame * numVerts;
			for ( k = 0; k < numVerts; k++, outXyz++, base++ ) {
				if ( compFrame < 0 ) {
					// plain base frame, copy it over
					outXyz->xyz[0] = LittleShort( base->xyz[0] );
					outXyz->xyz[1] = LittleShort( base->xyz[1] );
					outXyz->xyz[2] = LittleShort( base->xyz[2] );
					outXyz->normal = LittleShort( base->normal );
				} else {
					// expand the compressed delta against the base frame
					const unsigned int ofsVec = ( unsigned int )LittleInt( ( int )compXyz[compFrame * numVerts + k].ofsVec );
					const float *anorm = mdcAnorms[ofsVec >> 24];
					const idVec3 normal( anorm[0], anorm[1], anorm[2] );
					for ( int c = 0; c < 3; c++ ) {
						const float pos = LittleShort( base->xyz[c] ) * MD3_XYZ_SCALE +
											( (float)( ( ofsVec >> ( c * 8 ) ) & 255 ) - MDC_MAX_OFS ) * MDC_DIST_SCALE;
						outXyz->xyz[c] = idMath::Ftoi16( pos * ( 1.0f / MD3_XYZ_SCALE ) );
					}
					outXyz->normal = MDC_EncodeNormal( normal );
				}
			}
		}
		ofsCur += numVerts * numFrames * ( int )sizeof( md3XyzNormal_t );

		out->ofsEnd = ofsCur;
		dst += ofsCur;

		surf = (const mdcSurface_t *)( (const byte *)surf + LittleInt( surf->ofsEnd ) );
	}

	fileSystem->FreeFile( buffer );

	*headerOut = header;
	return true;
}

/*
=================
idRenderModelMDC::LoadHeader
=================
*/
bool idRenderModelMDC::LoadHeader( const char *fileName, md3Header_t **headerOut, ID_TIME_T *timestamp ) {
	return MDC_LoadHeader( fileName, headerOut, timestamp );
}
