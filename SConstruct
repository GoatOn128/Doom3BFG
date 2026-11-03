# Doom 3 BFG SCons build
#
# Usage:
#   scons toolchain=msvc arch=x64 config=debug
#   scons toolchain=clang arch=x64 config=debug
#   scons toolchain=gcc arch=x64 config=debug
#   scons arch=x86 config=release
#   scons arch=x64 config=retail dll=1
# Parallel jobs default to up to 16 CPU cores; use -jN or -j1 to override.
#
# Project definitions live in neo/*/SConscript, mirroring the original
# Premake external.lua, idlib.lua, d3xp.lua, and DoomEXE project blocks.
# Outputs follow Premake: bin/Doom3BFG.exe and, for dll=1, bin/gamex86.dll.
# Toolchains: msvc (default) builds with cl.exe/link.exe; clang drives LLVM
# clang-cl/lld-link/llvm-lib over MSVC headers and libraries; gcc uses a
# MinGW-w64 gcc/g++/windres toolchain from PATH.

import atexit
import colorsys
import fnmatch
import os
import platform as pyplatform
import re
import shutil
import subprocess
import sys
import threading
import unicodedata
import uuid
import xml.etree.ElementTree as ET

EnsurePythonVersion(3, 6)

# Parallel builds are enabled by default. Respect an explicit -j/--jobs option,
# including -j1 when the user wants a serial build. Cap the automatic default
# to avoid spawning an excessive number of memory-heavy C++ compiler processes.
def _has_explicit_jobs_option(argv):
    for i, arg in enumerate(argv):
        if arg in ('-j', '--jobs'):
            return True
        if arg.startswith('--jobs=') or (arg.startswith('-j') and arg != '-j'):
            return True
    return False

if not _has_explicit_jobs_option(sys.argv[1:]):
    _cpu_count = os.cpu_count() or 1
    SetOption('num_jobs', min(max(_cpu_count, 1), 16))

# Visual Studio export is a separate SCons goal. Accept both `scons msvc-projects`
# and `scons msvc=1` / `scons generate=msvc`.
MSVS_EXPORT_REQUESTED = (
    ARGUMENTS.get('msvc', '0').lower() in ('1', 'true', 'yes', 'on')
    or ARGUMENTS.get('generate', '').lower() in ('msvc', 'visualstudio', 'visual-studio')
    or 'msvc-projects' in COMMAND_LINE_TARGETS
)
# Keep MSVC console output conventional. ANSI colors, custom diagnostic piping,
# emoji summaries, and the pinned progress footer are reserved for LLVM/GCC builds.
PLAIN_MSVS_OUTPUT = (
    ARGUMENTS.get('toolchain', 'msvc').lower() == 'msvc'
    or MSVS_EXPORT_REQUESTED
)

# Enable ANSI terminal control sequences where supported. On Windows this also
# enables virtual-terminal processing for modern Windows Terminal / consoles.
# NO_COLOR disables styling, but does not disable the uncolored footer progress bar.
def _enable_terminal_ansi():
    try:
        if not sys.stdout.isatty():
            return False
    except Exception:
        return False

    if os.environ.get('TERM', '').lower() == 'dumb':
        return False

    if os.name == 'nt':
        try:
            import ctypes
            kernel32 = ctypes.windll.kernel32
            handle = kernel32.GetStdHandle(-11)  # STD_OUTPUT_HANDLE
            mode = ctypes.c_ulong()
            if not kernel32.GetConsoleMode(handle, ctypes.byref(mode)):
                return False
            # ENABLE_VIRTUAL_TERMINAL_PROCESSING
            if not kernel32.SetConsoleMode(handle, mode.value | 0x0004):
                return False
        except Exception:
            return False
    return True

TERMINAL_TTY = bool(getattr(sys.stdout, 'isatty', lambda: False)())
ANSI_TTY = _enable_terminal_ansi()
USE_COLOR = ANSI_TTY and os.environ.get('NO_COLOR') is None and not PLAIN_MSVS_OUTPUT
# Always reset an ANSI-capable terminal, even if styled output is disabled.
# This prevents an interrupted compiler or a previous command leaving a color
# (often pink/magenta on Windows terminals) active for the user's next prompt.
ANSI_RESET = '\033[0m' if ANSI_TTY else ''
RESET = '\033[0m' if USE_COLOR else ''
WHITE = '\033[97;1m' if USE_COLOR else ''
GRAY = '\033[90m' if USE_COLOR else ''
RED = '\033[91;1m' if USE_COLOR else ''
GREEN = '\033[92;1m' if USE_COLOR else ''
DIM = '\033[90m' if USE_COLOR else ''

# Compiler output is forwarded through a small diagnostic filter. Strip ANSI
# control sequences from child tools so they cannot leave the parent terminal
# in a changed color state. Count conventional GCC/Clang/MSVC diagnostics.
_ANSI_ESCAPE_RE = re.compile(
    r'\x1B(?:\[[0-?]*[ -/]*[@-~]|\][^\x07]*(?:\x07|\x1B\\)|[@-_])'
)
# SGR sequences (colors/bold/underline) are deliberately preserved so Clang's
# warning/error highlighting remains visible. Other terminal-control sequences
# from subprocesses are removed before forwarding output.
_ANSI_SGR_RE = re.compile(r'\x1B\[[0-?]*[ -/]*m')
_WARNING_RE = re.compile(r'\bwarning(?:\s+[A-Za-z]+[0-9]+)?\s*:', re.IGNORECASE)
_ERROR_RE = re.compile(r'\b(?:fatal\s+)?error(?:\s+[A-Za-z]+[0-9]+)?\s*:', re.IGNORECASE)


def _preserve_sgr_strip_other_ansi(text):
    def _replace(match):
        sequence = match.group(0)
        return sequence if _ANSI_SGR_RE.fullmatch(sequence) else ''
    return _ANSI_ESCAPE_RE.sub(_replace, text)

# Normal output is written inside a terminal scrolling region that excludes
# the last row. The progress bar is drawn on that reserved bottom row, so new
# compiler messages scroll above it rather than pushing it down the screen.
if ANSI_TTY:
    CLEAR_LINE = '\r\033[2K'
elif TERMINAL_TTY:
    CLEAR_LINE = '\r' + (' ' * 160) + '\r'
else:
    CLEAR_LINE = ''

def _status_text(label, value):
    # Start and end every SCons status line in the default terminal color.
    return '%s%s%s%s %s\'%s\'%s' % (
        ANSI_RESET, CLEAR_LINE, WHITE, label, GRAY, value,
        ANSI_RESET if ANSI_TTY else RESET
    )



# Progress is shown only for the default build, where the complete default
# target graph is known. Reserve the terminal's last row for the progress bar.
_PROGRESS_ENABLED = (
    ANSI_TTY
    and ARGUMENTS.get('verbose') != '1'
    and not PLAIN_MSVS_OUTPUT
    and not GetOption('no_exec')
    and not GetOption('clean')
    and not COMMAND_LINE_TARGETS
    and not MSVS_EXPORT_REQUESTED
)
_PROGRESS_LOCK = threading.Lock()
_PROGRESS_NODES = {}
_PROGRESS_STATE = {
    'completed': 0,
    'total': 0,
    'started': False,
    'footer_active': False,
    'terminal_height': 0,
    'warnings': 0,
    'errors': 0,
}


def _display_width(text):
    """Return approximate terminal cells occupied by Unicode text."""
    text = _ANSI_ESCAPE_RE.sub('', text)
    width = 0
    for index, char in enumerate(text):
        if char == '\u200d' or unicodedata.combining(char):
            continue
        if char == '\ufe0f':
            continue
        if char == '\ufe0e':
            continue
        next_char = text[index + 1] if index + 1 < len(text) else ''
        emoji_presentation = next_char == '\ufe0f'
        width += 2 if emoji_presentation or unicodedata.east_asian_width(char) in ('W', 'F') else 1
    return width


def _terminal_height():
    try:
        return max(4, shutil.get_terminal_size(fallback=(80, 24)).lines)
    except Exception:
        return 24


def _setup_progress_footer():
    if not _PROGRESS_ENABLED:
        return

    height = _terminal_height()
    _PROGRESS_STATE['terminal_height'] = height
    _PROGRESS_STATE['footer_active'] = True
    # Keep rows 1..height-1 as the scrollable build log and reserve the last
    # terminal row for the progress bar.
    sys.stdout.write(ANSI_RESET + '\033[1;%dr\033[%d;1H' % (height - 1, height - 1) + ANSI_RESET)
    sys.stdout.flush()


def _ensure_progress_footer_size():
    height = _terminal_height()
    old_height = _PROGRESS_STATE['terminal_height']
    if height != old_height:
        # Reapply the scrolling region after a terminal resize.
        sys.stdout.write(ANSI_RESET + '\033[r\033[1;%dr' % (height - 1) + ANSI_RESET)
        _PROGRESS_STATE['terminal_height'] = height


def _draw_progress(done, total, final=False):
    if not _PROGRESS_ENABLED or total <= 0:
        return

    columns = shutil.get_terminal_size(fallback=(80, 24)).columns
    # Preserve room for the right-aligned warning/error counters on narrow consoles.
    width = max(8, min(24, columns - 56))
    ratio = min(1.0, float(done) / float(total))
    filled = int(round(width * ratio))

    # Draw a continuous line rather than block characters. Each cell gets a
    # smoothly interpolated true-color hue along the full bar width, so the
    # completed portion looks like a continuous rainbow gradient.
    bar_parts = []
    for i in range(filled):
        if USE_COLOR:
            hue = float(i) / max(1, width - 1)
            red, green, blue = colorsys.hsv_to_rgb(hue, 0.92, 1.0)
            bar_parts.append('\033[38;2;%d;%d;%dm━' % (
                int(round(red * 255)), int(round(green * 255)), int(round(blue * 255))
            ))
        else:
            bar_parts.append('━')
    if width > filled:
        bar_parts.append(('\033[38;5;238m' if USE_COLOR else '') + '─' * (width - filled))
    bar = ''.join(bar_parts) + (ANSI_RESET if ANSI_TTY else '')

    left = '📊 Build [%s] %3d%% (%d/%d actions)' % (
        bar, int(round(ratio * 100)), done, total
    )
    warning_count = _PROGRESS_STATE['warnings']
    error_count = _PROGRESS_STATE['errors']
    if USE_COLOR:
        right = '\033[38;5;214m⚠️ %d%s  \033[38;5;196m❌ %d%s' % (
            warning_count, ANSI_RESET, error_count, ANSI_RESET
        )
    else:
        right = '⚠️ %d  ❌ %d' % (warning_count, error_count)
    padding = max(2, columns - _display_width(left) - _display_width(right))
    line = left + (' ' * padding) + right

    if _PROGRESS_STATE['footer_active']:
        _ensure_progress_footer_size()
        height = _PROGRESS_STATE['terminal_height']
        # Reset before and after drawing so the footer never leaks color state.
        sys.stdout.write(
            ANSI_RESET + '\033[%d;1H\033[2K%s%s\033[%d;1H' % (
                height, line, ANSI_RESET, height - 1
            )
        )
    else:
        # Fallback for very unusual terminals where no footer could be set up.
        sys.stdout.write(ANSI_RESET + CLEAR_LINE + line + ANSI_RESET + ('\n' if final else ''))
    sys.stdout.flush()


def _cleanup_progress_footer():
    if not _PROGRESS_STATE['footer_active']:
        return

    height = _terminal_height()
    # Erase the pinned bar, restore normal terminal scrolling, and leave the
    # cursor on a clean line so the final success/failure report is readable.
    sys.stdout.write(
        ANSI_RESET + '\033[%d;1H\033[2K\033[r\033[%d;1H\033[2K\033[%d;1H' % (
            height, max(1, height - 1), max(1, height - 1)
        ) + ANSI_RESET
    )
    sys.stdout.flush()
    _PROGRESS_STATE['footer_active'] = False


def _progress_post_action(target, source, env):
    if not _PROGRESS_ENABLED:
        return
    with _PROGRESS_LOCK:
        _PROGRESS_STATE['completed'] += 1
        _PROGRESS_STATE['started'] = True
        _draw_progress(
            _PROGRESS_STATE['completed'], _PROGRESS_STATE['total']
        )


# A raw Python function passed directly to AddPostAction is displayed by SCons
# as `_progress_post_action([...], [...])`. Wrap it in an Action whose display
# string is empty; the callback still executes after each built node.
_PROGRESS_ACTION = Action(
    _progress_post_action,
    strfunction=lambda target, source, env, executor=None: '',
)


def _diagnostic_spawn(sh, escape, cmd, args, child_env):
    """Run a command, relay its output, count diagnostics, and strip ANSI colors.

    This mirrors SCons' platform spawn command construction while capturing
    output line-by-line. Combining stdout/stderr keeps parallel compiler output
    readable and lets warnings/errors update the pinned progress footer live.
    """
    if os.name == 'nt':
        if not sh:
            sys.stderr.write('scons: Could not find command interpreter in PATH.\n')
            return 127
        # Do not pass escape(' '.join(args)) here. SCons' Windows escape()
        # wraps the *entire* command line in quotes; with already-quoted source
        # paths, cmd.exe can then interpret the whole string as the executable
        # name (for example: \"clang-cl ... \"src\file.c\" ...\").
        # Pass cmd.exe a raw Windows command line instead, quoting only the
        # interpreter path if necessary. The command arguments produced by
        # SCons already contain the required quoting for paths and flags.
        command = subprocess.list2cmdline([sh]) + ' /C ' + ' '.join(args)
    else:
        if not sh:
            sh = '/bin/sh'
        command = [sh, '-c', ' '.join(args)]

    try:
        process = subprocess.Popen(
            command,
            env=child_env,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            universal_newlines=True,
            errors='replace',
            bufsize=1,
        )
        if process.stdout is not None:
            for raw_line in process.stdout:
                # Count diagnostics using plain text, but forward Clang's SGR
                # sequences to keep colored warning/error highlighting. Reset at
                # each line boundary so no compiler color leaks into SCons or the
                # shell prompt after the build.
                plain_line = _ANSI_ESCAPE_RE.sub('', raw_line)
                display_line = _preserve_sgr_strip_other_ansi(raw_line)
                warnings = len(_WARNING_RE.findall(plain_line))
                errors = len(_ERROR_RE.findall(plain_line))
                with _PROGRESS_LOCK:
                    _PROGRESS_STATE['warnings'] += warnings
                    _PROGRESS_STATE['errors'] += errors
                    sys.stdout.write(ANSI_RESET + display_line + ANSI_RESET)
                    sys.stdout.flush()
                    if (warnings or errors) and _PROGRESS_ENABLED:
                        _draw_progress(
                            _PROGRESS_STATE['completed'],
                            _PROGRESS_STATE['total'],
                        )
        return process.wait()
    except OSError as exc:
        message = 'scons: %s: %s\n' % (cmd, exc)
        with _PROGRESS_LOCK:
            sys.stderr.write(ANSI_RESET + message + ANSI_RESET)
            sys.stderr.flush()
        return getattr(exc, 'errno', None) or 127


def _track_progress(env, nodes):
    if nodes is None:
        return nodes
    try:
        node_list = list(nodes)
    except TypeError:
        node_list = [nodes]
    for node in node_list:
        key = str(node)
        if key in _PROGRESS_NODES:
            continue
        _PROGRESS_NODES[key] = node
        if _PROGRESS_ENABLED:
            env.AddPostAction(node, _PROGRESS_ACTION)
    return nodes

def _report_build_result():
    if PLAIN_MSVS_OUTPUT:
        _cleanup_progress_footer()
        if ANSI_TTY:
            try:
                sys.stdout.write(ANSI_RESET + '\033[r')
                sys.stdout.flush()
            except Exception:
                pass
        return
    try:
        from SCons.Script import GetBuildFailures
        failures = GetBuildFailures()
    except Exception:
        _cleanup_progress_footer()
        if ANSI_TTY:
            try:
                sys.stdout.write(ANSI_RESET + '\033[r')
                sys.stdout.flush()
            except Exception:
                pass
        return

    warnings = _PROGRESS_STATE['warnings']
    errors = _PROGRESS_STATE['errors']
    if failures:
        _cleanup_progress_footer()
        for failure in failures:
            node = getattr(failure, 'node', None)
            path = str(node) if node is not None else 'unknown target'
            errstr = str(getattr(failure, 'errstr', '') or '').strip()
            suffix = os.path.splitext(path)[1].lower()
            if suffix in ('.o', '.obj'):
                icon, stage = '🛠️', 'Compilation'
            elif suffix in ('.dll', '.so', '.dylib', '.exe'):
                icon, stage = '🔗', 'Linking'
            elif suffix in ('.a', '.lib'):
                icon, stage = '📦', 'Archiving'
            elif suffix == '.res':
                icon, stage = '🖼️', 'Resource compilation'
            elif path.endswith(('g_funcs.h', 'g_func_decs.h')):
                icon, stage = '🧬', 'Code generation'
            else:
                icon, stage = '⚙️', 'Build step'

            detail = ' — ' + errstr if errstr else ''
            print('%s❌ %s %s failed: %s\'%s\'%s%s' % (
                RED, icon, stage, GRAY, path, RESET, detail
            ), file=sys.stderr)
        # Some linkers only return a nonzero exit status without an `error:` line.
        shown_errors = max(errors, len(failures))
        print('%s📊 Diagnostics: ⚠️ %d warning(s), ❌ %d error(s)%s' % (
            RED, warnings, shown_errors, RESET
        ), file=sys.stderr)
        if ANSI_TTY:
            try:
                sys.stdout.write(ANSI_RESET)
                sys.stderr.write(ANSI_RESET)
                sys.stdout.flush()
                sys.stderr.flush()
            except Exception:
                pass
        return

    if _PROGRESS_ENABLED and _PROGRESS_STATE['started']:
        total = _PROGRESS_STATE['total']
        done = _PROGRESS_STATE['completed']
        _draw_progress(total, total, final=True)
        _cleanup_progress_footer()
        skipped = max(0, total - done)
        print('%s✅ Build complete%s — %d action(s) rebuilt; %d up-to-date/skipped.  ⚠️ %d  ❌ %d' % (
            GREEN, RESET, done, skipped, warnings, errors
        ))
    else:
        # Even an up-to-date build must restore the terminal's scroll region.
        _cleanup_progress_footer()
        if warnings or errors:
            print('%s📊 Diagnostics: ⚠️ %d warning(s), ❌ %d error(s)%s' % (
                GREEN if not errors else RED, warnings, errors, RESET
            ))
    # Make sure the shell prompt always starts in its default terminal color.
    if ANSI_TTY:
        try:
            sys.stdout.write(ANSI_RESET)
            sys.stdout.flush()
        except Exception:
            pass


atexit.register(_report_build_result)

# -----------------------------------------------------------------------------
# Project options and platform validation
# -----------------------------------------------------------------------------
ARCH = ARGUMENTS.get('arch', 'x64').lower()
CONFIG = ARGUMENTS.get('config', 'debug').lower()
TOOLCHAIN = ARGUMENTS.get('toolchain', 'msvc').lower()
DLL_BUILD = ARGUMENTS.get('dll', '0').lower() in ('1', 'true', 'yes', 'on')
DEDICATED = ARGUMENTS.get('dedicated', '0').lower() in ('1', 'true', 'yes', 'on')

if ARCH not in ('x86', 'x64'):
    print("arch must be x86 or x64 (received %r)" % ARCH, file=sys.stderr)
    Exit(2)
if CONFIG not in ('debug', 'release', 'retail'):
    print("config must be debug, release, or retail (received %r)" % CONFIG, file=sys.stderr)
    Exit(2)
if TOOLCHAIN not in ('msvc', 'clang', 'gcc'):
    print("toolchain must be msvc, clang, or gcc (received %r)" % TOOLCHAIN, file=sys.stderr)
    Exit(2)

HOST_PLATFORM = pyplatform.system()
if HOST_PLATFORM != 'Windows':
    print(
        "This SConstruct currently supports Windows only. The supplied Premake "
        "configuration defines Windows compiler/linker settings but no Linux "
        "platform configuration.",
        file=sys.stderr,
    )
    Exit(2)

# The Premake file declares --dedicated but does not consume that option anywhere.
# Do not guess a dedicated-server source set or subsystem here.
if DEDICATED:
    print("WARNING: dedicated=1 was declared in Premake but has no implementation "
          "in the supplied Premake scripts; it is currently ignored.", file=sys.stderr)

# Paths used by every SConscript. Anchor everything to this file's location
# so the build works no matter which directory scons is invoked from. Source
# roots live under neo/, mirroring the original Premake layout. Some SCons
# versions execute the top-level SConstruct without defining __file__; fall
# back to the working directory, which every supported entry point (the VS
# Code build script, CI, a manual scons call) sets to the repository root.
if '__file__' in globals():
    SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
else:
    SCRIPT_DIR = os.getcwd()
if not os.path.isfile(os.path.join(SCRIPT_DIR, 'SConstruct')):
    print(
        "ERROR: SConstruct was not found in %s. Run scons from the repository "
        "root." % SCRIPT_DIR, file=sys.stderr)
    Exit(2)
PROJECT_ROOT = os.path.abspath(os.path.join(SCRIPT_DIR, 'neo'))
BUILD_ROOT = os.path.abspath(os.path.join(
    SCRIPT_DIR, 'build', 'scons', 'windows-%s-%s-%s' % (ARCH, CONFIG, TOOLCHAIN)))
OBJECT_ROOT = os.path.join(BUILD_ROOT, 'obj')
LIB_ROOT = os.path.join(BUILD_ROOT, 'lib')
BIN_DIR = os.path.abspath(os.path.join(SCRIPT_DIR, 'bin'))
CACHE_ROOT = os.path.abspath(os.path.join(SCRIPT_DIR, '.scons_cache'))

os.makedirs(OBJECT_ROOT, exist_ok=True)
os.makedirs(LIB_ROOT, exist_ok=True)
os.makedirs(BIN_DIR, exist_ok=True)

Help('''
Doom 3 BFG SCons build

Usage:
  scons [arch=x86|x64] [config=debug|release|retail] [toolchain=msvc|clang|gcc] [dll=1] [-jN]
  scons arch=x64 config=debug                 Build all projects
  scons libs                                  Build the "libs" group
  scons exes                                  Build the "exes" group
  scons external                              Build only the external project
  scons idLib                                 Build only the idLib project
  scons Game-D3XP                             Build only the game code
  scons DoomEXE                               Build the engine code
  scons ConvertIdTech3Assets                  Build only the id Tech 3 asset converter
  scons arch=x64 config=debug dll=1 dll       Build the "dll" group
  scons msvc-projects                         Generate/update Visual Studio files when build scripts change
  scons msvc=1                                Same as msvc-projects (generation only)

Project selection (mirrors Premake groups):
  libs               external + idLib + Game-D3XP static library (when dll=0)
  exes               DoomEXE / ConvertIdTech3Assets executables
  dll                Game-D3XP / bin/gamex86.dll (only when dll=1)
  external           Individual external static-library project
  idLib              Individual idLib static-library project
  Game-D3XP          Individual game project; .lib or .dll depending on dll=1
  DoomEXE            Individual executable project
  all                All projects

Options:
  arch=x86|x64       Target architecture (default: x64)
  toolchain=msvc     MSVC cl.exe/link.exe/lib.exe (default)
  toolchain=clang    LLVM clang-cl/lld-link/llvm-lib over MSVC headers and libs
  toolchain=gcc      MinGW-w64 gcc/g++/windres taken from PATH
  config=debug       Debug symbols, no optimization, static debug CRT
  config=release     Optimized release build
  config=retail      Optimized retail build with ID_RETAIL and no debug symbols
  dll=1              Put Game-D3XP in the "dll" group and build gamex86.dll
  dedicated=1        Dedicate server build
  verbose=1          Show full compiler/linker command lines
  msvc_version=14.5  Visual Studio toolset version for export (14.5 = VS 2026)
  -jN                Number of parallel jobs; defaults to min(CPU count, 16)

Project definitions:
  neo/external/SConscript
  neo/idLib/SConscript
  neo/Game-D3XP/SConscript
  neo/DoomEXE/SConscript
  neo/tools/convertidtech3assets/SConscript

Build products:
  bin/Doom3BFG.exe
  bin/gamex86.dll    (dll=1 only)
  build/scons/windows-<arch>-<config>-<toolchain>/lib/*
''')

# -----------------------------------------------------------------------------
# Source discovery
# -----------------------------------------------------------------------------
SOURCE_EXTENSIONS = ('.c', '.cc', '.cpp', '.cxx', '.rc')


def _relative(path):
    return os.path.normpath(path).replace('\\', '/')


def collect_sources(root_dirs, excludes=None):
    '''Collect compilable files recursively, matching Premake's directory globs.'''
    excludes = excludes or []
    found = []
    for root in root_dirs:
        root_path = root if os.path.isabs(root) else os.path.join(PROJECT_ROOT, root)
        if not os.path.isdir(root_path):
            print("ERROR: required source directory is missing: %s" % root_path, file=sys.stderr)
            Exit(2)
        for current, dirs, files in os.walk(root_path):
            dirs[:] = sorted(d for d in dirs if d not in ('.git', '.vs', '__pycache__', 'build', 'bin'))
            for filename in sorted(files):
                if os.path.splitext(filename)[1].lower() not in SOURCE_EXTENSIONS:
                    continue
                absolute_path = os.path.join(current, filename)
                path = _relative(os.path.relpath(absolute_path, PROJECT_ROOT))
                if any(fnmatch.fnmatch(path, pattern) for pattern in excludes):
                    continue
                found.append(path)
    return sorted(set(found), key=lambda p: p.lower())


def require_sources(label, sources):
    if not sources:
        print("ERROR: no compilable source files found for %s." % label, file=sys.stderr)
        Exit(2)
    return sources


# -----------------------------------------------------------------------------
# Toolchain selection
# -----------------------------------------------------------------------------
# msvc (default): cl.exe / link.exe / lib.exe / rc.exe from the MSVC environment.
# clang: LLVM clang-cl / lld-link / llvm-lib over MSVC headers and libraries.
# gcc: a MinGW-w64 gcc / g++ / windres toolchain from PATH.
if TOOLCHAIN == 'clang':
    LLVM_BIN = ARGUMENTS.get('llvm_bin', os.environ.get('LLVM_BIN', r'C:\Program Files\LLVM\bin'))


    def find_tool(name, fallback=None):
        executable = name if name.lower().endswith('.exe') else name + '.exe'
        candidate = os.path.join(LLVM_BIN, executable)
        if os.path.isfile(candidate):
            return candidate
        located = shutil.which(name) or shutil.which(executable)
        if located:
            return located
        return fallback or name


    CLANG_CL = ARGUMENTS.get('cc', find_tool('clang-cl'))
    LLD_LINK = ARGUMENTS.get('linker', find_tool('lld-link'))
    LLVM_LIB = ARGUMENTS.get('ar', find_tool('llvm-lib'))
    LLVM_RC = ARGUMENTS.get('rc', find_tool('llvm-rc', shutil.which('rc') or 'rc'))

    if CLANG_CL == 'clang-cl' and not shutil.which(CLANG_CL):
        print("ERROR: clang-cl was not found. Install LLVM or pass llvm_bin=<LLVM bin directory>.", file=sys.stderr)
        Exit(2)
    if LLD_LINK == 'lld-link' and not shutil.which(LLD_LINK):
        print("ERROR: lld-link was not found. Install LLVM or pass linker=<path>.", file=sys.stderr)
        Exit(2)
    if LLVM_LIB == 'llvm-lib' and not shutil.which(LLVM_LIB):
        print("ERROR: llvm-lib was not found. Install LLVM or pass ar=<path>.", file=sys.stderr)
        Exit(2)
elif TOOLCHAIN == 'gcc':
    for required_tool in ('gcc', 'g++', 'windres'):
        if not shutil.which(required_tool):
            print("ERROR: %s was not found on PATH. toolchain=gcc needs a MinGW-w64 toolchain (for example from MSYS2)." % required_tool, file=sys.stderr)
            Exit(2)

TARGET_ARCH = 'x86' if ARCH == 'x86' else 'amd64'
MACHINE_FLAG = '/MACHINE:X86' if ARCH == 'x86' else '/MACHINE:X64'
ARCH_FLAG = '-m32' if ARCH == 'x86' else '-m64'

# Link flag sets consumed by the SConscript files. MSVC and clang share the
# Microsoft linker switches; gcc needs the GNU equivalents.
if TOOLCHAIN == 'gcc':
    GUI_LINKFLAGS = ['-mwindows', '-Wl,--stack=16777216', '-Wl,--large-address-aware']
    DLL_LINKFLAGS = ['-Wl,--large-address-aware']
else:
    GUI_LINKFLAGS = [
        MACHINE_FLAG,
        '/SUBSYSTEM:WINDOWS',
        '/STACK:16777216,16777216',
        '/LARGEADDRESSAWARE',
    ]
    DLL_LINKFLAGS = [MACHINE_FLAG, '/LARGEADDRESSAWARE', '/MANIFEST:NO']

base_defines = [
    '__DOOM__',
    'ID_PC',
    '_CRT_SECURE_NO_DEPRECATE',
    '_CRT_NONSTDC_NO_DEPRECATE',
]
if ARCH == 'x86':
    base_defines.append('_USE_32BIT_TIME_T')
if DLL_BUILD:
    base_defines.append('__DOOM_DLL__')

base_cpppath = [
    PROJECT_ROOT,
    os.path.join(PROJECT_ROOT, 'external'),
    os.path.join(PROJECT_ROOT, 'idlib'),
    os.path.join(PROJECT_ROOT, 'external/miniz'),
    os.path.join(PROJECT_ROOT, 'external/minizip'),
    os.path.join(PROJECT_ROOT, 'external/libbinkdec/include'),
    os.path.join(PROJECT_ROOT, 'external/glad/include'),
]

# Toolchain environments: MSVC uses cl.exe/link.exe/lib.exe directly, clang
# keeps SCons' Microsoft builders but drives them with the LLVM tools, and
# gcc uses the MinGW builders (gcc/g++/windres) from PATH.
if TOOLCHAIN == 'gcc':
    env = Environment(
        tools=['mingw'],
        ENV=os.environ.copy(),
        TARGET_ARCH=TARGET_ARCH,
        CPPPATH=base_cpppath,
    )
    env.Replace(
        PROGSUFFIX='.exe',
        SHLIBPREFIX='',
        SHLIBSUFFIX='.dll',
        LIBPREFIX='',
        LIBSUFFIX='.a',
        OBJSUFFIX='.o',
    )
    env.Append(CPPDEFINES=base_defines)
    env.Append(CCFLAGS=['-Wall', '-Wextra', ARCH_FLAG, '-fstack-protector'])
    env.Append(CXXFLAGS=['-Wall', '-Wextra', ARCH_FLAG, '-fstack-protector', '-std=c++17'])
    # Match the MSVC static-CRT behavior: link the GCC runtime statically
    # so the exe and dll do not depend on libgcc/libstdc++ DLLs.
    env.Append(LINKFLAGS=['-static-libgcc', '-static-libstdc++'])
    env.Append(SHLINKFLAGS=['-static-libgcc', '-static-libstdc++'])
elif TOOLCHAIN == 'clang':
    env = Environment(
        tools=['default', 'mslink'],
        ENV=os.environ.copy(),
        CC=CLANG_CL,
        CXX=CLANG_CL,
        LINK=LLD_LINK,
        SHLINK=LLD_LINK,
        AR=LLVM_LIB,
        RC=LLVM_RC,
        TARGET_ARCH=TARGET_ARCH,
        CPPPATH=base_cpppath,
    )
    env.Replace(
        PROGSUFFIX='.exe',
        SHLIBPREFIX='',
        SHLIBSUFFIX='.dll',
        LIBPREFIX='',
        LIBSUFFIX='.lib',
        OBJSUFFIX='.obj',
        ARFLAGS=['/nologo', '/OUT:$TARGET'],
    )
    env.Append(CPPDEFINES=base_defines)
    env.Append(CCFLAGS=['/W4', '/nologo', ARCH_FLAG, '/GS'])
    env.Append(CXXFLAGS=['/W4', '/nologo', ARCH_FLAG, '/GS', '/std:c++17', '/EHsc', '/GR'])
else:  # msvc
    env = Environment(
        tools=['default', 'mslink'],
        ENV=os.environ.copy(),
        TARGET_ARCH=TARGET_ARCH,
        CPPPATH=base_cpppath,
    )
    env.Replace(
        PROGSUFFIX='.exe',
        SHLIBPREFIX='',
        SHLIBSUFFIX='.dll',
        LIBPREFIX='',
        LIBSUFFIX='.lib',
        OBJSUFFIX='.obj',
    )
    env.Append(CPPDEFINES=base_defines)
    env.Append(CCFLAGS=['/W4', '/nologo', '/GS'])
    env.Append(CXXFLAGS=['/W4', '/nologo', '/GS', '/std:c++17', '/EHsc', '/GR'])

# Premake staticruntime("On") maps to /MTd for Debug and /MT for the Microsoft
# toolchains. GCC has no CRT switch; its runtime is linked statically in the
# environment above, so only optimization and debug levels differ here.
# MSVC debug uses /Zi so the Visual Studio debugger gets a PDB; clang-cl
# keeps /Z7 for the same purpose.
if TOOLCHAIN == 'gcc':
    debug_ccflags = ['-O0', '-g']
    release_ccflags = ['-O2']
elif TOOLCHAIN == 'clang':
    debug_ccflags = ['/MTd', '/Z7', '/Od']
    release_ccflags = ['/MT', '/O2', '/Ob2', '/Gy', '/GF', '/Oi']
else:
    # /Zi writes a shared compiler PDB. Give it a per-build path with /Fd
    # so parallel cl.exe processes stop dropping vc140.pdb at the repo
    # root (fatal error C1090 when two compilers race on it), and use /FS
    # to serialize PDB writes through mspdbsrv.
    debug_ccflags = ['/MTd', '/Zi', '/FS', '/Od',
                     '/Fd' + os.path.join(OBJECT_ROOT, 'msvc-compiler.pdb')]
    release_ccflags = ['/MT', '/O2', '/Ob2', '/Gy', '/GF', '/Oi']

if CONFIG == 'debug':
    env.Append(CCFLAGS=debug_ccflags)
    env.Append(CXXFLAGS=debug_ccflags)
    env.Append(CPPDEFINES=['_DEBUG'])
    if TOOLCHAIN != 'gcc':
        env.Append(LINKFLAGS=['/DEBUG', '/MAP'])
        env.Append(SHLINKFLAGS=['/DEBUG', '/MAP'])
elif CONFIG == 'release':
    env.Append(CCFLAGS=release_ccflags)
    env.Append(CXXFLAGS=release_ccflags)
    env.Append(CPPDEFINES=['NDEBUG'])
    if TOOLCHAIN != 'gcc':
        env.Append(LINKFLAGS=['/OPT:REF', '/OPT:ICF'])
        env.Append(SHLINKFLAGS=['/OPT:REF', '/OPT:ICF'])
else:  # retail
    env.Append(CCFLAGS=release_ccflags)
    env.Append(CXXFLAGS=release_ccflags)
    env.Append(CPPDEFINES=['NDEBUG', 'ID_RETAIL'])
    if TOOLCHAIN != 'gcc':
        env.Append(LINKFLAGS=['/OPT:REF', '/OPT:ICF'])
        env.Append(SHLINKFLAGS=['/OPT:REF', '/OPT:ICF'])

# Keep stack protection enabled in every configuration. The supplied Premake
# disables /GS for Release, but this SCons port intentionally avoids weakening
# the check (particularly useful while investigating the reported stack-cookie
# failure). clang-cl emits CodeView symbols with /Z7; /ZI Edit-and-Continue and
# /RTC1 are MSVC-only features and are not passed to clang-cl.

# The Premake helpers set /LTCG:incremental even when LTO is enabled. That is an
# MSVC linker switch, not LLVM LTO. Do not pass it to lld-link; use /OPT:REF and
# /OPT:ICF for the equivalent dead-code / identical COMDAT optimizations.

if USE_COLOR:
    if TOOLCHAIN == 'clang':
        env.Append(CCFLAGS=['/clang:-fcolor-diagnostics'], CXXFLAGS=['/clang:-fcolor-diagnostics'])
    elif TOOLCHAIN == 'gcc':
        env.Append(CCFLAGS=['-fdiagnostics-color=always'], CXXFLAGS=['-fdiagnostics-color=always'])

# /FC makes compiler diagnostics use full paths. This is especially useful
# because exported Visual Studio project files live in build/msvc/ rather than
# beside SConstruct.
if TOOLCHAIN in ('msvc', 'clang'):
    env.Append(CCFLAGS=['/FC'], CXXFLAGS=['/FC'])

# Output policy by toolchain:
# - MSVC: retain concise, non-verbose filenames/targets only. Do not emit
#   custom Compiling/Linking labels, ANSI colors, emoji, or a progress footer;
#   Visual Studio's Output window should receive plain text and native cl/link
#   diagnostics. SCons' native SPAWN is left untouched.
# - Clang/GCC: retain the richer terminal output and diagnostic forwarding.
if TOOLCHAIN == 'msvc':
    if ARGUMENTS.get('verbose') != '1':
        # Do not echo compiler source names from SCons here. cl.exe already
        # prints the source basename itself; echoing $SOURCE as well produces
        # duplicate lines in Visual Studio's Output window (for example both
        # "neo\ui\GuiScript.cpp" and "GuiScript.cpp"). An empty COMSTR
        # suppresses only SCons' command echo; native cl.exe diagnostics and
        # its concise source-name output remain visible. Keep target messages
        # for link/archive steps, whose tools are otherwise quiet on success.
        env['CCCOMSTR'] = ''
        env['CXXCOMSTR'] = ''
        env['SHCCCOMSTR'] = ''
        env['SHCXXCOMSTR'] = ''
        env['LINKCOMSTR'] = '$TARGET'
        env['SHLINKCOMSTR'] = '$TARGET'
        env['ARCOMSTR'] = '$TARGET'
        env['RANLIBCOMSTR'] = '$TARGET'
        env['RCCOMSTR'] = '$SOURCE'
        env['ASCOMSTR'] = '$SOURCE'
elif not MSVS_EXPORT_REQUESTED:
    env['SPAWN'] = _diagnostic_spawn
    if ARGUMENTS.get('verbose') != '1':
        env['CCCOMSTR'] = _status_text('Compiling', '$SOURCE')
        env['CXXCOMSTR'] = _status_text('Compiling', '$SOURCE')
        env['SHCCCOMSTR'] = _status_text('Compiling', '$SOURCE')
        env['SHCXXCOMSTR'] = _status_text('Compiling', '$SOURCE')
        env['LINKCOMSTR'] = _status_text('Linking', '$TARGET')
        env['SHLINKCOMSTR'] = _status_text('Linking', '$TARGET')
        env['ARCOMSTR'] = _status_text('Archiving', '$TARGET')
        env['RANLIBCOMSTR'] = _status_text('Indexing', '$TARGET')
        env['RCCOMSTR'] = _status_text('Resources', '$SOURCE')

# SCons cache. Outputs remain separated by configuration/architecture.
env.CacheDir(CACHE_ROOT)


def build_objects(build_env, project_name, sources):
    '''Compile project sources into an isolated object directory.'''
    objects = []
    for source in sources:
        source = _relative(source)
        rel = source
        # Sources are relative to neo/: resolve them to full paths so the
        # build does not depend on the invocation directory.
        source = os.path.join(PROJECT_ROOT, source)
        target = os.path.join(OBJECT_ROOT, project_name, rel + build_env['OBJSUFFIX'])
        built = build_env.Object(target, source)
        objects.extend(built)
    _track_progress(build_env, objects)
    return objects


def build_static_library(project_name, sources, project_env=None):
    project_env = project_env or env
    objects = build_objects(project_env, project_name, sources)
    target_base = os.path.join(LIB_ROOT, project_name)
    nodes = project_env.StaticLibrary(target_base, objects)
    _track_progress(project_env, nodes)
    return nodes[0], objects

# -----------------------------------------------------------------------------
# Premake-style project definitions are kept in individual SConscript files.
# Each file owns its source selection, per-project defines, compiler settings,
# and output target, just as external.lua / idlib.lua / d3xp.lua did in Premake.
# -----------------------------------------------------------------------------
Export(
    'env', 'build_objects', 'build_static_library', 'collect_sources',
    'require_sources', 'PROJECT_ROOT', 'OBJECT_ROOT', 'LIB_ROOT', 'BIN_DIR',
    'DLL_BUILD', 'ARCH', 'CONFIG', 'TOOLCHAIN', 'GUI_LINKFLAGS',
    'DLL_LINKFLAGS', '_track_progress',
)

# The dependency order is intentional: project scripts consume previously
# constructed library nodes through SCons' exported construction environment.
external_lib = SConscript(os.path.join(SCRIPT_DIR, 'neo/external/SConscript'), chdir=0)
Export('external_lib')

idlib_lib = SConscript(os.path.join(SCRIPT_DIR, 'neo/idLib/SConscript'), chdir=0)
Export('idlib_lib')

if DLL_BUILD:
    game_target = SConscript(os.path.join(SCRIPT_DIR, 'neo/d3xp/SConscript'), chdir=0)
    game_static_lib = None
else:
    game_target = SConscript(os.path.join(SCRIPT_DIR, 'neo/d3xp/SConscript'), chdir=0)
    game_static_lib = game_target
Export('game_target', 'game_static_lib')

doom_target = SConscript(os.path.join(SCRIPT_DIR, 'neo/SConscript'), chdir=0)

# Standalone CLI tools that host the engine framework through sys/stub.
convertidtech3assets_target = SConscript(os.path.join(SCRIPT_DIR, 'neo/tools/convertidtech3assets/SConscript'), chdir=0)

# -----------------------------------------------------------------------------
# Premake-style project targets and groups
# -----------------------------------------------------------------------------
# SCons aliases reproduce Premake's named neo/groups. Each project is
# independently selectable, and dependency edges build the required libraries.
external_project = Alias('external', external_lib)
idlib_project = Alias('idLib', idlib_lib)
game_project = Alias('Game-D3XP', game_target)
doom_project = Alias('DoomEXE', doom_target)
convertidtech3assets_project = Alias('ConvertIdTech3Assets', convertidtech3assets_target)
Alias('Doom3BFG', doom_target)

libs_members = [external_project, idlib_project]
if not DLL_BUILD:
    libs_members.append(game_project)
libs_group = Alias('libs', libs_members)
exes_group = Alias('exes', [doom_project, convertidtech3assets_project])
all_members = [libs_group, exes_group]
if DLL_BUILD:
    dll_group = Alias('dll', [game_project])
    all_members.append(dll_group)
all_group = Alias('all', all_members)

Default(all_group)

# -----------------------------------------------------------------------------
# Optional Visual Studio solution/project export
# -----------------------------------------------------------------------------
# SCons' MSVSProject builder generates MSBuild-compatible .vcxproj files whose
# Build/Clean/Rebuild commands call back into SCons. This keeps SCons as the
# authoritative build system; Visual Studio is the IDE/debugger front-end.
#
# Output layout:
#   build/msvc/Doom3BFG.sln
#   build/msvc/DoomEXE.vcxproj[.filters]
#   build/msvc/external.vcxproj[.filters]
#   build/msvc/idLib.vcxproj[.filters]
#   build/msvc/Game-D3XP.vcxproj[.filters]
#
# Each generated project exposes Debug/Release/Retail for Win32 and x64.


def _collect_msvs_files(root_dirs, excludes=None):
    """Return (sources, headers, resources, misc) for a Premake-style project."""
    excludes = excludes or []
    source_exts = ('.c', '.cc', '.cpp', '.cxx', '.asm', '.s', '.S')
    header_exts = ('.h', '.hh', '.hpp', '.hxx', '.inl', '.ipp', '.inc', '.def')
    resource_exts = ('.rc',)
    sources, headers, resources, misc = [], [], [], []
    for root in root_dirs:
        root_path = root if os.path.isabs(root) else os.path.join(PROJECT_ROOT, root)
        if not os.path.isdir(root_path):
            print("ERROR: cannot export MSVC project; source directory is missing: %s" % root_path,
                  file=sys.stderr)
            Exit(2)
        for current, dirs, filenames in os.walk(root_path):
            dirs[:] = sorted(d for d in dirs if d not in ('.git', '.vs', '__pycache__', 'build', 'bin'))
            for filename in sorted(filenames):
                absolute = os.path.join(current, filename)
                relative = _relative(os.path.relpath(absolute, PROJECT_ROOT))
                if any(fnmatch.fnmatch(relative.lower(), pattern.lower()) for pattern in excludes):
                    continue
                ext = os.path.splitext(filename)[1]
                if ext in source_exts:
                    sources.append(relative)
                elif ext.lower() in header_exts:
                    headers.append(relative)
                elif ext.lower() in resource_exts:
                    resources.append(relative)
                elif ext.lower() in ('.lua', '.txt', '.md', '.def', '.rc2', '.manifest'):
                    misc.append(relative)
    key = lambda value: value.lower()
    return tuple(sorted(set(items), key=key) for items in (sources, headers, resources, misc))


def _msvs_relative_to_project(path, msvs_dir):
    """MSBuild interprets source/include paths relative to the .vcxproj folder."""
    absolute = path if os.path.isabs(path) else os.path.join(PROJECT_ROOT, path)
    return os.path.normpath(os.path.relpath(os.path.abspath(absolute), msvs_dir))


def _make_directory_filters_action(project_root, project_dir, project_name):
    """Replace SCons' type-based filters with the real source directory tree.

    SCons' MSVSProject builder creates synthetic roots such as Source Files,
    Header Files, Resource Files and Other Files. Visual Studio reads the
    .vcxproj.filters file to decide where entries appear in Solution Explorer.
    This post-action keeps the generated ClCompile/ClInclude/None item types,
    but assigns each item to its path relative to the project source root.
    """
    namespace = 'http://schemas.microsoft.com/developer/msbuild/2003'
    qname = lambda name: '{%s}%s' % (namespace, name)

    def _rewrite_filters(target, source, env):
        # MSVSProject's primary target is the .vcxproj; its generator writes
        # the companion .filters file as a secondary target in the same action.
        filters_path = str(target[0]) + '.filters'
        if not os.path.isfile(filters_path):
            raise RuntimeError('MSVS filters file was not generated: %s' % filters_path)

        ET.register_namespace('', namespace)
        tree = ET.parse(filters_path)
        root = tree.getroot()
        old_groups = list(root.findall(qname('ItemGroup')))
        file_groups = []
        filter_paths = set()

        for group in old_groups:
            retained_items = []
            for item in list(group):
                # Drop SCons' synthetic filter declarations. Keep actual
                # project items (ClCompile, ClInclude, None, ResourceCompile).
                if item.tag == qname('Filter') and 'Include' in item.attrib:
                    continue
                if 'Include' not in item.attrib:
                    retained_items.append(item)
                    continue

                for child in list(item):
                    if child.tag == qname('Filter'):
                        item.remove(child)

                include_path = item.attrib['Include']
                absolute_path = os.path.abspath(os.path.normpath(
                    os.path.join(project_dir, include_path)
                ))
                relative_path = os.path.relpath(absolute_path, project_root)
                relative_path = os.path.normpath(relative_path)

                # All Premake project source roots live beneath neo/. If an
                # auxiliary item is outside that tree, keep its repository-
                # relative path rather than creating a synthetic type folder.
                if relative_path == os.pardir or relative_path.startswith(os.pardir + os.sep):
                    relative_path = os.path.relpath(absolute_path, os.path.dirname(project_root))

                directory = os.path.dirname(relative_path)
                filter_name = directory.replace('/', '\\').replace(os.sep, '\\').strip('\\')
                if filter_name and filter_name != '.':
                    parts = filter_name.split('\\')
                    for index in range(1, len(parts) + 1):
                        filter_paths.add('\\'.join(parts[:index]))
                    ET.SubElement(item, qname('Filter')).text = filter_name

                retained_items.append(item)

            if retained_items:
                new_group = ET.Element(qname('ItemGroup'))
                for item in retained_items:
                    new_group.append(item)
                file_groups.append(new_group)

        # Rebuild the filters file with only directory-based virtual folders.
        for group in old_groups:
            root.remove(group)

        if filter_paths:
            definitions = ET.Element(qname('ItemGroup'))
            for filter_name in sorted(filter_paths, key=lambda value: (value.count('\\'), value.lower())):
                filter_node = ET.SubElement(
                    definitions, qname('Filter'), {'Include': filter_name}
                )
                filter_guid = '{%s}' % str(uuid.uuid5(
                    uuid.NAMESPACE_URL,
                    'Doom3BFG.MSVSFilter.%s.%s' % (project_name, filter_name),
                )).upper()
                ET.SubElement(filter_node, qname('UniqueIdentifier')).text = filter_guid
            root.append(definitions)

        for group in file_groups:
            root.append(group)

        tree.write(filters_path, encoding='utf-8', xml_declaration=True)
        return 0

    return _rewrite_filters


def _msvs_project_variants():
    variants = []
    for platform_name in ('Win32', 'x64'):
        for configuration in ('Debug', 'Release', 'Retail'):
            variants.append('%s|%s' % (configuration, platform_name))
    return variants


def _msvs_variant_defines(arch, configuration, project_defines):
    definitions = [
        '__DOOM__', 'ID_PC',
        '_CRT_SECURE_NO_DEPRECATE', '_CRT_NONSTDC_NO_DEPRECATE',
    ]
    if arch == 'x86':
        definitions.append('_USE_32BIT_TIME_T')
    if DLL_BUILD:
        definitions.append('__DOOM_DLL__')
    definitions.extend(project_defines)
    if configuration == 'Debug':
        definitions.append('_DEBUG')
    else:
        definitions.append('NDEBUG')
        if configuration == 'Retail':
            definitions.append('ID_RETAIL')
    return definitions


def _msvs_variant_cppflags(configuration):
    flags = ['/W4', '/nologo', '/GS', '/FC', '/std:c++17', '/EHsc', '/GR']
    if configuration == 'Debug':
        flags.extend(['/MTd', '/Zi', '/FS', '/Od'])
    else:
        flags.extend(['/MT', '/O2', '/Ob2', '/Gy', '/GF', '/Oi'])
    return flags


def _generate_msvc_projects():
    # SCons 4.11.x maps MSVC_VERSION 14.5 to Visual Studio 2026 (IDE 18.0).
    # Override with msvc_version=14.3 for VS 2022, 14.2 for VS 2019, etc.
    msvc_version = ARGUMENTS.get('msvc_version', '14.5')
    msvs_dir = os.path.abspath(os.path.join(SCRIPT_DIR, 'build', 'msvc'))
    os.makedirs(msvs_dir, exist_ok=True)

    try:
        msvs_env = Environment(
            tools=['default', 'msvs'],
            ENV=os.environ.copy(),
            MSVC_VERSION=msvc_version,
        )
    except Exception as exc:
        print(
            "ERROR: unable to initialize SCons Visual Studio project generator "
            "for MSVC_VERSION=%s: %s\n"
            "For Visual Studio 2026, use SCons 4.11.1 or newer. "
            "You can select another installed toolset with msvc_version=14.3, etc." %
            (msvc_version, exc),
            file=sys.stderr,
        )
        Exit(2)

    # SCons exposes the suffix variables as deferred construction-variable
    # expressions (for example ${GET_MSVSPROJECTSUFFIX}). Those expressions are
    # valid when SCons expands a builder target, but MUST NOT be concatenated into
    # the hand-written .sln file paths. Resolve the concrete suffixes once here.
    msvs_metadata = msvs_env.get('MSVS', {})
    msvs_project_suffix = msvs_metadata.get('PROJECTSUFFIX') or msvs_env.subst('$MSVSPROJECTSUFFIX')
    msvs_solution_suffix = msvs_metadata.get('SOLUTIONSUFFIX') or msvs_env.subst('$MSVSSOLUTIONSUFFIX')
    if not msvs_project_suffix or '$' in msvs_project_suffix:
        print('ERROR: could not resolve the Visual Studio project suffix: %r' % msvs_project_suffix, file=sys.stderr)
        Exit(2)
    if not msvs_solution_suffix or '$' in msvs_solution_suffix:
        print('ERROR: could not resolve the Visual Studio solution suffix: %r' % msvs_solution_suffix, file=sys.stderr)
        Exit(2)

    # Avoid SCons' generated Python bootstrap being incorrect for installations
    # where the `scons` command is supplied by a wrapper (for example Scoop).
    # The generated MSBuild project calls the same SCons command available to
    # the shell that generated the solution.
    scons_command = shutil.which('scons') or 'scons'
    if ' ' in scons_command and not (scons_command.startswith('"') and scons_command.endswith('"')):
        scons_command = '"%s"' % scons_command
    msvs_env['MSVSSCONS'] = scons_command

    # Preserve SCons as the compiler/build backend even when the current
    # command used toolchain=clang or toolchain=gcc.
    build_variants = []
    variant_args = []
    variant_defines_by_project = {}
    variant_flags = []
    variant_cpppaths = []
    for platform_name, arch in (('Win32', 'x86'), ('x64', 'x64')):
        for configuration in ('Debug', 'Release', 'Retail'):
            build_variants.append('%s|%s' % (configuration, platform_name))
            variant_args.append(
                'arch=%s config=%s toolchain=msvc%s' % (
                    arch, configuration.lower(), ' dll=1' if DLL_BUILD else ''
                )
            )
            variant_flags.append(_msvs_variant_cppflags(configuration))
            variant_cpppaths.append([
                _msvs_relative_to_project(path, msvs_dir)
                for path in base_cpppath
            ])

    # Match the project source selections from the supplied Premake files.
    doom_sources, doom_headers, doom_resources, doom_misc = _collect_msvs_files(
        ('cm', 'framework', 'renderer', 'sound', 'swf', 'sys', 'tools', 'ui'),
        excludes=[
            'framework/Session.cpp',
            'tools/compilers/roqvq/roq.m',
            'ui/GameWindow.cpp',
            'sys/win32/win_stats.*',
            'sys/win32/win_snd.cpp',
            'sys/win32/win_gamma.cpp',
            'renderer/BoundsTrack.cpp',
            # sys/stub is the standalone CLI-tool host harness (its own
            # main and sys/common stubs); it must never build in the engine.
            'sys/stub/*',
            'tools/convertidtech3assets/*',
        ],
    )
    idlib_sources, idlib_headers, idlib_resources, idlib_misc = _collect_msvs_files(('idlib',))
    game_sources, game_headers, game_resources, game_misc = _collect_msvs_files(
        ('d3xp',),
        excludes=[
            'd3xp/EndLevel.*',
            'd3xp/menus/MenuWidget_DevList.*',
            'd3xp/gamesys/Callbacks.cpp',
        ],
    )

    external_source_files = [
        'external/miniz/miniz.c',
        'external/minizip/ioapi.c',
        'external/minizip/unzip.cpp',
        'external/minizip/zip.cpp',
        'external/libbinkdec/src/BinkAudio.cpp',
        'external/libbinkdec/src/BinkDecoder.cpp',
        'external/libbinkdec/src/BinkVideo.cpp',
        'external/libbinkdec/src/BitReader.cpp',
        'external/libbinkdec/src/FileStream.cpp',
        'external/libbinkdec/src/HuffmanVLC.cpp',
        'external/libbinkdec/src/LogError.cpp',
        'external/libbinkdec/src/Util.cpp',
        'external/libbinkdec/src/avfft.c',
        'external/libbinkdec/src/dct.c',
        'external/libbinkdec/src/dct32.c',
        'external/libbinkdec/src/fft.c',
        'external/libbinkdec/src/mdct.c',
        'external/libbinkdec/src/rdft.c',
    ]
    external_header_files = [
        'external/miniz/miniz.h',
        'external/miniz/minizconf.h',
        'external/minizip/ioapi.h',
        'external/minizip/unzip.h',
        'external/minizip/zip.h',
    ]

    def project_paths(items):
        return [_msvs_relative_to_project(item, msvs_dir) for item in items]

    project_definitions = {
        'DoomEXE': [],
        'external': [],
        'idLib': ['__IDLIB__'],
        'Game-D3XP': ['_D3XP', 'CTF'] + (['GAME_DLL'] if DLL_BUILD else []),
    }

    # Build targets are the actual SCons artifacts for each variant. These let
    # Visual Studio show the correct output path and debug the executable.
    def target_for(project_name, arch, configuration):
        config_dir = os.path.join(
            SCRIPT_DIR, 'build', 'scons',
            'windows-%s-%s-msvc' % (arch, configuration.lower()),
        )
        if project_name == 'DoomEXE':
            return os.path.join(BIN_DIR, 'Doom3BFG.exe')
        if project_name == 'external':
            return os.path.join(config_dir, 'lib', 'external.lib')
        if project_name == 'idLib':
            return os.path.join(config_dir, 'lib', 'idLib.lib')
        if project_name == 'Game-D3XP':
            if DLL_BUILD:
                return os.path.join(BIN_DIR, 'gamex86.dll')
            return os.path.join(config_dir, 'lib', 'gamex86.lib')
        return None

    project_specs = [
        ('DoomEXE', doom_sources, doom_headers, doom_resources, doom_misc),
        ('external', external_source_files, external_header_files, [], []),
        ('idLib', idlib_sources, idlib_headers, idlib_resources, idlib_misc),
        ('Game-D3XP', game_sources, game_headers, game_resources, game_misc),
    ]

    # Assign deterministic GUIDs to generated VC++ projects and reuse them
    # in the hand-written solution file below.
    project_guids = {
        project_name: '{%s}' % str(uuid.uuid5(
            uuid.NAMESPACE_URL, 'Doom3BFG.VisualStudioProject.' + project_name
        )).upper()
        for project_name, _, _, _, _ in project_specs
    }

    project_nodes = []
    project_vcxproj_nodes = []
    for project_name, sources, headers, resources, misc in project_specs:
        if not sources and not headers and not resources and not misc:
            print("ERROR: no files found for Visual Studio project %s." % project_name,
                  file=sys.stderr)
            Exit(2)

        project_defines = [
            _msvs_variant_defines(arch, configuration, project_definitions[project_name])
            for platform_name, arch in (('Win32', 'x86'), ('x64', 'x64'))
            for configuration in ('Debug', 'Release', 'Retail')
        ]
        buildtargets = [
            target_for(project_name, arch, configuration)
            for platform_name, arch in (('Win32', 'x86'), ('x64', 'x64'))
            for configuration in ('Debug', 'Release', 'Retail')
        ]
        project_target = os.path.join(msvs_dir, project_name + msvs_project_suffix)
        kwargs = {
            'target': project_target,
            'srcs': project_paths(sources),
            'incs': project_paths(headers),
            'resources': project_paths(resources),
            'misc': project_paths(misc),
            'variant': build_variants,
            'cmdargs': ['-Q %s %s' % (project_name, args) for args in variant_args],
            'cppdefines': project_defines,
            'cppflags': variant_flags,
            'cpppaths': variant_cpppaths,
            'buildtarget': buildtargets,
            'auto_build_solution': 0,
        }
        if project_name == 'DoomEXE':
            kwargs['runfile'] = os.path.join(BIN_DIR, 'Doom3BFG.exe')

        # MSVS_PROJECT_GUID is the supported SCons construction variable for
        # the GUID written into each .vcxproj. Use a per-project clone so each
        # project receives a distinct, stable GUID.
        project_env = msvs_env.Clone()
        project_env.Replace(MSVS_PROJECT_GUID=project_guids[project_name])
        nodes = project_env.MSVSProject(**kwargs)

        # MSVSProject returns the .vcxproj and (for modern Visual Studio) its
        # companion .filters file. Only the .vcxproj belongs in the solution.
        project_suffix = msvs_project_suffix.lower()
        for project_node in nodes:
            project_node_path = str(project_node).lower()
            if project_node_path.endswith(project_suffix):
                project_vcxproj_nodes.append(project_node)
                # The MSVS tool also tags this node internally; set it here for
                # consistency across SCons versions.
                project_node.Tag('project_guid', project_guids[project_name])
                # MSVSProject writes both the .vcxproj and its secondary
                # .filters file in the primary .vcxproj action. Attach the
                # post-action to the primary target so ordering is guaranteed.
                rewrite_action = _make_directory_filters_action(
                    PROJECT_ROOT, msvs_dir, project_name
                )
                project_env.AddPostAction(
                    project_node,
                    Action(
                        rewrite_action,
                        strfunction=lambda target, source, env, executor=None: '',
                    ),
                )
        project_nodes.extend(nodes)

    solution_target = os.path.join(msvs_dir, 'Doom3BFG' + msvs_solution_suffix)

    def _write_solution(target, source, env):
        """Write a clean VS solution with real solution-folder records.

        SCons' MSVSSolution builder treats every supplied node as a project and
        derives a path from the node's directory. For logical Premake groups,
        this can produce bogus entries such as '..\\msvc\\exes'. Writing
        the small .sln file directly avoids treating solution folders as files.
        """
        solution_path = os.path.abspath(os.path.join(msvs_dir, 'Doom3BFG' + msvs_solution_suffix))
        solution_dir = os.path.dirname(solution_path)
        cpp_project_type = '{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}'
        solution_folder_type = '{2150E333-8FDC-42A3-9474-1A3956D46DE8}'

        if msvc_version.startswith('14.5'):
            vs_major, vs_version = '18', '18.0.0.0'
        elif msvc_version.startswith('14.3'):
            vs_major, vs_version = '17', '17.0.0.0'
        elif msvc_version.startswith('14.2'):
            vs_major, vs_version = '16', '16.0.0.0'
        elif msvc_version.startswith('14.1'):
            vs_major, vs_version = '15', '15.0.0.0'
        else:
            vs_major, vs_version = '17', '17.0.0.0'

        folder_names = ['exes', 'libs'] if not DLL_BUILD else ['exes', 'libs', 'dll']
        folder_guids = {
            folder: '{%s}' % str(uuid.uuid5(
                uuid.NAMESPACE_URL, 'Doom3BFG.VisualStudioSolutionFolder.' + folder
            )).upper()
            for folder in folder_names
        }
        solution_guid = '{%s}' % str(uuid.uuid5(
            uuid.NAMESPACE_URL, 'Doom3BFG.VisualStudioSolution.Doom3BFG'
        )).upper()

        # All .vcxproj files and the .sln live side-by-side in build/msvc.
        # Use the resolved literal suffix, never the deferred SCons expression
        # ${GET_MSVSPROJECTSUFFIX} (which Visual Studio cannot evaluate).
        project_paths = {
            name: os.path.relpath(
                os.path.join(msvs_dir, name + msvs_project_suffix),
                solution_dir,
            ).replace('/', '\\')
            for name, _, _, _, _ in project_specs
        }
        if any('$' in value for value in project_paths.values()):
            raise RuntimeError('Unresolved SCons variable found in Visual Studio project path: %r' % project_paths)
        dependencies = {
            'DoomEXE': ['external', 'idLib'] + ([] if DLL_BUILD else ['Game-D3XP']),
            'Game-D3XP': ['idLib'] if DLL_BUILD else [],
        }
        folder_for_project = {
            'DoomEXE': 'exes',
            'external': 'libs',
            'idLib': 'libs',
            'Game-D3XP': 'dll' if DLL_BUILD else 'libs',
        }

        lines = [
            'Microsoft Visual Studio Solution File, Format Version 12.00',
            '# Visual Studio ' + vs_major,
            'VisualStudioVersion = ' + vs_version,
            'MinimumVisualStudioVersion = 10.0.40219.1',
        ]

        # Real C++ projects always reference the generated .vcxproj filename.
        # Their paths are relative to build/msvc/Doom3BFG.sln, never to a
        # synthetic group directory or an unresolved SCons construction variable.
        for project_name, _, _, _, _ in project_specs:
            lines.append('Project("%s") = "%s", "%s", "%s"' % (
                cpp_project_type,
                project_name,
                project_paths[project_name],
                project_guids[project_name],
            ))
            dependency_names = dependencies.get(project_name, [])
            if dependency_names:
                lines.append('\tProjectSection(ProjectDependencies) = postProject')
                for dependency_name in dependency_names:
                    dependency_guid = project_guids[dependency_name]
                    lines.append('\t\t%s = %s' % (dependency_guid, dependency_guid))
                lines.append('\tEndProjectSection')
            lines.append('EndProject')

        # A solution folder is a logical container. Its path field is the
        # folder's display name, NOT a filesystem path such as ..\msvc\exes.
        for folder_name in folder_names:
            lines.extend([
                'Project("%s") = "%s", "%s", "%s"' % (
                    solution_folder_type,
                    folder_name,
                    folder_name,
                    folder_guids[folder_name],
                ),
                'EndProject',
            ])

        lines.extend([
            'Global',
            '\tGlobalSection(SolutionConfigurationPlatforms) = preSolution',
        ])
        for variant in build_variants:
            lines.append('\t\t%s = %s' % (variant, variant))
        lines.extend([
            '\tEndGlobalSection',
            '\tGlobalSection(ProjectConfigurationPlatforms) = postSolution',
        ])
        for project_name, _, _, _, _ in project_specs:
            project_guid = project_guids[project_name]
            for variant in build_variants:
                lines.append('\t\t%s.%s.ActiveCfg = %s' % (
                    project_guid, variant, variant
                ))
                lines.append('\t\t%s.%s.Build.0 = %s' % (
                    project_guid, variant, variant
                ))
        lines.extend([
            '\tEndGlobalSection',
            '\tGlobalSection(SolutionProperties) = preSolution',
            '\t\tHideSolutionNode = FALSE',
            '\tEndGlobalSection',
            '\tGlobalSection(NestedProjects) = preSolution',
        ])
        for project_name, folder_name in folder_for_project.items():
            lines.append('\t\t%s = %s' % (
                project_guids[project_name], folder_guids[folder_name]
            ))
        lines.extend([
            '\tEndGlobalSection',
            '\tGlobalSection(ExtensibilityGlobals) = postSolution',
            '\t\tSolutionGuid = %s' % solution_guid,
            '\tEndGlobalSection',
            'EndGlobal',
        ])

        os.makedirs(solution_dir, exist_ok=True)
        with open(solution_path, 'w', encoding='utf-8-sig', newline='') as solution_file:
            solution_file.write('\r\n'.join(lines) + '\r\n')
        return 0

    solution_nodes = Command(
        solution_target,
        project_vcxproj_nodes,
        Action(
            _write_solution,
            strfunction=lambda target, source, env, executor=None: 'Generating Visual Studio solution',
        ),
    )

    # ------------------------------------------------------------------
    # Build-description integrity for generated Visual Studio projects.
    #
    # SCons reads SConstruct/SConscript files on every invocation, so the
    # normal compile graph is already refreshed without a CMake-like restart.
    # The generated .vcxproj/.sln files are separate artifacts, however, and
    # must explicitly depend on the scripts that describe them. This makes
    # `scons msvc-projects` regenerate only when a build description, project
    # file inventory, or export setting has changed.
    # ------------------------------------------------------------------
    build_description_paths = [os.path.join(SCRIPT_DIR, 'SConstruct')]
    for current_root, dirs, filenames in os.walk(PROJECT_ROOT):
        dirs[:] = sorted(
            d for d in dirs
            if d not in ('.git', '.vs', '__pycache__', 'build', 'bin', 'obj')
        )
        for filename in filenames:
            if filename == 'SConscript' or filename.endswith('.scons.py'):
                build_description_paths.append(os.path.join(current_root, filename))

    # Normalize and de-duplicate in stable order. Only existing scripts are
    # included; a newly added SConscript changes this list on the next run and
    # therefore changes the Value signature below.
    build_description_paths = sorted(set(
        os.path.abspath(path) for path in build_description_paths
        if os.path.isfile(path)
    ))
    build_description_nodes = [File(path) for path in build_description_paths]

    # Include non-file settings and the current source/header inventory in a
    # Value node. That catches changes such as dll=1, VS toolset changes,
    # altered Premake-compatible source globs, and added/removed project files,
    # even when none of the output files has a newer timestamp.
    export_signature_data = {
        # Include the script path inventory itself so adding or removing a
        # SConscript also invalidates the generated project files.
        'build_description_paths': [
            os.path.relpath(path, SCRIPT_DIR).replace('\\', '/')
            for path in build_description_paths
        ],
        'msvc_version': msvc_version,
        'dll': bool(DLL_BUILD),
        'platforms': list(build_variants),
        'projects': {
            name: {
                'sources': [_relative(path) for path in sources],
                'headers': [_relative(path) for path in headers],
                'resources': [_relative(path) for path in resources],
                'misc': [_relative(path) for path in misc],
                'defines': list(project_definitions[name]),
            }
            for name, sources, headers, resources, misc in project_specs
        },
        'project_guids': dict(project_guids),
        'solution_folder_type': '{2150E333-8FDC-42A3-9474-1A3956D46DE8}',
    }
    export_signature = Value(repr(export_signature_data))
    export_integrity_inputs = build_description_nodes + [export_signature]

    # Apply the same integrity inputs to every generated project artifact
    # (.vcxproj and .filters) and to the solution. No AlwaysBuild is used:
    # unchanged exports remain up-to-date, while changed scripts force refresh.
    Depends(project_nodes, export_integrity_inputs)
    Depends(solution_nodes, export_integrity_inputs)

    # A separate selectable target makes export independent of the normal
    # default build and keeps the generated files entirely under build/msvc/.
    msvc_alias = Alias('msvc-projects', list(project_nodes) + list(solution_nodes))
    return msvc_alias


if MSVS_EXPORT_REQUESTED:
    msvc_projects_target = _generate_msvc_projects()
    Default(msvc_projects_target)
else:
    Default(all_group)


_PROGRESS_STATE['total'] = len(_PROGRESS_NODES)
if _PROGRESS_ENABLED:
    _setup_progress_footer()
    _draw_progress(0, _PROGRESS_STATE['total'])
