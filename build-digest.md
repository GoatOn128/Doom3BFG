# Build digest

commit: 1c14a2f0e858

- windows-x64-debug: cancelled
- windows-x64-release: cancelled
- windows-x86-debug: cancelled
- windows-x86-release: failure

## windows-x64-debug

status: cancelled

errors: 0
warnings: 6 in 2 kinds

### errors


### failure context


### warning kinds

- [3x] C4245
  - neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [3x] C4312
  - neo\renderer\BufferObject.cpp(188): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - neo\renderer\BufferObject.cpp(433): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - neo\renderer\BufferObject.cpp(671): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size

## windows-x64-release

status: cancelled

errors: 6
warnings: 12 in 3 kinds

### errors

neo\renderer\RenderWorld.cpp(387): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
neo\renderer\RenderWorld.cpp(418): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderWorld.cpp.obj] Error 2
neo\renderer\RenderWorld_defs.cpp(446): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
neo\renderer\RenderWorld_defs.cpp(450): error C2039: 'PushFrustumIntoTree': is not a member of 'idRenderWorldLocal'
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderWorld_defs.cpp.obj] Error 2

### failure context

- build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderWorld.cpp.obj

```
Compiling 'neo\renderer\RenderEntity.cpp'
RenderEntity.cpp
Compiling 'neo\renderer\RenderLightCommitted.cpp'
RenderLightCommitted.cpp
Compiling 'neo\renderer\RenderLightParms.cpp'
RenderLightParms.cpp
Compiling 'neo\renderer\RenderLog.cpp'
RenderLog.cpp
Compiling 'neo\renderer\RenderModelCommitted.cpp'
RenderModelCommitted.cpp
Compiling 'neo\renderer\RenderModelParms.cpp'
RenderModelParms.cpp
Compiling 'neo\renderer\RenderProgParm.cpp'
RenderProgParm.cpp
Compiling 'neo\renderer\RenderProgs.cpp'
RenderProgs.cpp
Compiling 'neo\renderer\RenderSystem.cpp'
RenderSystem.cpp
Compiling 'neo\renderer\RenderSystem_init.cpp'
RenderSystem_init.cpp
Compiling 'neo\renderer\RenderWorld.cpp'
RenderWorld.cpp
Compiling 'neo\renderer\RenderWorld_defs.cpp'
RenderWorld_defs.cpp
Compiling 'neo\renderer\RenderWorld_demo.cpp'
RenderWorld_demo.cpp
neo\renderer\RenderWorld.cpp(387): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\RenderWorld.cpp(418): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderWorld.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderWorld_defs.cpp.obj

```
RenderLog.cpp
Compiling 'neo\renderer\RenderModelCommitted.cpp'
RenderModelCommitted.cpp
Compiling 'neo\renderer\RenderModelParms.cpp'
RenderModelParms.cpp
Compiling 'neo\renderer\RenderProgParm.cpp'
RenderProgParm.cpp
Compiling 'neo\renderer\RenderProgs.cpp'
RenderProgs.cpp
Compiling 'neo\renderer\RenderSystem.cpp'
RenderSystem.cpp
Compiling 'neo\renderer\RenderSystem_init.cpp'
RenderSystem_init.cpp
Compiling 'neo\renderer\RenderWorld.cpp'
RenderWorld.cpp
Compiling 'neo\renderer\RenderWorld_defs.cpp'
RenderWorld_defs.cpp
Compiling 'neo\renderer\RenderWorld_demo.cpp'
RenderWorld_demo.cpp
neo\renderer\RenderWorld.cpp(387): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\RenderWorld.cpp(418): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderWorld.cpp.obj] Error 2
Compiling 'neo\renderer\RenderWorld_load.cpp'
RenderWorld_load.cpp
neo\renderer\RenderWorld_defs.cpp(446): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\RenderWorld_defs.cpp(450): error C2039: 'PushFrustumIntoTree': is not a member of 'idRenderWorldLocal'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderWorld_local.h(93): note: see declaration of 'idRenderWorldLocal'
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderWorld_defs.cpp.obj] Error 2
```


### warning kinds

- [6x] C4702
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(368) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1048) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1345) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1379) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1390) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1422) : warning C4702: unreachable code
- [3x] C4245
  - neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [3x] C4312
  - neo\renderer\BufferObject.cpp(188): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - neo\renderer\BufferObject.cpp(433): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - neo\renderer\BufferObject.cpp(671): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size

## windows-x86-debug

status: cancelled

errors: 19
warnings: 14 in 3 kinds

### errors

neo\renderer\RenderWorld.cpp(387): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
neo\renderer\RenderWorld.cpp(418): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderWorld.cpp.obj] Error 2
neo\renderer\RenderWorld_defs.cpp(446): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
neo\renderer\RenderWorld_defs.cpp(450): error C2039: 'PushFrustumIntoTree': is not a member of 'idRenderWorldLocal'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderWorld_defs.cpp.obj] Error 2
neo\renderer\tr_frontend_addlights.cpp(352): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(353): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(406): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(407): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(411): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\tr_frontend_addlights.cpp.obj] Error 2
neo\renderer\tr_frontend_addmodels.cpp(388): error C2065: 'areaReference_t': undeclared identifier
neo\renderer\tr_frontend_addmodels.cpp(388): error C2065: 'ref': undeclared identifier
neo\renderer\tr_frontend_addmodels.cpp(388): error C2039: 'entityRefs': is not a member of 'idRenderEntityLocal'
neo\renderer\tr_frontend_addmodels.cpp(389): error C2065: 'ref': undeclared identifier
neo\renderer\tr_frontend_addmodels.cpp(389): error C2660: 'idRenderWorldLocal::AreasAreConnected': function does not take 2 arguments
neo\renderer\tr_frontend_addmodels.cpp(727): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\tr_frontend_addmodels.cpp.obj] Error 2

### failure context

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderWorld.cpp.obj

```
Compiling 'neo\renderer\RenderEntity.cpp'
RenderEntity.cpp
Compiling 'neo\renderer\RenderLightCommitted.cpp'
RenderLightCommitted.cpp
Compiling 'neo\renderer\RenderLightParms.cpp'
RenderLightParms.cpp
Compiling 'neo\renderer\RenderLog.cpp'
RenderLog.cpp
Compiling 'neo\renderer\RenderModelCommitted.cpp'
RenderModelCommitted.cpp
Compiling 'neo\renderer\RenderModelParms.cpp'
RenderModelParms.cpp
Compiling 'neo\renderer\RenderProgParm.cpp'
RenderProgParm.cpp
Compiling 'neo\renderer\RenderProgs.cpp'
RenderProgs.cpp
Compiling 'neo\renderer\RenderSystem.cpp'
RenderSystem.cpp
Compiling 'neo\renderer\RenderSystem_init.cpp'
RenderSystem_init.cpp
Compiling 'neo\renderer\RenderWorld.cpp'
RenderWorld.cpp
Compiling 'neo\renderer\RenderWorld_defs.cpp'
RenderWorld_defs.cpp
Compiling 'neo\renderer\RenderWorld_demo.cpp'
RenderWorld_demo.cpp
neo\renderer\RenderWorld.cpp(387): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\RenderWorld.cpp(418): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderWorld.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderWorld_defs.cpp.obj

```
RenderModelCommitted.cpp
Compiling 'neo\renderer\RenderModelParms.cpp'
RenderModelParms.cpp
Compiling 'neo\renderer\RenderProgParm.cpp'
RenderProgParm.cpp
Compiling 'neo\renderer\RenderProgs.cpp'
RenderProgs.cpp
Compiling 'neo\renderer\RenderSystem.cpp'
RenderSystem.cpp
Compiling 'neo\renderer\RenderSystem_init.cpp'
RenderSystem_init.cpp
Compiling 'neo\renderer\RenderWorld.cpp'
RenderWorld.cpp
Compiling 'neo\renderer\RenderWorld_defs.cpp'
RenderWorld_defs.cpp
Compiling 'neo\renderer\RenderWorld_demo.cpp'
RenderWorld_demo.cpp
neo\renderer\RenderWorld.cpp(387): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\RenderWorld.cpp(418): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderWorld.cpp.obj] Error 2
Compiling 'neo\renderer\RenderWorld_load.cpp'
RenderWorld_load.cpp
Compiling 'neo\renderer\RenderWorld_portals.cpp'
RenderWorld_portals.cpp
neo\renderer\RenderWorld_defs.cpp(446): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\RenderWorld_defs.cpp(450): error C2039: 'PushFrustumIntoTree': is not a member of 'idRenderWorldLocal'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderWorld_local.h(93): note: see declaration of 'idRenderWorldLocal'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderWorld_defs.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\tr_frontend_addlights.cpp.obj

```
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderWorld_local.h(93): note: see declaration of 'idRenderWorldLocal'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderWorld_defs.cpp.obj] Error 2
Compiling 'neo\renderer\ResolutionScale.cpp'
ResolutionScale.cpp
Compiling 'neo\renderer\ScreenRect.cpp'
ScreenRect.cpp
Retrieved `build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\stblib_impls.c.obj' from cache
Compiling 'neo\renderer\tr_backend_draw.cpp'
tr_backend_draw.cpp
Compiling 'neo\renderer\tr_backend_rendertools.cpp'
tr_backend_rendertools.cpp
Compiling 'neo\renderer\tr_frontend_addlights.cpp'
tr_frontend_addlights.cpp
neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_draw.cpp(1488): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_draw.cpp(1506): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_draw.cpp(1526): warning C4389: '!=': signed/unsigned mismatch
Compiling 'neo\renderer\tr_frontend_addmodels.cpp'
tr_frontend_addmodels.cpp
neo\renderer\tr_frontend_addlights.cpp(352): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(353): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(406): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(407): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(411): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\tr_frontend_addlights.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\tr_frontend_addmodels.cpp.obj

```
neo\renderer\tr_frontend_addlights.cpp(352): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(353): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(406): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(407): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(411): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\tr_frontend_addlights.cpp.obj] Error 2
Compiling 'neo\renderer\tr_frontend_deform.cpp'
tr_frontend_deform.cpp
Compiling 'neo\renderer\tr_frontend_guisurf.cpp'
tr_frontend_guisurf.cpp
Compiling 'neo\renderer\tr_frontend_main.cpp'
tr_frontend_main.cpp
neo\renderer\tr_frontend_addmodels.cpp(388): error C2065: 'areaReference_t': undeclared identifier
neo\renderer\tr_frontend_addmodels.cpp(388): error C2065: 'ref': undeclared identifier
neo\renderer\tr_frontend_addmodels.cpp(388): error C2039: 'entityRefs': is not a member of 'idRenderEntityLocal'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_local.h(206): note: see declaration of 'idRenderEntityLocal'
neo\renderer\tr_frontend_addmodels.cpp(388): error C2065: 'ref': undeclared identifier
neo\renderer\tr_frontend_addmodels.cpp(388): error C2065: 'ref': undeclared identifier
neo\renderer\tr_frontend_addmodels.cpp(388): error C2065: 'ref': undeclared identifier
neo\renderer\tr_frontend_addmodels.cpp(389): error C2065: 'ref': undeclared identifier
neo\renderer\tr_frontend_addmodels.cpp(389): error C2660: 'idRenderWorldLocal::AreasAreConnected': function does not take 2 arguments
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderWorld_local.h(224): note: see declaration of 'idRenderWorldLocal::AreasAreConnected'
neo\renderer\tr_frontend_addmodels.cpp(389): note: while trying to match the argument list '(const int, portalConnection_t)'
neo\renderer\tr_frontend_addmodels.cpp(727): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\tr_frontend_addmodels.cpp.obj] Error 2
```


### warning kinds

- [9x] C4389
  - neo\d3xp\gamesys\Event.cpp(786): warning C4389: '==': signed/unsigned mismatch
  - neo\d3xp\gamesys\Event.cpp(853): warning C4389: '!=': signed/unsigned mismatch
  - neo\d3xp\gamesys\Event.cpp(903): warning C4389: '==': signed/unsigned mismatch
  - neo\d3xp\gamesys\Event.cpp(943): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1488): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1506): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1526): warning C4389: '!=': signed/unsigned mismatch
- [3x] C4245
  - neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [2x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used

## windows-x86-release

status: failure

errors: 19
warnings: 19 in 4 kinds

### errors

neo\renderer\RenderWorld.cpp(387): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
neo\renderer\RenderWorld.cpp(418): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\RenderWorld.cpp.obj] Error 2
neo\renderer\RenderWorld_defs.cpp(446): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
neo\renderer\RenderWorld_defs.cpp(450): error C2039: 'PushFrustumIntoTree': is not a member of 'idRenderWorldLocal'
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\RenderWorld_defs.cpp.obj] Error 2
neo\renderer\tr_frontend_addlights.cpp(352): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(353): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(406): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(407): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(411): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\tr_frontend_addlights.cpp.obj] Error 2
neo\renderer\tr_frontend_addmodels.cpp(388): error C2065: 'areaReference_t': undeclared identifier
neo\renderer\tr_frontend_addmodels.cpp(388): error C2065: 'ref': undeclared identifier
neo\renderer\tr_frontend_addmodels.cpp(388): error C2039: 'entityRefs': is not a member of 'idRenderEntityLocal'
neo\renderer\tr_frontend_addmodels.cpp(389): error C2065: 'ref': undeclared identifier
neo\renderer\tr_frontend_addmodels.cpp(389): error C2660: 'idRenderWorldLocal::AreasAreConnected': function does not take 2 arguments
neo\renderer\tr_frontend_addmodels.cpp(727): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\tr_frontend_addmodels.cpp.obj] Error 2

### failure context

- build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\RenderWorld.cpp.obj

```
Compiling 'neo\renderer\RenderEntity.cpp'
RenderEntity.cpp
Compiling 'neo\renderer\RenderLightCommitted.cpp'
Compiling 'neo\renderer\RenderLightParms.cpp'
RenderLightCommitted.cpp
RenderLightParms.cpp
Compiling 'neo\renderer\RenderLog.cpp'
RenderLog.cpp
Compiling 'neo\renderer\RenderModelCommitted.cpp'
RenderModelCommitted.cpp
Compiling 'neo\renderer\RenderModelParms.cpp'
Compiling 'neo\renderer\RenderProgParm.cpp'
RenderModelParms.cpp
RenderProgParm.cpp
Compiling 'neo\renderer\RenderProgs.cpp'
RenderProgs.cpp
Compiling 'neo\renderer\RenderSystem.cpp'
RenderSystem.cpp
Compiling 'neo\renderer\RenderSystem_init.cpp'
Compiling 'neo\renderer\RenderWorld.cpp'
RenderSystem_init.cpp
RenderWorld.cpp
Compiling 'neo\renderer\RenderWorld_defs.cpp'
RenderWorld_defs.cpp
Compiling 'neo\renderer\RenderWorld_demo.cpp'
RenderWorld_demo.cpp
neo\renderer\RenderWorld.cpp(387): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\RenderWorld.cpp(418): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\RenderWorld.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\RenderWorld_defs.cpp.obj

```
RenderLog.cpp
Compiling 'neo\renderer\RenderModelCommitted.cpp'
RenderModelCommitted.cpp
Compiling 'neo\renderer\RenderModelParms.cpp'
Compiling 'neo\renderer\RenderProgParm.cpp'
RenderModelParms.cpp
RenderProgParm.cpp
Compiling 'neo\renderer\RenderProgs.cpp'
RenderProgs.cpp
Compiling 'neo\renderer\RenderSystem.cpp'
RenderSystem.cpp
Compiling 'neo\renderer\RenderSystem_init.cpp'
Compiling 'neo\renderer\RenderWorld.cpp'
RenderSystem_init.cpp
RenderWorld.cpp
Compiling 'neo\renderer\RenderWorld_defs.cpp'
RenderWorld_defs.cpp
Compiling 'neo\renderer\RenderWorld_demo.cpp'
RenderWorld_demo.cpp
neo\renderer\RenderWorld.cpp(387): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\RenderWorld.cpp(418): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\RenderWorld.cpp.obj] Error 2
Compiling 'neo\renderer\RenderWorld_load.cpp'
RenderWorld_load.cpp
neo\renderer\RenderWorld_defs.cpp(446): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\RenderWorld_defs.cpp(450): error C2039: 'PushFrustumIntoTree': is not a member of 'idRenderWorldLocal'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderWorld_local.h(93): note: see declaration of 'idRenderWorldLocal'
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\RenderWorld_defs.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\tr_frontend_addlights.cpp.obj

```
RenderWorld_portals.cpp
Compiling 'neo\renderer\ResolutionScale.cpp'
ResolutionScale.cpp
Compiling 'neo\renderer\ScreenRect.cpp'
ScreenRect.cpp
Retrieved `build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\stblib_impls.c.obj' from cache
Compiling 'neo\renderer\tr_backend_draw.cpp'
tr_backend_draw.cpp
Compiling 'neo\renderer\tr_backend_rendertools.cpp'
tr_backend_rendertools.cpp
Compiling 'neo\renderer\tr_frontend_addlights.cpp'
tr_frontend_addlights.cpp
Compiling 'neo\renderer\tr_frontend_addmodels.cpp'
tr_frontend_addmodels.cpp
neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_draw.cpp(1488): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_draw.cpp(1506): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_draw.cpp(1526): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_frontend_addlights.cpp(352): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(353): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(406): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(407): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(411): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
Compiling 'neo\renderer\tr_frontend_deform.cpp'
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\tr_frontend_addlights.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\tr_frontend_addmodels.cpp.obj

```
neo\renderer\tr_frontend_addlights.cpp(352): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(353): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(406): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(407): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
neo\renderer\tr_frontend_addlights.cpp(411): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
Compiling 'neo\renderer\tr_frontend_deform.cpp'
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\tr_frontend_addlights.cpp.obj] Error 2
Compiling 'neo\renderer\tr_frontend_guisurf.cpp'
tr_frontend_deform.cpp
tr_frontend_guisurf.cpp
Compiling 'neo\renderer\tr_frontend_main.cpp'
tr_frontend_main.cpp
neo\renderer\tr_frontend_addmodels.cpp(388): error C2065: 'areaReference_t': undeclared identifier
neo\renderer\tr_frontend_addmodels.cpp(388): error C2065: 'ref': undeclared identifier
neo\renderer\tr_frontend_addmodels.cpp(388): error C2039: 'entityRefs': is not a member of 'idRenderEntityLocal'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_local.h(206): note: see declaration of 'idRenderEntityLocal'
neo\renderer\tr_frontend_addmodels.cpp(388): error C2065: 'ref': undeclared identifier
neo\renderer\tr_frontend_addmodels.cpp(388): error C2065: 'ref': undeclared identifier
neo\renderer\tr_frontend_addmodels.cpp(388): error C2065: 'ref': undeclared identifier
neo\renderer\tr_frontend_addmodels.cpp(389): error C2065: 'ref': undeclared identifier
neo\renderer\tr_frontend_addmodels.cpp(389): error C2660: 'idRenderWorldLocal::AreasAreConnected': function does not take 2 arguments
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderWorld_local.h(224): note: see declaration of 'idRenderWorldLocal::AreasAreConnected'
neo\renderer\tr_frontend_addmodels.cpp(389): note: while trying to match the argument list '(const int, portalConnection_t)'
neo\renderer\tr_frontend_addmodels.cpp(727): error C2039: 'prelightModel': is not a member of 'idRenderLightParms'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\RenderLightParms.h(74): note: see declaration of 'idRenderLightParms'
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\tr_frontend_addmodels.cpp.obj] Error 2
```


### warning kinds

- [7x] C4389
  - neo\d3xp\gamesys\Event.cpp(853): warning C4389: '!=': signed/unsigned mismatch
  - neo\d3xp\gamesys\Event.cpp(943): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1488): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1506): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1526): warning C4389: '!=': signed/unsigned mismatch
- [6x] C4702
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(368) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1048) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1345) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1379) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1390) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1422) : warning C4702: unreachable code
- [3x] C4245
  - neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [3x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\renderbump\renderbump.cpp(1318) : warning C4701: potentially uninitialized local variable 'opt' used

