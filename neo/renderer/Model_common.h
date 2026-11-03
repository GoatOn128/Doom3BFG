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

#ifndef __MODEL_COMMON_H__
#define __MODEL_COMMON_H__

#include "Model_local.h"

/*
===============================================================================

	Common code shared between some model loaders.

===============================================================================
*/

#define MOD_MAX_QPATH			64

// shared vertex layout offsets, the weight array follows the header
#define MOD_VERTEX_NORMAL_OFFSET			0
#define MOD_VERTEX_TEXCOORD_OFFSET			12
#define MOD_VERTEX_NUMWEIGHTS_OFFSET		20
#define MOD_WEIGHT_SIZE						16	// { int boneIndex; float boneWeight; float offset[3]; }

typedef struct {
	int			boneIndex;		// global bone index, used directly at runtime
	float		boneWeight;
	float		offset[3];
} modWeight_t;

typedef struct {
	short		angles[4];		// absolute euler angles, PITCH/YAW/ROLL, SHORT2ANGLE packed
	short		ofsAngles[2];	// PITCH/YAW direction from the parent bone origin
} modBoneFrameCompressed_t;

typedef struct {
	float		bounds[2][3];
	float		localOrigin[3];
	float		radius;
	float		parentOffset[3];
	// modBoneFrameCompressed_t[numBones] follows
} modFrame_t;

typedef struct {
	char		name[MOD_MAX_QPATH];
	int			parent;
	float		torsoWeight;
	float		parentDist;
	int			flags;
} modBoneInfo_t;

/*
===============================================================================

	idMODMesh

===============================================================================
*/

class idMODMesh {
public:
							idMODMesh();
							~idMODMesh();

	int						NumVerts() const { return numVerts; }
	int						NumTris() const { return numTris; }

	void					UpdateSurface( const struct renderEntity_s *ent, const idJointMat *entJoints,
											const idJointMat *entJointsInverted, modelSurface_t *surf ) const;
	void					CalculateBounds( const idJointMat *entJoints, idBounds &bounds ) const;
	int						NearestJoint( int a, int b, int c ) const;

	const idMaterial *		shader;
	deformInfo_t *			deformInfo;

	idStr					surfaceName;	// lowercased surface name, keys Q3/ET skin remapping
	int						surfaceNum;		// only needed for the interactions with UpdateSurface

private:
	int						numVerts;
	int						numTris;
	byte *					meshJoints;
	int						numMeshJoints;
	float					maxJointVertDist;

	friend class idRenderModelMODSkeletal;
};

/*
===============================================================================

	idRenderModelMODSkeletal

===============================================================================
*/

struct modTag_t {
	idStr					name;
	int						boneIndex;
	idVec3					offset;
	idMat3					axis;
};

// shared helpers, defined in Model_common.cpp and used by the format loaders
byte						*MOD_LoadFile( const char *fileName, int *fileSizeOut, ID_TIME_T *timestamp );
const char					*MOD_Name( const char *name, char *buffer );

class idRenderModelMODSkeletal : public idRenderModelStatic {
public:
							idRenderModelMODSkeletal();
	virtual					~idRenderModelMODSkeletal();

	virtual void			InitFromFile( const char *fileName );
	virtual bool			SupportsBinaryModel() { return false; }
	virtual void			PurgeModel();
	virtual void			LoadModel();
	virtual void			TouchData();
	virtual void			List() const;
	virtual void			Print() const;
	virtual int				Memory() const;
	virtual dynamicModel_t	IsDynamicModel() const;
	virtual idRenderModel *	InstantiateDynamicModel( const struct renderEntity_s *ent, const viewDef_t *view, idRenderModel *cachedModel );
	virtual idBounds		Bounds( const struct renderEntity_s *ent ) const;

	virtual int				NumJoints() const;
	virtual const idMD5Joint *GetJoints() const;
	virtual jointHandle_t	GetJointHandle( const char *name ) const;
	virtual const char *	GetJointName( jointHandle_t handle ) const;
	virtual const idJointQuat *GetDefaultPose() const;
	virtual bool			GetJointTransform( jointHandle_t handle, const struct renderEntity_s *ent, idVec3 &origin, idMat3 &axis ) const;
	virtual int				NearestJoint( int surfaceNum, int a, int b, int c ) const;

protected:
	// decode the absolute transforms of all bones of a single frame
	virtual void			DecodeFrame( int frameNum, idJointQuat *jointQuats ) const = 0;
	// fill the skeleton, meshes and tags from the file
	virtual bool			LoadMODFile( const char *fileName ) = 0;

	void					FinishSkeleton();
	// build a mesh from the surface data, the weights index global bones
	bool					BuildMeshFromSurface( idMODMesh &mesh, const char *shaderName, const char *surfaceName,
								int numVerts, int ofsVerts, int vertexHeaderSize,
								int numTriangles, int ofsTriangles,
								int surfaceEnd, const idJointMat *bindPose );
	void					GetFrameParms( const struct renderEntity_s *ent, int &frame, int &oldframe, float &backlerp ) const;
	// decode and blend two frames into absolute joint matrices
	void					DecodePose( int frame, int oldframe, float backlerp, idJointMat *outJoints ) const;
	// the posed bones, either the game supplied ones or decoded from the file
	const idJointMat *		PoseJoints( const struct renderEntity_s *ent, int &frame, int &oldframe, float &backlerp, idJointMat *posedJoints ) const;

	idList<idMD5Joint, TAG_MODEL>		joints;			// bones then tags
	idList<idJointQuat, TAG_MODEL>		defaultPose;	// parent relative, frame 0
	idList<idJointMat, TAG_MODEL>		invertedDefaultPose; // absolute, frame 0
	idList<idMODMesh, TAG_MODEL>		meshes;
	idList<idBounds, TAG_MODEL>			frameBounds;
	idList<modTag_t, TAG_MODEL>			tags;
	// the union of all frame bounds lives in the inherited idRenderModelStatic::bounds
	int									numBones;
	int									numFrames;
	byte *								fileData;		// the raw model file
	byte *								skeletonData;	// the sibling skeleton file (.mdx), MDM only
};

#endif /* !__MODEL_COMMON_H__ */
