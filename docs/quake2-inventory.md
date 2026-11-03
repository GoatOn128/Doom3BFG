# Quake 2 content support inventory

Audited at commit `cbe74a3c5baa252c2b83e490c3696062e8616f1b` (master) on 2026-11-03. Companion to `docs/quake3-inventory.md`.

Purpose: gap analysis before implementing Quake 2 content support. The engine side was read directly from this repo (`neo/framework/FileSystem.cpp`, `neo/renderer/Image_files.cpp`, `neo/renderer/ModelManager.cpp`, `neo/renderer/Cinematic.cpp`). The Q2 requirement side is taken entirely from the vendored GPL source in `references/quake2` (id's 3.21 release); no external sources were used.

Out of scope: game logic, networking, demos (`.dm2`), savegames, CD audio. The map format (BSP v38) is included but flagged the same way the Q3 inventory flagged its BSP: it is the largest item and coupled to the lightmap/lighting-provider decision already pending from the Q3 work.

## 1. Package archives (.pak)

Status: implemented. `idPackContainer` (`neo/framework/File_Pak.h/.cpp`) landed in commit `3df000b` (2026-11-03). `.pak` files mount alongside `.pk4`/`.pk3` in the game folders, opens, `GetFileLength` and directory listings resolve entries inside paks, and the `path` command prints mounted paks. Known limitation, shared with the stock zip container: `ListFilesTree` cannot recurse into pak subdirectories.

### 1.1 What the engine has today

- `idFileSystemLocal::AddSearchPath` (`neo/framework/FileSystem.cpp`, the `.resources` / `.pk4` / `.pk3` scan around lines 2621-2667) enumerates `.resources`, `.pk4` and `.pk3` and mounts all three through `idZipContainer` (built on the vendored minizip). `PakTypeForName` (lines 2309-2315) only knows `pk3` and `pk4`. There is no other container type.
- Lookup (`GetZipCacheEntry`) lowercases the requested relative path and compares case-insensitively through a per-container hash, walking containers last-to-first, so the alphabetically-last pak wins.
- Open and enumerate both work from containers (`OpenFileReadFlags`, `GetFileList` behind `ListFiles`/`ListFilesTree`), so decl folder registration, image loading and model loading see files inside mounted archives with no extra work.
- Loose file vs pak priority is `fs_resourceLoadPriority`; search path set is `fs_game`, `fs_game_base`, then `base`.

### 1.2 What .pak files are (`references/quake2/qcommon/files.c`, `qcommon/qfiles.h`)

- Not a zip. A linear file with a 12-byte header at the start of the file: `dpackheader_t { int ident ("PACK"); int dirofs; int dirlen; }`, and the directory at `dirofs` from the end: `dpackfile_t { char name[56]; int filepos, filelen; }` entries, 64 bytes each, `MAX_FILES_IN_PACK` 4096.
- Mounting (`FS_AddGameDirectory`): each game dir mounts only `pak0.pak` .. `pak9.pak` (fixed names, loop `i<10`), each pak prepended to the search list so higher numbers override lower ones, and paks override the loose directory. One base dir (`baseq2`) plus at most one mod dir.
- Entry lookup is case-insensitive (`Q_strcasecmp`).
- The directory checksum (`Com_BlockChecksum`, `PAK0_CHECKSUM` 0x40e614e0 retail) is only used in `NO_ADDONS` builds; stock Q2 3.21 has no pure system.

### 1.3 The gap (closed in `3df000b`)

Implemented as planned: the sorted-glob mounting was adopted, entry names are lowercased to match the case-insensitive lookup, no checksum verification runs, and mixed-case entries resolve through the hash. Implementation notes: entries pointing outside the pak are skipped with a warning, every opened file gets its own OS handle into the pak (concurrent readers cannot race the seek position), and the entry count is sanity-capped at 65536 instead of Q2's 4096.

Original analysis, kept for reference:

- The container format itself. Everything else already fits: the engine's container interface (cache table + hash, lowercased lookup, enumerate) matches Q2 semantics, and its case-insensitive compare matches `Q_strcasecmp` behavior.
- Implementation: an `idPackContainer` sibling of `idZipContainer` that reads the PACK header/directory and produces the same cache entries, plus a `.pak` line in `AddSearchPath`. All downstream code (decl folders, images, models) then sees pak contents unchanged.
- Policy notes: Q2's fixed `pak0-9` names vs the engine's glob-and-sort; adopting the glob keeps one code path (Q2 content rarely ships more than one or two paks). Loose-vs-pak priority stays `fs_resourceLoadPriority`. No checksum verification needed for local content support.
- Mixed-case entries inside old paks already resolve through the lowercased hash lookup.

## 2. Image formats

### 2.1 What the engine has today (`neo/renderer/Image_files.cpp`)

- `imageLoaders[]` (line 46) is `tga`, `bmp`, `png`, `jpg`, all through stb_image (`RB_LoadImage`); stb_image has no PCX and no WAL. Screenshots are written by stb (`tga`/`bmp`/`png`/`jpg`).
- `R_LoadCubeImages` (line 278) only tries `.tga` cube sides with the D3/Q3 suffixes (`_px/_nx/_py/_ny/_pz/_nz` or camera `_forward/_back/_left/_right/_up/_down`).
- The engine uploads RGBA and generates its own mipmaps; there is no paletted-texture path (Q2's `GL_COLOR_INDEX8_EXT`/`pics/16to8.dat` 3dfx machinery has no equivalent and is not needed).

### 2.2 What Q2 uses

- WAL (`references/quake2/ref_gl/gl_image.c` `GL_LoadWal`, struct `miptex_t` in `qcommon/qfiles.h`): the world texture format. Header carries `name[32]`, `width`, `height`, `offsets[4]` (four baked mip levels, mip 0 at `offsets[0]` is all the stock GL renderer reads), `animname[32]` (next frame of a texture animation chain), `flags`, `contents`, `value` (light strength for `SURF_LIGHT`). Pixels are 8-bit indexes into the global palette. Paths are `textures/<name>.wal`.
- PCX (`gl_image.c` `LoadPCX`, struct `pcx_t` in `qfiles.h`): 8-bit paletted, run-length encoded, palette = last 768 bytes of the file. Used for `pics/` (menus/HUD, `it_pic`), `conchars.pcx` (console font, 8x8 cells, unfiltered), model skins (`it_skin`), and `env/` sky boxes (`it_sky`). The stock loader rejects anything with `xmax >= 640` or `ymax >= 480` and requires manufacturer 0x0a / version 5 / encoding 1 / 8bpp.
- TGA (`gl_image.c` `LoadTGA`, screenshots in `ref_gl/gl_rmisc.c` `GL_ScreenShot_f`): type 2/10, 24/32-bit. Only screenshots and replacement content; stb already covers it.
- `pics/colormap.pcx` (`gl_image.c` `Draw_GetPalette`): the global 256-color palette (`d_8to24table`), index 255 transparent. Every 8-bit asset (WAL, PCX, skins) depends on it; base Q2 content cannot render without it. `pics/16to8.dat` is a 3dfx paletted-texture lookup table, dead hardware path, ignorable.
- Skin flood fill (`gl_image.c` `R_FloodFillSkin`): fills the skin background color so mipmaps do not get halos; cosmetic but stock-visible on player skins if skipped.
- Sky (`ref_gl/gl_warp.c` `R_SetSky`): six independent images `env/<name><rt|bk|lf|ft|up|dn>.pcx` (or `.tga`), no cubemap file, rotation/axis come from the map's `sky` spawn.

### 2.3 Gap analysis

Missing, in load order:

1. PCX loader (8-bit paletted + palette extraction). Port from `LoadPCX` (GPLv2+, attribution note in the port commit) or an independent decoder. Relax the 640x480 rejection to a warning for oversized mod content.
2. `pics/colormap.pcx` palette load (needed by 2 and 3; index 255 -> alpha 0).
3. WAL loader: decode 8-bit -> RGBA through the palette at load time. The baked mip levels can be ignored (mip 0 only); `flags`/`contents`/`value`/`animname` feed the implicit material (section 3).
4. Pics as materials: Q2 UI references pics by bare name with `pics/` and `.pcx` implied (`ref_gl/gl_draw.c` `Draw_FindPic`); D3 GUIs need material decls. The implicit material generation (same mechanism as the Q3 `implicitMap` work) should synthesize a material for `pics/<name>.pcx` once `.pcx` is a known image extension. `conchars.pcx` is replaceable by an `idFont` or a dedicated unfiltered material.
5. Sky adapter: `R_LoadCubeImages` hardcodes `.tga` and the D3/Q3 suffixes; Q2 skies are six `.pcx` files with `rt/bk/lf/ft/up/dn` suffixes. Either a Q2 suffix adapter feeding the cubemap path, or a synthetic skysphere material (same decision as the Q3 `skyparms` gap).
6. Skin flood fill: optional port of `R_FloodFillSkin` if skins show mip halo artifacts.

No new upload/render machinery is needed anywhere: the engine takes RGBA and does its own mipmapping.

## 3. Surface/material semantics (this is Q2's replacement for the Q3 shader gap)

Q2 has no shader files. Where Q3 put appearance into `scripts/*.shader`, Q2 puts it into data headers:

- The WAL header (`miptex_t.flags/contents/value/animname`).
- BSP `texinfo` entries (`flags` + `value` overrides, `nexttexinfo` chains for animated surfaces, `references/quake2/ref_gl/gl_model.c` `Mod_LoadTexinfo`).
- The flag set (`qcommon/qfiles.h`): `SURF_LIGHT` 0x1 (`value` = light strength), `SURF_SLICK` 0x2, `SURF_SKY` 0x4, `SURF_WARP` 0x8, `SURF_TRANS33` 0x10, `SURF_TRANS66` 0x20, `SURF_FLOWING` 0x40, `SURF_NODRAW` 0x80, plus the `CONTENTS_*` set (solid/window/lava/slime/water/mist/ladder/currents/...).

Mapping onto the existing material machinery (adapter work, no new systems beyond the flag translation itself):

| Q2 data | Doom 3 equivalent | Notes |
|---|---|---|
| `SURF_TRANS33` / `SURF_TRANS66` | `blend` + alpha (0.33/0.66) | translucent stage in the implicit material |
| `SURF_WARP` | `deform turbulent` / water material | Q2 warps texcoords; D3 deforms verts, visually close |
| `SURF_SKY` | sky material + section 2.3 item 5 | |
| `SURF_FLOWING` | `translate` stage (scroll) | |
| `SURF_NODRAW` | `nodraw` | |
| `SURF_LIGHT` + `value` | none | parse and ignore; surface lights need entities (conversion-time or game side) |
| `CONTENTS_*` | infoParms | contents bits also feed game collision; needs a Q2 flag table like the Q3 `surfaceparm` work |
| `animname` / `nexttexinfo` | `animMap`-style stage animation | the Q3 animMap stage covers the mechanism |
| palette index 255 | alphaTest / coverage | from the palette decode |

Where Q3 needed a legacy parser, Q2 needs a generator: the implicit material for a WAL texture is derived from these flags at image-load/decl time.

## 4. Model formats

### 4.1 What loads today

Dispatch in `neo/renderer/ModelManager.cpp` (`GetModel`, lines ~314-330): `ase`/`lwo`/`flt`/`ma` (static source formats), `md3`, `mdc`, `mds`, `mdm`, `md4`, `prt`, `liquid`, world `.proc`/`.bmodel`; MD5 handled separately (`MD5_MESH_EXT`). No MD2, no SP2.

### 4.2 What Q2 uses

- MD2 (`references/quake2/ref_gl/gl_model.c` `Mod_LoadAliasModel`, draw code in `ref_gl/gl_mesh.c`): `IDP2` version 8 (`dmdl_t` in `qfiles.h`). Up to 32 skins (`.pcx` names), `skinwidth`/`skinheight`, an ST array (`dstvert_t`), triangle lists (`dtriangle_t` with `index_xyz`/`index_st`), a strip/fan `glcmds` list, and frames of `daliasframe_t` (per-frame `scale[3]`/`translate[3]`/`name[16]` plus `dtrivertx_t { byte v[3]; byte lightnormalindex; }` verts). Normals come from the 162-entry `anorms.h` table.
- SP2 (`gl_model.c` `Mod_LoadSpriteModel`): `IDS2` version 2, frames of `{ width, height, origin_x, origin_y, pcx name }`; the renderer just binds the frame's image as a billboard.

### 4.3 The gap

Both loaders are missing. Implementation notes:

- MD2 can ride the MD3 parity machinery: two-frame vertex lerp through the `SHADERPARM_MD3_*` frame channel, per-frame bounds (`translate .. translate + scale*255`), skins resolved through `FindMaterial` by the skin name once `.pcx` materials exist (section 2.3 item 4), `glcmds` ignorable (rebuild triangles from `index_st` + `index_xyz`), `lightnormalindex` -> `anorms` table -> normals, tangents derived like the MD3 fix (`R_DeriveTangentsWithoutNormals`). MD2 has no tags; Q2's game code offsets weapon/screen models by frame hardcoding, so nothing renderer-side is needed for that.
- SP2 is trivial: synthesize a per-frame two-triangle quad (or particle-style) model honoring `origin_x`/`origin_y`, with the frame channel for animation. Only a few game entities use sprites.

## 5. Map format (BSP v38) - flagged, coupled to the lighting decision

The engine has no BSP loader at all (world geometry is `.proc`/`.bmodel` only), same situation as the Q3 inventory. Q2 maps are `IBSP` version 38 with 19 lumps (`qcommon/qfiles.h`):

- `LUMP_TEXINFO` references `textures/<name>.wal` by name plus flags/`nexttexinfo` (section 3).
- `LUMP_LIGHTING` lightmaps: up to 4 light styles per face, `lightofs` samples; the same lightmap/lighting-provider coupling flagged in `quake3-inventory.md` section 1.3C applies verbatim - without a lighting provider these can only be approximated (white/identity) with a documented visual difference.
- `LUMP_VISIBILITY` PVS/PHS; brushes/brushsides/leafs/areas feed the collision model (`references/quake2/qcommon/cmodel.c`), game side.
- Warp/sky/flowing/translucent surface behaviors come from the texinfo flags (section 3).

Decision needed, same as Q3: a Q2 BSP loader in the renderer, or an offline converter to `.proc`/`.bmodel` + generated materials (the converter can piggyback entirely on sections 2-3 without touching the renderer). Either way it is the single largest item.

## 6. Video (.cin)

- Engine today: `idCinematic::InitFromFile` (`neo/renderer/Cinematic.cpp`, lines ~64-70) dispatches `.bik` to Bink and `.roq` to `idCinematicRoQ`.
- Q2 `.cin` (`references/quake2/client/cl_cin.c`) is NOT RoQ. It is a 14 fps 8-bit paletted format: a five-int header (`width`, `height`, `s_rate`, `s_width`, `s_channels`), then per frame a command word (2 = end, 1 = a 256-color palette chunk follows), a size-prefixed order-1 Huffman block (`Huff1Decompress`, per-file codebook) decoding the full frame, and raw interleaved audio samples for the frame at `s_rate/14`.
- Gap: `idCinematicRoQ` cannot read it - different container and different codec. Options: a dedicated `idCinematic` subclass (the Q2 decoder is ~300 lines in `cl_cin.c`, GPLv2+, portable), or offline conversion to `.roq`/`.bik`. Q2's intro/endgame videos are `.cin`.

## 7. Sound

Q2 uses plain RIFF `.wav` (`references/quake2/client/snd_mem.c`; 8/16-bit, mono/stereo). The engine loads wav already. Nothing missing. (Ogg music is a third-party addition, not base Q2.)

## 8. What already works

- `.pak` archives (since `3df000b`: `idPackContainer` mounts them alongside `.pk4`/`.pk3`).
- TGA images (stb), including Q2 replacement tgas.
- WAV sound.
- Loose-directory content: `baseq2` as an `fs_game` directory needs no filesystem change (same as `etmain` in the Q3 work).
- Case-insensitive path lookups already match Q2 semantics.
- `.dm2` demos, savegames, `.cfg`: out of scope (game module), listed for completeness.

## 9. Recommended implementation order

1. `.pak` container - DONE in `3df000b` (`idPackContainer`). All base Q2 data in `pak0.pak` is now reachable.
2. PCX + WAL loaders + `colormap.pcx` palette (section 2).
3. Implicit materials from WAL flags/animname + Q2 flag tables (section 3).
4. MD2 (+SP2) through the MD3 path machinery (section 4).
5. `.cin` player (section 6).
6. BSP v38 decision (loader vs offline converter), coupled to the Q3 lightmap provider decision (section 5).

## Licensing note

`references/quake2` is id's 3.21 source release with GPLv2-or-later headers (`gnu.txt` in that directory); porting loaders from it (pak, PCX, WAL, MD2, cin) into this GPLv3 engine is license-compatible. Keep the original copyright headers on ported files and note the origin in the port commits.

## Sources

All in this repository:

- `references/quake2/qcommon/files.c` - pak format, search path, mounting, checksum
- `references/quake2/qcommon/qfiles.h` - pak/PCX/MD2/SP2/WAL/BSP structures and flag sets
- `references/quake2/ref_gl/gl_image.c` - LoadPCX, LoadTGA, GL_LoadWal, colormap palette, flood fill
- `references/quake2/ref_gl/gl_draw.c` - pics lookup convention, conchars
- `references/quake2/ref_gl/gl_rmisc.c` - TGA screenshots
- `references/quake2/ref_gl/gl_model.c` - MD2/SP2/BSP loaders, texinfo handling
- `references/quake2/ref_gl/gl_mesh.c` - MD2 draw path, anorms table
- `references/quake2/ref_gl/gl_warp.c` - sky env boxes
- `references/quake2/client/cl_cin.c` - .cin container and codec
- `neo/framework/FileSystem.cpp`, `neo/renderer/Image_files.cpp`, `neo/renderer/ModelManager.cpp`, `neo/renderer/Cinematic.cpp` - engine side, audited at head
