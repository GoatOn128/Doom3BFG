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

#include "precompiled.h"
#pragma hdrstop

#include "tr_local.h"

idCVar r_useAmbientLighting( "r_useAmbientLighting", "1", CVAR_RENDERER | CVAR_BOOL, "use the baked ambient lighting for the dynamic model fill" );
idCVar r_ambientFillScale( "r_ambientFillScale", "1.0", CVAR_RENDERER | CVAR_ARCHIVE | CVAR_FLOAT, "scale of the baked ambient fill on dynamic models" );
idCVar r_ambientBakeMinNodeSize( "r_ambientBakeMinNodeSize", "128", CVAR_RENDERER | CVAR_INTEGER, "minimum octree node size in world units for bakeAmbient", 32.0f, 512.0f );
idCVar r_ambientBakeSkyBrightness( "r_ambientBakeSkyBrightness", "0.25", CVAR_RENDERER | CVAR_FLOAT, "brightness of the sky light baked into the ambient channels" );
idCVar r_ambientBakeLightScale( "r_ambientBakeLightScale", "0.25", CVAR_RENDERER | CVAR_FLOAT, "scale of the point light contribution baked into the ambient channels" );
idCVar r_globalShadowMapSize( "r_globalShadowMapSize", "1024", CVAR_RENDERER | CVAR_INTEGER, "resolution of the baked global shadow map", 256.0f, 2048.0f );

idAmbientLighting ambientLighting;

// the file header, everything after it is raw data
struct ambientFileHeader_t {
	int		magic;
	int		numNodes;
	int		numSamples;
	float	mins[3];
	float	rootSize;
	int		depth;
};

/*
========================
idAmbientLighting::idAmbientLighting
========================
*/
idAmbientLighting::idAmbientLighting() {
	fileData = NULL;
	nodes = NULL;
	numNodes = 0;
	samples = NULL;
	numSamples = 0;
	mins.Zero();
	rootSize = 0.0f;
	depth = 0;
}

/*
========================
idAmbientLighting::~idAmbientLighting
========================
*/
idAmbientLighting::~idAmbientLighting() {
	Clear();
}

/*
========================
idAmbientLighting::Clear
========================
*/
void idAmbientLighting::Clear() {
	if ( fileData != NULL ) {
		Mem_Free( fileData );
		fileData = NULL;
	}
	nodes = NULL;
	numNodes = 0;
	samples = NULL;
	numSamples = 0;
	mins.Zero();
	rootSize = 0.0f;
	depth = 0;
}

/*
========================
idAmbientLighting::Load
========================
*/
bool idAmbientLighting::Load( const char *fileName ) {
	Clear();

	idFileLocal file( fileSystem->OpenFileRead( fileName ) );
	if ( file == NULL ) {
		return false;
	}

	ambientFileHeader_t header;
	const int fileLength = file->Length();
	if ( fileLength < (int)sizeof( header ) || file->Read( &header, sizeof( header ) ) != sizeof( header ) ) {
		common->Warning( "idAmbientLighting::Load: %s is too short\n", fileName );
		return false;
	}
	if ( header.magic != AMBIENT_MAGIC || header.numNodes <= 0 || header.numSamples < 0 ||
			header.rootSize <= 0.0f || header.depth <= 0 || header.depth > 8 ) {
		common->Warning( "idAmbientLighting::Load: %s has a bad header\n", fileName );
		return false;
	}

	const int dataLength = header.numNodes * (int)sizeof( node_t ) + header.numSamples * (int)sizeof( sample_t );
	if ( dataLength != fileLength - (int)sizeof( header ) ) {
		common->Warning( "idAmbientLighting::Load: %s has a bad size\n", fileName );
		return false;
	}

	fileData = (byte *)Mem_Alloc( dataLength, TAG_RENDER );
	file->Read( fileData, dataLength );

	nodes = (const node_t *)fileData;
	numNodes = header.numNodes;
	samples = (const sample_t *)( fileData + header.numNodes * (int)sizeof( node_t ) );
	numSamples = header.numSamples;
	mins.Set( header.mins[0], header.mins[1], header.mins[2] );
	rootSize = header.rootSize;
	depth = header.depth;

	return true;
}

/*
========================
idAmbientLighting::SampleChannels

Walks the octree down to the leaf cell that contains the point and blends
the corner samples of the cell trilinearly. Missing corner samples lose
their weight to the remaining corners.
========================
*/
bool idAmbientLighting::SampleChannels( const idVec3 &point, float channels[6][3] ) const {
	if ( !IsLoaded() ) {
		return false;
	}
	if ( point.x < mins.x || point.x > mins.x + rootSize ||
			point.y < mins.y || point.y > mins.y + rootSize ||
			point.z < mins.z || point.z > mins.z + rootSize ) {
		return false;
	}

	// walk down the octree, the child bits match the octant order
	const node_t * node = &nodes[0];
	idVec3 nodeMins = mins;
	float size = rootSize;
	for ( int level = 0; level < depth; level++ ) {
		const float half = size * 0.5f;
		const int x = ( point.x >= nodeMins.x + half ) ? 1 : 0;
		const int y = ( point.y >= nodeMins.y + half ) ? 1 : 0;
		const int z = ( point.z >= nodeMins.z + half ) ? 1 : 0;
		const int child = node->children[x | ( y << 1 ) | ( z << 2 )];
		if ( child == AMBIENT_EMPTY ) {
			return false;
		}
		node = &nodes[child];
		nodeMins.x += x * half;
		nodeMins.y += y * half;
		nodeMins.z += z * half;
		size = half;
	}

	// trilinear blend of the eight corner samples of the leaf cell
	float fx = ( point.x - nodeMins.x ) / size;
	float fy = ( point.y - nodeMins.y ) / size;
	float fz = ( point.z - nodeMins.z ) / size;
	fx = idMath::ClampFloat( 0.0f, 1.0f, fx );
	fy = idMath::ClampFloat( 0.0f, 1.0f, fy );
	fz = idMath::ClampFloat( 0.0f, 1.0f, fz );

	float total = 0.0f;
	float blend[6][3];
	for ( int c = 0; c < AMBIENT_NUM_CHANNELS; c++ ) {
		blend[c][0] = 0.0f;
		blend[c][1] = 0.0f;
		blend[c][2] = 0.0f;
	}

	for ( int i = 0; i < 8; i++ ) {
		const int corner = node->children[i];
		if ( corner == AMBIENT_EMPTY ) {
			continue;
		}
		const float wx = ( i & 1 ) ? fx : 1.0f - fx;
		const float wy = ( ( i >> 1 ) & 1 ) ? fy : 1.0f - fy;
		const float wz = ( ( i >> 2 ) & 1 ) ? fz : 1.0f - fz;
		const float weight = wx * wy * wz;
		if ( weight <= 0.0f ) {
			continue;
		}
		total += weight;
		const sample_t & sample = samples[corner];
		for ( int c = 0; c < AMBIENT_NUM_CHANNELS; c++ ) {
			for ( int k = 0; k < 3; k++ ) {
				blend[c][k] += weight * sample.channels[c][k] * ( 1.0f / 255.0f );
			}
		}
	}

	if ( total <= 0.0f ) {
		return false;
	}

	const float invTotal = 1.0f / total;
	for ( int c = 0; c < AMBIENT_NUM_CHANNELS; c++ ) {
		for ( int k = 0; k < 3; k++ ) {
			channels[c][k] = blend[c][k] * invTotal;
		}
	}
	return true;
}

/*
========================
idAmbientLighting::SampleFillColor
========================
*/
bool idAmbientLighting::SampleFillColor( const idVec3 &point, idVec3 &color ) const {
	float channels[AMBIENT_NUM_CHANNELS][3];
	if ( !SampleChannels( point, channels ) ) {
		return false;
	}
	color.Zero();
	for ( int c = 0; c < AMBIENT_NUM_CHANNELS; c++ ) {
		color.x += channels[c][0];
		color.y += channels[c][1];
		color.z += channels[c][2];
	}
	color *= 1.0f / (float)AMBIENT_NUM_CHANNELS;
	return true;
}

/*
===============================================================================

	The bake

===============================================================================
*/

// the six channel directions
static const idVec3 ambientChannelDirs[AMBIENT_NUM_CHANNELS] = {
	idVec3( 1.0f, 0.0f, 0.0f ),
	idVec3( -1.0f, 0.0f, 0.0f ),
	idVec3( 0.0f, 1.0f, 0.0f ),
	idVec3( 0.0f, -1.0f, 0.0f ),
	idVec3( 0.0f, 0.0f, 1.0f ),
	idVec3( 0.0f, 0.0f, -1.0f )
};

const int AMBIENT_MAX_REGISTERS = 512;

struct ambientBakeLight_t {
	idVec3			origin;
	idBounds		bounds;
	idVec3			color;
	float			radius;
};

// the working data of the octree build
struct ambientBakeContext_t {
	idRenderWorldLocal *			world;
	idVec3							mins;			// the corner of the root cube
	float							rootSize;
	int								depthLevels;
	float							leafSize;
	int								gridDim;
	idList<int, TAG_RENDER>			sampleGrid;		// sample index per grid corner, -1 when not baked yet
	idList<idAmbientLighting::sample_t, TAG_RENDER>	samples;
	idList<idAmbientLighting::node_t, TAG_RENDER>		nodes;
	idList<ambientBakeLight_t, TAG_RENDER>			lights;
	float							skyBrightness;
	float							lightScale;
};

/*
========================
R_GetLightColor

Evaluates the color registers of the light shader to get the light color.
========================
*/
static bool R_GetLightColor( const idRenderLightLocal * light, idVec3 &color ) {
	const idMaterial * shader = light->lightShader;
	if ( shader == NULL || shader->GetNumStages() == 0 ) {
		return false;
	}
	const float * registers = shader->ConstantRegisters();
	float registerBuffer[AMBIENT_MAX_REGISTERS];
	if ( registers == NULL ) {
		const int numRegisters = shader->GetNumRegisters();
		if ( numRegisters <= 0 || numRegisters > AMBIENT_MAX_REGISTERS ) {
			return false;
		}
		float globalParms[MAX_GLOBAL_SHADER_PARMS];
		memset( globalParms, 0, sizeof( globalParms ) );
		shader->EvaluateRegisters( registerBuffer, light->parms.shaderParms, globalParms, 0.0f, light->parms.referenceSound );
		registers = registerBuffer;
	}
	const shaderStage_t * stage = shader->GetStage( 0 );
	color.Set( registers[stage->color.registers[0]], registers[stage->color.registers[1]], registers[stage->color.registers[2]] );
	return true;
}

/*
========================
R_ComputeSampleChannels

Traces the six axis rays for the sky visibility and accumulates the
visible point lights onto the axis they come from.
========================
*/
static void R_ComputeSampleChannels( ambientBakeContext_t & ctx, const idVec3 & point, idVec3 channels[AMBIENT_NUM_CHANNELS] ) {
	for ( int c = 0; c < AMBIENT_NUM_CHANNELS; c++ ) {
		channels[c].Zero();
	}

	modelTrace_t trace;
	const float rayLength = ctx.rootSize + 64.0f;

	// sky light, a direction with a clear ray out of the world gets the
	// sky color, a direction that ends on geometry gets nothing, there is
	// no bounced light in the bake
	const idVec3 skyColor( 0.30f, 0.34f, 0.40f );
	for ( int c = 0; c < AMBIENT_NUM_CHANNELS; c++ ) {
		const idVec3 end = point + ambientChannelDirs[c] * rayLength;
		ctx.world->Trace( trace, point, end, 0.0f, true, false );
		if ( trace.fraction >= 1.0f ) {
			channels[c] += skyColor * ctx.skyBrightness;
		}
	}

	// point light contribution, the direct part of these lights is still
	// applied by the interactions at runtime, so this is scaled down to
	// fake the bounced ambient part
	for ( int i = 0; i < ctx.lights.Num(); i++ ) {
		const ambientBakeLight_t & light = ctx.lights[i];

		idVec3 dir = light.origin - point;
		const float dist = dir.Normalize();
		if ( dist > light.radius ) {
			continue;
		}

		ctx.world->Trace( trace, point, light.origin, 0.0f, true, false );
		if ( trace.fraction < 1.0f ) {
			continue;
		}

		float falloff = 1.0f - dist / light.radius;
		falloff = falloff * falloff;

		const idVec3 contribution = light.color * ( falloff * ctx.lightScale );
		for ( int c = 0; c < AMBIENT_NUM_CHANNELS; c++ ) {
			const float axisWeight = dir * ambientChannelDirs[c];
			if ( axisWeight > 0.0f ) {
				channels[c] += contribution * axisWeight;
			}
		}
	}
}

/*
========================
R_AmbientEnsureSample

Creates the sample of a grid corner on demand and caches its index.
========================
*/
static int R_AmbientEnsureSample( ambientBakeContext_t & ctx, int gx, int gy, int gz ) {
	// the grid has gridDim + 1 corners on every axis, keep the indices in range
	gx = idMath::ClampInt( 0, ctx.gridDim, gx );
	gy = idMath::ClampInt( 0, ctx.gridDim, gy );
	gz = idMath::ClampInt( 0, ctx.gridDim, gz );
	const int gridIndex = ( gz * ( ctx.gridDim + 1 ) + gy ) * ( ctx.gridDim + 1 ) + gx;
	if ( ctx.sampleGrid[gridIndex] != -1 ) {
		return ctx.sampleGrid[gridIndex];
	}

	const idVec3 point = ctx.mins + idVec3( gx, gy, gz ) * ctx.leafSize;
	idVec3 channels[AMBIENT_NUM_CHANNELS];
	R_ComputeSampleChannels( ctx, point, channels );

	idAmbientLighting::sample_t sample;
	for ( int c = 0; c < AMBIENT_NUM_CHANNELS; c++ ) {
		for ( int k = 0; k < 3; k++ ) {
			float value = channels[c][k] * 255.0f + 0.5f;
			value = idMath::ClampFloat( 0.0f, 255.0f, value );
			sample.channels[c][k] = (byte)value;
		}
	}
	sample.origin[0] = (short)gx;
	sample.origin[1] = (short)gy;
	sample.origin[2] = (short)gz;

	const int index = ctx.samples.Append( sample );
	ctx.sampleGrid[gridIndex] = index;

	if ( ctx.samples.Num() % 4096 == 0 ) {
		common->Printf( "bakeAmbient: %d samples...\n", ctx.samples.Num() );
	}

	return index;
}

/*
========================
R_AmbientNodeUseful

A node is subdivided when one of its probe points is inside a valid area
or when a light reaches into it, otherwise it stays empty.
========================
*/
static bool R_AmbientNodeUseful( const ambientBakeContext_t & ctx, const idVec3 & nodeMins, float size ) {
	const float half = size * 0.5f;
	for ( int ix = 0; ix <= 2; ix++ ) {
		for ( int iy = 0; iy <= 2; iy++ ) {
			for ( int iz = 0; iz <= 2; iz++ ) {
				const idVec3 probe = nodeMins + idVec3( ix * half, iy * half, iz * half );
				if ( ctx.world->PointInArea( probe ) >= 0 ) {
					return true;
				}
			}
		}
	}

	const idBounds nodeBounds( nodeMins, nodeMins + idVec3( size, size, size ) );
	for ( int i = 0; i < ctx.lights.Num(); i++ ) {
		if ( ctx.lights[i].bounds.IntersectsBounds( nodeBounds ) ) {
			return true;
		}
	}
	return false;
}

/*
========================
R_AmbientBuildNode_r
========================
*/
static int R_AmbientBuildNode_r( ambientBakeContext_t & ctx, const idVec3 & nodeMins, float size, int level ) {
	idAmbientLighting::node_t node;
	for ( int i = 0; i < 8; i++ ) {
		node.children[i] = AMBIENT_EMPTY;
	}
	const int nodeIndex = ctx.nodes.Append( node );

	if ( level >= ctx.depthLevels ) {
		// leaf level, the children are the corner samples of the cell
		// float error can push a coordinate past the max face, round to the
		// nearest cell and clamp so the sample grid stays in bounds
		const int gx = idMath::ClampInt( 0, ctx.gridDim - 1, idMath::Ftoi( ( nodeMins.x - ctx.mins.x ) / ctx.leafSize + 0.5f ) );
		const int gy = idMath::ClampInt( 0, ctx.gridDim - 1, idMath::Ftoi( ( nodeMins.y - ctx.mins.y ) / ctx.leafSize + 0.5f ) );
		const int gz = idMath::ClampInt( 0, ctx.gridDim - 1, idMath::Ftoi( ( nodeMins.z - ctx.mins.z ) / ctx.leafSize + 0.5f ) );
		for ( int i = 0; i < 8; i++ ) {
			ctx.nodes[nodeIndex].children[i] = (unsigned short)R_AmbientEnsureSample(
				ctx, gx + ( i & 1 ), gy + ( ( i >> 1 ) & 1 ), gz + ( ( i >> 2 ) & 1 ) );
		}
	} else if ( R_AmbientNodeUseful( ctx, nodeMins, size ) ) {
		const float half = size * 0.5f;
		for ( int i = 0; i < 8; i++ ) {
			const idVec3 childMins = nodeMins + idVec3( ( i & 1 ) * half, ( ( i >> 1 ) & 1 ) * half, ( ( i >> 2 ) & 1 ) * half );
			ctx.nodes[nodeIndex].children[i] = (unsigned short)R_AmbientBuildNode_r( ctx, childMins, half, level + 1 );
		}
	}

	return nodeIndex;
}

/*
========================
R_BakeAmbient

Builds the ambient octree of the world and writes it out.
========================
*/
static void R_BakeAmbient( idRenderWorldLocal * world, const char *fileName ) {
	// the world bounds from the area models
	idBounds worldBounds;
	worldBounds.Clear();
	for ( int i = 0; i < world->localModels.Num(); i++ ) {
		const idRenderModel * model = world->localModels[i];
		if ( model == NULL ) {
			continue;
		}
		for ( int s = 0; s < model->NumSurfaces(); s++ ) {
			const modelSurface_t * surface = model->Surface( s );
			if ( surface == NULL || surface->geometry == NULL ) {
				continue;
			}
			const srfTriangles_t * geometry = surface->geometry;
			// a surface may have no readable triangle data, skip it instead of crashing the bake
			if ( geometry->verts == NULL || geometry->indexes == NULL ||
					geometry->numVerts <= 0 || geometry->numIndexes < 3 ) {
				continue;
			}
			worldBounds.AddPoint( geometry->bounds[0] );
			worldBounds.AddPoint( geometry->bounds[1] );
		}
	}
	if ( worldBounds.IsCleared() ) {
		common->Warning( "bakeAmbient: the world has no geometry\n" );
		return;
	}

	// extend the bounds to a cube, the octree subdivides cubes
	ambientBakeContext_t ctx;
	ctx.world = world;
	const idVec3 center = worldBounds.GetCenter();
	const idVec3 extents = worldBounds[1] - worldBounds[0];
	ctx.rootSize = Max( extents.x, Max( extents.y, extents.z ) );
	if ( ctx.rootSize <= 0.0f ) {
		common->Warning( "bakeAmbient: the world has no extent\n" );
		return;
	}
	ctx.mins = center - idVec3( ctx.rootSize, ctx.rootSize, ctx.rootSize ) * 0.5f;

	// the octree subdivides down to the requested node size, five levels
	// keep the node and sample indices inside the 16 bit child entries
	const int minNodeSize = r_ambientBakeMinNodeSize.GetInteger();
	ctx.depthLevels = 0;
	while ( ctx.depthLevels < 5 && ctx.rootSize / (float)( 1 << ( ctx.depthLevels + 1 ) ) >= (float)minNodeSize ) {
		ctx.depthLevels++;
	}
	ctx.leafSize = ctx.rootSize / (float)( 1 << ctx.depthLevels );
	ctx.gridDim = 1 << ctx.depthLevels;

	// gather the lights that contribute to the bake, fog, blend and
	// ambient lights wash everything uniformly and stay runtime only
	for ( int i = 0; i < world->lightDefs.Num(); i++ ) {
		const idRenderLightLocal * light = world->lightDefs[i];
		if ( light == NULL ) {
			continue;
		}
		const idMaterial * shader = light->lightShader;
		if ( shader == NULL || shader->IsFogLight() || shader->IsBlendLight() || shader->IsAmbientLight() ) {
			continue;
		}
		ambientBakeLight_t bakeLight;
		if ( !R_GetLightColor( light, bakeLight.color ) ) {
			continue;
		}
		bakeLight.origin = light->committed.globalLightOrigin;
		bakeLight.bounds = light->committed.globalLightBounds;
		bakeLight.radius = light->committed.globalLightBounds.GetRadius();
		if ( bakeLight.radius <= 0.0f ) {
			continue;
		}
		ctx.lights.Append( bakeLight );
	}

	ctx.skyBrightness = r_ambientBakeSkyBrightness.GetFloat();
	ctx.lightScale = r_ambientBakeLightScale.GetFloat();

	common->Printf( "bakeAmbient: %d lights, leaf size %.0f, grid %d\n", ctx.lights.Num(), ctx.leafSize, ctx.gridDim );

	// the sample index of every grid corner, created on demand
	ctx.sampleGrid.SetNum( ( ctx.gridDim + 1 ) * ( ctx.gridDim + 1 ) * ( ctx.gridDim + 1 ) );
	for ( int i = 0; i < ctx.sampleGrid.Num(); i++ ) {
		ctx.sampleGrid[i] = -1;
	}

	common->Printf( "bakeAmbient: gathering ambient samples...\n" );

	R_AmbientBuildNode_r( ctx, ctx.mins, ctx.rootSize, 0 );

	idFileLocal file( fileSystem->OpenFileWrite( fileName, "fs_basepath" ) );
	if ( file == NULL ) {
		common->Warning( "bakeAmbient: could not open %s for writing\n", fileName );
		return;
	}

	ambientFileHeader_t header;
	header.magic = AMBIENT_MAGIC;
	header.numNodes = ctx.nodes.Num();
	header.numSamples = ctx.samples.Num();
	header.mins[0] = ctx.mins.x;
	header.mins[1] = ctx.mins.y;
	header.mins[2] = ctx.mins.z;
	header.rootSize = ctx.rootSize;
	header.depth = ctx.depthLevels;
	file->Write( &header, sizeof( header ) );
	file->Write( ctx.nodes.Ptr(), ctx.nodes.Num() * (int)sizeof( idAmbientLighting::node_t ) );
	file->Write( ctx.samples.Ptr(), ctx.samples.Num() * (int)sizeof( idAmbientLighting::sample_t ) );

	common->Printf( "bakeAmbient: wrote %s, %d nodes, %d samples\n", fileName, ctx.nodes.Num(), ctx.samples.Num() );
}

/*
========================
R_BakeAmbient_f
========================
*/
void R_BakeAmbient_f( const idCmdArgs &args ) {
	idRenderWorldLocal * world = tr.primaryWorld;
	if ( world == NULL ) {
		common->Warning( "bakeAmbient: no world is loaded\n" );
		return;
	}
	if ( world->mapName.Length() == 0 ) {
		common->Warning( "bakeAmbient: the current world has no map name\n" );
		return;
	}

	idStr base( world->mapName );
	base.StripFileExtension();

	common->Printf( "bakeAmbient: baking %s...\n", base.c_str() );
	R_BakeGlobalShadows( world, ( base + "_globalShadows2.bin" ).c_str() );
	R_BakeAmbient( world, ( base + ".ambient" ).c_str() );

	// reload what was just baked so it can be tested without a map reload
	R_LoadAmbientAndGlobalShadows( world->mapName );
}

/*
========================
R_LoadAmbientAndGlobalShadows
========================
*/
void R_LoadAmbientAndGlobalShadows( const char *mapName ) {
	ambientLighting.Clear();
	globalShadows.Clear();
	if ( mapName == NULL || mapName[0] == '\0' ) {
		return;
	}

	idStr base( mapName );
	base.StripFileExtension();

	if ( ambientLighting.Load( ( base + ".ambient" ).c_str() ) ) {
		common->Printf( "loaded %s.ambient\n", base.c_str() );
	}
	if ( globalShadows.Load( ( base + "_globalShadows2.bin" ).c_str() ) ) {
		common->Printf( "loaded %s_globalShadows2.bin\n", base.c_str() );
	}
}
