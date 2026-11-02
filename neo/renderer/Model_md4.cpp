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

// MD4 model support ported from the Wolfenstein: Enemy Territory GPL Source
// Code (Copyright (C) 1999-2010 id Software LLC, a ZeniMax Media company).
// The ET source is GPLv3 like this engine and is also vendored in this
// repository under references/etwolf.
//
// The MD4 format has no loader in the released ET sources, only the on-disk
// structures in qfiles.h. The decode below follows the Quake III 3x4 matrix
// convention used everywhere in the ET code base: each row holds a rotation
// basis vector with the translation in the last column. The runtime
// pipeline is modeled on the Doom 3 MD5 loader (Model_md5.cpp) and lives
// in Model_wolf.cpp.

#include "precompiled.h"
#pragma hdrstop

#include "tr_local.h"
#include "Model_local.h"
#include "Model_md4.h"

/*
====================
idRenderModelMD4::DecodeFrame

The MD4 frames store absolute 3x4 bone matrices directly.
====================
*/
void idRenderModelMD4::DecodeFrame( int frameNum, idJointQuat *jointQuats ) const {
	const md4Header_t *md4 = ( const md4Header_t * )fileData;

	const int frameSize = ( int )sizeof( md4Frame_t ) + numBones * ( int )sizeof( md4Bone_t );
	const md4Frame_t *frame = ( const md4Frame_t * )( fileData + LittleInt( md4->ofsFrames ) + frameNum * frameSize );
	const md4Bone_t *bones = ( const md4Bone_t * )( ( const byte * )frame + sizeof( md4Frame_t ) );

	for ( int i = 0; i < numBones; i++ ) {
		idMat3 rotation;
		idVec3 translation;
		for ( int r = 0; r < 3; r++ ) {
			rotation[r] = idVec3( LittleFloat( bones[i].matrix[r][0] ), LittleFloat( bones[i].matrix[r][1] ), LittleFloat( bones[i].matrix[r][2] ) );
			translation[r] = LittleFloat( bones[i].matrix[r][3] );
		}
		idJointMat joint;
		joint.SetRotation( rotation );
		joint.SetTranslation( translation );
		jointQuats[i] = joint.ToJointQuat();
	}
}

/*
====================
idRenderModelMD4::LoadWolfFile
====================
*/
bool idRenderModelMD4::LoadWolfFile( const char *fileName ) {
	int fileSize = 0;
	fileData = WolfLoadFile( fileName, &fileSize, &timeStamp );
	if ( fileData == NULL ) {
		common->Warning( "idRenderModelMD4: %s not found", fileName );
		return false;
	}

	const md4Header_t *md4 = ( const md4Header_t * )fileData;

	if ( LittleInt( md4->ident ) != MD4_IDENT ) {
		common->Warning( "idRenderModelMD4: %s has the wrong ident", fileName );
		return false;
	}
	if ( LittleInt( md4->version ) != MD4_VERSION ) {
		common->Warning( "idRenderModelMD4: %s has wrong version (%i should be %i)", fileName, LittleInt( md4->version ), MD4_VERSION );
		return false;
	}
	if ( LittleInt( md4->ofsEnd ) > fileSize ) {
		common->Warning( "idRenderModelMD4: %s is truncated", fileName );
		return false;
	}

	numFrames = LittleInt( md4->numFrames );
	numBones = LittleInt( md4->numBones );
	const int numLODs = LittleInt( md4->numLODs );

	if ( numFrames < 1 ) {
		common->Warning( "idRenderModelMD4: %s has no frames", fileName );
		return false;
	}
	if ( numBones < 1 || numBones > MD4_MAX_BONES ) {
		common->Warning( "idRenderModelMD4: %s has an invalid number of bones (%i)", fileName, numBones );
		return false;
	}
	if ( numLODs < 1 ) {
		common->Warning( "idRenderModelMD4: %s has no levels of detail", fileName );
		return false;
	}

	const int frameSize = ( int )sizeof( md4Frame_t ) + numBones * ( int )sizeof( md4Bone_t );
	if ( LittleInt( md4->ofsFrames ) + numFrames * frameSize > LittleInt( md4->ofsEnd ) ) {
		common->Warning( "idRenderModelMD4: %s has a truncated frame list", fileName );
		return false;
	}

	// the md4 format stores no bone names or hierarchy, generate plain names
	joints.SetGranularity( 1 );
	joints.SetNum( numBones );
	for ( int i = 0; i < numBones; i++ ) {
		idStr boneName;
		boneName.Format( "bone%i", i );
		joints[i].name = boneName;
		joints[i].parent = NULL;
	}

	// per frame bounds
	frameBounds.SetGranularity( 1 );
	frameBounds.SetNum( numFrames );
	for ( int i = 0; i < numFrames; i++ ) {
		const md4Frame_t *frame = ( const md4Frame_t * )( fileData + LittleInt( md4->ofsFrames ) + i * frameSize );
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

	// the surfaces of all levels of detail are loaded as meshes
	meshes.SetGranularity( 1 );
	int lodOfs = LittleInt( md4->ofsLODs );
	for ( int lod = 0; lod < numLODs; lod++ ) {
		const md4LOD_t *lodHeader = ( const md4LOD_t * )( fileData + lodOfs );
		if ( lodOfs + LittleInt( lodHeader->ofsEnd ) > LittleInt( md4->ofsEnd ) ) {
			common->Warning( "idRenderModelMD4: %s has a truncated level of detail", fileName );
			return false;
		}

		int surfaceOfs = lodOfs + LittleInt( lodHeader->ofsSurfaces );
		for ( int i = 0; i < LittleInt( lodHeader->numSurfaces ); i++ ) {
			const md4Surface_t *surf = ( const md4Surface_t * )( fileData + surfaceOfs );
			if ( surfaceOfs + ( int )sizeof( md4Surface_t ) > LittleInt( md4->ofsEnd ) ) {
				common->Warning( "idRenderModelMD4: %s has a truncated surface", fileName );
				return false;
			}
			const int surfEnd = surfaceOfs + LittleInt( surf->ofsEnd );
			if ( surfEnd > LittleInt( md4->ofsEnd ) ) {
				common->Warning( "idRenderModelMD4: %s has a truncated surface", fileName );
				return false;
			}

			idWolfMesh &mesh = meshes.Alloc();
			if ( !BuildMeshFromSurface( mesh, surf->shader,
					LittleInt( surf->numVerts ), surfaceOfs + LittleInt( surf->ofsVerts ), WOLF_MD4_VERTEX_HEADER_SIZE,
					LittleInt( surf->numTriangles ), surfaceOfs + LittleInt( surf->ofsTriangles ),
					surfEnd, bindPose ) ) {
				return false;
			}
			surfaceOfs = surfEnd;
		}

		lodOfs += LittleInt( lodHeader->ofsEnd );
	}

	return true;
}
