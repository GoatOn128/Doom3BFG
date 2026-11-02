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

Render light parms.

The light projection math in this file is the code that used to live as
statics in RenderLightCommitted.cpp, moved onto the parms so the light
def no longer derives its projection in a separate pass.

===============================================================================
*/

static const float SPOT_LIGHT_MIN_Z_NEAR	= 8.0f;
static const float SPOT_LIGHT_MIN_Z_FAR	= 16.0f;

/*
========================
idRenderLightParms::idRenderLightParms
========================
*/
idRenderLightParms::idRenderLightParms() {
	memset( this, 0, sizeof( *this ) );
}

/*
========================
idRenderLightParms::FromRenderLight

Converts the public renderLight_t into the renderer parms, folding the
pointLight and parallel bools into the lightType discriminant.
========================
*/
void idRenderLightParms::FromRenderLight( const renderLight_t & light ) {
	axis = light.axis;
	origin = light.origin;
	suppressLightInViewID = light.suppressLightInViewID;
	allowLightInViewID = light.allowLightInViewID;
	forceShadows = light.forceShadows;
	noShadows = light.noShadows;
	noSpecular = light.noSpecular;
	if ( light.parallel ) {
		lightType = LIGHT_PARALLEL;
	} else if ( light.pointLight ) {
		lightType = LIGHT_POINT;
	} else {
		lightType = LIGHT_SPOT;
	}
	lightRadius = light.lightRadius;
	lightCenter = light.lightCenter;
	target = light.target;
	right = light.right;
	up = light.up;
	start = light.start;
	end = light.end;
	prelightModel = light.prelightModel;
	lightId = light.lightId;
	shader = light.shader;
	for ( int i = 0; i < MAX_ENTITY_SHADER_PARMS; i++ ) {
		shaderParms[i] = light.shaderParms[i];
	}
	referenceSound = light.referenceSound;
}

/*
========================
idRenderLightParms::ToRenderLight
========================
*/
void idRenderLightParms::ToRenderLight( renderLight_t & light ) const {
	light.axis = axis;
	light.origin = origin;
	light.suppressLightInViewID = suppressLightInViewID;
	light.allowLightInViewID = allowLightInViewID;
	light.forceShadows = forceShadows;
	light.noShadows = noShadows;
	light.noSpecular = noSpecular;
	light.pointLight = ( lightType == LIGHT_POINT );
	light.parallel = ( lightType == LIGHT_PARALLEL );
	light.lightRadius = lightRadius;
	light.lightCenter = lightCenter;
	light.target = target;
	light.right = right;
	light.up = up;
	light.start = start;
	light.end = end;
	light.prelightModel = prelightModel;
	light.lightId = lightId;
	light.shader = shader;
	for ( int i = 0; i < MAX_ENTITY_SHADER_PARMS; i++ ) {
		light.shaderParms[i] = shaderParms[i];
	}
	light.referenceSound = referenceSound;
}

/*
========================
idRenderLightParms::ComputeLightProjectionMatrix

Computes the light projection matrix in light local space. A point or
parallel light uses a box projection, a spot light uses a frustum
projection, and the return value is the zScale of the old style light
projection ( 1.0 for the box projections, 1.0 / ( zNear + zFar ) for
projected lights ).
========================
*/
float idRenderLightParms::ComputeLightProjectionMatrix( idRenderMatrix & localProject ) const {
	if ( lightType == LIGHT_SPOT ) {
		const float targetDistSqr = target.LengthSqr();
		const float invTargetDist = idMath::InvSqrt( targetDistSqr );
		const float targetDist = invTargetDist * targetDistSqr;

		const idVec3 normalizedTarget = target * invTargetDist;
		const idVec3 normalizedRight = right * ( 0.5f * targetDist / right.LengthSqr() );
		const idVec3 normalizedUp = up * ( -0.5f * targetDist / up.LengthSqr() );

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
		const float zNear = Max( start * normalizedTarget, SPOT_LIGHT_MIN_Z_NEAR );
		const float zFar = Max( end * normalizedTarget, SPOT_LIGHT_MIN_Z_FAR );
		const float zScale = ( zNear + zFar ) / zFar;

		localProject[2][0] = normalizedTarget[0] * zScale;
		localProject[2][1] = normalizedTarget[1] * zScale;
		localProject[2][2] = normalizedTarget[2] * zScale;
		localProject[2][3] = - zNear * zScale;

		// now offset to the 0.0 - 1.0 texture range instead of -1.0 to 1.0 clip space range
		idVec4 projectedTarget;
		localProject.TransformPoint( target, projectedTarget );

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

	// A point or parallel light uses a box projection.
	// This projects into the 0.0 - 1.0 texture range instead of -1.0 to 1.0 clip space range.
	localProject.Zero();
	localProject[0][0] = 0.5f / lightRadius[0];
	localProject[1][1] = 0.5f / lightRadius[1];
	localProject[2][2] = 0.5f / lightRadius[2];
	localProject[0][3] = 0.5f;
	localProject[1][3] = 0.5f;
	localProject[2][3] = 0.5f;
	localProject[3][3] = 1.0f;	// identity perspective

	return 1.0f;
}

/*
========================
idRenderLightParms::ComputeLightGlobalOrigin
========================
*/
void idRenderLightParms::ComputeLightGlobalOrigin( idVec3 & globalOrigin ) const {
	if ( lightType == LIGHT_PARALLEL ) {
		// we are just faking parallel by making it a very far off center for now
		idVec3 dir = lightCenter;
		if ( dir.Normalize() == 0.0f ) {
			// make point straight up if not specified
			dir[2] = 1.0f;
		}
		globalOrigin = origin + dir * 100000.0f;
	} else {
		globalOrigin = origin + axis * lightCenter;
	}
}

/*
========================
idRenderLightParms::ComputeWorldToLightMatrix

Rotate and translate the light projection by the light matrix.
99% of lights remain axis aligned in world space.
========================
*/
void idRenderLightParms::ComputeWorldToLightMatrix( const idRenderMatrix & localProject, idRenderMatrix & baseLightProject, idRenderMatrix & inverseBaseLightProject ) const {
	idRenderMatrix lightMatrix;
	idRenderMatrix::CreateFromOriginAxis( origin, axis, lightMatrix );

	idRenderMatrix inverseLightMatrix;
	if ( !idRenderMatrix::Inverse( lightMatrix, inverseLightMatrix ) ) {
		idLib::Warning( "lightMatrix invert failed" );
	}

	// 'baseLightProject' goes from global space -> light local space -> light projective space
	idRenderMatrix::Multiply( localProject, inverseLightMatrix, baseLightProject );

	// Invert the light projection so we can deform zero-to-one cubes into
	// the light model and calculate global bounds.
	if ( !idRenderMatrix::Inverse( baseLightProject, inverseBaseLightProject ) ) {
		idLib::Warning( "baseLightProject invert failed" );
	}
}
