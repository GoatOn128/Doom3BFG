# Quake 3 / Wolfenstein: Enemy Territory content support inventory

Audited at commit `0c79836747bc850e93e3bfda8f5a4213d36924e5` (master) on 2026-11-02. Updated 2026-11-02: the MD3 parity work landed (`81dc731`) and MDC/MDS/MDM/MDX/MD4 loaders were added, see sections 2.1-2.3.

Purpose: gap analysis before implementing Q3/ET content support. Two areas as requested: shader (material) syntax and model formats. The engine side was read directly from this repo (`neo/renderer/Material.cpp`, `neo/renderer/Model_md3.cpp`, `neo/renderer/ModelManager.cpp`, `neo/framework/DeclManager.cpp`, `neo/renderer/Image_files.cpp`). The Q3/ET requirement side is taken from the ET: Legacy renderer sources (GPLv3, `src/renderer/tr_shader.c` and `src/renderer/tr_model.c`) and published format references.

Out of scope: Q3 BSP map format, game logic, sound, networking. Some shader features are coupled to map data (lightmaps, lightgrid, fog); those couplings are flagged.

## 1. Shader syntax

### 1.1 What the engine has today

- Materials load only from decls in `materials/*.mtr` (`neo/framework/DeclManager.cpp`: `RegisterDeclFolder("materials", ".mtr", DECL_MATERIAL)`). There is no folder/extension registration for `scripts/*.shader`.
- `idMaterial::Parse` (`neo/renderer/Material.cpp`) parses Doom 3 syntax only. Any unknown token sets `MF_DEFAULTED` and kills the whole material.
- The only Q3-family keyword currently parsed is `qer_editorimage`.
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

Loader note: `idDeclFile::LoadAndParse` already supports typeless decls through a folder's default decl type (it falls back to `defaultType` when the first token is not a registered type name), so `scripts/*.shader` can be registered with `RegisterDeclFolder("scripts", ".shader", DECL_MATERIAL)` and the scanner will pick up every `textures/... { ... }` block as a material decl. The missing part is the parser: `idMaterial::Parse` must gain a Q3 syntax mode (or a separate decl subclass), otherwise every Q3 token defaults the material.

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

All Q3-era model formats are implemented (port commit adds `Model_mdc.cpp/.h` and `Model_wolf.cpp/.h`):

- MDC: compressed MD3 variant from RtCW (`idRenderModelMDC` in `neo/renderer/Model_mdc.cpp`). The compressed frames (per-axis deltas plus an anorms256 normal index, per-frame base/comp tables) and the short-packed tags are decoded at load time into a synthesized MD3 layout, so the entire MD3 path (instantiate, LOD chain via the `LoadHeader`/`LodFileExtension` hooks, tags as joints, per-frame bounds) is shared unchanged.
- MDS: RtCW/ET skeletal format, single file with bones, compressed bone frames, weighted surfaces and bone-attached tags (`idRenderModelMDS` in `neo/renderer/Model_wolf.cpp`).
- MDM + MDX: RtCW split skeletal pair, `.mdm` mesh and tags plus the sibling `.mdx` skeleton/frames (`idRenderModelMDM`, the `.mdx` is loaded by replacing the extension).
- MD4: the early Q3-era skeletal format, kept for completion sake (`idRenderModelMD4`). Only the on-disk structures survive in the ET SDK headers; the decode follows the Q3 3x4 matrix convention (rotation rows with translation in the last column). No known content uses it.
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
2. Q3 shader parsing: register `scripts/*.shader` as a material decl folder (the typeless-decl scanner path already exists), add the Q3 syntax mode to the parser, implement the group A keywords, parse-and-ignore the editor/compile keywords, warn on the rest.
3. ~~MDC loader~~ Done (shares the fixed MD3 path through the `LoadHeader`/`LodFileExtension` hooks).
4. Q3 skin parser + remap hook.
5. Lighting provider decision for `$lightmap`/lightgrid keywords (coupled to the map format decision).
6. Global fog system, `skyparms` sky stage, sun flare.
7. ~~MDS/MDM/MDX~~ Done (plus MD4 for completion).

## Sources

- ET: Legacy shader parser (`src/renderer/tr_shader.c`, GPLv3): https://github.com/etlegacy/etlegacy/blob/master/src/renderer/tr_shader.c
- ET: Legacy model loaders (`src/renderer/tr_model.c`, GPLv3): https://github.com/etlegacy/etlegacy/blob/master/src/renderer/tr_model.c
- RtCW/ET model format family overview: https://github.com/mino-git/rtcw-wet-blender-model-tools
