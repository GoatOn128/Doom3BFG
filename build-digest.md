# Build digest

commit: b767e1180fc5

- windows-x64-debug: failure
- windows-x64-release: cancelled
- windows-x86-debug: failure
- windows-x86-release: cancelled

## windows-x64-debug

status: failure

errors: 29
warnings: 25 in 7 kinds

### errors

FileSystem.cpp.obj : error LNK2019: unresolved external symbol "char const * __cdecl Sys_Lang(int)" (?Sys_Lang@@YAPEBDH@Z) referenced in function "public: virtual class idFile * __cdecl idFileSystemLocal::OpenFileReadFlags(char const *,int,bool,char const *)" (?OpenFileReadFlags@idFileSystemLocal@@UEAAPEAVidFile@@PEBDH_N0@Z)
FileSystem.cpp.obj : error LNK2019: unresolved external symbol "int __cdecl Sys_NumLangs(void)" (?Sys_NumLangs@@YAHXZ) referenced in function "public: virtual class idFile * __cdecl idFileSystemLocal::OpenFileReadFlags(char const *,int,bool,char const *)" (?OpenFileReadFlags@idFileSystemLocal@@UEAAPEAVidFile@@PEBDH_N0@Z)
FileSystem.cpp.obj : error LNK2019: unresolved external symbol "public: int __cdecl idEventLoop::JournalLevel(void)const " (?JournalLevel@idEventLoop@@QEBAHXZ) referenced in function "public: virtual int __cdecl idFileSystemLocal::ReadFile(char const *,void * *,__int64 *)" (?ReadFile@idFileSystemLocal@@UEAAHPEBDPEAPEAXPEA_J@Z)
FileSystem.cpp.obj : error LNK2001: unresolved external symbol "class idCVar com_productionMode" (?com_productionMode@@3VidCVar@@A)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_SetWindowPos referenced in function "__int64 __cdecl AssertDialogProc(struct HWND__ *,unsigned int,unsigned __int64,__int64)" (?AssertDialogProc@@YA_JPEAUHWND__@@I_K_J@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_IsWindowVisible referenced in function "int __cdecl ParentWindowEnumProc(struct HWND__ *,__int64)" (?ParentWindowEnumProc@@YAHPEAUHWND__@@_J@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_DialogBoxParamA referenced in function "bool __cdecl AssertFailed(char const *,int,char const *)" (?AssertFailed@@YA_NPEBDH0@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_EndDialog referenced in function "__int64 __cdecl AssertDialogProc(struct HWND__ *,unsigned int,unsigned __int64,__int64)" (?AssertDialogProc@@YA_JPEAUHWND__@@I_K_J@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_SetDlgItemInt referenced in function "__int64 __cdecl AssertDialogProc(struct HWND__ *,unsigned int,unsigned __int64,__int64)" (?AssertDialogProc@@YA_JPEAUHWND__@@I_K_J@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_SetDlgItemTextA referenced in function "__int64 __cdecl AssertDialogProc(struct HWND__ *,unsigned int,unsigned __int64,__int64)" (?AssertDialogProc@@YA_JPEAUHWND__@@I_K_J@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_SetForegroundWindow referenced in function "__int64 __cdecl AssertDialogProc(struct HWND__ *,unsigned int,unsigned __int64,__int64)" (?AssertDialogProc@@YA_JPEAUHWND__@@I_K_J@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_GetWindowRect referenced in function "__int64 __cdecl AssertDialogProc(struct HWND__ *,unsigned int,unsigned __int64,__int64)" (?AssertDialogProc@@YA_JPEAUHWND__@@I_K_J@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_MessageBoxA referenced in function "bool __cdecl AssertFailed(char const *,int,char const *)" (?AssertFailed@@YA_NPEBDH0@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_GetDesktopWindow referenced in function "__int64 __cdecl AssertDialogProc(struct HWND__ *,unsigned int,unsigned __int64,__int64)" (?AssertDialogProc@@YA_JPEAUHWND__@@I_K_J@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_EnumWindows referenced in function "struct HWND__ * __cdecl FindParentWindow(void)" (?FindParentWindow@@YAPEAUHWND__@@XZ)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_GetWindowThreadProcessId referenced in function "int __cdecl ParentWindowEnumProc(struct HWND__ *,__int64)" (?ParentWindowEnumProc@@YAHPEAUHWND__@@_J@Z)
idLib.lib(win_filesystem.cpp.obj) : error LNK2019: unresolved external symbol __imp_CoTaskMemFree referenced in function "char const * __cdecl Sys_DefaultSavePath(void)" (?Sys_DefaultSavePath@@YAPEBDXZ)
idLib.lib(win_filesystem.cpp.obj) : error LNK2019: unresolved external symbol __imp_SHGetFolderPathA referenced in function "char const * __cdecl Sys_DefaultSavePath(void)" (?Sys_DefaultSavePath@@YAPEBDXZ)
idLib.lib(LangDict.cpp.obj) : error LNK2019: unresolved external symbol "int __cdecl Sys_Milliseconds(void)" (?Sys_Milliseconds@@YAHXZ) referenced in function "public: char const * __cdecl idLangDict::AddString(char const *)" (?AddString@idLangDict@@QEAAPEBDPEBD@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp_StackWalk64 referenced in function "void __cdecl Sys_CaptureExceptionStack(struct _EXCEPTION_POINTERS *)" (?Sys_CaptureExceptionStack@@YAXPEAU_EXCEPTION_POINTERS@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp_SymFunctionTableAccess64 referenced in function "void __cdecl Sys_CaptureExceptionStack(struct _EXCEPTION_POINTERS *)" (?Sys_CaptureExceptionStack@@YAXPEAU_EXCEPTION_POINTERS@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp_SymGetModuleBase64 referenced in function "void __cdecl Sys_CaptureExceptionStack(struct _EXCEPTION_POINTERS *)" (?Sys_CaptureExceptionStack@@YAXPEAU_EXCEPTION_POINTERS@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp_SymGetLineFromAddr64 referenced in function "void __cdecl Sys_DecodeStackTrace(unsigned char *,int,struct debugStackFrame_t *)" (?Sys_DecodeStackTrace@@YAXPEAEHPEAUdebugStackFrame_t@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp_SymInitialize referenced in function "void __cdecl Sys_DecodeStackTrace(unsigned char *,int,struct debugStackFrame_t *)" (?Sys_DecodeStackTrace@@YAXPEAEHPEAUdebugStackFrame_t@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp_SymGetSymFromAddr64 referenced in function "void __cdecl Sys_DecodeStackTrace(unsigned char *,int,struct debugStackFrame_t *)" (?Sys_DecodeStackTrace@@YAXPEAEHPEAUdebugStackFrame_t@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol MiniDumpWriteDump referenced in function "void __cdecl Sys_WriteMiniDump(struct _EXCEPTION_POINTERS *)" (?Sys_WriteMiniDump@@YAXPEAU_EXCEPTION_POINTERS@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2001: unresolved external symbol "class idCVar com_version" (?com_version@@3VidCVar@@A)
bin\convertidtech3assets.exe : fatal error LNK1120: 27 unresolved externals
scons: *** [bin\convertidtech3assets.exe] Error 1120

### failure context

- bin\convertidtech3assets.exe

```
FileSystem.cpp
bin\convertidtech3assets.exe
FileSystem.cpp.obj : error LNK2019: unresolved external symbol "char const * __cdecl Sys_Lang(int)" (?Sys_Lang@@YAPEBDH@Z) referenced in function "public: virtual class idFile * __cdecl idFileSystemLocal::OpenFileReadFlags(char const *,int,bool,char const *)" (?OpenFileReadFlags@idFileSystemLocal@@UEAAPEAVidFile@@PEBDH_N0@Z)
FileSystem.cpp.obj : error LNK2019: unresolved external symbol "int __cdecl Sys_NumLangs(void)" (?Sys_NumLangs@@YAHXZ) referenced in function "public: virtual class idFile * __cdecl idFileSystemLocal::OpenFileReadFlags(char const *,int,bool,char const *)" (?OpenFileReadFlags@idFileSystemLocal@@UEAAPEAVidFile@@PEBDH_N0@Z)
FileSystem.cpp.obj : error LNK2019: unresolved external symbol "public: int __cdecl idEventLoop::JournalLevel(void)const " (?JournalLevel@idEventLoop@@QEBAHXZ) referenced in function "public: virtual int __cdecl idFileSystemLocal::ReadFile(char const *,void * *,__int64 *)" (?ReadFile@idFileSystemLocal@@UEAAHPEBDPEAPEAXPEA_J@Z)
FileSystem.cpp.obj : error LNK2001: unresolved external symbol "class idCVar com_productionMode" (?com_productionMode@@3VidCVar@@A)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_SetWindowPos referenced in function "__int64 __cdecl AssertDialogProc(struct HWND__ *,unsigned int,unsigned __int64,__int64)" (?AssertDialogProc@@YA_JPEAUHWND__@@I_K_J@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_IsWindowVisible referenced in function "int __cdecl ParentWindowEnumProc(struct HWND__ *,__int64)" (?ParentWindowEnumProc@@YAHPEAUHWND__@@_J@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_DialogBoxParamA referenced in function "bool __cdecl AssertFailed(char const *,int,char const *)" (?AssertFailed@@YA_NPEBDH0@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_EndDialog referenced in function "__int64 __cdecl AssertDialogProc(struct HWND__ *,unsigned int,unsigned __int64,__int64)" (?AssertDialogProc@@YA_JPEAUHWND__@@I_K_J@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_SetDlgItemInt referenced in function "__int64 __cdecl AssertDialogProc(struct HWND__ *,unsigned int,unsigned __int64,__int64)" (?AssertDialogProc@@YA_JPEAUHWND__@@I_K_J@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_SetDlgItemTextA referenced in function "__int64 __cdecl AssertDialogProc(struct HWND__ *,unsigned int,unsigned __int64,__int64)" (?AssertDialogProc@@YA_JPEAUHWND__@@I_K_J@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_SetForegroundWindow referenced in function "__int64 __cdecl AssertDialogProc(struct HWND__ *,unsigned int,unsigned __int64,__int64)" (?AssertDialogProc@@YA_JPEAUHWND__@@I_K_J@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_GetWindowRect referenced in function "__int64 __cdecl AssertDialogProc(struct HWND__ *,unsigned int,unsigned __int64,__int64)" (?AssertDialogProc@@YA_JPEAUHWND__@@I_K_J@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_MessageBoxA referenced in function "bool __cdecl AssertFailed(char const *,int,char const *)" (?AssertFailed@@YA_NPEBDH0@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_GetDesktopWindow referenced in function "__int64 __cdecl AssertDialogProc(struct HWND__ *,unsigned int,unsigned __int64,__int64)" (?AssertDialogProc@@YA_JPEAUHWND__@@I_K_J@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_EnumWindows referenced in function "struct HWND__ * __cdecl FindParentWindow(void)" (?FindParentWindow@@YAPEAUHWND__@@XZ)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp_GetWindowThreadProcessId referenced in function "int __cdecl ParentWindowEnumProc(struct HWND__ *,__int64)" (?ParentWindowEnumProc@@YAHPEAUHWND__@@_J@Z)
idLib.lib(win_filesystem.cpp.obj) : error LNK2019: unresolved external symbol __imp_CoTaskMemFree referenced in function "char const * __cdecl Sys_DefaultSavePath(void)" (?Sys_DefaultSavePath@@YAPEBDXZ)
idLib.lib(win_filesystem.cpp.obj) : error LNK2019: unresolved external symbol __imp_SHGetFolderPathA referenced in function "char const * __cdecl Sys_DefaultSavePath(void)" (?Sys_DefaultSavePath@@YAPEBDXZ)
idLib.lib(LangDict.cpp.obj) : error LNK2019: unresolved external symbol "int __cdecl Sys_Milliseconds(void)" (?Sys_Milliseconds@@YAHXZ) referenced in function "public: char const * __cdecl idLangDict::AddString(char const *)" (?AddString@idLangDict@@QEAAPEBDPEBD@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp_StackWalk64 referenced in function "void __cdecl Sys_CaptureExceptionStack(struct _EXCEPTION_POINTERS *)" (?Sys_CaptureExceptionStack@@YAXPEAU_EXCEPTION_POINTERS@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp_SymFunctionTableAccess64 referenced in function "void __cdecl Sys_CaptureExceptionStack(struct _EXCEPTION_POINTERS *)" (?Sys_CaptureExceptionStack@@YAXPEAU_EXCEPTION_POINTERS@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp_SymGetModuleBase64 referenced in function "void __cdecl Sys_CaptureExceptionStack(struct _EXCEPTION_POINTERS *)" (?Sys_CaptureExceptionStack@@YAXPEAU_EXCEPTION_POINTERS@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp_SymGetLineFromAddr64 referenced in function "void __cdecl Sys_DecodeStackTrace(unsigned char *,int,struct debugStackFrame_t *)" (?Sys_DecodeStackTrace@@YAXPEAEHPEAUdebugStackFrame_t@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp_SymInitialize referenced in function "void __cdecl Sys_DecodeStackTrace(unsigned char *,int,struct debugStackFrame_t *)" (?Sys_DecodeStackTrace@@YAXPEAEHPEAUdebugStackFrame_t@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp_SymGetSymFromAddr64 referenced in function "void __cdecl Sys_DecodeStackTrace(unsigned char *,int,struct debugStackFrame_t *)" (?Sys_DecodeStackTrace@@YAXPEAEHPEAUdebugStackFrame_t@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol MiniDumpWriteDump referenced in function "void __cdecl Sys_WriteMiniDump(struct _EXCEPTION_POINTERS *)" (?Sys_WriteMiniDump@@YAXPEAU_EXCEPTION_POINTERS@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2001: unresolved external symbol "class idCVar com_version" (?com_version@@3VidCVar@@A)
bin\convertidtech3assets.exe : fatal error LNK1120: 27 unresolved externals
scons: *** [bin\convertidtech3assets.exe] Error 1120
```


### warning kinds

- [5x] C4389
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1499): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1517): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1537): warning C4389: '!=': signed/unsigned mismatch
- [4x] C4312
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\BufferObject.cpp(188): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\BufferObject.cpp(433): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\BufferObject.cpp(671): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_rendertools.cpp(727): warning C4312: 'type cast': conversion from 'int' to 'void *' of greater size
- [4x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\external\stb\stb_vorbis.h(4849) : warning C4701: potentially uninitialized local variable 'mid' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\renderbump\renderbump.cpp(1318) : warning C4701: potentially uninitialized local variable 'opt' used
- [3x] C4005
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(392): warning C4005: 'StrCmpN': macro redefinition
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(393): warning C4005: 'StrCmpNI': macro redefinition
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(499): warning C4005: 'StrCmpI': macro redefinition
- [3x] C4245
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [3x] C4311
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_rendertools.cpp(724): warning C4311: 'type cast': pointer truncation from 'void *' to 'GLuint'
  - D:\a\Doom3BFG\Doom3BFG\neo\sys\win32\win_syscon.cpp(119): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
  - D:\a\Doom3BFG\Doom3BFG\neo\sys\win32\win_syscon.cpp(128): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
- [3x] C4302
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_rendertools.cpp(724): warning C4302: 'type cast': truncation from 'void *' to 'GLuint'
  - D:\a\Doom3BFG\Doom3BFG\neo\sys\win32\win_syscon.cpp(119): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
  - D:\a\Doom3BFG\Doom3BFG\neo\sys\win32\win_syscon.cpp(128): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'

## windows-x64-release

status: cancelled

errors: 0
warnings: 15 in 4 kinds

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
- [3x] C4005
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(392): warning C4005: 'StrCmpN': macro redefinition
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(393): warning C4005: 'StrCmpNI': macro redefinition
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(499): warning C4005: 'StrCmpI': macro redefinition
- [3x] C4245
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [3x] C4312
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\BufferObject.cpp(188): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\BufferObject.cpp(433): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\BufferObject.cpp(671): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size

## windows-x86-debug

status: failure

errors: 29
warnings: 19 in 4 kinds

### errors

FileSystem.cpp.obj : error LNK2019: unresolved external symbol "char const * __cdecl Sys_Lang(int)" (?Sys_Lang@@YAPBDH@Z) referenced in function "public: virtual class idFile * __thiscall idFileSystemLocal::OpenFileReadFlags(char const *,int,bool,char const *)" (?OpenFileReadFlags@idFileSystemLocal@@UAEPAVidFile@@PBDH_N0@Z)
FileSystem.cpp.obj : error LNK2019: unresolved external symbol "int __cdecl Sys_NumLangs(void)" (?Sys_NumLangs@@YAHXZ) referenced in function "public: virtual class idFile * __thiscall idFileSystemLocal::OpenFileReadFlags(char const *,int,bool,char const *)" (?OpenFileReadFlags@idFileSystemLocal@@UAEPAVidFile@@PBDH_N0@Z)
FileSystem.cpp.obj : error LNK2019: unresolved external symbol "public: int __thiscall idEventLoop::JournalLevel(void)const " (?JournalLevel@idEventLoop@@QBEHXZ) referenced in function "public: virtual int __thiscall idFileSystemLocal::ReadFile(char const *,void * *,__int64 *)" (?ReadFile@idFileSystemLocal@@UAEHPBDPAPAXPA_J@Z)
FileSystem.cpp.obj : error LNK2001: unresolved external symbol "class idCVar com_productionMode" (?com_productionMode@@3VidCVar@@A)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__SetWindowPos@28 referenced in function "int __stdcall AssertDialogProc(struct HWND__ *,unsigned int,unsigned int,long)" (?AssertDialogProc@@YGHPAUHWND__@@IIJ@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__IsWindowVisible@4 referenced in function "int __stdcall ParentWindowEnumProc(struct HWND__ *,long)" (?ParentWindowEnumProc@@YGHPAUHWND__@@J@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__DialogBoxParamA@20 referenced in function "bool __cdecl AssertFailed(char const *,int,char const *)" (?AssertFailed@@YA_NPBDH0@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__EndDialog@8 referenced in function "int __stdcall AssertDialogProc(struct HWND__ *,unsigned int,unsigned int,long)" (?AssertDialogProc@@YGHPAUHWND__@@IIJ@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__SetDlgItemInt@16 referenced in function "int __stdcall AssertDialogProc(struct HWND__ *,unsigned int,unsigned int,long)" (?AssertDialogProc@@YGHPAUHWND__@@IIJ@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__SetDlgItemTextA@12 referenced in function "int __stdcall AssertDialogProc(struct HWND__ *,unsigned int,unsigned int,long)" (?AssertDialogProc@@YGHPAUHWND__@@IIJ@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__SetForegroundWindow@4 referenced in function "int __stdcall AssertDialogProc(struct HWND__ *,unsigned int,unsigned int,long)" (?AssertDialogProc@@YGHPAUHWND__@@IIJ@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__GetWindowRect@8 referenced in function "int __stdcall AssertDialogProc(struct HWND__ *,unsigned int,unsigned int,long)" (?AssertDialogProc@@YGHPAUHWND__@@IIJ@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__MessageBoxA@16 referenced in function "bool __cdecl AssertFailed(char const *,int,char const *)" (?AssertFailed@@YA_NPBDH0@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__GetDesktopWindow@0 referenced in function "int __stdcall AssertDialogProc(struct HWND__ *,unsigned int,unsigned int,long)" (?AssertDialogProc@@YGHPAUHWND__@@IIJ@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__EnumWindows@8 referenced in function "struct HWND__ * __cdecl FindParentWindow(void)" (?FindParentWindow@@YAPAUHWND__@@XZ)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__GetWindowThreadProcessId@8 referenced in function "int __stdcall ParentWindowEnumProc(struct HWND__ *,long)" (?ParentWindowEnumProc@@YGHPAUHWND__@@J@Z)
idLib.lib(win_filesystem.cpp.obj) : error LNK2019: unresolved external symbol __imp__CoTaskMemFree@4 referenced in function "char const * __cdecl Sys_DefaultSavePath(void)" (?Sys_DefaultSavePath@@YAPBDXZ)
idLib.lib(win_filesystem.cpp.obj) : error LNK2019: unresolved external symbol __imp__SHGetFolderPathA@20 referenced in function "char const * __cdecl Sys_DefaultSavePath(void)" (?Sys_DefaultSavePath@@YAPBDXZ)
idLib.lib(LangDict.cpp.obj) : error LNK2019: unresolved external symbol "int __cdecl Sys_Milliseconds(void)" (?Sys_Milliseconds@@YAHXZ) referenced in function "public: char const * __thiscall idLangDict::AddString(char const *)" (?AddString@idLangDict@@QAEPBDPBD@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp__StackWalk64@36 referenced in function "void __cdecl Sys_CaptureExceptionStack(struct _EXCEPTION_POINTERS *)" (?Sys_CaptureExceptionStack@@YAXPAU_EXCEPTION_POINTERS@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp__SymFunctionTableAccess64@12 referenced in function "void __cdecl Sys_CaptureExceptionStack(struct _EXCEPTION_POINTERS *)" (?Sys_CaptureExceptionStack@@YAXPAU_EXCEPTION_POINTERS@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp__SymGetModuleBase64@12 referenced in function "void __cdecl Sys_CaptureExceptionStack(struct _EXCEPTION_POINTERS *)" (?Sys_CaptureExceptionStack@@YAXPAU_EXCEPTION_POINTERS@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp__SymGetLineFromAddr64@20 referenced in function "void __cdecl Sys_DecodeStackTrace(unsigned char *,int,struct debugStackFrame_t *)" (?Sys_DecodeStackTrace@@YAXPAEHPAUdebugStackFrame_t@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp__SymInitialize@12 referenced in function "void __cdecl Sys_DecodeStackTrace(unsigned char *,int,struct debugStackFrame_t *)" (?Sys_DecodeStackTrace@@YAXPAEHPAUdebugStackFrame_t@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp__SymGetSymFromAddr64@20 referenced in function "void __cdecl Sys_DecodeStackTrace(unsigned char *,int,struct debugStackFrame_t *)" (?Sys_DecodeStackTrace@@YAXPAEHPAUdebugStackFrame_t@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol _MiniDumpWriteDump@28 referenced in function "void __cdecl Sys_WriteMiniDump(struct _EXCEPTION_POINTERS *)" (?Sys_WriteMiniDump@@YAXPAU_EXCEPTION_POINTERS@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2001: unresolved external symbol "class idCVar com_version" (?com_version@@3VidCVar@@A)
bin\convertidtech3assets.exe : fatal error LNK1120: 27 unresolved externals
scons: *** [bin\convertidtech3assets.exe] Error 1120

### failure context

- bin\convertidtech3assets.exe

```
FileSystem.cpp
bin\convertidtech3assets.exe
FileSystem.cpp.obj : error LNK2019: unresolved external symbol "char const * __cdecl Sys_Lang(int)" (?Sys_Lang@@YAPBDH@Z) referenced in function "public: virtual class idFile * __thiscall idFileSystemLocal::OpenFileReadFlags(char const *,int,bool,char const *)" (?OpenFileReadFlags@idFileSystemLocal@@UAEPAVidFile@@PBDH_N0@Z)
FileSystem.cpp.obj : error LNK2019: unresolved external symbol "int __cdecl Sys_NumLangs(void)" (?Sys_NumLangs@@YAHXZ) referenced in function "public: virtual class idFile * __thiscall idFileSystemLocal::OpenFileReadFlags(char const *,int,bool,char const *)" (?OpenFileReadFlags@idFileSystemLocal@@UAEPAVidFile@@PBDH_N0@Z)
FileSystem.cpp.obj : error LNK2019: unresolved external symbol "public: int __thiscall idEventLoop::JournalLevel(void)const " (?JournalLevel@idEventLoop@@QBEHXZ) referenced in function "public: virtual int __thiscall idFileSystemLocal::ReadFile(char const *,void * *,__int64 *)" (?ReadFile@idFileSystemLocal@@UAEHPBDPAPAXPA_J@Z)
FileSystem.cpp.obj : error LNK2001: unresolved external symbol "class idCVar com_productionMode" (?com_productionMode@@3VidCVar@@A)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__SetWindowPos@28 referenced in function "int __stdcall AssertDialogProc(struct HWND__ *,unsigned int,unsigned int,long)" (?AssertDialogProc@@YGHPAUHWND__@@IIJ@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__IsWindowVisible@4 referenced in function "int __stdcall ParentWindowEnumProc(struct HWND__ *,long)" (?ParentWindowEnumProc@@YGHPAUHWND__@@J@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__DialogBoxParamA@20 referenced in function "bool __cdecl AssertFailed(char const *,int,char const *)" (?AssertFailed@@YA_NPBDH0@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__EndDialog@8 referenced in function "int __stdcall AssertDialogProc(struct HWND__ *,unsigned int,unsigned int,long)" (?AssertDialogProc@@YGHPAUHWND__@@IIJ@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__SetDlgItemInt@16 referenced in function "int __stdcall AssertDialogProc(struct HWND__ *,unsigned int,unsigned int,long)" (?AssertDialogProc@@YGHPAUHWND__@@IIJ@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__SetDlgItemTextA@12 referenced in function "int __stdcall AssertDialogProc(struct HWND__ *,unsigned int,unsigned int,long)" (?AssertDialogProc@@YGHPAUHWND__@@IIJ@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__SetForegroundWindow@4 referenced in function "int __stdcall AssertDialogProc(struct HWND__ *,unsigned int,unsigned int,long)" (?AssertDialogProc@@YGHPAUHWND__@@IIJ@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__GetWindowRect@8 referenced in function "int __stdcall AssertDialogProc(struct HWND__ *,unsigned int,unsigned int,long)" (?AssertDialogProc@@YGHPAUHWND__@@IIJ@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__MessageBoxA@16 referenced in function "bool __cdecl AssertFailed(char const *,int,char const *)" (?AssertFailed@@YA_NPBDH0@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__GetDesktopWindow@0 referenced in function "int __stdcall AssertDialogProc(struct HWND__ *,unsigned int,unsigned int,long)" (?AssertDialogProc@@YGHPAUHWND__@@IIJ@Z)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__EnumWindows@8 referenced in function "struct HWND__ * __cdecl FindParentWindow(void)" (?FindParentWindow@@YAPAUHWND__@@XZ)
idLib.lib(sys_assert.cpp.obj) : error LNK2019: unresolved external symbol __imp__GetWindowThreadProcessId@8 referenced in function "int __stdcall ParentWindowEnumProc(struct HWND__ *,long)" (?ParentWindowEnumProc@@YGHPAUHWND__@@J@Z)
idLib.lib(win_filesystem.cpp.obj) : error LNK2019: unresolved external symbol __imp__CoTaskMemFree@4 referenced in function "char const * __cdecl Sys_DefaultSavePath(void)" (?Sys_DefaultSavePath@@YAPBDXZ)
idLib.lib(win_filesystem.cpp.obj) : error LNK2019: unresolved external symbol __imp__SHGetFolderPathA@20 referenced in function "char const * __cdecl Sys_DefaultSavePath(void)" (?Sys_DefaultSavePath@@YAPBDXZ)
idLib.lib(LangDict.cpp.obj) : error LNK2019: unresolved external symbol "int __cdecl Sys_Milliseconds(void)" (?Sys_Milliseconds@@YAHXZ) referenced in function "public: char const * __thiscall idLangDict::AddString(char const *)" (?AddString@idLangDict@@QAEPBDPBD@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp__StackWalk64@36 referenced in function "void __cdecl Sys_CaptureExceptionStack(struct _EXCEPTION_POINTERS *)" (?Sys_CaptureExceptionStack@@YAXPAU_EXCEPTION_POINTERS@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp__SymFunctionTableAccess64@12 referenced in function "void __cdecl Sys_CaptureExceptionStack(struct _EXCEPTION_POINTERS *)" (?Sys_CaptureExceptionStack@@YAXPAU_EXCEPTION_POINTERS@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp__SymGetModuleBase64@12 referenced in function "void __cdecl Sys_CaptureExceptionStack(struct _EXCEPTION_POINTERS *)" (?Sys_CaptureExceptionStack@@YAXPAU_EXCEPTION_POINTERS@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp__SymGetLineFromAddr64@20 referenced in function "void __cdecl Sys_DecodeStackTrace(unsigned char *,int,struct debugStackFrame_t *)" (?Sys_DecodeStackTrace@@YAXPAEHPAUdebugStackFrame_t@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp__SymInitialize@12 referenced in function "void __cdecl Sys_DecodeStackTrace(unsigned char *,int,struct debugStackFrame_t *)" (?Sys_DecodeStackTrace@@YAXPAEHPAUdebugStackFrame_t@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol __imp__SymGetSymFromAddr64@20 referenced in function "void __cdecl Sys_DecodeStackTrace(unsigned char *,int,struct debugStackFrame_t *)" (?Sys_DecodeStackTrace@@YAXPAEHPAUdebugStackFrame_t@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2019: unresolved external symbol _MiniDumpWriteDump@28 referenced in function "void __cdecl Sys_WriteMiniDump(struct _EXCEPTION_POINTERS *)" (?Sys_WriteMiniDump@@YAXPAU_EXCEPTION_POINTERS@@@Z)
idLib.lib(win_crashhandler.cpp.obj) : error LNK2001: unresolved external symbol "class idCVar com_version" (?com_version@@3VidCVar@@A)
bin\convertidtech3assets.exe : fatal error LNK1120: 27 unresolved externals
scons: *** [bin\convertidtech3assets.exe] Error 1120
```


### warning kinds

- [9x] C4389
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\gamesys\Event.cpp(786): warning C4389: '==': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\gamesys\Event.cpp(853): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\gamesys\Event.cpp(903): warning C4389: '==': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\gamesys\Event.cpp(943): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1499): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1517): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1537): warning C4389: '!=': signed/unsigned mismatch
- [4x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\external\stb\stb_vorbis.h(4849) : warning C4701: potentially uninitialized local variable 'mid' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\renderbump\renderbump.cpp(1318) : warning C4701: potentially uninitialized local variable 'opt' used
- [3x] C4005
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(392): warning C4005: 'StrCmpN': macro redefinition
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(393): warning C4005: 'StrCmpNI': macro redefinition
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(499): warning C4005: 'StrCmpI': macro redefinition
- [3x] C4245
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch

## windows-x86-release

status: cancelled

errors: 0
warnings: 23 in 5 kinds

### errors


### failure context


### warning kinds

- [7x] C4389
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\gamesys\Event.cpp(853): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\gamesys\Event.cpp(943): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1499): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1517): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1537): warning C4389: '!=': signed/unsigned mismatch
- [6x] C4702
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(368) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1048) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1345) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1379) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1390) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1422) : warning C4702: unreachable code
- [4x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\external\stb\stb_vorbis.h(4849) : warning C4701: potentially uninitialized local variable 'mid' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\renderbump\renderbump.cpp(1318) : warning C4701: potentially uninitialized local variable 'opt' used
- [3x] C4005
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(392): warning C4005: 'StrCmpN': macro redefinition
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(393): warning C4005: 'StrCmpNI': macro redefinition
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(499): warning C4005: 'StrCmpI': macro redefinition
- [3x] C4245
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch

