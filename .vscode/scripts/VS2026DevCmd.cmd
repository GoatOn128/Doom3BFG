@echo off
rem Initialize the Visual Studio 2026 (18.x) developer environment.
rem This script deliberately avoids FOR /F ('command') parsing: the default
rem vswhere path contains "Program Files (x86)", whose parentheses can break
rem nested CMD parsing and produce errors such as "C:\Program is not recognized".
rem
rem Usage:
rem   call .\.vscode\scripts\VS2026DevCmd.cmd
rem       Loads the x64 developer environment into the current terminal.
rem   call .\.vscode\scripts\VS2026DevCmd.cmd x86 debug 8 msvc
rem       Loads the matching environment and runs SCons.
rem   call .\.vscode\scripts\VS2026DevCmd.cmd x64 release 8 msvc dll
rem       Same, plus dll=1 so the game code builds as bin/gamex86.dll.
rem   call .\.vscode\scripts\VS2026DevCmd.cmd x64 debug 8 clang
rem       Same, but with toolchain=clang (LLVM over MSVC).
rem   call .\.vscode\scripts\VS2026DevCmd.cmd x64 debug 8 gcc
rem       Builds with MinGW gcc; Visual Studio is not used or required.
rem
rem   Arguments: <arch> <config> <jobs> <toolchain> [dll]

set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
set "VSINSTALL_FILE=%TEMP%\VSDevCmd_%RANDOM%_%RANDOM%.txt"
set "VSINSTALL="

rem Parse and validate the raw arguments before the Visual Studio lookup:
rem the gcc toolchain skips Visual Studio entirely. The checks run on
rem the raw %1..%5 so a stale or mangled variable cannot trip them.
rem The argument order is: <arch> <config> <jobs> <toolchain> [dll]
set "BUILD_ARCH=%~1"
set "BUILD_CONFIG=%~2"
set "BUILD_JOBS=%~3"
set "BUILD_TOOLCHAIN=%~4"
set "BUILD_DLL=%~5"
if not defined BUILD_TOOLCHAIN set "BUILD_TOOLCHAIN=msvc"
if not defined BUILD_JOBS set "BUILD_JOBS=8"
if "%~1"=="" goto parse_done
if /i not "%~1"=="x86" if /i not "%~1"=="x64" goto bad_arch
if /i not "%~2"=="debug" if /i not "%~2"=="release" if /i not "%~2"=="retail" if /i not "%~2"=="clean" goto bad_config
if not "%~4"=="" if /i not "%~4"=="msvc" if /i not "%~4"=="clang" if /i not "%~4"=="gcc" goto bad_toolchain
if not "%~5"=="" if /i not "%~5"=="dll" goto bad_dll
if /i "%~4"=="gcc" goto gcc_build

:parse_done

if not exist "%VSWHERE%" goto no_vswhere

rem Query VS 2026 (18.x) first. Redirect to a temp file instead of using FOR /F
rem around a command, so CMD does not re-parse parentheses in executable paths.
"%VSWHERE%" -latest -products * -version "[18.0,19.0)" -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath > "%VSINSTALL_FILE%" 2>nul
if not exist "%VSINSTALL_FILE%" goto fallback_vs
set /p "VSINSTALL=" < "%VSINSTALL_FILE%"
del /q "%VSINSTALL_FILE%" >nul 2>&1
if defined VSINSTALL goto found_vs

:fallback_vs
if exist "%VSINSTALL_FILE%" del /q "%VSINSTALL_FILE%" >nul 2>&1
echo [VSDevCmd] WARNING: Visual Studio 2026 (18.x) with C++ tools was not found; trying the latest installed Visual Studio.
"%VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath > "%VSINSTALL_FILE%" 2>nul
if not exist "%VSINSTALL_FILE%" goto no_visual_studio
set /p "VSINSTALL=" < "%VSINSTALL_FILE%"
del /q "%VSINSTALL_FILE%" >nul 2>&1
if not defined VSINSTALL goto no_visual_studio

:found_vs
set "VSDEVCMD=%VSINSTALL%\Common7\Tools\VsDevCmd.bat"
if not exist "%VSDEVCMD%" goto no_vsdevcmd

if "%~1"=="" goto interactive

call "%VSDEVCMD%" -arch=%BUILD_ARCH% -host_arch=x64
if not errorlevel 1 goto developer_environment_ready
set "VSDEV_ERROR=%ERRORLEVEL%"
echo [VSDevCmd] ERROR: VsDevCmd.bat failed with exit code %VSDEV_ERROR%.
exit /b %VSDEV_ERROR%

:developer_environment_ready
cd /d "%~dp0..\.."
if errorlevel 1 goto cd_failed

if /i "%BUILD_CONFIG%"=="clean" goto clean
if defined BUILD_DLL goto build_dll

echo [VSDevCmd] Building arch=%BUILD_ARCH% config=%BUILD_CONFIG% toolchain=%BUILD_TOOLCHAIN% jobs=%BUILD_JOBS%
scons arch=%BUILD_ARCH% config=%BUILD_CONFIG% toolchain=%BUILD_TOOLCHAIN% -j%BUILD_JOBS%
set "BUILD_RESULT=%ERRORLEVEL%"
goto build_finished

:build_dll
echo [VSDevCmd] Building arch=%BUILD_ARCH% config=%BUILD_CONFIG% toolchain=%BUILD_TOOLCHAIN% dll=1 jobs=%BUILD_JOBS%
scons arch=%BUILD_ARCH% config=%BUILD_CONFIG% toolchain=%BUILD_TOOLCHAIN% dll=1 -j%BUILD_JOBS%
set "BUILD_RESULT=%ERRORLEVEL%"
goto build_finished

:clean
echo [VSDevCmd] Cleaning build outputs.
scons toolchain=%BUILD_TOOLCHAIN% -c
set "BUILD_RESULT=%ERRORLEVEL%"

:build_finished
set "VSWHERE="
set "VSINSTALL_FILE="
set "VSINSTALL="
set "VSDEVCMD="
set "BUILD_ARCH="
set "BUILD_CONFIG="
set "BUILD_JOBS="
set "BUILD_DLL="
set "BUILD_TOOLCHAIN="
exit /b %BUILD_RESULT%

:gcc_build
cd /d "%~dp0..\.."
if errorlevel 1 goto cd_failed
echo [VSDevCmd] Building arch=%BUILD_ARCH% config=%BUILD_CONFIG% toolchain=gcc jobs=%BUILD_JOBS%
if /i "%BUILD_CONFIG%"=="clean" goto gcc_clean
if defined BUILD_DLL goto gcc_build_dll
scons arch=%BUILD_ARCH% config=%BUILD_CONFIG% toolchain=gcc -j%BUILD_JOBS%
set "BUILD_RESULT=%ERRORLEVEL%"
goto gcc_finished

:gcc_build_dll
scons arch=%BUILD_ARCH% config=%BUILD_CONFIG% toolchain=gcc dll=1 -j%BUILD_JOBS%
set "BUILD_RESULT=%ERRORLEVEL%"
goto gcc_finished

:gcc_clean
echo [VSDevCmd] Cleaning gcc build outputs.
scons toolchain=gcc -c
set "BUILD_RESULT=%ERRORLEVEL%"

:gcc_finished
set "BUILD_ARCH="
set "BUILD_CONFIG="
set "BUILD_JOBS="
set "BUILD_DLL="
set "BUILD_TOOLCHAIN="
exit /b %BUILD_RESULT%

:interactive
call "%VSDEVCMD%" -arch=x64 -host_arch=x64
if errorlevel 1 goto interactive_dev_failed
cd /d "%~dp0..\.."
if errorlevel 1 goto cd_failed
set "VSWHERE="
set "VSINSTALL_FILE="
set "VSINSTALL="
set "VSDEVCMD="
echo [VSDevCmd] Visual Studio developer environment is active. Working directory: %CD%
exit /b 0

:interactive_dev_failed
set "VSDEV_ERROR=%ERRORLEVEL%"
echo [VSDevCmd] ERROR: VsDevCmd.bat failed with exit code %VSDEV_ERROR%.
exit /b %VSDEV_ERROR%

:no_vswhere
echo [VSDevCmd] ERROR: vswhere.exe was not found: "%VSWHERE%"
echo Install or repair Visual Studio Installer, then retry.
exit /b 1

:no_visual_studio
echo [VSDevCmd] ERROR: No Visual Studio installation with the C++ build tools was found.
exit /b 1

:no_vsdevcmd
echo [VSDevCmd] ERROR: VsDevCmd.bat was not found: "%VSDEVCMD%"
exit /b 1

:bad_arch
echo [VSDevCmd] ERROR: Architecture must be x86 or x64. Received: "%~1"
exit /b 2

:bad_config
echo [VSDevCmd] ERROR: Configuration must be debug, release, retail, or clean. Received: "%~2"
exit /b 2

:bad_toolchain
echo [VSDevCmd] ERROR: Toolchain must be msvc, clang, or gcc. Received: "%~4"
exit /b 2

:bad_dll
echo [VSDevCmd] ERROR: The fifth argument must be dll or empty. Received: "%~5"
exit /b 2

:cd_failed
echo [VSDevCmd] ERROR: Could not change directory to the project root.
exit /b 1
