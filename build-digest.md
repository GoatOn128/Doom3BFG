# Build digest

commit: 916df566e3b4

- windows-x64-debug: cancelled
- windows-x64-release: cancelled
- windows-x64-release-dll: cancelled
- windows-x86-debug: cancelled
- windows-x86-release: failure

## windows-x64-debug

status: cancelled

errors: 0
warnings: 0 in 0 kinds

### errors


### failure context


### warning kinds

## windows-x64-release-dll

status: cancelled

errors: 0
warnings: 2 in 2 kinds

### errors


### failure context


### warning kinds

- [1x] C4101
  - neo\framework\Common.cpp(777): warning C4101: 'mouseEvents': unreferenced local variable
- [1x] C4245
  - neo\framework\Common_tools.cpp(40): warning C4245: 'initializing': conversion from 'int' to 'unsigned int', signed/unsigned mismatch

## windows-x64-release

status: cancelled

errors: 0
warnings: 0 in 0 kinds

### errors


### failure context


### warning kinds

## windows-x86-debug

status: cancelled

errors: 110
warnings: 2 in 1 kinds

### errors

D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(51): error C3646: 'isMainThread': unknown override specifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(51): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(64): error C2061: syntax error: identifier 'VERIFY_FORMAT_STRING'
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(64): error C3646: 'ID_STATIC_ATTRIBUTE_PRINTF': unknown override specifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(64): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(64): error C2059: syntax error: '('
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(65): error C2061: syntax error: identifier 'VERIFY_FORMAT_STRING'
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(65): error C3646: 'ID_STATIC_ATTRIBUTE_PRINTF': unknown override specifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(65): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(65): error C2059: syntax error: '('
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(66): error C2144: syntax error: 'void' should be preceded by ','
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(66): error C2143: syntax error: missing ')' before ';'
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(66): error C2238: unexpected token(s) preceding ';'
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(67): error C2144: syntax error: 'void' should be preceded by ';'
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(67): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(67): error C2061: syntax error: identifier 'VERIFY_FORMAT_STRING'
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(67): error C3646: 'ID_STATIC_ATTRIBUTE_PRINTF': unknown override specifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(67): error C2059: syntax error: '('
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(68): error C2061: syntax error: identifier 'VERIFY_FORMAT_STRING'
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(68): error C3646: 'ID_STATIC_ATTRIBUTE_PRINTF': unknown override specifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(68): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(68): error C2059: syntax error: '('
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(69): error C2061: syntax error: identifier 'VERIFY_FORMAT_STRING'
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(69): error C3646: 'ID_STATIC_ATTRIBUTE_PRINTF': unknown override specifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(69): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(69): error C2059: syntax error: '('
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(72): error C2143: syntax error: missing ')' before ';'
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(72): error C2059: syntax error: ')'
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(77): error C2143: syntax error: missing ')' before ';'
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(77): error C2059: syntax error: ')'
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(76): error C2065: 'isMainThread': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(132): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(132): error C2146: syntax error: missing ';' before identifier 'PackColor'
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(133): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(133): error C2146: syntax error: missing ')' before identifier 'color'
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(133): error C3646: 'color': unknown override specifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(133): error C2143: syntax error: missing ';' before '&'
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(133): error C2182: 'idVec3': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(133): error C2059: syntax error: ')'
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(133): error C2530: 'unpackedColor': references must be initialized
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(134): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(134): error C2086: 'int dword': redefinition
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(134): error C2146: syntax error: missing ';' before identifier 'PackColor'
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(135): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(135): error C2146: syntax error: missing ')' before identifier 'color'
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(135): error C3646: 'color': unknown override specifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(135): error C2143: syntax error: missing ';' before '&'
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(135): error C2182: 'idVec4': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(135): error C2059: syntax error: ')'
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(135): error C2086: 'int &unpackedColor': redefinition
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(152): error C2065: 'byte': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(152): error C2065: 'out': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(152): error C2062: type 'int' unexpected
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(153): error C2065: 'byte': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib/Lib.h(153): error C2065: 'in': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_exceptions.h(41): error C3861: 'strncpy': identifier not found
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(41): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(41): error C2146: syntax error: missing ';' before identifier 'mutexHandle_t'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(42): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(42): error C2146: syntax error: missing ';' before identifier 'signalHandle_t'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(43): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(43): error C2146: syntax error: missing ';' before identifier 'interlockedInt_t'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(84): error C3646: 'tlsIndex': unknown override specifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(84): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(68): error C2065: 'tlsIndex': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(68): error C3861: 'TlsAlloc': identifier not found
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(71): error C2065: 'tlsIndex': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(71): error C3861: 'TlsAlloc': identifier not found
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(72): error C2065: 'tlsIndex': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(72): error C2065: 'LPVOID': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(72): error C2146: syntax error: missing ')' before identifier 'val'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(72): error C3861: 'TlsSetValue': identifier not found
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(72): error C2146: syntax error: missing ';' before identifier 'val'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(72): error C2059: syntax error: ')'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(75): error C2065: 'tlsIndex': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(75): error C3861: 'TlsFree': identifier not found
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(78): error C2065: 'tlsIndex': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(78): error C3861: 'TlsGetValue': identifier not found
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2065: 'tlsIndex': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2065: 'LPVOID': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2146: syntax error: missing ')' before identifier 'val'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C3861: 'TlsSetValue': identifier not found
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2146: syntax error: missing ';' before identifier 'val'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2059: syntax error: ')'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(134): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(134): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(134): error C2062: type 'bool' unexpected
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(135): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(135): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(135): error C2182: 'Sys_SignalDestroy': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(136): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(136): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(136): error C2182: 'Sys_SignalRaise': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(137): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(137): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(137): error C2182: 'Sys_SignalClear': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(138): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(138): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(138): error C2062: type 'int' unexpected
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(140): error C2065: 'mutexHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(140): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(140): error C2182: 'Sys_MutexCreate': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(141): error C2065: 'mutexHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(141): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(141): error C2182: 'Sys_MutexDestroy': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(141): fatal error C1003: error count exceeds 100; stopping compilation
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(142): error C2065: 'mutexHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(142): fatal error C1003: error count exceeds 100; stopping compilation
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderProgParm.cpp.obj] Error 2

### failure context

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj

```
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(78): error C3861: 'TlsGetValue': identifier not found
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2065: 'tlsIndex': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2065: 'LPVOID': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2146: syntax error: missing ')' before identifier 'val'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C3861: 'TlsSetValue': identifier not found
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2146: syntax error: missing ';' before identifier 'val'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2059: syntax error: ')'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(134): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(134): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(134): error C2062: type 'bool' unexpected
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(135): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(135): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(135): error C2182: 'Sys_SignalDestroy': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(136): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(136): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(136): error C2182: 'Sys_SignalRaise': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(137): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(137): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(137): error C2182: 'Sys_SignalClear': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(138): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(138): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(138): error C2062: type 'int' unexpected
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(140): error C2065: 'mutexHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(140): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(140): error C2182: 'Sys_MutexCreate': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(141): error C2065: 'mutexHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(141): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(141): error C2182: 'Sys_MutexDestroy': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(142): error C2065: 'mutexHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(142): fatal error C1003: error count exceeds 100; stopping compilation
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderProgParm.cpp.obj

```
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2065: 'tlsIndex': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2065: 'LPVOID': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2146: syntax error: missing ')' before identifier 'val'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C3861: 'TlsSetValue': identifier not found
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2146: syntax error: missing ';' before identifier 'val'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2059: syntax error: ')'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(134): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(134): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(134): error C2062: type 'bool' unexpected
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(135): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(135): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(135): error C2182: 'Sys_SignalDestroy': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(136): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(136): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(136): error C2182: 'Sys_SignalRaise': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(137): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(137): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(137): error C2182: 'Sys_SignalClear': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(138): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(138): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(138): error C2062: type 'int' unexpected
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(140): error C2065: 'mutexHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(140): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(140): error C2182: 'Sys_MutexCreate': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(141): error C2065: 'mutexHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(141): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(141): error C2182: 'Sys_MutexDestroy': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(142): error C2065: 'mutexHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(142): fatal error C1003: error count exceeds 100; stopping compilation
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderProgParm.cpp.obj] Error 2
```


### warning kinds

- [2x] C4164
  - D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(48): warning C4164: '_ReadWriteBarrier': intrinsic function not declared

## windows-x86-release

status: failure

errors: 110
warnings: 2 in 1 kinds

### errors

neo\idlib/Lib.h(51): error C3646: 'isMainThread': unknown override specifier
neo\idlib/Lib.h(51): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
neo\idlib/Lib.h(64): error C2061: syntax error: identifier 'VERIFY_FORMAT_STRING'
neo\idlib/Lib.h(64): error C3646: 'ID_STATIC_ATTRIBUTE_PRINTF': unknown override specifier
neo\idlib/Lib.h(64): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
neo\idlib/Lib.h(64): error C2059: syntax error: '('
neo\idlib/Lib.h(65): error C2061: syntax error: identifier 'VERIFY_FORMAT_STRING'
neo\idlib/Lib.h(65): error C3646: 'ID_STATIC_ATTRIBUTE_PRINTF': unknown override specifier
neo\idlib/Lib.h(65): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
neo\idlib/Lib.h(65): error C2059: syntax error: '('
neo\idlib/Lib.h(66): error C2144: syntax error: 'void' should be preceded by ','
neo\idlib/Lib.h(66): error C2143: syntax error: missing ')' before ';'
neo\idlib/Lib.h(66): error C2238: unexpected token(s) preceding ';'
neo\idlib/Lib.h(67): error C2144: syntax error: 'void' should be preceded by ';'
neo\idlib/Lib.h(67): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
neo\idlib/Lib.h(67): error C2061: syntax error: identifier 'VERIFY_FORMAT_STRING'
neo\idlib/Lib.h(67): error C3646: 'ID_STATIC_ATTRIBUTE_PRINTF': unknown override specifier
neo\idlib/Lib.h(67): error C2059: syntax error: '('
neo\idlib/Lib.h(68): error C2061: syntax error: identifier 'VERIFY_FORMAT_STRING'
neo\idlib/Lib.h(68): error C3646: 'ID_STATIC_ATTRIBUTE_PRINTF': unknown override specifier
neo\idlib/Lib.h(68): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
neo\idlib/Lib.h(68): error C2059: syntax error: '('
neo\idlib/Lib.h(69): error C2061: syntax error: identifier 'VERIFY_FORMAT_STRING'
neo\idlib/Lib.h(69): error C3646: 'ID_STATIC_ATTRIBUTE_PRINTF': unknown override specifier
neo\idlib/Lib.h(69): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
neo\idlib/Lib.h(69): error C2059: syntax error: '('
neo\idlib/Lib.h(72): error C2143: syntax error: missing ')' before ';'
neo\idlib/Lib.h(72): error C2059: syntax error: ')'
neo\idlib/Lib.h(77): error C2143: syntax error: missing ')' before ';'
neo\idlib/Lib.h(77): error C2059: syntax error: ')'
neo\idlib/Lib.h(76): error C2065: 'isMainThread': undeclared identifier
neo\idlib/Lib.h(132): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
neo\idlib/Lib.h(132): error C2146: syntax error: missing ';' before identifier 'PackColor'
neo\idlib/Lib.h(133): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
neo\idlib/Lib.h(133): error C2146: syntax error: missing ')' before identifier 'color'
neo\idlib/Lib.h(133): error C3646: 'color': unknown override specifier
neo\idlib/Lib.h(133): error C2143: syntax error: missing ';' before '&'
neo\idlib/Lib.h(133): error C2182: 'idVec3': this use of 'void' is not valid
neo\idlib/Lib.h(133): error C2059: syntax error: ')'
neo\idlib/Lib.h(133): error C2530: 'unpackedColor': references must be initialized
neo\idlib/Lib.h(134): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
neo\idlib/Lib.h(134): error C2086: 'int dword': redefinition
neo\idlib/Lib.h(134): error C2146: syntax error: missing ';' before identifier 'PackColor'
neo\idlib/Lib.h(135): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
neo\idlib/Lib.h(135): error C2146: syntax error: missing ')' before identifier 'color'
neo\idlib/Lib.h(135): error C3646: 'color': unknown override specifier
neo\idlib/Lib.h(135): error C2143: syntax error: missing ';' before '&'
neo\idlib/Lib.h(135): error C2182: 'idVec4': this use of 'void' is not valid
neo\idlib/Lib.h(135): error C2059: syntax error: ')'
neo\idlib/Lib.h(135): error C2086: 'int &unpackedColor': redefinition
neo\idlib/Lib.h(152): error C2065: 'byte': undeclared identifier
neo\idlib/Lib.h(152): error C2065: 'out': undeclared identifier
neo\idlib/Lib.h(152): error C2062: type 'int' unexpected
neo\idlib/Lib.h(153): error C2065: 'byte': undeclared identifier
neo\idlib/Lib.h(153): error C2065: 'in': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_exceptions.h(41): error C3861: 'strncpy': identifier not found
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(41): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(41): error C2146: syntax error: missing ';' before identifier 'mutexHandle_t'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(42): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(42): error C2146: syntax error: missing ';' before identifier 'signalHandle_t'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(43): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(43): error C2146: syntax error: missing ';' before identifier 'interlockedInt_t'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(84): error C3646: 'tlsIndex': unknown override specifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(84): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(68): error C2065: 'tlsIndex': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(68): error C3861: 'TlsAlloc': identifier not found
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(71): error C2065: 'tlsIndex': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(71): error C3861: 'TlsAlloc': identifier not found
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(72): error C2065: 'tlsIndex': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(72): error C2065: 'LPVOID': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(72): error C2146: syntax error: missing ')' before identifier 'val'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(72): error C3861: 'TlsSetValue': identifier not found
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(72): error C2146: syntax error: missing ';' before identifier 'val'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(72): error C2059: syntax error: ')'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(75): error C2065: 'tlsIndex': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(75): error C3861: 'TlsFree': identifier not found
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(78): error C2065: 'tlsIndex': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(78): error C3861: 'TlsGetValue': identifier not found
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2065: 'tlsIndex': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2065: 'LPVOID': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2146: syntax error: missing ')' before identifier 'val'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C3861: 'TlsSetValue': identifier not found
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2146: syntax error: missing ';' before identifier 'val'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2059: syntax error: ')'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(134): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(134): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(134): error C2062: type 'bool' unexpected
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(135): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(135): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(135): error C2182: 'Sys_SignalDestroy': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(136): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(136): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(136): error C2182: 'Sys_SignalRaise': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(137): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(137): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(137): error C2182: 'Sys_SignalClear': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(138): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(138): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(138): error C2062: type 'int' unexpected
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(140): error C2065: 'mutexHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(140): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(140): error C2182: 'Sys_MutexCreate': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(141): error C2065: 'mutexHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(141): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(141): error C2182: 'Sys_MutexDestroy': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(141): fatal error C1003: error count exceeds 100; stopping compilation
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(142): error C2065: 'mutexHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(142): fatal error C1003: error count exceeds 100; stopping compilation
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\RenderProgParm.cpp.obj] Error 2

### failure context

- build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj

```
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(78): error C3861: 'TlsGetValue': identifier not found
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2065: 'tlsIndex': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2065: 'LPVOID': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2146: syntax error: missing ')' before identifier 'val'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C3861: 'TlsSetValue': identifier not found
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2146: syntax error: missing ';' before identifier 'val'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2059: syntax error: ')'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(134): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(134): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(134): error C2062: type 'bool' unexpected
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(135): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(135): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(135): error C2182: 'Sys_SignalDestroy': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(136): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(136): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(136): error C2182: 'Sys_SignalRaise': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(137): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(137): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(137): error C2182: 'Sys_SignalClear': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(138): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(138): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(138): error C2062: type 'int' unexpected
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(140): error C2065: 'mutexHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(140): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(140): error C2182: 'Sys_MutexCreate': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(141): error C2065: 'mutexHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(141): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(141): error C2182: 'Sys_MutexDestroy': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(142): error C2065: 'mutexHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(142): fatal error C1003: error count exceeds 100; stopping compilation
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\RenderProgParm.cpp.obj

```
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2065: 'tlsIndex': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2065: 'LPVOID': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2146: syntax error: missing ')' before identifier 'val'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C3861: 'TlsSetValue': identifier not found
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2146: syntax error: missing ';' before identifier 'val'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(81): error C2059: syntax error: ')'
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(134): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(134): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(134): error C2062: type 'bool' unexpected
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(135): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(135): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(135): error C2182: 'Sys_SignalDestroy': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(136): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(136): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(136): error C2182: 'Sys_SignalRaise': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(137): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(137): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(137): error C2182: 'Sys_SignalClear': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(138): error C2065: 'signalHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(138): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(138): error C2062: type 'int' unexpected
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(140): error C2065: 'mutexHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(140): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(140): error C2182: 'Sys_MutexCreate': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(141): error C2065: 'mutexHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(141): error C2065: 'handle': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(141): error C2182: 'Sys_MutexDestroy': this use of 'void' is not valid
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(142): error C2065: 'mutexHandle_t': undeclared identifier
D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(142): fatal error C1003: error count exceeds 100; stopping compilation
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\RenderProgParm.cpp.obj] Error 2
```


### warning kinds

- [2x] C4164
  - D:\a\Doom3BFG\Doom3BFG\neo\idlib\sys/sys_threading.h(48): warning C4164: '_ReadWriteBarrier': intrinsic function not declared

