# Build digest

commit: d8f0cf9e41ff

- windows-x64-debug: success
- windows-x64-release: success
- windows-x86-debug: success
- windows-x86-release: success

## windows-x64-debug

status: success

errors: 0
warnings: 15 in 6 kinds

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
- [3x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\renderbump\renderbump.cpp(1318) : warning C4701: potentially uninitialized local variable 'opt' used
- [2x] C4389
  - neo\renderer\tr_backend_draw.cpp(167): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(172): warning C4389: '!=': signed/unsigned mismatch
- [2x] C4311
  - neo\sys\win32\win_syscon.cpp(119): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(128): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
- [2x] C4302
  - neo\sys\win32\win_syscon.cpp(119): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(128): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'

## windows-x64-release

status: success

errors: 0
warnings: 21 in 7 kinds

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
- [3x] C4245
  - neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [3x] C4312
  - neo\renderer\BufferObject.cpp(188): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - neo\renderer\BufferObject.cpp(433): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - neo\renderer\BufferObject.cpp(671): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
- [3x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\renderbump\renderbump.cpp(1318) : warning C4701: potentially uninitialized local variable 'opt' used
- [2x] C4389
  - neo\renderer\tr_backend_draw.cpp(167): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(172): warning C4389: '!=': signed/unsigned mismatch
- [2x] C4311
  - neo\sys\win32\win_syscon.cpp(119): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(128): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
- [2x] C4302
  - neo\sys\win32\win_syscon.cpp(119): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(128): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'

## windows-x86-debug

status: success

errors: 0
warnings: 12 in 3 kinds

### errors


### failure context


### warning kinds

- [6x] C4389
  - neo\d3xp\gamesys\Event.cpp(786): warning C4389: '==': signed/unsigned mismatch
  - neo\d3xp\gamesys\Event.cpp(853): warning C4389: '!=': signed/unsigned mismatch
  - neo\d3xp\gamesys\Event.cpp(903): warning C4389: '==': signed/unsigned mismatch
  - neo\d3xp\gamesys\Event.cpp(943): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(167): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(172): warning C4389: '!=': signed/unsigned mismatch
- [3x] C4245
  - neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [3x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\renderbump\renderbump.cpp(1318) : warning C4701: potentially uninitialized local variable 'opt' used

## windows-x86-release

status: success

errors: 0
warnings: 16 in 4 kinds

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
- [4x] C4389
  - neo\d3xp\gamesys\Event.cpp(853): warning C4389: '!=': signed/unsigned mismatch
  - neo\d3xp\gamesys\Event.cpp(943): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(167): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(172): warning C4389: '!=': signed/unsigned mismatch
- [3x] C4245
  - neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [3x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\renderbump\renderbump.cpp(1318) : warning C4701: potentially uninitialized local variable 'opt' used

