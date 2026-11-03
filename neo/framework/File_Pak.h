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

#ifndef __FILE_PAK_H__
#define __FILE_PAK_H__

/*
==============================================================

  Container for the classic id Software .pak archive used by
  Quake and Quake II, based off idZipContainer and
  idResourceContainer. The on-disk layout is documented in the
  GPL Quake II 3.21 release vendored under references/quake2.

==============================================================
*/

// the .pak format stores file names in fixed 56 byte fields
#define MAX_PAK_FILE_NAME		56
// one directory entry is the 56 byte name plus offset and length
#define PAK_ENTRY_SIZE			64

class idPackContainer;

class idFile_InPak : public idFile {
	friend class	idPackContainer;
  public:
	idFile_InPak();
	virtual					~idFile_InPak();

	virtual const char *	GetName() const { return name.c_str(); }
	virtual const char *	GetFullPath() const { return fullPath.c_str(); }
	virtual int				Read( void *buffer, int len );
	virtual int				Write( const void *buffer, int len );
	virtual int				Length() const { return fileSize; }
	virtual ID_TIME_T		Timestamp() const { return 0; }
	virtual int				Tell() const { return internalFilePos; }
	virtual void			ForceFlush();
	virtual void			Flush();
	virtual int				Seek( int offset, fsOrigin_t origin );

  private:
	idStr					name;				// name of the file relative to the search path
	idStr					fullPath;			// full file path including the pak file name
	int						filePos;			// offset of the file inside the pak
	int						fileSize;			// size of the file
	int						internalFilePos;	// read position inside the file
	idFile *				handle;				// independent OS handle into the pak
};

class idPackCacheEntry {
  public:
	idPackCacheEntry() {
		Clear();
	}
	void Clear() {
		filename.Empty();
		offset = 0;
		length = 0;
		owner = NULL;
	}

	// part of the .pak file format
	idStrStatic< MAX_PAK_FILE_NAME + 1 >	filename;
	int						offset;			// from the start of the pak file
	int						length;			// .pak files never compress their contents

	// helpers only in memory
	idPackContainer *owner;
};

class idPackContainer {
	friend class	idFileSystemLocal;
  public:
	idPackContainer() {
		checksum = 0;
		numFileResources = 0;
	}
	~idPackContainer() {
		cacheTable.Clear();
	}
	bool Init( const char *fileName );
	idFile_InPak *OpenFile( const idPackCacheEntry &rt, const char *relativePath );

	const char *GetFileName() const {
		return fileName.c_str();
	}

	int GetNumFileResources() const {
		return numFileResources;
	}

	int GetChecksum() const {
		return checksum;
	}
  private:
	idStrStatic< 256 >	fileName;			// full OS path to the pak
	int					checksum;
	int					numFileResources;	// number of files in this container
	idList< idPackCacheEntry, TAG_RESOURCE>	cacheTable;
	idHashIndex			cacheHash;
};


#endif /* !__FILE_PAK_H__ */
