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

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms.  You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 BFG Edition Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning the license or the applicable additional terms, you should contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#ifndef __GLOBALSHADOWS_H__
#define __GLOBALSHADOWS_H__

/*
===============================================================================

	Baked global shadows

	A top down orthographic height map of the shadow casting world
	geometry. A point is shadowed when geometry above it blocks the
	downward direction. The runtime consumer of the data is a later
	phase, this phase only bakes and loads it.

	File layout of the "<map>_globalShadows2.bin" file:
	int magic, int width, int height, float mins[3], float maxs[3], then
	width * height unsigned short heights, the height of the highest shadow
	casting surface above the texel normalized to 0 .. 65535.
===============================================================================
*/

const int GLOBALSHADOWS_MAGIC = 0x21155702;

class idGlobalShadows {
public:
						idGlobalShadows();
						~idGlobalShadows();

	void				Clear();
	bool				Load( const char *fileName );
	bool				IsLoaded() const { return fileData != NULL; }

	// 0 is fully lit from straight above, 1 is fully shadowed
	float				SampleShadow( const idVec3 &worldPoint ) const;

private:
	byte *				fileData;
	int					width;
	int					height;
	idVec3				mins;
	idVec3				maxs;
};

extern idGlobalShadows globalShadows;

// bakes the global shadow map of the world into the file, used by bakeAmbient
bool R_BakeGlobalShadows( class idRenderWorldLocal *world, const char *fileName );

#endif /* !__GLOBALSHADOWS_H__ */
