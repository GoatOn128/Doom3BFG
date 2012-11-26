@echo off
set "WORKSPACE=%~dp0.code-workspace"

where code >nul 2>&1
if not errorlevel 1 (
    code --new-window "%WORKSPACE%"
    exit /b %ERRORLEVEL%
)

if exist "%LocalAppData%\Programs\Microsoft VS Code\Code.exe" (
    start "" "%LocalAppData%\Programs\Microsoft VS Code\Code.exe" --new-window "%WORKSPACE%"
    exit /b 0
)
if exist "%ProgramFiles%\Microsoft VS Code\Code.exe" (
    start "" "%ProgramFiles%\Microsoft VS Code\Code.exe" --new-window "%WORKSPACE%"
    exit /b 0
)

echo Could not find the VS Code command-line launcher or Code.exe.
echo Open VS Code and choose File ^> Open Workspace from File..., then select:
echo "%WORKSPACE%"
pause
exit /b 1
