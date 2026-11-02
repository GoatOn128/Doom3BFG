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

If you have questions concerning this license or the applicable additional terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

class idRenderLightLocal;

/*
============================================================

RENDER LIGHT COMMITTED

View independent light state that is derived once per frame in an
explicit commit pass. This is the committed-render-architecture
replacement for deriving the light projection data lazily inside
R_DeriveLightData: the light def stores the registered parms, and
all view independent derived state lives in committedLight_t.

============================================================
*/

struct committedLight_t {
	idPlane						lightProject[4];	// old style light projection where Z and W are flipped and for projected lights lightProject[3] is divided by ( zNear + zFar )
	idRenderMatrix				baseLightProject;	// global xyz1 to projected light strq
	idRenderMatrix				inverseBaseLightProject;	// transforms the zero-to-one cube to exactly cover the light in world space
	idVec3						globalLightOrigin;	// accounting for lightCenter and parallel
	idBounds					globalLightBounds;	// global bounds of the light volume
	int							commitFrame;		// tr.frameCount of the last commit, also set by a forced commit on light creation and update
};

// Rebuild the view independent committed state of a single light from its parms.
void R_CommitLight( idRenderLightLocal * light );

// Commit all lights of all worlds for this frame. Lights that were already
// committed this frame (for example by a forced commit during UpdateRenderLight)
// are skipped.
void R_CommitLights();
