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

The math in this file is the projection code that used to live in
R_DeriveLightData in RenderWorld_defs.cpp, restructured into an
explicit per frame commit stage. It derives the view independent
light state (the committedLight_t on the light def) that all
frontend consumers read.

===============================================================================
*/

static const float SPOT_LIGHT_MIN_Z_NEAR	= 8.0f;
static const float SPOT_LIGHT_MIN_Z_FAR		= 16.0f;

/*
========================
R_ComputePointLightProjectionMatrix

Computes the light projection matrix for a point light.
========================
*/
static float R_ComputePointLightProjectionMatrix( idRenderLightLocal * light, idRenderMatrix & localProject ) {
	assert( light->parms.pointLight );

	// A point light uses a box projection.
	// This projects into the 0.0 - 1.0 texture range instead of -1.0 to 1.0 clip space range.
	localProject.Zero();
	localProject[0][0] = 0.5f / light->parms.lightRadius[0];
	localProject[1][1] = 0.5f / light->parms.lightRadius[1];
	localProject[2][2] = 0.5f / light->parms.lightRadius[2];
	localProject[0][3] = 0.5f;
	localProject[1][3] = 0.5f;
	localProject[2][3] = 0.5f;
	localProject[3][3] = 1.0f;	// identity perspective

	return 1.0f;
}

/*
========================
R_ComputeSpotLightProjectionMatrix

Computes the light projection matrix for a spot light.
========================
*/
static float R_ComputeSpotLightProjectionMatrix( idRenderLightLocal * light, idRenderMatrix & localProject ) {
	const float targetDistSqr = light->parms.target.LengthSqr();
	const float invTargetDist = idMath::InvSqrt( targetDistSqr );
	const float targetDist = invTargetDist * targetDistSqr;

	const idVec3 normalizedTarget = light->parms.target * invTargetDist;
	const idVec3 normalizedRight = light->parms.right * ( 0.5f * targetDist / light->parms.right.LengthSqr() );
	const idVec3 normalizedUp = light->parms.up * ( -0.5f * targetDist / light->parms.up.LengthSqr() );

	localProject[0][0] = normalizedRight[0];
	localProject[0][1] = normalizedRight[1];
	localProject[0][2] = normalizedRight[2];
	localProject[0][3] = 0.0f;

	localProject[1][0] = normalizedUp[0];
	localProject[1][1] = normalizedUp[1];
	localProject[1][2] = normalizedUp[2];
	localProject[1][3] = 0.0f;

	localProject[3][0] = normalizedTarget[0];
	localProject[3][1] = normalizedTarget[1];
	localProject[3][2] = normalizedTarget[2];
	localProject[3][3] = 0.0f;

	// Set the falloff vector.
	// This is similar to the Z calculation for depth buffering, which means that the
	// mapped texture is going to be perspective distorted heavily towards the zero end.
	const float zNear = Max( light->parms.start * normalizedTarget, SPOT_LIGHT_MIN_Z_NEAR );
	const float zFar = Max( light->parms.end * normalizedTarget, SPOT_LIGHT_MIN_Z_FAR );
	const float zScale = ( zNear + zFar ) / zFar;

	localProject[2][0] = normalizedTarget[0] * zScale;
	localProject[2][1] = normalizedTarget[1] * zScale;
	localProject[2][2] = normalizedTarget[2] * zScale;
	localProject[2][3] = - zNear * zScale;

	// now offset to the 0.0 - 1.0 texture range instead of -1.0 to 1.0 clip space range
	idVec4 projectedTarget;
	localProject.TransformPoint( light->parms.target, projectedTarget );

	const float ofs0 = 0.5f - projectedTarget[0] / projectedTarget[3];
	localProject[0][0] += ofs0 * localProject[3][0];
	localProject[0][1] += ofs0 * localProject[3][1];
	localProject[0][2] += ofs0 * localProject[3][2];
	localProject[0][3] += ofs0 * localProject[3][3];

	const float ofs1 = 0.5f - projectedTarget[1] / projectedTarget[3];
	localProject[1][0] += ofs1 * localProject[3][0];
	localProject[1][1] += ofs1 * localProject[3][1];
	localProject[1][2] += ofs1 * localProject[3][2];
	localProject[1][3] += ofs1 * localProject[3][3];

	return 1.0f / ( zNear + zFar );
}

/*
========================
R_ComputeParallelLightProjectionMatrix

Computes the light projection matrix for a parallel light.
========================
*/
static float R_ComputeParallelLightProjectionMatrix( idRenderLightLocal * light, idRenderMatrix & localProject ) {
	assert( light->parms.parallel );

	// A parallel light uses a box projection.
	// This projects into the 0.0 - 1.0 texture range instead of -1.0 to 1.0 clip space range.
	localProject.Zero();
	localProject[0][0] = 0.5f / light->parms.lightRadius[0];
	localProject[1][1] = 0.5f / light->parms.lightRadius[1];
	localProject[2][2] = 0.5f / light->parms.lightRadius[2];
	localProject[0][3] = 0.5f;
	localProject[1][3] = 0.5f;
	localProject[2][3] = 0.5f;
	localProject[3][3] = 1.0f;	// identity perspective

	return 1.0f;
}

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
	float zScale = 1.0f;
	if ( light->parms.parallel ) {
		zScale = R_ComputeParallelLightProjectionMatrix( light, localProject );
	} else if ( light->parms.pointLight ) {
		zScale = R_ComputePointLightProjectionMatrix( light, localProject );
	} else {
		zScale = R_ComputeSpotLightProjectionMatrix( light, localProject );
	}

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
	// we are just faking parallel by making it a very far off center for now
	if ( light->parms.parallel ) {
		idVec3 dir = light->parms.lightCenter;
		if ( dir.Normalize() == 0.0f ) {
			// make point straight up if not specified
			dir[2] = 1.0f;
		}
		light->committed.globalLightOrigin = light->parms.origin + dir * 100000.0f;
	} else {
		light->committed.globalLightOrigin = light->parms.origin + light->parms.axis * light->parms.lightCenter;
	}

	// Rotate and translate the light projection by the light matrix.
	// 99% of lights remain axis aligned in world space.
	idRenderMatrix lightMatrix;
	idRenderMatrix::CreateFromOriginAxis( light->parms.origin, light->parms.axis, lightMatrix );

	idRenderMatrix inverseLightMatrix;
	if ( !idRenderMatrix::Inverse( lightMatrix, inverseLightMatrix ) ) {
		idLib::Warning( "lightMatrix invert failed" );
	}

	// 'baseLightProject' goes from global space -> light local space -> light projective space
	idRenderMatrix::Multiply( localProject, inverseLightMatrix, light->committed.baseLightProject );

	// Invert the light projection so we can deform zero-to-one cubes into
	// the light model and calculate global bounds.
	if ( !idRenderMatrix::Inverse( light->committed.baseLightProject, light->committed.inverseBaseLightProject ) ) {
		idLib::Warning( "baseLightProject invert failed" );
	}

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
