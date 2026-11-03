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

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 BFG Edition Source Code.  If not, please request a copy in writing from id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#include "precompiled.h"
#include "../sys/sys_local.h"
#pragma hdrstop

#include <cstdlib>		// styler.hpp uses std::getenv without including it
#include <memory>		// styler.hpp uses std::make_unique without including it

#ifdef _WIN32
#include <io.h>
#include <direct.h>
#endif

#include "styler.hpp"

idSession *			session = NULL;
idDeclManager *		declManager = NULL;
idEventLoop *		eventLoop = NULL;
idInputDevices *	inputDevice = NULL;
idJoystick *		joystick = NULL;
idSysPlatform *		platform = NULL;

/*
==============================================================

	idCommon

==============================================================
*/

#define TOOL_PRINT_MSG_SIZE	32048

// idlib color codes (Str.h): ^0 default, ^1 red, ^2 green, ^3 yellow,
// ^4 blue, ^5 cyan, ^6 orange, ^7 white, ^8 gray, ^9 black
void Tool_PrintQ3( std::ostream &os, const char *text ) {
	for ( const char *p = text; *p != '\0'; p++ ) {
		if ( p[0] == '^' && p[1] >= '0' && p[1] <= '9' ) {
			switch ( p[1] ) {
				case '0':	os << styler::Style::Reset;			break;
				case '1':	os << styler::Foreground::Red;		break;
				case '2':	os << styler::Foreground::Green;	break;
				case '3':	os << styler::Foreground::Yellow;	break;
				case '4':	os << styler::Foreground::Blue;		break;
				case '5':	os << styler::Foreground::Cyan;		break;
				case '6':	os << styler::ForegroundHI::Yellow;	break;
				case '7':	os << styler::Foreground::White;		break;
				case '8':	os << styler::ForegroundHI::Black;	break;
				case '9':	os << styler::Foreground::Black;		break;
			}
			p++;
		} else {
			os << *p;
		}
	}
	// never let a color bleed into later output
	os << styler::Style::Reset;
}

static void Tool_VPrintf( std::ostream &os, const char *prefix, const char *fmt, va_list argptr, bool newline ) {
	char buffer[TOOL_PRINT_MSG_SIZE];
	buffer[0] = '\0';
	idStr::vsnPrintf( buffer, sizeof( buffer ), fmt, argptr );
	os << prefix;
	Tool_PrintQ3( os, buffer );
	if ( newline ) {
		os << '\n';
	}
	os.flush();
}

class idCommonLocal : public idCommon {
public:
							idCommonLocal( void ) {}

	virtual void			Init( int argc, const char * const * argv, const char *cmdline ) {}
	virtual void			Shutdown( void ) {}
	virtual bool			IsShuttingDown( void ) const { return false; }
	virtual void			CreateMainMenu( void ) {}
	virtual void			Quit( void ) { exit( 0 ); }
	virtual bool			IsInitialized( void ) const { return true; }
	virtual void			Frame( void ) {}
	virtual void			UpdateScreen( bool captureToImage, bool releaseMouse ) {}
	virtual void			UpdateLevelLoadPacifier( void ) {}
	virtual void			StartupVariable( const char *match ) {}
	virtual void			InitTool( const toolFlag_t tool, const idDict *dict ) {}
	virtual void			ActivateTool( bool active ) {}
	virtual void			BeginRedirect( char *buffer, int buffersize, void (*flush)( const char * ) ) {}
	virtual void			EndRedirect( void ) {}
	virtual void			SetRefreshOnPrint( bool set ) {}
	virtual void			Printf( VERIFY_FORMAT_STRING const char *fmt, ... ) {
		va_list argptr;
		va_start( argptr, fmt );
		Tool_VPrintf( std::cout, "", fmt, argptr, false );
		va_end( argptr );
	}
	virtual void			VPrintf( const char *fmt, va_list arg ) { Tool_VPrintf( std::cout, "", fmt, arg, false ); }
	virtual void			DPrintf( VERIFY_FORMAT_STRING const char *fmt, ... ) {}
	virtual void			Warning( VERIFY_FORMAT_STRING const char *fmt, ... ) {
		va_list argptr;
		va_start( argptr, fmt );
		std::cout << styler::Foreground::Yellow;
		Tool_VPrintf( std::cout, "WARNING: ", fmt, argptr, true );
		va_end( argptr );
	}
	virtual void			DWarning( VERIFY_FORMAT_STRING const char *fmt, ... ) {}
	virtual void			PrintWarnings( void ) {}
	virtual void			ClearWarnings( const char *reason ) {}
	virtual void			Error( VERIFY_FORMAT_STRING const char *fmt, ... ) {
		va_list argptr;
		va_start( argptr, fmt );
		std::cout << styler::Foreground::Red;
		Tool_VPrintf( std::cout, "ERROR: ", fmt, argptr, true );
		va_end( argptr );
		exit( 0 );
	}
	virtual void			FatalError( VERIFY_FORMAT_STRING const char *fmt, ... ) {
		va_list argptr;
		va_start( argptr, fmt );
		std::cout << styler::Foreground::Red;
		Tool_VPrintf( std::cout, "FATAL ERROR: ", fmt, argptr, true );
		va_end( argptr );
		exit( 0 );
	}
	virtual const char *	KeysFromBinding( const char *bind ) { return NULL; }
	virtual const char *	BindingFromKey( const char *key ) { return NULL; }
	virtual int				ButtonState( int key ) { return 0; }
	virtual int				KeyState( int key ) { return 0; }
	virtual bool			IsMultiplayer( void ) { return false; }
	virtual bool			IsServer( void ) { return false; }
	virtual bool			IsClient( void ) { return false; }
	virtual bool			GetConsoleUsed( void ) { return false; }
	virtual int				GetSnapRate( void ) { return 50; }
	virtual void			NetReceiveReliable( int peer, int type, idBitMsg & msg ) {}
	virtual void			NetReceiveSnapshot( class idSnapShot & ss ) {}
	virtual void			NetReceiveUsercmds( int peer, idBitMsg & msg ) {}
	virtual bool			ProcessEvent( const sysEvent_t *event ) { return false; }
	virtual bool			LoadGame( const char *saveName ) { return false; }
	virtual bool			SaveGame( const char *saveName ) { return false; }
	virtual idDemoFile *	ReadDemo( void ) { return NULL; }
	virtual idDemoFile *	WriteDemo( void ) { return NULL; }
	virtual idGame *		Game( void ) { return NULL; }
	virtual idRenderWorld *	RW( void ) { return NULL; }
	virtual idSoundWorld *	SW( void ) { return NULL; }
	virtual idSoundWorld *	MenuSW( void ) { return NULL; }
	virtual idSession *		Session( void ) { return NULL; }
	virtual idCommonDialog &Dialog( void ) { return *(idCommonDialog *)NULL; }
	virtual void			OnSaveCompleted( idSaveLoadParms & parms ) {}
	virtual void			OnLoadCompleted( idSaveLoadParms & parms ) {}
	virtual void			OnLoadFilesCompleted( idSaveLoadParms & parms ) {}
	virtual void			OnEnumerationCompleted( idSaveLoadParms & parms ) {}
	virtual void			OnDeleteCompleted( idSaveLoadParms & parms ) {}
	virtual void			TriggerScreenWipe( const char *_wipeMaterial, bool hold ) {}
	virtual void			OnStartHosting( idMatchParameters & parms ) {}
	virtual int				GetGameFrame( void ) { return 0; }
	virtual void			InitializeMPMapsModes( void ) {}
	virtual const idStrList &GetModeList( void ) const { return modeList; }
	virtual const idStrList &GetModeDisplayList( void ) const { return modeDisplayList; }
	virtual const idList<mpMap_t> &GetMapList( void ) const { return mapList; }
	virtual void			ResetPlayerInput( int playerIndex ) {}
	virtual void			QueueShowShell( void ) {}
	virtual idUserCmdMgr &	GetUCmdMgr( void ) { return ucmdMgr; }
	virtual void			SetFocus( bool bstate ) {}
	virtual bool			IsFocused( void ) { return true; }
	virtual void			SetPaused( bool bstate ) {}
	virtual bool			IsPaused( void ) { return false; }

private:
	idUserCmdMgr			ucmdMgr;
	idStrList				modeList;
	idStrList				modeDisplayList;
	idList<mpMap_t>			mapList;
};

idCVar com_developer( "developer", "0", CVAR_BOOL | CVAR_SYSTEM, "developer mode" );
idCVar com_version( "si_version", "convertidtech3assets", CVAR_SYSTEM | CVAR_ROM | CVAR_SERVERINFO, "engine version" );
idCVar com_productionMode( "com_productionMode", "0", CVAR_SYSTEM | CVAR_BOOL, "0 - no special behavior, 1 - building a production build, 2 - running a production build" );

idCommonLocal		commonLocal;
idCommon *			common = &commonLocal;

/*
==============================================================

	idSys

==============================================================
*/

int Sys_Milliseconds() { return GetTickCount(); }
int Sys_NumLangs() { return 1; }
const char * Sys_Lang( int idx ) { return ( idx == 0 ) ? ID_LANG_ENGLISH : ""; }

int idEventLoop::JournalLevel() const { return 0; }

/*
==============================================================

	idSysLocal

==============================================================
*/

void			idSysLocal::DebugPrintf( VERIFY_FORMAT_STRING const char *fmt, ... ) {}
void			idSysLocal::DebugVPrintf( const char *fmt, va_list arg ) {}

double			idSysLocal::GetClockTicks( void ) { LARGE_INTEGER i; QueryPerformanceCounter( &i ); return (double)i.QuadPart; }
double			idSysLocal::ClockTicksPerSecond( void ) { LARGE_INTEGER i; QueryPerformanceFrequency( &i ); return (double)i.QuadPart; }
cpuid_t			idSysLocal::GetProcessorId( void ) { return CPUID_GENERIC; }
const char *	idSysLocal::GetProcessorString( void ) { return "Generic"; }

void			idSysLocal::FPU_SetFTZ( bool enable ) {}
void			idSysLocal::FPU_SetDAZ( bool enable ) {}

bool			idSysLocal::LockMemory( void *ptr, int bytes ) { return VirtualLock( ptr, bytes ) != 0; }
bool			idSysLocal::UnlockMemory( void *ptr, int bytes ) { return VirtualUnlock( ptr, bytes ) != 0; }

uintptr_t		idSysLocal::DLL_Load( const char *dllName ) { return (uintptr_t)LoadLibraryA( dllName ); }
void *			idSysLocal::DLL_GetProcAddress( uintptr_t dllHandle, const char *procName ) { return (void *)GetProcAddress( (HMODULE)dllHandle, procName ); }
void			idSysLocal::DLL_Unload( uintptr_t dllHandle ) { FreeLibrary( (HMODULE)dllHandle ); }
void			idSysLocal::DLL_GetFileName( const char *baseName, char *dllName, int maxLength ) { idStr::snPrintf( dllName, maxLength, "%s", baseName ); }

sysEvent_t		idSysLocal::GenerateMouseButtonEvent( int button, bool down ) { sysEvent_t ev; memset( &ev, 0, sizeof( ev ) ); return ev; }
sysEvent_t		idSysLocal::GenerateMouseMoveEvent( int deltax, int deltay ) { sysEvent_t ev; memset( &ev, 0, sizeof( ev ) ); return ev; }

void			idSysLocal::OpenURL( const char *url, bool quit ) {}
void			idSysLocal::StartProcess( const char *exeName, bool quit ) {}

idSysLocal		sysLocal;
idSys *			sys = &sysLocal;

/*
==============================================================

	Any CLI tool that wants the bare minimum to run the entire
	engine, should use the Tool_ functions.

==============================================================
*/

void Tool_InitFramework() {
	idLib::common = common;
	idLib::cvarSystem = cvarSystem;
	idLib::fileSystem = fileSystem;
	idLib::sys = sys;

	idLib::Init();
	cmdSystem->Init();
	cvarSystem->Init();
	idCVar::RegisterStaticVars();

	fileSystem->Init();
}

void Tool_ShutdownFramework() {
	fileSystem->Shutdown( false );
	cvarSystem->Shutdown();
	cmdSystem->Shutdown();
	idLib::ShutDown();
}
