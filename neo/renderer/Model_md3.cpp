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

#include "Model_local.h"
#include "Model_md3.h"

void R_DeriveTangentsWithoutNormals( srfTriangles_t *tri );

/***********************************************************************

	idRenderModelMD3

***********************************************************************/

static const char *MD3_SnapshotName = "_MD3_Snapshot_";

// MD3 level of detail selection, ported from the Quake III Arena renderer
static idCVar r_md3LodScale( "r_md3LodScale", "5", CVAR_FLOAT | CVAR_ARCHIVE | CVAR_RENDERER, "MD3 LOD scale, higher values keep higher detail longer" );
static idCVar r_md3LodBias( "r_md3LodBias", "0", CVAR_INTEGER | CVAR_ARCHIVE | CVAR_RENDERER, "MD3 LOD bias, positive values force lower detail" );

#define	LL(x) x=LittleInt(x)

/*
=================
MD3_DecodeNormal

Decodes the packed lat/lng spherical normal into a unit vector.
=================
*/
static void MD3_DecodeNormal( short normal, idVec3 &out ) {
	float lat = ( float )( ( normal >> 8 ) & 255 ) * ( idMath::PI / 128.0f );
	float lng = ( float )( normal & 255 ) * ( idMath::PI / 128.0f );

	out[0] = idMath::Cos( lat ) * idMath::Sin( lng );
	out[1] = idMath::Sin( lat ) * idMath::Sin( lng );
	out[2] = idMath::Cos( lng );
}

/*
=================
MD3_RadiusFromBounds

Radius of a sphere centered at the origin that encloses the bounds.
=================
*/
static float MD3_RadiusFromBounds( const idVec3 bounds[2] ) {
	idVec3 corner;

	for ( int i = 0; i < 3; i++ ) {
		float a = idMath::Fabs( bounds[0][i] );
		float b = idMath::Fabs( bounds[1][i] );
		corner[i] = ( a > b ) ? a : b;
	}

	return corner.Length();
}

/*
=================
MD3_ProjectRadius

Projects a radius at a world location into normalized view space.
=================
*/
static float MD3_ProjectRadius( float r, const idVec3 &location, const viewDef_t *view ) {
	const float *m = view->projectionMatrix;

	float c = view->renderView.viewaxis[0] * view->renderView.vieworg;
	float dist = view->renderView.viewaxis[0] * location - c;

	if ( dist <= 0.0f ) {
		return 0.0f;
	}

	idVec3 p;
	p[0] = 0.0f;
	p[1] = idMath::Fabs( r );
	p[2] = -dist;

	float projected[4];
	for ( int i = 0; i < 4; i++ ) {
		projected[i] = p[0] * m[0 + i] + p[1] * m[4 + i] + p[2] * m[8 + i] + m[12 + i];
	}

	float pr = projected[1] / projected[3];

	if ( pr > 1.0f ) {
		pr = 1.0f;
	}

	return pr;
}

/*
=================
MD3_LoadHeader

Loads a single MD3 file and byte swaps it in place. The whole file
stays in one memory block that is freed by PurgeModel. Returns false
on any failure.
=================
*/
static bool MD3_LoadHeader( const char *fileName, md3Header_t **headerOut, ID_TIME_T *timestamp ) {
	md3Header_t		*pinmodel;
	md3Frame_t		*frame;
	md3Surface_t	*surf;
	md3Shader_t		*shader;
	md3Triangle_t	*tri;
	md3St_t			*st;
	md3XyzNormal_t	*xyz;
	md3Tag_t		*tag;
	void			*buffer;
	int				version;
	int				fileLen;
	int				size;
	int				i, j;

	*headerOut = NULL;

	fileLen = fileSystem->ReadFile( fileName, &buffer, timestamp );
	if ( fileLen <= 0 ) {
		return false;
	}

	pinmodel = (md3Header_t *)buffer;

	if ( LittleInt( pinmodel->ident ) != MD3_IDENT ) {
		common->Warning( "MD3_LoadHeader: %s has the wrong ident", fileName );
		fileSystem->FreeFile( buffer );
		return false;
	}

	version = LittleInt( pinmodel->version );
	if ( version != MD3_VERSION ) {
		common->Warning( "MD3_LoadHeader: %s has wrong version (%i should be %i)", fileName, version, MD3_VERSION );
		fileSystem->FreeFile( buffer );
		return false;
	}

	if ( LittleInt( pinmodel->numFrames ) < 1 ) {
		common->Warning( "MD3_LoadHeader: %s has no frames", fileName );
		fileSystem->FreeFile( buffer );
		return false;
	}

	size = LittleInt( pinmodel->ofsEnd );
	if ( size > fileLen ) {
		common->Warning( "MD3_LoadHeader: %s has a bad ofsEnd", fileName );
		fileSystem->FreeFile( buffer );
		return false;
	}

	md3Header_t *header = (md3Header_t *)Mem_Alloc( size, TAG_MODEL );
	memcpy( header, buffer, size );
	fileSystem->FreeFile( buffer );

	LL(header->ident);
	LL(header->version);
	LL(header->numFrames);
	LL(header->numTags);
	LL(header->numSurfaces);
	LL(header->ofsFrames);
	LL(header->ofsTags);
	LL(header->ofsSurfaces);
	LL(header->ofsEnd);

	// swap all the frames
	frame = (md3Frame_t *) ( (byte *)header + header->ofsFrames );
	for ( i = 0; i < header->numFrames; i++, frame++ ) {
		frame->radius = LittleFloat( frame->radius );
		for ( j = 0; j < 3; j++ ) {
			frame->bounds[0][j] = LittleFloat( frame->bounds[0][j] );
			frame->bounds[1][j] = LittleFloat( frame->bounds[1][j] );
			frame->localOrigin[j] = LittleFloat( frame->localOrigin[j] );
		}
	}

	// swap all the tags
	tag = (md3Tag_t *) ( (byte *)header + header->ofsTags );
	for ( i = 0; i < header->numTags * header->numFrames; i++, tag++ ) {
		for ( j = 0; j < 3; j++ ) {
			tag->origin[j] = LittleFloat( tag->origin[j] );
			tag->axis[0][j] = LittleFloat( tag->axis[0][j] );
			tag->axis[1][j] = LittleFloat( tag->axis[1][j] );
			tag->axis[2][j] = LittleFloat( tag->axis[2][j] );
		}
	}

	// swap all the surfaces
	surf = (md3Surface_t *) ( (byte *)header + header->ofsSurfaces );
	for ( i = 0; i < header->numSurfaces; i++ ) {

		LL(surf->ident);
		LL(surf->flags);
		LL(surf->numFrames);
		LL(surf->numShaders);
		LL(surf->numTriangles);
		LL(surf->ofsTriangles);
		LL(surf->numVerts);
		LL(surf->ofsShaders);
		LL(surf->ofsSt);
		LL(surf->ofsXyzNormals);
		LL(surf->ofsEnd);

		if ( surf->numVerts > SHADER_MAX_VERTEXES ) {
			common->Error( "MD3_LoadHeader: %s has more than %i verts on a surface (%i)", fileName, SHADER_MAX_VERTEXES, surf->numVerts );
		}
		if ( surf->numTriangles * 3 > SHADER_MAX_INDEXES ) {
			common->Error( "MD3_LoadHeader: %s has more than %i triangles on a surface (%i)", fileName, SHADER_MAX_INDEXES / 3, surf->numTriangles );
		}

		// change to surface identifier
		surf->ident = 0;	//SF_MD3;

		// lowercase the surface name so skin compares are faster
		int slen = (int)strlen( surf->name );
		for ( j = 0; j < slen; j++ ) {
			surf->name[j] = tolower( surf->name[j] );
		}

		// strip off a trailing _1 or _2
		// this is a crutch for q3data being a mess
		j = (int)strlen( surf->name );
		if ( j > 2 && surf->name[j-2] == '_' ) {
			surf->name[j-2] = 0;
		}

		// register the shaders
		shader = (md3Shader_t *) ( (byte *)surf + surf->ofsShaders );
		for ( j = 0; j < surf->numShaders; j++, shader++ ) {
			shader->shader = declManager->FindMaterial( shader->name );
		}

		// swap all the triangles
		tri = (md3Triangle_t *) ( (byte *)surf + surf->ofsTriangles );
		for ( j = 0; j < surf->numTriangles; j++, tri++ ) {
			LL(tri->indexes[0]);
			LL(tri->indexes[1]);
			LL(tri->indexes[2]);
		}

		// swap all the ST
		st = (md3St_t *) ( (byte *)surf + surf->ofsSt );
		for ( j = 0; j < surf->numVerts; j++, st++ ) {
			st->st[0] = LittleFloat( st->st[0] );
			st->st[1] = LittleFloat( st->st[1] );
		}

		// swap all the XyzNormals
		xyz = (md3XyzNormal_t *) ( (byte *)surf + surf->ofsXyzNormals );
		for ( j = 0; j < surf->numVerts * surf->numFrames; j++, xyz++ ) {
			xyz->xyz[0] = LittleShort( xyz->xyz[0] );
			xyz->xyz[1] = LittleShort( xyz->xyz[1] );
			xyz->xyz[2] = LittleShort( xyz->xyz[2] );
			xyz->normal = LittleShort( xyz->normal );
		}

		// find the next surface
		surf = (md3Surface_t *)( (byte *)surf + surf->ofsEnd );
	}

	*headerOut = header;
	return true;
}

/*
=================
idRenderModelMD3::idRenderModelMD3
=================
*/
idRenderModelMD3::idRenderModelMD3() {
	index = 0;
	dataSize = 0;
	md3 = NULL;
	numLods = 0;
	for ( int i = 0; i < MD3_MAX_LODS; i++ ) {
		lods[i] = NULL;
	}
}

/*
=================
idRenderModelMD3::~idRenderModelMD3
=================
*/
idRenderModelMD3::~idRenderModelMD3() {
	// the base destructor calls PurgeModel again, which is a no-op then
	PurgeModel();
}

/*
=================
idRenderModelMD3::LoadHeader
=================
*/
bool idRenderModelMD3::LoadHeader( const char *fileName, md3Header_t **headerOut, ID_TIME_T *timestamp ) {
	return MD3_LoadHeader( fileName, headerOut, timestamp );
}

/*
=================
idRenderModelMD3::LodFileExtension
=================
*/
const char *idRenderModelMD3::LodFileExtension() const {
	return "md3";
}

/*
=================
idRenderModelMD3::InitFromFile
=================
*/
void idRenderModelMD3::InitFromFile( const char *fileName ) {
	name = fileName;
	LoadModel();
}

/*
=================
idRenderModelMD3::LoadModel

Used for initial loads, reloadModel, and reloading the data of purged
models. Upon exit the model will be valid, possibly as a default model.
=================
*/
void idRenderModelMD3::LoadModel() {
	if ( !purged ) {
		PurgeModel();
	}
	purged = false;

	if ( !LoadHeader( name.c_str(), &lods[0], &timeStamp ) ) {
		MakeDefaultModel();
		return;
	}
	numLods = 1;

	// load the lower detail levels, the chain stops at the first missing file
	idStr baseName = name;
	baseName.StripFileExtension();
	for ( int i = 1; i < MD3_MAX_LODS; i++ ) {
		idStr lodName;
		lodName.Format( "%s_%i.%s", baseName.c_str(), i, LodFileExtension() );

		md3Header_t *lod = NULL;
		if ( !MD3_LoadHeader( lodName.c_str(), &lod, NULL ) ) {
			break;
		}
		lods[i] = lod;
		numLods++;
	}

	md3 = lods[0];

	dataSize = 0;
	for ( int i = 0; i < numLods; i++ ) {
		dataSize += lods[i]->ofsEnd;
	}

	// the MD3 tags are exposed as joints so attachments can find them
	joints.Clear();
	const md3Tag_t *tag = (const md3Tag_t *) ( (byte *)md3 + md3->ofsTags );
	for ( int i = 0; i < md3->numTags; i++, tag++ ) {
		idMD5Joint joint;
		joint.name = tag->name;
		joints.Append( joint );
	}

	// the reference bounds are the union of all frame bounds
	bounds.Clear();
	const md3Frame_t *frame = (const md3Frame_t *) ( (byte *)md3 + md3->ofsFrames );
	for ( int i = 0; i < md3->numFrames; i++, frame++ ) {
		bounds.AddPoint( frame->bounds[0] );
		bounds.AddPoint( frame->bounds[1] );
	}
}

/*
===================
idRenderModelMD3::PurgeModel

Frees all the data, but leaves the class around for dangling references,
which can regenerate the data with LoadModel().
===================
*/
void idRenderModelMD3::PurgeModel() {
	idRenderModelStatic::PurgeModel();

	joints.Clear();

	for ( int i = 0; i < MD3_MAX_LODS; i++ ) {
		if ( lods[i] != NULL ) {
			Mem_Free( lods[i] );
			lods[i] = NULL;
		}
	}
	md3 = NULL;
	numLods = 0;
	dataSize = 0;
}

/*
=================
idRenderModelMD3::TouchData

Models that are already loaded at level start time will still touch
their materials to make sure they are kept loaded.
=================
*/
void idRenderModelMD3::TouchData() {
	for ( int i = 0; i < numLods; i++ ) {
		md3Surface_t *surf = (md3Surface_t *) ( (byte *)lods[i] + lods[i]->ofsSurfaces );
		for ( int j = 0; j < lods[i]->numSurfaces; j++ ) {
			md3Shader_t *shader = (md3Shader_t *) ( (byte *)surf + surf->ofsShaders );
			for ( int k = 0; k < surf->numShaders; k++, shader++ ) {
				if ( shader->shader != NULL ) {
					shader->shader = declManager->FindMaterial( shader->shader->GetName() );
				}
			}
			surf = (md3Surface_t *)( (byte *)surf + surf->ofsEnd );
		}
	}
}

/*
=================
idRenderModelMD3::IsDynamicModel
=================
*/
dynamicModel_t idRenderModelMD3::IsDynamicModel() const {
	return DM_CACHED;
}

/*
=================
idRenderModelMD3::GetFrameParms

Reads the frame, old frame and backlerp the entity wants to show.
=================
*/
void idRenderModelMD3::GetFrameParms( const struct renderEntity_s *ent, const struct md3Header_s *header, int &frame, int &oldframe, float &backlerp ) const {
	frame = 0;
	oldframe = 0;
	backlerp = 0.0f;

	if ( ent == NULL ) {
		return;
	}

	frame = idMath::Ftoi( ent->shaderParms[SHADERPARM_MD3_FRAME] );
	oldframe = idMath::Ftoi( ent->shaderParms[SHADERPARM_MD3_LASTFRAME] );
	backlerp = ent->shaderParms[SHADERPARM_MD3_BACKLERP];

	frame = idMath::ClampInt( 0, header->numFrames - 1, frame );
	oldframe = idMath::ClampInt( 0, header->numFrames - 1, oldframe );
	backlerp = idMath::ClampFloat( 0.0f, 1.0f, backlerp );
}

/*
=================
idRenderModelMD3::SelectLodForView

Picks a level of detail from the projected bounding sphere radius,
ported from the Quake III Arena R_ComputeLOD.
=================
*/
int idRenderModelMD3::SelectLodForView( const struct renderEntity_s *ent, const viewDef_t *view, int frame ) const {
	if ( numLods < 2 || view == NULL || ent == NULL ) {
		return 0;
	}

	const md3Frame_t *fr = (const md3Frame_t *) ( (byte *)md3 + md3->ofsFrames ) + frame;
	float radius = MD3_RadiusFromBounds( fr->bounds );

	int lod = 0;

	float projectedRadius = MD3_ProjectRadius( radius, ent->origin, view );
	if ( projectedRadius != 0.0f ) {
		float lodscale = r_md3LodScale.GetFloat();
		if ( lodscale > 20.0f ) {
			lodscale = 20.0f;
		}
		float flod = 1.0f - projectedRadius * lodscale;
		flod *= numLods;
		lod = idMath::Ftoi( flod );

		if ( lod < 0 ) {
			lod = 0;
		} else if ( lod >= numLods ) {
			lod = numLods - 1;
		}
	}

	lod += r_md3LodBias.GetInteger();

	if ( lod < 0 ) {
		lod = 0;
	} else if ( lod >= numLods ) {
		lod = numLods - 1;
	}

	return lod;
}

/*
=================
idRenderModelMD3::LerpMeshVertexes

Interpolates the vertex positions and decodes the packed normals of
the two frames.
=================
*/
void idRenderModelMD3::LerpMeshVertexes( srfTriangles_t *tri, const struct md3Surface_s *surf, const float backlerp, const int frame, const int oldframe ) const {
	const md3XyzNormal_t *xyz = (const md3XyzNormal_t *) ( (byte *)surf + surf->ofsXyzNormals );

	const int numVerts = surf->numVerts;
	const int curFrame = idMath::ClampInt( 0, surf->numFrames - 1, frame );
	const int curOldFrame = idMath::ClampInt( 0, surf->numFrames - 1, oldframe );

	const md3XyzNormal_t *newXyz = xyz + curFrame * numVerts;
	const md3XyzNormal_t *oldXyz = xyz + curOldFrame * numVerts;

	if ( backlerp == 0.0f ) {
		//
		// just copy the vertexes
		//
		idVec3 normal;
		for ( int vertNum = 0; vertNum < numVerts; vertNum++, newXyz++ ) {
			idDrawVert *outvert = &tri->verts[tri->numVerts];

			outvert->xyz.x = newXyz->xyz[0] * MD3_XYZ_SCALE;
			outvert->xyz.y = newXyz->xyz[1] * MD3_XYZ_SCALE;
			outvert->xyz.z = newXyz->xyz[2] * MD3_XYZ_SCALE;

			MD3_DecodeNormal( newXyz->normal, normal );
			outvert->SetNormal( normal );

			tri->numVerts++;
		}
	} else {
		//
		// interpolate and copy the vertexes
		//
		const float oldXyzScale = MD3_XYZ_SCALE * backlerp;
		const float newXyzScale = MD3_XYZ_SCALE * ( 1.0f - backlerp );

		idVec3 oldNormal;
		idVec3 newNormal;
		idVec3 normal;
		for ( int vertNum = 0; vertNum < numVerts; vertNum++, oldXyz++, newXyz++ ) {
			idDrawVert *outvert = &tri->verts[tri->numVerts];

			// interpolate the xyz
			outvert->xyz.x = oldXyz->xyz[0] * oldXyzScale + newXyz->xyz[0] * newXyzScale;
			outvert->xyz.y = oldXyz->xyz[1] * oldXyzScale + newXyz->xyz[1] * newXyzScale;
			outvert->xyz.z = oldXyz->xyz[2] * oldXyzScale + newXyz->xyz[2] * newXyzScale;

			// interpolate the normals
			MD3_DecodeNormal( oldXyz->normal, oldNormal );
			MD3_DecodeNormal( newXyz->normal, newNormal );
			normal = oldNormal * backlerp + newNormal * ( 1.0f - backlerp );
			normal.Normalize();
			outvert->SetNormal( normal );

			tri->numVerts++;
		}
	}
}

/*
=================
idRenderModelMD3::InstantiateDynamicModel
=================
*/
idRenderModel *idRenderModelMD3::InstantiateDynamicModel( const struct renderEntity_s *ent, const viewDef_t *view, idRenderModel *cachedModel ) {
	if ( cachedModel != NULL && !r_useCachedDynamicModels.GetBool() ) {
		delete cachedModel;
		cachedModel = NULL;
	}

	if ( purged ) {
		common->DWarning( "model %s instantiated while purged", Name() );
		LoadModel();
	}

	if ( md3 == NULL ) {
		delete cachedModel;
		return NULL;
	}

	tr.pc.c_generateMd5++;

	int frame = 0;
	int oldframe = 0;
	float backlerp = 0.0f;
	GetFrameParms( ent, md3, frame, oldframe, backlerp );

	const int lod = SelectLodForView( ent, view, frame );
	const md3Header_t *header = lods[lod];

	idRenderModelStatic * staticModel;
	if ( cachedModel != NULL ) {
		assert( dynamic_cast<idRenderModelStatic *>( cachedModel ) != NULL );
		assert( idStr::Icmp( cachedModel->Name(), MD3_SnapshotName ) == 0 );
		staticModel = static_cast<idRenderModelStatic *>( cachedModel );
	} else {
		staticModel = new (TAG_MODEL) idRenderModelStatic;
		staticModel->InitEmpty( MD3_SnapshotName );
	}

	staticModel->bounds.Clear();

	const md3Surface_t *surface = (const md3Surface_t *) ( (byte *)header + header->ofsSurfaces );
	for ( int i = 0; i < header->numSurfaces; i++ ) {

		// avoid deforming the surface if it will be a nodraw due to a skin remapping
		const idMaterial *shader = NULL;
		const md3Shader_t *shaders = (const md3Shader_t *) ( (byte *)surface + surface->ofsShaders );
		if ( surface->numShaders > 0 ) {
			shader = shaders->shader;
		}
		if ( shader == NULL ) {
			shader = declManager->FindMaterial( "_default" );
		}
		if ( ent != NULL ) {
			// pass the surface name so Q3 skins remap by surface, D3 skins by material
			shader = R_RemapShaderBySkin( shader, ent->customSkin, ent->customShader, surface->name );
		}
		if ( !shader || ( !shader->IsDrawn() && !shader->SurfaceCastsShadow() ) ) {
			staticModel->DeleteSurfaceWithId( i );
			surface = (const md3Surface_t *)( (byte *)surface + surface->ofsEnd );
			continue;
		}

		modelSurface_t *surf;
		int surfaceNum = 0;
		if ( staticModel->FindSurfaceWithId( i, surfaceNum ) ) {
			surf = &staticModel->surfaces[surfaceNum];
		} else {
			surf = &staticModel->surfaces.Alloc();
			surf->geometry = NULL;
			surf->shader = NULL;
			surf->id = i;
		}

		// reuse the buffers of the cached surface when they are big enough
		srfTriangles_t *tri = surf->geometry;
		if ( tri != NULL && tri->numVerts >= surface->numVerts && tri->numIndexes >= surface->numTriangles * 3 ) {
			// the vertex cache is no longer valid
			R_FreeStaticTriSurfVertexCaches( tri );
		} else {
			if ( tri != NULL ) {
				R_FreeStaticTriSurf( tri );
			}
			tri = R_AllocStaticTriSurf();
			R_AllocStaticTriSurfVerts( tri, surface->numVerts );
			R_AllocStaticTriSurfIndexes( tri, surface->numTriangles * 3 );
			surf->geometry = tri;
		}

		tri->numVerts = 0;
		tri->numIndexes = 0;
		tri->bounds.Clear();

		surf->shader = shader;

		LerpMeshVertexes( tri, surface, backlerp, frame, oldframe );

		const md3Triangle_t *triangles = (const md3Triangle_t *) ( (byte *)surface + surface->ofsTriangles );
		const int numTriangles = surface->numTriangles;
		for ( int j = 0; j < numTriangles; j++, triangles++ ) {
			tri->indexes[tri->numIndexes + 0] = (triIndex_t)triangles->indexes[0];
			tri->indexes[tri->numIndexes + 1] = (triIndex_t)triangles->indexes[1];
			tri->indexes[tri->numIndexes + 2] = (triIndex_t)triangles->indexes[2];
			tri->numIndexes += 3;
		}

		const md3St_t *st = (const md3St_t *) ( (byte *)surface + surface->ofsSt );
		for ( int j = 0; j < surface->numVerts; j++ ) {
			tri->verts[j].SetTexCoord( st[j].st[0], st[j].st[1] );
			for ( int k = 0; k < 4; k++ ) {
				tri->verts[j].color[k] = 255;
				tri->verts[j].color2[k] = 255;
			}
		}

		// build the tangents for interaction lighting, keeping the MD3 normals
		R_DeriveTangentsWithoutNormals( tri );

		R_BoundTriSurf( tri );

		staticModel->bounds.AddBounds( tri->bounds );

		// find the next surface
		surface = (const md3Surface_t *)( (byte *)surface + surface->ofsEnd );
	}

	// remove surfaces left over from a previous frame with a higher detail level
	for ( int i = staticModel->NumSurfaces() - 1; i >= 0; i-- ) {
		if ( staticModel->surfaces[i].id >= header->numSurfaces ) {
			staticModel->DeleteSurfaceWithId( staticModel->surfaces[i].id );
		}
	}

	return staticModel;
}

/*
=====================
idRenderModelMD3::Bounds
=====================
*/
idBounds idRenderModelMD3::Bounds( const struct renderEntity_s *ent ) const {
	if ( ent == NULL || md3 == NULL ) {
		return bounds;
	}

	int frame = 0;
	int oldframe = 0;
	float backlerp = 0.0f;
	GetFrameParms( ent, md3, frame, oldframe, backlerp );

	idBounds ret;
	ret.Clear();

	const md3Frame_t *frames = (const md3Frame_t *) ( (byte *)md3 + md3->ofsFrames );

	ret.AddPoint( frames[frame].bounds[0] );
	ret.AddPoint( frames[frame].bounds[1] );

	if ( oldframe != frame ) {
		ret.AddPoint( frames[oldframe].bounds[0] );
		ret.AddPoint( frames[oldframe].bounds[1] );
	}

	return ret;
}

/*
====================
idRenderModelMD3::NumJoints
====================
*/
int idRenderModelMD3::NumJoints() const {
	return joints.Num();
}

/*
====================
idRenderModelMD3::GetJoints
====================
*/
const idMD5Joint *idRenderModelMD3::GetJoints() const {
	return joints.Ptr();
}

/*
====================
idRenderModelMD3::GetJointHandle
====================
*/
jointHandle_t idRenderModelMD3::GetJointHandle( const char *name ) const {
	const idMD5Joint *joint = joints.Ptr();
	for ( int i = 0; i < joints.Num(); i++, joint++ ) {
		if ( idStr::Icmp( joint->name.c_str(), name ) == 0 ) {
			return ( jointHandle_t )i;
		}
	}

	return INVALID_JOINT;
}

/*
=====================
idRenderModelMD3::GetJointName
=====================
*/
const char *idRenderModelMD3::GetJointName( jointHandle_t handle ) const {
	if ( ( handle < 0 ) || ( handle >= joints.Num() ) ) {
		return "<invalid joint>";
	}

	return joints[ handle ].name;
}

/*
=====================
idRenderModelMD3::GetJointTransform

Returns the transform of the given tag for the given entity.
=====================
*/
bool idRenderModelMD3::GetJointTransform( jointHandle_t handle, const struct renderEntity_s *ent, idVec3 &origin, idMat3 &axis ) const {
	if ( md3 == NULL ) {
		return false;
	}

	if ( ( handle < 0 ) || ( handle >= md3->numTags ) ) {
		return false;
	}

	int frame = 0;
	int oldframe = 0;
	float backlerp = 0.0f;
	GetFrameParms( ent, md3, frame, oldframe, backlerp );

	const md3Tag_t *tags = (const md3Tag_t *) ( (byte *)md3 + md3->ofsTags );
	const md3Tag_t *newTag = tags + frame * md3->numTags + handle;
	const md3Tag_t *oldTag = tags + oldframe * md3->numTags + handle;

	for ( int i = 0; i < 3; i++ ) {
		origin[i] = oldTag->origin[i] * backlerp + newTag->origin[i] * ( 1.0f - backlerp );
		axis[0][i] = oldTag->axis[0][i] * backlerp + newTag->axis[0][i] * ( 1.0f - backlerp );
		axis[1][i] = oldTag->axis[1][i] * backlerp + newTag->axis[1][i] * ( 1.0f - backlerp );
		axis[2][i] = oldTag->axis[2][i] * backlerp + newTag->axis[2][i] * ( 1.0f - backlerp );
	}

	axis[0].Normalize();
	axis[1].Normalize();
	axis[2].Normalize();

	return true;
}

/*
==============
idRenderModelMD3::List
==============
*/
void idRenderModelMD3::List() const {
	int numTags = 0;
	int numSurfaces = 0;
	int numFrames = 0;
	if ( md3 != NULL ) {
		numTags = md3->numTags;
		numSurfaces = md3->numSurfaces;
		numFrames = md3->numFrames;
	}

	common->Printf( " %7i bytes %2i lods %3i frames %2i tags %3i surfaces %s", Memory(), numLods, numFrames, numTags, numSurfaces, Name() );

	if ( defaulted ) {
		common->Printf( " (DEFAULTED)" );
	}

	common->Printf( "\n" );
}

/*
===============
idRenderModelMD3::Memory
===============
*/
int	idRenderModelMD3::Memory() const {
	int total = sizeof( *this );
	total += joints.MemoryUsed();

	// count up strings
	for ( int i = 0; i < joints.Num(); i++ ) {
		total += joints[i].name.DynamicMemoryUsed();
	}

	// count up the raw model data
	for ( int i = 0; i < numLods; i++ ) {
		total += lods[i]->ofsEnd;
	}

	return total;
}
