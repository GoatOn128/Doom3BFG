# Build digest

commit: 5c7ef2054422

- windows-x64-debug: failure
- windows-x64-release: cancelled
- windows-x64-release-dll: cancelled
- windows-x86-debug: success
- windows-x86-release: success

## windows-x64-debug

status: failure

errors: 2
warnings: 26 in 7 kinds

### errors

neo\sys\win32\win_syscon.cpp(392): error C2065: 'GWL_WNDPROC': undeclared identifier
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\sys\win32\win_syscon.cpp.obj] Error 2

### failure context

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\sys\win32\win_syscon.cpp.obj

```
win_input.cpp
Compiling 'neo\sys\win32\win_localuser.cpp'
win_localuser.cpp
Compiling 'neo\sys\win32\win_main.cpp'
win_main.cpp
Compiling 'neo\sys\win32\win_net.cpp'
win_net.cpp
Compiling 'neo\sys\win32\win_savegame.cpp'
win_savegame.cpp
Compiling 'neo\sys\win32\win_seh.cpp'
win_seh.cpp
Compiling 'neo\sys\win32\win_session_local.cpp'
win_session_local.cpp
Compiling 'neo\sys\win32\win_shared.cpp'
win_shared.cpp
Compiling 'neo\sys\win32\win_signin.cpp'
win_signin.cpp
Compiling 'neo\sys\win32\win_syscon.cpp'
win_syscon.cpp
Compiling 'neo\sys\win32\win_wndproc.cpp'
win_wndproc.cpp
Compiling 'neo\tools\compilers\aas\AASBuild.cpp'
AASBuild.cpp
neo\sys\win32\win_syscon.cpp(119): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
neo\sys\win32\win_syscon.cpp(119): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
neo\sys\win32\win_syscon.cpp(128): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
neo\sys\win32\win_syscon.cpp(128): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
neo\sys\win32\win_syscon.cpp(392): error C2065: 'GWL_WNDPROC': undeclared identifier
neo\sys\win32\win_syscon.cpp(392): warning C4311: 'type cast': pointer truncation from 'LONG (__cdecl *)(HWND,UINT,WPARAM,LPARAM)' to 'long'
neo\sys\win32\win_syscon.cpp(392): warning C4302: 'type cast': truncation from 'LONG (__cdecl *)(HWND,UINT,WPARAM,LPARAM)' to 'long'
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\sys\win32\win_syscon.cpp.obj] Error 2
```


### warning kinds

- [5x] C4389
  - neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1498): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1516): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1536): warning C4389: '!=': signed/unsigned mismatch
- [4x] C4245
  - neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\framework\Common_tools.cpp(40): warning C4245: 'initializing': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [4x] C4312
  - neo\renderer\BufferObject.cpp(188): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - neo\renderer\BufferObject.cpp(433): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - neo\renderer\BufferObject.cpp(671): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - neo\renderer\tr_backend_rendertools.cpp(727): warning C4312: 'type cast': conversion from 'int' to 'void *' of greater size
- [4x] C4311
  - neo\renderer\tr_backend_rendertools.cpp(724): warning C4311: 'type cast': pointer truncation from 'void *' to 'GLuint'
  - neo\sys\win32\win_syscon.cpp(119): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(128): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(392): warning C4311: 'type cast': pointer truncation from 'LONG (__cdecl *)(HWND,UINT,WPARAM,LPARAM)' to 'long'
- [4x] C4302
  - neo\renderer\tr_backend_rendertools.cpp(724): warning C4302: 'type cast': truncation from 'void *' to 'GLuint'
  - neo\sys\win32\win_syscon.cpp(119): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(128): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(392): warning C4302: 'type cast': truncation from 'LONG (__cdecl *)(HWND,UINT,WPARAM,LPARAM)' to 'long'
- [4x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\external\stb\stb_vorbis.h(4849) : warning C4701: potentially uninitialized local variable 'mid' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\renderbump\renderbump.cpp(1318) : warning C4701: potentially uninitialized local variable 'opt' used
- [1x] C4101
  - neo\framework\Common.cpp(777): warning C4101: 'mouseEvents': unreferenced local variable

## windows-x64-release-dll

status: cancelled

errors: 32
warnings: 26 in 7 kinds

### errors

neo\sys\win32\win_syscon.cpp(392): error C2065: 'GWL_WNDPROC': undeclared identifier
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\sys\win32\win_syscon.cpp.obj] Error 2
neo\d3xp\Game_local.cpp(438): error C3861: 'Mem_EnableLeakTest': identifier not found
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Game_local.cpp.obj] Error 2
neo\d3xp\menus\MenuHandler_Shell.cpp(281): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuHandler_Shell.cpp(281): error C3861: 'GetBinding': identifier not found
neo\d3xp\menus\MenuHandler_Shell.cpp(283): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuHandler_Shell.cpp(283): error C3861: 'SetBinding': identifier not found
neo\d3xp\menus\MenuHandler_Shell.cpp(297): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuHandler_Shell.cpp(297): error C3861: 'GetBinding': identifier not found
neo\d3xp\menus\MenuHandler_Shell.cpp(300): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuHandler_Shell.cpp(300): error C3861: 'SetBinding': identifier not found
neo\d3xp\menus\MenuHandler_Shell.cpp(328): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuHandler_Shell.cpp(328): error C3861: 'SetBinding': identifier not found
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_Shell.cpp.obj] Error 2
neo\d3xp\menus\MenuScreen_HUD.cpp(678): error C2065: 'keyBindings_t': undeclared identifier
neo\d3xp\menus\MenuScreen_HUD.cpp(678): error C2146: syntax error: missing ';' before identifier 'bind'
neo\d3xp\menus\MenuScreen_HUD.cpp(678): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuScreen_HUD.cpp(678): error C3861: 'KeyBindingsFromBinding': identifier not found
neo\d3xp\menus\MenuScreen_HUD.cpp(678): error C2659: '=': function as left operand
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_HUD.cpp.obj] Error 2
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(253): error C2065: 'keyBindings_t': undeclared identifier
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(253): error C2146: syntax error: missing ';' before identifier 'bind'
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(253): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(253): error C3861: 'KeyBindingsFromBinding': identifier not found
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(253): error C2659: '=': function as left operand
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(385): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(385): error C2660: 'idMenuScreen_Shell_Bindings::SetBinding': function does not take 2 arguments
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Bindings.cpp.obj] Error 2
neo\d3xp\menus\MenuScreen_Shell_ControllerLayout.cpp(216): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuScreen_Shell_ControllerLayout.cpp(216): error C3861: 'GetBinding': identifier not found
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_ControllerLayout.cpp.obj] Error 2

### failure context

- build\scons\windows-x64-release-msvc\obj\DoomEXE\sys\win32\win_syscon.cpp.obj

```
Compiling 'neo\sys\win32\win_main.cpp'
win_localuser.cpp
win_main.cpp
Compiling 'neo\sys\win32\win_net.cpp'
win_net.cpp
Compiling 'neo\sys\win32\win_savegame.cpp'
win_savegame.cpp
Compiling 'neo\sys\win32\win_seh.cpp'
win_seh.cpp
Compiling 'neo\sys\win32\win_session_local.cpp'
win_session_local.cpp
Compiling 'neo\sys\win32\win_shared.cpp'
win_shared.cpp
Compiling 'neo\sys\win32\win_signin.cpp'
win_signin.cpp
Compiling 'neo\sys\win32\win_syscon.cpp'
win_syscon.cpp
Compiling 'neo\sys\win32\win_wndproc.cpp'
win_wndproc.cpp
Compiling 'neo\tools\compilers\aas\AASBuild.cpp'
AASBuild.cpp
Compiling 'neo\tools\compilers\aas\AASBuild_file.cpp'
AASBuild_file.cpp
neo\sys\win32\win_syscon.cpp(119): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
neo\sys\win32\win_syscon.cpp(119): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
neo\sys\win32\win_syscon.cpp(128): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
neo\sys\win32\win_syscon.cpp(128): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
neo\sys\win32\win_syscon.cpp(392): error C2065: 'GWL_WNDPROC': undeclared identifier
neo\sys\win32\win_syscon.cpp(392): warning C4311: 'type cast': pointer truncation from 'LONG (__cdecl *)(HWND,UINT,WPARAM,LPARAM)' to 'long'
neo\sys\win32\win_syscon.cpp(392): warning C4302: 'type cast': truncation from 'LONG (__cdecl *)(HWND,UINT,WPARAM,LPARAM)' to 'long'
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\sys\win32\win_syscon.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Game_local.cpp.obj

```
AI_pathing.cpp
Compiling 'neo\d3xp\ai\AI_Vagary.cpp'
AI_Vagary.cpp
Compiling 'neo\d3xp\AimAssist.cpp'
Compiling 'neo\d3xp\anim\Anim.cpp'
AimAssist.cpp
Anim.cpp
Compiling 'neo\d3xp\anim\Anim_Blend.cpp'
Anim_Blend.cpp
Compiling 'neo\d3xp\anim\Anim_Testmodel.cpp'
Anim_Testmodel.cpp
Compiling 'neo\d3xp\BrittleFracture.cpp'
BrittleFracture.cpp
Compiling 'neo\d3xp\Camera.cpp'
Camera.cpp
Compiling 'neo\d3xp\Entity.cpp'
Entity.cpp
Compiling 'neo\d3xp\Fx.cpp'
Fx.cpp
Compiling 'neo\d3xp\Game_local.cpp'
Compiling 'neo\d3xp\Game_network.cpp'
Game_local.cpp
Game_network.cpp
Compiling 'neo\d3xp\GameEdit.cpp'
GameEdit.cpp
Compiling 'neo\d3xp\gamesys\Class.cpp'
Class.cpp
neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
neo\d3xp\Game_local.cpp(438): error C3861: 'Mem_EnableLeakTest': identifier not found
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Game_local.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_Shell.cpp.obj

```
Compiling 'neo\d3xp\Leaderboards.cpp'
Leaderboards.cpp
Compiling 'neo\d3xp\Light.cpp'
Light.cpp
Compiling 'neo\d3xp\menus\MenuHandler.cpp'
MenuHandler.cpp
Compiling 'neo\d3xp\menus\MenuHandler_HUD.cpp'
MenuHandler_HUD.cpp
Compiling 'neo\d3xp\menus\MenuHandler_PDA.cpp'
MenuHandler_PDA.cpp
Compiling 'neo\d3xp\menus\MenuHandler_Scoreboard.cpp'
MenuHandler_Scoreboard.cpp
Compiling 'neo\d3xp\menus\MenuHandler_Shell.cpp'
Compiling 'neo\d3xp\menus\MenuScreen.cpp'
MenuHandler_Shell.cpp
MenuScreen.cpp
Compiling 'neo\d3xp\menus\MenuScreen_HUD.cpp'
MenuScreen_HUD.cpp
Compiling 'neo\d3xp\menus\MenuScreen_PDA_Inventory.cpp'
MenuScreen_PDA_Inventory.cpp
neo\d3xp\menus\MenuHandler_Shell.cpp(281): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuHandler_Shell.cpp(281): error C3861: 'GetBinding': identifier not found
neo\d3xp\menus\MenuHandler_Shell.cpp(283): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuHandler_Shell.cpp(283): error C3861: 'SetBinding': identifier not found
neo\d3xp\menus\MenuHandler_Shell.cpp(297): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuHandler_Shell.cpp(297): error C3861: 'GetBinding': identifier not found
neo\d3xp\menus\MenuHandler_Shell.cpp(300): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuHandler_Shell.cpp(300): error C3861: 'SetBinding': identifier not found
neo\d3xp\menus\MenuHandler_Shell.cpp(328): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuHandler_Shell.cpp(328): error C3861: 'SetBinding': identifier not found
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_Shell.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_HUD.cpp.obj

```
Compiling 'neo\d3xp\menus\MenuHandler_Scoreboard.cpp'
MenuHandler_Scoreboard.cpp
Compiling 'neo\d3xp\menus\MenuHandler_Shell.cpp'
Compiling 'neo\d3xp\menus\MenuScreen.cpp'
MenuHandler_Shell.cpp
MenuScreen.cpp
Compiling 'neo\d3xp\menus\MenuScreen_HUD.cpp'
MenuScreen_HUD.cpp
Compiling 'neo\d3xp\menus\MenuScreen_PDA_Inventory.cpp'
MenuScreen_PDA_Inventory.cpp
neo\d3xp\menus\MenuHandler_Shell.cpp(281): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuHandler_Shell.cpp(281): error C3861: 'GetBinding': identifier not found
neo\d3xp\menus\MenuHandler_Shell.cpp(283): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuHandler_Shell.cpp(283): error C3861: 'SetBinding': identifier not found
neo\d3xp\menus\MenuHandler_Shell.cpp(297): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuHandler_Shell.cpp(297): error C3861: 'GetBinding': identifier not found
neo\d3xp\menus\MenuHandler_Shell.cpp(300): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuHandler_Shell.cpp(300): error C3861: 'SetBinding': identifier not found
neo\d3xp\menus\MenuHandler_Shell.cpp(328): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuHandler_Shell.cpp(328): error C3861: 'SetBinding': identifier not found
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_Shell.cpp.obj] Error 2
Compiling 'neo\d3xp\menus\MenuScreen_PDA_UserData.cpp'
MenuScreen_PDA_UserData.cpp
Compiling 'neo\d3xp\menus\MenuScreen_PDA_UserEmails.cpp'
MenuScreen_PDA_UserEmails.cpp
neo\d3xp\menus\MenuScreen_HUD.cpp(678): error C2065: 'keyBindings_t': undeclared identifier
neo\d3xp\menus\MenuScreen_HUD.cpp(678): error C2146: syntax error: missing ';' before identifier 'bind'
neo\d3xp\menus\MenuScreen_HUD.cpp(678): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuScreen_HUD.cpp(678): error C3861: 'KeyBindingsFromBinding': identifier not found
neo\d3xp\menus\MenuScreen_HUD.cpp(678): error C2659: '=': function as left operand
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_HUD.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Bindings.cpp.obj

```
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_Shell.cpp.obj] Error 2
Compiling 'neo\d3xp\menus\MenuScreen_PDA_UserData.cpp'
MenuScreen_PDA_UserData.cpp
Compiling 'neo\d3xp\menus\MenuScreen_PDA_UserEmails.cpp'
MenuScreen_PDA_UserEmails.cpp
neo\d3xp\menus\MenuScreen_HUD.cpp(678): error C2065: 'keyBindings_t': undeclared identifier
neo\d3xp\menus\MenuScreen_HUD.cpp(678): error C2146: syntax error: missing ';' before identifier 'bind'
neo\d3xp\menus\MenuScreen_HUD.cpp(678): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuScreen_HUD.cpp(678): error C3861: 'KeyBindingsFromBinding': identifier not found
neo\d3xp\menus\MenuScreen_HUD.cpp(678): error C2659: '=': function as left operand
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_HUD.cpp.obj] Error 2
Compiling 'neo\d3xp\menus\MenuScreen_PDA_VideoDisks.cpp'
MenuScreen_PDA_VideoDisks.cpp
Compiling 'neo\d3xp\menus\MenuScreen_Scoreboard.cpp'
Compiling 'neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp'
MenuScreen_Scoreboard.cpp
MenuScreen_Shell_Bindings.cpp
Compiling 'neo\d3xp\menus\MenuScreen_Shell_Browser.cpp'
MenuScreen_Shell_Browser.cpp
Compiling 'neo\d3xp\menus\MenuScreen_Shell_ControllerLayout.cpp'
MenuScreen_Shell_ControllerLayout.cpp
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(253): error C2065: 'keyBindings_t': undeclared identifier
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(253): error C2146: syntax error: missing ';' before identifier 'bind'
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(253): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(253): error C3861: 'KeyBindingsFromBinding': identifier not found
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(253): error C2659: '=': function as left operand
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(385): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(385): error C2660: 'idMenuScreen_Shell_Bindings::SetBinding': function does not take 2 arguments
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(382): note: see declaration of 'idMenuScreen_Shell_Bindings::SetBinding'
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(385): note: while trying to match the argument list '(int, const char *)'
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Bindings.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_ControllerLayout.cpp.obj

```
neo\d3xp\menus\MenuScreen_HUD.cpp(678): error C2659: '=': function as left operand
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_HUD.cpp.obj] Error 2
Compiling 'neo\d3xp\menus\MenuScreen_PDA_VideoDisks.cpp'
MenuScreen_PDA_VideoDisks.cpp
Compiling 'neo\d3xp\menus\MenuScreen_Scoreboard.cpp'
Compiling 'neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp'
MenuScreen_Scoreboard.cpp
MenuScreen_Shell_Bindings.cpp
Compiling 'neo\d3xp\menus\MenuScreen_Shell_Browser.cpp'
MenuScreen_Shell_Browser.cpp
Compiling 'neo\d3xp\menus\MenuScreen_Shell_ControllerLayout.cpp'
MenuScreen_Shell_ControllerLayout.cpp
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(253): error C2065: 'keyBindings_t': undeclared identifier
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(253): error C2146: syntax error: missing ';' before identifier 'bind'
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(253): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(253): error C3861: 'KeyBindingsFromBinding': identifier not found
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(253): error C2659: '=': function as left operand
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(385): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(385): error C2660: 'idMenuScreen_Shell_Bindings::SetBinding': function does not take 2 arguments
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(382): note: see declaration of 'idMenuScreen_Shell_Bindings::SetBinding'
neo\d3xp\menus\MenuScreen_Shell_Bindings.cpp(385): note: while trying to match the argument list '(int, const char *)'
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Bindings.cpp.obj] Error 2
Compiling 'neo\d3xp\menus\MenuScreen_Shell_Controls.cpp'
MenuScreen_Shell_Controls.cpp
Compiling 'neo\d3xp\menus\MenuScreen_Shell_Credits.cpp'
MenuScreen_Shell_Credits.cpp
Compiling 'neo\d3xp\menus\MenuScreen_Shell_Dev.cpp'
MenuScreen_Shell_Dev.cpp
neo\d3xp\menus\MenuScreen_Shell_ControllerLayout.cpp(216): error C2653: 'idKeyInput': is not a class or namespace name
neo\d3xp\menus\MenuScreen_Shell_ControllerLayout.cpp(216): error C3861: 'GetBinding': identifier not found
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_ControllerLayout.cpp.obj] Error 2
```


### warning kinds

- [5x] C4389
  - neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1498): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1516): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1536): warning C4389: '!=': signed/unsigned mismatch
- [4x] C4245
  - neo\framework\Common_tools.cpp(40): warning C4245: 'initializing': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
- [4x] C4312
  - neo\renderer\BufferObject.cpp(188): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - neo\renderer\BufferObject.cpp(433): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - neo\renderer\BufferObject.cpp(671): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - neo\renderer\tr_backend_rendertools.cpp(727): warning C4312: 'type cast': conversion from 'int' to 'void *' of greater size
- [4x] C4311
  - neo\renderer\tr_backend_rendertools.cpp(724): warning C4311: 'type cast': pointer truncation from 'void *' to 'GLuint'
  - neo\sys\win32\win_syscon.cpp(119): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(128): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(392): warning C4311: 'type cast': pointer truncation from 'LONG (__cdecl *)(HWND,UINT,WPARAM,LPARAM)' to 'long'
- [4x] C4302
  - neo\renderer\tr_backend_rendertools.cpp(724): warning C4302: 'type cast': truncation from 'void *' to 'GLuint'
  - neo\sys\win32\win_syscon.cpp(119): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(128): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(392): warning C4302: 'type cast': truncation from 'LONG (__cdecl *)(HWND,UINT,WPARAM,LPARAM)' to 'long'
- [4x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\external\stb\stb_vorbis.h(4849) : warning C4701: potentially uninitialized local variable 'mid' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\renderbump\renderbump.cpp(1318) : warning C4701: potentially uninitialized local variable 'opt' used
- [1x] C4101
  - neo\framework\Common.cpp(777): warning C4101: 'mouseEvents': unreferenced local variable

## windows-x64-release

status: cancelled

errors: 2
warnings: 32 in 8 kinds

### errors

neo\sys\win32\win_syscon.cpp(392): error C2065: 'GWL_WNDPROC': undeclared identifier
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\sys\win32\win_syscon.cpp.obj] Error 2

### failure context

- build\scons\windows-x64-release-msvc\obj\DoomEXE\sys\win32\win_syscon.cpp.obj

```
win_localuser.cpp
Compiling 'neo\sys\win32\win_main.cpp'
win_main.cpp
Compiling 'neo\sys\win32\win_net.cpp'
win_net.cpp
Compiling 'neo\sys\win32\win_savegame.cpp'
win_savegame.cpp
Compiling 'neo\sys\win32\win_seh.cpp'
win_seh.cpp
Compiling 'neo\sys\win32\win_session_local.cpp'
Compiling 'neo\sys\win32\win_shared.cpp'
win_session_local.cpp
win_shared.cpp
Compiling 'neo\sys\win32\win_signin.cpp'
win_signin.cpp
Compiling 'neo\sys\win32\win_syscon.cpp'
win_syscon.cpp
Compiling 'neo\sys\win32\win_wndproc.cpp'
win_wndproc.cpp
Compiling 'neo\tools\compilers\aas\AASBuild.cpp'
AASBuild.cpp
Compiling 'neo\tools\compilers\aas\AASBuild_file.cpp'
AASBuild_file.cpp
neo\sys\win32\win_syscon.cpp(119): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
neo\sys\win32\win_syscon.cpp(119): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
neo\sys\win32\win_syscon.cpp(128): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
neo\sys\win32\win_syscon.cpp(128): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
neo\sys\win32\win_syscon.cpp(392): error C2065: 'GWL_WNDPROC': undeclared identifier
neo\sys\win32\win_syscon.cpp(392): warning C4311: 'type cast': pointer truncation from 'LONG (__cdecl *)(HWND,UINT,WPARAM,LPARAM)' to 'long'
neo\sys\win32\win_syscon.cpp(392): warning C4302: 'type cast': truncation from 'LONG (__cdecl *)(HWND,UINT,WPARAM,LPARAM)' to 'long'
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\sys\win32\win_syscon.cpp.obj] Error 2
```


### warning kinds

- [6x] C4702
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(368) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1048) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1345) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1379) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1390) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1422) : warning C4702: unreachable code
- [5x] C4389
  - neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1498): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1516): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1536): warning C4389: '!=': signed/unsigned mismatch
- [4x] C4245
  - neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\framework\Common_tools.cpp(40): warning C4245: 'initializing': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [4x] C4312
  - neo\renderer\BufferObject.cpp(188): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - neo\renderer\BufferObject.cpp(433): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - neo\renderer\BufferObject.cpp(671): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - neo\renderer\tr_backend_rendertools.cpp(727): warning C4312: 'type cast': conversion from 'int' to 'void *' of greater size
- [4x] C4311
  - neo\renderer\tr_backend_rendertools.cpp(724): warning C4311: 'type cast': pointer truncation from 'void *' to 'GLuint'
  - neo\sys\win32\win_syscon.cpp(119): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(128): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(392): warning C4311: 'type cast': pointer truncation from 'LONG (__cdecl *)(HWND,UINT,WPARAM,LPARAM)' to 'long'
- [4x] C4302
  - neo\renderer\tr_backend_rendertools.cpp(724): warning C4302: 'type cast': truncation from 'void *' to 'GLuint'
  - neo\sys\win32\win_syscon.cpp(119): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(128): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(392): warning C4302: 'type cast': truncation from 'LONG (__cdecl *)(HWND,UINT,WPARAM,LPARAM)' to 'long'
- [4x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\external\stb\stb_vorbis.h(4849) : warning C4701: potentially uninitialized local variable 'mid' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\renderbump\renderbump.cpp(1318) : warning C4701: potentially uninitialized local variable 'opt' used
- [1x] C4101
  - neo\framework\Common.cpp(777): warning C4101: 'mouseEvents': unreferenced local variable

## windows-x86-debug

status: success

errors: 0
warnings: 18 in 4 kinds

### errors


### failure context


### warning kinds

- [9x] C4389
  - neo\d3xp\gamesys\Event.cpp(786): warning C4389: '==': signed/unsigned mismatch
  - neo\d3xp\gamesys\Event.cpp(853): warning C4389: '!=': signed/unsigned mismatch
  - neo\d3xp\gamesys\Event.cpp(903): warning C4389: '==': signed/unsigned mismatch
  - neo\d3xp\gamesys\Event.cpp(943): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1498): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1516): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1536): warning C4389: '!=': signed/unsigned mismatch
- [4x] C4245
  - neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\framework\Common_tools.cpp(40): warning C4245: 'initializing': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [4x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\external\stb\stb_vorbis.h(4849) : warning C4701: potentially uninitialized local variable 'mid' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\renderbump\renderbump.cpp(1318) : warning C4701: potentially uninitialized local variable 'opt' used
- [1x] C4101
  - neo\framework\Common.cpp(777): warning C4101: 'mouseEvents': unreferenced local variable

## windows-x86-release

status: success

errors: 0
warnings: 0 in 0 kinds

### errors


### failure context


### warning kinds

