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

If you have questions concerning the license or the applicable additional terms, you may contact in writing to id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#include "precompiled.h"
#pragma hdrstop

#include "tr_local.h"

#include "Model_local.h"
#include "Model_mdl.h"

void R_DeriveTangentsWithoutNormals( srfTriangles_t *tri );

/***********************************************************************

	idRenderModelMDL

***********************************************************************/

static const char *MDL_SnapshotName = "_MDL_Snapshot_";

// mdl_t ident "IDPO" and version
#define MDL_IDENT	( ( 'O' << 24 ) + ( 'P' << 16 ) + ( 'D' << 8 ) + 'I' )
#define MDL_VERSION	6

// skin and frame group types
#define MDL_SINGLE	0
#define MDL_GROUP	1

/*
=============
MDL_LoadQ1Palette

The Quake 1 palette is the 768 raw RGB bytes of gfx/palette.lmp.
It is read once and cached for all model loads.
=============
*/
static bool MDL_LoadQ1Palette( byte palette[768] ) {
	static byte		cachedPalette[768];
	static bool		checked = false;
	static bool		valid = false;

	if ( !checked ) {
		checked = true;
		byte *buffer = NULL;
		int len = fileSystem->ReadFile( "gfx/palette.lmp", &buffer );
		if ( buffer != NULL && len >= 768 ) {
			memcpy( cachedPalette, buffer, 768 );
			valid = true;
		}
		fileSystem->FreeFile( buffer );
		if ( !valid ) {
			common->Warning( "MDL loader couldn't read the Quake 1 palette from gfx/palette.lmp\n" );
		}
	}

	if ( valid ) {
		memcpy( palette, cachedPalette, 768 );
	}
	return valid;
}

/*
================
MDL embedded images

The decoded skins are handed to the image manager through a generator
function. The registry keeps the RGBA data for the life of the process,
entries with the same name are replaced when a model reloads.
================
*/
struct mdlEmbeddedImage_t {
	idStr		name;
	byte *		pic;
	int			width;
	int			height;
};

static idList<mdlEmbeddedImage_t, TAG_MODEL> mdlEmbeddedImages;

static mdlEmbeddedImage_t *MDL_FindEmbeddedImage( const char *name ) {
	for ( int i = 0; i < mdlEmbeddedImages.Num(); i++ ) {
		if ( mdlEmbeddedImages[i].name.Icmp( name ) == 0 ) {
			return &mdlEmbeddedImages[i];
		}
	}
	return NULL;
}

static void MDL_RegisterEmbeddedImage( const char *name, byte *pic, int width, int height ) {
	mdlEmbeddedImage_t *existing = MDL_FindEmbeddedImage( name );
	if ( existing != NULL ) {
		Mem_Free( existing->pic );
		existing->pic = pic;
		existing->width = width;
		existing->height = height;
		return;
	}
	mdlEmbeddedImage_t &entry = mdlEmbeddedImages.Alloc();
	entry.name = name;
	entry.pic = pic;
	entry.width = width;
	entry.height = height;
}

// the sampler parameters must match what an implicit material asks for, or
// the image manager would create a second, empty file image with the same name
static void MDL_GenerateEmbeddedImage( idImage *image ) {
	const mdlEmbeddedImage_t *src = MDL_FindEmbeddedImage( image->GetName() );
	if ( src == NULL ) {
		common->Warning( "MDL generator missing the pixels for %s\n", image->GetName() );
		image->MakeDefault();
		return;
	}
	image->GenerateImage( src->pic, src->width, src->height, TF_DEFAULT, TR_CLAMP, TD_DEFAULT );
}

// the 162 vertex normals from the Quake 1 and Quake 2 anorms.h table
static const float MDLAnorms[162][3] = {
	{ -0.525731f, 0.000000f, 0.850651f },
	{ -0.442863f, 0.238856f, 0.864188f },
	{ -0.295242f, 0.000000f, 0.955423f },
	{ -0.309017f, 0.500000f, 0.809017f },
	{ -0.162460f, 0.262866f, 0.951056f },
	{ 0.000000f, 0.000000f, 1.000000f },
	{ 0.000000f, 0.850651f, 0.525731f },
	{ -0.147621f, 0.716567f, 0.681718f },
	{ 0.147621f, 0.716567f, 0.681718f },
	{ 0.000000f, 0.525731f, 0.850651f },
	{ 0.309017f, 0.500000f, 0.809017f },
	{ 0.525731f, 0.000000f, 0.850651f },
	{ 0.295242f, 0.000000f, 0.955423f },
	{ 0.442863f, 0.238856f, 0.864188f },
	{ 0.162460f, 0.262866f, 0.951056f },
	{ -0.681718f, 0.147621f, 0.716567f },
	{ -0.809017f, 0.309017f, 0.500000f },
	{ -0.587785f, 0.425325f, 0.688191f },
	{ -0.850651f, 0.525731f, 0.000000f },
	{ -0.864188f, 0.442863f, 0.238856f },
	{ -0.716567f, 0.681718f, 0.147621f },
	{ -0.688191f, 0.587785f, 0.425325f },
	{ -0.500000f, 0.809017f, 0.309017f },
	{ -0.238856f, 0.864188f, 0.442863f },
	{ -0.425325f, 0.688191f, 0.587785f },
	{ -0.716567f, 0.681718f, -0.147621f },
	{ -0.500000f, 0.809017f, -0.309017f },
	{ -0.525731f, 0.850651f, 0.000000f },
	{ 0.000000f, 0.850651f, -0.525731f },
	{ -0.238856f, 0.864188f, -0.442863f },
	{ 0.000000f, 0.955423f, -0.295242f },
	{ -0.262866f, 0.951056f, -0.162460f },
	{ 0.000000f, 1.000000f, 0.000000f },
	{ 0.000000f, 0.955423f, 0.295242f },
	{ -0.262866f, 0.951056f, 0.162460f },
	{ 0.238856f, 0.864188f, 0.442863f },
	{ 0.262866f, 0.951056f, 0.162460f },
	{ 0.500000f, 0.809017f, 0.309017f },
	{ 0.238856f, 0.864188f, -0.442863f },
	{ 0.262866f, 0.951056f, -0.162460f },
	{ 0.500000f, 0.809017f, -0.309017f },
	{ 0.850651f, 0.525731f, 0.000000f },
	{ 0.716567f, 0.681718f, 0.147621f },
	{ 0.716567f, 0.681718f, -0.147621f },
	{ 0.525731f, 0.850651f, 0.000000f },
	{ 0.425325f, 0.688191f, 0.587785f },
	{ 0.864188f, 0.442863f, 0.238856f },
	{ 0.688191f, 0.587785f, 0.425325f },
	{ 0.809017f, 0.309017f, 0.500000f },
	{ 0.681718f, 0.147621f, 0.716567f },
	{ 0.587785f, 0.425325f, 0.688191f },
	{ 0.955423f, 0.295242f, 0.000000f },
	{ 1.000000f, 0.000000f, 0.000000f },
	{ 0.951056f, 0.162460f, 0.262866f },
	{ 0.850651f, -0.525731f, 0.000000f },
	{ 0.955423f, -0.295242f, 0.000000f },
	{ 0.864188f, -0.442863f, 0.238856f },
	{ 0.951056f, -0.162460f, 0.262866f },
	{ 0.809017f, -0.309017f, 0.500000f },
	{ 0.681718f, -0.147621f, 0.716567f },
	{ 0.850651f, 0.000000f, 0.525731f },
	{ 0.864188f, 0.442863f, -0.238856f },
	{ 0.809017f, 0.309017f, -0.500000f },
	{ 0.951056f, 0.162460f, -0.262866f },
	{ 0.525731f, 0.000000f, -0.850651f },
	{ 0.681718f, 0.147621f, -0.716567f },
	{ 0.681718f, -0.147621f, -0.716567f },
	{ 0.850651f, 0.000000f, -0.525731f },
	{ 0.809017f, -0.309017f, -0.500000f },
	{ 0.864188f, -0.442863f, -0.238856f },
	{ 0.951056f, -0.162460f, -0.262866f },
	{ 0.147621f, 0.716567f, -0.681718f },
	{ 0.309017f, 0.500000f, -0.809017f },
	{ 0.425325f, 0.688191f, -0.587785f },
	{ 0.442863f, 0.238856f, -0.864188f },
	{ 0.587785f, 0.425325f, -0.688191f },
	{ 0.688191f, 0.587785f, -0.425325f },
	{ -0.147621f, 0.716567f, -0.681718f },
	{ -0.309017f, 0.500000f, -0.809017f },
	{ 0.000000f, 0.525731f, -0.850651f },
	{ -0.525731f, 0.000000f, -0.850651f },
	{ -0.442863f, 0.238856f, -0.864188f },
	{ -0.295242f, 0.000000f, -0.955423f },
	{ -0.162460f, 0.262866f, -0.951056f },
	{ 0.000000f, 0.000000f, -1.000000f },
	{ 0.295242f, 0.000000f, -0.955423f },
	{ 0.162460f, 0.262866f, -0.951056f },
	{ -0.442863f, -0.238856f, -0.864188f },
	{ -0.309017f, -0.500000f, -0.809017f },
	{ -0.162460f, -0.262866f, -0.951056f },
	{ 0.000000f, -0.850651f, -0.525731f },
	{ -0.147621f, -0.716567f, -0.681718f },
	{ 0.147621f, -0.716567f, -0.681718f },
	{ 0.000000f, -0.525731f, -0.850651f },
	{ 0.309017f, -0.500000f, -0.809017f },
	{ 0.442863f, -0.238856f, -0.864188f },
	{ 0.162460f, -0.262866f, -0.951056f },
	{ 0.238856f, -0.864188f, -0.442863f },
	{ 0.500000f, -0.809017f, -0.309017f },
	{ 0.425325f, -0.688191f, -0.587785f },
	{ 0.716567f, -0.681718f, -0.147621f },
	{ 0.688191f, -0.587785f, -0.425325f },
	{ 0.587785f, -0.425325f, -0.688191f },
	{ 0.000000f, -0.955423f, -0.295242f },
	{ 0.000000f, -1.000000f, 0.000000f },
	{ 0.262866f, -0.951056f, -0.162460f },
	{ 0.000000f, -0.850651f, 0.525731f },
	{ 0.000000f, -0.955423f, 0.295242f },
	{ 0.238856f, -0.864188f, 0.442863f },
	{ 0.262866f, -0.951056f, 0.162460f },
	{ 0.500000f, -0.809017f, 0.309017f },
	{ 0.716567f, -0.681718f, 0.147621f },
	{ 0.525731f, -0.850651f, 0.000000f },
	{ -0.238856f, -0.864188f, -0.442863f },
	{ -0.500000f, -0.809017f, -0.309017f },
	{ -0.262866f, -0.951056f, -0.162460f },
	{ -0.850651f, -0.525731f, 0.000000f },
	{ -0.716567f, -0.681718f, -0.147621f },
	{ -0.716567f, -0.681718f, 0.147621f },
	{ -0.525731f, -0.850651f, 0.000000f },
	{ -0.500000f, -0.809017f, 0.309017f },
	{ -0.238856f, -0.864188f, 0.442863f },
	{ -0.262866f, -0.951056f, 0.162460f },
	{ -0.864188f, -0.442863f, 0.238856f },
	{ -0.809017f, -0.309017f, 0.500000f },
	{ -0.688191f, -0.587785f, 0.425325f },
	{ -0.681718f, -0.147621f, 0.716567f },
	{ -0.442863f, -0.238856f, 0.864188f },
	{ -0.587785f, -0.425325f, 0.688191f },
	{ -0.309017f, -0.500000f, 0.809017f },
	{ -0.147621f, -0.716567f, 0.681718f },
	{ -0.425325f, -0.688191f, 0.587785f },
	{ -0.162460f, -0.262866f, 0.951056f },
	{ 0.442863f, -0.238856f, 0.864188f },
	{ 0.162460f, -0.262866f, 0.951056f },
	{ 0.309017f, -0.500000f, 0.809017f },
	{ 0.147621f, -0.716567f, 0.681718f },
	{ 0.000000f, -0.525731f, 0.850651f },
	{ 0.425325f, -0.688191f, 0.587785f },
	{ 0.587785f, -0.425325f, 0.688191f },
	{ 0.688191f, -0.587785f, 0.425325f },
	{ -0.955423f, 0.295242f, 0.000000f },
	{ -0.951056f, 0.162460f, 0.262866f },
	{ -1.000000f, 0.000000f, 0.000000f },
	{ -0.850651f, 0.000000f, 0.525731f },
	{ -0.955423f, -0.295242f, 0.000000f },
	{ -0.951056f, -0.162460f, 0.262866f },
	{ -0.864188f, 0.442863f, -0.238856f },
	{ -0.951056f, 0.162460f, -0.262866f },
	{ -0.809017f, 0.309017f, -0.500000f },
	{ -0.864188f, -0.442863f, -0.238856f },
	{ -0.951056f, -0.162460f, -0.262866f },
	{ -0.809017f, -0.309017f, -0.500000f },
	{ -0.681718f, 0.147621f, -0.716567f },
	{ -0.681718f, -0.147621f, -0.716567f },
	{ -0.850651f, 0.000000f, -0.525731f },
	{ -0.688191f, 0.587785f, -0.425325f },
	{ -0.587785f, 0.425325f, -0.688191f },
	{ -0.425325f, 0.688191f, -0.587785f },
	{ -0.425325f, -0.688191f, -0.587785f },
	{ -0.587785f, -0.425325f, -0.688191f },
	{ -0.688191f, -0.587785f, -0.425325f },
};

// all header fields are little endian in the file
static int MDLInt( const byte *p ) {
	return ( int )p[0] | ( ( int )p[1] << 8 ) | ( ( int )p[2] << 16 ) | ( ( int )p[3] << 24 );
}

static float MDLFloat( const byte *p ) {
	int v = MDLInt( p );
	float f;
	memcpy( &f, &v, 4 );
	return f;
}

// dstvert_t, one texture coordinate per vertex, in pixels
struct mdlStVert_t {
	int			onseam;
	int			s;
	int			t;
};

/*
=================
idRenderModelMDL::idRenderModelMDL
=================
*/
idRenderModelMDL::idRenderModelMDL() {
	tris = NULL;
	numVerts = 0;
	numTris = 0;
	shader = NULL;
	skinWidth = 0;
	skinHeight = 0;
	skinCount = 0;
	mdlScale = vec3_zero;
	mdlOrigin = vec3_zero;
}

/*
=================
idRenderModelMDL::~idRenderModelMDL
=================
*/
idRenderModelMDL::~idRenderModelMDL() {
	// the base destructor calls PurgeModel again, which is a no-op then
	PurgeModel();
}

/*
=================
idRenderModelMDL::InitFromFile
=================
*/
void idRenderModelMDL::InitFromFile( const char *fileName ) {
	name = fileName;
	LoadModel();
}

/*
=================
idRenderModelMDL::LoadModel

Used for initial loads, reloadModel, and reloading the data of purged
models. Upon exit the model will be valid, possibly as a default model.
=================
*/
void idRenderModelMDL::LoadModel() {
	if ( !purged ) {
		PurgeModel();
	}
	purged = false;

	if ( !LoadMDLFile() ) {
		FreeData();
		MakeDefaultModel();
	}
}

/*
===================
idRenderModelMDL::LoadMDLFile
===================
*/
bool idRenderModelMDL::LoadMDLFile() {
	byte *buffer = NULL;
	int len = fileSystem->ReadFile( name, &buffer, &timeStamp );
	if ( buffer == NULL || len < 72 ) {
		common->Warning( "MDL loader was unable to load model %s\n", name.c_str() );
		fileSystem->FreeFile( buffer );
		return false;
	}

	// mdl_t: ident, version, the scale, the scale origin, the counts,
	// then the sizes, the scale fields are floats
	if ( MDLInt( buffer + 0 ) != MDL_IDENT || MDLInt( buffer + 4 ) != MDL_VERSION ) {
		common->Warning( "%s has the wrong ident or version\n", name.c_str() );
		fileSystem->FreeFile( buffer );
		return false;
	}

	mdlScale = idVec3( MDLFloat( buffer + 8 ), MDLFloat( buffer + 12 ), MDLFloat( buffer + 16 ) );
	mdlOrigin = idVec3( MDLFloat( buffer + 20 ), MDLFloat( buffer + 24 ), MDLFloat( buffer + 28 ) );
	int nSkins = MDLInt( buffer + 36 );
	skinWidth = MDLInt( buffer + 40 );
	skinHeight = MDLInt( buffer + 44 );
	int nVerts = MDLInt( buffer + 48 );
	int nTris = MDLInt( buffer + 52 );
	int nFrames = MDLInt( buffer + 56 );

	if ( skinWidth < 1 || skinWidth > 4096 || skinHeight < 1 || skinHeight > 4096 ||
		nVerts < 3 || nVerts > MDL_MAX_VERTS || nTris < 1 || nTris > MDL_MAX_TRIS ||
		nSkins < 0 || nSkins > MDL_MAX_SKINS || nFrames < 1 ) {
		common->Warning( "%s has an invalid header\n", name.c_str() );
		fileSystem->FreeFile( buffer );
		return false;
	}

	imageBase = name;
	imageBase.StripFileExtension();

	// the skins are raw indexed blocks, expanded through the Quake 1
	// palette, skin groups are flattened
	byte palette[768];
	if ( nSkins > 0 ) {
		if ( !MDL_LoadQ1Palette( palette ) ) {
			fileSystem->FreeFile( buffer );
			return false;
		}
	}

	int pos = 72;
	for ( int i = 0; i < nSkins; i++ ) {
		if ( pos + 4 > len ) {
			fileSystem->FreeFile( buffer );
			return false;
		}
		int skinType = MDLInt( buffer + pos );
		pos += 4;
		if ( skinType == MDL_SINGLE ) {
			if ( !DecodeSkin( buffer, pos, len, palette ) ) {
				fileSystem->FreeFile( buffer );
				return false;
			}
		} else if ( skinType == MDL_GROUP ) {
			if ( pos + 4 > len ) {
				fileSystem->FreeFile( buffer );
				return false;
			}
			int subSkins = MDLInt( buffer + pos );
			pos += 4;
			if ( subSkins < 1 || subSkins > MDL_MAX_SKINS ) {
				fileSystem->FreeFile( buffer );
				return false;
			}
			// the group times are flattened away
			pos += subSkins * 4;
			for ( int j = 0; j < subSkins; j++ ) {
				if ( !DecodeSkin( buffer, pos, len, palette ) ) {
					fileSystem->FreeFile( buffer );
					return false;
				}
			}
		} else {
			common->Warning( "%s has an unknown skin type (%i)\n", name.c_str(), skinType );
			fileSystem->FreeFile( buffer );
			return false;
		}
	}

	// dstvert_t: onseam, s and t in pixels
	mdlStVert_t *stVerts = ( mdlStVert_t * )Mem_Alloc( nVerts * sizeof( mdlStVert_t ), TAG_MODEL );
	for ( int i = 0; i < nVerts; i++ ) {
		stVerts[i].onseam = MDLInt( buffer + pos + i * 12 + 0 );
		stVerts[i].s = MDLInt( buffer + pos + i * 12 + 4 );
		stVerts[i].t = MDLInt( buffer + pos + i * 12 + 8 );
		if ( stVerts[i].s < 0 || stVerts[i].s >= skinWidth * 2 || stVerts[i].t < 0 || stVerts[i].t >= skinHeight ) {
			common->Warning( "%s has an invalid texture coordinate (%i)\n", name.c_str(), i );
			Mem_Free( stVerts );
			fileSystem->FreeFile( buffer );
			return false;
		}
	}
	pos += nVerts * 12;

	// dtriangle_t: facesfront and the vertex indices, a backface corner
	// shifts its texture coordinate by half the skin width
	numVerts = nVerts;
	numTris = nTris;
	tris = ( mdlTri_t * )Mem_Alloc( nTris * sizeof( mdlTri_t ), TAG_MODEL );
	for ( int i = 0; i < nTris; i++ ) {
		int facesfront = MDLInt( buffer + pos + i * 16 + 0 );
		for ( int k = 0; k < 3; k++ ) {
			int vi = MDLInt( buffer + pos + i * 16 + 4 + k * 4 );
			if ( vi < 0 || vi >= nVerts ) {
				common->Warning( "%s has an invalid triangle (%i)\n", name.c_str(), i );
				Mem_Free( stVerts );
				fileSystem->FreeFile( buffer );
				return false;
			}
			int s = stVerts[vi].s;
			int t = stVerts[vi].t;
			if ( !facesfront && stVerts[vi].onseam ) {
				s += skinWidth / 2;
			}
			tris[i].xyz[k] = vi;
			tris[i].st[k].x = ( float )s / ( float )skinWidth;
			tris[i].st[k].y = ( float )( skinHeight - 1 - t ) / ( float )skinHeight;
		}
	}
	pos += nTris * 16;
	Mem_Free( stVerts );

	// every frame is a bbox pair, a name and the packed vertices, frame
	// groups are flattened
	bounds.Clear();
	for ( int f = 0; f < nFrames; f++ ) {
		if ( pos + 4 > len ) {
			fileSystem->FreeFile( buffer );
			return false;
		}
		int frameType = MDLInt( buffer + pos );
		pos += 4;
		if ( frameType == MDL_SINGLE ) {
			if ( !DecodeFrame( buffer, pos, len ) ) {
				fileSystem->FreeFile( buffer );
				return false;
			}
		} else if ( frameType == MDL_GROUP ) {
			if ( pos + 4 > len ) {
				fileSystem->FreeFile( buffer );
				return false;
			}
			int subFrames = MDLInt( buffer + pos );
			pos += 4;
			if ( subFrames < 1 || subFrames > MDL_MAX_FRAMES ) {
				fileSystem->FreeFile( buffer );
				return false;
			}
			// the group times are flattened away, the game code drives
			// the timing through the frame shader parms
			pos += subFrames * 4;
			for ( int j = 0; j < subFrames; j++ ) {
				if ( !DecodeFrame( buffer, pos, len ) ) {
					fileSystem->FreeFile( buffer );
					return false;
				}
			}
		} else {
			common->Warning( "%s has an unknown frame type (%i)\n", name.c_str(), frameType );
			fileSystem->FreeFile( buffer );
			return false;
		}
	}

	fileSystem->FreeFile( buffer );

	return true;
}

/*
===================
idRenderModelMDL::DecodeSkin

Decodes one skin block into an embedded image, the first skin becomes
the surface material.
===================
*/
bool idRenderModelMDL::DecodeSkin( const byte *data, int &pos, int len, byte palette[768] ) {
	if ( pos + skinWidth * skinHeight > len ) {
		return false;
	}

	const byte *skinData = data + pos;
	pos += skinWidth * skinHeight;

	// skins are opaque, expand bottom up through the palette
	byte *pic = ( byte * )Mem_Alloc( skinWidth * skinHeight * 4, TAG_IMAGE );
	for ( int y = 0; y < skinHeight; y++ ) {
		const byte *inRow = skinData + y * skinWidth;
		byte *outRow = pic + ( skinHeight - 1 - y ) * skinWidth * 4;
		for ( int x = 0; x < skinWidth; x++ ) {
			byte index = inRow[x];
			outRow[x*4+0] = palette[index*3+0];
			outRow[x*4+1] = palette[index*3+1];
			outRow[x*4+2] = palette[index*3+2];
			outRow[x*4+3] = 255;
		}
	}

	idStr imageName;
	imageName.Format( "%s_skin_%i", imageBase.c_str(), skinCount );
	MDL_RegisterEmbeddedImage( imageName, pic, skinWidth, skinHeight );
	globalImages->ImageFromFunction( imageName, MDL_GenerateEmbeddedImage );

	if ( shader == NULL ) {
		// the first skin is the surface material, the rest are only
		// registered as images so materials can reference them
		shader = declManager->FindMaterial( imageName );
	}

	skinCount++;
	return true;
}

/*
===================
idRenderModelMDL::DecodeFrame

Decodes one frame block into a frame entry.
===================
*/
bool idRenderModelMDL::DecodeFrame( const byte *data, int &pos, int len ) {
	if ( frames.Num() >= MDL_MAX_FRAMES ) {
		return false;
	}
	if ( pos + 24 + numVerts * 4 > len ) {
		return false;
	}

	// daliasframe_t: the bbox record and the frame name are skipped, the
	// bounds are computed from the vertices instead, the Quake 1 hack of
	// growing the stored box by 16 units is not replicated
	const byte *vertData = data + pos + 24;
	pos += 24 + numVerts * 4;

	mdlFrame_t &frame = frames.Alloc();
	frame.verts = ( mdlVert_t * )Mem_Alloc( numVerts * sizeof( mdlVert_t ), TAG_MODEL );
	frame.bounds.Clear();
	for ( int v = 0; v < numVerts; v++ ) {
		mdlVert_t &vert = frame.verts[v];
		vert.xyz.x = ( float )vertData[v*4+0] * mdlScale.x + mdlOrigin.x;
		vert.xyz.y = ( float )vertData[v*4+1] * mdlScale.y + mdlOrigin.y;
		vert.xyz.z = ( float )vertData[v*4+2] * mdlScale.z + mdlOrigin.z;
		int normalIndex = vertData[v*4+3];
		if ( normalIndex >= 0 && normalIndex < 162 ) {
			vert.normal = idVec3( MDLAnorms[normalIndex][0], MDLAnorms[normalIndex][1], MDLAnorms[normalIndex][2] );
		} else {
			vert.normal = idVec3( 0.0f, 0.0f, 1.0f );
		}
		frame.bounds.AddPoint( vert.xyz );
	}
	bounds.AddBounds( frame.bounds );

	return true;
}

/*
===================
idRenderModelMDL::FreeData
===================
*/
void idRenderModelMDL::FreeData() {
	for ( int i = 0; i < frames.Num(); i++ ) {
		Mem_Free( frames[i].verts );
		frames[i].verts = NULL;
	}
	frames.Clear();

	Mem_Free( tris );
	tris = NULL;
	numVerts = 0;
	numTris = 0;
	shader = NULL;
	skinCount = 0;
}

/*
===================
idRenderModelMDL::PurgeModel

Frees all the data, but leaves the class around for dangling references,
which can regenerate the data with LoadModel().
===================
*/
void idRenderModelMDL::PurgeModel() {
	idRenderModelStatic::PurgeModel();

	FreeData();
}

/*
=================
idRenderModelMDL::TouchData

Models that are already loaded at level start time will still touch
their materials to make sure they are kept loaded.
=================
*/
void idRenderModelMDL::TouchData() {
	if ( shader != NULL ) {
		shader = declManager->FindMaterial( shader->GetName() );
	}
}

/*
=================
idRenderModelMDL::IsDynamicModel
=================
*/
dynamicModel_t idRenderModelMDL::IsDynamicModel() const {
	return DM_CACHED;
}

/*
=================
idRenderModelMDL::GetFrameParms

Reads the frames and the interpolation amount the entity wants to show.
=================
*/
void idRenderModelMDL::GetFrameParms( const struct renderEntity_s *ent, int &frame, int &lastFrame, float &backLerp ) const {
	frame = 0;
	lastFrame = 0;
	backLerp = 0.0f;

	if ( ent == NULL ) {
		return;
	}

	frame = idMath::Ftoi( ent->shaderParms[SHADERPARM_MD3_FRAME] );
	lastFrame = idMath::Ftoi( ent->shaderParms[SHADERPARM_MD3_LASTFRAME] );
	backLerp = ent->shaderParms[SHADERPARM_MD3_BACKLERP];

	int max = frames.Num() - 1;
	frame = idMath::ClampInt( 0, max, frame );
	lastFrame = idMath::ClampInt( 0, max, lastFrame );
	if ( backLerp < 0.0f ) {
		backLerp = 0.0f;
	} else if ( backLerp > 1.0f ) {
		backLerp = 1.0f;
	}
}

/*
=================
idRenderModelMDL::InstantiateDynamicModel

Expands the current frame pair into a triangle soup and interpolates
between them.
=================
*/
idRenderModel *idRenderModelMDL::InstantiateDynamicModel( const struct renderEntity_s *ent, const viewDef_t *view, idRenderModel *cachedModel ) {
	if ( cachedModel != NULL && !r_useCachedDynamicModels.GetBool() ) {
		delete cachedModel;
		cachedModel = NULL;
	}

	if ( purged ) {
		common->DWarning( "model %s instantiated while purged", Name() );
		LoadModel();
	}

	if ( frames.Num() == 0 ) {
		delete cachedModel;
		return NULL;
	}

	int frame = 0;
	int lastFrame = 0;
	float backLerp = 0.0f;
	GetFrameParms( ent, frame, lastFrame, backLerp );
	float frontLerp = 1.0f - backLerp;

	const idMaterial *drawShader = shader;
	if ( ent != NULL && ent->customShader != NULL ) {
		drawShader = ent->customShader;
	}
	if ( drawShader == NULL ) {
		drawShader = declManager->FindMaterial( "_default" );
	}
	if ( !drawShader || ( !drawShader->IsDrawn() && !drawShader->SurfaceCastsShadow() ) ) {
		delete cachedModel;
		return NULL;
	}

	idRenderModelStatic *staticModel;
	if ( cachedModel != NULL ) {
		assert( dynamic_cast<idRenderModelStatic *>( cachedModel ) != NULL );
		assert( idStr::Icmp( cachedModel->Name(), MDL_SnapshotName ) == 0 );
		staticModel = static_cast<idRenderModelStatic *>( cachedModel );
	} else {
		staticModel = new (TAG_MODEL) idRenderModelStatic;
		staticModel->InitEmpty( MDL_SnapshotName );
	}

	srfTriangles_t *tri;
	int surfaceNum = 0;
	if ( staticModel->FindSurfaceWithId( 0, surfaceNum ) ) {
		tri = staticModel->surfaces[surfaceNum].geometry;
	} else {
		modelSurface_t &surf = staticModel->surfaces.Alloc();
		surf.id = 0;
		surf.shader = NULL;
		surf.geometry = R_AllocStaticTriSurf();
		tri = surf.geometry;
	}
	staticModel->surfaces[surfaceNum].shader = drawShader;

	// the mesh is expanded into a triangle soup, the texture coordinates
	// are final per corner because of the backside shift
	int soupVerts = numTris * 3;
	if ( tri->numVerts != soupVerts || tri->numIndexes != soupVerts ) {
		R_AllocStaticTriSurfVerts( tri, soupVerts );
		R_AllocStaticTriSurfIndexes( tri, soupVerts );
	}
	tri->numVerts = soupVerts;
	tri->numIndexes = soupVerts;

	const mdlVert_t *frontVerts = frames[frame].verts;
	const mdlVert_t *backVerts = frames[lastFrame].verts;

	idDrawVert *verts = tri->verts;
	int v = 0;
	for ( int t = 0; t < numTris; t++ ) {
		const mdlTri_t &modelTri = tris[t];
		for ( int k = 0; k < 3; k++ ) {
			const mdlVert_t &front = frontVerts[modelTri.xyz[k]];
			const mdlVert_t &back = backVerts[modelTri.xyz[k]];
			idDrawVert &out = verts[v];

			out.Clear();
			out.xyz = front.xyz * frontLerp + back.xyz * backLerp;
			out.SetNormal( front.normal * frontLerp + back.normal * backLerp );
			out.SetTexCoord( modelTri.st[k].x, modelTri.st[k].y );
			for ( int c = 0; c < 4; c++ ) {
				out.color[c] = 255;
				out.color2[c] = 255;
			}
			tri->indexes[v] = v;
			v++;
		}
	}

	// build the tangents for interaction lighting, keeping the normals
	R_DeriveTangentsWithoutNormals( tri );

	R_BoundTriSurf( tri );

	staticModel->bounds = tri->bounds;

	return staticModel;
}

/*
=====================
idRenderModelMDL::Bounds
=====================
*/
idBounds idRenderModelMDL::Bounds( const struct renderEntity_s *ent ) const {
	if ( ent == NULL || frames.Num() == 0 ) {
		return bounds;
	}

	int frame = 0;
	int lastFrame = 0;
	float backLerp = 0.0f;
	GetFrameParms( ent, frame, lastFrame, backLerp );

	idBounds ret = frames[frame].bounds;
	ret.AddBounds( frames[lastFrame].bounds );
	return ret;
}

/*
==============
idRenderModelMDL::List
==============
*/
void idRenderModelMDL::List() const {
	common->Printf( " %7i bytes %4i frames %4i verts %4i tris %s", Memory(), frames.Num(), numVerts, numTris, Name() );

	if ( defaulted ) {
		common->Printf( " (DEFAULTED)" );
	}

	common->Printf( "\n" );
}

/*
===============
idRenderModelMDL::Memory
===============
*/
int idRenderModelMDL::Memory() const {
	int total = sizeof( *this );
	total += frames.MemoryUsed();
	total += frames.Num() * ( sizeof( mdlFrame_t ) + numVerts * sizeof( mdlVert_t ) );
	total += numTris * sizeof( mdlTri_t );
	return total;
}
