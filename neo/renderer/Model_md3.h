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

#ifndef __MODEL_MD3_H__
#define __MODEL_MD3_H__

#include "Model_common.h"

/*
========================================================================

.MD3 triangle model file format

Private structures used by the MD3 loader.

========================================================================
*/

#define MD3_IDENT			(('3'<<24)+('P'<<16)+('D'<<8)+'I')
#define MD3_VERSION			15

// surface geometry should not exceed these limits
#define	SHADER_MAX_VERTEXES	1000
#define	SHADER_MAX_INDEXES	(6*SHADER_MAX_VERTEXES)

// limits
#define MD3_MAX_LODS		4
#define	MD3_MAX_TRIANGLES	8192	// per surface
#define MD3_MAX_VERTS		4096	// per surface
#define MD3_MAX_SHADERS		256		// per surface
#define MD3_MAX_FRAMES		1024	// per model
#define	MD3_MAX_SURFACES	32		// per model
#define MD3_MAX_TAGS		16		// per frame

// vertex scales
#define	MD3_XYZ_SCALE		(1.0/64)

typedef struct md3Frame_s {
	idVec3		bounds[2];
	idVec3		localOrigin;
	float		radius;
	char		name[16];
} md3Frame_t;

typedef struct md3Tag_s {
	char		name[MOD_MAX_QPATH];	// tag name
	idVec3		origin;
	idVec3		axis[3];
} md3Tag_t;

/*
** md3Surface_t
**
** CHUNK			SIZE
** header			sizeof( md3Surface_t )
** shaders			sizeof( md3Shader_t ) * numShaders
** triangles[0]		sizeof( md3Triangle_t ) * numTriangles
** st				sizeof( md3St_t ) * numVerts
** XyzNormals		sizeof( md3XyzNormal_t ) * numVerts * numFrames
*/

typedef struct md3Surface_s {
	int			ident;				//

	char		name[MOD_MAX_QPATH];	// polyset name

	int			flags;
	int			numFrames;			// all surfaces in a model should have the same

	int			numShaders;			// all surfaces in a model should have the same
	int			numVerts;

	int			numTriangles;
	int			ofsTriangles;

	int			ofsShaders;			// offset from start of md3Surface_t
	int			ofsSt;				// texture coords are common for all frames
	int			ofsXyzNormals;		// numVerts * numFrames

	int			ofsEnd;				// next surface follows
} md3Surface_t;

typedef struct {
	char				name[MOD_MAX_QPATH];
	const idMaterial *	shader;			// for in-game use
} md3Shader_t;

typedef struct {
	int			indexes[3];
} md3Triangle_t;

typedef struct {
	float		st[2];
} md3St_t;

typedef struct {
	short		xyz[3];
	short		normal;
} md3XyzNormal_t;

typedef struct md3Header_s {
	int			ident;
	int			version;

	char		name[MOD_MAX_QPATH];	// model name

	int			flags;

	int			numFrames;
	int			numTags;
	int			numSurfaces;

	int			numSkins;

	int			ofsFrames;			// offset for first frame
	int			ofsTags;			// numFrames * numTags
	int			ofsSurfaces;		// first surface, others follow

	int			ofsEnd;				// end of file
} md3Header_t;

/*
===============================================================================

	MD3 animated model

===============================================================================
*/

class idRenderModelMD3 : public idRenderModelStatic {
public:
								idRenderModelMD3();
	virtual						~idRenderModelMD3();

	virtual void				InitFromFile( const char *fileName );
	virtual bool				SupportsBinaryModel() { return false; }
	virtual void				PurgeModel();
	virtual void				LoadModel();
	virtual void				TouchData();
	virtual void				List() const;
	virtual int					Memory() const;
	virtual dynamicModel_t		IsDynamicModel() const;
	virtual idRenderModel *		InstantiateDynamicModel( const struct renderEntity_s *ent, const viewDef_t *view, idRenderModel *cachedModel );
	virtual idBounds			Bounds( const struct renderEntity_s *ent ) const;


	virtual int					NumJoints() const;	// the MD3 tags are exposed as joints so attachments can find them
	virtual const idMD5Joint *	GetJoints() const;
	virtual jointHandle_t		GetJointHandle( const char *name ) const;
	virtual const char *		GetJointName( jointHandle_t handle ) const;
	virtual bool				GetJointTransform( jointHandle_t handle, const struct renderEntity_s *ent, idVec3 &origin, idMat3 &axis ) const;

protected:
	// format hook points, MDC shares the whole MD3 path through these
	virtual bool				LoadHeader( const char *fileName, struct md3Header_s **headerOut, ID_TIME_T *timestamp );
	virtual const char *		LodFileExtension() const;

private:
	int							index;			// model = tr.models[model->index]
	int							dataSize;		// just for listing purposes
	struct md3Header_s *		md3;			// only if type == MOD_MESH
	struct md3Header_s *		lods[MD3_MAX_LODS];	// base model plus lower detail levels
	int							numLods;		// number of valid entries in lods[]
	idList<idMD5Joint, TAG_MODEL>	joints;		// the MD3 tags exposed as joints

	void						LerpMeshVertexes( srfTriangles_t *tri, const struct md3Surface_s *surf, const float backlerp, const int frame, const int oldframe ) const;
	void						GetFrameParms( const struct renderEntity_s *ent, const struct md3Header_s *header, int &frame, int &oldframe, float &backlerp ) const;
	int							SelectLodForView( const struct renderEntity_s *ent, const viewDef_t *view, int frame ) const;
};

#endif /* !__MODEL_MD3_H__ */
