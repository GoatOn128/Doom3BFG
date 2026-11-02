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

#include "precompiled.h"
#pragma hdrstop

#include "tr_local.h"

/*
===============================================================================

Light commit pass.

This is an explicit per frame commit stage that derives the view
independent light state (the committedLight_t on the light def) that
all frontend consumers read. The projection math itself lives on the
light parms now (RenderLightParms.cpp), not on the def.

===============================================================================
*/

/*
=================
R_CommitLight

Rebuilds the view independent committed state of a light from its
parms. Always recomputes: mid frame shape changes must re-derive,
so there is no freshness early out here. Frame gating happens in
R_CommitLights, and R_DeriveLightData calls this directly so the
committed state can never go stale.
=================
*/
void R_CommitLight( idRenderLightLocal * light ) {
	idRenderMatrix localProject;
	const float zScale = light->parms.ComputeLightProjectionMatrix( localProject );

	// set the old style light projection where Z and W are flipped and
	// for projected lights lightProject[3] is divided by ( zNear + zFar )
	light->committed.lightProject[0][0] = localProject[0][0];
	light->committed.lightProject[0][1] = localProject[0][1];
	light->committed.lightProject[0][2] = localProject[0][2];
	light->committed.lightProject[0][3] = localProject[0][3];

	light->committed.lightProject[1][0] = localProject[1][0];
	light->committed.lightProject[1][1] = localProject[1][1];
	light->committed.lightProject[1][2] = localProject[1][2];
	light->committed.lightProject[1][3] = localProject[1][3];

	light->committed.lightProject[2][0] = localProject[3][0];
	light->committed.lightProject[2][1] = localProject[3][1];
	light->committed.lightProject[2][2] = localProject[3][2];
	light->committed.lightProject[2][3] = localProject[3][3];

	light->committed.lightProject[3][0] = localProject[2][0] * zScale;
	light->committed.lightProject[3][1] = localProject[2][1] * zScale;
	light->committed.lightProject[3][2] = localProject[2][2] * zScale;
	light->committed.lightProject[3][3] = localProject[2][3] * zScale;

	// transform the lightProject
	float lightTransform[16];
	R_AxisToModelMatrix( light->parms.axis, light->parms.origin, lightTransform );
	for ( int i = 0; i < 4; i++ ) {
		idPlane temp = light->committed.lightProject[i];
		R_LocalPlaneToGlobal( lightTransform, temp, light->committed.lightProject[i] );
	}

	// adjust global light origin for off center projections and parallel projections
	light->parms.ComputeLightGlobalOrigin( light->committed.globalLightOrigin );

	// build the global space to light projective space matrix and its inverse
	light->parms.ComputeWorldToLightMatrix( localProject, light->committed.baseLightProject, light->committed.inverseBaseLightProject );

	// calculate the global light bounds by inverse projecting the zero to one cube with the 'inverseBaseLightProject'
	idRenderMatrix::ProjectedBounds( light->committed.globalLightBounds, light->committed.inverseBaseLightProject, bounds_zeroOneCube, false );

	light->committed.commitFrame = tr.frameCount;
}

/*
=================
R_CommitLights

Per frame commit pass: rebuild the committed state of every light
in every world that has not been committed yet this frame. Lights
that were created or updated during the frame were committed
directly through R_DeriveLightData, so subview re-entry of
R_RenderView stays cheap.
=================
*/
void R_CommitLights() {
	for ( int j = 0; j < tr.worlds.Num(); j++ ) {
		idRenderWorldLocal * rw = tr.worlds[j];

		for ( int i = 0; i < rw->lightDefs.Num(); i++ ) {
			idRenderLightLocal * light = rw->lightDefs[i];
			if ( light == NULL ) {
				continue;
			}
			if ( light->committed.commitFrame == tr.frameCount ) {
				continue;
			}
			R_CommitLight( light );
		}
	}
}
