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

#ifndef __RENDERLIGHTPARMS_H__
#define __RENDERLIGHTPARMS_H__

enum lightType_t {
	LIGHT_POINT,
	LIGHT_SPOT,
	LIGHT_PARALLEL,
	LIGHT_TYPE_MAX
};

// Light classification and falloff modes kept for parity with the committed
// render architecture. This renderer does not consume them yet, so the parms
// do not carry fields for them.
enum lightClass_t {
	LIGHT_NORMAL,
	LIGHT_PRELIGHT_ONLY,
	LIGHT_SLOWLIGHT_DYNAMIC_ONLY,
	LIGHT_SLOWLIGHT_PRIVATE_ONLY,
	LIGHT_DYNAMIC_ONLY,
	LIGHT_PRIVATE_DYNAMIC_ONLY,
	LIGHT_PRIVATE_PRIME,
	LIGHT_BLENDED_ONLY
};

enum lightFallOff_t {
	LIGHT_FALLOFF_TEXTURE,
	LIGHT_FALLOFF_LINEAR,
	LIGHT_FALLOFF_INVERSE_SQUARE,
	LIGHT_FALLOFF_RADIAL
};

/*
============================================================

RENDER LIGHT PARMS

The renderer side copy of the light specification. The public renderLight_t
stays the game facing API and is converted once at the UpdateLightDef
boundary. The pointLight and parallel bools of the public struct fold into
the lightType discriminant, and the light projection math lives on the
parms instead of deriving from the def in a separate pass.

============================================================
*/

struct idRenderLightParms {
					idRenderLightParms();

	// convert from and to the public API struct
	void			FromRenderLight( const renderLight_t & light );
	void			ToRenderLight( renderLight_t & light ) const;

	// Computes the light projection matrix in light local space and returns
	// the zScale: 1.0 for point and parallel lights, 1.0 / ( zNear + zFar )
	// for spot lights.
	float			ComputeLightProjectionMatrix( idRenderMatrix & localProject ) const;

	// Computes the light origin in global space, accounting for lightCenter
	// offsets and faking parallel lights with a very far off center origin.
	void			ComputeLightGlobalOrigin( idVec3 & globalOrigin ) const;

	// Builds the global space to light projective space matrix and its
	// inverse from the local light projection.
	void			ComputeWorldToLightMatrix( const idRenderMatrix & localProject, idRenderMatrix & baseLightProject, idRenderMatrix & inverseBaseLightProject ) const;

	idMat3			axis;
	idVec3			origin;
	int				suppressLightInViewID;
	int				allowLightInViewID;
	bool			forceShadows;
	bool			noShadows;
	bool			noSpecular;
	lightType_t		lightType;
	idVec3			lightRadius;
	idVec3			lightCenter;
	idVec3			target;
	idVec3			right;
	idVec3			up;
	idVec3			start;
	idVec3			end;

		// Dmap will generate an optimized shadow volume named _prelight_<lightName>
		// for the light against all the _area* models in the map.  The renderer will
		// ignore this value if the light has been moved after initial creation
		idRenderModel *	prelightModel;
	int				lightId;
	const idMaterial *shader;
	float			shaderParms[MAX_ENTITY_SHADER_PARMS];
	idSoundEmitter *referenceSound;
};

#endif // !__RENDERLIGHTPARMS_H__
