# Build digest

commit: a509f4cd68e0

- windows-x64-debug: cancelled
- windows-x64-release: cancelled
- windows-x64-release-dll: cancelled
- windows-x86-debug: cancelled
- windows-x86-release: failure

## windows-x64-debug

status: cancelled

errors: 87
warnings: 26 in 7 kinds

### errors

D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(20): error C2371: 'expOpType_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(49): error C2371: 'expOp_t': redefinition; different basic types
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\DeclManager.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\DeclRenderProg.cpp.obj] Error 2
neo\renderer\ParmBlock.cpp(16): error C2039: 'GetDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(16): error C2270: 'GetDest': modifiers not allowed on nonmember functions
neo\renderer\ParmBlock.cpp(17): error C2065: 'parmIndexDest': undeclared identifier
neo\renderer\ParmBlock.cpp(20): error C2039: 'GetA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(20): error C2270: 'GetA': modifiers not allowed on nonmember functions
neo\renderer\ParmBlock.cpp(21): error C2065: 'parmIndexA': undeclared identifier
neo\renderer\ParmBlock.cpp(44): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(44): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(45): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(45): error C2737: 'writeMask': const object must be initialized
neo\renderer\ParmBlock.cpp(48): error C2065: 'OP_TYPE_UNMASKED_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(51): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(54): error C2065: 'OP_TYPE_UNMASKED_MOVE': undeclared identifier
neo\renderer\ParmBlock.cpp(57): error C2065: 'OP_TYPE_MOVE': undeclared identifier
neo\renderer\ParmBlock.cpp(60): error C2065: 'OP_TYPE_SWIZZLE': undeclared identifier
neo\renderer\ParmBlock.cpp(91): error C2039: 'Fmod': is not a member of 'idMath'
neo\renderer\ParmBlock.cpp(91): error C3861: 'Fmod': identifier not found
neo\renderer\ParmBlock.cpp(106): error C2065: 'OP_TYPE_DOT3': undeclared identifier
neo\renderer\ParmBlock.cpp(114): error C2065: 'OP_TYPE_DOT4': undeclared identifier
neo\renderer\ParmBlock.cpp(48): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(51): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(54): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(57): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(60): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(106): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(114): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(134): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(183): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(183): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(184): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(184): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(187): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(187): error C2737: 'currentMask': const object must be initialized
neo\renderer\ParmBlock.cpp(188): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(188): error C2737: 'laterMask': const object must be initialized
neo\renderer\ParmBlock.cpp(189): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(223): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(226): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(226): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(227): error C2065: 'OP_TYPE_SWIZZLE': undeclared identifier
neo\renderer\ParmBlock.cpp(242): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(255): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(255): error C2737: 'oldType': const object must be initialized
neo\renderer\ParmBlock.cpp(256): error C2065: 'OP_TYPE_SWIZZLE': undeclared identifier
neo\renderer\ParmBlock.cpp(258): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(259): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(260): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(261): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(262): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(274): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(287): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(287): error C2737: 'oldType': const object must be initialized
neo\renderer\ParmBlock.cpp(288): error C2065: 'OP_TYPE_SWIZZLE': undeclared identifier
neo\renderer\ParmBlock.cpp(290): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(291): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(291): error C2065: 'OP_TYPE_UNMASKED_MOVE': undeclared identifier
neo\renderer\ParmBlock.cpp(292): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(293): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(294): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(341): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(365): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(366): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(366): error C2660: 'idParmBlock::GetRenderParmFromOps_r': function does not take 3 arguments
neo\renderer\ParmBlock.cpp(368): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(369): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(369): error C2660: 'idParmBlock::GetRenderParmFromOps_r': function does not take 3 arguments
neo\renderer\ParmBlock.cpp(413): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(413): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(414): error C2065: 'OP_TYPE_UNMASKED_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(414): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(419): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(419): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(420): error C2065: 'OP_TYPE_UNMASKED_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(420): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(424): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(428): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexB': is not a member of 'expOp_t'
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj] Error 2
neo\sys\win32\win_syscon.cpp(392): error C2065: 'GWL_WNDPROC': undeclared identifier
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\sys\win32\win_syscon.cpp.obj] Error 2

### failure context

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\DeclManager.cpp.obj

```
Common_tools.cpp
Compiling 'neo\framework\Compressor.cpp'
Compressor.cpp
neo\framework\Common_tools.cpp(40): warning C4245: 'initializing': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
Compiling 'neo\framework\Console.cpp'
Console.cpp
Compiling 'neo\framework\ConsoleHistory.cpp'
Compiling 'neo\framework\CVarSystem.cpp'
ConsoleHistory.cpp
CVarSystem.cpp
Compiling 'neo\framework\DebugGraph.cpp'
DebugGraph.cpp
Compiling 'neo\framework\DeclAF.cpp'
DeclAF.cpp
Compiling 'neo\framework\DeclEntityDef.cpp'
Compiling 'neo\framework\DeclFX.cpp'
DeclEntityDef.cpp
DeclFX.cpp
Compiling 'neo\framework\DeclManager.cpp'
DeclManager.cpp
Compiling 'neo\framework\DeclParticle.cpp'
DeclParticle.cpp
Compiling 'neo\framework\DeclPDA.cpp'
DeclPDA.cpp
Compiling 'neo\framework\DeclSkin.cpp'
DeclSkin.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(20): error C2371: 'expOpType_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(104): note: see declaration of 'expOpType_t'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(49): error C2371: 'expOp_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(137): note: see declaration of 'expOp_t'
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\DeclManager.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\DeclRenderProg.cpp.obj

```
Compiling 'neo\renderer\AutoRenderBink.cpp'
Compiling 'neo\renderer\BinaryImage.cpp'
AutoRenderBink.cpp
BinaryImage.cpp
Compiling 'neo\renderer\BufferObject.cpp'
BufferObject.cpp
Compiling 'neo\renderer\Cinematic.cpp'
Cinematic.cpp
neo\renderer\BufferObject.cpp(188): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
neo\renderer\BufferObject.cpp(433): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
neo\renderer\BufferObject.cpp(671): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
Compiling 'neo\renderer\CinematicBink.cpp'
CinematicBink.cpp
Compiling 'neo\renderer\CinematicRoQ.cpp'
CinematicRoQ.cpp
Compiling 'neo\renderer\Color\ColorSpace.cpp'
ColorSpace.cpp
Compiling 'neo\renderer\DeclRenderProg.cpp'
neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
DeclRenderProg.cpp
Compiling 'neo\renderer\DXT\DXTDecoder.cpp'
DXTDecoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder.cpp'
DXTEncoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder_SSE2.cpp'
DXTEncoder_SSE2.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(20): error C2371: 'expOpType_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(104): note: see declaration of 'expOpType_t'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(49): error C2371: 'expOp_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(137): note: see declaration of 'expOp_t'
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\DeclRenderProg.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj

```
neo\renderer\ParmBlock.cpp(414): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(419): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(419): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(420): error C2065: 'OP_TYPE_UNMASKED_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(420): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(424): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(424): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(428): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(428): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexA': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexA': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexB': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexB': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj] Error 2
```

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

errors: 87
warnings: 24 in 7 kinds

### errors

D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(20): error C2371: 'expOpType_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(49): error C2371: 'expOp_t': redefinition; different basic types
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\DeclManager.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\DeclRenderProg.cpp.obj] Error 2
neo\renderer\ParmBlock.cpp(16): error C2039: 'GetDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(16): error C2270: 'GetDest': modifiers not allowed on nonmember functions
neo\renderer\ParmBlock.cpp(17): error C2065: 'parmIndexDest': undeclared identifier
neo\renderer\ParmBlock.cpp(20): error C2039: 'GetA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(20): error C2270: 'GetA': modifiers not allowed on nonmember functions
neo\renderer\ParmBlock.cpp(21): error C2065: 'parmIndexA': undeclared identifier
neo\renderer\ParmBlock.cpp(44): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(44): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(45): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(45): error C2737: 'writeMask': const object must be initialized
neo\renderer\ParmBlock.cpp(48): error C2065: 'OP_TYPE_UNMASKED_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(51): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(54): error C2065: 'OP_TYPE_UNMASKED_MOVE': undeclared identifier
neo\renderer\ParmBlock.cpp(57): error C2065: 'OP_TYPE_MOVE': undeclared identifier
neo\renderer\ParmBlock.cpp(60): error C2065: 'OP_TYPE_SWIZZLE': undeclared identifier
neo\renderer\ParmBlock.cpp(91): error C2039: 'Fmod': is not a member of 'idMath'
neo\renderer\ParmBlock.cpp(91): error C3861: 'Fmod': identifier not found
neo\renderer\ParmBlock.cpp(106): error C2065: 'OP_TYPE_DOT3': undeclared identifier
neo\renderer\ParmBlock.cpp(114): error C2065: 'OP_TYPE_DOT4': undeclared identifier
neo\renderer\ParmBlock.cpp(48): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(51): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(54): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(57): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(60): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(106): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(114): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(134): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(183): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(183): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(184): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(184): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(187): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(187): error C2737: 'currentMask': const object must be initialized
neo\renderer\ParmBlock.cpp(188): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(188): error C2737: 'laterMask': const object must be initialized
neo\renderer\ParmBlock.cpp(189): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(223): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(226): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(226): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(227): error C2065: 'OP_TYPE_SWIZZLE': undeclared identifier
neo\renderer\ParmBlock.cpp(242): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(255): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(255): error C2737: 'oldType': const object must be initialized
neo\renderer\ParmBlock.cpp(256): error C2065: 'OP_TYPE_SWIZZLE': undeclared identifier
neo\renderer\ParmBlock.cpp(258): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(259): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(260): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(261): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(262): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(274): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(287): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(287): error C2737: 'oldType': const object must be initialized
neo\renderer\ParmBlock.cpp(288): error C2065: 'OP_TYPE_SWIZZLE': undeclared identifier
neo\renderer\ParmBlock.cpp(290): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(291): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(291): error C2065: 'OP_TYPE_UNMASKED_MOVE': undeclared identifier
neo\renderer\ParmBlock.cpp(292): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(293): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(294): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(341): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(365): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(366): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(366): error C2660: 'idParmBlock::GetRenderParmFromOps_r': function does not take 3 arguments
neo\renderer\ParmBlock.cpp(368): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(369): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(369): error C2660: 'idParmBlock::GetRenderParmFromOps_r': function does not take 3 arguments
neo\renderer\ParmBlock.cpp(413): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(413): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(414): error C2065: 'OP_TYPE_UNMASKED_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(414): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(419): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(419): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(420): error C2065: 'OP_TYPE_UNMASKED_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(420): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(424): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(428): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexB': is not a member of 'expOp_t'
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj] Error 2
neo\sys\win32\win_syscon.cpp(392): error C2065: 'GWL_WNDPROC': undeclared identifier
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\sys\win32\win_syscon.cpp.obj] Error 2

### failure context

- build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\DeclManager.cpp.obj

```
Common_tools.cpp
Compiling 'neo\framework\Compressor.cpp'
Compressor.cpp
Compiling 'neo\framework\Console.cpp'
Console.cpp
Compiling 'neo\framework\ConsoleHistory.cpp'
ConsoleHistory.cpp
neo\framework\Common_tools.cpp(40): warning C4245: 'initializing': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
Compiling 'neo\framework\CVarSystem.cpp'
CVarSystem.cpp
Compiling 'neo\framework\DebugGraph.cpp'
Compiling 'neo\framework\DeclAF.cpp'
Compiling 'neo\framework\DeclEntityDef.cpp'
DebugGraph.cpp
DeclAF.cpp
DeclEntityDef.cpp
Compiling 'neo\framework\DeclFX.cpp'
DeclFX.cpp
Compiling 'neo\framework\DeclManager.cpp'
Compiling 'neo\framework\DeclParticle.cpp'
DeclManager.cpp
DeclParticle.cpp
Compiling 'neo\framework\DeclPDA.cpp'
DeclPDA.cpp
Compiling 'neo\framework\DeclSkin.cpp'
DeclSkin.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(20): error C2371: 'expOpType_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(104): note: see declaration of 'expOpType_t'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(49): error C2371: 'expOp_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(137): note: see declaration of 'expOp_t'
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\DeclManager.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\DeclRenderProg.cpp.obj

```
Compiling 'neo\renderer\AutoRenderBink.cpp'
AutoRenderBink.cpp
Compiling 'neo\renderer\BinaryImage.cpp'
BinaryImage.cpp
Compiling 'neo\renderer\BufferObject.cpp'
BufferObject.cpp
Compiling 'neo\renderer\Cinematic.cpp'
Cinematic.cpp
neo\renderer\BufferObject.cpp(188): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
neo\renderer\BufferObject.cpp(433): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
neo\renderer\BufferObject.cpp(671): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
Compiling 'neo\renderer\CinematicBink.cpp'
CinematicBink.cpp
Compiling 'neo\renderer\CinematicRoQ.cpp'
Compiling 'neo\renderer\Color\ColorSpace.cpp'
CinematicRoQ.cpp
ColorSpace.cpp
Compiling 'neo\renderer\DeclRenderProg.cpp'
DeclRenderProg.cpp
neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
Compiling 'neo\renderer\DXT\DXTDecoder.cpp'
DXTDecoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder.cpp'
DXTEncoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder_SSE2.cpp'
DXTEncoder_SSE2.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(20): error C2371: 'expOpType_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(104): note: see declaration of 'expOpType_t'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(49): error C2371: 'expOp_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(137): note: see declaration of 'expOp_t'
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\DeclRenderProg.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj

```
neo\renderer\ParmBlock.cpp(414): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(419): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(419): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(420): error C2065: 'OP_TYPE_UNMASKED_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(420): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(424): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(424): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(428): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(428): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexA': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexA': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexB': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexB': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj] Error 2
```

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


### warning kinds

- [5x] C4389
  - neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1498): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1516): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1536): warning C4389: '!=': signed/unsigned mismatch
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
- [2x] C4245
  - neo\framework\Common_tools.cpp(40): warning C4245: 'initializing': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [1x] C4101
  - neo\framework\Common.cpp(777): warning C4101: 'mouseEvents': unreferenced local variable

## windows-x64-release

status: cancelled

errors: 85
warnings: 22 in 7 kinds

### errors

D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(20): error C2371: 'expOpType_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(49): error C2371: 'expOp_t': redefinition; different basic types
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\DeclManager.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\DeclRenderProg.cpp.obj] Error 2
neo\renderer\ParmBlock.cpp(16): error C2039: 'GetDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(16): error C2270: 'GetDest': modifiers not allowed on nonmember functions
neo\renderer\ParmBlock.cpp(17): error C2065: 'parmIndexDest': undeclared identifier
neo\renderer\ParmBlock.cpp(20): error C2039: 'GetA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(20): error C2270: 'GetA': modifiers not allowed on nonmember functions
neo\renderer\ParmBlock.cpp(21): error C2065: 'parmIndexA': undeclared identifier
neo\renderer\ParmBlock.cpp(44): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(44): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(45): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(45): error C2737: 'writeMask': const object must be initialized
neo\renderer\ParmBlock.cpp(48): error C2065: 'OP_TYPE_UNMASKED_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(51): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(54): error C2065: 'OP_TYPE_UNMASKED_MOVE': undeclared identifier
neo\renderer\ParmBlock.cpp(57): error C2065: 'OP_TYPE_MOVE': undeclared identifier
neo\renderer\ParmBlock.cpp(60): error C2065: 'OP_TYPE_SWIZZLE': undeclared identifier
neo\renderer\ParmBlock.cpp(91): error C2039: 'Fmod': is not a member of 'idMath'
neo\renderer\ParmBlock.cpp(91): error C3861: 'Fmod': identifier not found
neo\renderer\ParmBlock.cpp(106): error C2065: 'OP_TYPE_DOT3': undeclared identifier
neo\renderer\ParmBlock.cpp(114): error C2065: 'OP_TYPE_DOT4': undeclared identifier
neo\renderer\ParmBlock.cpp(48): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(51): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(54): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(57): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(60): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(106): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(114): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(134): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(183): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(183): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(184): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(184): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(187): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(187): error C2737: 'currentMask': const object must be initialized
neo\renderer\ParmBlock.cpp(188): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(188): error C2737: 'laterMask': const object must be initialized
neo\renderer\ParmBlock.cpp(189): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(223): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(226): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(226): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(227): error C2065: 'OP_TYPE_SWIZZLE': undeclared identifier
neo\renderer\ParmBlock.cpp(242): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(255): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(255): error C2737: 'oldType': const object must be initialized
neo\renderer\ParmBlock.cpp(256): error C2065: 'OP_TYPE_SWIZZLE': undeclared identifier
neo\renderer\ParmBlock.cpp(258): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(259): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(260): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(261): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(262): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(274): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(287): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(287): error C2737: 'oldType': const object must be initialized
neo\renderer\ParmBlock.cpp(288): error C2065: 'OP_TYPE_SWIZZLE': undeclared identifier
neo\renderer\ParmBlock.cpp(290): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(291): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(291): error C2065: 'OP_TYPE_UNMASKED_MOVE': undeclared identifier
neo\renderer\ParmBlock.cpp(292): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(293): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(294): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(341): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(365): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(366): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(366): error C2660: 'idParmBlock::GetRenderParmFromOps_r': function does not take 3 arguments
neo\renderer\ParmBlock.cpp(368): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(369): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(369): error C2660: 'idParmBlock::GetRenderParmFromOps_r': function does not take 3 arguments
neo\renderer\ParmBlock.cpp(413): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(413): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(414): error C2065: 'OP_TYPE_UNMASKED_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(414): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(419): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(419): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(420): error C2065: 'OP_TYPE_UNMASKED_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(420): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(424): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(428): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexB': is not a member of 'expOp_t'
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj] Error 2

### failure context

- build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\DeclManager.cpp.obj

```
Common_tools.cpp
Compiling 'neo\framework\Compressor.cpp'
Compressor.cpp
Compiling 'neo\framework\Console.cpp'
Compiling 'neo\framework\ConsoleHistory.cpp'
Console.cpp
ConsoleHistory.cpp
neo\framework\Common_tools.cpp(40): warning C4245: 'initializing': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
Compiling 'neo\framework\CVarSystem.cpp'
CVarSystem.cpp
Compiling 'neo\framework\DebugGraph.cpp'
DebugGraph.cpp
Compiling 'neo\framework\DeclAF.cpp'
DeclAF.cpp
Compiling 'neo\framework\DeclEntityDef.cpp'
DeclEntityDef.cpp
Compiling 'neo\framework\DeclFX.cpp'
DeclFX.cpp
Compiling 'neo\framework\DeclManager.cpp'
DeclManager.cpp
Compiling 'neo\framework\DeclParticle.cpp'
DeclParticle.cpp
Compiling 'neo\framework\DeclPDA.cpp'
DeclPDA.cpp
Compiling 'neo\framework\DeclSkin.cpp'
DeclSkin.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(20): error C2371: 'expOpType_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(104): note: see declaration of 'expOpType_t'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(49): error C2371: 'expOp_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(137): note: see declaration of 'expOp_t'
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\DeclManager.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\DeclRenderProg.cpp.obj

```
Compiling 'neo\renderer\AutoRenderBink.cpp'
AutoRenderBink.cpp
Compiling 'neo\renderer\BinaryImage.cpp'
BinaryImage.cpp
Compiling 'neo\renderer\BufferObject.cpp'
BufferObject.cpp
neo\renderer\BufferObject.cpp(188): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
neo\renderer\BufferObject.cpp(433): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
neo\renderer\BufferObject.cpp(671): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
Compiling 'neo\renderer\Cinematic.cpp'
Cinematic.cpp
Compiling 'neo\renderer\CinematicBink.cpp'
CinematicBink.cpp
Compiling 'neo\renderer\CinematicRoQ.cpp'
CinematicRoQ.cpp
Compiling 'neo\renderer\Color\ColorSpace.cpp'
ColorSpace.cpp
neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
Compiling 'neo\renderer\DeclRenderProg.cpp'
DeclRenderProg.cpp
Compiling 'neo\renderer\DXT\DXTDecoder.cpp'
DXTDecoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder.cpp'
Compiling 'neo\renderer\DXT\DXTEncoder_SSE2.cpp'
DXTEncoder.cpp
DXTEncoder_SSE2.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(20): error C2371: 'expOpType_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(104): note: see declaration of 'expOpType_t'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(49): error C2371: 'expOp_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(137): note: see declaration of 'expOp_t'
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\DeclRenderProg.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj

```
neo\renderer\ParmBlock.cpp(414): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(419): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(419): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(420): error C2065: 'OP_TYPE_UNMASKED_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(420): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(424): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(424): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(428): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(428): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexA': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexA': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexB': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexB': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj] Error 2
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
- [1x] C4101
  - neo\framework\Common.cpp(777): warning C4101: 'mouseEvents': unreferenced local variable
- [1x] C4311
  - neo\renderer\tr_backend_rendertools.cpp(724): warning C4311: 'type cast': pointer truncation from 'void *' to 'GLuint'
- [1x] C4302
  - neo\renderer\tr_backend_rendertools.cpp(724): warning C4302: 'type cast': truncation from 'void *' to 'GLuint'

## windows-x86-debug

status: cancelled

errors: 85
warnings: 14 in 3 kinds

### errors

D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(20): error C2371: 'expOpType_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(49): error C2371: 'expOp_t': redefinition; different basic types
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\DeclManager.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\DeclRenderProg.cpp.obj] Error 2
neo\renderer\ParmBlock.cpp(16): error C2039: 'GetDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(16): error C2270: 'GetDest': modifiers not allowed on nonmember functions
neo\renderer\ParmBlock.cpp(17): error C2065: 'parmIndexDest': undeclared identifier
neo\renderer\ParmBlock.cpp(20): error C2039: 'GetA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(20): error C2270: 'GetA': modifiers not allowed on nonmember functions
neo\renderer\ParmBlock.cpp(21): error C2065: 'parmIndexA': undeclared identifier
neo\renderer\ParmBlock.cpp(44): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(44): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(45): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(45): error C2737: 'writeMask': const object must be initialized
neo\renderer\ParmBlock.cpp(48): error C2065: 'OP_TYPE_UNMASKED_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(51): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(54): error C2065: 'OP_TYPE_UNMASKED_MOVE': undeclared identifier
neo\renderer\ParmBlock.cpp(57): error C2065: 'OP_TYPE_MOVE': undeclared identifier
neo\renderer\ParmBlock.cpp(60): error C2065: 'OP_TYPE_SWIZZLE': undeclared identifier
neo\renderer\ParmBlock.cpp(91): error C2039: 'Fmod': is not a member of 'idMath'
neo\renderer\ParmBlock.cpp(91): error C3861: 'Fmod': identifier not found
neo\renderer\ParmBlock.cpp(106): error C2065: 'OP_TYPE_DOT3': undeclared identifier
neo\renderer\ParmBlock.cpp(114): error C2065: 'OP_TYPE_DOT4': undeclared identifier
neo\renderer\ParmBlock.cpp(48): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(51): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(54): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(57): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(60): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(106): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(114): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(134): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(183): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(183): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(184): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(184): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(187): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(187): error C2737: 'currentMask': const object must be initialized
neo\renderer\ParmBlock.cpp(188): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(188): error C2737: 'laterMask': const object must be initialized
neo\renderer\ParmBlock.cpp(189): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(223): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(226): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(226): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(227): error C2065: 'OP_TYPE_SWIZZLE': undeclared identifier
neo\renderer\ParmBlock.cpp(242): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(255): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(255): error C2737: 'oldType': const object must be initialized
neo\renderer\ParmBlock.cpp(256): error C2065: 'OP_TYPE_SWIZZLE': undeclared identifier
neo\renderer\ParmBlock.cpp(258): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(259): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(260): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(261): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(262): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(274): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(287): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(287): error C2737: 'oldType': const object must be initialized
neo\renderer\ParmBlock.cpp(288): error C2065: 'OP_TYPE_SWIZZLE': undeclared identifier
neo\renderer\ParmBlock.cpp(290): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(291): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(291): error C2065: 'OP_TYPE_UNMASKED_MOVE': undeclared identifier
neo\renderer\ParmBlock.cpp(292): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(293): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(294): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(341): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(365): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(366): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(366): error C2660: 'idParmBlock::GetRenderParmFromOps_r': function does not take 3 arguments
neo\renderer\ParmBlock.cpp(368): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(369): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(369): error C2660: 'idParmBlock::GetRenderParmFromOps_r': function does not take 3 arguments
neo\renderer\ParmBlock.cpp(413): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(413): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(414): error C2065: 'OP_TYPE_UNMASKED_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(414): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(419): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(419): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(420): error C2065: 'OP_TYPE_UNMASKED_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(420): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(424): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(428): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexB': is not a member of 'expOp_t'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj] Error 2

### failure context

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\DeclManager.cpp.obj

```
Common_tools.cpp
Compiling 'neo\framework\Compressor.cpp'
Compressor.cpp
Compiling 'neo\framework\Console.cpp'
Console.cpp
neo\framework\Common_tools.cpp(40): warning C4245: 'initializing': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
Compiling 'neo\framework\ConsoleHistory.cpp'
ConsoleHistory.cpp
Compiling 'neo\framework\CVarSystem.cpp'
CVarSystem.cpp
Compiling 'neo\framework\DebugGraph.cpp'
DebugGraph.cpp
Compiling 'neo\framework\DeclAF.cpp'
DeclAF.cpp
Compiling 'neo\framework\DeclEntityDef.cpp'
DeclEntityDef.cpp
Compiling 'neo\framework\DeclFX.cpp'
DeclFX.cpp
Compiling 'neo\framework\DeclManager.cpp'
DeclManager.cpp
Compiling 'neo\framework\DeclParticle.cpp'
DeclParticle.cpp
Compiling 'neo\framework\DeclPDA.cpp'
DeclPDA.cpp
Compiling 'neo\framework\DeclSkin.cpp'
DeclSkin.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(20): error C2371: 'expOpType_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(104): note: see declaration of 'expOpType_t'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(49): error C2371: 'expOp_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(137): note: see declaration of 'expOp_t'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\DeclManager.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\DeclRenderProg.cpp.obj

```
Zip.cpp
Compiling 'neo\renderer\AutoRender.cpp'
AutoRender.cpp
Compiling 'neo\renderer\AutoRenderBink.cpp'
AutoRenderBink.cpp
Compiling 'neo\renderer\BinaryImage.cpp'
BinaryImage.cpp
Compiling 'neo\renderer\BufferObject.cpp'
BufferObject.cpp
Compiling 'neo\renderer\Cinematic.cpp'
Cinematic.cpp
Compiling 'neo\renderer\CinematicBink.cpp'
CinematicBink.cpp
Compiling 'neo\renderer\CinematicRoQ.cpp'
CinematicRoQ.cpp
Compiling 'neo\renderer\Color\ColorSpace.cpp'
ColorSpace.cpp
Compiling 'neo\renderer\DeclRenderProg.cpp'
DeclRenderProg.cpp
neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
Compiling 'neo\renderer\DXT\DXTDecoder.cpp'
DXTDecoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder.cpp'
DXTEncoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder_SSE2.cpp'
DXTEncoder_SSE2.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(20): error C2371: 'expOpType_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(104): note: see declaration of 'expOpType_t'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(49): error C2371: 'expOp_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(137): note: see declaration of 'expOp_t'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\DeclRenderProg.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj

```
neo\renderer\ParmBlock.cpp(414): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(419): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(419): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(420): error C2065: 'OP_TYPE_UNMASKED_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(420): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(424): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(424): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(428): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(428): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexA': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexA': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexB': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexB': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj] Error 2
```


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
- [1x] C4101
  - neo\framework\Common.cpp(777): warning C4101: 'mouseEvents': unreferenced local variable

## windows-x86-release

status: failure

errors: 85
warnings: 21 in 5 kinds

### errors

D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(20): error C2371: 'expOpType_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(49): error C2371: 'expOp_t': redefinition; different basic types
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\DeclManager.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\DeclRenderProg.cpp.obj] Error 2
neo\renderer\ParmBlock.cpp(16): error C2039: 'GetDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(16): error C2270: 'GetDest': modifiers not allowed on nonmember functions
neo\renderer\ParmBlock.cpp(17): error C2065: 'parmIndexDest': undeclared identifier
neo\renderer\ParmBlock.cpp(20): error C2039: 'GetA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(20): error C2270: 'GetA': modifiers not allowed on nonmember functions
neo\renderer\ParmBlock.cpp(21): error C2065: 'parmIndexA': undeclared identifier
neo\renderer\ParmBlock.cpp(44): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(44): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(45): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(45): error C2737: 'writeMask': const object must be initialized
neo\renderer\ParmBlock.cpp(48): error C2065: 'OP_TYPE_UNMASKED_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(51): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(54): error C2065: 'OP_TYPE_UNMASKED_MOVE': undeclared identifier
neo\renderer\ParmBlock.cpp(57): error C2065: 'OP_TYPE_MOVE': undeclared identifier
neo\renderer\ParmBlock.cpp(60): error C2065: 'OP_TYPE_SWIZZLE': undeclared identifier
neo\renderer\ParmBlock.cpp(91): error C2039: 'Fmod': is not a member of 'idMath'
neo\renderer\ParmBlock.cpp(91): error C3861: 'Fmod': identifier not found
neo\renderer\ParmBlock.cpp(106): error C2065: 'OP_TYPE_DOT3': undeclared identifier
neo\renderer\ParmBlock.cpp(114): error C2065: 'OP_TYPE_DOT4': undeclared identifier
neo\renderer\ParmBlock.cpp(48): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(51): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(54): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(57): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(60): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(106): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(114): error C2051: case expression not constant
neo\renderer\ParmBlock.cpp(134): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(183): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(183): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(184): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(184): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(187): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(187): error C2737: 'currentMask': const object must be initialized
neo\renderer\ParmBlock.cpp(188): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(188): error C2737: 'laterMask': const object must be initialized
neo\renderer\ParmBlock.cpp(189): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(223): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(226): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(226): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(227): error C2065: 'OP_TYPE_SWIZZLE': undeclared identifier
neo\renderer\ParmBlock.cpp(242): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(255): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(255): error C2737: 'oldType': const object must be initialized
neo\renderer\ParmBlock.cpp(256): error C2065: 'OP_TYPE_SWIZZLE': undeclared identifier
neo\renderer\ParmBlock.cpp(258): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(259): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(260): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(261): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(262): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(274): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(287): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(287): error C2737: 'oldType': const object must be initialized
neo\renderer\ParmBlock.cpp(288): error C2065: 'OP_TYPE_SWIZZLE': undeclared identifier
neo\renderer\ParmBlock.cpp(290): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(291): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(291): error C2065: 'OP_TYPE_UNMASKED_MOVE': undeclared identifier
neo\renderer\ParmBlock.cpp(292): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(293): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(294): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(341): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(365): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(366): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(366): error C2660: 'idParmBlock::GetRenderParmFromOps_r': function does not take 3 arguments
neo\renderer\ParmBlock.cpp(368): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(369): error C2039: 'parmIndexB': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(369): error C2660: 'idParmBlock::GetRenderParmFromOps_r': function does not take 3 arguments
neo\renderer\ParmBlock.cpp(413): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(413): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(414): error C2065: 'OP_TYPE_UNMASKED_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(414): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(419): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(419): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(420): error C2065: 'OP_TYPE_UNMASKED_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(420): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(424): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(428): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'type': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexA': is not a member of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexB': is not a member of 'expOp_t'
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj] Error 2

### failure context

- build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\DeclManager.cpp.obj

```
Common_tools.cpp
Compiling 'neo\framework\Compressor.cpp'
Compressor.cpp
Compiling 'neo\framework\Console.cpp'
Console.cpp
neo\framework\Common_tools.cpp(40): warning C4245: 'initializing': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
Compiling 'neo\framework\ConsoleHistory.cpp'
ConsoleHistory.cpp
Compiling 'neo\framework\CVarSystem.cpp'
CVarSystem.cpp
Compiling 'neo\framework\DebugGraph.cpp'
DebugGraph.cpp
Compiling 'neo\framework\DeclAF.cpp'
DeclAF.cpp
Compiling 'neo\framework\DeclEntityDef.cpp'
DeclEntityDef.cpp
Compiling 'neo\framework\DeclFX.cpp'
DeclFX.cpp
Compiling 'neo\framework\DeclManager.cpp'
DeclManager.cpp
Compiling 'neo\framework\DeclParticle.cpp'
DeclParticle.cpp
Compiling 'neo\framework\DeclPDA.cpp'
DeclPDA.cpp
Compiling 'neo\framework\DeclSkin.cpp'
DeclSkin.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(20): error C2371: 'expOpType_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(104): note: see declaration of 'expOpType_t'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(49): error C2371: 'expOp_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(137): note: see declaration of 'expOp_t'
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\DeclManager.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\DeclRenderProg.cpp.obj

```
Zip.cpp
Compiling 'neo\renderer\AutoRender.cpp'
AutoRender.cpp
Compiling 'neo\renderer\AutoRenderBink.cpp'
Compiling 'neo\renderer\BinaryImage.cpp'
Compiling 'neo\renderer\BufferObject.cpp'
AutoRenderBink.cpp
BinaryImage.cpp
BufferObject.cpp
Compiling 'neo\renderer\Cinematic.cpp'
Cinematic.cpp
Compiling 'neo\renderer\CinematicBink.cpp'
CinematicBink.cpp
Compiling 'neo\renderer\CinematicRoQ.cpp'
CinematicRoQ.cpp
Compiling 'neo\renderer\Color\ColorSpace.cpp'
ColorSpace.cpp
Compiling 'neo\renderer\DeclRenderProg.cpp'
DeclRenderProg.cpp
neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
Compiling 'neo\renderer\DXT\DXTDecoder.cpp'
DXTDecoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder.cpp'
DXTEncoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder_SSE2.cpp'
DXTEncoder_SSE2.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(20): error C2371: 'expOpType_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(104): note: see declaration of 'expOpType_t'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\ParmBlock.h(49): error C2371: 'expOp_t': redefinition; different basic types
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(137): note: see declaration of 'expOp_t'
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\DeclRenderProg.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj

```
neo\renderer\ParmBlock.cpp(414): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(419): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(419): error C2737: 'type': const object must be initialized
neo\renderer\ParmBlock.cpp(420): error C2065: 'OP_TYPE_UNMASKED_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(420): error C2065: 'OP_TYPE_MOVE_CONSTANT': undeclared identifier
neo\renderer\ParmBlock.cpp(424): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(424): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(428): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(428): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'type': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(443): error C2039: 'parmIndexDest': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexA': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexA': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexB': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
neo\renderer\ParmBlock.cpp(444): error C2039: 'parmIndexB': is not a member of 'expOp_t'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/Material.h(134): note: see declaration of 'expOp_t'
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj] Error 2
```


### warning kinds

- [7x] C4389
  - neo\d3xp\gamesys\Event.cpp(853): warning C4389: '!=': signed/unsigned mismatch
  - neo\d3xp\gamesys\Event.cpp(943): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1498): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1516): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1536): warning C4389: '!=': signed/unsigned mismatch
- [6x] C4702
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(368) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1048) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1345) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1379) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1390) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1422) : warning C4702: unreachable code
- [4x] C4245
  - neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\framework\Common_tools.cpp(40): warning C4245: 'initializing': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [3x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\renderbump\renderbump.cpp(1318) : warning C4701: potentially uninitialized local variable 'opt' used
- [1x] C4101
  - neo\framework\Common.cpp(777): warning C4101: 'mouseEvents': unreferenced local variable

