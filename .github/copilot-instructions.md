# Doom3BFG — Copilot instructions

Doom 3 BFG Edition GPL sources with a from-scratch SCons build ported from the
original Premake scripts. Windows only. Three toolchains: msvc (default) builds
with cl.exe/link.exe/lib.exe from the MSVC environment (vcvars or msvc-dev-cmd);
clang drives LLVM clang-cl/lld-link/llvm-lib over MSVC headers and libraries;
gcc uses a MinGW-w64 gcc/g++/windres toolchain from PATH.

## Build

    scons toolchain=msvc arch=x64 config=debug
    scons toolchain=clang arch=x64 config=debug
    scons toolchain=gcc arch=x64 config=debug
    scons arch=x86 config=release
    scons arch=x64 config=release dll=1

- arch: x86 or x64 (default x64). config: debug, release or retail (default debug).
- toolchain: msvc (default), clang, or gcc.
- dll=1 links Game-D3XP as bin/gamex86.dll instead of a static library.
- verbose=1 shows full compiler command lines. -jN overrides the default job count.
- Outputs: bin/Doom3BFG.exe, bin/gamex86.dll (dll=1), static libs under build/scons/windows-<arch>-<config>-<toolchain>/lib.
- toolchain=msvc needs the MSVC environment (vcvars or msvc-dev-cmd). toolchain=clang also needs LLVM on PATH or llvm_bin=<path>. toolchain=gcc needs MinGW-w64 gcc/g++/windres on PATH.

## Layout

- SConstruct — global build logic, toolchain setup, options, groups (libs, exes, dll, all).
- neo/*/SConscript — per-project definitions mirroring the Premake projects: external (neo/external), idLib (neo/idLib), Game-D3XP (neo/d3xp), DoomEXE (neo/SConscript).
- neo/external — bundled third-party code (miniz, minizip, libbinkdec, stb). Never modify, refactor or reformat it.
- base/ — game assets.

## CI

One workflow builds per push, then a second publishes its results:

- build-windows (ci-windows.yml) — matrix of x86/x64 times debug/release plus an x64 release dll=1 leg, built with MSVC (the default toolchain).
- publish (ci-publish.yml) — after the build finishes, commits build-digest.md and build-windows.log to the repo root.

Working rules:

1. Read build-digest.md first: per-leg status, errors, failure context and warning kinds. Open build-windows.log only when the digest trims a context block you need.
2. Fix every error AND every warning. The build compiles with /W4; a change is not done until the digest shows zero warnings.
3. Never hand-edit build-digest.md or build-windows.log. They are bot outputs regenerated every run.
4. [skip ci] in a commit message skips all workflows for that commit. Use it only for pushes that cannot affect the build (docs, notes). Never put it on a code push.
5. Digest files in the repo root can lag the branch head: the publish job also pushes. Match the commit sha printed at the top of build-digest.md against the branch head before diagnosing.

## Code style

- Formatting is manual: uncrustify.cfg at the repo root describes the project style, and there is no format bot. Keep formatting changes in their own commit, never mixed into a functional change.
- Comments: plain English, only where the code is not self-explanatory. No line-by-line noise, no commented-out code left behind.
- Edits are surgical and behavior-preserving. No drive-by rewrites or style-only refactors of engine code.

## Workflow

- Work on a feature branch, open a PR into master, squash merge when CI is green.
- Commit messages: plain-English bullet lists. One logical change per commit.
- After pushing, the publish job may push a digest commit on the same branch; rebase on it instead of discarding it.
