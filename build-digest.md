# Build digest

commit: 5e5ac501de3d

- windows-x64-debug: success
- windows-x64-release: success
- windows-x86-debug: success
- windows-x86-release: success

## windows-x64-debug

status: success

errors: 0
warnings: 5 in 3 kinds

### errors


### failure context


### warning kinds

- [2x] C4311
  - neo\sys\win32\win_syscon.cpp(119): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(128): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
- [2x] C4302
  - neo\sys\win32\win_syscon.cpp(119): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(128): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
- [1x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\renderbump\renderbump.cpp(1318) : warning C4701: potentially uninitialized local variable 'opt' used

## windows-x64-release

status: success

errors: 0
warnings: 5 in 3 kinds

### errors


### failure context


### warning kinds

- [2x] C4311
  - neo\sys\win32\win_syscon.cpp(119): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(128): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
- [2x] C4302
  - neo\sys\win32\win_syscon.cpp(119): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(128): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
- [1x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\renderbump\renderbump.cpp(1318) : warning C4701: potentially uninitialized local variable 'opt' used

## windows-x86-debug

status: success

errors: 0
warnings: 1 in 1 kinds

### errors


### failure context


### warning kinds

- [1x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\renderbump\renderbump.cpp(1318) : warning C4701: potentially uninitialized local variable 'opt' used

## windows-x86-release

status: success

errors: 0
warnings: 1 in 1 kinds

### errors


### failure context


### warning kinds

- [1x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\renderbump\renderbump.cpp(1318) : warning C4701: potentially uninitialized local variable 'opt' used

