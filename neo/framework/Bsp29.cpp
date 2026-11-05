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

#include "Bsp29.h"

static_assert( sizeof( bsp29LumpInfo_t ) == 8, "bsp29LumpInfo_t size" );
static_assert( sizeof( bsp29Vertex_t ) == 12, "bsp29Vertex_t size" );
static_assert( sizeof( bsp29Plane_t ) == 20, "bsp29Plane_t size" );
static_assert( sizeof( bsp29Node_t ) == 24, "bsp29Node_t size" );
static_assert( sizeof( bsp29TexInfo_t ) == 40, "bsp29TexInfo_t size" );
static_assert( sizeof( bsp29Edge_t ) == 4, "bsp29Edge_t size" );
static_assert( sizeof( bsp29Face_t ) == 20, "bsp29Face_t size" );
static_assert( sizeof( bsp29Leaf_t ) == 28, "bsp29Leaf_t size" );
static_assert( sizeof( bsp29Model_t ) == 64, "bsp29Model_t size" );
static_assert( sizeof( bspxFileRef_t ) == 76, "bspxFileRef_t size" );

// the names of the extension lumps in the BSPX directory
static const char *bspxLumpNames[BSPX_NUM_LUMPS] = {
	"D3_CM",
	"D3_LIGHTING",
	"D3_VIS"
};

static const char *bsp29LumpNames[BSP29_HEADER_LUMPS] = {
	"entities", "planes", "textures", "vertexes", "visibility", "nodes", "texinfo", "faces",
	"lighting", "clipnodes", "leafs", "marksurfaces", "edges", "surfedges", "models"
};

/*
===============================================================================

	little endian helpers and the byte swapping of the lump structures

===============================================================================
*/

static int Bsp29_ReadInt( const byte *p ) {
	return (int)( (unsigned int)p[0] | ( (unsigned int)p[1] << 8 ) | ( (unsigned int)p[2] << 16 ) | ( (unsigned int)p[3] << 24 ) );
}

static void Bsp29_AppendBytes( idList<byte> &dst, const void *src, int length ) {
	if ( length <= 0 ) {
		return;
	}
	const int start = dst.Num();
	dst.SetNum( start + length );
	memcpy( dst.Ptr() + start, src, length );
}

static void Bsp29_AppendInt( idList<byte> &dst, int value ) {
	byte b[4];
	b[0] = (byte)( value & 0xff );
	b[1] = (byte)( ( value >> 8 ) & 0xff );
	b[2] = (byte)( ( value >> 16 ) & 0xff );
	b[3] = (byte)( ( value >> 24 ) & 0xff );
	Bsp29_AppendBytes( dst, b, 4 );
}

static void Bsp29_Pad4( idList<byte> &dst ) {
	while ( dst.Num() & 3 ) {
		byte zero = 0;
		Bsp29_AppendBytes( dst, &zero, 1 );
	}
}

static void Swap( bsp29Vertex_t &v ) {
	for ( int i = 0; i < 3; i++ ) {
		v.point[i] = LittleFloat( v.point[i] );
	}
}

static void Swap( bsp29Plane_t &p ) {
	for ( int i = 0; i < 3; i++ ) {
		p.normal[i] = LittleFloat( p.normal[i] );
	}
	p.dist = LittleFloat( p.dist );
	p.type = LittleInt( p.type );
}

static void Swap( bsp29Node_t &n ) {
	n.planeNum = LittleInt( n.planeNum );
	for ( int i = 0; i < 2; i++ ) {
		n.children[i] = LittleShort( n.children[i] );
	}
	for ( int i = 0; i < 3; i++ ) {
		n.mins[i] = LittleShort( n.mins[i] );
		n.maxs[i] = LittleShort( n.maxs[i] );
	}
	n.firstFace = (unsigned short)LittleShort( (short)n.firstFace );
	n.numFaces = (unsigned short)LittleShort( (short)n.numFaces );
}

static void Swap( bsp29TexInfo_t &t ) {
	for ( int i = 0; i < 2; i++ ) {
		for ( int j = 0; j < 4; j++ ) {
			t.vecs[i][j] = LittleFloat( t.vecs[i][j] );
		}
	}
	t.miptex = LittleInt( t.miptex );
	t.flags = LittleInt( t.flags );
}

static void Swap( bsp29Edge_t &e ) {
	e.v[0] = (unsigned short)LittleShort( (short)e.v[0] );
	e.v[1] = (unsigned short)LittleShort( (short)e.v[1] );
}

static void Swap( bsp29Face_t &f ) {
	f.planeNum = LittleShort( f.planeNum );
	f.side = LittleShort( f.side );
	f.firstEdge = LittleInt( f.firstEdge );
	f.numEdges = LittleShort( f.numEdges );
	f.texInfo = LittleShort( f.texInfo );
	f.lightOfs = LittleInt( f.lightOfs );
}

static void Swap( bsp29Leaf_t &l ) {
	l.contents = LittleInt( l.contents );
	l.visOfs = LittleInt( l.visOfs );
	for ( int i = 0; i < 3; i++ ) {
		l.mins[i] = LittleShort( l.mins[i] );
		l.maxs[i] = LittleShort( l.maxs[i] );
	}
	l.firstMarkSurface = (unsigned short)LittleShort( (short)l.firstMarkSurface );
	l.numMarkSurfaces = (unsigned short)LittleShort( (short)l.numMarkSurfaces );
}

static void Swap( bsp29Model_t &m ) {
	for ( int i = 0; i < 3; i++ ) {
		m.mins[i] = LittleFloat( m.mins[i] );
		m.maxs[i] = LittleFloat( m.maxs[i] );
		m.origin[i] = LittleFloat( m.origin[i] );
	}
	for ( int i = 0; i < BSP29_MAX_HULLS; i++ ) {
		m.headNode[i] = LittleInt( m.headNode[i] );
	}
	m.visLeafs = LittleInt( m.visLeafs );
	m.firstFace = LittleInt( m.firstFace );
	m.numFaces = LittleInt( m.numFaces );
}

static void Swap( unsigned short &s ) {
	s = (unsigned short)LittleShort( (short)s );
}

static void Swap( int &i ) {
	i = LittleInt( i );
}

/*
================
Bsp29_LoadStructLump

Copies a lump of fixed size structures, the lump size has to be a multiple of the structure size.
================
*/
template< class type >
static bool Bsp29_LoadStructLump( const byte *file, const bsp29LumpInfo_t &info, bsp29LumpId_t id, idList<type> &list ) {
	const int size = (int)sizeof( type );
	if ( info.fileLen % size != 0 ) {
		common->Warning( "idBsp29: the %s lump has a funny size", bsp29LumpNames[id] );
		return false;
	}
	const int count = info.fileLen / size;
	list.SetNum( count );
	if ( count > 0 ) {
		memcpy( list.Ptr(), file + info.fileOfs, info.fileLen );
		for ( int i = 0; i < count; i++ ) {
			Swap( list[i] );
		}
	}
	return true;
}

template< class type >
static void Bsp29_SerializeStructs( idList<byte> &dst, const idList<type> &src ) {
	dst.SetNum( src.Num() * (int)sizeof( type ) );
	for ( int i = 0; i < src.Num(); i++ ) {
		type copy = src[i];
		Swap( copy );
		memcpy( dst.Ptr() + i * (int)sizeof( type ), &copy, sizeof( type ) );
	}
}

/*
===============================================================================

	idBsp29

===============================================================================
*/

/*
================
idBsp29::idBsp29
================
*/
idBsp29::idBsp29() {
	memset( lumpInfo, 0, sizeof( lumpInfo ) );
}

/*
================
idBsp29::~idBsp29
================
*/
idBsp29::~idBsp29() {
	Clear();
}

/*
================
idBsp29::Clear
================
*/
void idBsp29::Clear() {
	name.Clear();
	memset( lumpInfo, 0, sizeof( lumpInfo ) );
	entityString.Clear();
	entities.Clear();
	planes.Clear();
	textures.Clear();
	textureData.Clear();
	vertexes.Clear();
	visibility.Clear();
	nodes.Clear();
	texInfo.Clear();
	faces.Clear();
	leafs.Clear();
	markSurfaces.Clear();
	edges.Clear();
	surfEdges.Clear();
	models.Clear();
	rawClipNodes.Clear();
	rawLighting.Clear();
	extLumps.Clear();
}

/*
================
idBsp29::LoadFromFile
================
*/
bool idBsp29::LoadFromFile( const char *fileName ) {
	Clear();

	byte *buffer = NULL;
	int length = fileSystem->ReadFile( fileName, (void **)&buffer );
	if ( buffer == NULL || length <= 0 ) {
		if ( buffer != NULL ) {
			fileSystem->FreeFile( buffer );
		}
		common->Warning( "idBsp29: couldn't read %s", fileName );
		return false;
	}

	bool ok = LoadFromMemory( buffer, length, fileName );
	if ( buffer != NULL ) {
		fileSystem->FreeFile( buffer );
	}
	return ok;
}

/*
================
idBsp29::LoadFromMemory
================
*/
bool idBsp29::LoadFromMemory( const byte *file, int length, const char *debugName ) {
	Clear();

	if ( file == NULL || length < BSP29_HEADER_SIZE ) {
		common->Warning( "idBsp29: %s is too short for a BSP header", debugName );
		return false;
	}

	const int version = Bsp29_ReadInt( file );
	if ( version != BSP29_VERSION ) {
		if ( memcmp( file, "BSP2", 4 ) == 0 || memcmp( file, "2PSB", 4 ) == 0 ) {
			common->Warning( "idBsp29: %s is a BSP2 file, only version %d is supported", debugName, BSP29_VERSION );
		} else {
			common->Warning( "idBsp29: %s has version %d, should be %d", debugName, version, BSP29_VERSION );
		}
		return false;
	}

	for ( int i = 0; i < BSP29_HEADER_LUMPS; i++ ) {
		bsp29LumpInfo_t &info = lumpInfo[i];
		info.fileOfs = Bsp29_ReadInt( file + 4 + i * 8 );
		info.fileLen = Bsp29_ReadInt( file + 4 + i * 8 + 4 );
		if ( info.fileOfs < 0 || info.fileLen < 0 || (int64)info.fileOfs + (int64)info.fileLen > (int64)length ) {
			common->Warning( "idBsp29: %s has the %s lump outside of the file", debugName, bsp29LumpNames[i] );
			Clear();
			return false;
		}
	}

	bool ok = true;

	// entities, the lump is a null terminated string
	{
		const bsp29LumpInfo_t &info = lumpInfo[BSP29_LUMP_ENTITIES];
		idList<char> text;
		text.SetNum( info.fileLen + 1 );
		if ( info.fileLen > 0 ) {
			memcpy( text.Ptr(), file + info.fileOfs, info.fileLen );
		}
		text[info.fileLen] = '\0';
		entityString = text.Ptr();
	}

	ok = ok && Bsp29_LoadStructLump( file, lumpInfo[BSP29_LUMP_PLANES], BSP29_LUMP_PLANES, planes );
	ok = ok && Bsp29_LoadStructLump( file, lumpInfo[BSP29_LUMP_VERTEXES], BSP29_LUMP_VERTEXES, vertexes );
	ok = ok && Bsp29_LoadStructLump( file, lumpInfo[BSP29_LUMP_NODES], BSP29_LUMP_NODES, nodes );
	ok = ok && Bsp29_LoadStructLump( file, lumpInfo[BSP29_LUMP_TEXINFO], BSP29_LUMP_TEXINFO, texInfo );
	ok = ok && Bsp29_LoadStructLump( file, lumpInfo[BSP29_LUMP_FACES], BSP29_LUMP_FACES, faces );
	ok = ok && Bsp29_LoadStructLump( file, lumpInfo[BSP29_LUMP_LEAFS], BSP29_LUMP_LEAFS, leafs );
	ok = ok && Bsp29_LoadStructLump( file, lumpInfo[BSP29_LUMP_MARKSURFACES], BSP29_LUMP_MARKSURFACES, markSurfaces );
	ok = ok && Bsp29_LoadStructLump( file, lumpInfo[BSP29_LUMP_EDGES], BSP29_LUMP_EDGES, edges );
	ok = ok && Bsp29_LoadStructLump( file, lumpInfo[BSP29_LUMP_SURFEDGES], BSP29_LUMP_SURFEDGES, surfEdges );
	ok = ok && Bsp29_LoadStructLump( file, lumpInfo[BSP29_LUMP_MODELS], BSP29_LUMP_MODELS, models );
	if ( !ok ) {
		Clear();
		return false;
	}

	// the texture lump with the embedded miptex data, parsed in place
	{
		const bsp29LumpInfo_t &info = lumpInfo[BSP29_LUMP_TEXTURES];
		textureData.SetNum( info.fileLen );
		if ( info.fileLen > 0 ) {
			memcpy( textureData.Ptr(), file + info.fileOfs, info.fileLen );
		}
		if ( !textures.Parse( textureData.Ptr(), textureData.Num() ) ) {
			Clear();
			return false;
		}
	}

	// the visibility lump is loaded as is
	{
		const bsp29LumpInfo_t &info = lumpInfo[BSP29_LUMP_VISIBILITY];
		visibility.SetNum( info.fileLen );
		if ( info.fileLen > 0 ) {
			memcpy( visibility.Ptr(), file + info.fileOfs, info.fileLen );
		}
	}

	// the stock collision and lighting lumps are not parsed, only kept for writing the file back
	{
		const bsp29LumpInfo_t &clip = lumpInfo[BSP29_LUMP_CLIPNODES];
		rawClipNodes.SetNum( clip.fileLen );
		if ( clip.fileLen > 0 ) {
			memcpy( rawClipNodes.Ptr(), file + clip.fileOfs, clip.fileLen );
		}
		const bsp29LumpInfo_t &light = lumpInfo[BSP29_LUMP_LIGHTING];
		rawLighting.SetNum( light.fileLen );
		if ( light.fileLen > 0 ) {
			memcpy( rawLighting.Ptr(), file + light.fileOfs, light.fileLen );
		}
	}

	if ( !Validate() ) {
		Clear();
		return false;
	}

	if ( !ReadBspxDirectory( file, length ) ) {
		Clear();
		return false;
	}

	ParseEntities();

	name = debugName;
	return true;
}

/*
================
idBsp29::Validate

Checks every index so nothing that walks the lumps can leave them.
================
*/
bool idBsp29::Validate() const {
	const int numPlanes = planes.Num();
	const int numNodes = nodes.Num();
	const int numLeafs = leafs.Num();
	const int numFaces = faces.Num();
	const int numEdges = edges.Num();

	if ( models.Num() < 1 ) {
		common->Warning( "idBsp29: the map has no models" );
		return false;
	}
	if ( numLeafs < 1 ) {
		common->Warning( "idBsp29: the map has no leafs" );
		return false;
	}

	for ( int i = 0; i < numNodes; i++ ) {
		const bsp29Node_t &node = nodes[i];
		if ( node.planeNum < 0 || node.planeNum >= numPlanes ) {
			common->Warning( "idBsp29: node %d has a bad plane number %d", i, node.planeNum );
			return false;
		}
		for ( int j = 0; j < 2; j++ ) {
			const int child = node.children[j];
			if ( ( child >= 0 && child >= numNodes ) || ( child < 0 && -1 - child >= numLeafs ) ) {
				common->Warning( "idBsp29: node %d has a bad child %d", i, child );
				return false;
			}
		}
		if ( (int)node.firstFace + (int)node.numFaces > numFaces ) {
			common->Warning( "idBsp29: node %d has faces outside of the face lump", i );
			return false;
		}
	}

	for ( int i = 0; i < numLeafs; i++ ) {
		const bsp29Leaf_t &leaf = leafs[i];
		if ( (int)leaf.firstMarkSurface + (int)leaf.numMarkSurfaces > markSurfaces.Num() ) {
			common->Warning( "idBsp29: leaf %d has mark surfaces outside of the lump", i );
			return false;
		}
	}

	for ( int i = 0; i < markSurfaces.Num(); i++ ) {
		if ( markSurfaces[i] >= numFaces ) {
			common->Warning( "idBsp29: mark surface %d references the bad face %d", i, markSurfaces[i] );
			return false;
		}
	}

	for ( int i = 0; i < numFaces; i++ ) {
		const bsp29Face_t &face = faces[i];
		if ( face.planeNum < 0 || face.planeNum >= numPlanes ) {
			common->Warning( "idBsp29: face %d has a bad plane number %d", i, face.planeNum );
			return false;
		}
		if ( face.side != 0 && face.side != 1 ) {
			common->Warning( "idBsp29: face %d has a bad side %d", i, face.side );
			return false;
		}
		if ( face.firstEdge < 0 || face.numEdges < 0 || (int64)face.firstEdge + (int64)face.numEdges > (int64)surfEdges.Num() ) {
			common->Warning( "idBsp29: face %d has edges outside of the surface edge lump", i );
			return false;
		}
		if ( face.texInfo < 0 || face.texInfo >= texInfo.Num() ) {
			common->Warning( "idBsp29: face %d has a bad texinfo %d", i, face.texInfo );
			return false;
		}
	}

	for ( int i = 0; i < texInfo.Num(); i++ ) {
		if ( texInfo[i].miptex < 0 || texInfo[i].miptex >= textures.Num() ) {
			common->Warning( "idBsp29: texinfo %d has a bad texture number %d", i, texInfo[i].miptex );
			return false;
		}
	}

	for ( int i = 0; i < surfEdges.Num(); i++ ) {
		const int edge = surfEdges[i];
		if ( edge <= -numEdges || edge >= numEdges ) {
			common->Warning( "idBsp29: surface edge %d references the bad edge %d", i, edge );
			return false;
		}
	}

	for ( int i = 0; i < numEdges; i++ ) {
		if ( edges[i].v[0] >= vertexes.Num() || edges[i].v[1] >= vertexes.Num() ) {
			common->Warning( "idBsp29: edge %d references a bad vertex", i );
			return false;
		}
	}

	for ( int i = 0; i < models.Num(); i++ ) {
		const bsp29Model_t &model = models[i];
		const int head = model.headNode[0];
		if ( ( head >= 0 && head >= numNodes ) || ( head < 0 && -1 - head >= numLeafs ) ) {
			common->Warning( "idBsp29: model %d has a bad head node %d", i, head );
			return false;
		}
		if ( model.firstFace < 0 || model.numFaces < 0 || (int64)model.firstFace + (int64)model.numFaces > (int64)numFaces ) {
			common->Warning( "idBsp29: model %d has faces outside of the face lump", i );
			return false;
		}
	}

	return true;
}

/*
================
idBsp29::ReadBspxDirectory

The directory follows the last lump, 4 byte aligned. A damaged directory is
reported and ignored, the stock lumps stay usable.
================
*/
bool idBsp29::ReadBspxDirectory( const byte *file, int length ) {
	int64 lumpEnd = BSP29_HEADER_SIZE;
	for ( int i = 0; i < BSP29_HEADER_LUMPS; i++ ) {
		const int64 end = (int64)lumpInfo[i].fileOfs + (int64)lumpInfo[i].fileLen;
		if ( end > lumpEnd ) {
			lumpEnd = end;
		}
	}

	const int64 dirPos = ( lumpEnd + 3 ) & ~(int64)3;
	if ( dirPos + 8 > (int64)length || memcmp( file + dirPos, BSPX_IDENT, 4 ) != 0 ) {
		return true;
	}

	const int numLumps = Bsp29_ReadInt( file + dirPos + 4 );
	if ( numLumps < 0 || numLumps > BSPX_MAX_LUMPS || dirPos + 8 + (int64)numLumps * BSPX_DIR_ENTRY_SIZE > (int64)length ) {
		common->Warning( "idBsp29: the BSPX directory is damaged and ignored" );
		return true;
	}

	for ( int i = 0; i < numLumps; i++ ) {
		const byte *entry = file + dirPos + 8 + (int64)i * BSPX_DIR_ENTRY_SIZE;
		char lumpName[BSPX_MAX_LUMPNAME + 1];
		memcpy( lumpName, entry, BSPX_MAX_LUMPNAME );
		lumpName[BSPX_MAX_LUMPNAME] = '\0';
		const int ofs = Bsp29_ReadInt( entry + BSPX_MAX_LUMPNAME );
		const int len = Bsp29_ReadInt( entry + BSPX_MAX_LUMPNAME + 4 );
		if ( ofs < 0 || len < 0 || (int64)ofs + (int64)len > (int64)length ) {
			common->Warning( "idBsp29: the BSPX lump %s is outside of the file and ignored", lumpName );
			continue;
		}
		SetExtLump( lumpName, file + ofs, len );
	}

	return true;
}

/*
================
idBsp29::ParseEntities

Entity key/value pairs are kept as they are in the lump, the "model" "*n"
keys of brush entities reference the models lump.
================
*/
bool idBsp29::ParseEntities() {
	entities.Clear();

	idLexer src( LEXFL_NOSTRINGCONCAT | LEXFL_NOSTRINGESCAPECHARS | LEXFL_ALLOWPATHNAMES | LEXFL_NOFATALERRORS );
	if ( !src.LoadMemory( entityString.c_str(), entityString.Length(), "bsp entities" ) ) {
		return false;
	}

	idToken token;
	idToken key;
	while ( src.ReadToken( &token ) ) {
		if ( token != "{" ) {
			common->Warning( "idBsp29: found %s when expecting { in the entity lump", token.c_str() );
			return false;
		}
		idDict dict;
		while ( 1 ) {
			if ( !src.ReadToken( &key ) ) {
				common->Warning( "idBsp29: EOF without closing brace in the entity lump" );
				return false;
			}
			if ( key == "}" ) {
				break;
			}
			if ( !src.ReadToken( &token ) || token == "}" ) {
				common->Warning( "idBsp29: missing value for the key %s in the entity lump", key.c_str() );
				return false;
			}
			dict.Set( key.c_str(), token.c_str() );
		}
		entities.Append( dict );
	}
	return true;
}

/*
================
idBsp29::GetFacePoints
================
*/
bool idBsp29::GetFacePoints( int faceNum, idList<idVec3> &points ) const {
	points.Clear();
	if ( faceNum < 0 || faceNum >= faces.Num() ) {
		return false;
	}

	const bsp29Face_t &face = faces[faceNum];
	for ( int i = 0; i < face.numEdges; i++ ) {
		const int edgeNum = surfEdges[face.firstEdge + i];
		const bsp29Edge_t &edge = edges[ edgeNum >= 0 ? edgeNum : -edgeNum ];
		const bsp29Vertex_t &vertex = vertexes[ edgeNum >= 0 ? edge.v[0] : edge.v[1] ];
		points.Append( idVec3( vertex.point[0], vertex.point[1], vertex.point[2] ) );
	}
	return points.Num() >= 3;
}

/*
================
idBsp29::GetExtLumpName
================
*/
const char *idBsp29::GetExtLumpName( bspxLumpId_t id ) {
	if ( id < 0 || id >= BSPX_NUM_LUMPS ) {
		return "";
	}
	return bspxLumpNames[id];
}

/*
================
idBsp29::FindExtLump
================
*/
const bspxLump_t *idBsp29::FindExtLump( const char *lumpName ) const {
	for ( int i = 0; i < extLumps.Num(); i++ ) {
		if ( extLumps[i].name.Icmp( lumpName ) == 0 ) {
			return &extLumps[i];
		}
	}
	return NULL;
}

/*
================
idBsp29::SetExtLump
================
*/
void idBsp29::SetExtLump( const char *lumpName, const byte *source, int length ) {
	bspxLump_t *lump = NULL;
	for ( int i = 0; i < extLumps.Num(); i++ ) {
		if ( extLumps[i].name.Icmp( lumpName ) == 0 ) {
			lump = &extLumps[i];
			break;
		}
	}
	if ( lump == NULL ) {
		bspxLump_t added;
		added.name = lumpName;
		lump = &extLumps[ extLumps.Append( added ) ];
	}

	lump->data.SetNum( length );
	if ( length > 0 ) {
		memcpy( lump->data.Ptr(), source, length );
	}
}

/*
================
idBsp29::RemoveExtLump
================
*/
bool idBsp29::RemoveExtLump( const char *lumpName ) {
	for ( int i = 0; i < extLumps.Num(); i++ ) {
		if ( extLumps[i].name.Icmp( lumpName ) == 0 ) {
			extLumps.RemoveIndex( i );
			return true;
		}
	}
	return false;
}

/*
================
idBsp29::GetFileRef
================
*/
bool idBsp29::GetFileRef( bspxLumpId_t id, bspxFileRef_t &ref ) const {
	const bspxLump_t *lump = FindExtLump( GetExtLumpName( id ) );
	if ( lump == NULL || lump->data.Num() != (int)sizeof( bspxFileRef_t ) ) {
		return false;
	}

	const byte *p = lump->data.Ptr();
	ref.version = Bsp29_ReadInt( p );
	ref.checksum = (unsigned int)Bsp29_ReadInt( p + 4 );
	ref.fileLength = Bsp29_ReadInt( p + 8 );
	memcpy( ref.name, p + 12, BSPX_FILEREF_NAME_SIZE );
	ref.name[BSPX_FILEREF_NAME_SIZE - 1] = '\0';
	return ref.version == BSPX_FILEREF_VERSION;
}

/*
================
idBsp29::SetFileRef
================
*/
void idBsp29::SetFileRef( bspxLumpId_t id, const char *fileName, const byte *fileData, int fileLength ) {
	bspxFileRef_t ref;
	memset( &ref, 0, sizeof( ref ) );
	ref.version = BSPX_FILEREF_VERSION;
	ref.checksum = CRC32_BlockChecksum( fileData, fileLength );
	ref.fileLength = fileLength;
	idStr::Copynz( ref.name, fileName, sizeof( ref.name ) );

	idList<byte> bytes;
	Bsp29_AppendInt( bytes, ref.version );
	Bsp29_AppendInt( bytes, (int)ref.checksum );
	Bsp29_AppendInt( bytes, ref.fileLength );
	Bsp29_AppendBytes( bytes, ref.name, BSPX_FILEREF_NAME_SIZE );
	SetExtLump( GetExtLumpName( id ), bytes.Ptr(), bytes.Num() );
}

/*
================
idBsp29::CheckFileRef
================
*/
bspxRefState_t idBsp29::CheckFileRef( bspxLumpId_t id ) const {
	bspxFileRef_t ref;
	if ( !GetFileRef( id, ref ) ) {
		return BSPX_REF_NONE;
	}

	byte *buffer = NULL;
	int length = fileSystem->ReadFile( ref.name, (void **)&buffer );
	if ( buffer == NULL || length < 0 ) {
		if ( buffer != NULL ) {
			fileSystem->FreeFile( buffer );
		}
		return BSPX_REF_FILE_MISSING;
	}

	bool same = ( length == ref.fileLength ) && ( CRC32_BlockChecksum( buffer, length ) == ref.checksum );
	if ( buffer != NULL ) {
		fileSystem->FreeFile( buffer );
	}
	return same ? BSPX_REF_OK : BSPX_REF_STALE;
}

/*
================
idBsp29::GetLighting
================
*/
const byte *idBsp29::GetLighting( int &length ) const {
	const bspxLump_t *lump = FindExtLump( GetExtLumpName( BSPX_LUMP_LIGHTING ) );
	if ( lump == NULL ) {
		length = 0;
		return NULL;
	}
	length = lump->data.Num();
	return lump->data.Ptr();
}

/*
================
idBsp29::Write

The stock lumps are written in order, 4 byte aligned. The skipped lumps are
copied raw. The BSPX directory is appended when there are extension lumps, its
lump data follows the directory.
================
*/
bool idBsp29::Write( idFile *file ) const {
	if ( file == NULL || !IsLoaded() ) {
		return false;
	}

	idList<byte> lumpData[BSP29_HEADER_LUMPS];

	// the entity lump is written back as it was read, with its terminating null
	Bsp29_AppendBytes( lumpData[BSP29_LUMP_ENTITIES], entityString.c_str(), entityString.Length() + 1 );
	Bsp29_SerializeStructs( lumpData[BSP29_LUMP_PLANES], planes );
	lumpData[BSP29_LUMP_TEXTURES] = textureData;
	Bsp29_SerializeStructs( lumpData[BSP29_LUMP_VERTEXES], vertexes );
	lumpData[BSP29_LUMP_VISIBILITY] = visibility;
	Bsp29_SerializeStructs( lumpData[BSP29_LUMP_NODES], nodes );
	Bsp29_SerializeStructs( lumpData[BSP29_LUMP_TEXINFO], texInfo );
	Bsp29_SerializeStructs( lumpData[BSP29_LUMP_FACES], faces );
	lumpData[BSP29_LUMP_LIGHTING] = rawLighting;
	lumpData[BSP29_LUMP_CLIPNODES] = rawClipNodes;
	Bsp29_SerializeStructs( lumpData[BSP29_LUMP_LEAFS], leafs );
	Bsp29_SerializeStructs( lumpData[BSP29_LUMP_MARKSURFACES], markSurfaces );
	Bsp29_SerializeStructs( lumpData[BSP29_LUMP_EDGES], edges );
	Bsp29_SerializeStructs( lumpData[BSP29_LUMP_SURFEDGES], surfEdges );
	Bsp29_SerializeStructs( lumpData[BSP29_LUMP_MODELS], models );

	idList<byte> out;
	out.SetNum( BSP29_HEADER_SIZE );
	memset( out.Ptr(), 0, BSP29_HEADER_SIZE );

	int tableOfs[BSP29_HEADER_LUMPS];
	for ( int i = 0; i < BSP29_HEADER_LUMPS; i++ ) {
		Bsp29_Pad4( out );
		tableOfs[i] = out.Num();
		Bsp29_AppendBytes( out, lumpData[i].Ptr(), lumpData[i].Num() );
	}

	if ( extLumps.Num() > 0 ) {
		Bsp29_Pad4( out );
		const int dirSize = 8 + extLumps.Num() * BSPX_DIR_ENTRY_SIZE;
		const int dirPos = out.Num();
		int dataPos = dirPos + dirSize;

		Bsp29_AppendBytes( out, BSPX_IDENT, 4 );
		Bsp29_AppendInt( out, extLumps.Num() );
		for ( int i = 0; i < extLumps.Num(); i++ ) {
			char lumpName[BSPX_MAX_LUMPNAME];
			memset( lumpName, 0, sizeof( lumpName ) );
			idStr::Copynz( lumpName, extLumps[i].name.c_str(), sizeof( lumpName ) );
			Bsp29_AppendBytes( out, lumpName, BSPX_MAX_LUMPNAME );
			dataPos = ( dataPos + 3 ) & ~3;
			Bsp29_AppendInt( out, dataPos );
			Bsp29_AppendInt( out, extLumps[i].data.Num() );
			dataPos += extLumps[i].data.Num();
		}
		for ( int i = 0; i < extLumps.Num(); i++ ) {
			Bsp29_Pad4( out );
			Bsp29_AppendBytes( out, extLumps[i].data.Ptr(), extLumps[i].data.Num() );
		}
	}

	// the header, written last because the lump offsets are known now
	idList<byte> header;
	Bsp29_AppendInt( header, BSP29_VERSION );
	for ( int i = 0; i < BSP29_HEADER_LUMPS; i++ ) {
		Bsp29_AppendInt( header, tableOfs[i] );
		Bsp29_AppendInt( header, lumpData[i].Num() );
	}
	memcpy( out.Ptr(), header.Ptr(), BSP29_HEADER_SIZE );

	return file->Write( out.Ptr(), out.Num() ) == out.Num();
}
