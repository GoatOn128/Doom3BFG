# Build digest

commit: 4e702f3cce44

- windows-x64-debug: failure
- windows-x64-release: cancelled
- windows-x86-debug: cancelled
- windows-x86-release: cancelled

## windows-x64-debug

status: failure

errors: 12
warnings: 24 in 7 kinds

### errors

D:\a\Doom3BFG\Doom3BFG\neo\renderer\Image_files.cpp(236): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Image_files.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_md2.cpp(293): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_md2.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(71): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(392): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_mdl.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_sp2.cpp(111): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_sp2.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_spr.cpp(83): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_spr.cpp(210): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_spr.cpp.obj] Error 2

### failure context

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Image_files.cpp.obj

```
D:\a\Doom3BFG\Doom3BFG\neo\renderer\BufferObject.cpp(671): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Color\ColorSpace.cpp.obj /c neo\renderer\Color\ColorSpace.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D_
D:\a\Doom3BFG\Doom3BFG\neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
ColorSpace.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\DeclRenderProg.cpp.obj /c neo\renderer\DeclRenderProg.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOO
DeclRenderProg.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\DeclRenderProgGenerator.cpp.obj /c neo\renderer\DeclRenderProgGenerator.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compil
DeclRenderProgGenerator.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\DXT\DXTDecoder.cpp.obj /c neo\renderer\DXT\DXTDecoder.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOO
DXTDecoder.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\DXT\DXTEncoder.cpp.obj /c neo\renderer\DXT\DXTEncoder.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOO
DXTEncoder.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\DXT\DXTEncoder_SSE2.cpp.obj /c neo\renderer\DXT\DXTEncoder_SSE2.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /
DXTEncoder_SSE2.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Font.cpp.obj /c neo\renderer\Font.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_PC /D_CRT_S
Font.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\GLMatrix.cpp.obj /c neo\renderer\GLMatrix.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_PC 
GLMatrix.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\GuiModel.cpp.obj /c neo\renderer\GuiModel.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_PC 
GuiModel.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Image_files.cpp.obj /c neo\renderer\Image_files.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /D
Image_files.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Image_intrinsic.cpp.obj /c neo\renderer\Image_intrinsic.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__D
Image_intrinsic.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Image_load.cpp.obj /c neo\renderer\Image_load.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID
Image_load.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Image_files.cpp(236): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Image_files.cpp(236): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Image_files.cpp(236): note: while trying to match the argument list '(const char [18], byte **)'
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Image_files.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_md2.cpp.obj

```
Retrieved `build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\jobs\prelightshadowvolume\PreLightShadowVolume.cpp.obj' from cache
Retrieved `build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\jobs\ShadowShared.cpp.obj' from cache
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Material.cpp.obj /c neo\renderer\Material.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_PC 
Material.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model.cpp.obj /c neo\renderer\Model.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_PC /D_CRT
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_ase.cpp.obj /c neo\renderer\Model_ase.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model.cpp
Model_ase.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_beam.cpp.obj /c neo\renderer\Model_beam.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID
Model_beam.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_common.cpp.obj /c neo\renderer\Model_common.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ 
Model_common.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_liquid.cpp.obj /c neo\renderer\Model_liquid.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ 
Model_liquid.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_lwo.cpp.obj /c neo\renderer\Model_lwo.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_lwo.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_ma.cpp.obj /c neo\renderer\Model_ma.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_PC 
Model_ma.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_md2.cpp.obj /c neo\renderer\Model_md2.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_md2.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_md3.cpp.obj /c neo\renderer\Model_md3.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_md3.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_md4.cpp.obj /c neo\renderer\Model_md4.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_md4.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_md5.cpp.obj /c neo\renderer\Model_md5.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_md5.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_md2.cpp(293): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_md2.cpp(293): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_md2.cpp(293): note: while trying to match the argument list '(idStr, byte **, int64 *)'
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_md2.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_mdl.cpp.obj

```
Model_md2.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_md3.cpp.obj /c neo\renderer\Model_md3.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_md3.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_md4.cpp.obj /c neo\renderer\Model_md4.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_md4.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_md5.cpp.obj /c neo\renderer\Model_md5.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_md5.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_md2.cpp(293): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_md2.cpp(293): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_md2.cpp(293): note: while trying to match the argument list '(idStr, byte **, int64 *)'
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_md2.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_mdc.cpp.obj /c neo\renderer\Model_mdc.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_mdc.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_mdl.cpp.obj /c neo\renderer\Model_mdl.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_mdl.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_mdm.cpp.obj /c neo\renderer\Model_mdm.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_mdm.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_mds.cpp.obj /c neo\renderer\Model_mds.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_mds.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_prt.cpp.obj /c neo\renderer\Model_prt.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_prt.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(71): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(71): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(71): note: while trying to match the argument list '(const char [16], byte **)'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(392): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(392): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(392): note: while trying to match the argument list '(idStr, byte **, int64 *)'
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_mdl.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_sp2.cpp.obj

```
Model_mdc.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_mdl.cpp.obj /c neo\renderer\Model_mdl.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_mdl.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_mdm.cpp.obj /c neo\renderer\Model_mdm.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_mdm.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_mds.cpp.obj /c neo\renderer\Model_mds.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_mds.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_prt.cpp.obj /c neo\renderer\Model_prt.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_prt.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(71): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(71): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(71): note: while trying to match the argument list '(const char [16], byte **)'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(392): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(392): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(392): note: while trying to match the argument list '(idStr, byte **, int64 *)'
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_mdl.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_sp2.cpp.obj /c neo\renderer\Model_sp2.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_sp2.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_spr.cpp.obj /c neo\renderer\Model_spr.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_spr.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_sprite.cpp.obj /c neo\renderer\Model_sprite.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ 
Model_sprite.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\ModelDecal.cpp.obj /c neo\renderer\ModelDecal.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID
ModelDecal.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_sp2.cpp(111): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_sp2.cpp(111): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_sp2.cpp(111): note: while trying to match the argument list '(idStr, byte **, int64 *)'
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_sp2.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_spr.cpp.obj

```
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(71): note: while trying to match the argument list '(const char [16], byte **)'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(392): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(392): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(392): note: while trying to match the argument list '(idStr, byte **, int64 *)'
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_mdl.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_sp2.cpp.obj /c neo\renderer\Model_sp2.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_sp2.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_spr.cpp.obj /c neo\renderer\Model_spr.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_spr.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_sprite.cpp.obj /c neo\renderer\Model_sprite.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ 
Model_sprite.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\ModelDecal.cpp.obj /c neo\renderer\ModelDecal.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID
ModelDecal.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_sp2.cpp(111): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_sp2.cpp(111): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_sp2.cpp(111): note: while trying to match the argument list '(idStr, byte **, int64 *)'
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_sp2.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\ModelManager.cpp.obj /c neo\renderer\ModelManager.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ 
ModelManager.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_spr.cpp(83): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_spr.cpp(83): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_spr.cpp(83): note: while trying to match the argument list '(const char [16], byte **)'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_spr.cpp(210): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_spr.cpp(210): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_spr.cpp(210): note: while trying to match the argument list '(idStr, byte **, int64 *)'
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Model_spr.cpp.obj] Error 2
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
- [3x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\renderbump\renderbump.cpp(1318) : warning C4701: potentially uninitialized local variable 'opt' used

## windows-x64-release

status: cancelled

errors: 0
warnings: 11 in 3 kinds

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
- [2x] C4245
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch

## windows-x86-debug

status: cancelled

errors: 12
warnings: 10 in 3 kinds

### errors

D:\a\Doom3BFG\Doom3BFG\neo\renderer\Image_files.cpp(236): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Image_files.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_md2.cpp(293): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_md2.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(71): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(392): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_mdl.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_sp2.cpp(111): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_sp2.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_spr.cpp(83): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_spr.cpp(210): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_spr.cpp.obj] Error 2

### failure context

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Image_files.cpp.obj

```
CinematicRoQ.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Color\ColorSpace.cpp.obj /c neo\renderer\Color\ColorSpace.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D_
ColorSpace.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\DeclRenderProg.cpp.obj /c neo\renderer\DeclRenderProg.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOO
DeclRenderProg.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\DeclRenderProgGenerator.cpp.obj /c neo\renderer\DeclRenderProgGenerator.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compil
DeclRenderProgGenerator.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\DXT\DXTDecoder.cpp.obj /c neo\renderer\DXT\DXTDecoder.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOO
DXTDecoder.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\DXT\DXTEncoder.cpp.obj /c neo\renderer\DXT\DXTEncoder.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOO
DXTEncoder.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\DXT\DXTEncoder_SSE2.cpp.obj /c neo\renderer\DXT\DXTEncoder_SSE2.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /
DXTEncoder_SSE2.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Font.cpp.obj /c neo\renderer\Font.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_PC /D_CRT_S
Font.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\GLMatrix.cpp.obj /c neo\renderer\GLMatrix.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_PC 
GLMatrix.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\GuiModel.cpp.obj /c neo\renderer\GuiModel.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_PC 
GuiModel.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Image_files.cpp.obj /c neo\renderer\Image_files.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /D
Image_files.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Image_intrinsic.cpp.obj /c neo\renderer\Image_intrinsic.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__D
Image_intrinsic.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Image_load.cpp.obj /c neo\renderer\Image_load.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID
Image_load.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Image_files.cpp(236): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Image_files.cpp(236): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Image_files.cpp(236): note: while trying to match the argument list '(const char [18], byte **)'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Image_files.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_md2.cpp.obj

```
Retrieved `build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\jobs\prelightshadowvolume\PreLightShadowVolume.cpp.obj' from cache
Retrieved `build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\jobs\ShadowShared.cpp.obj' from cache
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Material.cpp.obj /c neo\renderer\Material.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_PC 
Material.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model.cpp.obj /c neo\renderer\Model.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_PC /D_CRT
Model.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_ase.cpp.obj /c neo\renderer\Model_ase.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_ase.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_beam.cpp.obj /c neo\renderer\Model_beam.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID
Model_beam.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_common.cpp.obj /c neo\renderer\Model_common.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ 
Model_common.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_liquid.cpp.obj /c neo\renderer\Model_liquid.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ 
Model_liquid.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_lwo.cpp.obj /c neo\renderer\Model_lwo.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_lwo.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_ma.cpp.obj /c neo\renderer\Model_ma.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_PC 
Model_ma.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_md2.cpp.obj /c neo\renderer\Model_md2.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_md2.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_md3.cpp.obj /c neo\renderer\Model_md3.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_md3.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_md4.cpp.obj /c neo\renderer\Model_md4.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_md4.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_md5.cpp.obj /c neo\renderer\Model_md5.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_md5.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_md2.cpp(293): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_md2.cpp(293): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_md2.cpp(293): note: while trying to match the argument list '(idStr, byte **, int64 *)'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_md2.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_mdl.cpp.obj

```
Model_md2.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_md3.cpp.obj /c neo\renderer\Model_md3.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_md3.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_md4.cpp.obj /c neo\renderer\Model_md4.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_md4.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_md5.cpp.obj /c neo\renderer\Model_md5.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_md5.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_md2.cpp(293): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_md2.cpp(293): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_md2.cpp(293): note: while trying to match the argument list '(idStr, byte **, int64 *)'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_md2.cpp.obj] Error 2
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_mdc.cpp.obj /c neo\renderer\Model_mdc.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_mdc.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_mdl.cpp.obj /c neo\renderer\Model_mdl.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_mdm.cpp.obj /c neo\renderer\Model_mdm.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_mdl.cpp
Model_mdm.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_mds.cpp.obj /c neo\renderer\Model_mds.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_mds.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_prt.cpp.obj /c neo\renderer\Model_prt.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_prt.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(71): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(71): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(71): note: while trying to match the argument list '(const char [16], byte **)'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(392): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(392): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(392): note: while trying to match the argument list '(idStr, byte **, int64 *)'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_mdl.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_sp2.cpp.obj

```
Model_mdc.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_mdl.cpp.obj /c neo\renderer\Model_mdl.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_mdm.cpp.obj /c neo\renderer\Model_mdm.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_mdl.cpp
Model_mdm.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_mds.cpp.obj /c neo\renderer\Model_mds.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_mds.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_prt.cpp.obj /c neo\renderer\Model_prt.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_prt.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(71): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(71): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(71): note: while trying to match the argument list '(const char [16], byte **)'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(392): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(392): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(392): note: while trying to match the argument list '(idStr, byte **, int64 *)'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_mdl.cpp.obj] Error 2
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_sp2.cpp.obj /c neo\renderer\Model_sp2.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_sp2.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_spr.cpp.obj /c neo\renderer\Model_spr.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_spr.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_sprite.cpp.obj /c neo\renderer\Model_sprite.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ 
Model_sprite.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\ModelDecal.cpp.obj /c neo\renderer\ModelDecal.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID
ModelDecal.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_sp2.cpp(111): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_sp2.cpp(111): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_sp2.cpp(111): note: while trying to match the argument list '(idStr, byte **, int64 *)'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_sp2.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_spr.cpp.obj

```
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(71): note: while trying to match the argument list '(const char [16], byte **)'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(392): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(392): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_mdl.cpp(392): note: while trying to match the argument list '(idStr, byte **, int64 *)'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_mdl.cpp.obj] Error 2
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_sp2.cpp.obj /c neo\renderer\Model_sp2.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_sp2.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_spr.cpp.obj /c neo\renderer\Model_spr.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID_P
Model_spr.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_sprite.cpp.obj /c neo\renderer\Model_sprite.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ 
Model_sprite.cpp
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\ModelDecal.cpp.obj /c neo\renderer\ModelDecal.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /DID
ModelDecal.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_sp2.cpp(111): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_sp2.cpp(111): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_sp2.cpp(111): note: while trying to match the argument list '(idStr, byte **, int64 *)'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_sp2.cpp.obj] Error 2
cl /Fobuild\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\ModelManager.cpp.obj /c neo\renderer\ModelManager.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x86-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ 
ModelManager.cpp
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_spr.cpp(83): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_spr.cpp(83): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_spr.cpp(83): note: while trying to match the argument list '(const char [16], byte **)'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_spr.cpp(210): error C2664: 'int idFileSystem::ReadFile(const char *,void **,int64 *)': cannot convert argument 2 from 'byte **' to 'void **'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_spr.cpp(210): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.h(122): note: see declaration of 'idFileSystem::ReadFile'
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Model_spr.cpp(210): note: while trying to match the argument list '(idStr, byte **, int64 *)'
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_spr.cpp.obj] Error 2
```


### warning kinds

- [4x] C4389
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\gamesys\Event.cpp(786): warning C4389: '==': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\gamesys\Event.cpp(853): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\gamesys\Event.cpp(903): warning C4389: '==': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\gamesys\Event.cpp(943): warning C4389: '!=': signed/unsigned mismatch
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
warnings: 13 in 4 kinds

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
- [2x] C4245
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
- [2x] C4389
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\gamesys\Event.cpp(853): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\gamesys\Event.cpp(943): warning C4389: '!=': signed/unsigned mismatch

