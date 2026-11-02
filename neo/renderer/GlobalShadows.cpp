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

idGlobalShadows globalShadows;

// the file header, everything after it is the raw height data
struct globalShadowFileHeader_t {
	int		magic;
	int		width;
	int		height;
	float	mins[3];
	float	maxs[3];
};

/*
========================
idGlobalShadows::idGlobalShadows
========================
*/
idGlobalShadows::idGlobalShadows() {
	fileData = NULL;
	width = 0;
	height = 0;
	mins.Zero();
	maxs.Zero();
}

/*
========================
idGlobalShadows::~idGlobalShadows
========================
*/
idGlobalShadows::~idGlobalShadows() {
	Clear();
}

/*
========================
idGlobalShadows::Clear
========================
*/
void idGlobalShadows::Clear() {
	if ( fileData != NULL ) {
		Mem_Free( fileData );
		fileData = NULL;
	}
	width = 0;
	height = 0;
	mins.Zero();
	maxs.Zero();
}

/*
========================
idGlobalShadows::Load
========================
*/
bool idGlobalShadows::Load( const char *fileName ) {
	Clear();

	idFileLocal file( fileSystem->OpenFileRead( fileName ) );
	if ( file == NULL ) {
		return false;
	}

	globalShadowFileHeader_t header;
	const int fileLength = file->Length();
	if ( fileLength < (int)sizeof( header ) || file->Read( &header, sizeof( header ) ) != sizeof( header ) ) {
		common->Warning( "idGlobalShadows::Load: %s is too short\n", fileName );
		return false;
	}
	if ( header.magic != GLOBALSHADOWS_MAGIC || header.width <= 0 || header.height <= 0 ||
			header.maxs[0] <= header.mins[0] || header.maxs[1] <= header.mins[1] || header.maxs[2] <= header.mins[2] ) {
		common->Warning( "idGlobalShadows::Load: %s has a bad header\n", fileName );
		return false;
	}

	const int dataLength = header.width * header.height * (int)sizeof( unsigned short );
	if ( dataLength != fileLength - (int)sizeof( header ) ) {
		common->Warning( "idGlobalShadows::Load: %s has a bad size\n", fileName );
		return false;
	}

	fileData = (byte *)Mem_Alloc( dataLength, TAG_RENDER );
	file->Read( fileData, dataLength );

	width = header.width;
	height = header.height;
	mins.Set( header.mins[0], header.mins[1], header.mins[2] );
	maxs.Set( header.maxs[0], header.maxs[1], header.maxs[2] );

	return true;
}

/*
========================
idGlobalShadows::SampleShadow

Bilinear samples the height map and compares it with the height of the
point, a point above the highest surface at its location is lit from
straight above, everything below is shadowed.
========================
*/
float idGlobalShadows::SampleShadow( const idVec3 &worldPoint ) const {
	if ( !IsLoaded() || width < 2 || height < 2 ) {
		return 0.0f;
	}
	if ( worldPoint.x < mins.x || worldPoint.x > maxs.x ||
			worldPoint.y < mins.y || worldPoint.y > maxs.y ) {
		return 0.0f;
	}

	const float fx = ( worldPoint.x - mins.x ) / ( maxs.x - mins.x ) * (float)width - 0.5f;
	const float fy = ( worldPoint.y - mins.y ) / ( maxs.y - mins.y ) * (float)height - 0.5f;

	int ix = idMath::Ftoi( fx );
	int iy = idMath::Ftoi( fy );
	float tx = fx - (float)ix;
	float ty = fy - (float)iy;
	if ( ix < 0 ) {
		ix = 0;
		tx = 0.0f;
	} else if ( ix > width - 2 ) {
		ix = width - 2;
		tx = 1.0f;
	}
	if ( iy < 0 ) {
		iy = 0;
		ty = 0.0f;
	} else if ( iy > height - 2 ) {
		iy = height - 2;
		ty = 1.0f;
	}

	const unsigned short * heights = (const unsigned short *)fileData;
	const unsigned short h00 = heights[ ( iy + 0 ) * width + ( ix + 0 ) ];
	const unsigned short h10 = heights[ ( iy + 0 ) * width + ( ix + 1 ) ];
	const unsigned short h01 = heights[ ( iy + 1 ) * width + ( ix + 0 ) ];
	const unsigned short h11 = heights[ ( iy + 1 ) * width + ( ix + 1 ) ];

	const float h0 = h00 + ( h10 - h00 ) * tx;
	const float h1 = h01 + ( h11 - h01 ) * tx;
	const float height = ( h0 + ( h1 - h0 ) * ty ) * ( 1.0f / 65535.0f );

	const float pz = ( worldPoint.z - mins.z ) / ( maxs.z - mins.z );
	if ( pz >= height + 0.002f ) {
		return 0.0f;
	}
	return 1.0f;
}

/*
========================
R_RasterizeGlobalShadowTri

Software rasterizes one triangle into the top down height map, the
highest surface wins at every texel.
========================
*/
static void R_RasterizeGlobalShadowTri( unsigned short * heights, int width, int height, const idVec2 p[3], const float h[3] ) {
	const float area = ( p[1].x - p[0].x ) * ( p[2].y - p[0].y ) - ( p[2].x - p[0].x ) * ( p[1].y - p[0].y );
	if ( area > -1e-6f && area < 1e-6f ) {
		return;
	}

	float minPx = Min( p[0].x, Min( p[1].x, p[2].x ) );
	float maxPx = Max( p[0].x, Max( p[1].x, p[2].x ) );
	float minPy = Min( p[0].y, Min( p[1].y, p[2].y ) );
	float maxPy = Max( p[0].y, Max( p[1].y, p[2].y ) );

	int x0 = idMath::Ftoi( idMath::Floor( minPx ) );
	int x1 = idMath::Ftoi( idMath::Ceil( maxPx ) );
	int y0 = idMath::Ftoi( idMath::Floor( minPy ) );
	int y1 = idMath::Ftoi( idMath::Ceil( maxPy ) );
	x0 = idMath::ClampInt( 0, width - 1, x0 );
	x1 = idMath::ClampInt( 0, width - 1, x1 );
	y0 = idMath::ClampInt( 0, height - 1, y0 );
	y1 = idMath::ClampInt( 0, height - 1, y1 );

	for ( int py = y0; py <= y1; py++ ) {
		for ( int px = x0; px <= x1; px++ ) {
			const float fx = px + 0.5f;
			const float fy = py + 0.5f;
			// edge functions of the three triangle edges, both windings pass
			const float e0 = ( fx - p[0].x ) * ( p[1].y - p[0].y ) - ( fy - p[0].y ) * ( p[1].x - p[0].x );
			const float e1 = ( fx - p[1].x ) * ( p[2].y - p[1].y ) - ( fy - p[1].y ) * ( p[2].x - p[1].x );
			const float e2 = ( fx - p[2].x ) * ( p[0].y - p[2].y ) - ( fy - p[2].y ) * ( p[0].x - p[2].x );
			const bool inside = ( e0 >= 0.0f && e1 >= 0.0f && e2 >= 0.0f ) || ( e0 <= 0.0f && e1 <= 0.0f && e2 <= 0.0f );
			if ( !inside ) {
				continue;
			}
			const float sum = e0 + e1 + e2;
			if ( sum > -1e-6f && sum < 1e-6f ) {
				continue;
			}
			// the edge functions are the barycentric weights of the corners
			const float height = ( e0 * h[0] + e1 * h[1] + e2 * h[2] ) / sum;
			int quantized = idMath::Ftoi( height * 65535.0f );
			quantized = idMath::ClampInt( 0, 65535, quantized );
			const int index = py * width + px;
			if ( quantized > heights[index] ) {
				heights[index] = (unsigned short)quantized;
			}
		}
	}
}

/*
========================
R_BakeGlobalShadows

Rasterizes the shadow casting world geometry into a top down height map
and writes it out.
========================
*/
bool R_BakeGlobalShadows( idRenderWorldLocal *world, const char *fileName ) {
	common->Printf( "bakeAmbient: baking global shadows...\n" );

	// gather the shadow casting world triangles and the world bounds
	idList<idVec3, TAG_RENDER> triVerts;
	triVerts.SetGranularity( 16384 );
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
			const idMaterial * material = surface->shader;
			if ( material == NULL || material->Coverage() == MC_TRANSLUCENT || !material->SurfaceCastsShadow() ) {
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
			for ( int t = 0; t + 2 < geometry->numIndexes; t += 3 ) {
				triVerts.Append( geometry->verts[geometry->indexes[t + 0]].xyz );
				triVerts.Append( geometry->verts[geometry->indexes[t + 1]].xyz );
				triVerts.Append( geometry->verts[geometry->indexes[t + 2]].xyz );
			}
		}
	}
	if ( worldBounds.IsCleared() || triVerts.Num() == 0 ) {
		common->Warning( "bakeAmbient: no shadow casting world geometry found\n" );
		return false;
	}

	const float xSize = worldBounds[1].x - worldBounds[0].x;
	const float ySize = worldBounds[1].y - worldBounds[0].y;
	const float zSize = worldBounds[1].z - worldBounds[0].z;
	if ( xSize <= 0.0f || ySize <= 0.0f || zSize <= 0.0f ) {
		common->Warning( "bakeAmbient: the world has no extent\n" );
		return false;
	}

	const int width = r_globalShadowMapSize.GetInteger();
	int height = idMath::Ftoi( (float)width * ( ySize / xSize ) );
	height = idMath::ClampInt( 1, 4096, height );

	idList<unsigned short, TAG_RENDER> heights;
	heights.SetNum( width * height );
	memset( heights.Ptr(), 0, width * height * (int)sizeof( unsigned short ) );

	const int numTris = triVerts.Num() / 3;
	for ( int t = 0; t < numTris; t++ ) {
		idVec2 p[3];
		float h[3];
		for ( int v = 0; v < 3; v++ ) {
			const idVec3 & vert = triVerts[t * 3 + v];
			p[v].x = ( vert.x - worldBounds[0].x ) / xSize * (float)width;
			p[v].y = ( vert.y - worldBounds[0].y ) / ySize * (float)height;
			h[v] = ( vert.z - worldBounds[0].z ) / zSize;
		}
		R_RasterizeGlobalShadowTri( heights.Ptr(), width, height, p, h );
	}

	idFileLocal file( fileSystem->OpenFileWrite( fileName, "fs_basepath" ) );
	if ( file == NULL ) {
		common->Warning( "bakeAmbient: could not open %s for writing\n", fileName );
		return false;
	}

	globalShadowFileHeader_t header;
	header.magic = GLOBALSHADOWS_MAGIC;
	header.width = width;
	header.height = height;
	header.mins[0] = worldBounds[0].x;
	header.mins[1] = worldBounds[0].y;
	header.mins[2] = worldBounds[0].z;
	header.maxs[0] = worldBounds[1].x;
	header.maxs[1] = worldBounds[1].y;
	header.maxs[2] = worldBounds[1].z;
	file->Write( &header, sizeof( header ) );
	file->Write( heights.Ptr(), width * height * (int)sizeof( unsigned short ) );

	common->Printf( "bakeAmbient: wrote %s, %d x %d heights\n", fileName, width, height );
	return true;
}
