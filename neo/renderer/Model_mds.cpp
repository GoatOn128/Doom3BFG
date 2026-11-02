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

// MDS model support ported from the Wolfenstein: Enemy Territory GPL Source
// Code (Copyright (C) 1999-2010 id Software LLC, a ZeniMax Media company).
// The ET source is GPLv3 like this engine and is also vendored in this
// repository under references/etwolf. The runtime pipeline (weight
// folding, deformInfo, GPU skinning joints array) is modeled on the Doom 3
// MD5 loader (Model_md5.cpp) and lives in Model_wolf.cpp.

#include "precompiled.h"
#pragma hdrstop

#include "tr_local.h"
#include "Model_local.h"
#include "Model_mds.h"

/*
====================
idRenderModelMDS::DecodeFrame

Decodes the compressed bone frames. The angles are absolute eulers, the
translation of each bone is parentDist along the ofsAngles direction from
its parent, the root bone uses the frame parentOffset.
====================
*/
void idRenderModelMDS::DecodeFrame( int frameNum, idJointQuat *jointQuats ) const {
	const mdsHeader_t *mds = ( const mdsHeader_t * )fileData;

	const int frameSize = sizeof( wolfFrame_t ) + numBones * sizeof( wolfBoneFrameCompressed_t );
	const wolfFrame_t *frame = ( const wolfFrame_t * )( fileData + LittleInt( mds->ofsFrames ) + frameNum * frameSize );
	const wolfBoneFrameCompressed_t *bones = ( const wolfBoneFrameCompressed_t * )( ( const byte * )frame + sizeof( wolfFrame_t ) );
	const wolfBoneInfo_t *boneInfo = ( const wolfBoneInfo_t * )( fileData + LittleInt( mds->ofsBones ) );

	for ( int i = 0; i < numBones; i++ ) {
		const idAngles angles( SHORT2ANGLE( LittleShort( bones[i].angles[0] ) ),
								SHORT2ANGLE( LittleShort( bones[i].angles[1] ) ),
								SHORT2ANGLE( LittleShort( bones[i].angles[2] ) ) );
		jointQuats[i].q = angles.ToQuat();
		jointQuats[i].w = 0.0f;

		const int parent = LittleInt( boneInfo[i].parent );
		if ( parent >= 0 ) {
			// direction from the parent bone origin to this bone origin
			const float pitch = SHORT2ANGLE( LittleShort( bones[i].ofsAngles[0] ) );
			const float yaw = SHORT2ANGLE( LittleShort( bones[i].ofsAngles[1] ) );
			const idVec3 dir( idMath::Cos( pitch ) * idMath::Cos( yaw ),
								idMath::Cos( pitch ) * idMath::Sin( yaw ),
								-idMath::Sin( pitch ) );
			jointQuats[i].t = jointQuats[parent].t + LittleFloat( boneInfo[i].parentDist ) * dir;
		} else {
			jointQuats[i].t = idVec3( LittleFloat( frame->parentOffset[0] ),
										LittleFloat( frame->parentOffset[1] ),
										LittleFloat( frame->parentOffset[2] ) );
		}
	}
}

/*
====================
idRenderModelMDS::LoadWolfFile
====================
*/
bool idRenderModelMDS::LoadWolfFile( const char *fileName ) {
	int fileSize = 0;
	fileData = WolfLoadFile( fileName, &fileSize, &timeStamp );
	if ( fileData == NULL ) {
		common->Warning( "idRenderModelMDS: %s not found", fileName );
		return false;
	}

	const mdsHeader_t *mds = ( const mdsHeader_t * )fileData;

	if ( LittleInt( mds->ident ) != MDS_IDENT ) {
		common->Warning( "idRenderModelMDS: %s has the wrong ident", fileName );
		return false;
	}
	if ( LittleInt( mds->version ) != MDS_VERSION ) {
		common->Warning( "idRenderModelMDS: %s has wrong version (%i should be %i)", fileName, LittleInt( mds->version ), MDS_VERSION );
		return false;
	}
	if ( LittleInt( mds->ofsEnd ) > fileSize ) {
		common->Warning( "idRenderModelMDS: %s is truncated", fileName );
		return false;
	}

	numFrames = LittleInt( mds->numFrames );
	numBones = LittleInt( mds->numBones );
	const int numTags = LittleInt( mds->numTags );
	const int numSurfaces = LittleInt( mds->numSurfaces );

	if ( numFrames < 1 ) {
		common->Warning( "idRenderModelMDS: %s has no frames", fileName );
		return false;
	}
	if ( numBones < 1 || numBones > MDS_MAX_BONES ) {
		common->Warning( "idRenderModelMDS: %s has an invalid number of bones (%i)", fileName, numBones );
		return false;
	}
	if ( numSurfaces < 1 || numSurfaces > MDS_MAX_SURFACES ) {
		common->Warning( "idRenderModelMDS: %s has an invalid number of surfaces (%i)", fileName, numSurfaces );
		return false;
	}
	if ( numTags < 0 || numTags > MDS_MAX_TAGS ) {
		common->Warning( "idRenderModelMDS: %s has an invalid number of tags (%i)", fileName, numTags );
		return false;
	}

	const int frameSize = sizeof( wolfFrame_t ) + numBones * sizeof( wolfBoneFrameCompressed_t );
	if ( LittleInt( mds->ofsFrames ) + numFrames * frameSize > LittleInt( mds->ofsEnd ) ) {
		common->Warning( "idRenderModelMDS: %s has a truncated frame list", fileName );
		return false;
	}
	if ( LittleInt( mds->ofsBones ) + numBones * sizeof( wolfBoneInfo_t ) > LittleInt( mds->ofsEnd ) ) {
		common->Warning( "idRenderModelMDS: %s has a truncated bone list", fileName );
		return false;
	}

	const wolfBoneInfo_t *boneInfo = ( const wolfBoneInfo_t * )( fileData + LittleInt( mds->ofsBones ) );
	for ( int i = 0; i < numBones; i++ ) {
		const int parent = LittleInt( boneInfo[i].parent );
		if ( parent >= i ) {
			common->Warning( "idRenderModelMDS: %s has an out of order bone hierarchy", fileName );
			return false;
		}
	}

	// the bones and tags are exposed as joints, tags ride after the bones
	joints.SetGranularity( 1 );
	joints.SetNum( numBones + numTags );
	for ( int i = 0; i < numBones; i++ ) {
		char nameBuffer[WOLF_MAX_QPATH + 1];
		joints[i].name = WolfName( boneInfo[i].name, nameBuffer );
		joints[i].parent = ( LittleInt( boneInfo[i].parent ) >= 0 ) ? &joints[LittleInt( boneInfo[i].parent )] : NULL;
	}

	// per frame bounds
	frameBounds.SetGranularity( 1 );
	frameBounds.SetNum( numFrames );
	for ( int i = 0; i < numFrames; i++ ) {
		const wolfFrame_t *frame = ( const wolfFrame_t * )( fileData + LittleInt( mds->ofsFrames ) + i * frameSize );
		idBounds &frameBound = frameBounds[i];
		frameBound.Clear();
		frameBound.AddPoint( idVec3( LittleFloat( frame->bounds[0][0] ), LittleFloat( frame->bounds[0][1] ), LittleFloat( frame->bounds[0][2] ) ) );
		frameBound.AddPoint( idVec3( LittleFloat( frame->bounds[1][0] ), LittleFloat( frame->bounds[1][1] ), LittleFloat( frame->bounds[1][2] ) ) );
	}

	// decode the bind pose of frame 0
	idJointQuat *bindQuats = ( idJointQuat * )_alloca16( numBones * sizeof( idJointQuat ) );
	idJointMat *bindPose = ( idJointMat * )_alloca16( numBones * sizeof( idJointMat ) );
	DecodeFrame( 0, bindQuats );
	for ( int i = 0; i < numBones; i++ ) {
		bindPose[i].SetRotation( bindQuats[i].q.ToMat3() );
		bindPose[i].SetTranslation( bindQuats[i].t );
	}

	// the tags are attached to bones, no local transform is stored
	tags.SetGranularity( 1 );
	if ( numTags > 0 && LittleInt( mds->ofsTags ) + numTags * ( int )sizeof( mdsTag_t ) > LittleInt( mds->ofsEnd ) ) {
		common->Warning( "idRenderModelMDS: %s has a truncated tag list", fileName );
		return false;
	}
	const mdsTag_t *tag = ( const mdsTag_t * )( fileData + LittleInt( mds->ofsTags ) );
	for ( int i = 0; i < numTags; i++, tag++ ) {
		const int boneIndex = LittleInt( tag->boneIndex );
		if ( boneIndex < 0 || boneIndex >= numBones ) {
			common->Warning( "idRenderModelMDS: %s has a tag with an out of range bone index", fileName );
			return false;
		}
		char nameBuffer[WOLF_MAX_QPATH + 1];
		wolfTag_t wolfTag;
		wolfTag.name = WolfName( tag->name, nameBuffer );
		wolfTag.boneIndex = boneIndex;
		wolfTag.offset = vec3_zero;
		wolfTag.axis = mat3_identity;
		tags.Append( wolfTag );
		joints[numBones + i].name = WolfName( tag->name, nameBuffer );
		joints[numBones + i].parent = NULL;
	}

	// the surfaces
	meshes.SetGranularity( 1 );
	meshes.SetNum( numSurfaces );
	int surfaceOfs = LittleInt( mds->ofsSurfaces );
	for ( int i = 0; i < numSurfaces; i++ ) {
		const mdsSurface_t *surf = ( const mdsSurface_t * )( fileData + surfaceOfs );
		if ( surfaceOfs + ( int )sizeof( mdsSurface_t ) > LittleInt( mds->ofsEnd ) ) {
			common->Warning( "idRenderModelMDS: %s has a truncated surface", fileName );
			return false;
		}
		const int surfEnd = surfaceOfs + LittleInt( surf->ofsEnd );
		if ( surfEnd > LittleInt( mds->ofsEnd ) ) {
			common->Warning( "idRenderModelMDS: %s has a truncated surface", fileName );
			return false;
		}
		if ( !BuildMeshFromSurface( meshes[i], surf->shader,
				LittleInt( surf->numVerts ), surfaceOfs + LittleInt( surf->ofsVerts ), WOLF_MDS_VERTEX_HEADER_SIZE,
				LittleInt( surf->numTriangles ), surfaceOfs + LittleInt( surf->ofsTriangles ),
				surfEnd, bindPose ) ) {
			return false;
		}
		surfaceOfs = surfEnd;
	}

	return true;
}
