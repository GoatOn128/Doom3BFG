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

#include "dmap.h"
#include "../../../framework/Bsp29.h"

/*
===============================================================================

	Converts a Quake 1 BSP (version 29) into the canonical idMapFile form so the
	regular dmap pipeline can build the .proc and .cm files from it.

	A Quake BSP does not store brushes, so they are rebuilt from the node tree of
	every model: each solid (or sky) leaf is the intersection of the half spaces
	of the nodes above it, which is a convex brush. The model bounds close the
	regions that run out to infinity. Faces on the node planes give the brush
	sides their textures, and the texinfo of those faces is converted into the
	texture matrix of the brush side.

	Water, slime and lava volumes are not converted.

	The Quake texture data is the WAD2 miptex lump embedded in the BSP.

	The plane and texinfo formats are from the Quake 1 GPL release
	(references/quake/WinQuake/bspfile.h, Copyright (C) 1996-1997 Id Software,
	Inc., GPLv2 or later).

===============================================================================
*/

// the materials are generated into Q1_MATERIAL_FILE, named after the miptex
#define Q1_MATERIAL_PREFIX			"textures/q1/"
#define Q1_MATERIAL_MISSING			"textures/q1/missing"
#define Q1_MATERIAL_CAULK			"textures/q1/caulk"
#define Q1_MATERIAL_FILE			"materials/q1.mtr"
#define Q1_MAP_MARKER				"q1bsp"		// worldspawn key that marks a .map made from a BSP

#define Q1_WORLD_MARGIN				128.0		// solid shell added around the world bounds
#define Q1_SUBMODEL_MARGIN			1.0
#define Q1_BASE_POLY_SIZE			262144.0
#define Q1_CLIP_EPSILON				0.01
#define Q1_MIN_SIDE_AREA			0.001
#define Q1_MIN_BRUSH_VOLUME			0.01
#define Q1_MIN_FACE_OVERLAP			0.01
#define Q1_PLANE_NORMAL_EPSILON		0.9999
#define Q1_PLANE_DIST_EPSILON		0.05
#define Q1_FACE_NORMAL_EPSILON		0.999
#define Q1_FACE_DIST_EPSILON		0.5
#define Q1_MAX_WALK_DEPTH			512
#define Q1_DEFAULT_TEXTURE_SIZE		64

typedef struct {
	double			x, y, z;
} q1Point_t;

typedef struct {
	double			n[3];				// outward normal, the inside of a brush is n.p + d <= 0
	double			d;
} q1Plane_t;

typedef idList<q1Point_t> q1Poly_t;

typedef struct {
	q1Plane_t		plane;
	int				node;				// BSP node the plane came from, -1 for the model bounds
} q1RegionPlane_t;

typedef struct {
	int				numSolidLeafs;
	int				numBrushes;
	int				numSlivers;			// regions without volume, not converted
	int				numLiquidLeafs;
	int				numTexturedSides;
	int				numCaulkSides;
	double			solidVolume;
} q1Stats_t;

typedef struct {
	const idBsp29 *			bsp;
	double					bounds[2][3];
	idList<q1RegionPlane_t>	path;
	idList<byte>			visited;
	idMapEntity *			entity;
	q1Stats_t *				stats;
	bool					failed;
} q1Walk_t;

/*
===============================================================================

	small convex polygon toolbox, double precision and independent of idWinding

===============================================================================
*/

/*
================
Q1_PlaneDist
================
*/
static double Q1_PlaneDist( const q1Plane_t &plane, const q1Point_t &p ) {
	return plane.n[0] * p.x + plane.n[1] * p.y + plane.n[2] * p.z + plane.d;
}

/*
================
Q1_NormalizePlane

Returns false for a plane without a usable normal.
================
*/
static bool Q1_NormalizePlane( q1Plane_t &plane ) {
	const double length = sqrt( plane.n[0] * plane.n[0] + plane.n[1] * plane.n[1] + plane.n[2] * plane.n[2] );
	if ( length < 1e-6 ) {
		return false;
	}
	plane.n[0] /= length;
	plane.n[1] /= length;
	plane.n[2] /= length;
	plane.d /= length;
	return true;
}

/*
================
Q1_BasePoly

A huge quad on the plane.
================
*/
static void Q1_BasePoly( const q1Plane_t &plane, q1Poly_t &poly ) {
	int axis = 0;
	double best = fabs( plane.n[0] );
	for ( int i = 1; i < 3; i++ ) {
		if ( fabs( plane.n[i] ) > best ) {
			best = fabs( plane.n[i] );
			axis = i;
		}
	}

	// the helper axis that is the least aligned with the normal
	double up[3] = { 0.0, 0.0, 0.0 };
	up[ axis == 2 ? 0 : 2 ] = 1.0;

	const double upDotN = up[0] * plane.n[0] + up[1] * plane.n[1] + up[2] * plane.n[2];
	double v[3];
	for ( int i = 0; i < 3; i++ ) {
		v[i] = up[i] - upDotN * plane.n[i];
	}
	const double vLength = sqrt( v[0] * v[0] + v[1] * v[1] + v[2] * v[2] );
	for ( int i = 0; i < 3; i++ ) {
		v[i] /= vLength;
	}

	double u[3];
	u[0] = v[1] * plane.n[2] - v[2] * plane.n[1];
	u[1] = v[2] * plane.n[0] - v[0] * plane.n[2];
	u[2] = v[0] * plane.n[1] - v[1] * plane.n[0];

	// a point on the plane
	double c[3];
	for ( int i = 0; i < 3; i++ ) {
		c[i] = -plane.d * plane.n[i];
	}

	const double size = Q1_BASE_POLY_SIZE;
	static const double signs[4][2] = { { -1.0, -1.0 }, { 1.0, -1.0 }, { 1.0, 1.0 }, { -1.0, 1.0 } };

	poly.Clear();
	for ( int i = 0; i < 4; i++ ) {
		q1Point_t p;
		p.x = c[0] + signs[i][0] * size * u[0] + signs[i][1] * size * v[0];
		p.y = c[1] + signs[i][0] * size * u[1] + signs[i][1] * size * v[1];
		p.z = c[2] + signs[i][0] * size * u[2] + signs[i][1] * size * v[2];
		poly.Append( p );
	}
}

/*
================
Q1_ClipPoly

Keeps the part of the polygon on the inside (n.p + d <= 0) of the plane. Points
within epsilon of the plane count as inside and are not split.
================
*/
static void Q1_ClipPoly( const q1Poly_t &in, const q1Plane_t &plane, double epsilon, q1Poly_t &out ) {
	out.Clear();

	const int num = in.Num();
	if ( num < 3 ) {
		return;
	}

	for ( int i = 0; i < num; i++ ) {
		const q1Point_t &a = in[i];
		const q1Point_t &b = in[ ( i + 1 ) % num ];
		const double da = Q1_PlaneDist( plane, a );
		const double db = Q1_PlaneDist( plane, b );

		if ( da <= epsilon ) {
			out.Append( a );
		}
		if ( ( da < -epsilon && db > epsilon ) || ( da > epsilon && db < -epsilon ) ) {
			const double t = da / ( da - db );
			q1Point_t mid;
			mid.x = a.x + t * ( b.x - a.x );
			mid.y = a.y + t * ( b.y - a.y );
			mid.z = a.z + t * ( b.z - a.z );
			out.Append( mid );
		}
	}

	if ( out.Num() < 3 ) {
		out.Clear();
	}
}

/*
================
Q1_PolyArea
================
*/
static double Q1_PolyArea( const q1Poly_t &poly ) {
	const int num = poly.Num();
	if ( num < 3 ) {
		return 0.0;
	}

	double sum[3] = { 0.0, 0.0, 0.0 };
	for ( int i = 0; i < num; i++ ) {
		const q1Point_t &a = poly[i];
		const q1Point_t &b = poly[ ( i + 1 ) % num ];
		sum[0] += a.y * b.z - a.z * b.y;
		sum[1] += a.z * b.x - a.x * b.z;
		sum[2] += a.x * b.y - a.y * b.x;
	}
	return 0.5 * sqrt( sum[0] * sum[0] + sum[1] * sum[1] + sum[2] * sum[2] );
}

/*
================
Q1_SamePlane

Same orientation and the same distance.
================
*/
static bool Q1_SamePlane( const q1Plane_t &a, const q1Plane_t &b ) {
	const double dot = a.n[0] * b.n[0] + a.n[1] * b.n[1] + a.n[2] * b.n[2];
	return dot > Q1_PLANE_NORMAL_EPSILON && fabs( a.d - b.d ) < Q1_PLANE_DIST_EPSILON;
}

/*
===============================================================================

	texture names and texture matrices

===============================================================================
*/

/*
================
Q1_MaterialName

Quake marks special textures with a leading character that is not welcome in a
material name: '*' liquids, '+' animations and '{' fences.
================
*/
static void Q1_MaterialName( const char *miptexName, idStr &material ) {
	if ( miptexName == NULL || miptexName[0] == '\0' ) {
		material = Q1_MATERIAL_MISSING;
		return;
	}

	idStr name;
	switch ( miptexName[0] ) {
		case '*':
			name = "liq_";
			miptexName++;
			break;
		case '+':
			name = "anim_";
			miptexName++;
			break;
		case '{':
			name = "fence_";
			miptexName++;
			break;
		default:
			break;
	}

	for ( ; *miptexName != '\0'; miptexName++ ) {
		const char c = *miptexName;
		if ( ( c >= 'a' && c <= 'z' ) || ( c >= '0' && c <= '9' ) || c == '_' || c == '-' ) {
			name.Append( c );
		} else if ( c >= 'A' && c <= 'Z' ) {
			name.Append( (char)( c - 'A' + 'a' ) );
		} else {
			name.Append( '_' );
		}
	}

	material = Q1_MATERIAL_PREFIX;
	material += name;
}

/*
================
Q1_ComputeAxisBase

The same tangent basis idMapBrushSide::GetTextureVectors() uses, which is what
the texture matrix of a brush side is relative to.
================
*/
static void Q1_ComputeAxisBase( const double normal[3], double texS[3], double texT[3] ) {
	double n[3];
	for ( int i = 0; i < 3; i++ ) {
		n[i] = ( fabs( normal[i] ) < 1e-6 ) ? 0.0 : normal[i];
	}

	const double rotY = -atan2( n[2], sqrt( n[1] * n[1] + n[0] * n[0] ) );
	const double rotZ = atan2( n[1], n[0] );

	texS[0] = -sin( rotZ );
	texS[1] = cos( rotZ );
	texS[2] = 0.0;
	texT[0] = -sin( rotY ) * cos( rotZ );
	texT[1] = -sin( rotY ) * sin( rotZ );
	texT[2] = -cos( rotY );
}

/*
================
Q1_TextureMatrix

Quake: s = S.p + s0 (in texels), with S an arbitrary 3D vector. On the plane of a
side that is the same as using the in-plane part of S and folding the
off-plane part into the constant. The in-plane vector is then expressed in the
tangent basis and divided by the texture size, because brush side texture
matrices are in units of the texture.
================
*/
static void Q1_TextureMatrix( const bsp29TexInfo_t &texInfo, const q1Plane_t &plane, int width, int height, idVec3 texMat[2] ) {
	double texS[3];
	double texT[3];
	Q1_ComputeAxisBase( plane.n, texS, texT );

	// n.p = -d on the plane
	const double planeDist = -plane.d;

	for ( int i = 0; i < 2; i++ ) {
		double s[3];
		for ( int j = 0; j < 3; j++ ) {
			s[j] = texInfo.vecs[i][j];
		}
		const double k = s[0] * plane.n[0] + s[1] * plane.n[1] + s[2] * plane.n[2];
		double inPlane[3];
		for ( int j = 0; j < 3; j++ ) {
			inPlane[j] = s[j] - k * plane.n[j];
		}

		const double size = (double)( i == 0 ? width : height );
		texMat[i][0] = (float)( ( inPlane[0] * texS[0] + inPlane[1] * texS[1] + inPlane[2] * texS[2] ) / size );
		texMat[i][1] = (float)( ( inPlane[0] * texT[0] + inPlane[1] * texT[1] + inPlane[2] * texT[2] ) / size );
		texMat[i][2] = (float)( ( texInfo.vecs[i][3] + k * planeDist ) / size );
	}
}

/*
================
Q1_AssignTexture

Finds the face of the BSP node that covers most of the side and takes material
and texture matrix from it. Sides without a face (inside the solid, or on the
model bounds) are caulked.
================
*/
static void Q1_AssignTexture( const idBsp29 &bsp, int nodeNum, const q1Plane_t &plane, const q1Poly_t &sidePoly, idMapBrushSide *side, q1Stats_t &stats ) {
	int bestFace = -1;
	double bestArea = Q1_MIN_FACE_OVERLAP;

	if ( nodeNum >= 0 ) {
		const bsp29Node_t &node = bsp.nodes[nodeNum];

		for ( int i = 0; i < (int)node.numFaces; i++ ) {
			const int faceNum = (int)node.firstFace + i;
			const bsp29Face_t &face = bsp.faces[faceNum];
			const bsp29Plane_t &facePlane = bsp.planes[face.planeNum];

			// the normal of a face points into the empty space, which is away from the solid region
			double faceNormal[3];
			for ( int j = 0; j < 3; j++ ) {
				faceNormal[j] = face.side ? -(double)facePlane.normal[j] : (double)facePlane.normal[j];
			}
			const double dot = faceNormal[0] * plane.n[0] + faceNormal[1] * plane.n[1] + faceNormal[2] * plane.n[2];
			if ( dot < Q1_FACE_NORMAL_EPSILON ) {
				continue;
			}

			idList<idVec3> points;
			if ( !bsp.GetFacePoints( faceNum, points ) ) {
				continue;
			}

			q1Poly_t facePoly;
			for ( int j = 0; j < points.Num(); j++ ) {
				q1Point_t p;
				p.x = points[j].x;
				p.y = points[j].y;
				p.z = points[j].z;
				facePoly.Append( p );
			}

			q1Point_t center = { 0.0, 0.0, 0.0 };
			for ( int j = 0; j < facePoly.Num(); j++ ) {
				center.x += facePoly[j].x;
				center.y += facePoly[j].y;
				center.z += facePoly[j].z;
			}
			center.x /= facePoly.Num();
			center.y /= facePoly.Num();
			center.z /= facePoly.Num();

			if ( fabs( Q1_PlaneDist( plane, center ) ) > Q1_FACE_DIST_EPSILON ) {
				continue;
			}

			// clip the side by the edges of the (convex) face, what is left is the overlap
			q1Poly_t clipped = sidePoly;
			q1Poly_t scratch;
			for ( int j = 0; j < facePoly.Num() && clipped.Num() >= 3; j++ ) {
				const q1Point_t &a = facePoly[j];
				const q1Point_t &b = facePoly[ ( j + 1 ) % facePoly.Num() ];
				const double edge[3] = { b.x - a.x, b.y - a.y, b.z - a.z };

				q1Plane_t edgePlane;
				edgePlane.n[0] = edge[1] * plane.n[2] - edge[2] * plane.n[1];
				edgePlane.n[1] = edge[2] * plane.n[0] - edge[0] * plane.n[2];
				edgePlane.n[2] = edge[0] * plane.n[1] - edge[1] * plane.n[0];
				edgePlane.d = 0.0;
				if ( !Q1_NormalizePlane( edgePlane ) ) {
					continue;
				}
				edgePlane.d = -( edgePlane.n[0] * a.x + edgePlane.n[1] * a.y + edgePlane.n[2] * a.z );

				// make the plane look away from the face center
				if ( Q1_PlaneDist( edgePlane, center ) > 0.0 ) {
					edgePlane.n[0] = -edgePlane.n[0];
					edgePlane.n[1] = -edgePlane.n[1];
					edgePlane.n[2] = -edgePlane.n[2];
					edgePlane.d = -edgePlane.d;
				}

				Q1_ClipPoly( clipped, edgePlane, Q1_CLIP_EPSILON, scratch );
				clipped = scratch;
			}

			const double area = Q1_PolyArea( clipped );
			if ( area > bestArea ) {
				bestArea = area;
				bestFace = faceNum;
			}
		}
	}

	if ( bestFace < 0 ) {
		side->SetMaterial( Q1_MATERIAL_CAULK );
		stats.numCaulkSides++;
		return;
	}

	const bsp29Face_t &face = bsp.faces[bestFace];
	const bsp29TexInfo_t &texInfo = bsp.texInfo[face.texInfo];
	const wad2MipTex_t &mipTex = bsp.textures.Get( texInfo.miptex );

	idStr material;
	Q1_MaterialName( mipTex.name, material );
	side->SetMaterial( material );

	const int width = mipTex.width > 0 ? mipTex.width : Q1_DEFAULT_TEXTURE_SIZE;
	const int height = mipTex.height > 0 ? mipTex.height : Q1_DEFAULT_TEXTURE_SIZE;
	idVec3 texMat[2];
	Q1_TextureMatrix( texInfo, plane, width, height, texMat );
	side->SetTextureMatrix( texMat );
	stats.numTexturedSides++;
}

/*
===============================================================================

	brush reconstruction

===============================================================================
*/

/*
================
Q1_BuildRegionBrush

Builds the brush of one solid leaf from the node planes above it plus the model
bounds. Returns NULL when the region has no volume.
================
*/
static idMapBrush *Q1_BuildRegionBrush( const q1Walk_t &walk ) {
	idList<q1RegionPlane_t> planes;

	// the node planes first, so a bounds plane that coincides with one of them is the one dropped
	for ( int i = 0; i < walk.path.Num(); i++ ) {
		bool duplicate = false;
		for ( int j = 0; j < planes.Num(); j++ ) {
			if ( Q1_SamePlane( planes[j].plane, walk.path[i].plane ) ) {
				duplicate = true;
				break;
			}
		}
		if ( !duplicate ) {
			planes.Append( walk.path[i] );
		}
	}

	for ( int axis = 0; axis < 3; axis++ ) {
		for ( int isMax = 0; isMax < 2; isMax++ ) {
			q1RegionPlane_t bound;
			memset( &bound, 0, sizeof( bound ) );
			bound.node = -1;
			bound.plane.n[axis] = isMax ? 1.0 : -1.0;
			bound.plane.d = isMax ? -walk.bounds[1][axis] : walk.bounds[0][axis];

			bool duplicate = false;
			for ( int j = 0; j < planes.Num(); j++ ) {
				if ( Q1_SamePlane( planes[j].plane, bound.plane ) ) {
					duplicate = true;
					break;
				}
			}
			if ( !duplicate ) {
				planes.Append( bound );
			}
		}
	}

	// every plane gets the polygon that is left after cutting it by all the others
	idList<q1Poly_t> polys;
	polys.SetNum( planes.Num() );
	q1Poly_t scratch;
	int numSides = 0;
	double volume = 0.0;
	for ( int i = 0; i < planes.Num(); i++ ) {
		Q1_BasePoly( planes[i].plane, polys[i] );
		for ( int j = 0; j < planes.Num() && polys[i].Num() >= 3; j++ ) {
			if ( i == j ) {
				continue;
			}
			Q1_ClipPoly( polys[i], planes[j].plane, Q1_CLIP_EPSILON, scratch );
			polys[i] = scratch;
		}

		const double area = Q1_PolyArea( polys[i] );
		if ( area < Q1_MIN_SIDE_AREA ) {
			polys[i].Clear();
			continue;
		}
		numSides++;
		// the volume of the cone from the origin to the side, signed by the distance of the plane
		volume += area * ( -planes[i].plane.d ) / 3.0;
	}

	if ( numSides < 4 || volume < Q1_MIN_BRUSH_VOLUME ) {
		return NULL;
	}

	idMapBrush *brush = new (TAG_DMAP) idMapBrush();
	for ( int i = 0; i < planes.Num(); i++ ) {
		if ( polys[i].Num() < 3 ) {
			continue;
		}
		idMapBrushSide *side = new (TAG_DMAP) idMapBrushSide();
		const q1Plane_t &plane = planes[i].plane;
		side->SetPlane( idPlane( (float)plane.n[0], (float)plane.n[1], (float)plane.n[2], (float)plane.d ) );
		Q1_AssignTexture( *walk.bsp, planes[i].node, plane, polys[i], side, *walk.stats );
		brush->AddSide( side );
	}

	walk.stats->solidVolume += volume;
	return brush;
}

/*
================
Q1_WalkNode

Walks the node tree of a model and turns every solid or sky leaf into a brush.
The front child of a node is on the positive side of its plane.
================
*/
static void Q1_WalkNode( q1Walk_t &walk, int child ) {
	if ( walk.failed ) {
		return;
	}

	const idBsp29 &bsp = *walk.bsp;

	if ( child < 0 ) {
		const bsp29Leaf_t &leaf = bsp.leafs[ -1 - child ];

		if ( leaf.contents == BSP29_CONTENTS_SOLID || leaf.contents == BSP29_CONTENTS_SKY ) {
			walk.stats->numSolidLeafs++;
			idMapBrush *brush = Q1_BuildRegionBrush( walk );
			if ( brush != NULL ) {
				walk.entity->AddPrimitive( brush );
				walk.stats->numBrushes++;
			} else {
				walk.stats->numSlivers++;
			}
		} else if ( leaf.contents == BSP29_CONTENTS_WATER || leaf.contents == BSP29_CONTENTS_SLIME || leaf.contents == BSP29_CONTENTS_LAVA ) {
			walk.stats->numLiquidLeafs++;
		}
		return;
	}

	if ( walk.path.Num() >= Q1_MAX_WALK_DEPTH || walk.visited[child] ) {
		common->Warning( "Q1 BSP: the node tree is too deep or has a loop at node %d", child );
		walk.failed = true;
		return;
	}
	walk.visited[child] = 1;

	const bsp29Node_t &node = bsp.nodes[child];
	const bsp29Plane_t &nodePlane = bsp.planes[node.planeNum];

	q1Plane_t plane;
	plane.n[0] = nodePlane.normal[0];
	plane.n[1] = nodePlane.normal[1];
	plane.n[2] = nodePlane.normal[2];
	plane.d = nodePlane.dist;
	if ( !Q1_NormalizePlane( plane ) ) {
		common->Warning( "Q1 BSP: node %d has a plane without a normal", child );
		walk.failed = true;
		return;
	}

	// the node plane is n.p = dist; the outward planes of the two regions:
	// front (n.p >= dist) is -n.p + dist <= 0, back (n.p <= dist) is n.p - dist <= 0
	q1RegionPlane_t front;
	front.node = child;
	front.plane.n[0] = -plane.n[0];
	front.plane.n[1] = -plane.n[1];
	front.plane.n[2] = -plane.n[2];
	front.plane.d = plane.d;

	q1RegionPlane_t back;
	back.node = child;
	back.plane.n[0] = plane.n[0];
	back.plane.n[1] = plane.n[1];
	back.plane.n[2] = plane.n[2];
	back.plane.d = -plane.d;

	walk.path.Append( front );
	Q1_WalkNode( walk, node.children[0] );
	walk.path.RemoveIndex( walk.path.Num() - 1 );

	walk.path.Append( back );
	Q1_WalkNode( walk, node.children[1] );
	walk.path.RemoveIndex( walk.path.Num() - 1 );
}

/*
================
Q1_BuildModelBrushes

Adds the brushes of a BSP model to the entity. Returns the number of brushes.
================
*/
static int Q1_BuildModelBrushes( const idBsp29 &bsp, int modelNum, idMapEntity *entity, q1Stats_t &stats ) {
	const bsp29Model_t &model = bsp.models[modelNum];
	const double margin = ( modelNum == 0 ) ? Q1_WORLD_MARGIN : Q1_SUBMODEL_MARGIN;

	q1Walk_t walk;
	walk.bsp = &bsp;
	walk.entity = entity;
	walk.stats = &stats;
	walk.failed = false;
	for ( int i = 0; i < 3; i++ ) {
		walk.bounds[0][i] = (double)model.mins[i] - margin;
		walk.bounds[1][i] = (double)model.maxs[i] + margin;
	}
	walk.visited.SetNum( bsp.nodes.Num() );
	memset( walk.visited.Ptr(), 0, walk.visited.Num() );

	const int before = stats.numBrushes;
	Q1_WalkNode( walk, model.headNode[0] );
	return stats.numBrushes - before;
}

/*
===============================================================================

	textures

===============================================================================
*/

/*
================
Q1_AddMaterial

Appends a material to the text unless the name is known. Materials with an image
get a diffusemap stage, which makes them opaque; without an image they are made
opaque by force. An opaque brush is what dmap needs to seal the map: the
implicit material the engine makes for a bare image is translucent.
================
*/
static bool Q1_AddMaterial( idStrList &known, idStr &text, const char *material, const char *image ) {
	for ( int i = 0; i < known.Num(); i++ ) {
		if ( known[i].Icmp( material ) == 0 ) {
			return false;
		}
	}
	known.Append( material );

	text += material;
	text += "\r\n{\r\n";
	if ( image != NULL ) {
		text += va( "\tqer_editorimage\t%s.tga\r\n\tdiffusemap\t%s.tga\r\n", image, image );
	} else {
		text += "\tforceOpaque\r\n";
	}
	text += "}\r\n\r\n";
	return true;
}

/*
================
Q1_WriteMaterials

Adds the materials of the BSP textures to Q1_MATERIAL_FILE, which is shared by
all converted maps, and loads it.
================
*/
static void Q1_WriteMaterials( const idBsp29 &bsp ) {
	idStr text;
	idStrList known;

	byte *buffer = NULL;
	const int length = fileSystem->ReadFile( Q1_MATERIAL_FILE, (void **)&buffer );
	if ( buffer != NULL ) {
		if ( length > 0 ) {
			text.Append( (const char *)buffer, length );

			// the file only holds materials made here: a name followed by a braced block
			idLexer src( LEXFL_NOSTRINGCONCAT | LEXFL_ALLOWPATHNAMES | LEXFL_NOFATALERRORS );
			if ( src.LoadMemory( (const char *)buffer, length, Q1_MATERIAL_FILE ) ) {
				idToken token;
				while ( src.ReadToken( &token ) ) {
					known.Append( token );
					src.SkipBracedSection( true );
				}
			}
		}
		fileSystem->FreeFile( buffer );
	}
	if ( text.Length() > 0 && text[ text.Length() - 1 ] != '\n' ) {
		text += "\r\n";
	}

	int numAdded = 0;
	for ( int i = 0; i < bsp.textures.Num(); i++ ) {
		const wad2MipTex_t &mipTex = bsp.textures.Get( i );
		if ( mipTex.name[0] == '\0' ) {
			continue;
		}
		idStr material;
		Q1_MaterialName( mipTex.name, material );
		if ( Q1_AddMaterial( known, text, material, mipTex.HasPixels() ? material.c_str() : NULL ) ) {
			numAdded++;
		}
	}
	if ( Q1_AddMaterial( known, text, Q1_MATERIAL_CAULK, NULL ) ) {
		numAdded++;
	}
	if ( Q1_AddMaterial( known, text, Q1_MATERIAL_MISSING, NULL ) ) {
		numAdded++;
	}

	if ( numAdded == 0 ) {
		return;
	}

	{
		idFileLocal file( fileSystem->OpenFileWrite( Q1_MATERIAL_FILE, "fs_basepath" ) );
		if ( file == NULL ) {
			common->Warning( "Q1 BSP: couldn't write %s, the brushes will not be opaque", Q1_MATERIAL_FILE );
			return;
		}
		file->Write( text.c_str(), text.Length() );
	}

	// pick up the new materials before dmap looks them up
	declManager->RegisterDeclFolder( "materials", ".mtr", DECL_MATERIAL );
	common->Printf( "%5i materials added to %s\n", numAdded, Q1_MATERIAL_FILE );
}

/*
================
Q1_ExportTextures

Writes the textures that have pixels as TGA images where the materials made up by
Q1_MaterialName() find them.
================
*/
static void Q1_ExportTextures( const idBsp29 &bsp ) {
	byte palette[WAD2_PALETTE_SIZE];
	if ( !idWad2::LoadPalette( palette ) ) {
		common->Warning( "Q1 BSP: no palette, the textures are not exported" );
		return;
	}

	idStrList written;
	int count = 0;
	for ( int i = 0; i < bsp.textures.Num(); i++ ) {
		const wad2MipTex_t &mipTex = bsp.textures.Get( i );
		if ( !mipTex.HasPixels() || mipTex.name[0] == '\0' ) {
			continue;
		}

		idStr material;
		Q1_MaterialName( mipTex.name, material );

		bool done = false;
		for ( int j = 0; j < written.Num(); j++ ) {
			if ( written[j] == material ) {
				done = true;
				break;
			}
		}
		if ( done ) {
			continue;
		}
		written.Append( material );

		// index 255 is transparent in the fence textures
		idList<byte> rgba;
		if ( !idWad2::DecodeMipTex( mipTex, palette, mipTex.name[0] == '{', rgba ) ) {
			continue;
		}

		idStr fileName = material + ".tga";
		R_WriteImage( TYPE_TGA, fileName.c_str(), rgba.Ptr(), 4, mipTex.width, mipTex.height, false, "fs_basepath" );
		count++;
	}
	common->Printf( "%5i textures exported to %s\n", count, Q1_MATERIAL_PREFIX );
}

/*
===============================================================================

	entities

===============================================================================
*/

/*
================
Q1_ConvertEntities
================
*/
static bool Q1_ConvertEntities( const idBsp29 &bsp, idMapFile *mapFile, q1Stats_t &stats ) {
	if ( bsp.entities.Num() == 0 ) {
		common->Warning( "Q1 BSP: the map has no entities" );
		return false;
	}
	if ( idStr::Icmp( bsp.entities[0].GetString( "classname", "" ), "worldspawn" ) != 0 ) {
		common->Warning( "Q1 BSP: the first entity is not the worldspawn" );
		return false;
	}

	int numBrushEntities = 0;
	for ( int i = 0; i < bsp.entities.Num(); i++ ) {
		idMapEntity *mapEnt = new (TAG_DMAP) idMapEntity();
		mapEnt->epairs = bsp.entities[i];

		if ( i == 0 ) {
			mapEnt->epairs.Set( Q1_MAP_MARKER, bsp.GetName() );
		}

		// dmap wants a name on every light, Quake lights have none
		if ( idStr::Icmp( mapEnt->epairs.GetString( "classname", "" ), "light" ) == 0 && mapEnt->epairs.GetString( "name", "" )[0] == '\0' ) {
			mapEnt->epairs.Set( "name", va( "light_%d", i ) );
		}

		int modelNum = -1;
		if ( i == 0 ) {
			modelNum = 0;
		} else {
			const char *model = mapEnt->epairs.GetString( "model", "" );
			if ( model[0] == '*' ) {
				modelNum = atoi( model + 1 );
				if ( modelNum < 1 || modelNum >= bsp.models.Num() ) {
					common->Warning( "Q1 BSP: entity %d references the bad model %s", i, model );
					modelNum = -1;
				}
			}
		}

		if ( i > 0 && modelNum > 0 ) {
			// a brush entity: the brushes are in world space, like in a map, so an origin would only offset them
			idVec3 origin;
			if ( mapEnt->epairs.GetVector( "origin", "0 0 0", origin ) && origin != vec3_origin ) {
				common->Warning( "Q1 BSP: the origin of the brush entity %d is ignored", i );
			}
			mapEnt->epairs.Delete( "origin" );

			idStr name = mapEnt->epairs.GetString( "name", "" );
			if ( name.IsEmpty() ) {
				name = va( "%s_%d", mapEnt->epairs.GetString( "classname", "q1ent" ), i );
				mapEnt->epairs.Set( "name", name );
			}
			// the model of a D3 brush entity is named like the entity
			mapEnt->epairs.Set( "model", name );
			numBrushEntities++;
		}

		if ( modelNum >= 0 ) {
			const int numBrushes = Q1_BuildModelBrushes( bsp, modelNum, mapEnt, stats );
			if ( modelNum > 0 && numBrushes == 0 ) {
				common->Warning( "Q1 BSP: the brush entity %d has no solid brushes", i );
			}
		}

		mapFile->AddEntity( mapEnt );
	}

	common->Printf( "%5i entities (%i with brushes)\n", bsp.entities.Num(), numBrushEntities );
	return true;
}

/*
================
ConvertBspToMapFile

Converts maps/name.bsp into maps/name.map, which dmap and the game then load like
any other map. A .map that was not made from a BSP is never overwritten.
================
*/
bool ConvertBspToMapFile( const char *name ) {
	idStr fileName = name;
	fileName.SetFileExtension( "bsp" );

	idStr mapName = name;
	mapName.SetFileExtension( "map" );

	byte *existing = NULL;
	const int existingLength = fileSystem->ReadFile( mapName, (void **)&existing );
	if ( existing != NULL ) {
		const bool ours = existingLength > 0 && strstr( (const char *)existing, "\"" Q1_MAP_MARKER "\"" ) != NULL;
		fileSystem->FreeFile( existing );
		if ( !ours ) {
			common->Warning( "%s exists and was not made from a BSP, it is not overwritten", mapName.c_str() );
			return false;
		}
	}

	byte *buffer = NULL;
	const int length = fileSystem->ReadFile( fileName, (void **)&buffer );
	if ( buffer == NULL || length <= 0 ) {
		if ( buffer != NULL ) {
			fileSystem->FreeFile( buffer );
		}
		common->Warning( "Couldn't read the BSP file '%s'", fileName.c_str() );
		return false;
	}

	idBsp29 bsp;
	const bool loaded = bsp.LoadFromMemory( buffer, length, fileName );
	if ( buffer != NULL ) {
		fileSystem->FreeFile( buffer );
	}
	if ( !loaded ) {
		return false;
	}

	common->Printf( "Quake BSP: %i models, %i nodes, %i leafs, %i faces, %i textures\n",
		bsp.models.Num(), bsp.nodes.Num(), bsp.leafs.Num(), bsp.faces.Num(), bsp.textures.Num() );

	if ( !dmapGlobals.noQ1Textures ) {
		Q1_ExportTextures( bsp );
	}
	Q1_WriteMaterials( bsp );

	idMapFile mapFile;
	q1Stats_t stats;
	memset( &stats, 0, sizeof( stats ) );
	if ( !Q1_ConvertEntities( bsp, &mapFile, stats ) ) {
		return false;
	}

	common->Printf( "%5i solid leafs -> %i brushes (%i without volume), %i liquid leafs skipped\n",
		stats.numSolidLeafs, stats.numBrushes, stats.numSlivers, stats.numLiquidLeafs );
	common->Printf( "%5i textured sides, %i caulk sides\n", stats.numTexturedSides, stats.numCaulkSides );

	return mapFile.Write( name, "map" );
}

/*
================
WriteBspExtensionRefs

After dmap wrote the .proc and the .cm file, the BSP gets the BSPX_LUMP_VIS and
BSPX_LUMP_CM references to them (name, size and checksum) and is written back
next to them.
================
*/
bool WriteBspExtensionRefs( const char *mapFileBase ) {
	idStr bspName = mapFileBase;
	bspName.SetFileExtension( "bsp" );

	idBsp29 bsp;
	if ( !bsp.LoadFromFile( bspName ) ) {
		return false;
	}

	static const struct {
		bspxLumpId_t	lump;
		const char *	extension;
	} refs[] = {
		{ BSPX_LUMP_VIS, "proc" },
		{ BSPX_LUMP_CM, "cm" }
	};

	int numRefs = 0;
	for ( int i = 0; i < (int)( sizeof( refs ) / sizeof( refs[0] ) ); i++ ) {
		idStr refName = mapFileBase;
		refName.SetFileExtension( refs[i].extension );

		byte *buffer = NULL;
		const int length = fileSystem->ReadFile( refName, (void **)&buffer );
		if ( buffer == NULL || length < 0 ) {
			if ( buffer != NULL ) {
				fileSystem->FreeFile( buffer );
			}
			bsp.RemoveExtLump( idBsp29::GetExtLumpName( refs[i].lump ) );
			common->Warning( "Q1 BSP: %s was not created, the BSP gets no reference to it", refName.c_str() );
			continue;
		}
		bsp.SetFileRef( refs[i].lump, refName, buffer, length );
		if ( buffer != NULL ) {
			fileSystem->FreeFile( buffer );
		}
		numRefs++;
	}

	idFileLocal file( fileSystem->OpenFileWrite( bspName, "fs_basepath" ) );
	if ( file == NULL ) {
		common->Warning( "Q1 BSP: couldn't open %s for writing", bspName.c_str() );
		return false;
	}
	if ( !bsp.Write( file ) ) {
		common->Warning( "Q1 BSP: couldn't write %s", bspName.c_str() );
		return false;
	}

	common->Printf( "writing %s (%i external file references)\n", bspName.c_str(), numRefs );
	return true;
}
