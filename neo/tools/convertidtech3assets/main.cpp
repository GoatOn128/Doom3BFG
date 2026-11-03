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

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 BFG Edition Source Code.  If not, please request a copy in writing to id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

If you have questions concerning this license or the applicable additional terms, you may contact in writing to id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#include "precompiled.h"
#pragma hdrstop

#include "sys/stub/sys_stub.h"
#include "Q3ShaderConverter.h"

/*
=================
main

convertidtech3assets <path to the Quake 3 install> [gameDir]

Converts the id Tech 3 .shader scripts of the given game directory into
Doom 3 BFG .mtr materials under materials/q3. The file system is pointed
at the install with fs_basepath / fs_savepath / fs_game before the tool
framework initializes, so the shader files are read straight out of the
Quake 3 pk3 files.
=================
*/
int main( int argc, char *argv[] ) {
	if ( argc != 2 && argc != 3 ) {
		common->Printf( "^1usage: convertidtech3assets <path to the Quake 3 install> [gameDir e.g. baseq3]^7\n" );
		return 0;
	}

	idStr gameDir = "baseq3";
	if ( argc == 3 ) {
		gameDir = argv[2];
	}

	// The file system mounts its search paths during Tool_InitFramework;
	// setting the path cvars before RegisterStaticVars keeps them in place.
	cvarSystem->SetCVarString( "fs_basepath", argv[1] );
	cvarSystem->SetCVarString( "fs_savepath", argv[1] );
	cvarSystem->SetCVarString( "fs_game", gameDir.c_str() );

	Tool_InitFramework();

	Q3ShaderConverter converter;
	if ( !converter.ConvertShaders( "scripts", ".shader", "materials/q3" ) ) {
		common->Printf( "^1no shaders converted^7\n" );
	} else {
		common->Printf( "^2converted %d shader%s: %d stage%s kept, %d stage%s dropped^7\n",
			converter.numShaders, converter.numShaders == 1 ? "" : "s",
			converter.numStages, converter.numStages == 1 ? "" : "s",
			converter.numStagesDropped, converter.numStagesDropped == 1 ? "" : "s" );
		if ( converter.numWarnings > 0 ) {
			common->Printf( "^3%d directive%s had no Doom 3 equivalent and were kept as comments^7\n",
				converter.numWarnings, converter.numWarnings == 1 ? "" : "s" );
		}
		if ( converter.needWaveTables ) {
			common->Printf( "^5wrote the wave tables to materials/q3/_q3waves.mtr^7\n" );
		}
	}

	Tool_ShutdownFramework();
	return 0;
}
