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

/*
=============================================================================
	Standalone tool host stub. Derived from the classic Doom 3 typeinfogen
	sys_stub.cpp, upgraded for the BFG edition branch. There is no
	idTypeInfoGen on this branch; this file is the process harness for the
	Q3 shader tool. It stubs idCommon and the sys layer so idlib, the
	filesystem (including the .pak container support) and the console
	subsystems can run without the full engine.

	Link this against: idlib + CmdSystem.cpp + CVarSystem.cpp +
	FileSystem.cpp + Zip.cpp + File_Pak.cpp + Unzip/minizip.
	Do NOT link framework/Common.cpp, sys/sys_local*.cpp or
	sys/sys_threading.cpp alongside this file - the symbols here replace
	them.
=============================================================================
*/

#include "precompiled.h"
#include "../sys/sys_local.h"
#pragma hdrstop

#ifdef _WIN32
#include <io.h>
#include <direct.h>
#endif

/*
==============================================================

	Globals that idlib and the linked framework files reference.
	These are NULL so any code path that actually uses them fails
	loudly in the debugger instead of pulling in the full engine.

==============================================================
*/

idSession *			session = NULL;
idDeclManager *		declManager = NULL;
idEventLoop *		eventLoop = NULL;
idInputDevices *	inputDevice = NULL;
idJoystick *		joystick = NULL;
idSysPlatform *		platform = NULL;

// classic sys_stub.cpp carried this; referenced by framework code only
idCVar com_developer( "developer", "0", CVAR_BOOL | CVAR_SYSTEM, "developer mode" );

/*
==============================================================

	idCommon

==============================================================
*/

#define STDIO_PRINT( pre, post )	\
	va_list argptr;					\
	va_start( argptr, fmt );		\
	printf( pre );					\
	vprintf( fmt, argptr );			\
	printf( post );					\
	va_end( argptr )

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
	virtual void			Printf( VERIFY_FORMAT_STRING const char *fmt, ... ) { STDIO_PRINT( "", "" ); }
	virtual void			VPrintf( const char *fmt, va_list arg ) { vprintf( fmt, arg ); }
	virtual void			DPrintf( VERIFY_FORMAT_STRING const char *fmt, ... ) {}
	virtual void			Warning( VERIFY_FORMAT_STRING const char *fmt, ... ) { STDIO_PRINT( "WARNING: ", "\n" ); }
	virtual void			DWarning( VERIFY_FORMAT_STRING const char *fmt, ... ) {}
	virtual void			PrintWarnings( void ) {}
	virtual void			ClearWarnings( const char *reason ) {}
	virtual void			Error( VERIFY_FORMAT_STRING const char *fmt, ... ) { STDIO_PRINT( "ERROR: ", "\n" ); exit( 0 ); }
	virtual void			FatalError( VERIFY_FORMAT_STRING const char *fmt, ... ) { STDIO_PRINT( "FATAL ERROR: ", "\n" ); exit( 0 ); }
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
	// idCommonDialog is abstract (implemented in Common_dialog.cpp which
	// the tool does not link). Nothing in the linked set ever calls
	// Dialog(), so this deliberately faults if some future code does.
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

idCommonLocal		commonLocal;
idCommon *			common = &commonLocal;

/*
==============================================================

	idSys

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

	Platform free functions declared in sys_public.h.
	Anything the tool does not use is a stub; the few that idlib
	or the filesystem actually rely on are implemented for real.

==============================================================
*/

void			Sys_Init( void ) {}
void			Sys_Shutdown( void ) {}
void			Sys_Error( VERIFY_FORMAT_STRING const char *error, ... ) { va_list argptr; va_start( argptr, error ); printf( "SYS ERROR: " ); vprintf( error, argptr ); printf( "\n" ); va_end( argptr ); exit( 1 ); }
const char *	Sys_GetCmdLine( void ) { return ""; }
void			Sys_ReLaunch( void *launchData, unsigned int launchDataSize ) { exit( 0 ); }
void			Sys_Launch( const char *path, idCmdArgs &args, void *launchData, unsigned int launchDataSize ) {}
void			Sys_Quit( void ) { exit( 0 ); }

char *			Sys_GetClipboardData( void ) { return NULL; }
void			Sys_SetClipboardData( const char *string ) {}

void			Sys_Printf( VERIFY_FORMAT_STRING const char *msg, ... ) { va_list argptr; va_start( argptr, msg ); vprintf( msg, argptr ); va_end( argptr ); }
void			Sys_DebugPrintf( VERIFY_FORMAT_STRING const char *fmt, ... ) { va_list argptr; va_start( argptr, fmt ); vprintf( fmt, argptr ); va_end( argptr ); }
void			Sys_DebugVPrintf( const char *fmt, va_list arg ) { vprintf( fmt, arg ); }

void			Sys_Sleep( int msec ) { Sleep( msec ); }
void			Sys_EnableThreadAffinity( bool enable ) {}
int64			Sys_HiResClockCount( void ) { LARGE_INTEGER i; QueryPerformanceCounter( &i ); return i.QuadPart; }
double			Sys_HiResClockCountToMilliseconds( int64 count ) { static double freq = 0.0; if ( freq == 0.0 ) { LARGE_INTEGER i; QueryPerformanceFrequency( &i ); freq = (double)i.QuadPart; } return (double)count * 1000.0 / freq; }
void			Sys_SleepHiRes( double msec ) { if ( msec < 1.0 ) { Sleep( 0 ); } else { Sleep( (int)msec ); } }

int				Sys_Milliseconds( void ) { return (int)GetTickCount(); }
uint64			Sys_Microseconds( void ) { LARGE_INTEGER i; static double freq = 0.0; if ( freq == 0.0 ) { LARGE_INTEGER f; QueryPerformanceFrequency( &f ); freq = (double)f.QuadPart; } QueryPerformanceCounter( &i ); return (uint64)( (double)i.QuadPart * 1000000.0 / freq ); }

double			Sys_GetClockTicks( void ) { return sys->GetClockTicks(); }
double			Sys_ClockTicksPerSecond( void ) { return sys->ClockTicksPerSecond(); }
cpuid_t			Sys_GetProcessorId( void ) { return sys->GetProcessorId(); }
const char *	Sys_GetProcessorString( void ) { return sys->GetProcessorString(); }
void			Sys_FPU_SetFTZ( bool enable ) {}
void			Sys_FPU_SetDAZ( bool enable ) {}

int				Sys_GetSystemRam( void ) { MEMORYSTATUSEX statex; statex.dwLength = sizeof( statex ); GlobalMemoryStatusEx( &statex ); return (int)( statex.ullTotalPhys / ( 1024 * 1024 ) ); }
int				Sys_GetDriveFreeSpace( const char *path ) { ULARGE_INTEGER total; if ( GetDiskFreeSpaceExA( path, &total, NULL, NULL ) ) { return (int)( total.QuadPart / ( 1024 * 1024 ) ); } return 0; }
int64			Sys_GetDriveFreeSpaceInBytes( const char *path ) { ULARGE_INTEGER total; if ( GetDiskFreeSpaceExA( path, &total, NULL, NULL ) ) { return (int64)total.QuadPart; } return 0; }

bool			Sys_LockMemory( void *ptr, int bytes ) { return VirtualLock( ptr, bytes ) != 0; }
bool			Sys_UnlockMemory( void *ptr, int bytes ) { return VirtualUnlock( ptr, bytes ) != 0; }
void			Sys_SetPhysicalWorkMemory( int minBytes, int maxBytes ) {}

uintptr_t		Sys_DLL_Load( const char *dllName ) { return (uintptr_t)LoadLibraryA( dllName ); }
void *			Sys_DLL_GetProcAddress( uintptr_t dllHandle, const char *procName ) { return (void *)GetProcAddress( (HMODULE)dllHandle, procName ); }
void			Sys_DLL_Unload( uintptr_t dllHandle ) { FreeLibrary( (HMODULE)dllHandle ); }

void			Sys_GenerateEvents( void ) {}
sysEvent_t		Sys_GetEvent( void ) { sysEvent_t ev; memset( &ev, 0, sizeof( ev ) ); ev.evType = SE_NONE; return ev; }
void			Sys_ClearEvents( void ) {}

void			Sys_ShowWindow( bool show ) {}
bool			Sys_IsWindowVisible( void ) { return false; }
void			Sys_ShowConsole( int visLevel, bool quitOnClose ) {}

ID_TIME_T		Sys_FileTimeStamp( idFileHandle fp ) { return 0; }
const char *	Sys_TimeStampToStr( ID_TIME_T timeStamp ) { static char buf[64]; buf[0] = '\0'; return buf; }
const char *	Sys_SecToStr( int sec ) { static char buf[64]; buf[0] = '\0'; return buf; }

const char *	Sys_DefaultBasePath( void ) {
	static char cwd[MAX_OSPATH];
	_getcwd( cwd, sizeof( cwd ) - 1 );
	cwd[sizeof( cwd ) - 1] = 0;
	return cwd;
}
const char *	Sys_DefaultSavePath( void ) {
	if ( cvarSystem != NULL ) {
		return cvarSystem->GetCVarString( "fs_basepath" );
	}
	return Sys_DefaultBasePath();
}

bool			Sys_Exec( const char *appPath, const char *workingPath, const char *args, execProcessWorkFunction_t workFn, execOutputFunction_t outputFn, const int waitMS, unsigned int &exitCode ) { return false; }

void			Sys_SetLanguageFromSystem( void ) {}
const char *	Sys_DefaultLanguage( void ) { return ID_LANG_ENGLISH; }
int				Sys_LangIndex( const char *lang ) { return 0; }
const char *	Sys_Lang( int idx ) { return ID_LANG_ENGLISH; }
int				Sys_NumLangs( void ) { return 1; }

bool			Sys_StringToNetAdr( const char *s, netadr_t *a, bool doDNSResolve ) { memset( a, 0, sizeof( *a ) ); a->type = NA_BAD; return false; }
const char *	Sys_NetAdrToString( const netadr_t a ) { return ""; }
bool			Sys_IsLANAddress( const netadr_t a ) { return false; }
bool			Sys_CompareNetAdrBase( const netadr_t a, const netadr_t b ) { return false; }
int				Sys_GetLocalIPCount( void ) { return 0; }
const char *	Sys_GetLocalIP( int i ) { return ""; }
void			Sys_InitNetworking( void ) {}
void			Sys_ShutdownNetworking( void ) {}

/*
==============================================================

	Platform free functions declared in idlib/sys/sys_filesystem.h.
	FileSystem.cpp uses these, so they are implemented for real.

==============================================================
*/

void			Sys_Mkdir( const char *path ) { _mkdir( path ); }
bool			Sys_Rmdir( const char *path ) { return _rmdir( path ) == 0; }
bool			Sys_IsFileWritable( const char *path ) {
	DWORD attrib = GetFileAttributesA( path );
	if ( attrib == INVALID_FILE_ATTRIBUTES ) { return true; }
	if ( attrib & FILE_ATTRIBUTE_READONLY ) { return false; }
	return true;
}

sysFolder_t		Sys_IsFolder( const char *path ) {
	DWORD attrib = GetFileAttributesA( path );
	if ( attrib == INVALID_FILE_ATTRIBUTES ) { return FOLDER_NO; }
	if ( attrib & FILE_ATTRIBUTE_DIRECTORY ) { return FOLDER_YES; }
	return FOLDER_NO;
}

bool			Sys_IsFileOnHdd( const char *path ) { return true; }

int				Sys_ListFiles( const char *directory, const char *extension, idList<class idStr> &list ) {
	static char		search[MAX_OSPATH];
	struct _finddata_t findinfo;
	intptr_t		findhandle;
	int				flag;

	if ( !extension ) {
		extension = "";
	}

	// passing a slash as extension will find directories
	if ( extension[0] == '/' && extension[1] == 0 ) {
		extension = "";
		flag = 0;
	} else {
		flag = _A_SUBDIR;
	}

	idStr::snPrintf( search, sizeof( search ), "%s\\*%s", directory, extension );

	// search
	list.Clear();

	findhandle = _findfirst( search, &findinfo );
	if ( findhandle == -1 ) {
		return -1;
	}
	do {
		if ( flag ^ ( findinfo.attrib & _A_SUBDIR ) ) {
			list.Append( findinfo.name );
		}
	} while ( _findnext( findhandle, &findinfo ) != -1 );

	_findclose( findhandle );

	return list.Num();
}

const char *	Sys_EXEPath( void ) {
	static char exe[MAX_OSPATH];
	if ( !GetModuleFileNameA( NULL, exe, sizeof( exe ) - 1 ) ) { exe[0] = 0; }
	exe[sizeof( exe ) - 1] = 0;
	return exe;
}
const char *	Sys_CWD( void ) { return Sys_DefaultBasePath(); }
const char *	Sys_LaunchPath( void ) { return Sys_EXEPath(); }

/*
==============================================================

	Threading primitives declared in idlib/sys/sys_threading.h.
	Implemented for real so idlib code that links against them
	behaves even if it spins up a helper thread.

==============================================================
*/

uintptr_t		Sys_GetCurrentThreadID( void ) { return (uintptr_t)GetCurrentThreadId(); }

static int Sys_ThreadPriority( xthreadPriority priority ) {
	switch ( priority ) {
		case THREAD_LOWEST:			return THREAD_PRIORITY_LOWEST;
		case THREAD_BELOW_NORMAL:	return THREAD_PRIORITY_BELOW_NORMAL;
		case THREAD_NORMAL:			return THREAD_PRIORITY_NORMAL;
		case THREAD_ABOVE_NORMAL:	return THREAD_PRIORITY_ABOVE_NORMAL;
		case THREAD_HIGHEST:		return THREAD_PRIORITY_HIGHEST;
	}
	return THREAD_PRIORITY_NORMAL;
}

uintptr_t		Sys_CreateThread( xthread_t function, void *parms, xthreadPriority priority, const char *name, core_t core, int stackSize, bool suspended ) {
	HANDLE h = CreateThread( NULL, stackSize, (LPTHREAD_START_ROUTINE)function, parms, suspended ? CREATE_SUSPENDED : 0, NULL );
	if ( h == NULL ) {
		return 0;
	}
	SetThreadPriority( h, Sys_ThreadPriority( priority ) );
	return (uintptr_t)h;
}

void			Sys_WaitForThread( uintptr_t threadHandle ) { WaitForSingleObject( (HANDLE)threadHandle, INFINITE ); }
void			Sys_DestroyThread( uintptr_t threadHandle ) { CloseHandle( (HANDLE)threadHandle ); }
void			Sys_SetCurrentThreadName( const char *name ) {}

void			Sys_SignalCreate( signalHandle_t &handle, bool manualReset ) { handle = CreateEvent( NULL, manualReset, FALSE, NULL ); }
void			Sys_SignalDestroy( signalHandle_t &handle ) { CloseHandle( handle ); handle = NULL; }
void			Sys_SignalRaise( signalHandle_t &handle ) { SetEvent( handle ); }
void			Sys_SignalClear( signalHandle_t &handle ) { ResetEvent( handle ); }
bool			Sys_SignalWait( signalHandle_t &handle, int timeout ) { return WaitForSingleObject( handle, timeout < 0 ? INFINITE : timeout ) == WAIT_OBJECT_0; }

void			Sys_MutexCreate( mutexHandle_t &handle ) { InitializeCriticalSection( &handle ); }
void			Sys_MutexDestroy( mutexHandle_t &handle ) { DeleteCriticalSection( &handle ); }
bool			Sys_MutexLock( mutexHandle_t &handle, bool blocking ) { return blocking ? ( EnterCriticalSection( &handle ), true ) : ( TryEnterCriticalSection( &handle ) != 0 ); }
void			Sys_MutexUnlock( mutexHandle_t &handle ) { LeaveCriticalSection( &handle ); }

interlockedInt_t Sys_InterlockedIncrement( interlockedInt_t &value ) { return InterlockedIncrement( &value ); }
interlockedInt_t Sys_InterlockedDecrement( interlockedInt_t &value ) { return InterlockedDecrement( &value ); }
interlockedInt_t Sys_InterlockedAdd( interlockedInt_t &value, interlockedInt_t i ) { return InterlockedExchangeAdd( &value, i ) + i; }
interlockedInt_t Sys_InterlockedSub( interlockedInt_t &value, interlockedInt_t i ) { return InterlockedExchangeAdd( &value, -i ) - i; }
interlockedInt_t Sys_InterlockedExchange( interlockedInt_t &value, interlockedInt_t exchange ) { return InterlockedExchange( &value, exchange ); }
interlockedInt_t Sys_InterlockedCompareExchange( interlockedInt_t &value, interlockedInt_t &comparand, interlockedInt_t exchange ) { return InterlockedCompareExchange( &value, exchange, comparand ); }

void *			Sys_InterlockedExchangePointer( void * &ptr, void *exchange ) { return InterlockedExchangePointer( &ptr, exchange ); }
void *			Sys_InterlockedCompareExchangePointer( void * &ptr, void *comparand, void *exchange ) { return InterlockedCompareExchangePointer( &ptr, exchange, comparand ); }

void			Sys_Yield( void ) { SwitchToThread(); }

/*
==============================================================

	main

==============================================================
*/

int main( int argc, char **argv ) {
	idLib::common = common;
	idLib::cvarSystem = cvarSystem;
	idLib::fileSystem = fileSystem;
	idLib::sys = sys;

	idLib::Init();
	cmdSystem->Init();
	cvarSystem->Init();
	idCVar::RegisterStaticVars();

	// Point the filesystem at real game data before Init. The engine
	// base game dir is "base"; for Quake 3 content set fs_game to
	// "baseq3" (or whatever mod dir holds the .pak files).
	// NOTE: idFileSystemLocal::Init fatals out if it cannot find
	// default.cfg in any search path, so fs_basepath + fs_game must
	// resolve to a directory that actually contains one.
	if ( argc > 1 ) {
		cvarSystem->SetCVarString( "fs_basepath", argv[1] );
	}
	if ( argc > 2 ) {
		cvarSystem->SetCVarString( "fs_game", argv[2] );
	}

	fileSystem->Init();

	// =====================================================================
	// Q3 shader tool entry point.
	// idLexer/idParser/idList/idStr/idDict and the filesystem (including
	// the .pak container support) are live past this point. Put the tool
	// logic - or a call to it - here.
	// =====================================================================

	fileSystem->Shutdown( false );
	cvarSystem->Shutdown();
	cmdSystem->Shutdown();
	idLib::ShutDown();

	return 0;
}
