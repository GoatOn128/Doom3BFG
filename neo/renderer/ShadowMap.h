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

If you have questions concerning this license or the additional terms, you should contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#ifndef __SHADOWMAP_H__
#define __SHADOWMAP_H__

// shadow map cvars
extern idCVar r_useShadowMaps;			// render shadow maps for shadow casting lights
extern idCVar r_shadowMapSize;			// shadow map tile resolution, changes require a vid_restart
extern idCVar r_shadowMapMaxLights;		// maximum number of lights per view that get a shadow map, changes require a vid_restart
extern idCVar r_shadowMapZNear;			// near clip plane for shadow map rendering
extern idCVar r_shadowMapBias;			// minimum variance for the shadow map moments
extern idCVar r_showShadowMaps;			// print the shadow map slot assignment

// create the shadow map atlas texture and framebuffer, called from R_InitOpenGL
void R_InitShadowMaps();
// free the shadow map atlas, called from ShutdownOpenGL
void R_ShutdownShadowMaps();
// render the shadow maps for all shadow casting lights of the current view
void RB_RenderShadowMaps();
// bind the shadow map atlas to the currently selected texture unit, the atlas is a raw GL texture
bool R_BindShadowMapAtlas();
// release the shadow map atlas from the currently selected texture unit
void R_UnbindShadowMapAtlas();

#endif /* !__SHADOWMAP_H__ */
