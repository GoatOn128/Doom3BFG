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

#ifndef __MODEL_MDS_H__
#define __MODEL_MDS_H__

#include "Model_common.h"

#define MDS_IDENT				( ( 'W' << 24 ) + ( 'S' << 16 ) + ( 'D' << 8 ) + 'M' )
#define MDS_VERSION				4
#define MDS_MAX_VERTS			6000
#define MDS_MAX_TRIANGLES		8192
#define MDS_MAX_BONES			128
#define MDS_MAX_SURFACES		32
#define MDS_MAX_TAGS			128
#define MDS_VERTEX_HEADER_SIZE	32	// + fixedParent + fixedDist

typedef struct {
	char		name[MOD_MAX_QPATH];
	float		torsoWeight;
	int			boneIndex;
} mdsTag_t;

typedef struct {
	int			ident;
	char		name[MOD_MAX_QPATH];
	char		shader[MOD_MAX_QPATH];
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
	int			version;
	char		name[MOD_MAX_QPATH];
	float		lodScale;
	float		lodBias;
	int			numFrames;
	int			numBones;
	int			ofsFrames;		// modFrame_t[numFrames]
	int			ofsBones;		// mdsBoneInfo_t[numBones]
	int			torsoParent;
	int			numSurfaces;
	int			ofsSurfaces;
	int			numTags;
	int			ofsTags;		// mdsTag_t[numTags]
	int			ofsEnd;
} mdsHeader_t;

/*
===============================================================================

	MDS loader.

===============================================================================
*/
class idRenderModelMDS : public idRenderModelMODSkeletal {
public:
					idRenderModelMDS() {}
	virtual			~idRenderModelMDS() {}

protected:
	virtual void	DecodeFrame( int frameNum, idJointQuat *jointQuats ) const;
	virtual bool	LoadMODFile( const char *fileName );
};

#endif /* !__MODEL_MDS_H__ */
