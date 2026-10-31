@echo off
setlocal EnableExtensions

set "SCRIPT_DIR=%~dp0"
set "PROJECT_ROOT="

if exist "%SCRIPT_DIR%SConstruct" if exist "%SCRIPT_DIR%.vscode\settings.json" set "PROJECT_ROOT=%SCRIPT_DIR%"

if not defined PROJECT_ROOT if exist "%SCRIPT_DIR%..\SConstruct" if exist "%SCRIPT_DIR%..\.vscode\settings.json" for %%I in ("%SCRIPT_DIR%..") do set "PROJECT_ROOT=%%~fI"

if not defined PROJECT_ROOT if exist "%SCRIPT_DIR%..\..\SConstruct" if exist "%SCRIPT_DIR%..\..\.vscode\settings.json" for %%I in ("%SCRIPT_DIR%..\..") do set "PROJECT_ROOT=%%~fI"

if not defined PROJECT_ROOT (
    echo ERROR: Could not locate the project root.
    echo Put this launcher beside SConstruct,
    echo with the .vscode folder beside it.
    pause
    exit /b 1
)

for %%I in ("%PROJECT_ROOT%") do set "PROJECT_ROOT=%%~fI"

where code >nul 2>&1
if not errorlevel 1 (
    call code --new-window "%PROJECT_ROOT%"
    exit /b %ERRORLEVEL%
)

if exist "%LocalAppData%\Programs\Microsoft VS Code\Code.exe" (
    start "" "%LocalAppData%\Programs\Microsoft VS Code\Code.exe" --new-window "%PROJECT_ROOT%"
    exit /b 0
)
if exist "%ProgramFiles%\Microsoft VS Code\Code.exe" (
    start "" "%ProgramFiles%\Microsoft VS Code\Code.exe" --new-window "%PROJECT_ROOT%"
    exit /b 0
)
if defined ProgramFiles(x86) if exist "%ProgramFiles(x86)%\Microsoft VS Code\Code.exe" (
    start "" "%ProgramFiles(x86)%\Microsoft VS Code\Code.exe" --new-window "%PROJECT_ROOT%"
    exit /b 0
)

exit /b 1
