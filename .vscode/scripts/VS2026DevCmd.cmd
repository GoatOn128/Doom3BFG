@echo off
rem Initialize the Visual Studio 2026 (18.x) developer environment.
rem This script deliberately avoids FOR /F ('command') parsing: the default
rem vswhere path contains "Program Files (x86)", whose parentheses can break
rem nested CMD parsing and produce errors such as "C:\Program is not recognized".
rem
rem Usage:
rem   call .\.vscode\scripts\VS2026DevCmd.cmd
rem       Loads the x64 developer environment into the current terminal.
rem   call .\.vscode\scripts\VS2026DevCmd.cmd x86 debug 8
rem       Loads the matching environment and runs SCons.

set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
set "VSINSTALL_FILE=%TEMP%\VSDevCmd_%RANDOM%_%RANDOM%.txt"
set "VSINSTALL="

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

set "BUILD_ARCH=%~1"
set "BUILD_CONFIG=%~2"
set "BUILD_JOBS=%~3"
set "BUILD_HARDLINK=%~4"

if /i not "%BUILD_ARCH%"=="x86" if /i not "%BUILD_ARCH%"=="x64" goto bad_arch
if /i not "%BUILD_CONFIG%"=="debug" if /i not "%BUILD_CONFIG%"=="release" if /i not "%BUILD_CONFIG%"=="clean" goto bad_config
if not defined BUILD_JOBS set "BUILD_JOBS=8"

call "%VSDEVCMD%" -arch=%BUILD_ARCH% -host_arch=x64
if not errorlevel 1 goto developer_environment_ready
set "VSDEV_ERROR=%ERRORLEVEL%"
echo [VSDevCmd] ERROR: VsDevCmd.bat failed with exit code %VSDEV_ERROR%.
exit /b %VSDEV_ERROR%

:developer_environment_ready
cd /d "%~dp0..\.."
if errorlevel 1 goto cd_failed

if /i "%BUILD_CONFIG%"=="clean" goto clean
if defined BUILD_HARDLINK goto build_hardlink

echo [VSDevCmd] Building arch=%BUILD_ARCH% config=%BUILD_CONFIG% jobs=%BUILD_JOBS%
scons arch=%BUILD_ARCH% config=%BUILD_CONFIG% -j%BUILD_JOBS%
set "BUILD_RESULT=%ERRORLEVEL%"
goto build_finished

:build_hardlink
echo [VSDevCmd] Building arch=%BUILD_ARCH% config=%BUILD_CONFIG% hardlink=%BUILD_HARDLINK% jobs=%BUILD_JOBS%
scons arch=%BUILD_ARCH% config=%BUILD_CONFIG% hardlink=%BUILD_HARDLINK% -j%BUILD_JOBS%
set "BUILD_RESULT=%ERRORLEVEL%"
goto build_finished

:clean
echo [VSDevCmd] Cleaning build outputs.
scons -c
set "BUILD_RESULT=%ERRORLEVEL%"

:build_finished
set "VSWHERE="
set "VSINSTALL_FILE="
set "VSINSTALL="
set "VSDEVCMD="
set "BUILD_ARCH="
set "BUILD_CONFIG="
set "BUILD_JOBS="
set "BUILD_HARDLINK="
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
echo [VSDevCmd] ERROR: Architecture must be x86 or x64.
exit /b 2

:bad_config
echo [VSDevCmd] ERROR: Configuration must be debug, release, or clean.
exit /b 2

:cd_failed
echo [VSDevCmd] ERROR: Could not change directory to the project root.
exit /b 1
