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

#ifndef __BSP29_H__
#define __BSP29_H__

#include "Wad2.h"

/*
===============================================================================

	Quake 1 BSP (version 29) loader and writer.

	The lump structures come from the Quake 1 GPL release
	(references/quake/WinQuake/bspfile.h, Copyright (C) 1996-1997 Id Software,
	Inc., GPLv2 or later).

	Extension lumps (BSPX)
	----------------------
	The 15 lump header of the format is left untouched so stock Quake tools and
	engines keep opening the file. Extra lumps live in a BSPX directory that
	follows the last lump (4 byte aligned):

		char	id[4] = "BSPX";
		int		numLumps;
		struct { char name[24]; int fileOfs; int fileLen; } lumps[numLumps];

	Three extension lumps are known to this engine:

		BSPX_LUMP_CM		reference to the external collision model (.cm)
		BSPX_LUMP_VIS		reference to the external render world (.proc)
		BSPX_LUMP_LIGHTING	lightmap data, RGB, three bytes per luxel (the same
							indexing as the stock lighting lump, offset = lightofs * 3)

	The stock collision (LUMP_CLIPNODES) and lighting (LUMP_LIGHTING) lumps are
	skipped by the loader: their bytes are kept raw so the file can be written
	back unchanged, but they are not parsed. All other lumps are loaded, and
	unknown BSPX lumps are kept by name.

	The reference lumps hold bspxFileRef_t: the relative file name, the size and
	the CRC32 of the external file as written by dmap.

===============================================================================
*/

#define BSP29_VERSION			29
#define BSP29_HEADER_LUMPS		15
#define BSP29_HEADER_SIZE		( 4 + BSP29_HEADER_LUMPS * 8 )
#define BSP29_MAX_HULLS			4
#define BSP29_MAX_LIGHTMAPS		4
#define BSP29_NUM_AMBIENTS		4

#define BSPX_IDENT				"BSPX"
#define BSPX_MAX_LUMPNAME		24
#define BSPX_DIR_ENTRY_SIZE		( BSPX_MAX_LUMPNAME + 8 )
#define BSPX_MAX_LUMPS			1024
#define BSPX_FILEREF_VERSION	1
#define BSPX_FILEREF_NAME_SIZE	64

typedef enum {
	BSP29_LUMP_ENTITIES = 0,
	BSP29_LUMP_PLANES,
	BSP29_LUMP_TEXTURES,
	BSP29_LUMP_VERTEXES,
	BSP29_LUMP_VISIBILITY,
	BSP29_LUMP_NODES,
	BSP29_LUMP_TEXINFO,
	BSP29_LUMP_FACES,
	BSP29_LUMP_LIGHTING,
	BSP29_LUMP_CLIPNODES,
	BSP29_LUMP_LEAFS,
	BSP29_LUMP_MARKSURFACES,
	BSP29_LUMP_EDGES,
	BSP29_LUMP_SURFEDGES,
	BSP29_LUMP_MODELS
} bsp29LumpId_t;

typedef enum {
	BSPX_LUMP_CM = 0,
	BSPX_LUMP_LIGHTING,
	BSPX_LUMP_VIS,
	BSPX_NUM_LUMPS
} bspxLumpId_t;

// leaf contents
#define BSP29_CONTENTS_EMPTY	-1
#define BSP29_CONTENTS_SOLID	-2
#define BSP29_CONTENTS_WATER	-3
#define BSP29_CONTENTS_SLIME	-4
#define BSP29_CONTENTS_LAVA		-5
#define BSP29_CONTENTS_SKY		-6

// texinfo flags
#define BSP29_TEX_SPECIAL		1		// sky or slime, no lightmap or 256 subdivision

// on disk structures, all naturally aligned so the lumps can be copied straight in
struct bsp29LumpInfo_t {
	int				fileOfs;
	int				fileLen;
};

struct bsp29Vertex_t {
	float			point[3];
};

struct bsp29Plane_t {
	float			normal[3];
	float			dist;
	int				type;
};

struct bsp29Node_t {
	int				planeNum;
	short			children[2];		// negative numbers are -(leafs+1), not nodes
	short			mins[3];
	short			maxs[3];
	unsigned short	firstFace;
	unsigned short	numFaces;			// counting both sides
};

struct bsp29TexInfo_t {
	float			vecs[2][4];			// [s/t][xyz offset]
	int				miptex;
	int				flags;
};

struct bsp29Edge_t {
	unsigned short	v[2];
};

struct bsp29Face_t {
	short			planeNum;
	short			side;
	int				firstEdge;
	short			numEdges;
	short			texInfo;
	byte			styles[BSP29_MAX_LIGHTMAPS];
	int				lightOfs;
};

struct bsp29Leaf_t {
	int				contents;
	int				visOfs;				// -1 = no visibility info
	short			mins[3];
	short			maxs[3];
	unsigned short	firstMarkSurface;
	unsigned short	numMarkSurfaces;
	byte			ambientLevel[BSP29_NUM_AMBIENTS];
};

struct bsp29Model_t {
	float			mins[3];
	float			maxs[3];
	float			origin[3];
	int				headNode[BSP29_MAX_HULLS];
	int				visLeafs;			// not including the solid leaf 0
	int				firstFace;
	int				numFaces;
};

struct bspxFileRef_t {
	int				version;
	unsigned int	checksum;			// CRC32 of the file
	int				fileLength;
	char			name[BSPX_FILEREF_NAME_SIZE];	// relative to the game directory, null terminated
};

struct bspxLump_t {
	idStr			name;
	idList<byte>	data;
};

typedef enum {
	BSPX_REF_NONE,						// the BSP has no such reference lump
	BSPX_REF_OK,
	BSPX_REF_FILE_MISSING,
	BSPX_REF_STALE						// the file exists but its size or checksum differs
} bspxRefState_t;

class idBsp29 {
public:
						idBsp29();
						~idBsp29();

	void				Clear();

						// the file is read through the file system, so it can sit inside a pak
	bool				LoadFromFile( const char *fileName );
						// the data is copied
	bool				LoadFromMemory( const byte *data, int length, const char *debugName );
						// writes the 15 stock lumps and, if there are extension lumps, the BSPX directory
	bool				Write( idFile *file ) const;

	const char *		GetName() const { return name.c_str(); }
	bool				IsLoaded() const { return models.Num() > 0; }

						// the 15 stock lump table entries as read, also for the skipped lumps
	const bsp29LumpInfo_t &GetLumpInfo( bsp29LumpId_t lump ) const { return lumpInfo[lump]; }

	// extension lumps
	static const char *	GetExtLumpName( bspxLumpId_t id );
	const bspxLump_t *	FindExtLump( const char *lumpName ) const;
	int					NumExtLumps() const { return extLumps.Num(); }
	const bspxLump_t &	GetExtLump( int index ) const { return extLumps[index]; }
	void				SetExtLump( const char *lumpName, const byte *data, int length );
	bool				RemoveExtLump( const char *lumpName );

						// BSPX_LUMP_CM and BSPX_LUMP_VIS
	bool				GetFileRef( bspxLumpId_t id, bspxFileRef_t &ref ) const;
	void				SetFileRef( bspxLumpId_t id, const char *fileName, const byte *fileData, int fileLength );
	bspxRefState_t		CheckFileRef( bspxLumpId_t id ) const;

						// BSPX_LUMP_LIGHTING, NULL when the BSP has none
	const byte *		GetLighting( int &length ) const;

	// geometry helpers
						// the corner points of a face in map order
	bool				GetFacePoints( int faceNum, idList<idVec3> &points ) const;

	// lump data, valid after a successful load
	idStr						entityString;
	idList<idDict>				entities;
	idList<bsp29Plane_t>		planes;
	idList<byte>				textureData;		// raw texture lump, the miptex entries point into it
	idWad2MipTexLump			textures;
	idList<bsp29Vertex_t>		vertexes;
	idList<byte>				visibility;
	idList<bsp29Node_t>			nodes;
	idList<bsp29TexInfo_t>		texInfo;
	idList<bsp29Face_t>			faces;
	idList<bsp29Leaf_t>			leafs;
	idList<unsigned short>		markSurfaces;
	idList<bsp29Edge_t>			edges;
	idList<int>					surfEdges;
	idList<bsp29Model_t>		models;

private:
						// not copyable, the texture entries point into textureData
						idBsp29( const idBsp29 &other );
	idBsp29 &			operator=( const idBsp29 &other );

	idStr				name;
	bsp29LumpInfo_t		lumpInfo[BSP29_HEADER_LUMPS];
	idList<byte>		rawClipNodes;				// LUMP_CLIPNODES, skipped
	idList<byte>		rawLighting;				// LUMP_LIGHTING, skipped
	idList<bspxLump_t>	extLumps;

	bool				ParseEntities();
	bool				Validate() const;
	bool				ReadBspxDirectory( const byte *data, int length );
};

#endif /* !__BSP29_H__ */
