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

#include "precompiled.h"
#pragma hdrstop

#include "tr_local.h"

#include "Q3Bsp.h"

#include "../idlib/MapFile.h"
#include "../idlib/containers/HashIndex.h"

// on disk constants of the IBSP format, versions 46 (Q3) and 47 (RtCW/ET),
// layout referenced from the vendored ET SDK (GPLv3, license compatible)
static const int	Q3BSP_IDENT			= ( 'I' ) | ( 'B' << 8 ) | ( 'S' << 16 ) | ( 'P' << 24 );
static const int	Q3BSP_VERSION_Q3		= 46;
static const int	Q3BSP_VERSION_ET		= 47;
static const int	Q3BSP_NUM_LUMPS		= 17;

static const int	LUMP_ENTITIES			= 0;
static const int	LUMP_SHADERS			= 1;
static const int	LUMP_PLANES				= 2;
static const int	LUMP_MODELS				= 7;
static const int	LUMP_BRUSHES			= 8;
static const int	LUMP_BRUSHSIDES		= 9;
static const int	LUMP_DRAWVERTS			= 10;
static const int	LUMP_DRAWINDEXES		= 11;
static const int	LUMP_SURFACES			= 13;
static const int	LUMP_LIGHTMAPS			= 14;
static const int	LUMP_LIGHTGRID			= 15;
static const int	LUMP_VISIBILITY		= 16;

// fixed struct sizes and field offsets in bytes
static const int	BSP_SHADER_SIZE		= 72;		// char name[64] + int surfaceFlags + int contentFlags
static const int	BSP_PLANE_SIZE			= 16;		// float normal[3] + float dist
static const int	BSP_MODEL_SIZE			= 40;		// float mins[3] + float maxs[3] + 4 ints
static const int	BSP_BRUSH_SIZE			= 12;		// int firstSide + int numSides + int shaderNum
static const int	BSP_BRUSHSIDE_SIZE	= 8;			// int planeNum + int shaderNum
static const int	BSP_DRAWVERT_SIZE		= 44;		// float xyz[3] + float st[2] + float lightmap[2] + float normal[3] + byte color[4]
static const int	BSP_SURFACE_SIZE		= 104;
static const int	BSP_LIGHTMAP_SIZE		= 128 * 128 * 3;	// Q3 stores RGB blocks
static const int	BSP_LIGHTMAP_ET_SIZE	= 128 * 128 * 4;	// RtCW/ET add an alpha channel

// drawvert field offsets
static const int	VERT_XYZ				= 0;
static const int	VERT_ST					= 12;
static const int	VERT_LIGHTMAP			= 20;
static const int	VERT_NORMAL				= 28;
static const int	VERT_COLOR				= 40;

// surface field offsets inside the 104 byte face struct
static const int	SURF_SHADERNUM		= 0;
static const int	SURF_TYPE				= 8;
static const int	SURF_FIRSTVERT		= 12;
static const int	SURF_NUMVERTS			= 16;
static const int	SURF_FIRSTINDEX		= 20;
static const int	SURF_NUMINDEXES		= 24;
static const int	SURF_LIGHTMAPNUM		= 28;
static const int	SURF_LMX					= 32;
static const int	SURF_LMY					= 36;
static const int	SURF_LMW					= 40;
static const int	SURF_LMH					= 44;
static const int	SURF_LMORIGIN			= 48;
static const int	SURF_LMVECS			= 60;
static const int	SURF_PATCHWIDTH		= 96;
static const int	SURF_PATCHHEIGHT		= 100;

// face types
static const int	MST_PLANAR				= 1;
static const int	MST_PATCH				= 2;
static const int	MST_TRIANGLE_SOUP	= 3;
static const int	MST_FLARE				= 4;
static const int	MST_FOLIAGE			= 5;

// patches tessellate with four segments per control grid step
static const int	PATCH_TESSELATION	= 4;

// surface split before the 16 bit index range would wrap
static const int	MAX_SURFACE_VERTS	= 65535;

// lightmap conversion tuning
static const int	LIGHT_GRID_CELL		= 128;		// world units per light merge cell

static idCVar	r_q3bspMaxLights( "r_q3bspMaxLights", "256", CVAR_INTEGER | CVAR_ARCHIVE, "maximum number of point lights converted from Q3 BSP lightmaps" );
static idCVar	r_q3bspLightScale( "r_q3bspLightScale", "1", CVAR_FLOAT | CVAR_ARCHIVE, "brightness scale for lights converted from Q3 BSP lightmaps" );
static idCVar	r_q3bspLightSpacing( "r_q3bspLightSpacing", "8", CVAR_INTEGER | CVAR_ARCHIVE, "luxels between Q3 BSP lightmap samples" );

/*
===============================================================================

	Byte level readers, endian safe by construction

===============================================================================
*/

static ID_INLINE int BspReadInt( const byte *base, int ofs ) {
	return (int)base[ofs] | ( (int)base[ofs+1] << 8 ) | ( (int)base[ofs+2] << 16 ) | ( (int)base[ofs+3] << 24 );
}

static ID_INLINE float BspReadFloat( const byte *base, int ofs ) {
	// avoid type punning, the compiler folds this into a plain load
	byte out[4];
	out[0] = base[ofs];
	out[1] = base[ofs+1];
	out[2] = base[ofs+2];
	out[3] = base[ofs+3];
	return *(float *)out;
}

static ID_INLINE void BspReadText( const byte *base, int ofs, char *out, int maxLen ) {
	int i;
	for ( i = 0; i < maxLen - 1 && base[ofs+i] != 0; i++ ) {
		out[i] = base[ofs+i];
	}
	out[i] = 0;
}

static ID_INLINE idVec3 BspReadVec3( const byte *base, int ofs ) {
	return idVec3( BspReadFloat( base, ofs ), BspReadFloat( base, ofs+4 ), BspReadFloat( base, ofs+8 ) );
}

/*
===============================================================================

	File loading

===============================================================================
*/

struct q3bspFile_t {
	idStr			fileName;		// "maps/<name>.bsp"
	int				version;		// 46 = Q3, 47 = RtCW/ET
	ID_TIME_T		fileTime;
	byte *			data;			// whole file, owned
	int				len;
	const byte *	lumps[Q3BSP_NUM_LUMPS];
	int				lumpLens[Q3BSP_NUM_LUMPS];

	void		Free();
	bool		Load( const char *name );
};

/*
================
q3bspFile_t::Free
================
*/
void q3bspFile_t::Free() {
	if ( data != NULL ) {
		fileSystem->FreeFile( data );
		data = NULL;
	}
	len = 0;
}

/*
================
q3bspFile_t::Load
================
*/
bool q3bspFile_t::Load( const char *name ) {
	data = NULL;
	len = 0;
	fileTime = FILE_NOT_FOUND_TIMESTAMP;
	version = 0;
	for ( int i = 0; i < Q3BSP_NUM_LUMPS; i++ ) {
		lumps[i] = NULL;
		lumpLens[i] = 0;
	}

	fileName = name;
	fileName.SetFileExtension( "bsp" );

	void *buffer = NULL;
	len = fileSystem->ReadFile( fileName, &buffer, &fileTime );
	if ( len <= 0 || buffer == NULL ) {
		len = 0;
		return false;
	}
	data = (byte *)buffer;

	if ( len < 8 + Q3BSP_NUM_LUMPS * 8 ) {
		common->Warning( "Q3Bsp: %s is too small to be a BSP\n", fileName.c_str() );
		Free();
		return false;
	}

	int ident = BspReadInt( data, 0 );
	version = BspReadInt( data, 4 );
	if ( ident != Q3BSP_IDENT || ( version != Q3BSP_VERSION_Q3 && version != Q3BSP_VERSION_ET ) ) {
		Free();
		return false;
	}

	for ( int i = 0; i < Q3BSP_NUM_LUMPS; i++ ) {
		int ofs = BspReadInt( data, 8 + i * 8 );
		int size = BspReadInt( data, 12 + i * 8 );
		if ( ofs < 0 || size < 0 || ofs + size > len ) {
			common->Warning( "Q3Bsp: %s has a bad lump table\n", fileName.c_str() );
			Free();
			return false;
		}
		lumps[i] = data + ofs;
		lumpLens[i] = size;
	}
	return true;
}

static ID_INLINE int BspNumShaders( const q3bspFile_t *bsp ) {
	return bsp->lumpLens[LUMP_SHADERS] / BSP_SHADER_SIZE;
}

static ID_INLINE int BspNumPlanes( const q3bspFile_t *bsp ) {
	return bsp->lumpLens[LUMP_PLANES] / BSP_PLANE_SIZE;
}

static ID_INLINE int BspNumModels( const q3bspFile_t *bsp ) {
	return bsp->lumpLens[LUMP_MODELS] / BSP_MODEL_SIZE;
}

static ID_INLINE int BspNumBrushSides( const q3bspFile_t *bsp ) {
	return bsp->lumpLens[LUMP_BRUSHSIDES] / BSP_BRUSHSIDE_SIZE;
}

static ID_INLINE int BspNumVerts( const q3bspFile_t *bsp ) {
	return bsp->lumpLens[LUMP_DRAWVERTS] / BSP_DRAWVERT_SIZE;
}

static ID_INLINE int BspNumFaces( const q3bspFile_t *bsp ) {
	return bsp->lumpLens[LUMP_SURFACES] / BSP_SURFACE_SIZE;
}

static ID_INLINE int BspNumIndexes( const q3bspFile_t *bsp ) {
	return bsp->lumpLens[LUMP_DRAWINDEXES] / 4;
}

static ID_INLINE int BspNumLightmaps( const q3bspFile_t *bsp ) {
	int stride = ( bsp->version == Q3BSP_VERSION_ET ) ? BSP_LIGHTMAP_ET_SIZE : BSP_LIGHTMAP_SIZE;
	return bsp->lumpLens[LUMP_LIGHTMAPS] / stride;
}

// reads the NUL padded shader name of a face
static void BspGetShaderName( const q3bspFile_t *bsp, int shaderNum, char *out, int maxLen ) {
	const byte *sh = bsp->lumps[LUMP_SHADERS] + shaderNum * BSP_SHADER_SIZE;
	BspReadText( sh, 0, out, Min( maxLen, 64 ) );
}

static ID_INLINE const byte *BspFace( const q3bspFile_t *bsp, int faceNum ) {
	return bsp->lumps[LUMP_SURFACES] + faceNum * BSP_SURFACE_SIZE;
}

static ID_INLINE int BspReadFaceInt( const q3bspFile_t *bsp, int faceNum, int ofs ) {
	return BspReadInt( BspFace( bsp, faceNum ), ofs );
}

/*
===============================================================================

	idMapFile conversion for the collision model

===============================================================================
*/

/*
================
Q3BspConvertModelBrushes

Converts the brushes of one BSP model to idMapBrush primitives on the entity.
The BSP planes have outward normals with the interior on the negative side,
which is exactly what the Doom 3 map brush parser produces.
================
*/
static void Q3BspConvertModelBrushes( const q3bspFile_t *bsp, idMapEntity *mapEnt, int firstBrush, int numBrushes ) {
	char shaderName[64];
	for ( int b = 0; b < numBrushes; b++ ) {
		const byte *brush = bsp->lumps[LUMP_BRUSHES] + ( firstBrush + b ) * BSP_BRUSH_SIZE;
		int firstSide = BspReadInt( brush, 0 );
		int numSides = BspReadInt( brush, 4 );
		int shaderNum = BspReadInt( brush, 8 );

		if ( shaderNum < 0 || shaderNum >= BspNumShaders( bsp ) ) {
			continue;
		}
		if ( firstSide < 0 || numSides < 0 || firstSide + numSides > BspNumBrushSides( bsp ) ) {
			continue;
		}

		idMapBrush *mapBrush = new (TAG_IDLIB) idMapBrush();
		for ( int s = 0; s < numSides; s++ ) {
			const byte *side = bsp->lumps[LUMP_BRUSHSIDES] + ( firstSide + s ) * BSP_BRUSHSIDE_SIZE;
			int planeNum = BspReadInt( side, 0 );
			int sideShaderNum = BspReadInt( side, 4 );

			if ( planeNum < 0 || planeNum >= BspNumPlanes( bsp ) ) {
				continue;
			}
			int materialNum = ( sideShaderNum >= 0 && sideShaderNum < BspNumShaders( bsp ) ) ? sideShaderNum : shaderNum;

			BspGetShaderName( bsp, materialNum, shaderName, sizeof( shaderName ) );
			const byte *plane = bsp->lumps[LUMP_PLANES] + planeNum * BSP_PLANE_SIZE;
			idVec3 normal = BspReadVec3( plane, 0 );
			float dist = BspReadFloat( plane, 12 );

			idMapBrushSide *mapSide = new (TAG_IDLIB) idMapBrushSide();
			mapSide->SetMaterial( shaderName );
			mapSide->SetPlane( idPlane( normal, dist ) );
			// the Q3 texel scale, matches the stock Q3 map parser
			idVec3 texMat[2];
			texMat[0].Set( 0.03125f, 0.0f, 0.0f );
			texMat[1].Set( 0.0f, 0.03125f, 0.0f );
			mapSide->SetTextureMatrix( texMat );
			mapBrush->AddSide( mapSide );
		}

		if ( mapBrush->GetNumSides() > 0 ) {
			mapEnt->AddPrimitive( mapBrush );
		} else {
			delete mapBrush;
		}
	}
}

/*
================
Q3Bsp_ConvertToMapFile

Converts a Q3/RtCW/ET .bsp to an idMapFile that the stock collision model
manager consumes. Returns NULL when no .bsp exists for the name.
================
*/
idMapFile *Q3Bsp_ConvertToMapFile( const char *mapName ) {
	q3bspFile_t bsp;
	if ( !bsp.Load( mapName ) ) {
		return NULL;
	}

	idStr bspMapName = bsp.fileName;
	bspMapName.SetFileExtension( "map" );

	idMapFile *mapFile = new (TAG_GAME) idMapFile();

	// parse the entities lump with the stock map entity parser, the lexer
	// reads the buffer in place so free it only after parsing
	idLexer src( LEXFL_NOSTRINGCONCAT | LEXFL_NOSTRINGESCAPECHARS | LEXFL_ALLOWPATHNAMES );
	int entitiesLen = bsp.lumpLens[LUMP_ENTITIES];
	byte *entityText = new byte[entitiesLen + 1];
	memcpy( entityText, bsp.lumps[LUMP_ENTITIES], entitiesLen );
	entityText[entitiesLen] = 0;
	src.LoadMemory( (const char *)entityText, entitiesLen, bsp.fileName.c_str() );

	idMapEntity *mapEnt;
	while ( ( mapEnt = idMapEntity::Parse( src, ( mapFile->GetNumEntities() == 0 ), CURRENT_MAP_VERSION ) ) != NULL ) {
		mapFile->AddEntity( mapEnt );
	}
	delete[] entityText;

	// the worldspawn must be named as such even if the BSP omitted it
	if ( mapFile->GetNumEntities() == 0 ) {
		common->Warning( "Q3Bsp: %s has no entities\n", bsp.fileName.c_str() );
		bsp.Free();
		delete mapFile;
		return NULL;
	}
	idMapEntity *world = mapFile->GetEntity( 0 );
	world->epairs.Set( "classname", "worldspawn" );

	// worldspawn is model *0 in every BSP
	const char *worldModel = world->epairs.GetString( "model" );
	if ( worldModel == NULL || worldModel[0] == 0 ) {
		world->epairs.Set( "model", "*0" );
	}

	int numModels = BspNumModels( &bsp );
	for ( int m = 0; m < numModels; m++ ) {
		const byte *model = bsp.lumps[LUMP_MODELS] + m * BSP_MODEL_SIZE;
		int firstBrush = BspReadInt( model, 32 );
		int numBrushes = BspReadInt( model, 36 );
		if ( numBrushes <= 0 ) {
			continue;
		}

		idMapEntity *ent = world;
		if ( m > 0 ) {
			// bmodels attach to the entity that references them as *N
			idStr modelName = va( "*%i", m );
			ent = NULL;
			for ( int e = 0; e < mapFile->GetNumEntities(); e++ ) {
				idMapEntity *check = mapFile->GetEntity( e );
				if ( idStr::Icmp( check->epairs.GetString( "model" ), modelName.c_str() ) == 0 ) {
					ent = check;
					break;
				}
			}
			if ( ent == NULL ) {
				// keep the geometry even when nothing referenced it
				ent = new (TAG_IDLIB) idMapEntity();
				ent->epairs.Set( "model", modelName.c_str() );
				mapFile->AddEntity( ent );
			}
		}
		Q3BspConvertModelBrushes( &bsp, ent, firstBrush, numBrushes );
	}

	// name and time stamp follow the idMapFile::Parse convention so the
	// collision model caches maps/<name>.cm and generated/<name>.bcm
	mapFile->SetMapInfo( bspMapName.c_str(), bsp.fileTime );

	bsp.Free();
	return mapFile;
}

/*
===============================================================================

	World render model

===============================================================================
*/

struct q3RawVert_t {
	idVec3	xyz;
	idVec3	normal;
	float	st[2];
};

class q3SurfaceBuilder_t {
public:
	q3SurfaceBuilder_t() { shaderNum = -1; shader = NULL; }

	int						shaderNum;
	idStr						shaderName;
	const idMaterial *		shader;
	idList<q3RawVert_t, TAG_RENDER>	verts;
	idList<triIndex_t, TAG_RENDER>	indexes;
};

/*
================
Q3BspFlushSurface

Emits one model surface from a builder, recentering the texture coordinates
on an integer average for maximum 16-bit precision like the .proc loader.
================
*/
static void Q3BspFlushSurface( idRenderModel *model, q3SurfaceBuilder_t *b ) {
	if ( b->verts.Num() == 0 || b->indexes.Num() == 0 ) {
		return;
	}

	float minS = idMath::INFINITUM, maxS = -idMath::INFINITUM;
	float minT = idMath::INFINITUM, maxT = -idMath::INFINITUM;
	for ( int i = 0; i < b->verts.Num(); i++ ) {
		minS = Min( minS, b->verts[i].st[0] );
		maxS = Max( maxS, b->verts[i].st[0] );
		minT = Min( minT, b->verts[i].st[1] );
		maxT = Max( maxT, b->verts[i].st[1] );
	}
	const float midS = (float)idMath::Ftoi( ( minS + maxS ) * 0.5f );
	const float midT = (float)idMath::Ftoi( ( minT + maxT ) * 0.5f );

	modelSurface_t surf;
	surf.id = 0;
	surf.shader = b->shader;
	( (idMaterial *)surf.shader )->AddReference();
	surf.geometry = R_AllocStaticTriSurf();

	srfTriangles_t *tri = surf.geometry;
	tri->numVerts = b->verts.Num();
	tri->numIndexes = b->indexes.Num();

	R_AllocStaticTriSurfVerts( tri, tri->numVerts );
	for ( int i = 0; i < tri->numVerts; i++ ) {
		tri->verts[i].xyz = b->verts[i].xyz;
		tri->verts[i].SetTexCoord( b->verts[i].st[0] - midS, b->verts[i].st[1] - midT );
		tri->verts[i].SetNormal( b->verts[i].normal.x, b->verts[i].normal.y, b->verts[i].normal.z );
	}

	R_AllocStaticTriSurfIndexes( tri, tri->numIndexes );
	for ( int i = 0; i < tri->numIndexes; i++ ) {
		tri->indexes[i] = b->indexes[i];
	}

	model->AddSurface( surf );

	b->verts.SetNum( 0 );
	b->indexes.SetNum( 0 );
}

/*
================
Q3BspAddTriangleFace

Planar faces and triangle soups take their geometry straight from the
drawvert and drawindex lumps, with per triangle validation.
================
*/
static void Q3BspAddTriangleFace( idRenderModel *model, q3SurfaceBuilder_t *b, const q3bspFile_t *bsp, int faceNum ) {
	int firstVert = BspReadFaceInt( bsp, faceNum, SURF_FIRSTVERT );
	int numVerts = BspReadFaceInt( bsp, faceNum, SURF_NUMVERTS );
	int firstIndex = BspReadFaceInt( bsp, faceNum, SURF_FIRSTINDEX );
	int numIndexes = BspReadFaceInt( bsp, faceNum, SURF_NUMINDEXES );

	// drop faces with out of range references instead of crashing on them
	if ( numVerts <= 0 || numIndexes < 3 || ( numIndexes % 3 ) != 0 ) {
		return;
	}
	if ( firstVert < 0 || firstVert + numVerts > BspNumVerts( bsp ) ) {
		return;
	}
	if ( firstIndex < 0 || firstIndex + numIndexes > BspNumIndexes( bsp ) ) {
		return;
	}

	// split the surface before the indexes would wrap the 16 bit range
	if ( b->verts.Num() + numVerts > MAX_SURFACE_VERTS ) {
		Q3BspFlushSurface( model, b );
	}

	int base = b->verts.Num();
	for ( int i = 0; i < numVerts; i++ ) {
		const byte *v = bsp->lumps[LUMP_DRAWVERTS] + ( firstVert + i ) * BSP_DRAWVERT_SIZE;
		q3RawVert_t rv;
		rv.xyz = BspReadVec3( v, VERT_XYZ );
		rv.normal = BspReadVec3( v, VERT_NORMAL );
		rv.st[0] = BspReadFloat( v, VERT_ST );
		rv.st[1] = BspReadFloat( v, VERT_ST + 4 );
		b->verts.Append( rv );
	}

	for ( int i = 0; i + 2 < numIndexes; i += 3 ) {
		int i0 = BspReadInt( bsp->lumps[LUMP_DRAWINDEXES], ( firstIndex + i + 0 ) * 4 );
		int i1 = BspReadInt( bsp->lumps[LUMP_DRAWINDEXES], ( firstIndex + i + 1 ) * 4 );
		int i2 = BspReadInt( bsp->lumps[LUMP_DRAWINDEXES], ( firstIndex + i + 2 ) * 4 );
		if ( i0 < 0 || i0 >= numVerts || i1 < 0 || i1 >= numVerts || i2 < 0 || i2 >= numVerts ) {
			continue;
		}
		if ( i0 == i1 || i1 == i2 || i0 == i2 ) {
			continue;
		}
		b->indexes.Append( (triIndex_t)( base + i0 ) );
		b->indexes.Append( (triIndex_t)( base + i1 ) );
		b->indexes.Append( (triIndex_t)( base + i2 ) );
	}
}

/*
================
Q3BspAddPatchFace

Patches are biquadratic bezier surfaces with a (patchWidth x patchHeight)
control grid whose control points live in the drawvert lump. Every 3x3
control sub grid tessellates with a fixed level of four segments, which is
close enough to the Q3 adaptive subdivision for world geometry.
================
*/
static ID_INLINE float Q3BspLerp( float a, float b, float t ) {
	return a + ( b - a ) * t;
}

static ID_INLINE float Q3BspBezier( float a, float b, float c, float t ) {
	// quadratic bezier through three control values
	float ab = Q3BspLerp( a, b, t );
	float bc = Q3BspLerp( b, c, t );
	return Q3BspLerp( ab, bc, t );
}

static void Q3BspAddPatchFace( idRenderModel *model, q3SurfaceBuilder_t *b, const q3bspFile_t *bsp, int faceNum ) {
	int firstVert = BspReadFaceInt( bsp, faceNum, SURF_FIRSTVERT );
	int controlW = BspReadFaceInt( bsp, faceNum, SURF_PATCHWIDTH );
	int controlH = BspReadFaceInt( bsp, faceNum, SURF_PATCHHEIGHT );

	// a patch control grid must be an odd size of at least 3x3
	if ( controlW < 3 || controlH < 3 || ( controlW - 1 ) % 2 != 0 || ( controlH - 1 ) % 2 != 0 ) {
		return;
	}
	if ( firstVert < 0 || firstVert + controlW * controlH > BspNumVerts( bsp ) ) {
		return;
	}

	int subX = ( controlW - 1 ) / 2;
	int subY = ( controlH - 1 ) / 2;
	int gridW = subX * PATCH_TESSELATION + 1;
	int gridH = subY * PATCH_TESSELATION + 1;

	// the tessellated grid has up to four times the control points
	if ( b->verts.Num() + gridW * gridH > MAX_SURFACE_VERTS ) {
		Q3BspFlushSurface( model, b );
	}

	const byte *ctrlVerts = bsp->lumps[LUMP_DRAWVERTS] + firstVert * BSP_DRAWVERT_SIZE;

	// the corner control points decide which side the patch faces, compare
	// against the average control normal to get the winding right
	idVec3 c00 = BspReadVec3( ctrlVerts, VERT_XYZ );
	idVec3 c20 = BspReadVec3( ctrlVerts + ( controlW - 1 ) * BSP_DRAWVERT_SIZE, VERT_XYZ );
	idVec3 c02 = BspReadVec3( ctrlVerts + ( controlH - 1 ) * controlW * BSP_DRAWVERT_SIZE, VERT_XYZ );
	idVec3 patchNormal = ( c20 - c00 ).Cross( c02 - c00 );
	idVec3 avgNormal;
	avgNormal.Zero();
	for ( int i = 0; i < controlW * controlH; i++ ) {
		avgNormal += BspReadVec3( ctrlVerts + i * BSP_DRAWVERT_SIZE, VERT_NORMAL );
	}
	bool flip = ( patchNormal * avgNormal ) < 0.0f;

	int base = b->verts.Num();

	// evaluate the whole grid, one vertex per (x, y) lattice point
	for ( int y = 0; y < gridH; y++ ) {
		int sy = Min( y / PATCH_TESSELATION, subY - 1 );
		float v = (float)( y - sy * PATCH_TESSELATION ) * ( 1.0f / (float)PATCH_TESSELATION );
		for ( int x = 0; x < gridW; x++ ) {
			int sx = Min( x / PATCH_TESSELATION, subX - 1 );
			float u = (float)( x - sx * PATCH_TESSELATION ) * ( 1.0f / (float)PATCH_TESSELATION );

			// 3x3 control points with 8 floats each: xyz(3), st(2), normal(3)
			float ctrl[72];
			for ( int row = 0; row < 3; row++ ) {
				for ( int col = 0; col < 3; col++ ) {
					int vertNum = ( 2 * sy + row ) * controlW + ( 2 * sx + col );
					const byte *cv = ctrlVerts + vertNum * BSP_DRAWVERT_SIZE;
					float *cp = ctrl + ( row * 3 + col ) * 8;
					cp[0] = BspReadFloat( cv, VERT_XYZ );
					cp[1] = BspReadFloat( cv, VERT_XYZ + 4 );
					cp[2] = BspReadFloat( cv, VERT_XYZ + 8 );
					cp[3] = BspReadFloat( cv, VERT_ST );
					cp[4] = BspReadFloat( cv, VERT_ST + 4 );
					cp[5] = BspReadFloat( cv, VERT_NORMAL );
					cp[6] = BspReadFloat( cv, VERT_NORMAL + 4 );
					cp[7] = BspReadFloat( cv, VERT_NORMAL + 8 );
				}
			}

			// bezier evaluate all 8 floats of the grid vertex
			q3RawVert_t out;
			out.xyz.x = Q3BspBezier( Q3BspBezier( ctrl[0], ctrl[8], ctrl[16], u ), Q3BspBezier( ctrl[24], ctrl[32], ctrl[40], u ), Q3BspBezier( ctrl[48], ctrl[56], ctrl[64], u ), v );
			out.xyz.y = Q3BspBezier( Q3BspBezier( ctrl[1], ctrl[9], ctrl[17], u ), Q3BspBezier( ctrl[25], ctrl[33], ctrl[41], u ), Q3BspBezier( ctrl[49], ctrl[57], ctrl[65], u ), v );
			out.xyz.z = Q3BspBezier( Q3BspBezier( ctrl[2], ctrl[10], ctrl[18], u ), Q3BspBezier( ctrl[26], ctrl[34], ctrl[42], u ), Q3BspBezier( ctrl[50], ctrl[58], ctrl[66], u ), v );
			out.st[0] = Q3BspBezier( Q3BspBezier( ctrl[3], ctrl[11], ctrl[19], u ), Q3BspBezier( ctrl[27], ctrl[35], ctrl[43], u ), Q3BspBezier( ctrl[51], ctrl[59], ctrl[67], u ), v );
			out.st[1] = Q3BspBezier( Q3BspBezier( ctrl[4], ctrl[12], ctrl[20], u ), Q3BspBezier( ctrl[28], ctrl[36], ctrl[44], u ), Q3BspBezier( ctrl[52], ctrl[60], ctrl[68], u ), v );
			out.normal.x = Q3BspBezier( Q3BspBezier( ctrl[5], ctrl[13], ctrl[21], u ), Q3BspBezier( ctrl[29], ctrl[37], ctrl[45], u ), Q3BspBezier( ctrl[53], ctrl[61], ctrl[69], u ), v );
			out.normal.y = Q3BspBezier( Q3BspBezier( ctrl[6], ctrl[14], ctrl[22], u ), Q3BspBezier( ctrl[30], ctrl[38], ctrl[46], u ), Q3BspBezier( ctrl[54], ctrl[62], ctrl[70], u ), v );
			out.normal.z = Q3BspBezier( Q3BspBezier( ctrl[7], ctrl[15], ctrl[23], u ), Q3BspBezier( ctrl[31], ctrl[39], ctrl[47], u ), Q3BspBezier( ctrl[55], ctrl[63], ctrl[71], u ), v );
			out.normal.Normalize();

			b->verts.Append( out );
		}
	}

	// stitch the grid into triangles
	for ( int y = 0; y + 1 < gridH; y++ ) {
		for ( int x = 0; x + 1 < gridW; x++ ) {
			int v0 = base + y * gridW + x;
			int v1 = base + ( y + 1 ) * gridW + x;
			int v2 = base + ( y + 1 ) * gridW + x + 1;
			int v3 = base + y * gridW + x + 1;
			if ( !flip ) {
				b->indexes.Append( (triIndex_t)v0 );
				b->indexes.Append( (triIndex_t)v1 );
				b->indexes.Append( (triIndex_t)v2 );
				b->indexes.Append( (triIndex_t)v0 );
				b->indexes.Append( (triIndex_t)v2 );
				b->indexes.Append( (triIndex_t)v3 );
			} else {
				b->indexes.Append( (triIndex_t)v0 );
				b->indexes.Append( (triIndex_t)v2 );
				b->indexes.Append( (triIndex_t)v1 );
				b->indexes.Append( (triIndex_t)v0 );
				b->indexes.Append( (triIndex_t)v3 );
				b->indexes.Append( (triIndex_t)v2 );
			}
		}
	}
}

/*
================
Q3Bsp_BuildWorldRenderModel

Builds one static world model (_area0) from all faces of all BSP models.
Faces group per shader, with a split when a group would exceed the
16 bit index range.
================
*/
idRenderModel *Q3Bsp_BuildWorldRenderModel( const char *name, ID_TIME_T *timeStamp ) {
	q3bspFile_t bsp;
	if ( !bsp.Load( name ) ) {
		return NULL;
	}
	if ( BspNumFaces( &bsp ) <= 0 ) {
		common->Warning( "Q3Bsp: %s has no faces\n", bsp.fileName.c_str() );
		bsp.Free();
		return NULL;
	}
	if ( timeStamp != NULL ) {
		*timeStamp = bsp.fileTime;
	}

	idRenderModel *model = renderModelManager->AllocModel();
	model->InitEmpty( "_area0" );

	idList<q3SurfaceBuilder_t, TAG_RENDER> builders;

	int numShaders = BspNumShaders( &bsp );
	int numFaces = BspNumFaces( &bsp );

	for ( int faceNum = 0; faceNum < numFaces; faceNum++ ) {
		int type = BspReadFaceInt( &bsp, faceNum, SURF_TYPE );

		// flares and foliage are billboard effects without world geometry
		if ( type == MST_FLARE || type == MST_FOLIAGE ) {
			continue;
		}

		int shaderNum = BspReadFaceInt( &bsp, faceNum, SURF_SHADERNUM );
		if ( shaderNum < 0 || shaderNum >= numShaders ) {
			continue;
		}

		// find the builder for this shader
		int builderIndex = -1;
		for ( int i = 0; i < builders.Num(); i++ ) {
			if ( builders[i].shaderNum == shaderNum ) {
				builderIndex = i;
				break;
			}
		}
		if ( builderIndex == -1 ) {
			char shaderName[64];
			BspGetShaderName( &bsp, shaderNum, shaderName, sizeof( shaderName ) );

			// clip, caul, hint and other editor materials have no stages
			const idMaterial *shader = declManager->FindMaterial( shaderName );
			if ( shader == NULL || !shader->IsDrawn() ) {
				continue;
			}

			q3SurfaceBuilder_t builder;
			builder.shaderNum = shaderNum;
			builder.shaderName = shaderName;
			builder.shader = shader;
			builderIndex = builders.Append( builder );
		}
		q3SurfaceBuilder_t *b = &builders[builderIndex];

		if ( type == MST_PATCH ) {
			Q3BspAddPatchFace( model, b, &bsp, faceNum );
		} else {
			Q3BspAddTriangleFace( model, b, &bsp, faceNum );
		}
	}

	// flush the remaining builders
	for ( int i = 0; i < builders.Num(); i++ ) {
		Q3BspFlushSurface( model, &builders[i] );
	}

	model->FinishSurfaces();

	if ( model->NumSurfaces() == 0 ) {
		common->Warning( "Q3Bsp: %s has no drawable surfaces\n", bsp.fileName.c_str() );
		bsp.Free();
		delete model;
		return NULL;
	}

	common->Printf( "Q3Bsp: %s built world model with %i surfaces\n", bsp.fileName.c_str(), model->NumSurfaces() );

	bsp.Free();
	return model;
}

/*
===============================================================================

	Lightmap conversion to point lights

===============================================================================
*/

struct q3LightSample_t {
	idVec3	origin;
	idVec3	color;
	float	luminance;
};

/*
================
Q3Bsp_AddLightmapLights

Samples the lightmap blocks of every lit face on a coarse luxel grid and
merges the samples into world grid cells. The brightest cells become point
lights, which is an approximation of the baked lightmap lighting.
================
*/
void Q3Bsp_AddLightmapLights( idRenderWorldLocal *world, const char *name ) {
	q3bspFile_t bsp;
	if ( !bsp.Load( name ) ) {
		return;
	}

	int numLightmaps = BspNumLightmaps( &bsp );
	if ( numLightmaps <= 0 ) {
		bsp.Free();
		return;
	}
	int lmStride = ( bsp.version == Q3BSP_VERSION_ET ) ? 4 : 3;

	int spacing = r_q3bspLightSpacing.GetInteger();
	if ( spacing < 1 ) {
		spacing = 1;
	}

	idList<q3LightSample_t, TAG_RENDER> cells;		// accumulated cells
	idList<int, TAG_RENDER> cellCount;				// samples merged into each cell
	idList<int, TAG_RENDER> cellX, cellY, cellZ;		// grid coordinates of each cell
	idHashIndex cellHash( 2048, 4096 );

	for ( int faceNum = 0; faceNum < BspNumFaces( &bsp ); faceNum++ ) {
		const byte *face = BspFace( &bsp, faceNum );
		int lightmapNum = BspReadInt( face, SURF_LIGHTMAPNUM );
		int lmW = BspReadInt( face, SURF_LMW );
		int lmH = BspReadInt( face, SURF_LMH );
		int type = BspReadFaceInt( &bsp, faceNum, SURF_TYPE );

		if ( lightmapNum < 0 || lightmapNum >= numLightmaps ) {
			continue;
		}
		// flares and foliage have no lightmap space worth sampling
		if ( type == MST_FLARE || type == MST_FOLIAGE ) {
			continue;
		}
		if ( lmW <= 0 || lmH <= 0 ) {
			continue;
		}

		idVec3 lmOrigin = BspReadVec3( face, SURF_LMORIGIN );
		idVec3 lmVecX = BspReadVec3( face, SURF_LMVECS );
		idVec3 lmVecY = BspReadVec3( face, SURF_LMVECS + 12 );
		idVec3 lmVecZ = BspReadVec3( face, SURF_LMVECS + 24 );

		const byte *lm = bsp.lumps[LUMP_LIGHTMAPS] + lightmapNum * lmStride * 128 * 128;

		for ( int y = 0; y < lmH && y < 128; y += spacing ) {
			for ( int x = 0; x < lmW && x < 128; x += spacing ) {
				const byte *luxel = lm + ( y * 128 + x ) * lmStride;
				idVec3 color( luxel[0] / 255.0f, luxel[1] / 255.0f, luxel[2] / 255.0f );
				float luminance = color.x * 0.3f + color.y * 0.5f + color.z * 0.2f;
				if ( luminance < 0.02f ) {
					continue;
				}

				// world position of the luxel, lifted off the surface
				idVec3 origin = lmOrigin + lmVecX * (float)x + lmVecY * (float)y + lmVecZ * 2.0f;

				// merge into a world grid cell
				int cx = idMath::Ftoi( idMath::Floor( origin.x / LIGHT_GRID_CELL ) );
				int cy = idMath::Ftoi( idMath::Floor( origin.y / LIGHT_GRID_CELL ) );
				int cz = idMath::Ftoi( idMath::Floor( origin.z / LIGHT_GRID_CELL ) );
				int key = ( cx * 73856093 ) ^ ( cy * 19349663 ) ^ ( cz * 83492791 );

				int cellIndex = -1;
				for ( int j = cellHash.First( key ); j != -1; j = cellHash.Next( j ) ) {
					if ( cellX[j] == cx && cellY[j] == cy && cellZ[j] == cz ) {
						cellIndex = j;
						break;
					}
				}
				if ( cellIndex == -1 ) {
					q3LightSample_t cell;
					cell.origin = origin;
					cell.color = color;
					cell.luminance = luminance;
					cellIndex = cells.Append( cell );
					cellCount.Append( 1 );
					cellX.Append( cx );
					cellY.Append( cy );
					cellZ.Append( cz );
					cellHash.Add( key, cellIndex );
				} else {
					cells[cellIndex].origin += origin;
					cells[cellIndex].color += color;
					cells[cellIndex].luminance += luminance;
					cellCount[cellIndex]++;
				}
			}
		}
	}

	// average each cell
	for ( int i = 0; i < cells.Num(); i++ ) {
		float invCount = 1.0f / (float)cellCount[i];
		cells[i].origin *= invCount;
		cells[i].color *= invCount;
		cells[i].luminance *= invCount;
	}

	// keep only the brightest cells
	int maxLights = r_q3bspMaxLights.GetInteger();
	if ( maxLights < 0 ) {
		maxLights = 0;
	}
	int numLights = Min( cells.Num(), maxLights );
	for ( int i = 0; i < numLights; i++ ) {
		// selection sort by luminance, the cell list is small enough for this
		int best = i;
		for ( int j = i + 1; j < cells.Num(); j++ ) {
			if ( cells[j].luminance > cells[best].luminance ) {
				best = j;
			}
		}
		q3LightSample_t tmp = cells[i];
		cells[i] = cells[best];
		cells[best] = tmp;

		renderLight_t light;
		memset( &light, 0, sizeof( light ) );
		light.axis = mat3_identity;
		light.origin = cells[i].origin;
		light.pointLight = true;
		light.parallel = false;
		light.noShadows = true;
		float radius = LIGHT_GRID_CELL * 0.75f;
		light.lightRadius = idVec3( radius, radius, radius );
		float scale = r_q3bspLightScale.GetFloat();
		light.shaderParms[0] = cells[i].color.x * scale;
		light.shaderParms[1] = cells[i].color.y * scale;
		light.shaderParms[2] = cells[i].color.z * scale;
		light.shaderParms[3] = 1.0f;

		world->AddLightDef( &light );
	}

	if ( numLights > 0 ) {
		common->Printf( "Q3Bsp: added %i lightmap lights from %s\n", numLights, bsp.fileName.c_str() );
	}

	bsp.Free();
}
