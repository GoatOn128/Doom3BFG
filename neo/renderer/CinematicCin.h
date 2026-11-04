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

#ifndef __CINEMATICCIN_H__
#define __CINEMATICCIN_H__

#include "Cinematic.h"
#include "../sound/SoundCinematic.h"

/*
===============================================================================

	Quake II .cin cinematics.  14 fps 8-bit paletted frames coded with
	an order-1 Huffman codec, with a raw audio chunk per frame.

===============================================================================
*/

class idCinematicCin : public idCinematic {
public:
					idCinematicCin();
	virtual				~idCinematicCin();

	virtual bool			InitFromFile( const char *qpath, bool looping );
	virtual int			AnimationLength();
	virtual cinData_t		ImageForTime( int milliseconds );
	virtual void			Close();
	virtual void			ResetTime( int time );
	virtual int			GetStartTime();
	virtual bool			IsPlaying() const;
	virtual void			ExportToTGA( bool skipExisting = true );
	virtual float			GetFrameRate() const;

private:
	void				CinReset();
	bool				ReadNextFrame();
	bool				Huff1TableInit();
	int				SmallestNode1( int numhnodes );

	int				animationLength;
	int				startTime;
	float				frameRate;
	int				CIN_WIDTH, CIN_HEIGHT;
	cinStatus_t			status;
	bool				looping;

	idStr				fileName;
	idFile *			iFile;
	idImage *			img;
	byte *				image;			// decoded RGBA frame
	byte *				compressed;			// current compressed frame block
	byte *				samples;			// current raw audio chunk

	byte				palette[768];

	// order-1 huffman
	int *				hnodes1;		// 256*256*2 nodes
	int				numhnodes1[256];
	bool				h_used[512];
	int				h_count[512];

	int				framePos;		// last decoded frame, -1 before the first
	bool				hasFrame;

	// audio
	int				s_rate;
	int				s_width;
	int				s_channels;
	idCinematicAudio *		cinematicAudio;
};

#endif /* !__CINEMATICCIN_H__ */
