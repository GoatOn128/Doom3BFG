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

If you have questions concerning this license or the applicable additional terms, please contact in writing to id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================

MDC (compressed MD3) support ported from the Wolfenstein: Enemy Territory
GPL Source Code (Copyright (C) 1999-2010 id Software LLC, a ZeniMax Media
company). The ET source is GPLv3 like this engine and is also vendored in
this repository under references/etwolf.

*/

#ifndef __MODEL_MDC_H__
#define __MODEL_MDC_H__

#include "Model_md3.h"

// file format constants from the Enemy Territory qfiles.h
#define MDC_IDENT			(('C'<<24)+('P'<<16)+('D'<<8)+'I')
#define MDC_VERSION		2

// resolution of the compressed vertex offset direction
#define MDC_DIST_SCALE		0.05f
// to centre the compressed offset per axis
#define MDC_MAX_OFS		127.0f
// scale to get degrees out of a compressed tag angle
#define MDC_TAG_ANGLE_SCALE	(360.0f / 32700.0f)

typedef struct {
	unsigned int	ofsVec;		// three 8 bit axis offsets plus a normal index in the high byte
} mdcXyzCompressed_t;

typedef struct {
	char			name[MAX_MD3PATH];	// tag name, stored once per tag
} mdcTagName_t;

typedef struct {
	short			xyz[3];
	short			angles[3];
} mdcTag_t;

// the on-disk shader entry, the runtime md3Shader_t replaces the index with a pointer
typedef struct {
	char			name[MAX_MD3PATH];
	int				shaderIndex;
} mdcShaderFile_t;

typedef struct mdcSurface_s {
	int				ident;

	char			name[MAX_MD3PATH];	// polyset name

	int				flags;
	int				numCompFrames;		// all surfaces in a model should have the same
	int				numBaseFrames;		// ditto

	int				numShaders;			// all surfaces in a model should have the same
	int				numVerts;

	int				numTriangles;
	int				ofsTriangles;

	int				ofsShaders;			// offset from start of mdcSurface_t
	int				ofsSt;				// texture coords are common for all frames
	int				ofsXyzNormals;		// numVerts * numBaseFrames
	int				ofsXyzCompressed;	// numVerts * numCompFrames

	int				ofsFrameBaseFrames;	// numFrames
	int				ofsFrameCompFrames;	// numFrames, -1 when the frame is a base frame

	int				ofsEnd;				// next surface follows
} mdcSurface_t;

typedef struct mdcHeader_s {
	int				ident;
	int				version;

	char			name[MAX_MD3PATH];	// model name

	int				flags;

	int				numFrames;
	int				numTags;
	int				numSurfaces;

	int				numSkins;

	int				ofsFrames;		// offset for first frame, stores the bounds and localOrigin
	int				ofsTagNames;		// numTags
	int				ofsTags;		// numFrames * numTags
	int				ofsSurfaces;	// first surface, others follow

	int				ofsEnd;			// end of file
} mdcHeader_t;

// idRenderModelMDC loads an MDC file and decodes the compressed data into a
// synthesized MD3 layout at load time, so the whole MD3 path (instantiate,
// LOD chain, tags as joints, per frame bounds) is shared unchanged.
class idRenderModelMDC : public idRenderModelMD3 {
public:
	idRenderModelMDC() { }

protected:
	virtual bool		LoadHeader( const char *fileName, struct md3Header_s **headerOut, ID_TIME_T *timestamp );
	virtual const char *LodFileExtension() const { return "mdc"; }
};

#endif /* !__MODEL_MDC_H__ */
