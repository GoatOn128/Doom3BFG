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

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms.
You should have received a copy of these additional terms immediately following
the terms and conditions of the GNU General Public License which accompanied the
Doom 3 BFG Edition Source Code.  If not, please request a copy in writing from
id Software at the address below.

If you have questions concerning this license, the applicable additional terms,
or would like to contact id Software, please write:

id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================*/

// MDS/MDM/MDX/MD4 model support ported from the Wolfenstein: Enemy Territory
// GPL Source Code (Copyright (C) 1999-2010 id Software LLC, a ZeniMax Media
// company). The ET source is GPLv3 like this engine and is also vendored in
// this repository under references/etwolf. The runtime pipeline (weight
// folding, deformInfo, GPU skinning joints array) is modeled on the Doom 3
// MD5 loader (Model_md5.cpp).

#include "precompiled.h"
#pragma hdrstop

#include "tr_local.h"
#include "Model_local.h"
#include "Model_wolf.h"

static const char *Wolf_SnapshotName = "_Wolf_Snapshot_";

// up to this many influences are folded into the vertex color bytes
static const int MAX_VERTEX_WEIGHTS = 4;

/*
========================
WolfLoadFile

Reads a file into a TAG_MODEL block owned by the model. The caller is
responsible for freeing it with Mem_Free.
========================
*/
byte *WolfLoadFile( const char *fileName, int *fileSizeOut, ID_TIME_T *timestamp ) {
	void *buffer = NULL;
	int fileLen = fileSystem->ReadFile( fileName, &buffer, timestamp );
	if ( fileLen <= 0 ) {
		return NULL;
	}

	byte *data = (byte *)Mem_Alloc( fileLen, TAG_MODEL );
	memcpy( data, buffer, fileLen );
	fileSystem->FreeFile( buffer );

	*fileSizeOut = fileLen;
	return data;
}

/*
========================
WolfName

Copies a fixed size file name field into a zero terminated buffer.
========================
*/
const char *WolfName( const char *name, char *buffer ) {
	memcpy( buffer, name, WOLF_MAX_QPATH );
	buffer[WOLF_MAX_QPATH] = '\0';
	return buffer;
}

/*
========================
WolfTransformVertsAndTangents

Deforms the base pose verts with the skinned joint matrices. Scalar version
of the idMD5Mesh code in Model_md5.cpp.
========================
*/
static void WolfTransformVertsAndTangents( idDrawVert *targetVerts, const int numVerts, const idDrawVert *baseVerts, const idJointMat *joints ) {
	for ( int i = 0; i < numVerts; i++ ) {
		const idDrawVert &base = baseVerts[i];

		const idJointMat &j0 = joints[base.color[0]];
		const idJointMat &j1 = joints[base.color[1]];
		const idJointMat &j2 = joints[base.color[2]];
		const idJointMat &j3 = joints[base.color[3]];

		const float w0 = base.color2[0] * ( 1.0f / 255.0f );
		const float w1 = base.color2[1] * ( 1.0f / 255.0f );
		const float w2 = base.color2[2] * ( 1.0f / 255.0f );
		const float w3 = base.color2[3] * ( 1.0f / 255.0f );

		idJointMat accum;
		idJointMat::Mul( accum, j0, w0 );
		idJointMat::Mad( accum, j1, w1 );
		idJointMat::Mad( accum, j2, w2 );
		idJointMat::Mad( accum, j3, w3 );

		targetVerts[i].xyz = accum * idVec4( base.xyz.x, base.xyz.y, base.xyz.z, 1.0f );
		targetVerts[i].SetNormal( accum * base.GetNormal() );
		targetVerts[i].SetTangent( accum * base.GetTangent() );
		targetVerts[i].tangent[3] = base.tangent[3];
	}
}

/*
========================
WolfTransformJoints

Builds the GPU skinning matrices, current pose times inverse bind pose.
Scalar version of TransformJoints in Model_md5.cpp.
========================
*/
static void WolfTransformJoints( idJointMat *outJoints, const int numJoints, const idJointMat *inJoints, const idJointMat *inverseBindJoints ) {
	for ( int i = 0; i < numJoints; i++ ) {
		idJointMat::Multiply( outJoints[i], inJoints[i], inverseBindJoints[i] );
	}
}

/***********************************************************************

	idWolfMesh

***********************************************************************/

idWolfMesh::idWolfMesh() {
	shader = NULL;
	deformInfo = NULL;
	surfaceNum = 0;
	numVerts = 0;
	numTris = 0;
	meshJoints = NULL;
	numMeshJoints = 0;
	maxJointVertDist = 0.0f;
}

idWolfMesh::~idWolfMesh() {
	if ( deformInfo != NULL ) {
		R_FreeDeformInfo( deformInfo );
		deformInfo = NULL;
	}
	if ( meshJoints != NULL ) {
		Mem_Free( meshJoints );
		meshJoints = NULL;
	}
}

/*
====================
idWolfMesh::UpdateSurface

Mirrors idMD5Mesh::UpdateSurface, the surface geometry is rebuilt from the
deformInfo and either transformed on the CPU or referenced for GPU skinning.
====================
*/
void idWolfMesh::UpdateSurface( const struct renderEntity_s *ent, const idJointMat *entJoints,
								const idJointMat *entJointsInverted, modelSurface_t *surf ) const {

	tr.pc.c_deformedSurfaces++;
	tr.pc.c_deformedVerts += deformInfo->numOutputVerts;
	tr.pc.c_deformedIndexes += deformInfo->numIndexes;

	surf->shader = shader;

	if ( surf->geometry != NULL ) {
		// if the number of verts and indexes are the same we can re-use the triangle surface
		if ( surf->geometry->numVerts == deformInfo->numOutputVerts && surf->geometry->numIndexes == deformInfo->numIndexes ) {
			R_FreeStaticTriSurfVertexCaches( surf->geometry );
		} else {
			R_FreeStaticTriSurf( surf->geometry );
			surf->geometry = R_AllocStaticTriSurf();
		}
	} else {
		surf->geometry = R_AllocStaticTriSurf();
	}

	srfTriangles_t *tri = surf->geometry;

	// note that some of the data is referenced, and should not be freed
	tri->referencedIndexes = true;
	tri->numIndexes = deformInfo->numIndexes;
	tri->indexes = deformInfo->indexes;
	tri->silIndexes = deformInfo->silIndexes;
	tri->numMirroredVerts = deformInfo->numMirroredVerts;
	tri->mirroredVerts = deformInfo->mirroredVerts;
	tri->numDupVerts = deformInfo->numDupVerts;
	tri->dupVerts = deformInfo->dupVerts;
	tri->numSilEdges = deformInfo->numSilEdges;
	tri->silEdges = deformInfo->silEdges;

	tri->indexCache = deformInfo->staticIndexCache;

	tri->numVerts = deformInfo->numOutputVerts;
	if ( r_useGPUSkinning.GetBool() ) {
		if ( tri->verts != NULL && tri->verts != deformInfo->verts ) {
			R_FreeStaticTriSurfVerts( tri );
		}
		tri->verts = deformInfo->verts;
		tri->ambientCache = deformInfo->staticAmbientCache;
		tri->shadowCache = deformInfo->staticShadowCache;
		tri->referencedVerts = true;
	} else {
		if ( tri->verts == NULL || tri->verts == deformInfo->verts ) {
			tri->verts = NULL;
			R_AllocStaticTriSurfVerts( tri, deformInfo->numOutputVerts );
			assert( tri->verts != NULL );	// quiet analyze warning
			memcpy( tri->verts, deformInfo->verts, deformInfo->numOutputVerts * sizeof( deformInfo->verts[0] ) );	// copy over the texture coordinates
		}
		WolfTransformVertsAndTangents( tri->verts, deformInfo->numOutputVerts, deformInfo->verts, entJointsInverted );
		tri->referencedVerts = false;
	}
	tri->tangentsCalculated = true;

	CalculateBounds( entJoints, tri->bounds );
}

/*
====================
idWolfMesh::CalculateBounds

Rough bounds from the joint radii, mirroring idMD5Mesh::CalculateBounds.
====================
*/
void idWolfMesh::CalculateBounds( const idJointMat *entJoints, idBounds &bounds ) const {
	bounds.Clear();
	for ( int i = 0; i < numMeshJoints; i++ ) {
		const idJointMat &joint = entJoints[meshJoints[i]];
		bounds.AddPoint( joint.GetTranslation() );
	}
	bounds.ExpandSelf( maxJointVertDist );
}

/*
====================
idWolfMesh::NearestJoint
====================
*/
int idWolfMesh::NearestJoint( int a, int b, int c ) const {
	// duplicated vertices might not have weights
	int vertNum;
	if ( a >= 0 && a < numVerts ) {
		vertNum = a;
	} else if ( b >= 0 && b < numVerts ) {
		vertNum = b;
	} else if ( c >= 0 && c < numVerts ) {
		vertNum = c;
	} else {
		vertNum = 0;
	}
	return deformInfo->verts[vertNum].color[0];
}

/***********************************************************************

	idRenderModelWolfSkeletal

***********************************************************************/

idRenderModelWolfSkeletal::idRenderModelWolfSkeletal() {
	numBones = 0;
	numFrames = 0;
	fileData = NULL;
	skeletonData = NULL;
}

idRenderModelWolfSkeletal::~idRenderModelWolfSkeletal() {
	PurgeModel();
}

void idRenderModelWolfSkeletal::InitFromFile( const char *fileName ) {
	name = fileName;
	LoadModel();
}

dynamicModel_t idRenderModelWolfSkeletal::IsDynamicModel() const {
	return DM_CACHED;
}

/*
===================
idRenderModelWolfSkeletal::LoadModel
===================
*/
void idRenderModelWolfSkeletal::LoadModel() {
	if ( !purged ) {
		PurgeModel();
	}
	purged = false;

	if ( !LoadWolfFile( name.c_str() ) ) {
		MakeDefaultModel();
		return;
	}

	FinishSkeleton();
}

/*
===================
idRenderModelWolfSkeletal::PurgeModel
===================
*/
void idRenderModelWolfSkeletal::PurgeModel() {
	purged = true;

	joints.Clear();
	defaultPose.Clear();
	invertedDefaultPose.Clear();
	meshes.Clear();
	frameBounds.Clear();
	tags.Clear();

	bounds.Clear();
	numBones = 0;
	numFrames = 0;

	if ( fileData != NULL ) {
		Mem_Free( fileData );
		fileData = NULL;
	}
	if ( skeletonData != NULL ) {
		Mem_Free( skeletonData );
		skeletonData = NULL;
	}
}

/*
===================
idRenderModelWolfSkeletal::TouchData
===================
*/
void idRenderModelWolfSkeletal::TouchData() {
	for ( int i = 0; i < meshes.Num(); i++ ) {
		declManager->FindMaterial( meshes[i].shader->GetName() );
	}
}

/*
====================
idRenderModelWolfSkeletal::GetFrameParms

Reads the frame, old frame and backlerp the entity wants to show, the same
shader parms the MD3 loader uses.
====================
*/
void idRenderModelWolfSkeletal::GetFrameParms( const struct renderEntity_s *ent, int &frame, int &oldframe, float &backlerp ) const {
	frame = 0;
	oldframe = 0;
	backlerp = 0.0f;

	if ( ent == NULL ) {
		return;
	}

	frame = idMath::Ftoi( ent->shaderParms[SHADERPARM_MD3_FRAME] );
	oldframe = idMath::Ftoi( ent->shaderParms[SHADERPARM_MD3_LASTFRAME] );
	backlerp = ent->shaderParms[SHADERPARM_MD3_BACKLERP];

	frame = idMath::ClampInt( 0, numFrames - 1, frame );
	oldframe = idMath::ClampInt( 0, numFrames - 1, oldframe );
	backlerp = idMath::ClampFloat( 0.0f, 1.0f, backlerp );
}

/*
====================
idRenderModelWolfSkeletal::DecodePose

Decodes two frames and blends them into absolute joint matrices.
====================
*/
void idRenderModelWolfSkeletal::DecodePose( int frame, int oldframe, float backlerp, idJointMat *outJoints ) const {
	idJointQuat *quatA = ( idJointQuat * )_alloca16( numBones * sizeof( idJointQuat ) );
	idJointQuat *quatB = ( idJointQuat * )_alloca16( numBones * sizeof( idJointQuat ) );

	DecodeFrame( oldframe, quatA );
	DecodeFrame( frame, quatB );

	const float f = 1.0f - backlerp;
	for ( int i = 0; i < numBones; i++ ) {
		const idQuat q = Slerp( quatA[i].q, quatB[i].q, f );
		const idVec3 t = quatA[i].t + f * ( quatB[i].t - quatA[i].t );
		outJoints[i].SetRotation( q.ToMat3() );
		outJoints[i].SetTranslation( t );
	}
}

/*
====================
idRenderModelWolfSkeletal::PoseJoints

Returns the posed bones of the entity. Game supplied joints are used when
the renderEntity carries a matching skeleton, otherwise the pose is decoded
from the file frames.
====================
*/
const idJointMat *idRenderModelWolfSkeletal::PoseJoints( const struct renderEntity_s *ent, int &frame, int &oldframe, float &backlerp, idJointMat *posedJoints ) const {
	if ( ent != NULL && ent->joints != NULL && ent->numJoints == numBones ) {
		return ent->joints;
	}

	DecodePose( frame, oldframe, backlerp, posedJoints );
	return posedJoints;
}

/*
====================
idRenderModelWolfSkeletal::FinishSkeleton

Builds the parent relative default pose for game animators and the inverse
bind pose used for skinning, both from frame 0.
====================
*/
void idRenderModelWolfSkeletal::FinishSkeleton() {
	idJointQuat *bindQuats = ( idJointQuat * )_alloca16( numBones * sizeof( idJointQuat ) );
	idJointMat *bindPose = ( idJointMat * )_alloca16( numBones * sizeof( idJointMat ) );

	DecodeFrame( 0, bindQuats );
	for ( int i = 0; i < numBones; i++ ) {
		bindPose[i].SetRotation( bindQuats[i].q.ToMat3() );
		bindPose[i].SetTranslation( bindQuats[i].t );
	}

	// parent relative default pose, the game animator composes these
	defaultPose.SetGranularity( 1 );
	defaultPose.SetNum( numBones );
	for ( int i = 0; i < numBones; i++ ) {
		idJointQuat *pose = &defaultPose[i];
		*pose = bindQuats[i];
		if ( joints[i].parent != NULL ) {
			const int parentNum = joints[i].parent - joints.Ptr();
			pose->q = ( bindPose[i].ToMat3() * bindPose[parentNum].ToMat3().Transpose() ).ToQuat();
			pose->t = ( bindPose[i].ToVec3() - bindPose[parentNum].ToVec3() ) * bindPose[parentNum].ToMat3().Transpose();
		}
	}

	// the inverse bind pose supports deforming the base pose verts on the GPU
	invertedDefaultPose.SetGranularity( 1 );
	invertedDefaultPose.SetNum( SIMD_ROUND_JOINTS( numBones ) );
	for ( int i = 0; i < numBones; i++ ) {
		invertedDefaultPose[i] = bindPose[i];
		invertedDefaultPose[i].Invert();
	}
	SIMD_INIT_LAST_JOINT( invertedDefaultPose.Ptr(), numBones );

	// the reference bounds are the union of all frame bounds
	bounds.Clear();
	for ( int i = 0; i < frameBounds.Num(); i++ ) {
		bounds.AddBounds( frameBounds[i] );
	}

	common->UpdateLevelLoadPacifier();
}

/*
====================
idRenderModelWolfSkeletal::BuildMeshFromSurface

Walks the variable sized vertices of a surface, validates the data and
builds the skinning mesh with the MD5 weight folding.
====================
*/
bool idRenderModelWolfSkeletal::BuildMeshFromSurface( idWolfMesh &mesh, const char *shaderName,
		int numVerts, int ofsVerts, int vertexHeaderSize,
		int numTriangles, int ofsTriangles,
		int surfaceEnd, const idJointMat *bindPose ) {

	if ( numVerts < 1 || numVerts > MDS_MAX_VERTS ) {
		common->Warning( "Wolf model %s has an invalid number of verts on a surface (%i)", Name(), numVerts );
		return false;
	}
	if ( numTriangles < 1 || numTriangles > MDS_MAX_TRIANGLES ) {
		common->Warning( "Wolf model %s has an invalid number of triangles on a surface (%i)", Name(), numTriangles );
		return false;
	}
	if ( ofsTriangles + numTriangles * 3 * sizeof( int ) > surfaceEnd ) {
		common->Warning( "Wolf model %s has a truncated triangle list", Name() );
		return false;
	}

	// flatten the variable sized vertices and their weights
	idList<idVec2, TAG_MODEL> texCoords;
	idList<int, TAG_MODEL> firstWeight;
	idList<int, TAG_MODEL> numWeights;
	idList<wolfWeight_t, TAG_MODEL> weights;

	texCoords.SetGranularity( 1 );
	firstWeight.SetGranularity( 1 );
	numWeights.SetGranularity( 1 );
	weights.SetGranularity( 1 );

	texCoords.SetNum( numVerts );
	firstWeight.SetNum( numVerts );
	numWeights.SetNum( numVerts );

	int offset = ofsVerts;
	for ( int i = 0; i < numVerts; i++ ) {
		if ( offset + vertexHeaderSize > surfaceEnd ) {
			common->Warning( "Wolf model %s has a truncated vertex list", Name() );
			return false;
		}

		const byte *vert = fileData + offset;
		const int vertNumWeights = LittleInt( *( const int * )( vert + WOLF_VERTEX_NUMWEIGHTS_OFFSET ) );
		if ( vertNumWeights < 1 || vertNumWeights > 256 ) {
			common->Warning( "Wolf model %s has a vertex with an invalid number of weights (%i)", Name(), vertNumWeights );
			return false;
		}
		if ( offset + vertexHeaderSize + vertNumWeights * WOLF_WEIGHT_SIZE > surfaceEnd ) {
			common->Warning( "Wolf model %s has a truncated weight list", Name() );
			return false;
		}

		texCoords[i] = idVec2( LittleFloat( *( const float * )( vert + WOLF_VERTEX_TEXCOORD_OFFSET ) ),
								LittleFloat( *( const float * )( vert + WOLF_VERTEX_TEXCOORD_OFFSET + sizeof( float ) ) ) );

		firstWeight[i] = weights.Num();
		numWeights[i] = vertNumWeights;

		const byte *weightData = vert + vertexHeaderSize;
		for ( int k = 0; k < vertNumWeights; k++, weightData += WOLF_WEIGHT_SIZE ) {
			wolfWeight_t weight;
			weight.boneIndex = LittleInt( *( const int * )( weightData + 0 ) );
			weight.boneWeight = LittleFloat( *( const float * )( weightData + 4 ) );
			weight.offset[0] = LittleFloat( *( const float * )( weightData + 8 ) );
			weight.offset[1] = LittleFloat( *( const float * )( weightData + 12 ) );
			weight.offset[2] = LittleFloat( *( const float * )( weightData + 16 ) );
			if ( weight.boneIndex < 0 || weight.boneIndex >= numBones ) {
				common->Warning( "Wolf model %s has a weight with an out of range bone index (%i)", Name(), weight.boneIndex );
				return false;
			}
			weights.Append( weight );
		}

		offset += vertexHeaderSize + vertNumWeights * WOLF_WEIGHT_SIZE;
	}

	// the shader
	const idMaterial *material = NULL;
	if ( shaderName != NULL && shaderName[0] != '\0' ) {
		char shaderBuffer[WOLF_MAX_QPATH + 1];
		material = declManager->FindMaterial( WolfName( shaderName, shaderBuffer ) );
	}
	if ( material == NULL ) {
		material = declManager->FindMaterial( "_default" );
	}

	// build a base pose that can be used for skinning
	idDrawVert *basePose = ( idDrawVert * )Mem_ClearedAlloc( numVerts * sizeof( *basePose ), TAG_MD5_BASE );
	for ( int i = 0; i < numVerts; i++ ) {
		idVec3 v = vec3_zero;
		const int first = firstWeight[i];
		for ( int k = 0; k < numWeights[i]; k++ ) {
			const wolfWeight_t &weight = weights[first + k];
			v += bindPose[weight.boneIndex] * idVec4( weight.offset[0], weight.offset[1], weight.offset[2], weight.boneWeight );
		}
		basePose[i].Clear();
		basePose[i].xyz = v;
		basePose[i].SetTexCoord( texCoords[i] );
	}

	// fold the weights into the verts, keeping the four largest influences
	{
		byte *used = ( byte * )Mem_ClearedAlloc( numBones * sizeof( byte ), TAG_MODEL );
		int numMeshJoints = 0;
		float maxJointVertDist = 0.0f;

		for ( int i = 0; i < numVerts; i++ ) {
			idDrawVert &dv = basePose[i];

			// sort the weights and take the four largest
			int sorted[MAX_VERTEX_WEIGHTS];
			const int vertNumWeights = numWeights[i];
			const int usedWeights = Min( MAX_VERTEX_WEIGHTS, vertNumWeights );
			assert( vertNumWeights <= 256 );

			// pick the largest weights by simple selection into a small array
			bool taken[256];
			memset( taken, 0, sizeof( taken ) );
			for ( int j = 0; j < usedWeights; j++ ) {
				int best = -1;
				float bestWeight = -1.0f;
				for ( int k = 0; k < vertNumWeights; k++ ) {
					if ( !taken[k] && weights[firstWeight[i] + k].boneWeight > bestWeight ) {
						bestWeight = weights[firstWeight[i] + k].boneWeight;
						best = k;
					}
				}
				assert( best >= 0 );
				taken[best] = true;
				sorted[j] = firstWeight[i] + best;
			}

			float usedWeight = 0;
			for ( int j = 0; j < usedWeights; j++ ) {
				usedWeight += weights[sorted[j]].boneWeight;
			}

			byte finalWeights[MAX_VERTEX_WEIGHTS] = { 0 };
			byte finalJointIndecies[MAX_VERTEX_WEIGHTS] = { 0 };
			if ( usedWeight > 0.0f ) {
				for ( int j = 0; j < usedWeights; j++ ) {
					const wolfWeight_t &weight = weights[sorted[j]];
					const float normalizedWeight = weight.boneWeight / usedWeight;
					finalWeights[j] = idMath::Ftob( normalizedWeight * 255.0f );
					finalJointIndecies[j] = ( byte )weight.boneIndex;
				}
			}

			// sort the weights and indices for hardware skinning
			for ( int k = 0; k < 3; ++k ) {
				for ( int l = k + 1; l < 4; ++l ) {
					if ( finalWeights[l] > finalWeights[k] ) {
						SwapValues( finalWeights[k], finalWeights[l] );
						SwapValues( finalJointIndecies[k], finalJointIndecies[l] );
					}
				}
			}

			// give any left over to the biggest weight
			finalWeights[0] += Max( 255 - finalWeights[0] - finalWeights[1] - finalWeights[2] - finalWeights[3], 0 );

			dv.color[0] = finalJointIndecies[0];
			dv.color[1] = finalJointIndecies[1];
			dv.color[2] = finalJointIndecies[2];
			dv.color[3] = finalJointIndecies[3];

			dv.color2[0] = finalWeights[0];
			dv.color2[1] = finalWeights[1];
			dv.color2[2] = finalWeights[2];
			dv.color2[3] = finalWeights[3];

			for ( int j = 0; j < usedWeights; j++ ) {
				if ( !used[finalJointIndecies[j]] ) {
					used[finalJointIndecies[j]] = 1;
					numMeshJoints++;
				}
				const idJointMat &joint = bindPose[finalJointIndecies[j]];
				const float dist = ( dv.xyz - joint.GetTranslation() ).Length();
				if ( dist > maxJointVertDist ) {
					maxJointVertDist = dist;
				}
			}
		}

		mesh.numMeshJoints = numMeshJoints;
		mesh.maxJointVertDist = maxJointVertDist;
		mesh.meshJoints = ( byte * )Mem_Alloc( numMeshJoints * sizeof( mesh.meshJoints[0] ), TAG_MODEL );
		int meshJointNum = 0;
		for ( int i = 0; i < numBones; i++ ) {
			if ( used[i] ) {
				mesh.meshJoints[meshJointNum++] = i;
			}
		}
		Mem_Free( used );
	}

	// the triangles, R_BuildDeformInfo takes plain indexes
	int *indexes = ( int * )Mem_Alloc( numTriangles * 3 * sizeof( int ), TAG_MODEL );
	const int *triangles = ( const int * )( fileData + ofsTriangles );
	for ( int j = 0; j < numTriangles * 3; j++ ) {
		const int index = LittleInt( triangles[j] );
		if ( index < 0 || index >= numVerts ) {
			common->Warning( "Wolf model %s has an out of range triangle index (%i)", Name(), index );
			Mem_Free( basePose );
			Mem_Free( indexes );
			return false;
		}
		indexes[j] = index;
	}

	mesh.shader = material;
	mesh.numVerts = numVerts;
	mesh.numTris = numTriangles;

	mesh.deformInfo = R_BuildDeformInfo( numVerts, basePose, numTriangles * 3, indexes, material->UseUnsmoothedTangents() );

	for ( int i = 0; i < mesh.deformInfo->numOutputVerts; i++ ) {
		for ( int j = 0; j < 4; j++ ) {
			if ( mesh.deformInfo->verts[i].color[j] >= numBones ) {
				common->Warning( "Wolf model %s has a bad joint index", Name() );
				Mem_Free( basePose );
				Mem_Free( indexes );
				return false;
			}
		}
	}

	Mem_Free( basePose );
	Mem_Free( indexes );

	return true;
}

/*
====================
idRenderModelWolfSkeletal::InstantiateDynamicModel
====================
*/
idRenderModel *idRenderModelWolfSkeletal::InstantiateDynamicModel( const struct renderEntity_s *ent, const viewDef_t *view, idRenderModel *cachedModel ) {
	if ( cachedModel != NULL && !r_useCachedDynamicModels.GetBool() ) {
		delete cachedModel;
		cachedModel = NULL;
	}

	if ( purged ) {
		common->DWarning( "model %s instantiated while purged", Name() );
		LoadModel();
	}

	if ( fileData == NULL || meshes.Num() == 0 ) {
		delete cachedModel;
		return NULL;
	}

	tr.pc.c_generateMd5++;

	int frame = 0;
	int oldframe = 0;
	float backlerp = 0.0f;
	GetFrameParms( ent, frame, oldframe, backlerp );

	// pose the skeleton
	idJointMat *posedJoints = ( idJointMat * )_alloca16( SIMD_ROUND_JOINTS( numBones ) * sizeof( idJointMat ) );
	const idJointMat *entJoints = PoseJoints( ent, frame, oldframe, backlerp, posedJoints );

	idRenderModelStatic *staticModel;
	if ( cachedModel != NULL ) {
		assert( dynamic_cast<idRenderModelStatic *>( cachedModel ) != NULL );
		assert( idStr::Icmp( cachedModel->Name(), Wolf_SnapshotName ) == 0 );
		staticModel = static_cast<idRenderModelStatic *>( cachedModel );
	} else {
		staticModel = new ( TAG_MODEL ) idRenderModelStatic;
		staticModel->InitEmpty( Wolf_SnapshotName );
	}

	staticModel->bounds.Clear();

	// update the GPU joints array
	const int numInvertedJoints = SIMD_ROUND_JOINTS( numBones );
	if ( staticModel->jointsInverted == NULL ) {
		staticModel->numInvertedJoints = numInvertedJoints;
		const int alignment = glConfig.uniformBufferOffsetAlignment;
		staticModel->jointsInverted = ( idJointMat * )Mem_ClearedAlloc( ALIGN( numInvertedJoints * sizeof( idJointMat ), alignment ), TAG_JOINTMAT );
		staticModel->jointsInvertedBuffer = 0;
	} else {
		assert( staticModel->numInvertedJoints == numInvertedJoints );
	}

	WolfTransformJoints( staticModel->jointsInverted, numBones, entJoints, invertedDefaultPose.Ptr() );

	// create all the surfaces
	idWolfMesh *mesh = meshes.Ptr();
	for ( int i = 0; i < meshes.Num(); i++, mesh++ ) {
		// avoid deforming the surface if it will be a nodraw due to a skin remapping
		const idMaterial *shader = mesh->shader;
		if ( ent != NULL ) {
			shader = R_RemapShaderBySkin( shader, ent->customSkin, ent->customShader );
		}
		if ( !shader || ( !shader->IsDrawn() && !shader->SurfaceCastsShadow() ) ) {
			staticModel->DeleteSurfaceWithId( i );
			mesh->surfaceNum = -1;
			continue;
		}

		modelSurface_t *surf;
		int surfaceNum = 0;
		if ( staticModel->FindSurfaceWithId( i, surfaceNum ) ) {
			mesh->surfaceNum = surfaceNum;
			surf = &staticModel->surfaces[surfaceNum];
		} else {
			mesh->surfaceNum = staticModel->NumSurfaces();
			surf = &staticModel->surfaces.Alloc();
			surf->geometry = NULL;
			surf->shader = NULL;
			surf->id = i;
		}

		mesh->UpdateSurface( ent, entJoints, staticModel->jointsInverted, surf );

		// the deformation of the tangents can be deferred until each surface is added to the view
		surf->geometry->staticModelWithJoints = staticModel;

		staticModel->bounds.AddBounds( surf->geometry->bounds );
	}

	return staticModel;
}

/*
====================
idRenderModelWolfSkeletal::Bounds
====================
*/
idBounds idRenderModelWolfSkeletal::Bounds( const struct renderEntity_s *ent ) const {
	if ( ent == NULL || frameBounds.Num() == 0 ) {
		return bounds;
	}

	int frame = 0;
	int oldframe = 0;
	float backlerp = 0.0f;
	GetFrameParms( ent, frame, oldframe, backlerp );

	idBounds ret;
	ret.Clear();

	ret.AddPoint( frameBounds[frame][0] );
	ret.AddPoint( frameBounds[frame][1] );

	if ( oldframe != frame ) {
		ret.AddPoint( frameBounds[oldframe][0] );
		ret.AddPoint( frameBounds[oldframe][1] );
	}

	return ret;
}

int idRenderModelWolfSkeletal::NumJoints() const {
	return numBones;
}

const idMD5Joint *idRenderModelWolfSkeletal::GetJoints() const {
	return joints.Ptr();
}

const idJointQuat *idRenderModelWolfSkeletal::GetDefaultPose() const {
	return defaultPose.Ptr();
}

jointHandle_t idRenderModelWolfSkeletal::GetJointHandle( const char *name ) const {
	const idMD5Joint *joint = joints.Ptr();
	for ( int i = 0; i < joints.Num(); i++, joint++ ) {
		if ( idStr::Icmp( joint->name.c_str(), name ) == 0 ) {
			return ( jointHandle_t )i;
		}
	}

	return INVALID_JOINT;
}

const char *idRenderModelWolfSkeletal::GetJointName( jointHandle_t handle ) const {
	if ( ( handle < 0 ) || ( handle >= joints.Num() ) ) {
		return "<invalid joint>";
	}

	return joints[handle].name;
}

/*
=====================
idRenderModelWolfSkeletal::GetJointTransform

Returns the transform of the given bone or tag for the given entity.
=====================
*/
bool idRenderModelWolfSkeletal::GetJointTransform( jointHandle_t handle, const struct renderEntity_s *ent, idVec3 &origin, idMat3 &axis ) const {
	if ( fileData == NULL || ( handle < 0 ) || ( handle >= joints.Num() ) ) {
		return false;
	}

	int frame = 0;
	int oldframe = 0;
	float backlerp = 0.0f;
	GetFrameParms( ent, frame, oldframe, backlerp );

	idJointMat *posedJoints = ( idJointMat * )_alloca16( numBones * sizeof( idJointMat ) );
	const idJointMat *pose = PoseJoints( ent, frame, oldframe, backlerp, posedJoints );

	if ( handle < numBones ) {
		origin = pose[handle].ToVec3();
		axis = pose[handle].ToMat3();
		return true;
	}

	// the tags ride on their parent bone
	const wolfTag_t &tag = tags[handle - numBones];
	const idJointMat &bone = pose[tag.boneIndex];

	origin = bone * idVec4( tag.offset.x, tag.offset.y, tag.offset.z, 1.0f );

	const idMat3 boneRot = bone.ToMat3();
	for ( int j = 0; j < 3; j++ ) {
		axis[j] = boneRot * tag.axis[j];
	}

	return true;
}

/*
=====================
idRenderModelWolfSkeletal::NearestJoint
=====================
*/
int idRenderModelWolfSkeletal::NearestJoint( int surfaceNum, int a, int b, int c ) const {
	const idWolfMesh *mesh = meshes.Ptr();
	for ( int i = 0; i < meshes.Num(); i++, mesh++ ) {
		if ( mesh->surfaceNum == surfaceNum ) {
			return mesh->NearestJoint( a, b, c );
		}
	}
	return 0;
}

/*
==============
idRenderModelWolfSkeletal::Print
==============
*/
void idRenderModelWolfSkeletal::Print() const {
	common->Printf( "%s\n", name.c_str() );
	common->Printf( "Dynamic skeletal model.\n" );
	common->Printf( "    verts  tris material\n" );
	int totalVerts = 0;
	int totalTris = 0;
	const idWolfMesh *mesh = meshes.Ptr();
	for ( int i = 0; i < meshes.Num(); i++, mesh++ ) {
		totalVerts += mesh->NumVerts();
		totalTris += mesh->NumTris();
		common->Printf( "%2i: %5i %5i %s\n", i, mesh->NumVerts(), mesh->NumTris(), mesh->shader->GetName() );
	}
	common->Printf( "-----\n" );
	common->Printf( "%4i verts.\n", totalVerts );
	common->Printf( "%4i tris.\n", totalTris );
	common->Printf( "%4i bones.\n", numBones );
	common->Printf( "%4i tags.\n", tags.Num() );
	common->Printf( "%4i frames.\n", numFrames );
}

/*
==============
idRenderModelWolfSkeletal::List
==============
*/
void idRenderModelWolfSkeletal::List() const {
	int totalTris = 0;
	int totalVerts = 0;
	const idWolfMesh *mesh = meshes.Ptr();
	for ( int i = 0; i < meshes.Num(); i++, mesh++ ) {
		totalTris += mesh->NumTris();
		totalVerts += mesh->NumVerts();
	}
	common->Printf( " %4ik %3i %4i %4i %4i %s(Wolf)", Memory() / 1024, meshes.Num(), totalVerts, totalTris, numBones, Name() );

	if ( defaulted ) {
		common->Printf( " (DEFAULTED)" );
	}

	common->Printf( "\n" );
}

/*
===============
idRenderModelWolfSkeletal::Memory
===============
*/
int idRenderModelWolfSkeletal::Memory() const {
	int total = sizeof( *this );
	total += joints.MemoryUsed() + defaultPose.MemoryUsed() + invertedDefaultPose.MemoryUsed() + meshes.MemoryUsed();

	// count up strings
	for ( int i = 0; i < joints.Num(); i++ ) {
		total += joints[i].name.DynamicMemoryUsed();
	}

	// count up meshes
	for ( int i = 0; i < meshes.Num(); i++ ) {
		const idWolfMesh *mesh = &meshes[i];

		total += mesh->numMeshJoints * sizeof( mesh->meshJoints[0] );

		// sum up deform info
		total += sizeof( mesh->deformInfo );
		total += R_DeformInfoMemoryUsed( mesh->deformInfo );
	}

	return total;
}
