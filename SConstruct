# Doom 3 BFG SCons build
#
# Usage:
#   scons arch=x64 config=debug
#   scons arch=x86 config=release
#   scons arch=x64 config=retail dll=1
# Parallel jobs default to up to 16 CPU cores; use -jN or -j1 to override.
#
# Project definitions live in neo/*/SConscript, mirroring the original
# Premake external.lua, idlib.lua, d3xp.lua, and DoomEXE project blocks.
# Outputs follow Premake: bin/Doom3BFG.exe and, for dll=1, bin/gamex86.dll.

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
USE_COLOR = ANSI_TTY and os.environ.get('NO_COLOR') is None
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
    and not GetOption('no_exec')
    and not GetOption('clean')
    and not COMMAND_LINE_TARGETS
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
DLL_BUILD = ARGUMENTS.get('dll', '0').lower() in ('1', 'true', 'yes', 'on')
DEDICATED = ARGUMENTS.get('dedicated', '0').lower() in ('1', 'true', 'yes', 'on')

if ARCH not in ('x86', 'x64'):
    print("arch must be x86 or x64 (received %r)" % ARCH, file=sys.stderr)
    Exit(2)
if CONFIG not in ('debug', 'release', 'retail'):
    print("config must be debug, release, or retail (received %r)" % CONFIG, file=sys.stderr)
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
# roots live under neo/, mirroring the original Premake layout.
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
PROJECT_ROOT = os.path.abspath(os.path.join(SCRIPT_DIR, 'neo'))
BUILD_ROOT = os.path.abspath(os.path.join(
    SCRIPT_DIR, 'build', 'scons', 'windows-%s-%s' % (ARCH, CONFIG)))
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
  scons [arch=x86|x64] [config=debug|release|retail] [dll=1] [-jN]
  scons arch=x64 config=debug                 Build all projects
  scons libs                                  Build the "libs" group
  scons exes                                  Build the "exes" group
  scons external                              Build only the external project
  scons idLib                                 Build only the idLib project
  scons Game-D3XP                             Build only the game code
  scons DoomEXE                               Build the engine code
  scons arch=x64 config=debug dll=1 dll       Build the "dll" group

Project selection (mirrors Premake groups):
  libs               external + idLib + Game-D3XP static library (when dll=0)
  exes               DoomEXE / bin/Doom3BFG.exe
  dll                Game-D3XP / bin/gamex86.dll (only when dll=1)
  external           Individual external static-library project
  idLib              Individual idLib static-library project
  Game-D3XP          Individual game project; .lib or .dll depending on dll=1
  DoomEXE            Individual executable project
  all                All projects

Options:
  arch=x86|x64       Target architecture (default: x64)
  config=debug       Debug symbols, no optimization, static debug CRT
  config=release     Optimized release build
  config=retail      Optimized retail build with ID_RETAIL and no debug symbols
  dll=1              Put Game-D3XP in the "dll" group and build gamex86.dll
  dedicated=1        Dedicate server build
  verbose=1          Show full compiler/linker command lines
  -jN                Number of parallel jobs; defaults to min(CPU count, 16)

Project definitions:
  neo/external/SConscript
  neo/idLib/SConscript
  neo/Game-D3XP/SConscript
  neo/DoomEXE/SConscript

Build products:
  bin/Doom3BFG.exe
  bin/gamex86.dll    (dll=1 only)
  build/scons/windows-<arch>-<config>/lib/*.lib
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
# LLVM / Windows toolchain
# -----------------------------------------------------------------------------
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

TARGET_ARCH = 'x86' if ARCH == 'x86' else 'amd64'
MACHINE_FLAG = '/MACHINE:X86' if ARCH == 'x86' else '/MACHINE:X64'
ARCH_FLAG = '-m32' if ARCH == 'x86' else '-m64'

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
]

# Use SCons' Microsoft link/resource builders, but drive compilation and linking
# with LLVM's clang-cl/lld-link/llvm-lib toolchain.
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

# Premake staticruntime("On") maps to /MTd for Debug and /MT otherwise.
if CONFIG == 'debug':
    env.Append(CCFLAGS=['/MTd', '/Z7', '/Od'])
    env.Append(CXXFLAGS=['/MTd', '/Z7', '/Od'])
    env.Append(CPPDEFINES=['_DEBUG'])
    env.Append(LINKFLAGS=['/DEBUG', '/MAP'])
    env.Append(SHLINKFLAGS=['/DEBUG', '/MAP'])
elif CONFIG == 'release':
    env.Append(CCFLAGS=['/MT', '/O2', '/Ob2', '/Gy', '/GF', '/Oi'])
    env.Append(CXXFLAGS=['/MT', '/O2', '/Ob2', '/Gy', '/GF', '/Oi'])
    env.Append(CPPDEFINES=['NDEBUG'])
    env.Append(LINKFLAGS=['/OPT:REF', '/OPT:ICF'])
    env.Append(SHLINKFLAGS=['/OPT:REF', '/OPT:ICF'])
else:  # retail
    env.Append(CCFLAGS=['/MT', '/O2', '/Ob2', '/Gy', '/GF', '/Oi'])
    env.Append(CXXFLAGS=['/MT', '/O2', '/Ob2', '/Gy', '/GF', '/Oi'])
    env.Append(CPPDEFINES=['NDEBUG', 'ID_RETAIL'])
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
    env.Append(CCFLAGS=['/clang:-fcolor-diagnostics'], CXXFLAGS=['/clang:-fcolor-diagnostics'])

# Keep the diagnostic forwarding, SCons output, and progress footer from the
# previous build script. SCons' mslink tool supplies the command templates.
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
        target = os.path.join(OBJECT_ROOT, project_name, rel + '.obj')
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
    'DLL_BUILD', 'ARCH', 'CONFIG', 'MACHINE_FLAG', '_track_progress',
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

# -----------------------------------------------------------------------------
# Premake-style project targets and groups
# -----------------------------------------------------------------------------
# SCons aliases reproduce Premake's named neo/groups. Each project is
# independently selectable, and dependency edges build the required libraries.
external_project = Alias('external', external_lib)
idlib_project = Alias('idLib', idlib_lib)
game_project = Alias('Game-D3XP', game_target)
doom_project = Alias('DoomEXE', doom_target)
Alias('Doom3BFG', doom_target)

libs_members = [external_project, idlib_project]
if not DLL_BUILD:
    libs_members.append(game_project)
libs_group = Alias('libs', libs_members)
exes_group = Alias('exes', [doom_project])
all_members = [libs_group, exes_group]
if DLL_BUILD:
    dll_group = Alias('dll', [game_project])
    all_members.append(dll_group)
all_group = Alias('all', all_members)

Default(all_group)

_PROGRESS_STATE['total'] = len(_PROGRESS_NODES)
if _PROGRESS_ENABLED:
    _setup_progress_footer()
    _draw_progress(0, _PROGRESS_STATE['total'])
