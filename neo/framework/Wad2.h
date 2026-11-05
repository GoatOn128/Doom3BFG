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

#ifndef __WAD2_H__
#define __WAD2_H__

/*
===============================================================================

	Quake WAD2 containers and Quake miptex textures.

	The container layout, the lump types and the miptex layout come from the
	Quake 1 GPL release (references/quake/WinQuake/wad.h, wad.c and
	bspfile.h, Copyright (C) 1996-1997 Id Software, Inc., GPLv2 or later).

	Lump names are compared case insensitive. LZSS compressed lumps (the
	compression byte is CMP_LZSS) are not supported, the Quake source has no
	decompressor either and no stock wad uses them; such lumps load as
	unavailable data.

===============================================================================
*/

#define WAD2_IDENT			"WAD2"
#define WAD2_HEADER_SIZE	12			// char id[4], int numlumps, int infotableofs
#define WAD2_LUMPINFO_SIZE	32			// int filepos, disksize, size; char type, compression, pad[2]; char name[16]
#define WAD2_MAX_LUMPNAME	16
#define WAD2_MIPLEVELS		4
#define WAD2_MIPTEX_HEADER	40			// char name[16]; unsigned width, height; unsigned offsets[4]
#define WAD2_MAX_TEXTURE_SIZE	4096

#define WAD2_CMP_NONE		0
#define WAD2_CMP_LZSS		1

#define WAD2_TYP_NONE		0
#define WAD2_TYP_LABEL		1
#define WAD2_TYP_PALETTE	64
#define WAD2_TYP_QTEX		65
#define WAD2_TYP_QPIC		66
#define WAD2_TYP_SOUND		67
#define WAD2_TYP_MIPTEX		68

#define WAD2_PALETTE_SIZE	768			// 256 RGB triplets, the raw contents of gfx/palette.lmp
#define WAD2_TRANSPARENT_INDEX	255

struct wad2Lump_t {
	int				filePos;
	int				diskSize;
	int				size;				// uncompressed size
	int				type;
	int				compression;
	char			name[WAD2_MAX_LUMPNAME + 1];	// lowercase, always null terminated
};

// A miptex as found in a wad lump or in the BSP texture lump. The mip level pointers
// reference the buffer the miptex was parsed from, which has to outlive the struct.
struct wad2MipTex_t {
	char			name[WAD2_MAX_LUMPNAME + 1];	// lowercase, always null terminated
	int				width;
	int				height;
	const byte *	mip[WAD2_MIPLEVELS];			// NULL when the pixels are not stored in the miptex
	bool			HasPixels() const { return mip[0] != NULL; }
};

class idWad2 {
public:
						idWad2();
						~idWad2();

	void				Clear();

						// the file is read through the file system, so it can sit inside a pak
	bool				LoadFromFile( const char *fileName );
						// the data is copied
	bool				LoadFromMemory( const byte *data, int length, const char *debugName );

	const char *		GetName() const { return name.c_str(); }
	int					NumLumps() const { return lumps.Num(); }
	const wad2Lump_t &	GetLump( int index ) const { return lumps[index]; }

						// returns the lump index or -1, type -1 matches every type
	int					FindLump( const char *lumpName, int type = -1 ) const;

						// NULL for compressed lumps, the size is wad2Lump_t::size
	const byte *		GetLumpData( int index ) const;

						// fills the miptex of a TYP_MIPTEX lump, the lump stays owned by the wad
	bool				GetMipTex( int index, wad2MipTex_t &mipTex ) const;

						// parses a miptex_t at the start of data, used for wad lumps and the BSP texture lump.
						// Pixel pointers are only set when all four mip levels are inside length.
	static bool			ParseMipTex( const byte *data, int length, wad2MipTex_t &mipTex );

						// reads gfx/palette.lmp through the file system, cached after the first call
	static bool			LoadPalette( byte palette[WAD2_PALETTE_SIZE] );

						// Decodes the first mip level to RGBA. Index 255 becomes transparent when
						// transparent255 is set, otherwise alpha is 255.
	static bool			DecodeMipTex( const wad2MipTex_t &mipTex, const byte palette[WAD2_PALETTE_SIZE], bool transparent255, idList<byte> &rgba );

						// lowercases and null terminates a 16 byte lump name field
	static void			CleanupName( const char *in, char out[WAD2_MAX_LUMPNAME + 1] );

private:
	idStr				name;
	idList<byte>		data;
	idList<wad2Lump_t>	lumps;
};

/*
===============================================================================

	The texture lump of a BSP: dmiptexlump_t followed by the miptex data.

	Textures stored in an external wad have no pixels in the BSP (offset table
	of zero, or a dataofs of -1); ResolveExternal() fills those from a wad.

===============================================================================
*/

class idWad2MipTexLump {
public:
						idWad2MipTexLump();

	void				Clear();

						// data has to stay alive as long as the textures are used
	bool				Parse( const byte *data, int length );

	int					Num() const { return textures.Num(); }
						// textures with dataofs == -1 are listed as empty entries so that the BSP texinfo indices stay valid
	const wad2MipTex_t &Get( int index ) const { return textures[index]; }
	int					Find( const char *textureName ) const;
	bool				IsValid( int index ) const { return index >= 0 && index < textures.Num() && textures[index].width > 0; }

						// returns the number of textures that got pixels (or at least a size) from the wad
	int					ResolveExternal( const idWad2 &wad );

private:
	idList<wad2MipTex_t>	textures;
};

#endif /* !__WAD2_H__ */
