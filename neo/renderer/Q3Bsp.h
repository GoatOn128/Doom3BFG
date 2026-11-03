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

If you have questions concerning this license or the additional terms, you should contact in writing: id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#ifndef __Q3BSP_H__
#define __Q3BSP_H__

/*
===============================================================================

	Loading of Q3/RtCW/ET binary BSP maps (IBSP versions 46 and 47).

	The world geometry builds a static render model (_area0), the brush
	geometry converts to an idMapFile for the stock collision model
	(with automatic .cm caching), and the lightmap blocks convert to
	point lights. There is no PVS, the world is one portal area.

===============================================================================
*/

class idRenderWorldLocal;
class idMapFile;

// converts a Q3/RtCW/ET .bsp to an idMapFile, or NULL when no .bsp exists
idMapFile *		Q3Bsp_ConvertToMapFile( const char *mapName );

// builds the world render model (_area0) from a .bsp, or NULL when no .bsp exists
idRenderModel *	Q3Bsp_BuildWorldRenderModel( const char *name, ID_TIME_T *timeStamp = NULL );

// adds point lights sampled from the .bsp lightmap blocks
void			Q3Bsp_AddLightmapLights( idRenderWorldLocal *world, const char *name );

#endif /* !__Q3BSP_H__ */
