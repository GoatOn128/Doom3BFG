# Build digest

commit: a1f252981d71

- windows-x64-debug: cancelled
- windows-x64-release: cancelled
- windows-x86-debug: cancelled
- windows-x86-release: failure

## windows-x64-debug

status: cancelled

errors: 0
warnings: 14 in 5 kinds

### errors


### failure context


### warning kinds

- [5x] C4389
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1488): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1506): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1526): warning C4389: '!=': signed/unsigned mismatch
- [4x] C4312
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\BufferObject.cpp(188): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\BufferObject.cpp(433): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\BufferObject.cpp(671): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_rendertools.cpp(727): warning C4312: 'type cast': conversion from 'int' to 'void *' of greater size
- [3x] C4245
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [1x] C4311
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_rendertools.cpp(724): warning C4311: 'type cast': pointer truncation from 'void *' to 'GLuint'
- [1x] C4302
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_rendertools.cpp(724): warning C4302: 'type cast': truncation from 'void *' to 'GLuint'

## windows-x64-release

status: cancelled

errors: 0
warnings: 20 in 6 kinds

### errors


### failure context


### warning kinds

- [6x] C4702
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(368) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1048) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1345) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1379) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1390) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1422) : warning C4702: unreachable code
- [5x] C4389
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1488): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1506): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1526): warning C4389: '!=': signed/unsigned mismatch
- [4x] C4312
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\BufferObject.cpp(188): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\BufferObject.cpp(433): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\BufferObject.cpp(671): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_rendertools.cpp(727): warning C4312: 'type cast': conversion from 'int' to 'void *' of greater size
- [3x] C4245
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [1x] C4311
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_rendertools.cpp(724): warning C4311: 'type cast': pointer truncation from 'void *' to 'GLuint'
- [1x] C4302
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_rendertools.cpp(724): warning C4302: 'type cast': truncation from 'void *' to 'GLuint'

## windows-x86-debug

status: cancelled

errors: 0
warnings: 12 in 2 kinds

### errors


### failure context


### warning kinds

- [9x] C4389
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\gamesys\Event.cpp(786): warning C4389: '==': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\gamesys\Event.cpp(853): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\gamesys\Event.cpp(903): warning C4389: '==': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\gamesys\Event.cpp(943): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1488): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1506): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1526): warning C4389: '!=': signed/unsigned mismatch
- [3x] C4245
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch

## windows-x86-release

status: failure

errors: 1
warnings: 20 in 5 kinds

### errors

scons: *** [bin\Doom3BFG.exe] Error 1169

### failure context

- bin\Doom3BFG.exe

```
sys_stub.cpp.obj : error LNK2005: "void __cdecl Sys_SetClipboardData(char const *)" (?Sys_SetClipboardData@@YAXPBD@Z) already defined in win_main.cpp.obj
sys_stub.cpp.obj : error LNK2005: "void __cdecl Sys_SetLanguageFromSystem(void)" (?Sys_SetLanguageFromSystem@@YAXXZ) already defined in win_main.cpp.obj
sys_stub.cpp.obj : error LNK2005: "void __cdecl Sys_SetPhysicalWorkMemory(int,int)" (?Sys_SetPhysicalWorkMemory@@YAXHH@Z) already defined in win_shared.cpp.obj
sys_stub.cpp.obj : error LNK2005: "void __cdecl Sys_ShowConsole(int,bool)" (?Sys_ShowConsole@@YAXH_N@Z) already defined in win_syscon.cpp.obj
sys_stub.cpp.obj : error LNK2005: "void __cdecl Sys_ShowWindow(bool)" (?Sys_ShowWindow@@YAX_N@Z) already defined in win_main.cpp.obj
sys_stub.cpp.obj : error LNK2005: "void __cdecl Sys_Shutdown(void)" (?Sys_Shutdown@@YAXXZ) already defined in win_main.cpp.obj
sys_stub.cpp.obj : error LNK2005: "void __cdecl Sys_ShutdownNetworking(void)" (?Sys_ShutdownNetworking@@YAXXZ) already defined in win_net.cpp.obj
sys_stub.cpp.obj : error LNK2005: "void __cdecl Sys_Sleep(int)" (?Sys_Sleep@@YAXH@Z) already defined in win_main.cpp.obj
sys_stub.cpp.obj : error LNK2005: "void __cdecl Sys_SleepHiRes(double)" (?Sys_SleepHiRes@@YAXN@Z) already defined in win_main.cpp.obj
sys_stub.cpp.obj : error LNK2005: "bool __cdecl Sys_StringToNetAdr(char const *,struct netadr_t *,bool)" (?Sys_StringToNetAdr@@YA_NPBDPAUnetadr_t@@_N@Z) already defined in win_net.cpp.obj
sys_stub.cpp.obj : error LNK2005: "char const * __cdecl Sys_TimeStampToStr(__int64)" (?Sys_TimeStampToStr@@YAPBD_J@Z) already defined in sys_local.cpp.obj
sys_stub.cpp.obj : error LNK2005: "bool __cdecl Sys_UnlockMemory(void *,int)" (?Sys_UnlockMemory@@YA_NPAXH@Z) already defined in win_shared.cpp.obj
sys_stub.cpp.obj : error LNK2005: "public: virtual void __thiscall idCommonLocal::TriggerScreenWipe(char const *,bool)" (?TriggerScreenWipe@idCommonLocal@@UAEXPBD_N@Z) already defined in Common_load.cpp.obj
sys_stub.cpp.obj : error LNK2005: "public: virtual void __thiscall idCommonLocal::UpdateLevelLoadPacifier(void)" (?UpdateLevelLoadPacifier@idCommonLocal@@UAEXXZ) already defined in Common_load.cpp.obj
sys_stub.cpp.obj : error LNK2005: "public: virtual void __thiscall idCommonLocal::UpdateScreen(bool,bool)" (?UpdateScreen@idCommonLocal@@UAEX_N0@Z) already defined in common_frame.cpp.obj
sys_stub.cpp.obj : error LNK2005: "public: virtual void __thiscall idCommonLocal::VPrintf(char const *,char *)" (?VPrintf@idCommonLocal@@UAEXPBDPAD@Z) already defined in Common_printf.cpp.obj
sys_stub.cpp.obj : error LNK2005: "public: virtual void __cdecl idCommonLocal::Warning(char const *,...)" (?Warning@idCommonLocal@@UAAXPBDZZ) already defined in Common_printf.cpp.obj
sys_stub.cpp.obj : error LNK2005: "class idSysPlatform * platform" (?platform@@3PAVidSysPlatform@@A) already defined in sys_platform_local.cpp.obj
sys_stub.cpp.obj : error LNK2005: "class idInputDevices * inputDevice" (?inputDevice@@3PAVidInputDevices@@A) already defined in win_input.cpp.obj
sys_stub.cpp.obj : error LNK2005: "class idJoystick * joystick" (?joystick@@3PAVidJoystick@@A) already defined in win_input.cpp.obj
sys_stub.cpp.obj : error LNK2005: "class idSys * sys" (?sys@@3PAVidSys@@A) already defined in sys_local.cpp.obj
sys_stub.cpp.obj : error LNK2005: "class idEventLoop * eventLoop" (?eventLoop@@3PAVidEventLoop@@A) already defined in EventLoop.cpp.obj
sys_stub.cpp.obj : error LNK2005: "class idSession * session" (?session@@3PAVidSession@@A) already defined in win_session_local.cpp.obj
sys_stub.cpp.obj : error LNK2005: "class idDeclManager * declManager" (?declManager@@3PAVidDeclManager@@A) already defined in DeclManager.cpp.obj
sys_stub.cpp.obj : error LNK2005: "class idCommon * common" (?common@@3PAVidCommon@@A) already defined in Common.cpp.obj
sys_stub.cpp.obj : error LNK2005: "class idSysLocal sysLocal" (?sysLocal@@3VidSysLocal@@A) already defined in sys_local.cpp.obj
sys_stub.cpp.obj : error LNK2005: "class idCVar com_developer" (?com_developer@@3VidCVar@@A) already defined in Common.cpp.obj
sys_stub.cpp.obj : error LNK2005: "class idCommonLocal commonLocal" (?commonLocal@@3VidCommonLocal@@A) already defined in Common.cpp.obj
   Creating library bin\Doom3BFG.lib and object bin\Doom3BFG.exp
bin\Doom3BFG.exe : fatal error LNK1169: one or more multiply defined symbols found
scons: *** [bin\Doom3BFG.exe] Error 1169
```


### warning kinds

- [7x] C4389
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\gamesys\Event.cpp(853): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\gamesys\Event.cpp(943): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1488): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1506): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1526): warning C4389: '!=': signed/unsigned mismatch
- [6x] C4702
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(368) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1048) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1345) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1379) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1390) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1422) : warning C4702: unreachable code
- [3x] C4245
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [3x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\renderbump\renderbump.cpp(1318) : warning C4701: potentially uninitialized local variable 'opt' used
- [1x] C4985
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\q3shaders\sys_stub.cpp(221): warning C4985: 'Sys_Error': attributes not present on previous declaration.

