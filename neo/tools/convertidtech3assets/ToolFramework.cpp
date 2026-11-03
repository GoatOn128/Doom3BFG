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

If you have questions concerning the license or the applicable additional terms, you may contact in writing to id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#include "precompiled.h"
#pragma hdrstop

/*
   The file system drags in a few framework pieces that the sys/stub
   harness does not provide. The engine defines them in files the stub
   replaces (Common.cpp, EventLoop.cpp, sys_local.cpp, win_main.cpp),
   which cannot be linked here because they also define the globals the
   stub owns. This file provides the minimal versions the tool needs.
*/

// basic millisecond timing for idLib (engine: win_main.cpp)
int Sys_Milliseconds() {
	return GetTickCount();
}

// single-language versions (engine: sys_local.cpp builds the list from
// the installed string files; a conversion tool only needs english)
int Sys_NumLangs() {
	return 1;
}

const char * Sys_Lang( int idx ) {
	return ( idx == 0 ) ? ID_LANG_ENGLISH : "";
}

// journaling is always off in a batch tool (engine: EventLoop.cpp reads
// the com_journal cvar; the stub hosts no event loop and the file system
// NULL-checks the event loop pointer before journalling)
int idEventLoop::JournalLevel() const {
	return 0;
}

// the engine defines these in Common.cpp, which the stub replaces
idCVar com_version( "si_version", "convertidtech3assets", CVAR_SYSTEM | CVAR_ROM | CVAR_SERVERINFO, "engine version" );
idCVar com_productionMode( "com_productionMode", "0", CVAR_SYSTEM | CVAR_BOOL, "0 - no special behavior, 1 - building a production build, 2 - running a production build" );
