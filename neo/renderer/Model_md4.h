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

#ifndef __MODEL_MD4_H__
#define __MODEL_MD4_H__

#include "Model_common.h"

#define MD4_IDENT				( ( '4' << 24 ) + ( 'P' << 16 ) + ( 'D' << 8 ) + 'I' )
#define MD4_VERSION				1
#define MD4_MAX_BONES			128
#define MD4_VERTEX_HEADER_SIZE	24

typedef struct {
	float		bounds[2][3];
	float		localOrigin[3];
	float		radius;
	char		name[16];
	// md4Bone_t[numBones] follows
} md4Frame_t;

typedef struct {
	int			ident;
	char		name[MOD_MAX_QPATH];
	char		shader[MOD_MAX_QPATH];
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
	char		name[MOD_MAX_QPATH];
	int			numFrames;
	int			numBones;
	int			ofsFrames;		// md4Frame_t[numFrames]
	int			numLODs;
	int			ofsLODs;		// md4LOD_t[numLODs]
	int			ofsEnd;
} md4Header_t;

/*
===============================================================================

	MD4 loader. (Absolute per-frame bone matrices)

===============================================================================
*/

class idRenderModelMD4 : public idRenderModelMODSkeletal {
public:
					idRenderModelMD4() {}
	virtual			~idRenderModelMD4() {}

protected:
	virtual void	DecodeFrame( int frameNum, idJointQuat *jointQuats ) const;
	virtual bool	LoadMODFile( const char *fileName );
};

#endif /* !__MODEL_MD4_H__ */
