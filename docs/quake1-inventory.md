# Quake 1 content support inventory

Audited at commit `f552f8c15b0ec9b78d8babdb87cf7e098ddba622` (master) on 2026-11-03. Companion to `docs/quake2-inventory.md` and `docs/quake3-inventory.md`.

Purpose: gap analysis before implementing Quake 1 content support. The engine side is unchanged from the Q2 audit and cross-referenced here (`neo/framework/FileSystem.cpp`, `neo/renderer/Image_files.cpp`, `neo/renderer/ModelManager.cpp`, `neo/renderer/Cinematic.cpp`). The Q1 requirement side is taken entirely from the vendored source in `references/quake` (id's 1999 GPL release: `WinQuake/` holds the shared engine plus the software and GL renderers, `QW/` is the netcode fork and is reference-only); no external sources were used.

Out of scope: QuakeC game logic (flagged in section 7), networking, demos (`.dem`), savegames, CD audio. The map format (BSP v29) is included and flagged the same way as in the Q2/Q3 inventories.

## 1. Package archives (.pak)

Status: implemented (shared work item with the Q2 inventory). `idPackContainer` (`neo/framework/File_Pak.h/.cpp`) landed in commit `3df000b` (2026-11-03); one container serves both games, so `id1/pak0.pak` contents are reachable through normal opens and listings.

### 1.1 What Q1 .pak files are (`references/quake/WinQuake/common.c`, `COM_LoadPackFile` / `COM_AddGameDirectory` / `COM_FindFile`)

- Byte-identical container to Q2: 12-byte header at the file start (`dpackheader_t { char id[4] = "PACK"; int dirofs; int dirlen; }`), directory of 64-byte entries (`dpackfile_t { char name[56]; int filepos, filelen; }`), `MAX_FILES_IN_PACK` 2048 (Q2 uses 4096).
- Mounting: per game dir, `pak0.pak .. pakN.pak` in an uncapped loop (stops at the first missing file), each pak prepended to the search list so higher numbers override lower ones, and paks override the loose directory. Base dir `id1`, then optional stacked mission-pack dirs (`rogue`, `hipnotic`), then a `-game` dir on top - the same one-base-plus-one-mod stacking the engine already models with `fs_game`.
- Q1 entry lookup is case-SENSITIVE (`strcmp`); all stock pak entries are lowercase, so the engine's case-insensitive lookup is a superset and finds everything Q1 finds.
- The registered check (`gfx/pop.lmp`, `PAK0_COUNT` 339, `PAK0_CRC` 32981) is a 1996 licensing artifact; ignorable.

### 1.2 The gap (closed in `3df000b`)

Implemented as described: the engine's sorted-glob mounting replaced Q1's pak0..pakN loop with no behavior change on stock content, entry names are lowercased (the case-insensitive lookup superset), and the max-files validation became a 65536-entry sanity cap covering both games' stock paks.

Original analysis, kept for reference:

- Same as the Q2 inventory section 1.3: the container format is missing, everything downstream fits. One `idPackContainer` serves both games - only the max-files validation constant differs (2048 vs 4096; take the larger). The engine's sorted-glob mounting can replace Q1's pak0..pakN loop without behavior change on stock content.

## 2. Images

Status: `gfx/palette.lmp` is loaded (768 raw bytes) inside the SPR and MDL model loaders (commits `2aa9c25c`, `0b2538e5`) to decode their embedded bitmaps; the general image loaders of section 2.2 (lmp/qpic, WAD2, miptex) remain open. The model loaders decode MDL skins as fully opaque RGBA (no 255 transparency on model skins).

### 2.1 What Q1 uses

Q1 has no image files on disk in the Q2 sense: almost everything 8-bit is either a loose `.lmp`, a lump inside `gfx.wad`, a miptex embedded in the BSP (section 5), or a bitmap inside a model/sprite file. The common substrate is a global 256-color palette.

- Global palette: `gfx/palette.lmp` (768 raw bytes, no header), loaded in `Host_Init` (`host.c`) into `host_basepal`; `VID_SetPalette` (`gl_vidnt.c`) builds `d_8to24table`, and entry 255 is masked to transparent. `Check_Gamma` applies `pow((pal+1)/256, gamma)` with a 0.7 default before the table is built - decode-time gamma shaping that the stock look depends on.
- `gfx/colormap.lmp`: the software renderer's light-to-dark colormap plus the fullbright count (`vid.fullbright = 256 - value read at int index 2048` in `VID_Init`). GL uses only that fullbright count. Palette colors `256-fullbright .. 255` (248-255 in stock) are never darkened by lighting in the software renderer; stock GLQuake has no per-texel fullbright handling on world surfaces at all (known limitation - the lightmap modulates every texel; `r_fullbright` only forces lighting off globally). A convention decision for the D3 side: match GLQuake (ignore) or match software (honor).
- lmp pics (`qpic_t { int width; int height; byte data[]; }`, `wad.h`): `gfx/*.lmp` (conback, vidmodes, etc.), 8-bit, index 255 transparent (`Draw_TransPic` skips 255).
- WAD2: `gfx.wad`, loaded at startup (`W_LoadWadFile` in `Host_Init`). A lump container (`wadinfo_t` header, `lumpinfo_t` entries with `filepos/disksize/size/type/compression/name[16]`), lump types `TYP_QPIC` (menu/HUD pics), `TYP_MIPTEX`, `TYP_PALETTE`, `TYP_SOUND`, with an LZSS compression flag. `W_CleanupName` LOWERCASES every lump name (per `wad.c`) - all wad lookups are lowercase by convention. The console font is the `conchars` lump from gfx.wad (128x128, zeros remapped to 255, uploaded unfiltered, `gl_draw.c` `Draw_Init`).
- Model/sprite bitmaps: raw 8-bit, palette-indexed, 255 transparent (uploaded through `GL_LoadTexture` with alpha).
- World textures: miptex embedded in the BSP - `miptex_t { char name[16]; unsigned width, height; unsigned offsets[4]; }` (16-aligned sizes, four baked mip levels, indexed pixels after the header). Textures with `dataofs == -1` (not embedded) are skipped by stock GLQuake - external-texture-wad maps are a later-engine convention, not required for stock content.

### 2.2 The gap

Missing, in dependency order:

1. `gfx/palette.lmp` loader (768 bytes, no header) with the 0.7 gamma curve and the 255-transparent convention. Same role as Q2's `colormap.pcx`; one palette object per game.
2. lmp/qpic loader (trivial: two ints + raw 8-bit data).
3. WAD2 container reader (`gfx.wad`; uppercase name lookup, per-lump types, LZSS flag - stock gfx.wad lumps are uncompressed).
4. 8-bit-to-RGBA decode through the palette for all of the above; same strategy as the Q2 PCX/WAL work (engine wants RGBA and does its own mipmaps; the four baked mip levels are ignorable).
5. Pics to materials: `gfx/*.lmp` and gfx.wad QPIC lumps referenced by name need implicit materials, like the Q2 `pics/` work; `conchars` is replaceable by an `idFont` or an unfiltered material.

## 3. Surface/material semantics

Q1 has no shader files and no WAL-style flag header. Appearance is encoded in texture NAME PREFIXES plus one texinfo flag (`gl_model.c` `Mod_LoadTextures` / `Mod_LoadSurfaces`):

- Name starting `*`: turbulent liquid; texcoords warped by `turbsin` (`gl_warp.c` `EmitWaterPolys`), surfaces subdivided at 64 units.
- Name starting `sky`: the sky texture. A sky texture is 256x128: `R_InitSky` (`gl_warp.c`) splits it into a solid layer (right half) and an alpha overlay (left half, index 0 replaced by the averaged backdrop color), rendered as two scrolling passes (realtime*8 and realtime*16) over subdivided sky surfaces. This is Q1's sky - one texture, not the Q2 env box (the env-box code in `gl_warp.c` is `#ifdef QUAKE2`, compiled out).
- Name starting `+`: animated texture; frame index digit `0-9`, alternate frames `A-J`, sequenced at 10 fps (`R_TextureAnimation`, `gl_rsurf.c`).
- `texinfo_t.flags & TEX_SPECIAL`: sky or slime - no lightmap, forced subdivision.

Mapping onto D3 materials (same implicit-material generator as the Q2 inventory section 3, different flag source):

| Q1 convention | Doom 3 equivalent | Notes |
|---|---|---|
| `*` prefix | water material / `deform turbulent` | liquid surfaces also carry CONTENTS_* in the BSP leaf, game side |
| `sky` prefix | skysphere material with the two-layer scroll | or bake the two halves into a skybox; visual-only decision |
| `+` digit / `+` letter | animMap-style frame stage | the Q3 animMap work covers the mechanism |
| `TEX_SPECIAL` | noLighting/sky handling | |
| palette 255 | alphaTest / coverage | from the palette decode |

## 4. Model formats

Status: MDL loads since `0b2538e5` and SPR since `2aa9c25c` (`neo/renderer/Model_mdl.h/.cpp`, `neo/renderer/Model_spr.h/.cpp`), both dispatched from `ModelManager::GetModel` on the lowercased extension. Gap closed; see 4.3 for what landed.

### 4.1 What loads today

Same dispatch as the Q2 audit (`neo/renderer/ModelManager.cpp`): no MDL, no SPR. MD2/MD3-style machinery exists and is the porting target.

### 4.2 What Q1 uses

- MDL (`Mod_LoadAliasModel`, `gl_model.c`; structs `modelgen.h`): `IDPOLYHEADER` "IDPO", `ALIAS_VERSION` 6. Header `mdl_t` (per-model `scale[3]`/`scale_origin[3]`, `boundingradius`, `eyeposition`, `skinwidth`/`skinheight`, counts, `synctype`, `flags`); skins embedded as 8-bit palette bitmaps (single or skin groups with intervals); `stvert_t { onseam, s, t }` - the backskin seam trick (backfaces sample `s + skinwidth/2`); `dtriangle_t { facesfront, vertindex[3] }`; frames of `daliasframe_t { bboxmin, bboxmax (trivertx_t), name[16] }` + `trivertx_t { byte v[3]; byte lightnormalindex; }` verts, single or frame groups with intervals. Normals from the 162-entry `anorms.h` table.
- SPR (`Mod_LoadSpriteModel`, `gl_model.c`; structs `spritegn.h`): `IDSPRITEHEADER` "IDSP", `SPRITE_VERSION` 1, five orientation types (`SPR_VP_PARALLEL_UPRIGHT`..`SPR_VP_PARALLEL_ORIENTED`), frames of `dspriteframe_t { origin[2], width, height }` plus an embedded 8-bit bitmap (255 transparent), single or groups with intervals.
- Brush submodels: doors/plats are `*N` models inside the map BSP (`dmodel_t` with `headnode[4]`) - part of the map decision (section 5).

### 4.3 The gap and implementation notes (closed in `0b2538e5` for MDL, `2aa9c25c` for SPR)

- MDL loader: same MD3-parity machinery as the MD2 plan in the Q2 inventory - frame-channel lerp, per-frame bounds from `bboxmin/bboxmax`, skins decoded through the Q1 palette into RGBA textures (one material per skin, resolved by name), `lightnormalindex` -> `anorms` -> normals, tangents derived like the MD3 fix. Q1-specific work: materialize the onseam backskin (split verts at the seam so backfaces sample the duplicate half of the skin), and group frames (interval lists) beyond the two-frame lerp.
- SPR loader: same synthesized-quad approach as the Q2 SP2 item; embedded bitmaps instead of pcx references, plus the orientation type on the entity (game-side glue).

As implemented:

- MDL (`0b2538e5`): onseam handled without vertex splitting - per-corner final UVs with `s + skinwidth/2` applied when `!facesfront && onseam` (the shift depends on the triangle, so UVs are stored per corner); skins decoded opaque RGBA through `gfx/palette.lmp`, the first skin becomes the material, the rest register as images a material can reference by name; skin and frame groups flattened, game code drives timing through the `SHADERPARM_MD3_*` frame parms; per-frame bounds scanned from the vertices (Q1 bboxmin/bboxmax records ignored); normals from the 162-entry anorms table (same table as the MD2 loader).
- SPR (`2aa9c25c`): per-frame quads from the embedded bitmaps through the same palette. The orientation-type billboard glue is not automatic: `deform sprite` in a user material or `ent->customShader` on the entity.

## 5. Map format (BSP v29) - flagged, coupled to the lighting decision

The engine has no BSP loader (world is `.proc`/`.bmodel` only). Q1 maps are BSP version 29 with 15 lumps (`bspfile.h`), and the differences from Q2 v38 matter:

- `LUMP_TEXTURES` embeds the world's miptex directly (section 2.1) - a Q1 map is self-contained, no loose texture files to find.
- `LUMP_TEXINFO`: `texinfo_t { vecs[2][4], miptex, flags }` with `TEX_SPECIAL` (section 3).
- `LUMP_LIGHTING`: `dface_t.styles[4]` + `lightofs` - the same lightmap/lighting-provider coupling flagged in both earlier inventories.
- `LUMP_CLIPNODES`: up to `MAX_MAP_HULLS` 4 collision hulls - game-side (the equivalent of Q2's brush/cmodel data, but hull-based).
- Leaf `ambient_level[4]` (water/sky/slime/lava auto-sound levels), `LUMP_VISIBILITY`, `dmodel_t` submodels with `headnode[4]`.

Same decision as the Q2 inventory section 5: an in-engine BSP loader or an offline converter to `.proc`/`.bmodel` + generated materials. Either way it is the single largest item and shares the lightmap provider question with the Q2/Q3 tracks.

## 6. Sound

Plain RIFF `.wav` (`snd_mem.c` `GetWavinfo`: RIFF/fmt/data chunks, 8/16-bit, loop via cue/LIST markers). The engine loads wav already. Nothing missing.

## 7. Game logic (progs.dat) - the non-format gap

Q1's entire game ships as `progs.dat`, QuakeC bytecode executed by the engine's built-in VM (`PR_Init`/`pr_edict.c`/`pr_exec.c`). Unlike Q2/Q3 (native game modules the engine could in principle load or reimplement), there is no path to running Q1 game logic without implementing a QuakeC virtual machine, converting the QC, or reimplementing the game. Out of scope for a content-support inventory, but it is the gate between "renders Q1 content" and "plays Quake". Startup script conventions (`quake.rc` exec'ing `default.cfg`/`config.cfg`/`autoexec.cfg`) are listed for completeness.

## 8. What already works

- MDL models (since `0b2538e5`) and SPR sprites (since `2aa9c25c`), embedded skins and frames decoded through `gfx/palette.lmp`.
- `.pak` archives (since `3df000b`: `idPackContainer` mounts `id1` paks).
- WAV sound.
- Loose-directory content: `id1` as an `fs_game` directory needs no filesystem change (same as `baseq2`/`etmain`).
- Case-insensitive path lookups are a superset of Q1's case-sensitive semantics.
- `.dem` demos, savegames, CD audio: out of scope.
- No video format exists in Q1 (the `.cin` track is Q2-only).

## 9. Recommended implementation order

1. `.pak` container - DONE in `3df000b` (shared `idPackContainer`); stock Q1 data in `id1/pak0.pak` is now reachable.
2. `palette.lmp` + lmp + WAD2 loaders (section 2.2). - PARTIAL: `palette.lmp` is loaded inside the SPR and MDL model loaders (`2aa9c25c`, `0b2538e5`); `idWad2` / `idWad2MipTexLump` (`neo/framework/Wad2.*`) read WAD2 containers and miptex and decode them through the palette (used by dmap for BSP textures); the lmp/qpic loader and runtime `gfx.wad` use remain open.
3. Implicit materials from the name-prefix/TEX_SPECIAL conventions (section 3).
4. MDL (+SPR) through the MD3 path machinery (section 4). - DONE in `0b2538e5` (MDL) and `2aa9c25c` (SPR).
5. BSP v29 decision, piggybacking on sections 2-3 and sharing the lightmap provider question (section 5). - PARTIAL: `idBsp29` (`neo/framework/Bsp29.*`) loads/writes v29 with the clipnodes and lighting lumps skipped and the BSPX lumps `D3_CM`, `D3_LIGHTING`, `D3_VIS` appended; `dmap maps/x.bsp` converts the node tree to brushes and writes `.proc`/`.cm`. No runtime BSP loading yet.
6. QuakeC VM decision only when "playing" (not just rendering) becomes the goal (section 7).

## Licensing note

`references/quake` is id's 1999 source release with GPLv2-or-later headers (`gnu.txt` in that directory); porting loaders from it (pak, lmp, WAD2, MDL, SPR, miptex decode) into this GPLv3 engine is license-compatible. Keep the original copyright headers on ported files and note the origin in the port commits.

## Sources

All in this repository:

- `references/quake/WinQuake/common.c` - pak format, search path, mounting, lookup semantics
- `references/quake/WinQuake/host.c` - gfx.wad / palette.lmp / colormap.lmp load sites
- `references/quake/WinQuake/wad.h` - WAD2 container and qpic_t structures
- `references/quake/WinQuake/gl_vidnt.c` - d_8to24table build, 255 transparency, gamma curve, fullbright count
- `references/quake/WinQuake/gl_draw.c` - lmp pics, conchars, GL_Upload8, transparency conventions
- `references/quake/WinQuake/gl_model.c` - BSP/MDL/SPR loaders, miptex, texture name conventions, animation chaining
- `references/quake/WinQuake/gl_warp.c` - sky texture split and water warp
- `references/quake/WinQuake/gl_rsurf.c` - lightmap building, texture animation, r_fullbright
- `references/quake/WinQuake/bspfile.h` - BSP v29 lumps and structures
- `references/quake/WinQuake/modelgen.h`, `spritegn.h` - MDL and SPR on-disk formats
- `references/quake/WinQuake/snd_mem.c` - wav loading
- Engine side: unchanged from the Q2 audit at this head (`neo/framework/FileSystem.cpp`, `neo/renderer/Image_files.cpp`, `neo/renderer/ModelManager.cpp`, `neo/renderer/Cinematic.cpp`)
