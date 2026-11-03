# Build digest

commit: 6ce42b70fa35

- windows-x64-debug: cancelled
- windows-x64-release: cancelled
- windows-x86-debug: failure
- windows-x86-release: cancelled

## windows-x64-debug

status: cancelled

errors: 29
warnings: 17 in 6 kinds

### errors

D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1669): error C2601: 'idMaterial::ParseDeform': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1764): error C2601: 'idMaterial::AddImplicitStages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1827): error C2601: 'idMaterial::SortInteractionStages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1868): error C2601: 'idMaterial::ParseMaterial': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2196): error C2601: 'idMaterial::SetGui': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2207): error C2601: 'idMaterial::Parse': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2433): error C2601: 'idMaterial::Print': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2455): error C2601: 'idMaterial::Save': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2464): error C2601: 'idMaterial::AddReference': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2485): error C2601: 'idMaterial::EvaluateRegisters': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2594): error C2601: 'idMaterial::Texgen': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2611): error C2601: 'idMaterial::GetImageWidth': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2621): error C2601: 'idMaterial::GetImageHeight': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2631): error C2601: 'idMaterial::CinematicLength': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2643): error C2601: 'idMaterial::UpdateCinematic': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2655): error C2601: 'idMaterial::CloseCinematic': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2670): error C2601: 'idMaterial::ResetCinematicTime': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2683): error C2601: 'idMaterial::GetCinematicStartTime': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2697): error C2601: 'idMaterial::CinematicIsPlaying': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2713): error C2601: 'idMaterial::CheckForConstantRegisters': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2739): error C2601: 'idMaterial::ImageName': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2755): error C2601: 'idMaterial::Size': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2764): error C2601: 'idMaterial::SetDefaultText': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2790): error C2601: 'idMaterial::DefaultDefinition': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2806): error C2601: 'idMaterial::GetBumpStage': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2820): error C2601: 'idMaterial::ReloadImages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2841): error C2601: 'idMaterial::SetFastPathImages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): fatal error C1075: '{': no matching token found
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Material.cpp.obj] Error 2

### failure context

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Material.cpp.obj

```
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2631): error C2601: 'idMaterial::CinematicLength': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2643): error C2601: 'idMaterial::UpdateCinematic': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2655): error C2601: 'idMaterial::CloseCinematic': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2670): error C2601: 'idMaterial::ResetCinematicTime': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2683): error C2601: 'idMaterial::GetCinematicStartTime': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2697): error C2601: 'idMaterial::CinematicIsPlaying': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2713): error C2601: 'idMaterial::CheckForConstantRegisters': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2739): error C2601: 'idMaterial::ImageName': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2755): error C2601: 'idMaterial::Size': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2764): error C2601: 'idMaterial::SetDefaultText': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2790): error C2601: 'idMaterial::DefaultDefinition': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2806): error C2601: 'idMaterial::GetBumpStage': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2820): error C2601: 'idMaterial::ReloadImages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2841): error C2601: 'idMaterial::SetFastPathImages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): fatal error C1075: '{': no matching token found
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\Material.cpp.obj] Error 2
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
- [1x] C4311
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_rendertools.cpp(724): warning C4311: 'type cast': pointer truncation from 'void *' to 'GLuint'
- [1x] C4302
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_rendertools.cpp(724): warning C4302: 'type cast': truncation from 'void *' to 'GLuint'

## windows-x64-release

status: cancelled

errors: 29
warnings: 23 in 7 kinds

### errors

D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1669): error C2601: 'idMaterial::ParseDeform': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1764): error C2601: 'idMaterial::AddImplicitStages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1827): error C2601: 'idMaterial::SortInteractionStages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1868): error C2601: 'idMaterial::ParseMaterial': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2196): error C2601: 'idMaterial::SetGui': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2207): error C2601: 'idMaterial::Parse': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2433): error C2601: 'idMaterial::Print': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2455): error C2601: 'idMaterial::Save': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2464): error C2601: 'idMaterial::AddReference': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2485): error C2601: 'idMaterial::EvaluateRegisters': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2594): error C2601: 'idMaterial::Texgen': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2611): error C2601: 'idMaterial::GetImageWidth': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2621): error C2601: 'idMaterial::GetImageHeight': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2631): error C2601: 'idMaterial::CinematicLength': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2643): error C2601: 'idMaterial::UpdateCinematic': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2655): error C2601: 'idMaterial::CloseCinematic': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2670): error C2601: 'idMaterial::ResetCinematicTime': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2683): error C2601: 'idMaterial::GetCinematicStartTime': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2697): error C2601: 'idMaterial::CinematicIsPlaying': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2713): error C2601: 'idMaterial::CheckForConstantRegisters': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2739): error C2601: 'idMaterial::ImageName': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2755): error C2601: 'idMaterial::Size': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2764): error C2601: 'idMaterial::SetDefaultText': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2790): error C2601: 'idMaterial::DefaultDefinition': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2806): error C2601: 'idMaterial::GetBumpStage': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2820): error C2601: 'idMaterial::ReloadImages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2841): error C2601: 'idMaterial::SetFastPathImages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): fatal error C1075: '{': no matching token found
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Material.cpp.obj] Error 2

### failure context

- build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Material.cpp.obj

```
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2631): error C2601: 'idMaterial::CinematicLength': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2643): error C2601: 'idMaterial::UpdateCinematic': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2655): error C2601: 'idMaterial::CloseCinematic': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2670): error C2601: 'idMaterial::ResetCinematicTime': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2683): error C2601: 'idMaterial::GetCinematicStartTime': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2697): error C2601: 'idMaterial::CinematicIsPlaying': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2713): error C2601: 'idMaterial::CheckForConstantRegisters': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2739): error C2601: 'idMaterial::ImageName': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2755): error C2601: 'idMaterial::Size': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2764): error C2601: 'idMaterial::SetDefaultText': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2790): error C2601: 'idMaterial::DefaultDefinition': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2806): error C2601: 'idMaterial::GetBumpStage': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2820): error C2601: 'idMaterial::ReloadImages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2841): error C2601: 'idMaterial::SetFastPathImages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): fatal error C1075: '{': no matching token found
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Material.cpp.obj] Error 2
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
- [1x] C4311
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_rendertools.cpp(724): warning C4311: 'type cast': pointer truncation from 'void *' to 'GLuint'
- [1x] C4302
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\tr_backend_rendertools.cpp(724): warning C4302: 'type cast': truncation from 'void *' to 'GLuint'

## windows-x86-debug

status: failure

errors: 29
warnings: 18 in 4 kinds

### errors

D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1669): error C2601: 'idMaterial::ParseDeform': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1764): error C2601: 'idMaterial::AddImplicitStages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1827): error C2601: 'idMaterial::SortInteractionStages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1868): error C2601: 'idMaterial::ParseMaterial': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2196): error C2601: 'idMaterial::SetGui': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2207): error C2601: 'idMaterial::Parse': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2433): error C2601: 'idMaterial::Print': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2455): error C2601: 'idMaterial::Save': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2464): error C2601: 'idMaterial::AddReference': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2485): error C2601: 'idMaterial::EvaluateRegisters': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2594): error C2601: 'idMaterial::Texgen': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2611): error C2601: 'idMaterial::GetImageWidth': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2621): error C2601: 'idMaterial::GetImageHeight': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2631): error C2601: 'idMaterial::CinematicLength': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2643): error C2601: 'idMaterial::UpdateCinematic': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2655): error C2601: 'idMaterial::CloseCinematic': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2670): error C2601: 'idMaterial::ResetCinematicTime': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2683): error C2601: 'idMaterial::GetCinematicStartTime': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2697): error C2601: 'idMaterial::CinematicIsPlaying': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2713): error C2601: 'idMaterial::CheckForConstantRegisters': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2739): error C2601: 'idMaterial::ImageName': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2755): error C2601: 'idMaterial::Size': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2764): error C2601: 'idMaterial::SetDefaultText': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2790): error C2601: 'idMaterial::DefaultDefinition': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2806): error C2601: 'idMaterial::GetBumpStage': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2820): error C2601: 'idMaterial::ReloadImages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2841): error C2601: 'idMaterial::SetFastPathImages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): fatal error C1075: '{': no matching token found
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Material.cpp.obj] Error 2

### failure context

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Material.cpp.obj

```
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2631): error C2601: 'idMaterial::CinematicLength': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2643): error C2601: 'idMaterial::UpdateCinematic': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2655): error C2601: 'idMaterial::CloseCinematic': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2670): error C2601: 'idMaterial::ResetCinematicTime': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2683): error C2601: 'idMaterial::GetCinematicStartTime': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2697): error C2601: 'idMaterial::CinematicIsPlaying': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2713): error C2601: 'idMaterial::CheckForConstantRegisters': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2739): error C2601: 'idMaterial::ImageName': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2755): error C2601: 'idMaterial::Size': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2764): error C2601: 'idMaterial::SetDefaultText': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2790): error C2601: 'idMaterial::DefaultDefinition': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2806): error C2601: 'idMaterial::GetBumpStage': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2820): error C2601: 'idMaterial::ReloadImages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2841): error C2601: 'idMaterial::SetFastPathImages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): fatal error C1075: '{': no matching token found
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Material.cpp.obj] Error 2
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
- [3x] C4005
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(392): warning C4005: 'StrCmpN': macro redefinition
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(393): warning C4005: 'StrCmpNI': macro redefinition
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(499): warning C4005: 'StrCmpI': macro redefinition
- [3x] C4245
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [3x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\renderbump\renderbump.cpp(1318) : warning C4701: potentially uninitialized local variable 'opt' used

## windows-x86-release

status: cancelled

errors: 29
warnings: 19 in 4 kinds

### errors

D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1669): error C2601: 'idMaterial::ParseDeform': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1764): error C2601: 'idMaterial::AddImplicitStages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1827): error C2601: 'idMaterial::SortInteractionStages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1868): error C2601: 'idMaterial::ParseMaterial': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2196): error C2601: 'idMaterial::SetGui': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2207): error C2601: 'idMaterial::Parse': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2433): error C2601: 'idMaterial::Print': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2455): error C2601: 'idMaterial::Save': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2464): error C2601: 'idMaterial::AddReference': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2485): error C2601: 'idMaterial::EvaluateRegisters': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2594): error C2601: 'idMaterial::Texgen': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2611): error C2601: 'idMaterial::GetImageWidth': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2621): error C2601: 'idMaterial::GetImageHeight': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2631): error C2601: 'idMaterial::CinematicLength': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2643): error C2601: 'idMaterial::UpdateCinematic': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2655): error C2601: 'idMaterial::CloseCinematic': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2670): error C2601: 'idMaterial::ResetCinematicTime': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2683): error C2601: 'idMaterial::GetCinematicStartTime': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2697): error C2601: 'idMaterial::CinematicIsPlaying': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2713): error C2601: 'idMaterial::CheckForConstantRegisters': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2739): error C2601: 'idMaterial::ImageName': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2755): error C2601: 'idMaterial::Size': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2764): error C2601: 'idMaterial::SetDefaultText': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2790): error C2601: 'idMaterial::DefaultDefinition': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2806): error C2601: 'idMaterial::GetBumpStage': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2820): error C2601: 'idMaterial::ReloadImages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2841): error C2601: 'idMaterial::SetFastPathImages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): fatal error C1075: '{': no matching token found
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\Material.cpp.obj] Error 2

### failure context

- build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\Material.cpp.obj

```
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2631): error C2601: 'idMaterial::CinematicLength': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2643): error C2601: 'idMaterial::UpdateCinematic': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2655): error C2601: 'idMaterial::CloseCinematic': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2670): error C2601: 'idMaterial::ResetCinematicTime': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2683): error C2601: 'idMaterial::GetCinematicStartTime': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2697): error C2601: 'idMaterial::CinematicIsPlaying': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2713): error C2601: 'idMaterial::CheckForConstantRegisters': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2739): error C2601: 'idMaterial::ImageName': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2755): error C2601: 'idMaterial::Size': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2764): error C2601: 'idMaterial::SetDefaultText': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2790): error C2601: 'idMaterial::DefaultDefinition': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2806): error C2601: 'idMaterial::GetBumpStage': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2820): error C2601: 'idMaterial::ReloadImages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(2841): error C2601: 'idMaterial::SetFastPathImages': local function definitions are illegal
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): note: this line contains a '{' which has not yet been matched
D:\a\Doom3BFG\Doom3BFG\neo\renderer\Material.cpp(1115): fatal error C1075: '{': no matching token found
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\Material.cpp.obj] Error 2
```


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
- [3x] C4005
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(392): warning C4005: 'StrCmpN': macro redefinition
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(393): warning C4005: 'StrCmpNI': macro redefinition
  - C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\um\shlwapi.h(499): warning C4005: 'StrCmpI': macro redefinition
- [3x] C4245
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - D:\a\Doom3BFG\Doom3BFG\neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch

