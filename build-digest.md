# Build digest

commit: 7410fd5dc52a

- windows-x64-debug: failure
- windows-x64-release: cancelled
- windows-x86-debug: cancelled
- windows-x86-release: cancelled

## windows-x64-debug

status: failure

errors: 17
warnings: 25 in 7 kinds

### errors

D:\a\Doom3BFG\Doom3BFG\neo\tools\convertidtech3assets\ToolFramework.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
D:\a\Doom3BFG\Doom3BFG\neo\framework\CmdSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CmdSystem.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\framework\CVarSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\tools\convertidtech3assets\ToolFramework.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CVarSystem.cpp.obj] Error 2
DD:\a\Doom3BFG\Doom3BFG\neo\framework\File_Manifest.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS:\a\Doom3BFG\Doom3BFG\neo\framework\File.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-ms
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Manifest.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\framework\File_Pak.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
D:\a\Doom3BFG\Doom3BFG\neo\framework\File_Resource.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Pak.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\framework\File_Zip.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Resource.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Zip.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\FileSystem.cpp.obj] Error 2

### failure context

- build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CmdSystem.cpp.obj

```
gamex86.lib(Item.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Item.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuScreen_HUD.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuScreen_HUD.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuHandler_HUD.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuHandler_HUD.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuHandler_Scoreboard.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuHandler_Scoreboard.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(Push.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Push.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(Physics_Static.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Physics_Static.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(Physics_Player.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Physics_Player.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(Mover.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Mover.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(Force_Constant.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Force_Constant.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(AF.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(AF.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(Force_Field.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Force_Field.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(Force_Spring.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Force_Spring.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(IK.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(IK.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(PlayerIcon.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(PlayerIcon.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(AimAssist.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(AimAssist.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_List.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_List.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_CommandBar.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_CommandBar.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_DynamicList.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_DynamicList.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_NavBar.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_NavBar.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_Scrollbar.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_Scrollbar.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuHandler_PDA.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuHandler_PDA.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\tools\convertidtech3assets\ToolFramework.cpp.obj /c neo\tools\convertidtech3assets\ToolFramework.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CmdSystem.cpp.obj /c neo\framework\CmdSystem.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D
ToolFramework.cpp
D:\a\Doom3BFG\Doom3BFG\neo\tools\convertidtech3assets\ToolFramework.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
CmdSystem.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CVarSystem.cpp.obj /c neo\framework\CVarSystem.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC 
CVarSystem.cpp
D:\a\Doom3BFG\Doom3BFG\neo\framework\CmdSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CmdSystem.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\tools\convertidtech3assets\ToolFramework.cpp.obj

```
gamex86.lib(MenuHandler_HUD.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuHandler_HUD.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuHandler_Scoreboard.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuHandler_Scoreboard.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(Push.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Push.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(Physics_Static.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Physics_Static.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(Physics_Player.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Physics_Player.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(Mover.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Mover.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(Force_Constant.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Force_Constant.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(AF.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(AF.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(Force_Field.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Force_Field.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(Force_Spring.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Force_Spring.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(IK.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(IK.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(PlayerIcon.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(PlayerIcon.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(AimAssist.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(AimAssist.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_List.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_List.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_CommandBar.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_CommandBar.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_DynamicList.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_DynamicList.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_NavBar.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_NavBar.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_Scrollbar.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_Scrollbar.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuHandler_PDA.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuHandler_PDA.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\tools\convertidtech3assets\ToolFramework.cpp.obj /c neo\tools\convertidtech3assets\ToolFramework.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CmdSystem.cpp.obj /c neo\framework\CmdSystem.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D
ToolFramework.cpp
D:\a\Doom3BFG\Doom3BFG\neo\tools\convertidtech3assets\ToolFramework.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
CmdSystem.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CVarSystem.cpp.obj /c neo\framework\CVarSystem.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC 
CVarSystem.cpp
D:\a\Doom3BFG\Doom3BFG\neo\framework\CmdSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CmdSystem.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\framework\CVarSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\tools\convertidtech3assets\ToolFramework.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CVarSystem.cpp.obj

```
gamex86.lib(Push.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Push.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(Physics_Static.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Physics_Static.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(Physics_Player.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Physics_Player.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(Mover.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Mover.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(Force_Constant.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Force_Constant.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(AF.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(AF.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(Force_Field.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Force_Field.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(Force_Spring.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Force_Spring.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(IK.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(IK.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(PlayerIcon.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(PlayerIcon.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(AimAssist.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(AimAssist.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_List.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_List.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_CommandBar.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_CommandBar.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_DynamicList.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_DynamicList.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_NavBar.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_NavBar.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_Scrollbar.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_Scrollbar.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuHandler_PDA.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuHandler_PDA.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\tools\convertidtech3assets\ToolFramework.cpp.obj /c neo\tools\convertidtech3assets\ToolFramework.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CmdSystem.cpp.obj /c neo\framework\CmdSystem.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D
ToolFramework.cpp
D:\a\Doom3BFG\Doom3BFG\neo\tools\convertidtech3assets\ToolFramework.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
CmdSystem.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CVarSystem.cpp.obj /c neo\framework\CVarSystem.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC 
CVarSystem.cpp
D:\a\Doom3BFG\Doom3BFG\neo\framework\CmdSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CmdSystem.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\framework\CVarSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\tools\convertidtech3assets\ToolFramework.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File.cpp.obj /c neo\framework\File.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CVarSystem.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File.cpp.obj

```
gamex86.lib(Force_Spring.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(Force_Spring.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(IK.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(IK.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(PlayerIcon.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(PlayerIcon.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(AimAssist.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(AimAssist.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_List.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_List.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_CommandBar.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_CommandBar.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_DynamicList.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_DynamicList.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_NavBar.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_NavBar.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_Scrollbar.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_Scrollbar.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuHandler_PDA.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuHandler_PDA.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\tools\convertidtech3assets\ToolFramework.cpp.obj /c neo\tools\convertidtech3assets\ToolFramework.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CmdSystem.cpp.obj /c neo\framework\CmdSystem.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D
ToolFramework.cpp
D:\a\Doom3BFG\Doom3BFG\neo\tools\convertidtech3assets\ToolFramework.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
CmdSystem.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CVarSystem.cpp.obj /c neo\framework\CVarSystem.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC 
CVarSystem.cpp
D:\a\Doom3BFG\Doom3BFG\neo\framework\CmdSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CmdSystem.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\framework\CVarSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\tools\convertidtech3assets\ToolFramework.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File.cpp.obj /c neo\framework\File.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CVarSystem.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Manifest.cpp.obj /c neo\framework\File_Manifest.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pd
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Pak.cpp.obj /c neo\framework\File_Pak.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__
File.cpp
File_Manifest.cpp
DD:\a\Doom3BFG\Doom3BFG\neo\framework\File_Manifest.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS:\a\Doom3BFG\Doom3BFG\neo\framework\File.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-ms

scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Manifest.cpp.obj

```
gamex86.lib(IK.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(IK.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(PlayerIcon.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(PlayerIcon.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(AimAssist.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(AimAssist.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_List.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_List.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_CommandBar.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_CommandBar.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_DynamicList.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_DynamicList.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_NavBar.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_NavBar.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuWidget_Scrollbar.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_Scrollbar.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuHandler_PDA.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuHandler_PDA.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\tools\convertidtech3assets\ToolFramework.cpp.obj /c neo\tools\convertidtech3assets\ToolFramework.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CmdSystem.cpp.obj /c neo\framework\CmdSystem.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D
ToolFramework.cpp
D:\a\Doom3BFG\Doom3BFG\neo\tools\convertidtech3assets\ToolFramework.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
CmdSystem.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CVarSystem.cpp.obj /c neo\framework\CVarSystem.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC 
CVarSystem.cpp
D:\a\Doom3BFG\Doom3BFG\neo\framework\CmdSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CmdSystem.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\framework\CVarSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\tools\convertidtech3assets\ToolFramework.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File.cpp.obj /c neo\framework\File.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CVarSystem.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Manifest.cpp.obj /c neo\framework\File_Manifest.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pd
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Pak.cpp.obj /c neo\framework\File_Pak.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__
File.cpp
File_Manifest.cpp
DD:\a\Doom3BFG\Doom3BFG\neo\framework\File_Manifest.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS:\a\Doom3BFG\Doom3BFG\neo\framework\File.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-ms

scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Manifest.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Pak.cpp.obj

```
gamex86.lib(MenuWidget_Scrollbar.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuWidget_Scrollbar.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
gamex86.lib(MenuHandler_PDA.cpp.obj) : warning LNK4099: PDB 'msvc-compiler.pdb' was not found with 'gamex86.lib(MenuHandler_PDA.cpp.obj)' or at 'D:\a\Doom3BFG\Doom3BFG\bin\msvc-compiler.pdb'; linking object as if no debug info
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\tools\convertidtech3assets\ToolFramework.cpp.obj /c neo\tools\convertidtech3assets\ToolFramework.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CmdSystem.cpp.obj /c neo\framework\CmdSystem.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D
ToolFramework.cpp
D:\a\Doom3BFG\Doom3BFG\neo\tools\convertidtech3assets\ToolFramework.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
CmdSystem.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CVarSystem.cpp.obj /c neo\framework\CVarSystem.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC 
CVarSystem.cpp
D:\a\Doom3BFG\Doom3BFG\neo\framework\CmdSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CmdSystem.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\framework\CVarSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\tools\convertidtech3assets\ToolFramework.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File.cpp.obj /c neo\framework\File.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CVarSystem.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Manifest.cpp.obj /c neo\framework\File_Manifest.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pd
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Pak.cpp.obj /c neo\framework\File_Pak.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__
File.cpp
File_Manifest.cpp
DD:\a\Doom3BFG\Doom3BFG\neo\framework\File_Manifest.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS:\a\Doom3BFG\Doom3BFG\neo\framework\File.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-ms

scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Manifest.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Resource.cpp.obj /c neo\framework\File_Resource.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pd
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Zip.cpp.obj /c neo\framework\File_Zip.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__
File_Pak.cpp
File_Resource.cpp
D:\a\Doom3BFG\Doom3BFG\neo\framework\File_Pak.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
File_Zip.cpp
D:\a\Doom3BFG\Doom3BFG\neo\framework\File_Resource.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Pak.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Resource.cpp.obj

```
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\tools\convertidtech3assets\ToolFramework.cpp.obj /c neo\tools\convertidtech3assets\ToolFramework.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CmdSystem.cpp.obj /c neo\framework\CmdSystem.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D
ToolFramework.cpp
D:\a\Doom3BFG\Doom3BFG\neo\tools\convertidtech3assets\ToolFramework.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
CmdSystem.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CVarSystem.cpp.obj /c neo\framework\CVarSystem.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC 
CVarSystem.cpp
D:\a\Doom3BFG\Doom3BFG\neo\framework\CmdSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CmdSystem.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\framework\CVarSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\tools\convertidtech3assets\ToolFramework.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File.cpp.obj /c neo\framework\File.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CVarSystem.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Manifest.cpp.obj /c neo\framework\File_Manifest.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pd
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Pak.cpp.obj /c neo\framework\File_Pak.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__
File.cpp
File_Manifest.cpp
DD:\a\Doom3BFG\Doom3BFG\neo\framework\File_Manifest.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS:\a\Doom3BFG\Doom3BFG\neo\framework\File.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-ms

scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Manifest.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Resource.cpp.obj /c neo\framework\File_Resource.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pd
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Zip.cpp.obj /c neo\framework\File_Zip.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__
File_Pak.cpp
File_Resource.cpp
D:\a\Doom3BFG\Doom3BFG\neo\framework\File_Pak.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
File_Zip.cpp
D:\a\Doom3BFG\Doom3BFG\neo\framework\File_Resource.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Pak.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\framework\File_Zip.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Resource.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Zip.cpp.obj

```
ToolFramework.cpp
D:\a\Doom3BFG\Doom3BFG\neo\tools\convertidtech3assets\ToolFramework.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
CmdSystem.cpp
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CVarSystem.cpp.obj /c neo\framework\CVarSystem.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC 
CVarSystem.cpp
D:\a\Doom3BFG\Doom3BFG\neo\framework\CmdSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CmdSystem.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\framework\CVarSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\tools\convertidtech3assets\ToolFramework.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File.cpp.obj /c neo\framework\File.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CVarSystem.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Manifest.cpp.obj /c neo\framework\File_Manifest.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pd
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Pak.cpp.obj /c neo\framework\File_Pak.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__
File.cpp
File_Manifest.cpp
DD:\a\Doom3BFG\Doom3BFG\neo\framework\File_Manifest.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS:\a\Doom3BFG\Doom3BFG\neo\framework\File.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-ms

scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Manifest.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Resource.cpp.obj /c neo\framework\File_Resource.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pd
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Zip.cpp.obj /c neo\framework\File_Zip.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__
File_Pak.cpp
File_Resource.cpp
D:\a\Doom3BFG\Doom3BFG\neo\framework\File_Pak.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
File_Zip.cpp
D:\a\Doom3BFG\Doom3BFG\neo\framework\File_Resource.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Pak.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\framework\File_Zip.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Resource.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\FileSystem.cpp.obj /c neo\framework\FileSystem.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC 
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Zip.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\FileSystem.cpp.obj

```
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CVarSystem.cpp.obj /c neo\framework\CVarSystem.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC 
CVarSystem.cpp
D:\a\Doom3BFG\Doom3BFG\neo\framework\CmdSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CmdSystem.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\framework\CVarSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\tools\convertidtech3assets\ToolFramework.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File.cpp.obj /c neo\framework\File.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__DOOM__ /
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\CVarSystem.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Manifest.cpp.obj /c neo\framework\File_Manifest.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pd
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Pak.cpp.obj /c neo\framework\File_Pak.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__
File.cpp
File_Manifest.cpp
DD:\a\Doom3BFG\Doom3BFG\neo\framework\File_Manifest.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS:\a\Doom3BFG\Doom3BFG\neo\framework\File.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-ms

scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Manifest.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Resource.cpp.obj /c neo\framework\File_Resource.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pd
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Zip.cpp.obj /c neo\framework\File_Zip.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /D__
File_Pak.cpp
File_Resource.cpp
D:\a\Doom3BFG\Doom3BFG\neo\framework\File_Pak.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
File_Zip.cpp
D:\a\Doom3BFG\Doom3BFG\neo\framework\File_Resource.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Pak.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\framework\File_Zip.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Resource.cpp.obj] Error 2
cl /Fobuild\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\FileSystem.cpp.obj /c neo\framework\FileSystem.cpp /TP /W4 /nologo /GS /std:c++17 /EHsc /GR /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC /nologo /W4 /nologo /GS /MTd /Zi /FS /Od /FdD:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb /FC 
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\File_Zip.cpp.obj] Error 2
FileSystem.cpp
D:\a\Doom3BFG\Doom3BFG\neo\framework\FileSystem.cpp: fatal error C1041: cannot open program database 'D:\a\Doom3BFG\Doom3BFG\build\scons\windows-x64-debug-msvc\obj\msvc-compiler.pdb'; if multiple CL.EXE write to the same .PDB file, please use /FS
scons: *** [build\scons\windows-x64-debug-msvc\obj\ConvertIdTech3Assets\framework\FileSystem.cpp.obj] Error 2
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
warnings: 31 in 8 kinds

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

## windows-x86-debug

status: cancelled

errors: 0
warnings: 16 in 4 kinds

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
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1499): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1517): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_draw.cpp(1537): warning C4389: '!=': signed/unsigned mismatch
- [3x] C4005
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(392): warning C4005: 'StrCmpN': macro redefinition
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(393): warning C4005: 'StrCmpNI': macro redefinition
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(499): warning C4005: 'StrCmpI': macro redefinition
- [3x] C4245
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [1x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\external\stb\stb_vorbis.h(4849) : warning C4701: potentially uninitialized local variable 'mid' used

## windows-x86-release

status: cancelled

errors: 0
warnings: 14 in 4 kinds

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
- [2x] C4389
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\gamesys\Event.cpp(853): warning C4389: '!=': signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\gamesys\Event.cpp(943): warning C4389: '!=': signed/unsigned mismatch

