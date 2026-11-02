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

Model commit pass.

The math in this file is the entity transform code that used to live in
R_DeriveEntityData in RenderWorld_defs.cpp, restructured into an
explicit per frame commit stage. It derives the view independent entity
state (the committedModel_t on the entity def) that all frontend
consumers read.

===============================================================================
*/

/*
========================
R_CommitModel

Rebuild the view independent committed state of a single entity from
its parms. R_CommitModels, and R_DeriveEntityData call this directly
so the data is also valid immediately after an entity update.
========================
*/
void R_CommitModel( idRenderEntityLocal * entity ) {
	if ( entity->parms.hModel == NULL ) {
		entity->parms.hModel = renderModelManager->DefaultModel();
	}

	// if the entity hasn't been fully specified due to expensive animation calcs
	// for md5 and particles, use the provided conservative bounds.
	if ( entity->parms.callback != NULL ) {
		entity->committed.localReferenceBounds = entity->parms.bounds;
	} else {
		entity->committed.localReferenceBounds = entity->parms.hModel->Bounds( &entity->parms );
	}

	R_AxisToModelMatrix( entity->parms.axis, entity->parms.origin, entity->committed.modelMatrix );

	idRenderMatrix::CreateFromOriginAxis( entity->parms.origin, entity->parms.axis, entity->committed.modelRenderMatrix );

	// calculate the matrix that transforms the unit cube to exactly cover the model in world space
	idRenderMatrix::OffsetScaleForBounds( entity->committed.modelRenderMatrix, entity->committed.localReferenceBounds, entity->committed.inverseBaseModelProject );

	// calculate the global model bounds by inverse projecting the unit cube with the 'inverseBaseModelProject'
	idRenderMatrix::ProjectedBounds( entity->committed.globalReferenceBounds, entity->committed.inverseBaseModelProject, bounds_unitCube, false );

	entity->committed.commitFrame = tr.frameCount;
}

/*
========================
R_CommitModels

Commit all models of all worlds for this frame. Models that were
already committed this frame (for example by a forced commit during an
entity update) are skipped.
========================
*/
void R_CommitModels() {
	for ( int j = 0; j < tr.worlds.Num(); j++ ) {
		idRenderWorldLocal * rw = tr.worlds[j];

		for ( int i = 0; i < rw->entityDefs.Num(); i++ ) {
			idRenderEntityLocal * entity = rw->entityDefs[i];
			if ( entity == NULL ) {
				continue;
			}
			if ( entity->committed.commitFrame == tr.frameCount ) {
				continue;
			}
			R_CommitModel( entity );
		}
	}
}
