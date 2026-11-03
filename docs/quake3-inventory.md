# Quake 3 / Wolfenstein: Enemy Territory content support inventory

Audited at commit `0c79836747bc850e93e3bfda8f5a4213d36924e5` (master) on 2026-11-02. Updated 2026-11-02: the MD3 parity work landed (`81dc731`) and MDC/MDS/MDM/MDX/MD4 loaders were added, see sections 2.1-2.3. Updated 2026-11-03: PK3 archive mounting and the Team Arena/ET menu (.menu) GUI format audited, see sections 4-5 and steps 8-9.

Purpose: gap analysis before implementing Q3/ET content support. Two areas as requested: shader (material) syntax and model formats. The engine side was read directly from this repo (`neo/renderer/Material.cpp`, `neo/renderer/Model_md3.cpp`, `neo/renderer/ModelManager.cpp`, `neo/framework/DeclManager.cpp`, `neo/renderer/Image_files.cpp`). The Q3/ET requirement side is taken from the ET: Legacy renderer sources (GPLv3, `src/renderer/tr_shader.c` and `src/renderer/tr_model.c`) and published format references.

Out of scope: Q3 BSP map format, game logic, sound, networking. Some shader features are coupled to map data (lightmaps, lightgrid, fog); those couplings are flagged.

## 1. Shader syntax

### 1.1 What the engine has today

- Materials load from decls in `materials/*.mtr` (`neo/framework/DeclManager.cpp`: `RegisterDeclFolder("materials", ".mtr", DECL_MATERIAL)`) and from `scripts/*.shader` through the legacy Q3 parser (`RegisterDeclFolder("scripts", ".shader", DECL_MATERIAL)`, dispatched by file extension in `idMaterial::Parse`).
- `idMaterial::Parse` (`neo/renderer/Material.cpp`) parses Doom 3 syntax for `.mtr` sources and legacy Q3 syntax for `.shader` sources (`ParseLegacyMaterial`). Doom 3 unknown tokens still set `MF_DEFAULTED`; the legacy parser warns and skips the line instead.
- `qer_editorimage` is honored by both parsers (`editorImageName`).
- The `infoParms` table maps Doom 3 content/surface flags (`solid`, `water`, `slick`, `ladder`, `metal`, ...). The Q3/ET `SURF_*` / `CONTENTS_*` flag set is different.
- Stage machinery that exists and is useful: `blend` with the same `GL_*` enum names as Q3, `alphaTest`, `texGen reflect/skybox/wobbleSky/normal`, `translate/scale/centerScale/shear/rotate`, `vertexColor/inverseVertexColor`, color registers (`color/red/green/blue/alpha/rgb/rgba`), `maskDepth`, `videomap`, `nopicmip`, `clamp` variants, `if` conditionals, float expressions with `time`, `parm0-11`, `global0-7` and tables (`sinTable`, `cosTable`).
- Images load through stb_image: tga, bmp, png, jpg (`neo/renderer/Image_files.cpp`). Q3-era textures (.tga/.jpg) already load fine. No PCX/WAL (not needed for ET).

### 1.2 What Q3/ET shader files are

`scripts/*.shader` files contain many shaders each, with no type keyword prefix:

```
textures/common/caulk
{
    surfaceparm nodraw
    ...
    {
        map $lightmap
        rgbGen identity
    }
}
```

Loader note: `idDeclFile::LoadAndParse` supports typeless decls through a folder's default decl type (it falls back to `defaultType` when the first token is not a registered type name), so `scripts/*.shader` is registered with `RegisterDeclFolder("scripts", ".shader", DECL_MATERIAL)` and the scanner picks up every `textures/... { ... }` block as a material decl. `idMaterial::Parse` detects the `.shader` source file and runs the legacy Q3 parser (`ParseLegacyMaterial`) instead of the Doom 3 one.

Verified runtime keyword set from ET: Legacy `tr_shader.c` (these are the runtime-relevant ones; `qer_*`, most `q3map_*`, `tesssize` and `light <value>` are parsed and ignored):

- General: `cull` (front | back | backside | backsided | none | twosided | disable), `deformVertexes` (wave | normal | bulge | move | autosprite | autosprite2 | text | projectionShadow), `clampTime`, `surfaceParm`, `nomipmaps`/`nomipmap`, `nopicmip`, `polygonOffset`, `entityMergable`, `fogParms`, `portal`, `skyparms`, `sunshader`, `lightgridmulamb`, `lightgridmuldir`, `fogvars`, `skyfogvars`, `waterfogvars`, `nofog`, `allowcompress`/`nocompress`, `distancecull`, `sort` (portal | sky | opaque | decal | seeThrough | banner | additive | nearest | underwater | number), `implicitMap`/`implicitBlend`/`implicitMask`, `q3map_sun`/`q3map_sunExt` (feeds the sun flare).
- Stage: `map` (+ `$whiteimage`/`*white`, `$lightmap`, `$dlight`), `clampmap`, `animMap`, `videoMap`, `alphaFunc` (GT0 | LT128 | GE128), `depthfunc` (lequal | equal), `depthwrite`, `detail`, `fog` (on), `blendfunc` (add | filter | blend | `GL_SRC, GL_DST` pairs), `rgbGen` (identity | identityLighting | wave | const | entity | oneMinusEntity | vertex | exactVertex | lightingDiffuse | oneMinusVertex), `alphaGen` (wave | const | identity | entity | oneMinusEntity | vertex | normalzfade | portal | lightingSpecular), `tcGen` (texture/base | environment | lightmap | vector), `tcMod` (rotate | scroll | scale | offset | transform | turb | stretch | swap | entityTranslate).
- Obsolete variants present in ET files: `map16`/`map32`/`mapcomp`/`mapnocomp`/`animmapcomp`/`animmapnocomp` (16/32-bit and compression selection).
- Waveforms (base, amplitude, phase, frequency): sin, square, triangle, sawtooth, inversesawtooth, noise.

### 1.3 Gap analysis

#### A. Direct equivalents, adapter-level work

| Q3/ET keyword | Existing Doom 3 equivalent | Notes |
|---|---|---|
| `cull none/twosided/disable` | `twoSided` | D3 twoSided also forces noShadows; fine for us |
| `cull back/backside/backsided` | `backSided` | |
| `cull front` | default | |
| `polygonOffset` | `polygonOffset` | D3 takes an optional float offset |
| `nopicmip` | `nopicmip` | Q3 is per-shader, D3 per-stage; promote or apply to all stages |
| `blendfunc add/blend/filter` | `blend add/blend/filter` | identical results |
| `blendfunc GL_SRC, GL_DST` | `blend GL_SRC, GL_DST` | same GL_ enum names already parsed |
| `alphaFunc GT0/LT128/GE128` | `alphaTest <expr>` | sets coverage MC_PERFORATED, same machinery |
| `clampmap` | `map` + `clamp` | |
| `depthwrite` | `maskDepth` (off) | check D3 default depth semantics per sort |
| `depthfunc equal` | `GLS_DEPTHFUNC_EQUAL` exists in drawStateBits | needs a stage keyword to set it |
| `tcGen environment` | `texGen reflect` | |
| `tcMod scroll` | `translate` | |
| `tcMod scale` | `scale` | |
| `tcMod rotate` | `rotate` | |
| `tcMod stretch` | `centerScale` + table expression | dynamic per-time scale, expressible with expressions+tables |
| `deformVertexes autosprite` | `deform sprite` | |
| `videoMap` | `videomap` | RoQ supported (Bink too) |
| `nofog` | `noFog` | |
| `rgbGen const (r g b)` | `color` | |
| `qer_*`, `q3map_*`, `tesssize`, `light <n>`, `entityMergable` | none | parse and ignore |
| `implicitMap/implicitBlend/implicitMask` | implicit material generation | D3 already auto-generates implicit materials from image names; needs the three state-bit variants |

#### B. Needs new parser support, but no new systems

- `animMap <fps> <images>`: no frame-animated texture stages in D3. Needs a new textureStage field (frame list + fps) and time-based selection in the texture commit.
- `tcGen vector`, `tcMod transform/offset/swap`: D3 has a 2x3 expression texture matrix, so transform/offset/swap are expressible; `tcGen vector` needs a new texgen.
- `tcMod entityTranslate`: per-entity texcoord offset; new mechanism (needs entity data in the texture matrix evaluation).
- `tcMod turb`: per-vertex texcoord turbulence; no equivalent, new code.
- `rgbGen wave` / `alphaGen wave` with all six waveforms: color registers + expressions cover it, but only sinTable/cosTable ship. Add square/triangle/sawtooth/inversesawtooth/noise as tables (or expression ops).
- `rgbGen entity/oneMinusEntity`, `alphaGen entity/oneMinusEntity`: D3 `colored` uses parm0-3; entity color needs a mapping from the future game's entity color channel to shaderParms (game-side glue).
- `rgbGen vertex/oneMinusVertex`, `alphaGen vertex`: `vertexColor`/`inverseVertexColor` exist; the Q3 semantics feed precomputed vertex lighting, see C.
- `alphaGen normalzfade`, `alphaGen portal`, `alphaGen lightingSpecular`: no equivalents; new code if needed (all three are rare outside RtCW foliage/effects).
- `deformVertexes wave/normal/bulge/move/text/autosprite2/projectionShadow`: D3 deforms (expand/move/turbulent/flare/tube/eyeBall/particle) do not match one-to-one. `move` is close to DFRM_MOVE but Q3 takes an arbitrary direction and a wave. New deform code, or approximate and ignore the rest.
- `clampTime`, `distancecull`, `sort <named>`: parse and map. Q3 named sort values need a mapping table onto the D3 sort scale.
- `map16/map32/mapcomp/mapnocomp` + `allowcompress/nocompress`: 16/32-bit selection is obsolete; compression control can map to image options or be ignored.
- `skyparms <farbox> <cloudheight> <nearbox>`: the farbox is a cubeMap skybox (Q3 skybox naming `_up/_dn/_lf/_rt/_ft/_bk` differs from D3 cube file naming), and the cloud layer is a scrolling texture stage over the sky. Needs a small sky-stage pipeline; closest existing pieces are `texGen skybox` and `wobbleSky`.

#### C. Needs new systems (not just syntax)

- `$lightmap`, `tcGen lightmap`, `rgbGen vertex/exactVertex/lightingDiffuse`: Q3 surfaces are lit by BSP lightmaps plus vertex lighting from the map lightgrid. This engine has neither. This is the single largest shader gap, and it is coupled to the map format decision (a Q3 BSP loader or a content conversion path). Until a lighting provider exists, these keywords can only be approximated (for example: lightmap stages as white/identity, vertex lighting as fullbright) with a documented visual difference.
- `$dlight`: merged dynamic light texture from the Q3 renderer. D3BFG draws per-light interactions instead; no equivalent by design. Substitute a neutral image.
- `fogParms` + `fogvars/skyfogvars/waterfogvars`: Q3 global distance fog with farclip control. D3 fog is per-fog-light. Needs a global fog system (fullscreen/depth pass or per-zone fog parameters).
- `sunshader` + `q3map_sun`/`q3map_sunExt`: sun flare rendering; needs a flare system.
- `lightgridmulamb`/`lightgridmuldir`: lightgrid multipliers; N/A until lightgrid exists.
- `identityLighting`: Q3 multiplies by identityLight (r_overBrightBits); D3BFG has its own gamma/tone pipeline. A convention decision, otherwise lighting differs subtly on every shader.
- `surfaceparm`: for rendering only `nodraw`, `nomarks`, `noimpact`, `trans` matter; the rest are gameplay/collision flags consumed by the game module (ladder, metalsteps, playerclip, ...). Parse them into the existing infoParms mechanism with a Q3 flag mapping, or park them for the game side.

#### D. Name/canonicalization notes

- Q3 shader names are extension-less paths (`textures/common/caulk`); the decl manager canonicalizes names by lowercasing and truncating at the last dot (`MakeNameCanonical` in DeclManager.cpp). Typical Q3 names are unaffected; names containing dots get truncated.
- Q3 looks shaders up by texture name with the extension stripped (game-side); out of scope here but noted for the future game module.

## 2. Model format support

### 2.1 What loads today

Dispatch in `neo/renderer/ModelManager.cpp` (`GetModel`):

| Extension | Handler |
|---|---|
| `.ase`, `.lwo`, `.flt`, `.ma` | `idRenderModelStatic` (source formats) |
| `.md5mesh` | `idRenderModelMD5` (skeletal) |
| `.md3` | `idRenderModelMD3` |
| `.mdc` | `idRenderModelMDC` (decodes to MD3 layout at load, shares the MD3 path) |
| `.mds` | `idRenderModelMDS` (skeletal) |
| `.mdm` | `idRenderModelMDM` (skeletal; loads the sibling `.mdx`) |
| `.md4` | `idRenderModelMD4` (skeletal, kept for completion) |
| `.prt` | particle |
| `.liquid` | liquid |
| world `.proc`/`.bmodel` | RenderWorld static geometry |

Nothing else dispatches anywhere. There is no Q3 BSP (`MOD_BRUSH`) path.

### 2.2 MD3 audit (`neo/renderer/Model_md3.cpp/.h`)

Fixed with the Q3 parity work (commit `81dc731`), all items below now work:

- Full header/frame/tag/surface byte-swapping and validation (version 15, `SHADER_MAX_VERTEXES` 1000 guard).
- Surface shader registration through `declManager->FindMaterial` (Q3 shader names resolve once Q3 materials parse).
- Two-frame vertex lerp driven by `shaderParms`: `SHADERPARM_MD3_FRAME`, `SHADERPARM_MD3_LASTFRAME`, `SHADERPARM_MD3_BACKLERP`.
- Surface name lowercasing plus the trailing `_1`/`_2` strip (same Q3 crutch).
- Lat-long normals are decoded and tangents derived (`R_DeriveTangentsWithoutNormals`), so interaction lighting works.
- Tags are exposed as joints with a lerped tag query API (`GetJointHandle`/`GetJointTransform`), the game-facing equivalent of ET `R_LerpTag`.
- `Bounds()` returns the lerped per-frame bounds like ET `R_ModelBounds`.
- LOD: `_1`/`_2`/`_3` extension variants load (`MD3_MAX_LODS` 4, `r_md3lodscale`/`r_md3lodbias`), selected per view like Q3 `R_ComputeLOD`.

Still missing for Q3/ET use:

1. No Q3 skin remap (see 2.4).

### 2.3 Model formats

All Q3-era model formats are implemented (the port adds `Model_mdc.cpp/.h`, a shared `Model_wolf.cpp/.h` base and one file pair per format: `Model_mds`, `Model_mdm`, `Model_md4`):

- MDC: compressed MD3 variant from RtCW (`idRenderModelMDC` in `neo/renderer/Model_mdc.cpp`). The compressed frames (per-axis deltas plus an anorms256 normal index, per-frame base/comp tables) and the short-packed tags are decoded at load time into a synthesized MD3 layout, so the entire MD3 path (instantiate, LOD chain via the `LoadHeader`/`LodFileExtension` hooks, tags as joints, per-frame bounds) is shared unchanged.
- MDS: RtCW/ET skeletal format, single file with bones, compressed bone frames, weighted surfaces and bone-attached tags (`idRenderModelMDS` in `neo/renderer/Model_mds.cpp`).
- MDM + MDX: RtCW split skeletal pair, `.mdm` mesh and tags plus the sibling `.mdx` skeleton/frames (`idRenderModelMDM` in `neo/renderer/Model_mdm.cpp`, the `.mdx` is loaded by replacing the extension).
- MD4: the early Q3-era skeletal format, kept for completion sake (`idRenderModelMD4` in `neo/renderer/Model_md4.cpp`). Only the on-disk structures survive in the ET SDK headers; the decode follows the Q3 3x4 matrix convention (rotation rows with translation in the last column). No known content uses it.
- External `.tag` files (RtCW skeletal attachments): still not loaded; only relevant alongside MDM.
- `.shadow` scripts (ET per-model projection shadow shader + six floats): only relevant if a projection shadow path is added; our shadow roadmap is shadowmap-based, so likely never.
- MD2, MDR: not ET formats, not needed.

Skeletal implementation notes (MDS/MDM/MDX/MD4): the pipeline is modeled on the Doom 3 MD5 loader. Surfaces become `deformInfo_t` meshes with the four largest weights folded into the vertex colors, so the GPU skinning path (`jointsInverted` + `staticModelWithJoints`) works without a game-side animator. Rendering falls back to the file frames (MD3-style `shaderParms` frame channel) when the renderEntity carries no matching joints, so bind-pose and shaderParms-driven playback work out of the box. Torso blending (torsoParent/torsoWeight split) is not applied; with a single frame channel it is a no-op anyway. Bone angles are stored as absolute SHORT2ANGLE eulers, translations as parentDist along a pitch/yaw direction from the parent, matching the ET runtime decode (`R_CalcBone`); the ET and Doom 3 angle conventions turned out to be identical (`AnglesToAxis` == `idAngles::ToMat3`).

Licensing note: reference implementations for MD3/MDC/MDS/MDM/MDX live in the ET: Legacy repository and the vendored WET SDK (`references/etwolf`, GPLv3, like this engine). Porting between the two is license-compatible; keep the attribution headers and note the origin in the port commits.

### 2.4 Skins

- Q3/ET: `scripts/*.skin` text files. One skin is a list of `surface,texture` lines (player-model surface to replacement texture/shader), used for team skins and model variants.
- D3: `idDeclSkin` decls in `skins/*.skin` with syntax `skin <name> { <model> : <old> = <new> }`, keyed by material name rather than surface name.
- Gap: a Q3 skin parser plus a remap hook in the MD3/MDC instantiate path, keyed on md3 surface names (which the loader already lowercases for exactly this purpose). The current `idRenderModelMD3` ignores skins entirely.

### 2.5 Animation/game glue (out of renderer, listed for completeness)

- ET players animate through game code: `animation.cfg`, `frame`/`oldframe`/`backlerp` on the render entity, three-part lower/upper/head model hierarchy connected by tags.
- The shaderParms frame channel of the MD3 path is the equivalent hook; a future game module can drive it without renderer changes once tags are exposed (2.2 item 2).

## 3. Recommended implementation order

1. ~~MD3 loader fixes~~ Done (`81dc731`): normal decode + tangent derivation, per-frame bounds, tag exposure with a lerped tag query API, LOD chain.
2. ~~Q3 shader parsing~~ Done: `scripts/*.shader` registered as a material decl folder (`DeclManager.cpp`), `idMaterial::Parse` dispatches to `ParseLegacyMaterial` for `.shader` sources. Implemented: group A keywords (blend/texgen/tcGen/tcMod/rgbGen/alphaGen/alphaFunc/depthFunc/depthWrite/animMap/clamp/cull/sort/polygonOffset/nopicmip-per-shader/deformVertexes autosprite/surfaceparm/implicit*), waveform ops (`sin/square/triangle/sawtooth/inverse_sawtooth/noise` as register ops), `$lightmap`→`_white`, `$dlight`→`_black`. Parsed and ignored: editor/compile keywords (`qer_*`, `q3map_*`, `tesssize`, `light <n>`, `entityMergable`, `nomipmaps`, `allowcompress`/`nocompress`, `clampTime`, `distancecull`). Warn and skip line on everything else (no `MF_DEFAULTED`).
3. ~~MDC loader~~ Done (shares the fixed MD3 path through the `LoadHeader`/`LodFileExtension` hooks).
4. Q3 skin parser + remap hook.
5. Lighting provider decision for `$lightmap`/lightgrid keywords (coupled to the map format decision).
6. Global fog system, `skyparms` sky stage, sun flare.
7. ~~MDS/MDM/MDX~~ Done (plus MD4 for completion).
8. PK3 mounting. In practice a prerequisite for 4-6: ET content (skins included) ships inside pk3 archives, and everything registered so far only reads loose files. The change itself is one enumeration line in `AddSearchPath`, details in section 4.
9. Legacy .menu GUI parser (Team Arena/RTCW/ET menu format onto the Doom 3 window system). Start with the static keyword subset and a warn-and-skip pass, phase ownerdraw/feeder support until a UI/game module exists, details in section 5.

## 4. Package archives (pk3)

### 4.1 What the engine has today

- Full zip container support already exists in this fork: `idZipContainer`/`idZipCacheEntry` (`neo/framework/File_Zip.h/.cpp`, built on the vendored minizip, explicitly based off `idResourceContainer` and dhewm3). Each `searchpath_t` (`neo/framework/FileSystem.cpp`) carries both `.resources` containers and a list of zip containers (`zipFiles`).
- Mounting happens in `idFileSystemLocal::AddSearchPath` (FileSystem.cpp, the `.resources`/`.pk4` scan): each game dir root is enumerated, the pak lists are sorted alphabetically and every archive becomes a container in that search path.
- Lookup (`GetZipCacheEntry`) lowercases the requested relative path and compares case-insensitively through a per-container hash, walking search paths and containers last-to-first, so the alphabetically-last pak wins - the same override rule Q3 uses.
- Open and enumerate both work from containers: `OpenFileReadFlags` resolves through zip containers, and `GetFileList` (behind `ListFiles`/`ListFilesTree`) iterates zip cache tables, so decl folder registration, image loading and model loading already see files inside mounted paks with no extra work.
- Loose file vs pak priority is the `fs_resourceLoadPriority` cvar (0 = loose dirs win, 1 = paks win before dirs).
- Search path set: `fs_game`, `fs_game_base`, then `BASE_GAMEDIR` ("base"). ET's `etmain` would simply be an `fs_game` directory.

### 4.2 What pk3 files are

- Plain zip archives. Byte-identical in format to pk4 as far as the container code is concerned; entries are lowercase relative paths (`scripts/`, `textures/`, `models/`, `sound/`, `ui/`, `maps/`).
- Q3 semantics: paks live in the game dir (`etmain` or a mod dir), later-alphabetical paks override earlier ones, checksums exist for pure/server verification (not needed for local content support).

### 4.3 The gap (small)

- Exactly one enumeration short: `AddSearchPath` scans only `.pk4` (`ListOSFiles( pakfile, ".pk4", pakfiles )`). Adding a `.pk3` pass and merging both lists before the alphabetical sort mounts Q3/ET paks with no new container, lookup or listing code; update the `...Loaded pk4 file` log line to cover both.
- Keep pk3 and pk4 in one sorted list so the override order stays well defined across both extensions.
- Mixed-case entries inside old paks still resolve (the lookup lowercases the query and compares with `Icmp`). The container checksum is only used for logging; no pure checks.
- If `.resources` files exist in the same game dir they load as well; `fs_resourceLoadPriority` decides which wins per file.

## 5. Legacy menu GUIs (Team Arena / RTCW / ET .menu to Doom 3 windows)

### 5.1 What the engine has today

- The full idTech4 UI system in `neo/ui`: `idUserInterfaceManagerLocal` (`UserInterface.cpp`, `FindGui` loads .gui sources, plus optional binary gui caching through `binaryLoadGuis`), the `idWindow` hierarchy (`Window.cpp`), dict-backed window variables (`Winvar.h`, "gui::" state), gui scripting (`GuiScript.cpp`) and typed windows: `EditWindow`, `ChoiceWindow`, `SliderWindow`, `ListWindow` (+`ListGUI`), `BindWindow`, `FieldWindow`, `RenderWindow`, `SimpleWindow`. Text draws through `idFont` (`renderSystem->RegisterFont`); images draw through material decls.
- Window register vars (`idWindow::RegisterVars`, Window.cpp): `rect`, `forecolor`, `hovercolor`, `backcolor`, `bordercolor`, `matcolor`, `text`, `textscale`, `visible`, `background` (material decl name), `cvar`, `choices`/`choiceVar`, `bind`, `rotate`, `translate`, `scale`, `noevents`, `hideCursor`, ...
- Window event scripts (`idWindow::ScriptNames`): `onMouseEnter`, `onMouseExit`, `onAction`, `onActivate`, `onDeactivate`, `onESC`, `onEvent`, `onTrigger`, `onActionRelease`, `onEnter`, `onEnterRelease`.
- Gui script commands (`GuiScript.cpp` `commandList`): `set`, `setFocus`, `endGame`, `resetTime`, `showCursor`, `resetCinematics`, `transition`, `localSound`, `runScript`, `evalRegs`, plus if/else blocks. `set` with destination name `cmd` queues console commands; `set` can address any window's variables by name.
- Coordinate space: windows default to a 640x480 forced aspect (`forceAspectWidth`/`forceAspectHeight`), the same virtual resolution TA/ET menus are authored against (ET `AdjustFrom640`).
- Game-side menu flow (`neo/framework/Common_menu.cpp`, `Session.cpp`) drives named guis; cvars and console commands are first-class through the gui dict and the `cmd` path.

### 5.2 What the .menu format is

The Team Arena menu script format, carried unchanged through RTCW and W:ET. Reference sources are vendored in this repo under `references/etwolf` (GPLv3, license-compatible).

- Layout: `ui/menus.txt` (cvar `ui_menuFiles`) lists .menu files; `UI_LoadMenus` (ui_main.c) parses each through the engine script preprocessor; `Menu_Parse`/`Item_Parse` (ui_shared.c) fill `menuDef_t`/`itemDef_t` (structs in ui_shared.h, constants in etmain/ui/menudef.h).
- menuDef keywords (ui_shared.c `menuParseKeywords`): name, fullscreen, rect, style, visible, onOpen, onClose, onTimeout, onESC, onEnter, border, borderSize, backcolor, forecolor, bordercolor, focuscolor, disablecolor, outlinecolor, background, ownerdraw, ownerdrawFlag, outOfBoundsClick, soundLoop, cinematic, fadeClamp, fadeCycle, fadeAmount, execKey, execKeyInt, alwaysontop, modal, itemHotkeyMode.
- itemDef keywords (ui_shared.c `itemParseKeywords`, ~75): accept, action, addColorRange, addColorRangeRel, align, asset_model, asset_shader, autowrapped, backcolor, background, border, bordercolor, bordersize, cinematic, columns, contextmenu, cvar, cvarFloat, cvarFloatList, cvarStrList, cvarListUndefined, cvarTest, decoration, textasint, textasfloat, disableCvar, doubleclick, onEsc, onEnter, elementheight, elementtype, elementwidth, enableCvar, execKey, feeder, focusSound, forecolor, group, hideCvar, horizontalscroll, leaveFocus, maxChars, maxPaintChars, model_angle, model_animplay, model_fovx, model_fovy, model_origin, model_rotation, mouseEnter, mouseEnterText, mouseExit, mouseExitText, name, noToggle, notselectable, onFocus, origin, outlinecolor, ownerdraw, ownerdrawFlag, rect, settingDisabled, settingEnabled, showCvar, special, style, text, textalign, textalignx, textaligny, textfile, textfont, textscale, textstyle, tooltip, tooltipalignx, tooltipaligny, type, visible, voteFlag, wrapped.
- Item types (menudef.h `ITEM_TYPE_*`): text, button, radiobutton, checkbox, editfield, combo, listbox, model, ownerdraw, numericfield, slider, yesno, multi, bind, menumodel, timeout_counter, tricheckbox.
- Item/menu scripts run through `Item_RunScript` (ui_shared.c `commandList`): fadein, fadeout, show, hide, setcolor, open, fadeinmenu, fadeoutmenu, conditionalscript, conditionalsopen, close, closeall, closeallothermenus, clipboard, showpage, setasset, setbackground, setitemcolor, setmenuitemcolor, setteamcolor, setfocus, clearfocus, setplayermodel, setplayerhead, transition, setcvar, clearcvar, copycvar, exec, execnow, play, playlooped, orbit, addlistitem, checkautoupdate, getautoupdate, setmenufocus, execwolfconfig, setEditFocus, abort.
- The menu engine is not data-driven all the way down: `displayContextDef_t` (ui_shared.h) is a callback table the menu code calls into for ownerdraw painting, feeders (maps/servers/demos/profiles), keybind queries, cinematics and model previews. A large share of ET menu behavior is ui-module C code (`ui_main.c` alone is ~280KB), not .menu data.

### 5.3 Mapping strategy (redirect onto the D3 window system, same approach as the shader parser)

- menuDef -> one `idUserInterfaceLocal` per menu (or one gui with per-menu child windows); itemDef -> an `idWindow` child.
- Direct redirects: rect -> rect; forecolor/backcolor/bordercolor (rgba 0-1) -> same vars; border/bordersize -> border/borderSize; visible; background (ET shader path) -> background material decl (the Q3 shader work already turns ui texture paths into materials; look up by texture name); text/textalign/textalignx/textaligny -> same vars; textscale -> textscale (needs calibration, ET bitmap-font scale vs idFont scale); cvar/cvarTest -> cvar; onOpen/onClose/onESC -> onActivate/onDeactivate/onESC; mouseEnter/mouseExit -> onMouseEnter/onMouseExit; action -> onAction.
- ITEM_TYPE mapping: text/button -> plain windowDef; editfield/numericfield -> `EditWindow`; slider -> `SliderWindow`; checkbox/radio/yesno/multi/combo -> `ChoiceWindow` or a cvar-driven window; listbox -> `ListWindow` (feeder data through `ListGUI`); bind -> `BindWindow`; model/menumodel -> `RenderWindow` (needs a render-to-texture bridge); ownerdraw -> warn-and-skip initially.
- Command translation: show/hide -> `set <window>::visible`; setcvar/clearcvar -> set on cvar vars; setfocus -> `setFocus`; transition -> `transition`; play -> `localSound` (ET plays raw wav paths, D3 needs a sound decl - synthesize one from the path or warn-and-skip); exec/execnow -> `set cmd <console command>` (Script_Set's cmd special case); conditionalscript/conditionalsopen -> if/else on a cvar test.
- open/close/closeall/fadeinmenu/fadeoutmenu -> a legacy menu stack manager on top of named guis. D3 has no menu stack; TA semantics (modal stack, alwaysontop, outOfBoundsClick, ESC) have to be reproduced around `idUserInterfaceLocal` activate/deactivate.
- Parse-and-ignore initially: fades (fadeClamp/fadeCycle/fadeAmount), orbit, blink/pulse/gradient text styles and borders.
- Warn-and-skip group: all ownerdraw items, feeders, setplayermodel/setplayerhead/execwolfconfig/checkautoupdate/getautoupdate, campaign/vote flags. These need a UI/game module behind them; a data-only parser can at most render a placeholder, exactly like unknown shader keywords warn and continue.

### 5.4 Why this one is genuinely tricky (unlike pk3)

- Ownerdraw and feeder behavior lives in ui-module C code, not in .menu data. menudef.h defines ~100 CG_* and ~30 UI_* ownerdraw types plus a dozen feeder types (maps, servers, demos, campaigns, profiles); without a UI module there is nothing to draw. Early menus will be partially functional: main menu, options/controls/system are feasible first targets; server browser and limbo screens are the deep end.
- Menu stack and focus semantics are engine-side in ET (Menus_ActivateByName, Menus_CloseAll, modal stack, per-item hotkeys through execKey/onKey tables, focus colors and fade cycles). D3 windows have hover/focus events but no per-item key tables or menu stack; an adapter layer must reproduce them.
- Sound: ET menu sounds are raw wav paths through the sfx system; D3 needs sound decls. Either synthesize decls from paths or map a small fixed set of standard menu sounds.
- Fonts: ET uses embedded bitmap fonts; text extents and therefore layouts depend on their metrics. idFont metrics differ, so layouts need recalibration (a textscale fudge cvar is a pragmatic lever).
- Model previews and cinematics in menus need bridges (render-to-texture for ITEM_TYPE_MODEL, roq/bik wiring for menu cinematics).
- The binary gui caching (`binaryLoadGuis`) only covers .gui files; a runtime .menu parser must build the window tree directly and stay out of that path.

Phasing:

1. Parser skeleton: menus.txt + .menu loading, menuDef/itemDef accepted, unknown keywords warn-and-skip (the shader-parser approach).
2. Static menus: rects, colors, borders, background images, text, decoration items; open/close stack plus exec/cvar wiring.
3. Interactive items: action/hover/focus events, sounds, checkbox/slider/editfield/bind through the typed windows.
4. Ownerdraw/feeder items only once a UI/game module exists.

## Sources

- ET: Legacy shader parser (`src/renderer/tr_shader.c`, GPLv3): https://github.com/etlegacy/etlegacy/blob/master/src/renderer/tr_shader.c
- ET: Legacy model loaders (`src/renderer/tr_model.c`, GPLv3): https://github.com/etlegacy/etlegacy/blob/master/src/renderer/tr_model.c
- RtCW/ET model format family overview: https://github.com/mino-git/rtcw-wet-blender-model-tools
- ET: Legacy menu parser (`src/ui/ui_shared.c`, GPLv3): https://github.com/etlegacy/etlegacy/blob/master/src/ui/ui_shared.c
- ET: Legacy UI module (`src/ui/ui_main.c`, GPLv3): https://github.com/etlegacy/etlegacy/blob/master/src/ui/ui_main.c
- TA/ET menu constants (`etmain/ui/menudef.h`, GPLv3): https://github.com/etlegacy/etlegacy/blob/master/etmain/ui/menudef.h
- Vendored copies of all three live in this repo under `references/etwolf` (src/ui/ and etmain/ui/).
