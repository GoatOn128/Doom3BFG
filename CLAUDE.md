# Doom3BFG — agent instructions

Doom 3 BFG Edition GPL sources with a from-scratch SCons build ported from the
original Premake scripts. Windows only. The toolchain is LLVM: clang-cl compiles,
lld-link links, llvm-lib archives. MSVC supplies headers, libraries and the
resource tooling environment (vcvars or msvc-dev-cmd), nothing else.

## Build

    scons arch=x64 config=debug
    scons arch=x86 config=release
    scons arch=x64 config=release dll=1

- arch: x86 or x64 (default x64). config: debug, release or retail (default debug).
- dll=1 links Game-D3XP as bin/base/gamex86.dll instead of a static library.
- verbose=1 shows full compiler command lines. -jN overrides the default job count.
- Outputs: bin/Doom3BFG.exe, bin/base/gamex86.dll (dll=1), static libs under build/scons/windows-<arch>-<config>/lib.
- LLVM must be on PATH (or pass llvm_bin=<path>) and the MSVC environment must be active.

## Layout

- SConstruct — global build logic, toolchain setup, options, groups (libs, exes, dll, all).
- neo/*/SConscript — per-project definitions mirroring the Premake projects: external (neo/external), idLib (neo/idLib), Game-D3XP (neo/d3xp), DoomEXE (neo/SConscript).
- neo/external — bundled third-party code (miniz, minizip, libbinkdec, stb). Never modify, refactor or reformat it.
- base/ — game assets.

## CI

Two workflows run per push, then a third publishes their results:

- format (ci-format.yml) — uncrustify pass over neo/ excluding neo/external; on push events it auto-commits corrections with [skip ci].
- build-windows (ci-windows.yml) — matrix of x86/x64 times debug/release plus an x64 release dll=1 leg, built with clang-cl.
- publish (ci-publish.yml) — after both finish, commits build-digest.md and build-windows.log to the repo root.

Working rules:

1. Read build-digest.md first: per-leg status, errors, failure context and warning kinds. Open build-windows.log only when the digest trims a context block you need.
2. Fix every error AND every warning. The build compiles with /W4; a change is not done until the digest shows zero warnings.
3. Never hand-edit build-digest.md or build-windows.log. They are bot outputs regenerated every run.
4. [skip ci] in a commit message skips all workflows for that commit. Use it only for pushes that cannot affect the build (docs, notes). Never put it on a code push.
5. Digest files in the repo root can lag the branch head: the bot and the publish job also push. Match the commit sha printed at the top of build-digest.md against the branch head before diagnosing.

## Code style

- uncrustify (uncrustify.cfg at the repo root) owns formatting; the CI bot auto-commits reformatting after pushes. Do not hand-format code and do not revert the bot's commits — rebase on them.
- Comments: plain English, only where the code is not self-explanatory. No line-by-line noise, no commented-out code left behind.
- Edits are surgical and behavior-preserving. No drive-by rewrites or style-only refactors of engine code.

## Workflow

- Work on a feature branch, open a PR into master, squash merge when CI is green.
- Commit messages: plain-English bullet lists. One logical change per commit.
- After pushing expect the uncrustify bot to push a follow-up format commit on the same branch.
