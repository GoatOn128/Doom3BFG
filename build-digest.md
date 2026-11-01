# Build digest

commit: 5331e282630c

- windows-x64-debug: failure
- windows-x64-release: cancelled
- windows-x86-debug: cancelled
- windows-x86-release: cancelled

## windows-x64-debug

status: failure

errors: 153
warnings: 22 in 7 kinds

### errors

neo\sys\win32\win_glimp.cpp(360): error C2065: 'ERROR_INVALID_VERSION_ARB': undeclared identifier
neo\sys\win32\win_glimp.cpp(361): error C2065: 'ERROR_INVALID_PROFILE_ARB': undeclared identifier
neo\sys\win32\win_glimp.cpp(360): error C2051: case expression not constant
neo\sys\win32\win_glimp.cpp(361): error C2051: case expression not constant
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\sys\win32\win_glimp.cpp.obj] Error 2
neo\tools\compilers\dmap\optimize.cpp(239): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(244): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(245): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(246): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(247): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(249): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(250): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(267): error C3861: 'qglEnable': identifier not found
neo\tools\compilers\dmap\optimize.cpp(268): error C3861: 'qglBlendFunc': identifier not found
neo\tools\compilers\dmap\optimize.cpp(269): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(270): error C3861: 'qglPointSize': identifier not found
neo\tools\compilers\dmap\optimize.cpp(271): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(273): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(275): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(276): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\dmap\optimize.cpp(277): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(294): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(299): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(300): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(301): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(302): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(304): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(305): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(483): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(484): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(485): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(486): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(487): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(488): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(690): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(691): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(692): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(693): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(694): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(695): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(696): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(697): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(698): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(699): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(700): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(701): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(968): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(969): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(970): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(971): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(972): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(973): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(974): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(975): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(976): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(977): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(978): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(979): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1002): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1003): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1004): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1005): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1006): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1007): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1020): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1021): error C3861: 'qglPointSize': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1022): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1023): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1024): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1025): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1042): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1044): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1046): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1047): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1048): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1049): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1050): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1051): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1052): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1053): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1054): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1055): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1056): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1057): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1370): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1372): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1373): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1374): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1375): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1377): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1378): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1496): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1497): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1498): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1499): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1500): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1501): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1502): error C3861: 'qglFlush': identifier not found
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\tools\compilers\dmap\optimize.cpp.obj] Error 2
neo\tools\compilers\renderbump\renderbump.cpp(929): error C3861: 'RB_SetGL2D': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(931): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(933): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(935): error C3861: 'qglMatrixMode': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(936): error C3861: 'qglLoadIdentity': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(937): error C3861: 'qglOrtho': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(938): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(939): error C3861: 'qglMatrixMode': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(940): error C3861: 'qglLoadIdentity': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(942): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(944): error C3861: 'qglClearColor': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(945): error C3861: 'qglClear': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(947): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(981): error C3861: 'qglClearColor': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(982): error C3861: 'qglClear': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(983): error C3861: 'qglRasterPos2f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(984): error C3861: 'qglPixelZoom': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(985): error C3861: 'qglDrawPixels': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(986): error C3861: 'qglPixelZoom': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(987): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1422): error C3861: 'qglViewport': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1424): error C3861: 'qglEnable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1425): error C3861: 'qglCullFace': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1426): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1427): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1428): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1429): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1430): error C3861: 'qglEnable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1431): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1432): error C3861: 'qglDepthMask': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1433): error C3861: 'qglDepthFunc': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1435): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1437): error C3861: 'qglMatrixMode': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1438): error C3861: 'qglLoadIdentity': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1439): error C3861: 'qglOrtho': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1442): error C3861: 'qglMatrixMode': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1443): error C3861: 'qglLoadIdentity': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1471): error C3861: 'qglClearColor': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1472): error C3861: 'qglClear': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1474): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1488): error C3861: 'qglColor3ubv': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1490): error C3861: 'qglVertex3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1516): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1518): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1521): error C3861: 'qglVertex3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1522): error C3861: 'qglVertex3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1523): error C3861: 'qglVertex3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1536): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1539): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1543): error C3861: 'qglVertex3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1550): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1551): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1553): error C3861: 'qglReadPixels': identifier not found
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\tools\compilers\renderbump\renderbump.cpp.obj] Error 2

### failure context

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\sys\win32\win_glimp.cpp.obj

```
sys_profile.cpp
Compiling 'neo\sys\sys_savegame.cpp'
sys_savegame.cpp
Compiling 'neo\sys\sys_session_callbacks.cpp'
Compiling 'neo\sys\sys_session_local.cpp'
sys_session_callbacks.cpp
sys_session_local.cpp
Compiling 'neo\sys\sys_session_savegames.cpp'
sys_session_savegames.cpp
Compiling 'neo\sys\sys_signin.cpp'
sys_signin.cpp
Compiling 'neo\sys\sys_voicechat.cpp'
sys_voicechat.cpp
Compiling 'neo\sys\win32\win_achievements.cpp'
win_achievements.cpp
Compiling 'neo\sys\win32\win_cpu.cpp'
win_cpu.cpp
Compiling 'neo\sys\win32\win_glimp.cpp'
win_glimp.cpp
Compiling 'neo\sys\win32\win_input.cpp'
win_input.cpp
Compiling 'neo\sys\win32\win_localuser.cpp'
win_localuser.cpp
Compiling 'neo\sys\win32\win_main.cpp'
win_main.cpp
neo\sys\win32\win_glimp.cpp(360): error C2065: 'ERROR_INVALID_VERSION_ARB': undeclared identifier
neo\sys\win32\win_glimp.cpp(361): error C2065: 'ERROR_INVALID_PROFILE_ARB': undeclared identifier
neo\sys\win32\win_glimp.cpp(360): error C2051: case expression not constant
neo\sys\win32\win_glimp.cpp(361): error C2051: case expression not constant
neo\sys\win32\win_glimp.cpp(363): warning C4065: switch statement contains 'default' but no 'case' labels
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\sys\win32\win_glimp.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\tools\compilers\dmap\optimize.cpp.obj

```
neo\tools\compilers\dmap\optimize.cpp(1024): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1025): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1042): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1044): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1046): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1047): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1048): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1049): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1050): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1051): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1052): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1053): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1054): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1055): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1056): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1057): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1370): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1372): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1373): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1374): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1375): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1377): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1378): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1496): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1497): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1498): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1499): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1500): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1501): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1502): error C3861: 'qglFlush': identifier not found
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\tools\compilers\dmap\optimize.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\tools\compilers\renderbump\renderbump.cpp.obj

```
neo\tools\compilers\renderbump\renderbump.cpp(1426): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1427): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1428): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1429): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1430): error C3861: 'qglEnable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1431): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1432): error C3861: 'qglDepthMask': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1433): error C3861: 'qglDepthFunc': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1435): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1437): error C3861: 'qglMatrixMode': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1438): error C3861: 'qglLoadIdentity': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1439): error C3861: 'qglOrtho': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1442): error C3861: 'qglMatrixMode': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1443): error C3861: 'qglLoadIdentity': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1471): error C3861: 'qglClearColor': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1472): error C3861: 'qglClear': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1474): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1488): error C3861: 'qglColor3ubv': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1490): error C3861: 'qglVertex3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1516): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1518): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1521): error C3861: 'qglVertex3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1522): error C3861: 'qglVertex3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1523): error C3861: 'qglVertex3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1536): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1539): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1543): error C3861: 'qglVertex3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1550): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1551): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1553): error C3861: 'qglReadPixels': identifier not found
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\tools\compilers\renderbump\renderbump.cpp.obj] Error 2
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
- [3x] C4245
  - neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [3x] C4311
  - neo\renderer\tr_backend_rendertools.cpp(724): warning C4311: 'type cast': pointer truncation from 'void *' to 'GLuint'
  - neo\sys\win32\win_syscon.cpp(119): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(128): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
- [3x] C4302
  - neo\renderer\tr_backend_rendertools.cpp(724): warning C4302: 'type cast': truncation from 'void *' to 'GLuint'
  - neo\sys\win32\win_syscon.cpp(119): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(128): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
- [3x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\external\stb\stb_vorbis.h(4849) : warning C4701: potentially uninitialized local variable 'mid' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used
- [1x] C4065
  - neo\sys\win32\win_glimp.cpp(363): warning C4065: switch statement contains 'default' but no 'case' labels

## windows-x64-release

status: cancelled

errors: 0
warnings: 8 in 2 kinds

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
- [2x] C4245
  - neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch

## windows-x86-debug

status: cancelled

errors: 0
warnings: 7 in 2 kinds

### errors


### failure context


### warning kinds

- [4x] C4389
  - neo\d3xp\gamesys\Event.cpp(786): warning C4389: '==': signed/unsigned mismatch
  - neo\d3xp\gamesys\Event.cpp(853): warning C4389: '!=': signed/unsigned mismatch
  - neo\d3xp\gamesys\Event.cpp(903): warning C4389: '==': signed/unsigned mismatch
  - neo\d3xp\gamesys\Event.cpp(943): warning C4389: '!=': signed/unsigned mismatch
- [3x] C4245
  - neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch

## windows-x86-release

status: cancelled

errors: 153
warnings: 20 in 5 kinds

### errors

neo\sys\win32\win_glimp.cpp(360): error C2065: 'ERROR_INVALID_VERSION_ARB': undeclared identifier
neo\sys\win32\win_glimp.cpp(361): error C2065: 'ERROR_INVALID_PROFILE_ARB': undeclared identifier
neo\sys\win32\win_glimp.cpp(360): error C2051: case expression not constant
neo\sys\win32\win_glimp.cpp(361): error C2051: case expression not constant
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\sys\win32\win_glimp.cpp.obj] Error 2
neo\tools\compilers\dmap\optimize.cpp(239): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(244): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(245): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(246): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(247): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(249): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(250): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(267): error C3861: 'qglEnable': identifier not found
neo\tools\compilers\dmap\optimize.cpp(268): error C3861: 'qglBlendFunc': identifier not found
neo\tools\compilers\dmap\optimize.cpp(269): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(270): error C3861: 'qglPointSize': identifier not found
neo\tools\compilers\dmap\optimize.cpp(271): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(273): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(275): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(276): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\dmap\optimize.cpp(277): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(294): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(299): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(300): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(301): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(302): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(304): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(305): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(483): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(484): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(485): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(486): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(487): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(488): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(690): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(691): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(692): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(693): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(694): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(695): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(696): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(697): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(698): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(699): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(700): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(701): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(968): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(969): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(970): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(971): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(972): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(973): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(974): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(975): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(976): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(977): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(978): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(979): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1002): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1003): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1004): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1005): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1006): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1007): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1020): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1021): error C3861: 'qglPointSize': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1022): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1023): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1024): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1025): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1042): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1044): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1046): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1047): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1048): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1049): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1050): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1051): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1052): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1053): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1054): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1055): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1056): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1057): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1370): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1372): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1373): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1374): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1375): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1377): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1378): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1496): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1497): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1498): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1499): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1500): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1501): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1502): error C3861: 'qglFlush': identifier not found
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\tools\compilers\dmap\optimize.cpp.obj] Error 2
neo\tools\compilers\renderbump\renderbump.cpp(929): error C3861: 'RB_SetGL2D': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(931): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(933): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(935): error C3861: 'qglMatrixMode': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(936): error C3861: 'qglLoadIdentity': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(937): error C3861: 'qglOrtho': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(938): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(939): error C3861: 'qglMatrixMode': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(940): error C3861: 'qglLoadIdentity': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(942): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(944): error C3861: 'qglClearColor': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(945): error C3861: 'qglClear': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(947): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(981): error C3861: 'qglClearColor': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(982): error C3861: 'qglClear': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(983): error C3861: 'qglRasterPos2f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(984): error C3861: 'qglPixelZoom': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(985): error C3861: 'qglDrawPixels': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(986): error C3861: 'qglPixelZoom': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(987): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1422): error C3861: 'qglViewport': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1424): error C3861: 'qglEnable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1425): error C3861: 'qglCullFace': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1426): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1427): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1428): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1429): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1430): error C3861: 'qglEnable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1431): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1432): error C3861: 'qglDepthMask': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1433): error C3861: 'qglDepthFunc': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1435): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1437): error C3861: 'qglMatrixMode': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1438): error C3861: 'qglLoadIdentity': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1439): error C3861: 'qglOrtho': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1442): error C3861: 'qglMatrixMode': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1443): error C3861: 'qglLoadIdentity': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1471): error C3861: 'qglClearColor': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1472): error C3861: 'qglClear': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1474): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1488): error C3861: 'qglColor3ubv': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1490): error C3861: 'qglVertex3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1516): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1518): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1521): error C3861: 'qglVertex3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1522): error C3861: 'qglVertex3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1523): error C3861: 'qglVertex3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1536): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1539): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1543): error C3861: 'qglVertex3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1550): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1551): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1553): error C3861: 'qglReadPixels': identifier not found
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\tools\compilers\renderbump\renderbump.cpp.obj] Error 2

### failure context

- build\scons\windows-x86-release-msvc\obj\DoomEXE\sys\win32\win_glimp.cpp.obj

```
sys_platform_local.cpp
Compiling 'neo\sys\sys_profile.cpp'
sys_profile.cpp
Compiling 'neo\sys\sys_savegame.cpp'
sys_savegame.cpp
Compiling 'neo\sys\sys_session_callbacks.cpp'
sys_session_callbacks.cpp
Compiling 'neo\sys\sys_session_local.cpp'
sys_session_local.cpp
Compiling 'neo\sys\sys_session_savegames.cpp'
sys_session_savegames.cpp
Compiling 'neo\sys\sys_signin.cpp'
sys_signin.cpp
Compiling 'neo\sys\sys_voicechat.cpp'
sys_voicechat.cpp
Compiling 'neo\sys\win32\win_achievements.cpp'
win_achievements.cpp
Compiling 'neo\sys\win32\win_cpu.cpp'
Compiling 'neo\sys\win32\win_glimp.cpp'
win_cpu.cpp
win_glimp.cpp
Compiling 'neo\sys\win32\win_input.cpp'
win_input.cpp
Compiling 'neo\sys\win32\win_localuser.cpp'
win_localuser.cpp
neo\sys\win32\win_glimp.cpp(360): error C2065: 'ERROR_INVALID_VERSION_ARB': undeclared identifier
neo\sys\win32\win_glimp.cpp(361): error C2065: 'ERROR_INVALID_PROFILE_ARB': undeclared identifier
neo\sys\win32\win_glimp.cpp(360): error C2051: case expression not constant
neo\sys\win32\win_glimp.cpp(361): error C2051: case expression not constant
neo\sys\win32\win_glimp.cpp(363): warning C4065: switch statement contains 'default' but no 'case' labels
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\sys\win32\win_glimp.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\DoomEXE\tools\compilers\dmap\optimize.cpp.obj

```
neo\tools\compilers\dmap\optimize.cpp(1024): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1025): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1042): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1044): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1046): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1047): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1048): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1049): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1050): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1051): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1052): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1053): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1054): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1055): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1056): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1057): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1370): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1372): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1373): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1374): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1375): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1377): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1378): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1496): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1497): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1498): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1499): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1500): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1501): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1502): error C3861: 'qglFlush': identifier not found
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\tools\compilers\dmap\optimize.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\DoomEXE\tools\compilers\renderbump\renderbump.cpp.obj

```
neo\tools\compilers\renderbump\renderbump.cpp(1426): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1427): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1428): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1429): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1430): error C3861: 'qglEnable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1431): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1432): error C3861: 'qglDepthMask': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1433): error C3861: 'qglDepthFunc': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1435): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1437): error C3861: 'qglMatrixMode': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1438): error C3861: 'qglLoadIdentity': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1439): error C3861: 'qglOrtho': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1442): error C3861: 'qglMatrixMode': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1443): error C3861: 'qglLoadIdentity': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1471): error C3861: 'qglClearColor': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1472): error C3861: 'qglClear': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1474): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1488): error C3861: 'qglColor3ubv': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1490): error C3861: 'qglVertex3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1516): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1518): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1521): error C3861: 'qglVertex3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1522): error C3861: 'qglVertex3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1523): error C3861: 'qglVertex3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1536): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1539): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1543): error C3861: 'qglVertex3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1550): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1551): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1553): error C3861: 'qglReadPixels': identifier not found
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\tools\compilers\renderbump\renderbump.cpp.obj] Error 2
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
- [3x] C4245
  - neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [3x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\external\stb\stb_vorbis.h(4849) : warning C4701: potentially uninitialized local variable 'mid' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used
- [1x] C4065
  - neo\sys\win32\win_glimp.cpp(363): warning C4065: switch statement contains 'default' but no 'case' labels

