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
#include "Model_mds.h"
#include "Model_mdm.h"

/*
====================
idRenderModelMDM::DecodeFrame

The skeleton and frames come from the .mdx file.
====================
*/
void idRenderModelMDM::DecodeFrame( int frameNum, idJointQuat *jointQuats ) const {
	const mdxHeader_t *mdx = ( const mdxHeader_t * )skeletonData;

	const int frameSize = ( int )sizeof( modFrame_t ) + numBones * ( int )sizeof( modBoneFrameCompressed_t );
	const modFrame_t *frame = ( const modFrame_t * )( skeletonData + LittleInt( mdx->ofsFrames ) + frameNum * frameSize );
	const modBoneFrameCompressed_t *bones = ( const modBoneFrameCompressed_t * )( ( const byte * )frame + sizeof( modFrame_t ) );
	const modBoneInfo_t *boneInfo = ( const modBoneInfo_t * )( skeletonData + LittleInt( mdx->ofsBones ) );

	for ( int i = 0; i < numBones; i++ ) {
		const idAngles angles( SHORT2ANGLE( LittleShort( bones[i].angles[0] ) ),
								SHORT2ANGLE( LittleShort( bones[i].angles[1] ) ),
								SHORT2ANGLE( LittleShort( bones[i].angles[2] ) ) );
		jointQuats[i].q = angles.ToQuat();
		jointQuats[i].w = 0.0f;

		const int parent = LittleInt( boneInfo[i].parent );
		if ( parent >= 0 ) {
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
idRenderModelMDM::LoadMODFile

The mesh and tags come from the .mdm, the skeleton and frames from the .mdx file.
====================
*/
bool idRenderModelMDM::LoadMODFile( const char *fileName ) {
	int fileSize = 0;
	fileData = MOD_LoadFile( fileName, &fileSize, &timeStamp );
	if ( fileData == NULL ) {
		common->Warning( "idRenderModelMDM: %s not found", fileName );
		return false;
	}

	const mdmHeader_t *mdm = ( const mdmHeader_t * )fileData;

	if ( LittleInt( mdm->ident ) != MDM_IDENT ) {
		common->Warning( "idRenderModelMDM: %s has the wrong ident", fileName );
		return false;
	}
	if ( LittleInt( mdm->version ) != MDM_VERSION ) {
		common->Warning( "idRenderModelMDM: %s has wrong version (%i should be %i)", fileName, LittleInt( mdm->version ), MDM_VERSION );
		return false;
	}
	if ( LittleInt( mdm->ofsEnd ) > fileSize ) {
		common->Warning( "idRenderModelMDM: %s is truncated", fileName );
		return false;
	}

	const int numTags = LittleInt( mdm->numTags );
	const int numSurfaces = LittleInt( mdm->numSurfaces );
	if ( numSurfaces < 1 || numSurfaces > MDM_MAX_SURFACES ) {
		common->Warning( "idRenderModelMDM: %s has an invalid number of surfaces (%i)", fileName, numSurfaces );
		return false;
	}
	if ( numTags < 0 || numTags > MDM_MAX_TAGS ) {
		common->Warning( "idRenderModelMDM: %s has an invalid number of tags (%i)", fileName, numTags );
		return false;
	}

	// the skeleton comes from the sibling .mdx file
	idStr skeletonName = fileName;
	skeletonName.StripFileExtension();
	skeletonName += ".mdx";

	int skeletonSize = 0;
	skeletonData = MOD_LoadFile( skeletonName.c_str(), &skeletonSize, NULL );
	if ( skeletonData == NULL ) {
		common->Warning( "idRenderModelMDM: %s not found", skeletonName.c_str() );
		return false;
	}

	const mdxHeader_t *mdx = ( const mdxHeader_t * )skeletonData;
	if ( LittleInt( mdx->ident ) != MDX_IDENT ) {
		common->Warning( "idRenderModelMDM: %s has the wrong ident", skeletonName.c_str() );
		return false;
	}
	if ( LittleInt( mdx->version ) != MDX_VERSION ) {
		common->Warning( "idRenderModelMDM: %s has wrong version (%i should be %i)", skeletonName.c_str(), LittleInt( mdx->version ), MDX_VERSION );
		return false;
	}

	numFrames = LittleInt( mdx->numFrames );
	numBones = LittleInt( mdx->numBones );

	if ( numFrames < 1 ) {
		common->Warning( "idRenderModelMDM: %s has no frames", skeletonName.c_str() );
		return false;
	}
	if ( numBones < 1 || numBones > MDX_MAX_BONES ) {
		common->Warning( "idRenderModelMDM: %s has an invalid number of bones (%i)", skeletonName.c_str(), numBones );
		return false;
	}

	const int frameSize = ( int )sizeof( modFrame_t ) + numBones * ( int )sizeof( modBoneFrameCompressed_t );
	if ( LittleInt( mdx->ofsFrames ) + numFrames * frameSize > LittleInt( mdx->ofsEnd ) ) {
		common->Warning( "idRenderModelMDM: %s has a truncated frame list", skeletonName.c_str() );
		return false;
	}
	if ( LittleInt( mdx->ofsBones ) + numBones * ( int )sizeof( modBoneInfo_t ) > LittleInt( mdx->ofsEnd ) ) {
		common->Warning( "idRenderModelMDM: %s has a truncated bone list", skeletonName.c_str() );
		return false;
	}

	const modBoneInfo_t *boneInfo = ( const modBoneInfo_t * )( skeletonData + LittleInt( mdx->ofsBones ) );
	for ( int i = 0; i < numBones; i++ ) {
		const int parent = LittleInt( boneInfo[i].parent );
		if ( parent >= i ) {
			common->Warning( "idRenderModelMDM: %s has an out of order bone hierarchy", skeletonName.c_str() );
			return false;
		}
	}

	// the bones and tags are exposed as joints, tags ride after the bones
	joints.SetGranularity( 1 );
	joints.SetNum( numBones + numTags );
	for ( int i = 0; i < numBones; i++ ) {
		char nameBuffer[MOD_MAX_QPATH + 1];
		joints[i].name = MOD_Name( boneInfo[i].name, nameBuffer );
		joints[i].parent = ( LittleInt( boneInfo[i].parent ) >= 0 ) ? &joints[LittleInt( boneInfo[i].parent )] : NULL;
	}

	// per frame bounds
	frameBounds.SetGranularity( 1 );
	frameBounds.SetNum( numFrames );
	for ( int i = 0; i < numFrames; i++ ) {
		const modFrame_t *frame = ( const modFrame_t * )( skeletonData + LittleInt( mdx->ofsFrames ) + i * frameSize );
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

	// the tags have a local offset and axis relative to their bone
	tags.SetGranularity( 1 );
	int tagOfs = LittleInt( mdm->ofsTags );
	for ( int i = 0; i < numTags; i++ ) {
		const mdmTag_t *tag = ( const mdmTag_t * )( fileData + tagOfs );
		if ( tagOfs + ( int )sizeof( mdmTag_t ) > LittleInt( mdm->ofsEnd ) ) {
			common->Warning( "idRenderModelMDM: %s has a truncated tag", fileName );
			return false;
		}
		if ( tagOfs + LittleInt( tag->ofsEnd ) > LittleInt( mdm->ofsEnd ) ) {
			common->Warning( "idRenderModelMDM: %s has a truncated tag", fileName );
			return false;
		}
		const int boneIndex = LittleInt( tag->boneIndex );
		if ( boneIndex < 0 || boneIndex >= numBones ) {
			common->Warning( "idRenderModelMDM: %s has a tag with an out of range bone index", fileName );
			return false;
		}
		char nameBuffer[MOD_MAX_QPATH + 1];
		modTag_t wolfTag;
		wolfTag.name = MOD_Name( tag->name, nameBuffer );
		wolfTag.boneIndex = boneIndex;
		wolfTag.offset = idVec3( LittleFloat( tag->offset[0] ), LittleFloat( tag->offset[1] ), LittleFloat( tag->offset[2] ) );
		for ( int r = 0; r < 3; r++ ) {
			wolfTag.axis[r] = idVec3( LittleFloat( tag->axis[r][0] ), LittleFloat( tag->axis[r][1] ), LittleFloat( tag->axis[r][2] ) );
		}
		tags.Append( wolfTag );
		joints[numBones + i].name = MOD_Name( tag->name, nameBuffer );
		joints[numBones + i].parent = NULL;
		tagOfs += LittleInt( tag->ofsEnd );
	}

	// the surfaces, the mdmSurface_t layout matches mdsSurface_t
	meshes.SetGranularity( 1 );
	meshes.SetNum( numSurfaces );
	int surfaceOfs = LittleInt( mdm->ofsSurfaces );
	for ( int i = 0; i < numSurfaces; i++ ) {
		const mdsSurface_t *surf = ( const mdsSurface_t * )( fileData + surfaceOfs );
		if ( surfaceOfs + ( int )sizeof( mdsSurface_t ) > LittleInt( mdm->ofsEnd ) ) {
			common->Warning( "idRenderModelMDM: %s has a truncated surface", fileName );
			return false;
		}
		const int surfEnd = surfaceOfs + LittleInt( surf->ofsEnd );
		if ( surfEnd > LittleInt( mdm->ofsEnd ) ) {
			common->Warning( "idRenderModelMDM: %s has a truncated surface", fileName );
			return false;
		}
		if ( !BuildMeshFromSurface( meshes[i], surf->shader,
				LittleInt( surf->numVerts ), surfaceOfs + LittleInt( surf->ofsVerts ), MDM_VERTEX_HEADER_SIZE,
				LittleInt( surf->numTriangles ), surfaceOfs + LittleInt( surf->ofsTriangles ),
				surfEnd, bindPose ) ) {
			return false;
		}
		surfaceOfs = surfEnd;
	}

	return true;
}
