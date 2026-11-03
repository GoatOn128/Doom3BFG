/*
===========================================================================

Doom 3 BFG Edition GPL Source Code
Copyright (C) 1993-2012 id Software LLC, a ZeniMax Media company
Copyright (C) 2024 Robert Beckebans

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

#include "File_Pak.h"

/*
================================================================================================

idPackContainer

================================================================================================
*/

// a pak file starts with the "PACK" id followed by the directory offset and size
static const char *PAK_HEADER_ID = "PACK";
static const int PAK_HEADER_SIZE = 12;
// sanity limit, Quake capped its paks at 2048 entries and Quake II has no fixed cap
static const int PAK_MAX_FILES = 65536;

/*
========================
idPackContainer::Init
========================
*/
bool idPackContainer::Init( const char *_fileName ) {
	idFileLocal f = fileSystem->OpenExplicitFileRead( _fileName );
	if( !f ) {
		return false;
	}

	const int fileLength = f->Length();

	char headerId[4] = { 0, 0, 0, 0 };
	int dirOffset = 0;
	int dirLength = 0;
	if( f->Read( headerId, 4 ) != 4 || memcmp( headerId, PAK_HEADER_ID, 4 ) != 0 ||
			f->ReadInt( dirOffset ) != sizeof( dirOffset ) || f->ReadInt( dirLength ) != sizeof( dirLength ) ) {
		idLib::Warning( "Unable to open pak file %s, bad header", _fileName );
		return false;
	}

	if( dirOffset < PAK_HEADER_SIZE || dirLength <= 0 || ( dirLength % PAK_ENTRY_SIZE ) != 0 ) {
		idLib::Warning( "Unable to open pak file %s, bad directory layout", _fileName );
		return false;
	}

	const int numFiles = dirLength / PAK_ENTRY_SIZE;
	if( numFiles > PAK_MAX_FILES || dirOffset + dirLength > fileLength ) {
		idLib::Warning( "Unable to open pak file %s, directory out of range", _fileName );
		return false;
	}

	// read the whole directory in one go so the checksum covers the raw table
	// just like the zip containers checksum their contents
	byte *dirData = ( byte * )Mem_Alloc( dirLength, TAG_IDFILE );
	f->Seek( dirOffset, FS_SEEK_SET );
	if( f->Read( dirData, dirLength ) != dirLength ) {
		Mem_Free( dirData );
		idLib::Warning( "Unable to open pak file %s, short directory read", _fileName );
		return false;
	}

	checksum = LittleInt( MD4_BlockChecksum( dirData, dirLength ) );

	fileName = _fileName;
	numFileResources = numFiles;
	cacheTable.SetNum( numFiles );

	for( int i = 0; i < numFiles; i++ ) {
		const byte *entry = dirData + i * PAK_ENTRY_SIZE;

		char name[MAX_PAK_FILE_NAME + 1];
		memcpy( name, entry, MAX_PAK_FILE_NAME );
		name[MAX_PAK_FILE_NAME] = '\0';

		int entryOffset = 0;
		int entryLength = 0;
		memcpy( &entryOffset, entry + MAX_PAK_FILE_NAME, sizeof( int ) );
		memcpy( &entryLength, entry + MAX_PAK_FILE_NAME + 4, sizeof( int ) );
		entryOffset = LittleInt( entryOffset );
		entryLength = LittleInt( entryLength );

		// drop entries that point outside the pak instead of dying on them later
		if( entryOffset < 0 || entryLength < 0 || entryOffset + entryLength > fileLength ) {
			idLib::Warning( "pak file %s has a bad entry '%s', skipped", _fileName, name );
			continue;
		}

		idPackCacheEntry &rt = cacheTable[i];
		rt.filename = name;
		rt.filename.BackSlashesToSlashes();
		// the filesystem is case insensitive everywhere so store the names lowercased
		rt.filename.ToLower();
		rt.offset = entryOffset;
		rt.length = entryLength;
		rt.owner = this;

		cacheHash.Add( cacheHash.GenerateKey( rt.filename, false ), i );
	}

	Mem_Free( dirData );

	return true;
}

/*
===========
idPackContainer::OpenFile
===========
*/
idFile_InPak *idPackContainer::OpenFile( const idPackCacheEntry &rt, const char *relativePath ) {
	// every open file gets its own handle into the pak so concurrent readers
	// cannot race each other on the seek position
	idFile *pakHandle = fileSystem->OpenExplicitFileRead( fileName );
	if( pakHandle == NULL ) {
		idLib::Warning( "Couldn't reopen pak file %s", fileName.c_str() );
		return NULL;
	}

	idFile_InPak *file = new idFile_InPak();
	file->handle = pakHandle;
	file->name = relativePath;
	file->fullPath = fileName + "/" + relativePath;
	file->filePos = rt.offset;
	file->fileSize = rt.length;
	file->internalFilePos = 0;

	return file;
}

/*
================================================================================================

idFile_InPak

================================================================================================
*/

/*
=================
idFile_InPak::idFile_InPak
=================
*/
idFile_InPak::idFile_InPak() {
	filePos = 0;
	fileSize = 0;
	internalFilePos = 0;
	handle = NULL;
}

/*
=================
idFile_InPak::~idFile_InPak
=================
*/
idFile_InPak::~idFile_InPak() {
	delete handle;
}

/*
=================
idFile_InPak::Read
=================
*/
int idFile_InPak::Read( void *buffer, int len ) {
	if( handle == NULL ) {
		return 0;
	}

	if( internalFilePos + len > fileSize ) {
		len = fileSize - internalFilePos;
	}

	if( len <= 0 ) {
		return 0;
	}

	handle->Seek( filePos + internalFilePos, FS_SEEK_SET );
	int read = handle->Read( buffer, len );
	internalFilePos += read;

	return read;
}

/*
=================
idFile_InPak::Write
=================
*/
int idFile_InPak::Write( const void *buffer, int len ) {
	common->FatalError( "idFile_InPak::Write: cannot write to the packed file %s", name.c_str() );
	return 0;
}

/*
=================
idFile_InPak::ForceFlush
=================
*/
void idFile_InPak::ForceFlush() {
	common->FatalError( "idFile_InPak::ForceFlush: cannot flush the packed file %s", name.c_str() );
}

/*
=================
idFile_InPak::Flush
=================
*/
void idFile_InPak::Flush() {
	common->FatalError( "idFile_InPak::Flush: cannot flush the packed file %s", name.c_str() );
}

/*
=================
idFile_InPak::Seek

  returns zero on success and -1 on failure
=================
*/
int idFile_InPak::Seek( int offset, fsOrigin_t origin ) {
	int pos = 0;

	switch( origin ) {
		case FS_SEEK_SET: {
			pos = offset;
			break;
		}
		case FS_SEEK_CUR: {
			pos = internalFilePos + offset;
			break;
		}
		case FS_SEEK_END: {
			pos = fileSize - offset;
			break;
		}
		default: {
			common->FatalError( "idFile_InPak::Seek: bad origin for %s\n", name.c_str() );
			return -1;
		}
	}

	if( pos < 0 || pos > fileSize ) {
		return -1;
	}

	internalFilePos = pos;

	return 0;
}
