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
#include "Model_sp2.h"

void R_DeriveTangentsWithoutNormals( srfTriangles_t *tri );

/***********************************************************************

	idRenderModelSP2

***********************************************************************/

static const char *SP2_SnapshotName = "_SP2_Snapshot_";

// dsprite_t ident "IDS2" and version
#define SP2_IDENT	( ( '2' << 24 ) + ( 'S' << 16 ) + ( 'D' << 8 ) + 'I' )
#define SP2_VERSION	2

// all header fields are little endian in the file
static int SP2Int( const byte *p ) {
	return ( int )p[0] | ( ( int )p[1] << 8 ) | ( ( int )p[2] << 16 ) | ( ( int )p[3] << 24 );
}

/*
=================
idRenderModelSP2::idRenderModelSP2
=================
*/
idRenderModelSP2::idRenderModelSP2() {
}

/*
=================
idRenderModelSP2::~idRenderModelSP2
=================
*/
idRenderModelSP2::~idRenderModelSP2() {
	// the base destructor calls PurgeModel again, which is a no-op then
	PurgeModel();
}

/*
=================
idRenderModelSP2::InitFromFile
=================
*/
void idRenderModelSP2::InitFromFile( const char *fileName ) {
	name = fileName;
	LoadModel();
}

/*
=================
idRenderModelSP2::LoadModel

Used for initial loads, reloadModel, and reloading the data of purged
models. Upon exit the model will be valid, possibly as a default model.
=================
*/
void idRenderModelSP2::LoadModel() {
	if ( !purged ) {
		PurgeModel();
	}
	purged = false;

	if ( !LoadSP2File() ) {
		frames.Clear();
		MakeDefaultModel();
	}
}

/*
===================
idRenderModelSP2::LoadSP2File
===================
*/
bool idRenderModelSP2::LoadSP2File() {
	byte *buffer = NULL;
	int len = fileSystem->ReadFile( name, ( void ** )&buffer, &timeStamp );
	if ( buffer == NULL || len < 12 ) {
		common->Warning( "SP2 loader was unable to load model %s\n", name.c_str() );
		fileSystem->FreeFile( buffer );
		return false;
	}

	// dsprite_t: ident, version, numframes
	if ( SP2Int( buffer + 0 ) != SP2_IDENT || SP2Int( buffer + 4 ) != SP2_VERSION ) {
		common->Warning( "%s has the wrong ident or version\n", name.c_str() );
		fileSystem->FreeFile( buffer );
		return false;
	}

	int numframes = SP2Int( buffer + 8 );
	if ( numframes < 1 || numframes > SP2_MAX_FRAMES ) {
		common->Warning( "%s has an invalid number of frames (%i)\n", name.c_str(), numframes );
		fileSystem->FreeFile( buffer );
		return false;
	}

	// every frame is a dsprframe_t: width, height, origin_x, origin_y
	// and the name of the frame image
	if ( len < 12 + numframes * 80 ) {
		common->Warning( "%s is too small for %i frames\n", name.c_str(), numframes );
		fileSystem->FreeFile( buffer );
		return false;
	}

	int pos = 12;
	for ( int i = 0; i < numframes; i++ ) {
		sp2Frame_t &frame = frames.Alloc();
		frame.width = SP2Int( buffer + pos + 0 );
		frame.height = SP2Int( buffer + pos + 4 );
		float originX = ( float )SP2Int( buffer + pos + 8 );
		float originY = ( float )SP2Int( buffer + pos + 12 );

		// the frame images are separate files, referenced by name, the
		// same way the Quake 2 loader looked them up
		char imageName[65];
		memcpy( imageName, buffer + pos + 16, 64 );
		imageName[64] = '\0';
		pos += 80;

		if ( frame.width < 1 || frame.height < 1 || frame.width > 4096 || frame.height > 4096 ) {
			common->Warning( "%s has an invalid frame size (%i x %i)\n", name.c_str(), frame.width, frame.height );
			frames.Clear();
			fileSystem->FreeFile( buffer );
			return false;
		}

		frame.material = declManager->FindMaterial( imageName );

		frame.left = originX;
		frame.right = originX + frame.width;
		frame.up = originY;
		frame.down = originY - frame.height;
	}

	fileSystem->FreeFile( buffer );

	// the reference bounds are the union of all frame bounds
	bounds.Clear();
	for ( int i = 0; i < frames.Num(); i++ ) {
		const sp2Frame_t &fr = frames[i];
		idBounds frameBounds;
		frameBounds.Clear();
		frameBounds.AddPoint( idVec3( 0.0f, fr.left, fr.down ) );
		frameBounds.AddPoint( idVec3( 0.0f, fr.right, fr.up ) );
		bounds.AddBounds( frameBounds );
	}

	return true;
}

/*
===================
idRenderModelSP2::PurgeModel

Frees all the data, but leaves the class around for dangling references,
which can regenerate the data with LoadModel().
===================
*/
void idRenderModelSP2::PurgeModel() {
	idRenderModelStatic::PurgeModel();

	frames.Clear();
}

/*
=================
idRenderModelSP2::TouchData

Models that are already loaded at level start time will still touch
their materials to make sure they are kept loaded.
=================
*/
void idRenderModelSP2::TouchData() {
	for ( int i = 0; i < frames.Num(); i++ ) {
		if ( frames[i].material != NULL ) {
			frames[i].material = declManager->FindMaterial( frames[i].material->GetName() );
		}
	}
}

/*
=================
idRenderModelSP2::IsDynamicModel
=================
*/
dynamicModel_t idRenderModelSP2::IsDynamicModel() const {
	return DM_CACHED;
}

/*
=================
idRenderModelSP2::GetFrameParms

Reads the frame the entity wants to show.
=================
*/
void idRenderModelSP2::GetFrameParms( const struct renderEntity_s *ent, int &frame ) const {
	frame = 0;

	if ( ent == NULL ) {
		return;
	}

	frame = idMath::Ftoi( ent->shaderParms[SHADERPARM_MD3_FRAME] );
	frame = idMath::ClampInt( 0, frames.Num() - 1, frame );
}

/*
=================
idRenderModelSP2::InstantiateDynamicModel

Builds a quad on the Y/Z plane from the current frame extents.
=================
*/
idRenderModel *idRenderModelSP2::InstantiateDynamicModel( const struct renderEntity_s *ent, const viewDef_t *view, idRenderModel *cachedModel ) {
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
	GetFrameParms( ent, frame );
	const sp2Frame_t &fr = frames[frame];

	const idMaterial *shader = fr.material;
	if ( ent != NULL && ent->customShader != NULL ) {
		shader = ent->customShader;
	}
	if ( shader == NULL ) {
		shader = declManager->FindMaterial( "_default" );
	}
	if ( !shader || ( !shader->IsDrawn() && !shader->SurfaceCastsShadow() ) ) {
		delete cachedModel;
		return NULL;
	}

	idRenderModelStatic *staticModel;
	if ( cachedModel != NULL ) {
		assert( dynamic_cast<idRenderModelStatic *>( cachedModel ) != NULL );
		assert( idStr::Icmp( cachedModel->Name(), SP2_SnapshotName ) == 0 );
		staticModel = static_cast<idRenderModelStatic *>( cachedModel );
	} else {
		staticModel = new (TAG_MODEL) idRenderModelStatic;
		staticModel->InitEmpty( SP2_SnapshotName );
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
		R_AllocStaticTriSurfVerts( tri, 4 );
		R_AllocStaticTriSurfIndexes( tri, 6 );
	}
	staticModel->surfaces[surfaceNum].shader = shader;

	tri->numVerts = 4;
	tri->numIndexes = 6;

	idDrawVert *verts = tri->verts;
	verts[0].Clear();
	verts[0].xyz = idVec3( 0.0f, fr.left, fr.up );
	verts[0].SetTexCoord( 0.0f, 1.0f );

	verts[1].Clear();
	verts[1].xyz = idVec3( 0.0f, fr.right, fr.up );
	verts[1].SetTexCoord( 1.0f, 1.0f );

	verts[2].Clear();
	verts[2].xyz = idVec3( 0.0f, fr.right, fr.down );
	verts[2].SetTexCoord( 1.0f, 0.0f );

	verts[3].Clear();
	verts[3].xyz = idVec3( 0.0f, fr.left, fr.down );
	verts[3].SetTexCoord( 0.0f, 0.0f );

	for ( int i = 0; i < 4; i++ ) {
		verts[i].SetNormal( 1.0f, 0.0f, 0.0f );
		verts[i].SetTangent( 0.0f, 1.0f, 0.0f );
		verts[i].SetBiTangent( 0.0f, 0.0f, 1.0f );
		for ( int c = 0; c < 4; c++ ) {
			verts[i].color[c] = 255;
			verts[i].color2[c] = 255;
		}
	}

	tri->indexes[0] = 0;
	tri->indexes[1] = 3;
	tri->indexes[2] = 2;
	tri->indexes[3] = 0;
	tri->indexes[4] = 2;
	tri->indexes[5] = 1;

	// build the tangents for interaction lighting, keeping the normals
	R_DeriveTangentsWithoutNormals( tri );

	R_BoundTriSurf( tri );

	staticModel->bounds = tri->bounds;

	return staticModel;
}

/*
=====================
idRenderModelSP2::Bounds
=====================
*/
idBounds idRenderModelSP2::Bounds( const struct renderEntity_s *ent ) const {
	if ( ent == NULL || frames.Num() == 0 ) {
		return bounds;
	}

	int frame = 0;
	GetFrameParms( ent, frame );
	const sp2Frame_t &fr = frames[frame];

	idBounds ret;
	ret.Clear();
	ret.AddPoint( idVec3( 0.0f, fr.left, fr.down ) );
	ret.AddPoint( idVec3( 0.0f, fr.right, fr.up ) );
	return ret;
}

/*
==============
idRenderModelSP2::List
==============
*/
void idRenderModelSP2::List() const {
	common->Printf( " %7i bytes %3i frames %s", Memory(), frames.Num(), Name() );

	if ( defaulted ) {
		common->Printf( " (DEFAULTED)" );
	}

	common->Printf( "\n" );
}

/*
===============
idRenderModelSP2::Memory
===============
*/
int idRenderModelSP2::Memory() const {
	int total = sizeof( *this );
	total += frames.MemoryUsed();
	total += frames.Num() * sizeof( sp2Frame_t );
	return total;
}
