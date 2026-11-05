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

#include "Wad2.h"

#define WAD2_MAX_LUMPS		65536
#define WAD2_MAX_BSP_TEXTURES	65536

// all fields of the format are little endian
static int Wad2_ReadInt( const byte *p ) {
	return (int)( (unsigned int)p[0] | ( (unsigned int)p[1] << 8 ) | ( (unsigned int)p[2] << 16 ) | ( (unsigned int)p[3] << 24 ) );
}

/*
================
idWad2::CleanupName

W_CleanupName of the Quake source: lowercase and zero padded.
================
*/
void idWad2::CleanupName( const char *in, char out[WAD2_MAX_LUMPNAME + 1] ) {
	int i;
	for ( i = 0; i < WAD2_MAX_LUMPNAME; i++ ) {
		int c = (unsigned char)in[i];
		if ( c == 0 ) {
			break;
		}
		if ( c >= 'A' && c <= 'Z' ) {
			c += 'a' - 'A';
		}
		out[i] = (char)c;
	}
	for ( ; i <= WAD2_MAX_LUMPNAME; i++ ) {
		out[i] = 0;
	}
}

/*
================
idWad2::idWad2
================
*/
idWad2::idWad2() {
}

/*
================
idWad2::~idWad2
================
*/
idWad2::~idWad2() {
	Clear();
}

/*
================
idWad2::Clear
================
*/
void idWad2::Clear() {
	name.Clear();
	data.Clear();
	lumps.Clear();
}

/*
================
idWad2::LoadFromFile
================
*/
bool idWad2::LoadFromFile( const char *fileName ) {
	Clear();

	byte *buffer = NULL;
	int length = fileSystem->ReadFile( fileName, (void **)&buffer );
	if ( buffer == NULL || length <= 0 ) {
		if ( buffer != NULL ) {
			fileSystem->FreeFile( buffer );
		}
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
idWad2::LoadFromMemory
================
*/
bool idWad2::LoadFromMemory( const byte *source, int length, const char *debugName ) {
	Clear();

	if ( source == NULL || length < WAD2_HEADER_SIZE ) {
		common->Warning( "idWad2: %s is too short for a wad header", debugName );
		return false;
	}
	if ( memcmp( source, WAD2_IDENT, 4 ) != 0 ) {
		common->Warning( "idWad2: %s does not have the WAD2 id", debugName );
		return false;
	}

	const int numLumps = Wad2_ReadInt( source + 4 );
	const int tableOfs = Wad2_ReadInt( source + 8 );
	if ( numLumps < 0 || numLumps > WAD2_MAX_LUMPS ) {
		common->Warning( "idWad2: %s has a bad lump count %d", debugName, numLumps );
		return false;
	}
	if ( tableOfs < WAD2_HEADER_SIZE || (int64)tableOfs + (int64)numLumps * WAD2_LUMPINFO_SIZE > (int64)length ) {
		common->Warning( "idWad2: %s has a lump table outside of the file", debugName );
		return false;
	}

	name = debugName;
	data.SetNum( length );
	memcpy( data.Ptr(), source, length );

	lumps.SetNum( numLumps );
	const byte *info = data.Ptr() + tableOfs;
	for ( int i = 0; i < numLumps; i++, info += WAD2_LUMPINFO_SIZE ) {
		wad2Lump_t &lump = lumps[i];
		lump.filePos = Wad2_ReadInt( info );
		lump.diskSize = Wad2_ReadInt( info + 4 );
		lump.size = Wad2_ReadInt( info + 8 );
		lump.type = info[12];
		lump.compression = info[13];
		CleanupName( (const char *)info + 16, lump.name );
	}

	return true;
}

/*
================
idWad2::FindLump
================
*/
int idWad2::FindLump( const char *lumpName, int type ) const {
	char clean[WAD2_MAX_LUMPNAME + 1];
	CleanupName( lumpName, clean );

	for ( int i = 0; i < lumps.Num(); i++ ) {
		if ( type >= 0 && lumps[i].type != type ) {
			continue;
		}
		if ( strcmp( lumps[i].name, clean ) == 0 ) {
			return i;
		}
	}
	return -1;
}

/*
================
idWad2::GetLumpData
================
*/
const byte *idWad2::GetLumpData( int index ) const {
	if ( index < 0 || index >= lumps.Num() ) {
		return NULL;
	}
	const wad2Lump_t &lump = lumps[index];
	if ( lump.compression != WAD2_CMP_NONE ) {
		return NULL;
	}
	if ( lump.filePos < 0 || lump.diskSize < 0 || (int64)lump.filePos + (int64)lump.diskSize > (int64)data.Num() ) {
		return NULL;
	}
	return data.Ptr() + lump.filePos;
}

/*
================
idWad2::GetMipTex
================
*/
bool idWad2::GetMipTex( int index, wad2MipTex_t &mipTex ) const {
	if ( index < 0 || index >= lumps.Num() || lumps[index].type != WAD2_TYP_MIPTEX ) {
		return false;
	}
	const byte *lumpData = GetLumpData( index );
	if ( lumpData == NULL ) {
		return false;
	}
	if ( !ParseMipTex( lumpData, lumps[index].diskSize, mipTex ) ) {
		return false;
	}
	// the wad directory name is the one the lookups use
	idStr::Copynz( mipTex.name, lumps[index].name, sizeof( mipTex.name ) );
	return true;
}

/*
================
idWad2::ParseMipTex
================
*/
bool idWad2::ParseMipTex( const byte *source, int length, wad2MipTex_t &mipTex ) {
	memset( &mipTex, 0, sizeof( mipTex ) );

	if ( source == NULL || length < WAD2_MIPTEX_HEADER ) {
		return false;
	}

	CleanupName( (const char *)source, mipTex.name );

	const int width = Wad2_ReadInt( source + 16 );
	const int height = Wad2_ReadInt( source + 20 );
	if ( width <= 0 || height <= 0 || width > WAD2_MAX_TEXTURE_SIZE || height > WAD2_MAX_TEXTURE_SIZE ) {
		return false;
	}
	mipTex.width = width;
	mipTex.height = height;

	// a zero offset table is how a texture that lives in an external wad is stored
	for ( int level = 0; level < WAD2_MIPLEVELS; level++ ) {
		const int offset = Wad2_ReadInt( source + 24 + level * 4 );
		if ( offset < WAD2_MIPTEX_HEADER ) {
			continue;
		}
		const int w = Max( 1, width >> level );
		const int h = Max( 1, height >> level );
		if ( (int64)offset + (int64)w * (int64)h > (int64)length ) {
			continue;
		}
		mipTex.mip[level] = source + offset;
	}

	return true;
}

/*
================
idWad2::LoadPalette
================
*/
bool idWad2::LoadPalette( byte palette[WAD2_PALETTE_SIZE] ) {
	static byte		cachedPalette[WAD2_PALETTE_SIZE];
	static bool		checked = false;
	static bool		valid = false;

	if ( !checked ) {
		checked = true;
		byte *buffer = NULL;
		int length = fileSystem->ReadFile( "gfx/palette.lmp", (void **)&buffer );
		if ( buffer != NULL && length >= WAD2_PALETTE_SIZE ) {
			memcpy( cachedPalette, buffer, WAD2_PALETTE_SIZE );
			valid = true;
		}
		if ( buffer != NULL ) {
			fileSystem->FreeFile( buffer );
		}
		if ( !valid ) {
			common->Warning( "idWad2: couldn't read the Quake 1 palette from gfx/palette.lmp" );
		}
	}

	if ( valid ) {
		memcpy( palette, cachedPalette, WAD2_PALETTE_SIZE );
	}
	return valid;
}

/*
================
idWad2::DecodeMipTex
================
*/
bool idWad2::DecodeMipTex( const wad2MipTex_t &mipTex, const byte palette[WAD2_PALETTE_SIZE], bool transparent255, idList<byte> &rgba ) {
	if ( !mipTex.HasPixels() || mipTex.width <= 0 || mipTex.height <= 0 ) {
		return false;
	}

	const int numPixels = mipTex.width * mipTex.height;
	rgba.SetNum( numPixels * 4 );

	const byte *src = mipTex.mip[0];
	byte *dst = rgba.Ptr();
	for ( int i = 0; i < numPixels; i++, dst += 4 ) {
		const int index = src[i];
		dst[0] = palette[index * 3 + 0];
		dst[1] = palette[index * 3 + 1];
		dst[2] = palette[index * 3 + 2];
		dst[3] = ( transparent255 && index == WAD2_TRANSPARENT_INDEX ) ? 0 : 255;
	}
	return true;
}

/*
================
idWad2MipTexLump::idWad2MipTexLump
================
*/
idWad2MipTexLump::idWad2MipTexLump() {
}

/*
================
idWad2MipTexLump::Clear
================
*/
void idWad2MipTexLump::Clear() {
	textures.Clear();
}

/*
================
idWad2MipTexLump::Parse
================
*/
bool idWad2MipTexLump::Parse( const byte *source, int length ) {
	Clear();

	// an empty lump is a valid map without textures
	if ( source == NULL || length == 0 ) {
		return true;
	}
	if ( length < 4 ) {
		common->Warning( "idWad2MipTexLump: texture lump is too short" );
		return false;
	}

	const int num = Wad2_ReadInt( source );
	if ( num < 0 || num > WAD2_MAX_BSP_TEXTURES || 4 + (int64)num * 4 > (int64)length ) {
		common->Warning( "idWad2MipTexLump: bad texture count %d", num );
		return false;
	}

	textures.SetNum( num );
	int numBad = 0;
	for ( int i = 0; i < num; i++ ) {
		wad2MipTex_t &tex = textures[i];
		memset( &tex, 0, sizeof( tex ) );

		const int offset = Wad2_ReadInt( source + 4 + i * 4 );
		if ( offset == -1 ) {
			// missing in the map, left as an empty entry
			continue;
		}
		if ( offset < 0 || offset > length || !idWad2::ParseMipTex( source + offset, length - offset, tex ) ) {
			memset( &tex, 0, sizeof( tex ) );
			numBad++;
		}
	}
	if ( numBad > 0 ) {
		common->Warning( "idWad2MipTexLump: %d of %d textures are invalid", numBad, num );
	}

	return true;
}

/*
================
idWad2MipTexLump::Find
================
*/
int idWad2MipTexLump::Find( const char *textureName ) const {
	char clean[WAD2_MAX_LUMPNAME + 1];
	idWad2::CleanupName( textureName, clean );

	for ( int i = 0; i < textures.Num(); i++ ) {
		if ( textures[i].name[0] != '\0' && strcmp( textures[i].name, clean ) == 0 ) {
			return i;
		}
	}
	return -1;
}

/*
================
idWad2MipTexLump::ResolveExternal
================
*/
int idWad2MipTexLump::ResolveExternal( const idWad2 &wad ) {
	int numResolved = 0;

	for ( int i = 0; i < textures.Num(); i++ ) {
		wad2MipTex_t &tex = textures[i];
		if ( tex.name[0] == '\0' || tex.HasPixels() ) {
			continue;
		}
		const int lumpIndex = wad.FindLump( tex.name, WAD2_TYP_MIPTEX );
		if ( lumpIndex < 0 ) {
			continue;
		}
		wad2MipTex_t external;
		if ( wad.GetMipTex( lumpIndex, external ) && external.HasPixels() ) {
			tex = external;
			numResolved++;
		}
	}
	return numResolved;
}
