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
// this repository under references/etwolf. The skeletal pipeline is modeled
// on the Doom 3 MD5 loader (Model_md5.cpp) including the GPU skinning path.

#ifndef __MODEL_WOLF_H__
#define __MODEL_WOLF_H__

#include "Model_local.h"

/*
===============================================================================

	Wolfenstein skeletal file formats (MDS / MDM / MDX / MD4)

	The structures below match the on-disk layouts from the
	Wolfenstein: Enemy Territory SDK qfiles.h exactly.

===============================================================================
*/

#define WOLF_MAX_QPATH			64

// MDS file format (Wolfenstein Skeletal Format)
#define MDS_IDENT				( ( 'W' << 24 ) + ( 'S' << 16 ) + ( 'D' << 8 ) + 'M' )
#define MDS_VERSION				4
#define MDS_MAX_VERTS			6000
#define MDS_MAX_TRIANGLES		8192
#define MDS_MAX_BONES			128
#define MDS_MAX_SURFACES		32
#define MDS_MAX_TAGS			128

// MDM file format (Wolfenstein Skeletal Mesh)
#define MDM_IDENT				( ( 'W' << 24 ) + ( 'M' << 16 ) + ( 'D' << 8 ) + 'M' )
#define MDM_VERSION				3
#define MDM_MAX_VERTS			6000
#define MDM_MAX_TRIANGLES		8192
#define MDM_MAX_SURFACES		32
#define MDM_MAX_TAGS			128

// MDX file format (Wolfenstein Skeletal Data)
#define MDX_IDENT				( ( 'W' << 24 ) + ( 'X' << 16 ) + ( 'D' << 8 ) + 'M' )
#define MDX_VERSION				2
#define MDX_MAX_BONES			128

// MD4 file format (early Quake III Arena skeletal format, kept for completeness)
#define MD4_IDENT				( ( '4' << 24 ) + ( 'P' << 16 ) + ( 'D' << 8 ) + 'I' )
#define MD4_VERSION				1
#define MD4_MAX_BONES			128

// shared vertex layout offsets, the weight array follows the header
#define WOLF_VERTEX_NORMAL_OFFSET			0
#define WOLF_VERTEX_TEXCOORD_OFFSET			12
#define WOLF_VERTEX_NUMWEIGHTS_OFFSET		20
#define WOLF_MDS_VERTEX_HEADER_SIZE			32	// + fixedParent + fixedDist
#define WOLF_MDM_VERTEX_HEADER_SIZE			24
#define WOLF_MD4_VERTEX_HEADER_SIZE			24
#define WOLF_WEIGHT_SIZE					 16	// { int boneIndex; float boneWeight; float offset[3]; }

typedef struct {
	int			boneIndex;		// global bone index, used directly at runtime
	float		boneWeight;
	float		offset[3];
} wolfWeight_t;

typedef struct {
	short		angles[4];		// absolute euler angles, PITCH/YAW/ROLL, SHORT2ANGLE packed
	short		ofsAngles[2];	// PITCH/YAW direction from the parent bone origin
} wolfBoneFrameCompressed_t;

typedef struct {
	float		bounds[2][3];
	float		localOrigin[3];
	float		radius;
	float		parentOffset[3];
	// wolfBoneFrameCompressed_t[numBones] follows
} wolfFrame_t;

typedef struct {
	float		bounds[2][3];
	float		localOrigin[3];
	float		radius;
	char		name[16];
	// md4Bone_t[numBones] follows
} md4Frame_t;

typedef struct {
	char		name[WOLF_MAX_QPATH];
	int			parent;
	float		torsoWeight;
	float		parentDist;
	int			flags;
} wolfBoneInfo_t;

typedef struct {
	char		name[WOLF_MAX_QPATH];
	float		torsoWeight;
	int			boneIndex;
} mdsTag_t;

typedef struct {
	char		name[WOLF_MAX_QPATH];
	float		axis[3][3];
	int			boneIndex;
	float		offset[3];
	int			numBoneReferences;
	int			ofsBoneReferences;
	int			ofsEnd;			// next tag follows
} mdmTag_t;

typedef struct {
	int			ident;
	char		name[WOLF_MAX_QPATH];
	char		shader[WOLF_MAX_QPATH];
	int			shaderIndex;
	int			minLod;
	int			ofsHeader;
	int			numVerts;
	int			ofsVerts;
	int			numTriangles;
	int			ofsTriangles;
	int			ofsCollapseMap;
	int			numBoneReferences;
	int			ofsBoneReferences;
	int			ofsEnd;			// next surface follows
} mdsSurface_t;

typedef struct {
	int			ident;
	char		name[WOLF_MAX_QPATH];
	char		shader[WOLF_MAX_QPATH];
	int			shaderIndex;
	int			ofsHeader;
	int			numVerts;
	int			ofsVerts;
	int			numTriangles;
	int			ofsTriangles;
	int			numBoneReferences;
	int			ofsBoneReferences;
	int			ofsEnd;			// next surface follows
} md4Surface_t;

typedef struct {
	float		matrix[3][4];	// absolute bone transform, rows with translation in the last column
} md4Bone_t;

typedef struct {
	int			numSurfaces;
	int			ofsSurfaces;
	int			ofsEnd;			// next lod follows
} md4LOD_t;

typedef struct {
	int			ident;
	int			version;
	char		name[WOLF_MAX_QPATH];
	float		lodScale;
	float		lodBias;
	int			numFrames;
	int			numBones;
	int			ofsFrames;		// wolfFrame_t[numFrames]
	int			ofsBones;		// mdsBoneInfo_t[numBones]
	int			torsoParent;
	int			numSurfaces;
	int			ofsSurfaces;
	int			numTags;
	int			ofsTags;		// mdsTag_t[numTags]
	int			ofsEnd;
} mdsHeader_t;

typedef struct {
	int			ident;
	int			version;
	char		name[WOLF_MAX_QPATH];
	float		lodScale;
	float		lodBias;
	int			numSurfaces;
	int			ofsSurfaces;
	int			numTags;
	int			ofsTags;		// mdmTag_t[numTags], variable sized
	int			ofsEnd;
} mdmHeader_t;

typedef struct {
	int			ident;
	int			version;
	char		name[WOLF_MAX_QPATH];
	int			numFrames;
	int			numBones;
	int			ofsFrames;		// wolfFrame_t[numFrames]
	int			ofsBones;		// mdxBoneInfo_t[numBones]
	int			torsoParent;
	int			ofsEnd;
} mdxHeader_t;

typedef struct {
	int			ident;
	int			version;
	char		name[WOLF_MAX_QPATH];
	int			numFrames;
	int			numBones;
	int			ofsFrames;		// md4Frame_t[numFrames]
	int			numLODs;
	int			ofsLODs;		// md4LOD_t[numLODs]
	int			ofsEnd;
} md4Header_t;

/*
===============================================================================

	idWolfMesh

	One skinned surface, mirrors the pieces of idMD5Mesh the Wolfenstein
	formats need.

===============================================================================
*/

class idWolfMesh {
public:
							idWolfMesh();
							~idWolfMesh();

	int						NumVerts() const { return numVerts; }
	int						NumTris() const { return numTris; }

	void					UpdateSurface( const struct renderEntity_s *ent, const idJointMat *entJoints,
											const idJointMat *entJointsInverted, modelSurface_t *surf ) const;
	void					CalculateBounds( const idJointMat *entJoints, idBounds &bounds ) const;
	int						NearestJoint( int a, int b, int c ) const;

	const idMaterial *		shader;
	deformInfo_t *			deformInfo;

	int						surfaceNum;		// only needed for the interactions with UpdateSurface

private:
	int						numVerts;
	int						numTris;
	byte *					meshJoints;
	int						numMeshJoints;
	float					maxJointVertDist;

	friend class idRenderModelWolfSkeletal;
};

/*
===============================================================================

	idRenderModelWolfSkeletal

	Common base for the Wolfenstein skeletal formats. Models are posed from
	the file frames through the MD3 style shader parms, or from game supplied
	joints when the renderEntity carries a matching skeleton.

===============================================================================
*/

struct wolfTag_t {
	idStr					name;
	int						boneIndex;
	idVec3					offset;
	idMat3					axis;
};

class idRenderModelWolfSkeletal : public idRenderModelStatic {
public:
							idRenderModelWolfSkeletal();
	virtual					~idRenderModelWolfSkeletal();

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
	virtual bool			LoadWolfFile( const char *fileName ) = 0;

	void					FinishSkeleton();
	// build a mesh from the surface data, the weights index global bones
	bool					BuildMeshFromSurface( idWolfMesh &mesh, const char *shaderName,
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
	idList<idWolfMesh, TAG_MODEL>		meshes;
	idList<idBounds, TAG_MODEL>			frameBounds;
	idList<wolfTag_t, TAG_MODEL>		tags;
	// the union of all frame bounds lives in the inherited idRenderModelStatic::bounds
	int									numBones;
	int									numFrames;
	byte *								fileData;		// the raw model file
	byte *								skeletonData;	// the sibling skeleton file (.mdx), MDM only
};

// MDS: bones, frames, surfaces and tags all in one file
class idRenderModelMDS : public idRenderModelWolfSkeletal {
public:
							idRenderModelMDS() {}
	virtual					~idRenderModelMDS() {}

protected:
	virtual void			DecodeFrame( int frameNum, idJointQuat *jointQuats ) const;
	virtual bool			LoadWolfFile( const char *fileName );
};

// MDM: mesh and tags from the .mdm, skeleton and frames from the sibling .mdx
class idRenderModelMDM : public idRenderModelWolfSkeletal {
public:
							idRenderModelMDM() {}
	virtual					~idRenderModelMDM() {}

protected:
	virtual void			DecodeFrame( int frameNum, idJointQuat *jointQuats ) const;
	virtual bool			LoadWolfFile( const char *fileName );
};

// MD4: absolute per-frame bone matrices, kept for completion sake
class idRenderModelMD4 : public idRenderModelWolfSkeletal {
public:
							idRenderModelMD4() {}
	virtual					~idRenderModelMD4() {}

protected:
	virtual void			DecodeFrame( int frameNum, idJointQuat *jointQuats ) const;
	virtual bool			LoadWolfFile( const char *fileName );
};

#endif /* !__MODEL_WOLF_H__ */
