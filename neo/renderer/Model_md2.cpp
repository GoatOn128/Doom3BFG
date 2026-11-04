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
#include "Model_md2.h"

void R_DeriveTangentsWithoutNormals( srfTriangles_t *tri );

/***********************************************************************

	idRenderModelMD2

***********************************************************************/

static const char *MD2_SnapshotName = "_MD2_Snapshot_";

// dmdl_t ident "IDP2" and version
#define MD2_IDENT	( ( '2' << 24 ) + ( 'P' << 16 ) + ( 'D' << 8 ) + 'I' )
#define MD2_VERSION	8

// the 162 vertex normals from the Quake 2 anorms.h table
static const float MD2Anorms[162][3] = {
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
static int MD2Int( const byte *p ) {
	return ( int )p[0] | ( ( int )p[1] << 8 ) | ( ( int )p[2] << 16 ) | ( ( int )p[3] << 24 );
}

static short MD2Short( const byte *p ) {
	return ( short )( ( int )p[0] | ( ( int )p[1] << 8 ) );
}

static float MD2Float( const byte *p ) {
	int v = MD2Int( p );
	float f;
	memcpy( &f, &v, 4 );
	return f;
}

/*
=================
idRenderModelMD2::idRenderModelMD2
=================
*/
idRenderModelMD2::idRenderModelMD2() {
	tris = NULL;
	st = NULL;
	numVerts = 0;
	numTris = 0;
	shader = NULL;
}

/*
=================
idRenderModelMD2::~idRenderModelMD2
=================
*/
idRenderModelMD2::~idRenderModelMD2() {
	// the base destructor calls PurgeModel again, which is a no-op then
	PurgeModel();
}

/*
=================
idRenderModelMD2::InitFromFile
=================
*/
void idRenderModelMD2::InitFromFile( const char *fileName ) {
	name = fileName;
	LoadModel();
}

/*
=================
idRenderModelMD2::LoadModel

Used for initial loads, reloadModel, and reloading the data of purged
models. Upon exit the model will be valid, possibly as a default model.
=================
*/
void idRenderModelMD2::LoadModel() {
	if ( !purged ) {
		PurgeModel();
	}
	purged = false;

	if ( !LoadMD2File() ) {
		FreeData();
		MakeDefaultModel();
	}
}

/*
===================
idRenderModelMD2::LoadMD2File
===================
*/
bool idRenderModelMD2::LoadMD2File() {
	byte *buffer = NULL;
	int len = fileSystem->ReadFile( name, &buffer, &timeStamp );
	if ( buffer == NULL || len < 60 ) {
		common->Warning( "MD2 loader was unable to load model %s\n", name.c_str() );
		fileSystem->FreeFile( buffer );
		return false;
	}

	// dmdl_t: ident, version, skinwidth, skinheight, framesize, the
	// counts, then the section offsets
	if ( MD2Int( buffer + 0 ) != MD2_IDENT || MD2Int( buffer + 4 ) != MD2_VERSION ) {
		common->Warning( "%s has the wrong ident or version\n", name.c_str() );
		fileSystem->FreeFile( buffer );
		return false;
	}

	int skinwidth = MD2Int( buffer + 8 );
	int skinheight = MD2Int( buffer + 12 );
	int framesize = MD2Int( buffer + 16 );
	int nSkins = MD2Int( buffer + 20 );
	int nXyz = MD2Int( buffer + 24 );
	int nTris = MD2Int( buffer + 28 );
	int ofsSkins = MD2Int( buffer + 36 );
	int ofsSt = MD2Int( buffer + 40 );
	int ofsTris = MD2Int( buffer + 44 );
	int ofsFrames = MD2Int( buffer + 48 );
	int ofsEnd = MD2Int( buffer + 56 );

	if ( skinwidth < 1 || skinwidth > 4096 || skinheight < 1 || skinheight > 4096 ||
		nXyz < 3 || nXyz > MD2_MAX_VERTS || nTris < 1 || nTris > MD2_MAX_TRIS ||
		nSkins < 0 || nSkins > 32 || ofsEnd <= 0 || ofsEnd > len ||
		framesize != 40 + nXyz * 4 ) {
		common->Warning( "%s has an invalid header\n", name.c_str() );
		fileSystem->FreeFile( buffer );
		return false;
	}

	int nFrames = ( ofsEnd - ofsFrames ) / framesize;
	if ( nFrames < 1 || nFrames > MD2_MAX_FRAMES ||
		ofsFrames + nFrames * framesize != ofsEnd ||
		ofsSkins + nSkins * 64 > ofsEnd ||
		ofsSt + nXyz * 4 > ofsEnd ||
		ofsTris + nTris * 12 > ofsEnd ) {
		common->Warning( "%s has an invalid layout\n", name.c_str() );
		fileSystem->FreeFile( buffer );
		return false;
	}

	// the skins are name records, the first one is used as the surface
	// material, any additional skin names are ignored
	if ( nSkins > 0 ) {
		char skinName[65];
		memcpy( skinName, buffer + ofsSkins, 64 );
		skinName[64] = '\0';
		shader = declManager->FindMaterial( skinName );
	} else {
		shader = declManager->FindMaterial( "_default" );
	}

	numVerts = nXyz;
	numTris = nTris;

	// the texture coordinates are stored in pixels with t starting at
	// the top, convert them to the bottom up 0..1 range of the engine
	st = ( idVec2 * )Mem_Alloc( nXyz * sizeof( idVec2 ), TAG_MODEL );
	for ( int i = 0; i < nXyz; i++ ) {
		int s = MD2Short( buffer + ofsSt + i * 4 + 0 );
		int t = MD2Short( buffer + ofsSt + i * 4 + 2 );
		st[i].x = ( float )s / ( float )skinwidth;
		st[i].y = ( float )( skinheight - 1 - t ) / ( float )skinheight;
	}

	// every triangle corner references one vertex and one texture
	// coordinate, the two indices differ at texture seams
	tris = ( md2Tri_t * )Mem_Alloc( nTris * sizeof( md2Tri_t ), TAG_MODEL );
	for ( int i = 0; i < nTris; i++ ) {
		const byte *triData = buffer + ofsTris + i * 12;
		for ( int k = 0; k < 3; k++ ) {
			int xyz = MD2Short( triData + k * 2 );
			int stIdx = MD2Short( triData + 6 + k * 2 );
			if ( xyz < 0 || xyz >= nXyz || stIdx < 0 || stIdx >= nXyz ) {
				common->Warning( "%s has an invalid triangle (%i)\n", name.c_str(), i );
				fileSystem->FreeFile( buffer );
				return false;
			}
			tris[i].xyz[k] = xyz;
			tris[i].st[k] = stIdx;
		}
	}

	// every frame is a scale, a translate and the packed vertices
	bounds.Clear();
	for ( int f = 0; f < nFrames; f++ ) {
		const byte *frameData = buffer + ofsFrames + f * framesize;
		idVec3 scale( MD2Float( frameData + 0 ), MD2Float( frameData + 4 ), MD2Float( frameData + 8 ) );
		idVec3 translate( MD2Float( frameData + 12 ), MD2Float( frameData + 16 ), MD2Float( frameData + 20 ) );
		const byte *vertData = frameData + 40;

		md2Frame_t &frame = frames.Alloc();
		frame.verts = ( md2Vert_t * )Mem_Alloc( nXyz * sizeof( md2Vert_t ), TAG_MODEL );
		frame.bounds.Clear();
		for ( int v = 0; v < nXyz; v++ ) {
			md2Vert_t &vert = frame.verts[v];
			vert.xyz.x = ( float )vertData[v*4+0] * scale.x + translate.x;
			vert.xyz.y = ( float )vertData[v*4+1] * scale.y + translate.y;
			vert.xyz.z = ( float )vertData[v*4+2] * scale.z + translate.z;
			int normalIndex = vertData[v*4+3];
			if ( normalIndex >= 0 && normalIndex < 162 ) {
				vert.normal = idVec3( MD2Anorms[normalIndex][0], MD2Anorms[normalIndex][1], MD2Anorms[normalIndex][2] );
			} else {
				vert.normal = idVec3( 0.0f, 0.0f, 1.0f );
			}
			frame.bounds.AddPoint( vert.xyz );
		}
		bounds.AddBounds( frame.bounds );
	}

	fileSystem->FreeFile( buffer );

	return true;
}

/*
===================
idRenderModelMD2::FreeData
===================
*/
void idRenderModelMD2::FreeData() {
	for ( int i = 0; i < frames.Num(); i++ ) {
		Mem_Free( frames[i].verts );
		frames[i].verts = NULL;
	}
	frames.Clear();

	Mem_Free( tris );
	tris = NULL;
	Mem_Free( st );
	st = NULL;
	numVerts = 0;
	numTris = 0;
	shader = NULL;
}

/*
===================
idRenderModelMD2::PurgeModel

Frees all the data, but leaves the class around for dangling references,
which can regenerate the data with LoadModel().
===================
*/
void idRenderModelMD2::PurgeModel() {
	idRenderModelStatic::PurgeModel();

	FreeData();
}

/*
=================
idRenderModelMD2::TouchData

Models that are already loaded at level start time will still touch
their materials to make sure they are kept loaded.
=================
*/
void idRenderModelMD2::TouchData() {
	if ( shader != NULL ) {
		shader = declManager->FindMaterial( shader->GetName() );
	}
}

/*
=================
idRenderModelMD2::IsDynamicModel
=================
*/
dynamicModel_t idRenderModelMD2::IsDynamicModel() const {
	return DM_CACHED;
}

/*
=================
idRenderModelMD2::GetFrameParms

Reads the frames and the interpolation amount the entity wants to show.
=================
*/
void idRenderModelMD2::GetFrameParms( const struct renderEntity_s *ent, int &frame, int &lastFrame, float &backLerp ) const {
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
idRenderModelMD2::InstantiateDynamicModel

Expands the current frame pair into a triangle soup and interpolates
between them.
=================
*/
idRenderModel *idRenderModelMD2::InstantiateDynamicModel( const struct renderEntity_s *ent, const viewDef_t *view, idRenderModel *cachedModel ) {
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
		assert( idStr::Icmp( cachedModel->Name(), MD2_SnapshotName ) == 0 );
		staticModel = static_cast<idRenderModelStatic *>( cachedModel );
	} else {
		staticModel = new (TAG_MODEL) idRenderModelStatic;
		staticModel->InitEmpty( MD2_SnapshotName );
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

	// the mesh is expanded into a triangle soup because the vertex and
	// the texture coordinate indices differ at texture seams
	int soupVerts = numTris * 3;
	if ( tri->numVerts != soupVerts || tri->numIndexes != soupVerts ) {
		R_AllocStaticTriSurfVerts( tri, soupVerts );
		R_AllocStaticTriSurfIndexes( tri, soupVerts );
	}
	tri->numVerts = soupVerts;
	tri->numIndexes = soupVerts;

	const md2Vert_t *frontVerts = frames[frame].verts;
	const md2Vert_t *backVerts = frames[lastFrame].verts;

	idDrawVert *verts = tri->verts;
	int v = 0;
	for ( int t = 0; t < numTris; t++ ) {
		const md2Tri_t &modelTri = tris[t];
		for ( int k = 0; k < 3; k++ ) {
			const md2Vert_t &front = frontVerts[modelTri.xyz[k]];
			const md2Vert_t &back = backVerts[modelTri.xyz[k]];
			idDrawVert &out = verts[v];

			out.Clear();
			out.xyz = front.xyz * frontLerp + back.xyz * backLerp;
			out.SetNormal( front.normal * frontLerp + back.normal * backLerp );
			out.SetTexCoord( st[modelTri.st[k]].x, st[modelTri.st[k]].y );
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
idRenderModelMD2::Bounds
=====================
*/
idBounds idRenderModelMD2::Bounds( const struct renderEntity_s *ent ) const {
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
idRenderModelMD2::List
==============
*/
void idRenderModelMD2::List() const {
	common->Printf( " %7i bytes %4i frames %4i verts %4i tris %s", Memory(), frames.Num(), numVerts, numTris, Name() );

	if ( defaulted ) {
		common->Printf( " (DEFAULTED)" );
	}

	common->Printf( "\n" );
}

/*
===============
idRenderModelMD2::Memory
===============
*/
int idRenderModelMD2::Memory() const {
	int total = sizeof( *this );
	total += frames.MemoryUsed();
	total += frames.Num() * ( sizeof( md2Frame_t ) + numVerts * sizeof( md2Vert_t ) );
	total += numTris * sizeof( md2Tri_t );
	total += numVerts * sizeof( idVec2 );
	return total;
}
