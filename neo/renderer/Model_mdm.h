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

#ifndef __MODEL_MDM_H__
#define __MODEL_MDM_H__

#include "Model_common.h"

#define MDM_IDENT				( ( 'W' << 24 ) + ( 'M' << 16 ) + ( 'D' << 8 ) + 'M' )
#define MDM_VERSION				3
#define MDM_MAX_VERTS			6000
#define MDM_MAX_TRIANGLES		8192
#define MDM_MAX_SURFACES		32
#define MDM_MAX_TAGS			128
#define MDM_VERTEX_HEADER_SIZE	24

#define MDX_IDENT				( ( 'W' << 24 ) + ( 'X' << 16 ) + ( 'D' << 8 ) + 'M' )
#define MDX_VERSION				2
#define MDX_MAX_BONES			128

typedef struct {
	char		name[MOD_MAX_QPATH];
	float		axis[3][3];
	int			boneIndex;
	float		offset[3];
	int			numBoneReferences;
	int			ofsBoneReferences;
	int			ofsEnd;			// next tag follows
} mdmTag_t;

typedef struct {
	int			ident;
	int			version;
	char		name[MOD_MAX_QPATH];
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
	char		name[MOD_MAX_QPATH];
	int			numFrames;
	int			numBones;
	int			ofsFrames;		// modFrame_t[numFrames]
	int			ofsBones;		// mdxBoneInfo_t[numBones]
	int			torsoParent;
	int			ofsEnd;
} mdxHeader_t;

/*
===============================================================================

	MDM loader.

===============================================================================
*/

class idRenderModelMDM : public idRenderModelMODSkeletal {
public:
					idRenderModelMDM() {}
	virtual			~idRenderModelMDM() {}

protected:
	virtual void	DecodeFrame( int frameNum, idJointQuat *jointQuats ) const;
	virtual bool	LoadMODFile( const char *fileName );
};

#endif /* !__MODEL_MDM_H__ */
