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

#include "precompiled.h"
#pragma hdrstop

#include "tr_local.h"

idCVar r_useShadowMaps( "r_useShadowMaps", "0", CVAR_RENDERER | CVAR_BOOL, "render shadow maps for shadow casting lights" );
idCVar r_shadowMapSize( "r_shadowMapSize", "512", CVAR_RENDERER | CVAR_INTEGER, "shadow map tile resolution, the atlas is rebuilt on the fly when this changes", 128, 2048 );
idCVar r_shadowMapMaxLights( "r_shadowMapMaxLights", "4", CVAR_RENDERER | CVAR_INTEGER, "maximum number of lights per view that get a shadow map, the atlas is rebuilt on the fly when this changes", 0, 16 );
idCVar r_shadowMapZNear( "r_shadowMapZNear", "1", CVAR_RENDERER | CVAR_FLOAT, "near clip plane for shadow map rendering" );
idCVar r_shadowMapBias( "r_shadowMapBias", "0.0005", CVAR_RENDERER | CVAR_FLOAT, "shadow map depth compare bias, raise this when shadow acne appears" );
idCVar r_showShadowMaps( "r_showShadowMaps", "0", CVAR_RENDERER | CVAR_BOOL, "print the shadow map slot assignment" );

// every light occupies a horizontal strip of six cube face tiles in the atlas
static const int SHADOW_MAP_CUBE_FACES = 6;

// the six cube face views: +X, +Y, -X, -Y, +Z, -Z
static const idAngles shadowMapFaceAngles[SHADOW_MAP_CUBE_FACES] = {
	idAngles( 0.0f, 0.0f, 0.0f ),
	idAngles( 0.0f, 90.0f, 0.0f ),
	idAngles( 0.0f, 180.0f, 0.0f ),
	idAngles( 0.0f, 270.0f, 0.0f ),
	idAngles( -90.0f, 0.0f, 0.0f ),
	idAngles( 90.0f, 0.0f, 0.0f )
};

static GLuint shadowMapAtlasTexture = 0;
static GLuint shadowMapFrameBuffer = 0;
static int shadowMapTileSize = 0;
static int shadowMapAtlasWidth = 0;
static int shadowMapAtlasHeight = 0;

// RB_SetMVP lives in tr_backend_draw.cpp
void RB_SetMVP( const idRenderMatrix & mvp );

/*
====================
R_ShutdownShadowMaps
====================
*/
void R_ShutdownShadowMaps() {
	if ( shadowMapFrameBuffer != 0 ) {
		gladGL.DeleteFramebuffers( 1, &shadowMapFrameBuffer );
		shadowMapFrameBuffer = 0;
	}
	if ( shadowMapAtlasTexture != 0 ) {
		gladGL.DeleteTextures( 1, &shadowMapAtlasTexture );
		shadowMapAtlasTexture = 0;
	}
	shadowMapTileSize = 0;
	shadowMapAtlasWidth = 0;
	shadowMapAtlasHeight = 0;
}

/*
====================
R_InitShadowMaps

Create the shadow map atlas depth texture and the framebuffer object that
renders into it. The atlas is a raw GL texture because it is never bound by
a material, the interaction shaders sample it directly.
====================
*/
void R_InitShadowMaps() {
	// a previous context may still have alive atlas objects
	R_ShutdownShadowMaps();

	if ( r_shadowMapMaxLights.GetInteger() <= 0 ) {
		return;
	}

	shadowMapTileSize = r_shadowMapSize.GetInteger();
	const int atlasWidth = SHADOW_MAP_CUBE_FACES * shadowMapTileSize;
	const int atlasHeight = r_shadowMapMaxLights.GetInteger() * shadowMapTileSize;

	if ( atlasWidth > glConfig.maxTextureSize || atlasHeight > glConfig.maxTextureSize ) {
		common->Printf( "shadow map atlas %ix%i exceeds the maximum texture size %i, shadow maps disabled\n", atlasWidth, atlasHeight, glConfig.maxTextureSize );
		shadowMapTileSize = 0;
		return;
	}

	gladGL.GenTextures( 1, &shadowMapAtlasTexture );
	gladGL.BindTexture( GL_TEXTURE_2D, shadowMapAtlasTexture );
	gladGL.TexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	gladGL.TexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
	gladGL.TexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
	gladGL.TexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
	gladGL.TexImage2D( GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, atlasWidth, atlasHeight, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, NULL );
	gladGL.BindTexture( GL_TEXTURE_2D, 0 );

	gladGL.GenFramebuffers( 1, &shadowMapFrameBuffer );
	gladGL.BindFramebuffer( GL_FRAMEBUFFER, shadowMapFrameBuffer );
	gladGL.FramebufferTexture2D( GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, shadowMapAtlasTexture, 0 );
	const GLenum status = gladGL.CheckFramebufferStatus( GL_FRAMEBUFFER );
	gladGL.BindFramebuffer( GL_FRAMEBUFFER, 0 );

	if ( status != GL_FRAMEBUFFER_COMPLETE ) {
		common->Warning( "the shadow map framebuffer is incomplete ( 0x%x ), shadow maps disabled", status );
		R_ShutdownShadowMaps();
		return;
	}

	// the setup binds above bypass the per unit binding caches, invalidate
	// them so idImage::Bind and R_BindShadowMapAtlas rebind the real units
	for ( int i = 0; i < MAX_MULTITEXTURE_UNITS; i++ ) {
		backEnd.glState.tmu[i].current2DMap = 0xFFFFFFFF;
		backEnd.glState.tmu[i].currentCubeMap = 0xFFFFFFFF;
	}

	shadowMapAtlasWidth = atlasWidth;
	shadowMapAtlasHeight = atlasHeight;

	common->Printf( "shadow map atlas %ix%i, %i lights x %i tiles of %ix%i\n",
		shadowMapAtlasWidth, shadowMapAtlasHeight,
		r_shadowMapMaxLights.GetInteger(), SHADOW_MAP_CUBE_FACES, shadowMapTileSize, shadowMapTileSize );
}

/*
====================
R_BindShadowMapAtlas

Bind the raw atlas texture to the currently selected texture unit. The
interaction shaders sample it through the positional samp5 sampler.
====================
*/
bool R_BindShadowMapAtlas() {
	if ( shadowMapAtlasTexture == 0 ) {
		return false;
	}
	// GL_SelectTexture only tracks the unit in this fork, idImage::Bind does
	// the real unit selection through gladGL.BindMultiTextureEXT, so the atlas
	// must go through the same path and keep the binding cache in sync
	const int texUnit = backEnd.glState.currenttmu;
	tmu_t * tmu = &backEnd.glState.tmu[texUnit];
	if ( tmu->current2DMap != shadowMapAtlasTexture ) {
		tmu->current2DMap = shadowMapAtlasTexture;
		gladGL.BindMultiTextureEXT( GL_TEXTURE0_ARB + texUnit, GL_TEXTURE_2D, shadowMapAtlasTexture );
	}
	return true;
}

/*
====================
R_UnbindShadowMapAtlas

Release the raw atlas texture from the currently selected texture unit and
dirty the binding cache so the next idImage::Bind on this unit binds again.
====================
*/
void R_UnbindShadowMapAtlas() {
	const int texUnit = backEnd.glState.currenttmu;
	gladGL.BindMultiTextureEXT( GL_TEXTURE0_ARB + texUnit, GL_TEXTURE_2D, 0 );
	backEnd.glState.tmu[texUnit].current2DMap = 0xFFFFFFFF;
}

/*
====================
RB_RenderShadowMapSurface

Render a single surface into the current shadow map tile.
====================
*/
static void RB_RenderShadowMapSurface( const drawSurf_t * surf, const idRenderMatrix & lightViewProj ) {
	const idMaterial * material = surf->material;

	// translucent surfaces don't cast shadows
	if ( material->Coverage() == MC_TRANSLUCENT ) {
		return;
	}

	// material opted out of shadow casting
	if ( !material->SurfaceCastsShadow() ) {
		return;
	}

	// entity opted out of shadow casting
	if ( surf->space->entityDef != NULL && surf->space->entityDef->parms.noShadow ) {
		return;
	}

	// some deforms may disable themselves by setting numIndexes = 0
	if ( surf->numIndexes == 0 ) {
		return;
	}

	// solid skinned casters are closed character meshes, render their back
	// faces into the shadow map so the skinning math differences between the
	// shadow map depth and the receiver depth never cause self shadow acne
	if ( surf->jointCache != 0 && material->Coverage() != MC_PERFORATED ) {
		GL_Cull( CT_BACK_SIDED );
	} else {
		GL_Cull( CT_TWO_SIDED );
	}

	// rebuild the local to world matrix from the transposed float matrix that
	// the viewEntity carries, the backend viewEntity has no idRenderMatrix copy
	float matrixData[16];
	R_MatrixTranspose( surf->space->modelMatrix, matrixData );

	idRenderMatrix modelRenderMatrix;
	for ( int i = 0; i < 4; i++ ) {
		for ( int j = 0; j < 4; j++ ) {
			modelRenderMatrix[i][j] = matrixData[i * 4 + j];
		}
	}

	idRenderMatrix mvp;
	idRenderMatrix::Multiply( lightViewProj, modelRenderMatrix, mvp );
	RB_SetMVP( mvp );

	// perforated surfaces alpha test their holes into the shadow, the same
	// way RB_FillDepthBufferGeneric alpha tests them into the depth buffer
	if ( material->Coverage() == MC_PERFORATED ) {
		const float * regs = surf->shaderRegisters;
		bool drewAlphaTested = false;

		// a material may have several alpha tested stages
		for ( int stageNum = 0; stageNum < material->GetNumStages(); stageNum++ ) {
			const shaderStage_t * pStage = material->GetStage( stageNum );

			// only the alpha tested stages carry the mask
			if ( !pStage->hasAlphaTest ) {
				continue;
			}

			// check the stage enable condition
			if ( regs[ pStage->conditionRegister ] == 0 ) {
				continue;
			}

			// cinematic stages can't serve as a static shadow mask
			if ( pStage->texture.image == NULL ) {
				continue;
			}

			drewAlphaTested = true;

			// the mask texture rides on texture unit 0
			GL_SelectTexture( 0 );
			pStage->texture.image->Bind();

			// the mask coordinates go through the stage texture matrix
			float texS[4] = { 1.0f, 0.0f, 0.0f, 0.0f };
			float texT[4] = { 0.0f, 1.0f, 0.0f, 0.0f };
			if ( pStage->texture.hasMatrix ) {
				texS[0] = regs[ pStage->texture.matrix[0][0] ];
				texS[1] = regs[ pStage->texture.matrix[0][1] ];
				texS[3] = regs[ pStage->texture.matrix[0][2] ];

				texT[0] = regs[ pStage->texture.matrix[1][0] ];
				texT[1] = regs[ pStage->texture.matrix[1][1] ];
				texT[3] = regs[ pStage->texture.matrix[1][2] ];

				// keep scrolls from generating incredibly large texture values
				if ( texS[3] < -40.0f || texS[3] > 40.0f ) {
					texS[3] -= idMath::Ftoi( texS[3] );
				}
				if ( texT[3] < -40.0f || texT[3] > 40.0f ) {
					texT[3] -= idMath::Ftoi( texT[3] );
				}
			}
			renderProgManager.SetUniformValue( RENDERPARM_TEXTUREMATRIX_S, texS );
			renderProgManager.SetUniformValue( RENDERPARM_TEXTUREMATRIX_T, texT );

			// the depth programs clip against the stage alpha test value
			const idVec4 alphaTest( regs[ pStage->alphaTestRegister ] );
			renderProgManager.SetUniformValue( RENDERPARM_ALPHA_TEST, alphaTest.ToFloatPtr() );

			if ( surf->jointCache ) {
				renderProgManager.BindShader_DepthSkinned();
			} else {
				renderProgManager.BindShader_Depth();
			}

			RB_DrawElementsWithCounters( surf );
		}

		if ( drewAlphaTested ) {
			// reset the alpha test so later solid draws are not clipped
			renderProgManager.SetUniformValue( RENDERPARM_ALPHA_TEST, vec4_zero.ToFloatPtr() );
			return;
		}

		// every alpha tested stage was conditioned off, the surface casts a
		// solid shadow
	}

	if ( surf->jointCache ) {
		renderProgManager.BindShader_DepthSkinned();
	} else {
		renderProgManager.BindShader_Depth();
	}

	RB_DrawElementsWithCounters( surf );
}

/*
====================
RB_RenderShadowMaps

Render a depth map for every shadow casting light of the current view into
the shadow map atlas. Each light uses a horizontal strip of six cube face
tiles rendered with a 90 degree fov. The per face world to atlas matrices
are stored on the viewLight so the interaction shaders can sample the
atlas in light space.
====================
*/
void RB_RenderShadowMaps() {
	renderLog.OpenBlock( "RB_RenderShadowMaps" );

	const viewDef_t * viewDef = backEnd.viewDef;

	// rebuild the atlas when the size cvars change so no vid_restart is
	// needed, the command is gutted in this fork and only rebuilds the window
	if ( r_shadowMapSize.IsModified() || r_shadowMapMaxLights.IsModified() ) {
		r_shadowMapSize.ClearModified();
		r_shadowMapMaxLights.ClearModified();
		R_InitShadowMaps();
	}

	// the slot reset must always run so the viewLight shadow map state is
	// valid for the rest of the backend even when shadow maps are off
	for ( viewLight_t * vLight = viewDef->viewLights; vLight != NULL; vLight = vLight->next ) {
		vLight->shadowMapSlot = -1;
	}

	if ( !r_useShadowMaps.GetBool() || shadowMapFrameBuffer == 0 ) {
		renderLog.CloseBlock();
		return;
	}

	// 2d rendering and guis have no lights and no shadow geometry
	if ( viewDef->viewLights == NULL || viewDef->viewEntitys == NULL ) {
		renderLog.CloseBlock();
		return;
	}

	const int maxSlots = shadowMapAtlasHeight / shadowMapTileSize;
	int slot = 0;

	gladGL.BindFramebuffer( GL_FRAMEBUFFER, shadowMapFrameBuffer );
	gladGL.DrawBuffer( GL_NONE );
	gladGL.ReadBuffer( GL_NONE );

	GL_State( GLS_DEFAULT );

	// the cube face view matrices can flip the triangle winding, only the
	// depth values matter here
	GL_Cull( CT_TWO_SIDED );

	// collect the shadow casting lights first, then assign the limited
	// atlas strips by relevance instead of view light list order: the
	// list order changes while the view turns, which let the shadowing
	// of a light pop in and out when more lights than strips are visible
	struct shadowCandidate_t {
		viewLight_t *	vLight;
		float			score;
	};
	static const int MAX_SHADOW_CANDIDATES = 32;
	shadowCandidate_t candidates[MAX_SHADOW_CANDIDATES];
	int numCandidates = 0;
	for ( viewLight_t * vLight = viewDef->viewLights; vLight != NULL; vLight = vLight->next ) {
		// fog and blend lights have no shadowing
		if ( vLight->lightShader->IsFogLight() || vLight->lightShader->IsBlendLight() ) {
			continue;
		}

		// the light was set to not cast shadows
		if ( !vLight->lightDef->LightCastsShadows() ) {
			continue;
		}

		// lights without interactions have nothing to shadow
		if ( vLight->localInteractions == NULL && vLight->globalInteractions == NULL ) {
			continue;
		}

		shadowCandidate_t candidate;
		candidate.vLight = vLight;
		if ( vLight->lightDef->parms.parallel ) {
			// a parallel light shades everything, it must never lose its strip
			candidate.score = -1.0f;
		} else {
			idVec3 delta = vLight->globalLightOrigin - viewDef->renderView.vieworg;
			candidate.score = delta.LengthSqr();
		}

		// insertion sort by score, equal scores keep the list order
		int index = numCandidates;
		while ( index > 0 && candidates[index - 1].score > candidate.score ) {
			index--;
		}
		if ( index >= MAX_SHADOW_CANDIDATES ) {
			// farther away than everything collected so far, it would not
			// get a strip once the sort is done anyway
			continue;
		}
		int last = ( numCandidates < MAX_SHADOW_CANDIDATES ) ? numCandidates : MAX_SHADOW_CANDIDATES - 1;
		for ( int j = last; j > index; j-- ) {
			candidates[j] = candidates[j - 1];
		}
		candidates[index] = candidate;
		if ( numCandidates < MAX_SHADOW_CANDIDATES ) {
			numCandidates++;
		}
	}

	for ( int candidateNum = 0; candidateNum < numCandidates && slot < maxSlots; candidateNum++ ) {
		viewLight_t * vLight = candidates[candidateNum].vLight;

		// the shadow map covers the whole light volume
		const idBounds & lightBounds = vLight->lightDef->committed.globalLightBounds;
		const float zFar = Max( ( lightBounds[1] - lightBounds[0] ).Length() * 0.5f, 64.0f );
		const float zNear = Min( r_shadowMapZNear.GetFloat(), zFar - 1.0f );

		for ( int face = 0; face < SHADOW_MAP_CUBE_FACES; face++ ) {
			const idMat3 axis = shadowMapFaceAngles[face].ToMat3();

			idRenderMatrix viewMatrix;
			idRenderMatrix::CreateViewMatrix( vLight->globalLightOrigin, axis, viewMatrix );

			idRenderMatrix projMatrix;
			idRenderMatrix::CreateProjectionMatrix( -zNear, zNear, -zNear, zNear, zNear, zFar, projMatrix );

			idRenderMatrix viewProj;
			idRenderMatrix::Multiply( projMatrix, viewMatrix, viewProj ); // apply the view matrix first, then the projection

			// store a biased world to atlas matrix on the viewLight: the first
			// two rows scale the clip position into the atlas tile and carry
			// the tile offset in the homogeneous w column, so dividing the
			// result by w gives the atlas texture coordinate, the third row
			// keeps the depth
			const float tileWidth = ( float )shadowMapTileSize / ( float )shadowMapAtlasWidth;
			const float tileHeight = ( float )shadowMapTileSize / ( float )shadowMapAtlasHeight;
			const float tileOffsetU = face * tileWidth;
			const float tileOffsetV = slot * tileHeight;

			idRenderMatrix & shadowMatrix = vLight->shadowMapMatrix[face];
			for ( int i = 0; i < 4; i++ ) {
				shadowMatrix[0][i] = 0.5f * tileWidth * viewProj[0][i] + ( 0.5f * tileWidth + tileOffsetU ) * viewProj[3][i];
				shadowMatrix[1][i] = 0.5f * tileHeight * viewProj[1][i] + ( 0.5f * tileHeight + tileOffsetV ) * viewProj[3][i];
				shadowMatrix[2][i] = viewProj[2][i];
				shadowMatrix[3][i] = viewProj[3][i];
			}

			// one atlas tile per cube face
			GL_Viewport( face * shadowMapTileSize, slot * shadowMapTileSize, shadowMapTileSize, shadowMapTileSize );
			GL_Scissor( face * shadowMapTileSize, slot * shadowMapTileSize, shadowMapTileSize, shadowMapTileSize );

			GL_Clear( false, true, false, 0, 0.0f, 0.0f, 0.0f, 0.0f );

			for ( const drawSurf_t * surf = vLight->localInteractions; surf != NULL; surf = surf->nextOnLight ) {
				RB_RenderShadowMapSurface( surf, viewProj );
			}
			for ( const drawSurf_t * surf = vLight->globalInteractions; surf != NULL; surf = surf->nextOnLight ) {
				RB_RenderShadowMapSurface( surf, viewProj );
			}
		}

		vLight->shadowMapSlot = slot;
		slot++;

		if ( r_showShadowMaps.GetBool() ) {
			common->Printf( "shadow map: light %s slot %i\n", vLight->lightShader->GetName(), slot - 1 );
		}
	}

	// back to the default framebuffer
	gladGL.BindFramebuffer( GL_FRAMEBUFFER, 0 );
	gladGL.DrawBuffer( GL_BACK );
	gladGL.ReadBuffer( GL_BACK );

	// restore the view state that RB_DrawViewInternal set up
	GL_Viewport( viewDef->viewport.x1,
		viewDef->viewport.y1,
		viewDef->viewport.x2 + 1 - viewDef->viewport.x1,
		viewDef->viewport.y2 + 1 - viewDef->viewport.y1 );
	GL_Scissor( backEnd.viewDef->viewport.x1 + viewDef->scissor.x1,
		backEnd.viewDef->viewport.y1 + viewDef->scissor.y1,
		viewDef->scissor.x2 + 1 - viewDef->scissor.x1,
		viewDef->scissor.y2 + 1 - viewDef->scissor.y1 );
	backEnd.currentScissor = viewDef->scissor;

	backEnd.glState.faceCulling = -1; // force face culling to set next time
	GL_Cull( CT_FRONT_SIDED );

	// the interaction pass must set its own matrices again
	backEnd.currentSpace = NULL;

	renderLog.CloseBlock();
}
