# Build digest

commit: 37ec9e765169

- windows-x64-debug: failure
- windows-x64-release: cancelled
- windows-x86-debug: failure
- windows-x86-release: cancelled

## windows-x64-debug

status: failure

errors: 314
warnings: 22 in 7 kinds

### errors

neo\renderer\gl_backend.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\gl_backend.cpp.obj] Error 2
neo\renderer\gl_GraphicsAPIWrapper.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\gl_GraphicsAPIWrapper.cpp.obj] Error 2
neo\renderer\gl_Image.cpp(37): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\gl_Image.cpp.obj] Error 2
neo\renderer\OpenGL\gl_backend.cpp(64): error C3861: 'qglClearColor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(66): error C3861: 'qglClearColor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(68): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(69): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(118): error C3861: 'qglFinish': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(137): error C3861: 'qglIsSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(138): error C3861: 'qglDeleteSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(142): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(143): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(144): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(145): error C3861: 'qglFenceSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(158): error C3861: 'qglIsSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(160): error C3861: 'qglClientWaitSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(168): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(169): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(170): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(172): error C3861: 'qglFinish': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(252): error C3861: 'qglColorMask': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(254): error C3861: 'qglFlush': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(276): error C3861: 'qglViewport': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(278): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(280): error C3861: 'qglMatrixMode': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(281): error C3861: 'qglLoadIdentity': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(282): error C3861: 'qglOrtho': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(283): error C3861: 'qglMatrixMode': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(284): error C3861: 'qglLoadIdentity': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(292): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(293): error C3861: 'qglDisable': identifier not found
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_backend.cpp.obj] Error 2
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(68): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(71): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(76): error C3861: 'qglCullFace': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(78): error C3861: 'qglCullFace': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(82): error C3861: 'qglCullFace': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(84): error C3861: 'qglCullFace': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(98): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(107): error C3861: 'qglViewport': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(119): error C3861: 'qglPolygonOffset': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(134): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(136): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(137): error C3861: 'qglDepthBoundsEXT': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(209): error C3861: 'qglClearColor': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(216): error C3861: 'qglClearStencil': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(219): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(233): error C3861: 'qglClearDepth': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(240): error C3861: 'qglCullFace': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(241): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(244): error C3861: 'qglColorMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(245): error C3861: 'qglBlendFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(246): error C3861: 'qglDepthMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(247): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(248): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(249): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(250): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(251): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(254): error C3861: 'qglShadeModel': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(255): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(256): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(257): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(258): error C3861: 'qglDrawBuffer': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(259): error C3861: 'qglReadBuffer': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(262): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(289): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(290): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(291): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(292): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(333): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(335): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(336): error C3861: 'qglBlendFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(345): error C3861: 'qglDepthMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(347): error C3861: 'qglDepthMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(359): error C3861: 'qglColorMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(367): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(369): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(378): error C3861: 'qglPolygonOffset': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(379): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(380): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(382): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(383): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(415): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(417): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(435): error C3861: 'qglStencilFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(472): error C3861: 'qglStencilOp': identifier not found
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp.obj] Error 2
neo\renderer\OpenGL\gl_Image.cpp(88): error C3861: 'qglBindTexture': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(91): error C3861: 'qglPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(94): error C3861: 'glPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(100): error C3861: 'qglCompressedTexSubImage2DARB': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(108): error C3861: 'qglPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(110): error C3861: 'qglPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(113): error C3861: 'qglTexSubImage2D': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(119): error C3861: 'glPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(122): error C3861: 'qglPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(158): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(159): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(160): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(161): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(163): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(164): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(165): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(166): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(168): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(169): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(170): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(171): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(173): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(174): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(175): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(176): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(178): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(179): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(180): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(181): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(183): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(184): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(185): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(186): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(205): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(207): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(209): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(212): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(213): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(216): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(217): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(233): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(235): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(240): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(246): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(247): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(251): error C3861: 'qglTexParameterfv': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(252): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(253): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(258): error C3861: 'qglTexParameterfv': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(259): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(260): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(264): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(265): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(380): error C3861: 'qglGenTextures': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(403): error C3861: 'qglBindTexture': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(428): error C3861: 'qglCompressedTexImage2DARB': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(433): error C3861: 'qglTexImage2D': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(443): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(460): error C3861: 'qglDeleteTextures': identifier not found
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_Image.cpp.obj] Error 2
neo\renderer\RenderSystem_init.cpp(339): error C2664: 'void (GLDEBUGPROCARB,const void *)': cannot convert argument 1 from 'overloaded-function' to 'GLDEBUGPROCARB'
neo\renderer\RenderSystem_init.cpp(343): error C3861: 'glEnable': identifier not found
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\RenderSystem_init.cpp.obj] Error 2
neo\renderer\tr_backend_rendertools.cpp(603): error C3861: 'glLoadMatrixf': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2164): error C3861: 'glEnable': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2165): error C3861: 'glClearColor': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2170): error C3861: 'glScissor': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2171): error C3861: 'glClear': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2175): error C3861: 'glScissor': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2176): error C3861: 'glClear': identifier not found
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\tr_backend_rendertools.cpp.obj] Error 2
neo\sys\win32\win_glimp.cpp(360): error C2065: 'ERROR_INVALID_VERSION_ARB': undeclared identifier
neo\sys\win32\win_glimp.cpp(361): error C2065: 'ERROR_INVALID_PROFILE_ARB': undeclared identifier
neo\sys\win32\win_glimp.cpp(360): error C2051: case expression not constant
neo\sys\win32\win_glimp.cpp(361): error C2051: case expression not constant
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\sys\win32\win_glimp.cpp.obj] Error 2
neo\tools\compilers\dmap\optimize.cpp(239): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(244): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(245): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(246): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(247): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(249): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(250): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(267): error C3861: 'qglEnable': identifier not found
neo\tools\compilers\dmap\optimize.cpp(268): error C3861: 'qglBlendFunc': identifier not found
neo\tools\compilers\dmap\optimize.cpp(269): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(270): error C3861: 'qglPointSize': identifier not found
neo\tools\compilers\dmap\optimize.cpp(271): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(273): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(275): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(276): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\dmap\optimize.cpp(277): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(294): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(299): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(300): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(301): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(302): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(304): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(305): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(483): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(484): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(485): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(486): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(487): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(488): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(690): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(691): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(692): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(693): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(694): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(695): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(696): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(697): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(698): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(699): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(700): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(701): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(968): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(969): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(970): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(971): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(972): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(973): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(974): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(975): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(976): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(977): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(978): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(979): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1002): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1003): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1004): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1005): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1006): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1007): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1020): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1021): error C3861: 'qglPointSize': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1022): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1023): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1024): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1025): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1042): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1044): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1046): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1047): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1048): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1049): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1050): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1051): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1052): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1053): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1054): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1055): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1056): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1057): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1370): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1372): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1373): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1374): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1375): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1377): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1378): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1496): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1497): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1498): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1499): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1500): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1501): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1502): error C3861: 'qglFlush': identifier not found
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\tools\compilers\dmap\optimize.cpp.obj] Error 2
neo\tools\compilers\renderbump\renderbump.cpp(929): error C3861: 'RB_SetGL2D': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(931): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(933): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(935): error C3861: 'qglMatrixMode': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(936): error C3861: 'qglLoadIdentity': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(937): error C3861: 'qglOrtho': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(938): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(939): error C3861: 'qglMatrixMode': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(940): error C3861: 'qglLoadIdentity': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(942): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(944): error C3861: 'qglClearColor': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(945): error C3861: 'qglClear': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(947): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(981): error C3861: 'qglClearColor': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(982): error C3861: 'qglClear': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(983): error C3861: 'qglRasterPos2f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(984): error C3861: 'qglPixelZoom': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(985): error C3861: 'qglDrawPixels': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(986): error C3861: 'qglPixelZoom': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(987): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1422): error C3861: 'qglViewport': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1424): error C3861: 'qglEnable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1425): error C3861: 'qglCullFace': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1426): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1427): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1428): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1429): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1430): error C3861: 'qglEnable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1431): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1432): error C3861: 'qglDepthMask': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1433): error C3861: 'qglDepthFunc': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1435): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1437): error C3861: 'qglMatrixMode': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1438): error C3861: 'qglLoadIdentity': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1439): error C3861: 'qglOrtho': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1442): error C3861: 'qglMatrixMode': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1443): error C3861: 'qglLoadIdentity': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1471): error C3861: 'qglClearColor': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1472): error C3861: 'qglClear': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1474): error C3861: 'qglBegin': identifier not found

### failure context

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\gl_backend.cpp.obj

```
CinematicBink.cpp
neo\renderer\BufferObject.cpp(188): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
neo\renderer\BufferObject.cpp(433): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
neo\renderer\BufferObject.cpp(671): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
Compiling 'neo\renderer\CinematicRoQ.cpp'
CinematicRoQ.cpp
Compiling 'neo\renderer\Color\ColorSpace.cpp'
ColorSpace.cpp
Compiling 'neo\renderer\DeclRenderProg.cpp'
DeclRenderProg.cpp
neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
Compiling 'neo\renderer\DeclRenderProgGenerator.cpp'
DeclRenderProgGenerator.cpp
Compiling 'neo\renderer\DXT\DXTDecoder.cpp'
DXTDecoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder.cpp'
DXTEncoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder_SSE2.cpp'
DXTEncoder_SSE2.cpp
Compiling 'neo\renderer\Font.cpp'
Font.cpp
Compiling 'neo\renderer\gl_backend.cpp'
gl_backend.cpp
Compiling 'neo\renderer\gl_GraphicsAPIWrapper.cpp'
gl_GraphicsAPIWrapper.cpp
Compiling 'neo\renderer\gl_Image.cpp'
gl_Image.cpp
Compiling 'neo\renderer\GLMatrix.cpp'
GLMatrix.cpp
neo\renderer\gl_backend.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\gl_backend.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\gl_GraphicsAPIWrapper.cpp.obj

```
Compiling 'neo\renderer\CinematicRoQ.cpp'
CinematicRoQ.cpp
Compiling 'neo\renderer\Color\ColorSpace.cpp'
ColorSpace.cpp
Compiling 'neo\renderer\DeclRenderProg.cpp'
DeclRenderProg.cpp
neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
Compiling 'neo\renderer\DeclRenderProgGenerator.cpp'
DeclRenderProgGenerator.cpp
Compiling 'neo\renderer\DXT\DXTDecoder.cpp'
DXTDecoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder.cpp'
DXTEncoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder_SSE2.cpp'
DXTEncoder_SSE2.cpp
Compiling 'neo\renderer\Font.cpp'
Font.cpp
Compiling 'neo\renderer\gl_backend.cpp'
gl_backend.cpp
Compiling 'neo\renderer\gl_GraphicsAPIWrapper.cpp'
gl_GraphicsAPIWrapper.cpp
Compiling 'neo\renderer\gl_Image.cpp'
gl_Image.cpp
Compiling 'neo\renderer\GLMatrix.cpp'
GLMatrix.cpp
neo\renderer\gl_backend.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\gl_backend.cpp.obj] Error 2
Compiling 'neo\renderer\GuiModel.cpp'
GuiModel.cpp
neo\renderer\gl_GraphicsAPIWrapper.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\gl_GraphicsAPIWrapper.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\gl_Image.cpp.obj

```
Compiling 'neo\renderer\DeclRenderProg.cpp'
DeclRenderProg.cpp
neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
Compiling 'neo\renderer\DeclRenderProgGenerator.cpp'
DeclRenderProgGenerator.cpp
Compiling 'neo\renderer\DXT\DXTDecoder.cpp'
DXTDecoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder.cpp'
DXTEncoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder_SSE2.cpp'
DXTEncoder_SSE2.cpp
Compiling 'neo\renderer\Font.cpp'
Font.cpp
Compiling 'neo\renderer\gl_backend.cpp'
gl_backend.cpp
Compiling 'neo\renderer\gl_GraphicsAPIWrapper.cpp'
gl_GraphicsAPIWrapper.cpp
Compiling 'neo\renderer\gl_Image.cpp'
gl_Image.cpp
Compiling 'neo\renderer\GLMatrix.cpp'
GLMatrix.cpp
neo\renderer\gl_backend.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\gl_backend.cpp.obj] Error 2
Compiling 'neo\renderer\GuiModel.cpp'
GuiModel.cpp
neo\renderer\gl_GraphicsAPIWrapper.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\gl_GraphicsAPIWrapper.cpp.obj] Error 2
Compiling 'neo\renderer\Image_files.cpp'
Image_files.cpp
neo\renderer\gl_Image.cpp(37): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\gl_Image.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_backend.cpp.obj

```
Compiling 'neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp'
gl_GraphicsAPIWrapper.cpp
neo\renderer\OpenGL\gl_backend.cpp(64): error C3861: 'qglClearColor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(66): error C3861: 'qglClearColor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(68): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(69): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(118): error C3861: 'qglFinish': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(137): error C3861: 'qglIsSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(138): error C3861: 'qglDeleteSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(142): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(143): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(144): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(145): error C3861: 'qglFenceSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(158): error C3861: 'qglIsSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(160): error C3861: 'qglClientWaitSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(168): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(169): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(170): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(172): error C3861: 'qglFinish': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(252): error C3861: 'qglColorMask': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(254): error C3861: 'qglFlush': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(276): error C3861: 'qglViewport': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(278): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(280): error C3861: 'qglMatrixMode': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(281): error C3861: 'qglLoadIdentity': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(282): error C3861: 'qglOrtho': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(283): error C3861: 'qglMatrixMode': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(284): error C3861: 'qglLoadIdentity': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(292): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(293): error C3861: 'qglDisable': identifier not found
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_backend.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp.obj

```
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(250): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(251): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(254): error C3861: 'qglShadeModel': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(255): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(256): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(257): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(258): error C3861: 'qglDrawBuffer': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(259): error C3861: 'qglReadBuffer': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(262): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(289): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(290): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(291): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(292): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(333): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(335): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(336): error C3861: 'qglBlendFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(345): error C3861: 'qglDepthMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(347): error C3861: 'qglDepthMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(359): error C3861: 'qglColorMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(367): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(369): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(378): error C3861: 'qglPolygonOffset': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(379): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(380): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(382): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(383): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(415): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(417): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(435): error C3861: 'qglStencilFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(472): error C3861: 'qglStencilOp': identifier not found
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_Image.cpp.obj

```
neo\renderer\OpenGL\gl_Image.cpp(183): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(184): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(185): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(186): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(205): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(207): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(209): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(212): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(213): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(216): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(217): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(233): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(235): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(240): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(246): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(247): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(251): error C3861: 'qglTexParameterfv': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(252): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(253): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(258): error C3861: 'qglTexParameterfv': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(259): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(260): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(264): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(265): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(380): error C3861: 'qglGenTextures': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(403): error C3861: 'qglBindTexture': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(428): error C3861: 'qglCompressedTexImage2DARB': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(433): error C3861: 'qglTexImage2D': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(443): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(460): error C3861: 'qglDeleteTextures': identifier not found
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_Image.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\RenderSystem_init.cpp.obj

```
neo\renderer\OpenGL\gl_Image.cpp(259): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(260): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(264): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(265): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(380): error C3861: 'qglGenTextures': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(403): error C3861: 'qglBindTexture': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(428): error C3861: 'qglCompressedTexImage2DARB': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(433): error C3861: 'qglTexImage2D': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(443): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(460): error C3861: 'qglDeleteTextures': identifier not found
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_Image.cpp.obj] Error 2
Compiling 'neo\renderer\RenderLog.cpp'
RenderLog.cpp
Compiling 'neo\renderer\RenderProgParm.cpp'
RenderProgParm.cpp
Compiling 'neo\renderer\RenderProgs.cpp'
RenderProgs.cpp
Compiling 'neo\renderer\RenderSystem.cpp'
RenderSystem.cpp
Compiling 'neo\renderer\RenderSystem_init.cpp'
RenderSystem_init.cpp
Compiling 'neo\renderer\RenderWorld.cpp'
RenderWorld.cpp
Compiling 'neo\renderer\RenderWorld_defs.cpp'
RenderWorld_defs.cpp
Compiling 'neo\renderer\RenderWorld_demo.cpp'
RenderWorld_demo.cpp
neo\renderer\RenderSystem_init.cpp(339): error C2664: 'void (GLDEBUGPROCARB,const void *)': cannot convert argument 1 from 'overloaded-function' to 'GLDEBUGPROCARB'
neo\renderer\RenderSystem_init.cpp(339): note: None of the functions with this name in scope match the target type
neo\renderer\RenderSystem_init.cpp(343): error C3861: 'glEnable': identifier not found
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\RenderSystem_init.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\tr_backend_rendertools.cpp.obj

```
ResolutionScale.cpp
Compiling 'neo\renderer\ScreenRect.cpp'
ScreenRect.cpp
Compiling 'neo\renderer\stblib_impls.c'
stblib_impls.c
Compiling 'neo\renderer\tr_backend_draw.cpp'
tr_backend_draw.cpp
Compiling 'neo\renderer\tr_backend_rendertools.cpp'
tr_backend_rendertools.cpp
Compiling 'neo\renderer\tr_frontend_addlights.cpp'
tr_frontend_addlights.cpp
Compiling 'neo\renderer\tr_frontend_addmodels.cpp'
tr_frontend_addmodels.cpp
neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_draw.cpp(1498): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_draw.cpp(1516): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_draw.cpp(1536): warning C4389: '!=': signed/unsigned mismatch
Compiling 'neo\renderer\tr_frontend_deform.cpp'
neo\renderer\tr_backend_rendertools.cpp(603): error C3861: 'glLoadMatrixf': identifier not found
neo\renderer\tr_backend_rendertools.cpp(724): warning C4311: 'type cast': pointer truncation from 'void *' to 'GLuint'
neo\renderer\tr_backend_rendertools.cpp(724): warning C4302: 'type cast': truncation from 'void *' to 'GLuint'
neo\renderer\tr_backend_rendertools.cpp(727): warning C4312: 'type cast': conversion from 'int' to 'void *' of greater size
neo\renderer\tr_backend_rendertools.cpp(2164): error C3861: 'glEnable': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2165): error C3861: 'glClearColor': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2170): error C3861: 'glScissor': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2171): error C3861: 'glClear': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2175): error C3861: 'glScissor': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2176): error C3861: 'glClear': identifier not found
tr_frontend_deform.cpp
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\tr_backend_rendertools.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\sys\win32\win_glimp.cpp.obj

```
Compiling 'neo\sys\sys_profile.cpp'
sys_profile.cpp
Compiling 'neo\sys\sys_savegame.cpp'
sys_savegame.cpp
Compiling 'neo\sys\sys_session_callbacks.cpp'
sys_session_callbacks.cpp
Compiling 'neo\sys\sys_session_local.cpp'
sys_session_local.cpp
Compiling 'neo\sys\sys_session_savegames.cpp'
sys_session_savegames.cpp
Compiling 'neo\sys\sys_signin.cpp'
sys_signin.cpp
Compiling 'neo\sys\sys_voicechat.cpp'
sys_voicechat.cpp
Compiling 'neo\sys\win32\win_achievements.cpp'
win_achievements.cpp
Compiling 'neo\sys\win32\win_cpu.cpp'
win_cpu.cpp
Compiling 'neo\sys\win32\win_glimp.cpp'
win_glimp.cpp
Compiling 'neo\sys\win32\win_input.cpp'
Compiling 'neo\sys\win32\win_localuser.cpp'
win_input.cpp
win_localuser.cpp
neo\sys\win32\win_glimp.cpp(360): error C2065: 'ERROR_INVALID_VERSION_ARB': undeclared identifier
neo\sys\win32\win_glimp.cpp(361): error C2065: 'ERROR_INVALID_PROFILE_ARB': undeclared identifier
neo\sys\win32\win_glimp.cpp(360): error C2051: case expression not constant
neo\sys\win32\win_glimp.cpp(361): error C2051: case expression not constant
neo\sys\win32\win_glimp.cpp(363): warning C4065: switch statement contains 'default' but no 'case' labels
Compiling 'neo\sys\win32\win_main.cpp'
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\sys\win32\win_glimp.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\DoomEXE\tools\compilers\dmap\optimize.cpp.obj

```
neo\tools\compilers\dmap\optimize.cpp(1024): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1025): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1042): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1044): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1046): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1047): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1048): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1049): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1050): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1051): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1052): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1053): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1054): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1055): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1056): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1057): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1370): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1372): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1373): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1374): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1375): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1377): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1378): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1496): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1497): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1498): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1499): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1500): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1501): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1502): error C3861: 'qglFlush': identifier not found
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\tools\compilers\dmap\optimize.cpp.obj] Error 2
```


### warning kinds

- [5x] C4389
  - neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1498): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1516): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1536): warning C4389: '!=': signed/unsigned mismatch
- [4x] C4312
  - neo\renderer\BufferObject.cpp(188): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - neo\renderer\BufferObject.cpp(433): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - neo\renderer\BufferObject.cpp(671): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - neo\renderer\tr_backend_rendertools.cpp(727): warning C4312: 'type cast': conversion from 'int' to 'void *' of greater size
- [3x] C4245
  - neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [3x] C4311
  - neo\renderer\tr_backend_rendertools.cpp(724): warning C4311: 'type cast': pointer truncation from 'void *' to 'GLuint'
  - neo\sys\win32\win_syscon.cpp(119): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(128): warning C4311: 'type cast': pointer truncation from 'HBRUSH' to 'long'
- [3x] C4302
  - neo\renderer\tr_backend_rendertools.cpp(724): warning C4302: 'type cast': truncation from 'void *' to 'GLuint'
  - neo\sys\win32\win_syscon.cpp(119): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
  - neo\sys\win32\win_syscon.cpp(128): warning C4302: 'type cast': truncation from 'HBRUSH' to 'long'
- [3x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\external\stb\stb_vorbis.h(4849) : warning C4701: potentially uninitialized local variable 'mid' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used
- [1x] C4065
  - neo\sys\win32\win_glimp.cpp(363): warning C4065: switch statement contains 'default' but no 'case' labels

## windows-x64-release

status: cancelled

errors: 153
warnings: 12 in 3 kinds

### errors

neo\renderer\gl_backend.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\gl_backend.cpp.obj] Error 2
neo\renderer\gl_GraphicsAPIWrapper.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\gl_GraphicsAPIWrapper.cpp.obj] Error 2
neo\renderer\gl_Image.cpp(37): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\gl_Image.cpp.obj] Error 2
neo\renderer\OpenGL\gl_backend.cpp(64): error C3861: 'qglClearColor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(66): error C3861: 'qglClearColor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(68): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(69): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(118): error C3861: 'qglFinish': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(137): error C3861: 'qglIsSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(138): error C3861: 'qglDeleteSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(142): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(143): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(144): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(145): error C3861: 'qglFenceSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(158): error C3861: 'qglIsSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(160): error C3861: 'qglClientWaitSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(168): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(169): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(170): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(172): error C3861: 'qglFinish': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(252): error C3861: 'qglColorMask': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(254): error C3861: 'qglFlush': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(276): error C3861: 'qglViewport': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(278): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(280): error C3861: 'qglMatrixMode': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(281): error C3861: 'qglLoadIdentity': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(282): error C3861: 'qglOrtho': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(283): error C3861: 'qglMatrixMode': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(284): error C3861: 'qglLoadIdentity': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(292): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(293): error C3861: 'qglDisable': identifier not found
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_backend.cpp.obj] Error 2
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(68): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(71): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(76): error C3861: 'qglCullFace': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(78): error C3861: 'qglCullFace': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(82): error C3861: 'qglCullFace': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(84): error C3861: 'qglCullFace': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(98): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(107): error C3861: 'qglViewport': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(119): error C3861: 'qglPolygonOffset': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(134): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(136): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(137): error C3861: 'qglDepthBoundsEXT': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(209): error C3861: 'qglClearColor': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(216): error C3861: 'qglClearStencil': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(219): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(233): error C3861: 'qglClearDepth': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(240): error C3861: 'qglCullFace': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(241): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(244): error C3861: 'qglColorMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(245): error C3861: 'qglBlendFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(246): error C3861: 'qglDepthMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(247): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(248): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(249): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(250): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(251): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(254): error C3861: 'qglShadeModel': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(255): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(256): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(257): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(258): error C3861: 'qglDrawBuffer': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(259): error C3861: 'qglReadBuffer': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(262): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(289): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(290): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(291): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(292): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(333): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(335): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(336): error C3861: 'qglBlendFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(345): error C3861: 'qglDepthMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(347): error C3861: 'qglDepthMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(359): error C3861: 'qglColorMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(367): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(369): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(378): error C3861: 'qglPolygonOffset': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(379): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(380): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(382): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(383): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(415): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(417): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(435): error C3861: 'qglStencilFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(472): error C3861: 'qglStencilOp': identifier not found
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp.obj] Error 2
neo\renderer\OpenGL\gl_Image.cpp(88): error C3861: 'qglBindTexture': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(91): error C3861: 'qglPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(94): error C3861: 'glPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(100): error C3861: 'qglCompressedTexSubImage2DARB': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(108): error C3861: 'qglPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(110): error C3861: 'qglPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(113): error C3861: 'qglTexSubImage2D': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(119): error C3861: 'glPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(122): error C3861: 'qglPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(158): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(159): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(160): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(161): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(163): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(164): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(165): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(166): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(168): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(169): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(170): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(171): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(173): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(174): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(175): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(176): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(178): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(179): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(180): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(181): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(183): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(184): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(185): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(186): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(205): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(207): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(209): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(212): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(213): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(216): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(217): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(233): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(235): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(240): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(246): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(247): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(251): error C3861: 'qglTexParameterfv': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(252): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(253): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(258): error C3861: 'qglTexParameterfv': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(259): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(260): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(264): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(265): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(380): error C3861: 'qglGenTextures': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(403): error C3861: 'qglBindTexture': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(428): error C3861: 'qglCompressedTexImage2DARB': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(433): error C3861: 'qglTexImage2D': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(443): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(460): error C3861: 'qglDeleteTextures': identifier not found
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_Image.cpp.obj] Error 2
neo\renderer\RenderSystem_init.cpp(339): error C2664: 'void (GLDEBUGPROCARB,const void *)': cannot convert argument 1 from 'overloaded-function' to 'GLDEBUGPROCARB'
neo\renderer\RenderSystem_init.cpp(343): error C3861: 'glEnable': identifier not found
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderSystem_init.cpp.obj] Error 2

### failure context

- build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\gl_backend.cpp.obj

```
Cinematic.cpp
Compiling 'neo\renderer\CinematicBink.cpp'
CinematicBink.cpp
Compiling 'neo\renderer\CinematicRoQ.cpp'
CinematicRoQ.cpp
neo\renderer\BufferObject.cpp(188): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
neo\renderer\BufferObject.cpp(433): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
neo\renderer\BufferObject.cpp(671): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
Compiling 'neo\renderer\Color\ColorSpace.cpp'
ColorSpace.cpp
Compiling 'neo\renderer\DeclRenderProg.cpp'
DeclRenderProg.cpp
neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
Compiling 'neo\renderer\DeclRenderProgGenerator.cpp'
DeclRenderProgGenerator.cpp
Compiling 'neo\renderer\DXT\DXTDecoder.cpp'
DXTDecoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder.cpp'
DXTEncoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder_SSE2.cpp'
DXTEncoder_SSE2.cpp
Compiling 'neo\renderer\Font.cpp'
Font.cpp
Compiling 'neo\renderer\gl_backend.cpp'
gl_backend.cpp
Compiling 'neo\renderer\gl_GraphicsAPIWrapper.cpp'
gl_GraphicsAPIWrapper.cpp
Compiling 'neo\renderer\gl_Image.cpp'
gl_Image.cpp
neo\renderer\gl_backend.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\gl_backend.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\gl_GraphicsAPIWrapper.cpp.obj

```
neo\renderer\BufferObject.cpp(433): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
neo\renderer\BufferObject.cpp(671): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
Compiling 'neo\renderer\Color\ColorSpace.cpp'
ColorSpace.cpp
Compiling 'neo\renderer\DeclRenderProg.cpp'
DeclRenderProg.cpp
neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
Compiling 'neo\renderer\DeclRenderProgGenerator.cpp'
DeclRenderProgGenerator.cpp
Compiling 'neo\renderer\DXT\DXTDecoder.cpp'
DXTDecoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder.cpp'
DXTEncoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder_SSE2.cpp'
DXTEncoder_SSE2.cpp
Compiling 'neo\renderer\Font.cpp'
Font.cpp
Compiling 'neo\renderer\gl_backend.cpp'
gl_backend.cpp
Compiling 'neo\renderer\gl_GraphicsAPIWrapper.cpp'
gl_GraphicsAPIWrapper.cpp
Compiling 'neo\renderer\gl_Image.cpp'
gl_Image.cpp
neo\renderer\gl_backend.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\gl_backend.cpp.obj] Error 2
Compiling 'neo\renderer\GLMatrix.cpp'
GLMatrix.cpp
Compiling 'neo\renderer\GuiModel.cpp'
GuiModel.cpp
neo\renderer\gl_GraphicsAPIWrapper.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\gl_GraphicsAPIWrapper.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\gl_Image.cpp.obj

```
Compiling 'neo\renderer\DeclRenderProg.cpp'
DeclRenderProg.cpp
neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
Compiling 'neo\renderer\DeclRenderProgGenerator.cpp'
DeclRenderProgGenerator.cpp
Compiling 'neo\renderer\DXT\DXTDecoder.cpp'
DXTDecoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder.cpp'
DXTEncoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder_SSE2.cpp'
DXTEncoder_SSE2.cpp
Compiling 'neo\renderer\Font.cpp'
Font.cpp
Compiling 'neo\renderer\gl_backend.cpp'
gl_backend.cpp
Compiling 'neo\renderer\gl_GraphicsAPIWrapper.cpp'
gl_GraphicsAPIWrapper.cpp
Compiling 'neo\renderer\gl_Image.cpp'
gl_Image.cpp
neo\renderer\gl_backend.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\gl_backend.cpp.obj] Error 2
Compiling 'neo\renderer\GLMatrix.cpp'
GLMatrix.cpp
Compiling 'neo\renderer\GuiModel.cpp'
GuiModel.cpp
neo\renderer\gl_GraphicsAPIWrapper.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\gl_GraphicsAPIWrapper.cpp.obj] Error 2
Compiling 'neo\renderer\Image_files.cpp'
Image_files.cpp
neo\renderer\gl_Image.cpp(37): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\gl_Image.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_backend.cpp.obj

```
Compiling 'neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp'
gl_GraphicsAPIWrapper.cpp
neo\renderer\OpenGL\gl_backend.cpp(64): error C3861: 'qglClearColor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(66): error C3861: 'qglClearColor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(68): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(69): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(118): error C3861: 'qglFinish': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(137): error C3861: 'qglIsSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(138): error C3861: 'qglDeleteSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(142): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(143): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(144): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(145): error C3861: 'qglFenceSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(158): error C3861: 'qglIsSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(160): error C3861: 'qglClientWaitSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(168): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(169): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(170): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(172): error C3861: 'qglFinish': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(252): error C3861: 'qglColorMask': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(254): error C3861: 'qglFlush': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(276): error C3861: 'qglViewport': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(278): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(280): error C3861: 'qglMatrixMode': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(281): error C3861: 'qglLoadIdentity': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(282): error C3861: 'qglOrtho': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(283): error C3861: 'qglMatrixMode': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(284): error C3861: 'qglLoadIdentity': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(292): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(293): error C3861: 'qglDisable': identifier not found
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_backend.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp.obj

```
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(250): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(251): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(254): error C3861: 'qglShadeModel': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(255): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(256): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(257): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(258): error C3861: 'qglDrawBuffer': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(259): error C3861: 'qglReadBuffer': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(262): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(289): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(290): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(291): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(292): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(333): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(335): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(336): error C3861: 'qglBlendFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(345): error C3861: 'qglDepthMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(347): error C3861: 'qglDepthMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(359): error C3861: 'qglColorMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(367): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(369): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(378): error C3861: 'qglPolygonOffset': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(379): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(380): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(382): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(383): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(415): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(417): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(435): error C3861: 'qglStencilFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(472): error C3861: 'qglStencilOp': identifier not found
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_Image.cpp.obj

```
neo\renderer\OpenGL\gl_Image.cpp(183): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(184): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(185): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(186): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(205): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(207): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(209): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(212): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(213): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(216): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(217): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(233): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(235): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(240): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(246): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(247): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(251): error C3861: 'qglTexParameterfv': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(252): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(253): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(258): error C3861: 'qglTexParameterfv': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(259): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(260): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(264): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(265): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(380): error C3861: 'qglGenTextures': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(403): error C3861: 'qglBindTexture': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(428): error C3861: 'qglCompressedTexImage2DARB': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(433): error C3861: 'qglTexImage2D': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(443): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(460): error C3861: 'qglDeleteTextures': identifier not found
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_Image.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderSystem_init.cpp.obj

```
neo\renderer\OpenGL\gl_Image.cpp(259): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(260): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(264): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(265): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(380): error C3861: 'qglGenTextures': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(403): error C3861: 'qglBindTexture': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(428): error C3861: 'qglCompressedTexImage2DARB': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(433): error C3861: 'qglTexImage2D': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(443): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(460): error C3861: 'qglDeleteTextures': identifier not found
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_Image.cpp.obj] Error 2
Compiling 'neo\renderer\RenderLog.cpp'
RenderLog.cpp
Compiling 'neo\renderer\RenderProgParm.cpp'
RenderProgParm.cpp
Compiling 'neo\renderer\RenderProgs.cpp'
Compiling 'neo\renderer\RenderSystem.cpp'
RenderProgs.cpp
RenderSystem.cpp
Compiling 'neo\renderer\RenderSystem_init.cpp'
RenderSystem_init.cpp
Compiling 'neo\renderer\RenderWorld.cpp'
RenderWorld.cpp
Compiling 'neo\renderer\RenderWorld_defs.cpp'
RenderWorld_defs.cpp
Compiling 'neo\renderer\RenderWorld_demo.cpp'
RenderWorld_demo.cpp
neo\renderer\RenderSystem_init.cpp(339): error C2664: 'void (GLDEBUGPROCARB,const void *)': cannot convert argument 1 from 'overloaded-function' to 'GLDEBUGPROCARB'
neo\renderer\RenderSystem_init.cpp(339): note: None of the functions with this name in scope match the target type
neo\renderer\RenderSystem_init.cpp(343): error C3861: 'glEnable': identifier not found
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderSystem_init.cpp.obj] Error 2
```


### warning kinds

- [6x] C4702
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(368) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1048) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1345) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1379) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1390) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1422) : warning C4702: unreachable code
- [3x] C4245
  - neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [3x] C4312
  - neo\renderer\BufferObject.cpp(188): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - neo\renderer\BufferObject.cpp(433): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size
  - neo\renderer\BufferObject.cpp(671): warning C4312: 'reinterpret_cast': conversion from 'GLuint' to 'void *' of greater size

## windows-x86-debug

status: failure

errors: 314
warnings: 16 in 4 kinds

### errors

neo\renderer\gl_backend.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\gl_backend.cpp.obj] Error 2
neo\renderer\gl_GraphicsAPIWrapper.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\gl_GraphicsAPIWrapper.cpp.obj] Error 2
neo\renderer\gl_Image.cpp(37): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\gl_Image.cpp.obj] Error 2
neo\renderer\OpenGL\gl_backend.cpp(64): error C3861: 'qglClearColor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(66): error C3861: 'qglClearColor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(68): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(69): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(118): error C3861: 'qglFinish': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(137): error C3861: 'qglIsSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(138): error C3861: 'qglDeleteSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(142): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(143): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(144): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(145): error C3861: 'qglFenceSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(158): error C3861: 'qglIsSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(160): error C3861: 'qglClientWaitSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(168): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(169): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(170): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(172): error C3861: 'qglFinish': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(252): error C3861: 'qglColorMask': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(254): error C3861: 'qglFlush': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(276): error C3861: 'qglViewport': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(278): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(280): error C3861: 'qglMatrixMode': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(281): error C3861: 'qglLoadIdentity': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(282): error C3861: 'qglOrtho': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(283): error C3861: 'qglMatrixMode': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(284): error C3861: 'qglLoadIdentity': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(292): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(293): error C3861: 'qglDisable': identifier not found
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_backend.cpp.obj] Error 2
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(68): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(71): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(76): error C3861: 'qglCullFace': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(78): error C3861: 'qglCullFace': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(82): error C3861: 'qglCullFace': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(84): error C3861: 'qglCullFace': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(98): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(107): error C3861: 'qglViewport': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(119): error C3861: 'qglPolygonOffset': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(134): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(136): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(137): error C3861: 'qglDepthBoundsEXT': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(209): error C3861: 'qglClearColor': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(216): error C3861: 'qglClearStencil': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(219): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(233): error C3861: 'qglClearDepth': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(240): error C3861: 'qglCullFace': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(241): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(244): error C3861: 'qglColorMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(245): error C3861: 'qglBlendFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(246): error C3861: 'qglDepthMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(247): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(248): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(249): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(250): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(251): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(254): error C3861: 'qglShadeModel': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(255): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(256): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(257): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(258): error C3861: 'qglDrawBuffer': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(259): error C3861: 'qglReadBuffer': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(262): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(289): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(290): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(291): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(292): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(333): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(335): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(336): error C3861: 'qglBlendFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(345): error C3861: 'qglDepthMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(347): error C3861: 'qglDepthMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(359): error C3861: 'qglColorMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(367): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(369): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(378): error C3861: 'qglPolygonOffset': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(379): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(380): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(382): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(383): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(415): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(417): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(435): error C3861: 'qglStencilFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(472): error C3861: 'qglStencilOp': identifier not found
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp.obj] Error 2
neo\renderer\OpenGL\gl_Image.cpp(88): error C3861: 'qglBindTexture': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(91): error C3861: 'qglPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(94): error C3861: 'glPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(100): error C3861: 'qglCompressedTexSubImage2DARB': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(108): error C3861: 'qglPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(110): error C3861: 'qglPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(113): error C3861: 'qglTexSubImage2D': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(119): error C3861: 'glPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(122): error C3861: 'qglPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(158): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(159): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(160): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(161): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(163): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(164): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(165): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(166): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(168): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(169): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(170): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(171): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(173): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(174): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(175): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(176): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(178): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(179): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(180): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(181): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(183): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(184): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(185): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(186): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(205): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(207): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(209): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(212): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(213): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(216): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(217): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(233): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(235): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(240): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(246): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(247): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(251): error C3861: 'qglTexParameterfv': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(252): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(253): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(258): error C3861: 'qglTexParameterfv': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(259): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(260): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(264): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(265): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(380): error C3861: 'qglGenTextures': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(403): error C3861: 'qglBindTexture': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(428): error C3861: 'qglCompressedTexImage2DARB': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(433): error C3861: 'qglTexImage2D': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(443): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(460): error C3861: 'qglDeleteTextures': identifier not found
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_Image.cpp.obj] Error 2
neo\renderer\RenderSystem_init.cpp(339): error C2664: 'void (GLDEBUGPROCARB,const void *)': cannot convert argument 1 from 'overloaded-function' to 'GLDEBUGPROCARB'
neo\renderer\RenderSystem_init.cpp(343): error C3861: 'glEnable': identifier not found
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderSystem_init.cpp.obj] Error 2
neo\renderer\tr_backend_rendertools.cpp(603): error C3861: 'glLoadMatrixf': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2164): error C3861: 'glEnable': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2165): error C3861: 'glClearColor': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2170): error C3861: 'glScissor': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2171): error C3861: 'glClear': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2175): error C3861: 'glScissor': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2176): error C3861: 'glClear': identifier not found
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\tr_backend_rendertools.cpp.obj] Error 2
neo\sys\win32\win_glimp.cpp(360): error C2065: 'ERROR_INVALID_VERSION_ARB': undeclared identifier
neo\sys\win32\win_glimp.cpp(361): error C2065: 'ERROR_INVALID_PROFILE_ARB': undeclared identifier
neo\sys\win32\win_glimp.cpp(360): error C2051: case expression not constant
neo\sys\win32\win_glimp.cpp(361): error C2051: case expression not constant
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\sys\win32\win_glimp.cpp.obj] Error 2
neo\tools\compilers\dmap\optimize.cpp(239): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(244): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(245): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(246): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(247): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(249): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(250): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(267): error C3861: 'qglEnable': identifier not found
neo\tools\compilers\dmap\optimize.cpp(268): error C3861: 'qglBlendFunc': identifier not found
neo\tools\compilers\dmap\optimize.cpp(269): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(270): error C3861: 'qglPointSize': identifier not found
neo\tools\compilers\dmap\optimize.cpp(271): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(273): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(275): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(276): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\dmap\optimize.cpp(277): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(294): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(299): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(300): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(301): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(302): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(304): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(305): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(483): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(484): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(485): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(486): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(487): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(488): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(690): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(691): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(692): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(693): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(694): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(695): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(696): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(697): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(698): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(699): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(700): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(701): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(968): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(969): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(970): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(971): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(972): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(973): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(974): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(975): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(976): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(977): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(978): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(979): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1002): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1003): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1004): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1005): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1006): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1007): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1020): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1021): error C3861: 'qglPointSize': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1022): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1023): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1024): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1025): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1042): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1044): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1046): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1047): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1048): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1049): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1050): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1051): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1052): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1053): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1054): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1055): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1056): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1057): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1370): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1372): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1373): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1374): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1375): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1377): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1378): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1496): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1497): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1498): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1499): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1500): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1501): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1502): error C3861: 'qglFlush': identifier not found
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\tools\compilers\dmap\optimize.cpp.obj] Error 2
neo\tools\compilers\renderbump\renderbump.cpp(929): error C3861: 'RB_SetGL2D': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(931): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(933): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(935): error C3861: 'qglMatrixMode': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(936): error C3861: 'qglLoadIdentity': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(937): error C3861: 'qglOrtho': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(938): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(939): error C3861: 'qglMatrixMode': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(940): error C3861: 'qglLoadIdentity': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(942): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(944): error C3861: 'qglClearColor': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(945): error C3861: 'qglClear': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(947): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(981): error C3861: 'qglClearColor': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(982): error C3861: 'qglClear': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(983): error C3861: 'qglRasterPos2f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(984): error C3861: 'qglPixelZoom': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(985): error C3861: 'qglDrawPixels': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(986): error C3861: 'qglPixelZoom': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(987): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1422): error C3861: 'qglViewport': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1424): error C3861: 'qglEnable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1425): error C3861: 'qglCullFace': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1426): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1427): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1428): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1429): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1430): error C3861: 'qglEnable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1431): error C3861: 'qglDisable': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1432): error C3861: 'qglDepthMask': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1433): error C3861: 'qglDepthFunc': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1435): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1437): error C3861: 'qglMatrixMode': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1438): error C3861: 'qglLoadIdentity': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1439): error C3861: 'qglOrtho': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1442): error C3861: 'qglMatrixMode': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1443): error C3861: 'qglLoadIdentity': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1471): error C3861: 'qglClearColor': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1472): error C3861: 'qglClear': identifier not found
neo\tools\compilers\renderbump\renderbump.cpp(1474): error C3861: 'qglBegin': identifier not found

### failure context

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\gl_backend.cpp.obj

```
Compiling 'neo\renderer\Cinematic.cpp'
Cinematic.cpp
Compiling 'neo\renderer\CinematicBink.cpp'
CinematicBink.cpp
Compiling 'neo\renderer\CinematicRoQ.cpp'
CinematicRoQ.cpp
Compiling 'neo\renderer\Color\ColorSpace.cpp'
ColorSpace.cpp
neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
Compiling 'neo\renderer\DeclRenderProg.cpp'
DeclRenderProg.cpp
Compiling 'neo\renderer\DeclRenderProgGenerator.cpp'
DeclRenderProgGenerator.cpp
Compiling 'neo\renderer\DXT\DXTDecoder.cpp'
DXTDecoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder.cpp'
DXTEncoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder_SSE2.cpp'
DXTEncoder_SSE2.cpp
Compiling 'neo\renderer\Font.cpp'
Font.cpp
Compiling 'neo\renderer\gl_backend.cpp'
gl_backend.cpp
Compiling 'neo\renderer\gl_GraphicsAPIWrapper.cpp'
gl_GraphicsAPIWrapper.cpp
Compiling 'neo\renderer\gl_Image.cpp'
gl_Image.cpp
neo\renderer\gl_backend.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
Compiling 'neo\renderer\GLMatrix.cpp'
GLMatrix.cpp
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\gl_backend.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\gl_GraphicsAPIWrapper.cpp.obj

```
Compiling 'neo\renderer\CinematicRoQ.cpp'
CinematicRoQ.cpp
Compiling 'neo\renderer\Color\ColorSpace.cpp'
ColorSpace.cpp
neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
Compiling 'neo\renderer\DeclRenderProg.cpp'
DeclRenderProg.cpp
Compiling 'neo\renderer\DeclRenderProgGenerator.cpp'
DeclRenderProgGenerator.cpp
Compiling 'neo\renderer\DXT\DXTDecoder.cpp'
DXTDecoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder.cpp'
DXTEncoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder_SSE2.cpp'
DXTEncoder_SSE2.cpp
Compiling 'neo\renderer\Font.cpp'
Font.cpp
Compiling 'neo\renderer\gl_backend.cpp'
gl_backend.cpp
Compiling 'neo\renderer\gl_GraphicsAPIWrapper.cpp'
gl_GraphicsAPIWrapper.cpp
Compiling 'neo\renderer\gl_Image.cpp'
gl_Image.cpp
neo\renderer\gl_backend.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
Compiling 'neo\renderer\GLMatrix.cpp'
GLMatrix.cpp
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\gl_backend.cpp.obj] Error 2
Compiling 'neo\renderer\GuiModel.cpp'
neo\renderer\gl_GraphicsAPIWrapper.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
GuiModel.cpp
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\gl_GraphicsAPIWrapper.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\gl_Image.cpp.obj

```
neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
Compiling 'neo\renderer\DeclRenderProg.cpp'
DeclRenderProg.cpp
Compiling 'neo\renderer\DeclRenderProgGenerator.cpp'
DeclRenderProgGenerator.cpp
Compiling 'neo\renderer\DXT\DXTDecoder.cpp'
DXTDecoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder.cpp'
DXTEncoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder_SSE2.cpp'
DXTEncoder_SSE2.cpp
Compiling 'neo\renderer\Font.cpp'
Font.cpp
Compiling 'neo\renderer\gl_backend.cpp'
gl_backend.cpp
Compiling 'neo\renderer\gl_GraphicsAPIWrapper.cpp'
gl_GraphicsAPIWrapper.cpp
Compiling 'neo\renderer\gl_Image.cpp'
gl_Image.cpp
neo\renderer\gl_backend.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
Compiling 'neo\renderer\GLMatrix.cpp'
GLMatrix.cpp
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\gl_backend.cpp.obj] Error 2
Compiling 'neo\renderer\GuiModel.cpp'
neo\renderer\gl_GraphicsAPIWrapper.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
GuiModel.cpp
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\gl_GraphicsAPIWrapper.cpp.obj] Error 2
Compiling 'neo\renderer\Image_files.cpp'
Image_files.cpp
neo\renderer\gl_Image.cpp(37): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\gl_Image.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_backend.cpp.obj

```
gl_Image.cpp
ParmBlock.cpp
neo\renderer\OpenGL\gl_backend.cpp(64): error C3861: 'qglClearColor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(66): error C3861: 'qglClearColor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(68): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(69): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(118): error C3861: 'qglFinish': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(137): error C3861: 'qglIsSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(138): error C3861: 'qglDeleteSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(142): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(143): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(144): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(145): error C3861: 'qglFenceSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(158): error C3861: 'qglIsSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(160): error C3861: 'qglClientWaitSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(168): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(169): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(170): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(172): error C3861: 'qglFinish': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(252): error C3861: 'qglColorMask': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(254): error C3861: 'qglFlush': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(276): error C3861: 'qglViewport': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(278): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(280): error C3861: 'qglMatrixMode': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(281): error C3861: 'qglLoadIdentity': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(282): error C3861: 'qglOrtho': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(283): error C3861: 'qglMatrixMode': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(284): error C3861: 'qglLoadIdentity': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(292): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(293): error C3861: 'qglDisable': identifier not found
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_backend.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp.obj

```
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(250): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(251): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(254): error C3861: 'qglShadeModel': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(255): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(256): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(257): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(258): error C3861: 'qglDrawBuffer': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(259): error C3861: 'qglReadBuffer': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(262): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(289): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(290): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(291): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(292): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(333): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(335): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(336): error C3861: 'qglBlendFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(345): error C3861: 'qglDepthMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(347): error C3861: 'qglDepthMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(359): error C3861: 'qglColorMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(367): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(369): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(378): error C3861: 'qglPolygonOffset': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(379): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(380): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(382): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(383): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(415): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(417): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(435): error C3861: 'qglStencilFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(472): error C3861: 'qglStencilOp': identifier not found
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_Image.cpp.obj

```
neo\renderer\OpenGL\gl_Image.cpp(183): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(184): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(185): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(186): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(205): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(207): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(209): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(212): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(213): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(216): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(217): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(233): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(235): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(240): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(246): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(247): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(251): error C3861: 'qglTexParameterfv': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(252): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(253): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(258): error C3861: 'qglTexParameterfv': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(259): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(260): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(264): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(265): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(380): error C3861: 'qglGenTextures': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(403): error C3861: 'qglBindTexture': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(428): error C3861: 'qglCompressedTexImage2DARB': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(433): error C3861: 'qglTexImage2D': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(443): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(460): error C3861: 'qglDeleteTextures': identifier not found
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_Image.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderSystem_init.cpp.obj

```
neo\renderer\OpenGL\gl_Image.cpp(259): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(260): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(264): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(265): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(380): error C3861: 'qglGenTextures': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(403): error C3861: 'qglBindTexture': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(428): error C3861: 'qglCompressedTexImage2DARB': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(433): error C3861: 'qglTexImage2D': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(443): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(460): error C3861: 'qglDeleteTextures': identifier not found
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_Image.cpp.obj] Error 2
Compiling 'neo\renderer\RenderLog.cpp'
RenderLog.cpp
Compiling 'neo\renderer\RenderProgParm.cpp'
RenderProgParm.cpp
Compiling 'neo\renderer\RenderProgs.cpp'
RenderProgs.cpp
Compiling 'neo\renderer\RenderSystem.cpp'
RenderSystem.cpp
Compiling 'neo\renderer\RenderSystem_init.cpp'
RenderSystem_init.cpp
Compiling 'neo\renderer\RenderWorld.cpp'
RenderWorld.cpp
Compiling 'neo\renderer\RenderWorld_defs.cpp'
RenderWorld_defs.cpp
Compiling 'neo\renderer\RenderWorld_demo.cpp'
RenderWorld_demo.cpp
neo\renderer\RenderSystem_init.cpp(339): error C2664: 'void (GLDEBUGPROCARB,const void *)': cannot convert argument 1 from 'overloaded-function' to 'GLDEBUGPROCARB'
neo\renderer\RenderSystem_init.cpp(339): note: None of the functions with this name in scope match the target type
neo\renderer\RenderSystem_init.cpp(343): error C3861: 'glEnable': identifier not found
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderSystem_init.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\tr_backend_rendertools.cpp.obj

```
Compiling 'neo\renderer\RenderWorld_load.cpp'
RenderWorld_load.cpp
Compiling 'neo\renderer\RenderWorld_portals.cpp'
RenderWorld_portals.cpp
Compiling 'neo\renderer\ResolutionScale.cpp'
ResolutionScale.cpp
Compiling 'neo\renderer\ScreenRect.cpp'
ScreenRect.cpp
Compiling 'neo\renderer\stblib_impls.c'
stblib_impls.c
Compiling 'neo\renderer\tr_backend_draw.cpp'
tr_backend_draw.cpp
Compiling 'neo\renderer\tr_backend_rendertools.cpp'
tr_backend_rendertools.cpp
Compiling 'neo\renderer\tr_frontend_addlights.cpp'
tr_frontend_addlights.cpp
Compiling 'neo\renderer\tr_frontend_addmodels.cpp'
tr_frontend_addmodels.cpp
neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_draw.cpp(1498): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_draw.cpp(1516): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_draw.cpp(1536): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_rendertools.cpp(603): error C3861: 'glLoadMatrixf': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2164): error C3861: 'glEnable': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2165): error C3861: 'glClearColor': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2170): error C3861: 'glScissor': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2171): error C3861: 'glClear': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2175): error C3861: 'glScissor': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2176): error C3861: 'glClear': identifier not found
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\tr_backend_rendertools.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\sys\win32\win_glimp.cpp.obj

```
sys_profile.cpp
Compiling 'neo\sys\sys_savegame.cpp'
sys_savegame.cpp
Compiling 'neo\sys\sys_session_callbacks.cpp'
sys_session_callbacks.cpp
Compiling 'neo\sys\sys_session_local.cpp'
sys_session_local.cpp
Compiling 'neo\sys\sys_session_savegames.cpp'
sys_session_savegames.cpp
Compiling 'neo\sys\sys_signin.cpp'
sys_signin.cpp
Compiling 'neo\sys\sys_voicechat.cpp'
sys_voicechat.cpp
Compiling 'neo\sys\win32\win_achievements.cpp'
win_achievements.cpp
Compiling 'neo\sys\win32\win_cpu.cpp'
win_cpu.cpp
Compiling 'neo\sys\win32\win_glimp.cpp'
Compiling 'neo\sys\win32\win_input.cpp'
win_glimp.cpp
win_input.cpp
Compiling 'neo\sys\win32\win_localuser.cpp'
win_localuser.cpp
Compiling 'neo\sys\win32\win_main.cpp'
win_main.cpp
neo\sys\win32\win_glimp.cpp(360): error C2065: 'ERROR_INVALID_VERSION_ARB': undeclared identifier
neo\sys\win32\win_glimp.cpp(361): error C2065: 'ERROR_INVALID_PROFILE_ARB': undeclared identifier
neo\sys\win32\win_glimp.cpp(360): error C2051: case expression not constant
neo\sys\win32\win_glimp.cpp(361): error C2051: case expression not constant
neo\sys\win32\win_glimp.cpp(363): warning C4065: switch statement contains 'default' but no 'case' labels
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\sys\win32\win_glimp.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\DoomEXE\tools\compilers\dmap\optimize.cpp.obj

```
neo\tools\compilers\dmap\optimize.cpp(1024): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1025): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1042): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1044): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1046): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1047): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1048): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1049): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1050): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1051): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1052): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1053): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1054): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1055): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1056): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1057): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1370): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1372): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1373): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1374): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1375): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1377): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1378): error C3861: 'qglFlush': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1496): error C3861: 'qglBegin': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1497): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1498): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1499): error C3861: 'qglColor3f': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1500): error C3861: 'qglVertex3fv': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1501): error C3861: 'qglEnd': identifier not found
neo\tools\compilers\dmap\optimize.cpp(1502): error C3861: 'qglFlush': identifier not found
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\tools\compilers\dmap\optimize.cpp.obj] Error 2
```


### warning kinds

- [9x] C4389
  - neo\d3xp\gamesys\Event.cpp(786): warning C4389: '==': signed/unsigned mismatch
  - neo\d3xp\gamesys\Event.cpp(853): warning C4389: '!=': signed/unsigned mismatch
  - neo\d3xp\gamesys\Event.cpp(903): warning C4389: '==': signed/unsigned mismatch
  - neo\d3xp\gamesys\Event.cpp(943): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1498): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1516): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1536): warning C4389: '!=': signed/unsigned mismatch
- [3x] C4245
  - neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [3x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\external\stb\stb_vorbis.h(4849) : warning C4701: potentially uninitialized local variable 'mid' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\aas\AASReach.cpp(267) : warning C4701: potentially uninitialized local variable 'edge1Num' used
  - D:\a\Doom3BFG\Doom3BFG\neo\tools\compilers\amplitude\amplitude.cpp(177) : warning C4701: potentially uninitialized local variable 'format' used
- [1x] C4065
  - neo\sys\win32\win_glimp.cpp(363): warning C4065: switch statement contains 'default' but no 'case' labels

## windows-x86-release

status: cancelled

errors: 161
warnings: 17 in 4 kinds

### errors

neo\renderer\gl_backend.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\gl_backend.cpp.obj] Error 2
neo\renderer\gl_GraphicsAPIWrapper.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\gl_GraphicsAPIWrapper.cpp.obj] Error 2
neo\renderer\gl_Image.cpp(37): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\gl_Image.cpp.obj] Error 2
neo\renderer\OpenGL\gl_backend.cpp(64): error C3861: 'qglClearColor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(66): error C3861: 'qglClearColor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(68): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(69): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(118): error C3861: 'qglFinish': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(137): error C3861: 'qglIsSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(138): error C3861: 'qglDeleteSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(142): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(143): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(144): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(145): error C3861: 'qglFenceSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(158): error C3861: 'qglIsSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(160): error C3861: 'qglClientWaitSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(168): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(169): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(170): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(172): error C3861: 'qglFinish': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(252): error C3861: 'qglColorMask': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(254): error C3861: 'qglFlush': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(276): error C3861: 'qglViewport': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(278): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(280): error C3861: 'qglMatrixMode': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(281): error C3861: 'qglLoadIdentity': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(282): error C3861: 'qglOrtho': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(283): error C3861: 'qglMatrixMode': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(284): error C3861: 'qglLoadIdentity': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(292): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(293): error C3861: 'qglDisable': identifier not found
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_backend.cpp.obj] Error 2
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(68): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(71): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(76): error C3861: 'qglCullFace': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(78): error C3861: 'qglCullFace': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(82): error C3861: 'qglCullFace': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(84): error C3861: 'qglCullFace': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(98): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(107): error C3861: 'qglViewport': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(119): error C3861: 'qglPolygonOffset': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(134): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(136): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(137): error C3861: 'qglDepthBoundsEXT': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(209): error C3861: 'qglClearColor': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(216): error C3861: 'qglClearStencil': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(219): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(233): error C3861: 'qglClearDepth': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(240): error C3861: 'qglCullFace': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(241): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(244): error C3861: 'qglColorMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(245): error C3861: 'qglBlendFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(246): error C3861: 'qglDepthMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(247): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(248): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(249): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(250): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(251): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(254): error C3861: 'qglShadeModel': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(255): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(256): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(257): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(258): error C3861: 'qglDrawBuffer': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(259): error C3861: 'qglReadBuffer': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(262): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(289): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(290): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(291): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(292): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(333): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(335): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(336): error C3861: 'qglBlendFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(345): error C3861: 'qglDepthMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(347): error C3861: 'qglDepthMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(359): error C3861: 'qglColorMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(367): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(369): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(378): error C3861: 'qglPolygonOffset': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(379): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(380): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(382): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(383): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(415): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(417): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(435): error C3861: 'qglStencilFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(472): error C3861: 'qglStencilOp': identifier not found
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp.obj] Error 2
neo\renderer\OpenGL\gl_Image.cpp(88): error C3861: 'qglBindTexture': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(91): error C3861: 'qglPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(94): error C3861: 'glPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(100): error C3861: 'qglCompressedTexSubImage2DARB': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(108): error C3861: 'qglPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(110): error C3861: 'qglPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(113): error C3861: 'qglTexSubImage2D': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(119): error C3861: 'glPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(122): error C3861: 'qglPixelStorei': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(158): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(159): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(160): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(161): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(163): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(164): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(165): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(166): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(168): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(169): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(170): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(171): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(173): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(174): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(175): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(176): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(178): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(179): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(180): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(181): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(183): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(184): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(185): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(186): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(205): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(207): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(209): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(212): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(213): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(216): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(217): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(233): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(235): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(240): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(246): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(247): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(251): error C3861: 'qglTexParameterfv': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(252): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(253): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(258): error C3861: 'qglTexParameterfv': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(259): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(260): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(264): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(265): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(380): error C3861: 'qglGenTextures': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(403): error C3861: 'qglBindTexture': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(428): error C3861: 'qglCompressedTexImage2DARB': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(433): error C3861: 'qglTexImage2D': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(443): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(460): error C3861: 'qglDeleteTextures': identifier not found
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_Image.cpp.obj] Error 2
neo\renderer\RenderSystem_init.cpp(339): error C2664: 'void (GLDEBUGPROCARB,const void *)': cannot convert argument 1 from 'overloaded-function' to 'GLDEBUGPROCARB'
neo\renderer\RenderSystem_init.cpp(343): error C3861: 'glEnable': identifier not found
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\RenderSystem_init.cpp.obj] Error 2
neo\renderer\tr_backend_rendertools.cpp(603): error C3861: 'glLoadMatrixf': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2164): error C3861: 'glEnable': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2165): error C3861: 'glClearColor': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2170): error C3861: 'glScissor': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2171): error C3861: 'glClear': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2175): error C3861: 'glScissor': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2176): error C3861: 'glClear': identifier not found
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\tr_backend_rendertools.cpp.obj] Error 2

### failure context

- build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\gl_backend.cpp.obj

```
Compiling 'neo\renderer\Cinematic.cpp'
Cinematic.cpp
Compiling 'neo\renderer\CinematicBink.cpp'
CinematicBink.cpp
Compiling 'neo\renderer\CinematicRoQ.cpp'
CinematicRoQ.cpp
Compiling 'neo\renderer\Color\ColorSpace.cpp'
ColorSpace.cpp
Compiling 'neo\renderer\DeclRenderProg.cpp'
DeclRenderProg.cpp
neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
Compiling 'neo\renderer\DeclRenderProgGenerator.cpp'
DeclRenderProgGenerator.cpp
Compiling 'neo\renderer\DXT\DXTDecoder.cpp'
DXTDecoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder.cpp'
DXTEncoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder_SSE2.cpp'
DXTEncoder_SSE2.cpp
Compiling 'neo\renderer\Font.cpp'
Font.cpp
Compiling 'neo\renderer\gl_backend.cpp'
gl_backend.cpp
Compiling 'neo\renderer\gl_GraphicsAPIWrapper.cpp'
gl_GraphicsAPIWrapper.cpp
Compiling 'neo\renderer\gl_Image.cpp'
gl_Image.cpp
Compiling 'neo\renderer\GLMatrix.cpp'
GLMatrix.cpp
neo\renderer\gl_backend.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\gl_backend.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\gl_GraphicsAPIWrapper.cpp.obj

```
Compiling 'neo\renderer\CinematicRoQ.cpp'
CinematicRoQ.cpp
Compiling 'neo\renderer\Color\ColorSpace.cpp'
ColorSpace.cpp
Compiling 'neo\renderer\DeclRenderProg.cpp'
DeclRenderProg.cpp
neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
Compiling 'neo\renderer\DeclRenderProgGenerator.cpp'
DeclRenderProgGenerator.cpp
Compiling 'neo\renderer\DXT\DXTDecoder.cpp'
DXTDecoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder.cpp'
DXTEncoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder_SSE2.cpp'
DXTEncoder_SSE2.cpp
Compiling 'neo\renderer\Font.cpp'
Font.cpp
Compiling 'neo\renderer\gl_backend.cpp'
gl_backend.cpp
Compiling 'neo\renderer\gl_GraphicsAPIWrapper.cpp'
gl_GraphicsAPIWrapper.cpp
Compiling 'neo\renderer\gl_Image.cpp'
gl_Image.cpp
Compiling 'neo\renderer\GLMatrix.cpp'
GLMatrix.cpp
neo\renderer\gl_backend.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\gl_backend.cpp.obj] Error 2
Compiling 'neo\renderer\GuiModel.cpp'
GuiModel.cpp
neo\renderer\gl_GraphicsAPIWrapper.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\gl_GraphicsAPIWrapper.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\gl_Image.cpp.obj

```
Compiling 'neo\renderer\DeclRenderProg.cpp'
DeclRenderProg.cpp
neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
Compiling 'neo\renderer\DeclRenderProgGenerator.cpp'
DeclRenderProgGenerator.cpp
Compiling 'neo\renderer\DXT\DXTDecoder.cpp'
DXTDecoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder.cpp'
DXTEncoder.cpp
Compiling 'neo\renderer\DXT\DXTEncoder_SSE2.cpp'
DXTEncoder_SSE2.cpp
Compiling 'neo\renderer\Font.cpp'
Font.cpp
Compiling 'neo\renderer\gl_backend.cpp'
gl_backend.cpp
Compiling 'neo\renderer\gl_GraphicsAPIWrapper.cpp'
gl_GraphicsAPIWrapper.cpp
Compiling 'neo\renderer\gl_Image.cpp'
gl_Image.cpp
Compiling 'neo\renderer\GLMatrix.cpp'
GLMatrix.cpp
neo\renderer\gl_backend.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\gl_backend.cpp.obj] Error 2
Compiling 'neo\renderer\GuiModel.cpp'
GuiModel.cpp
neo\renderer\gl_GraphicsAPIWrapper.cpp(32): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\gl_GraphicsAPIWrapper.cpp.obj] Error 2
Compiling 'neo\renderer\Image_files.cpp'
Image_files.cpp
neo\renderer\gl_Image.cpp(37): fatal error C1083: Cannot open include file: '../tr_local.h': No such file or directory
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\gl_Image.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_backend.cpp.obj

```
Compiling 'neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp'
gl_GraphicsAPIWrapper.cpp
neo\renderer\OpenGL\gl_backend.cpp(64): error C3861: 'qglClearColor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(66): error C3861: 'qglClearColor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(68): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(69): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(118): error C3861: 'qglFinish': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(137): error C3861: 'qglIsSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(138): error C3861: 'qglDeleteSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(142): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(143): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(144): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(145): error C3861: 'qglFenceSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(158): error C3861: 'qglIsSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(160): error C3861: 'qglClientWaitSync': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(168): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(169): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(170): error C3861: 'qglClear': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(172): error C3861: 'qglFinish': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(252): error C3861: 'qglColorMask': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(254): error C3861: 'qglFlush': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(276): error C3861: 'qglViewport': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(278): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(280): error C3861: 'qglMatrixMode': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(281): error C3861: 'qglLoadIdentity': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(282): error C3861: 'qglOrtho': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(283): error C3861: 'qglMatrixMode': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(284): error C3861: 'qglLoadIdentity': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(292): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_backend.cpp(293): error C3861: 'qglDisable': identifier not found
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_backend.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp.obj

```
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(250): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(251): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(254): error C3861: 'qglShadeModel': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(255): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(256): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(257): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(258): error C3861: 'qglDrawBuffer': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(259): error C3861: 'qglReadBuffer': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(262): error C3861: 'qglScissor': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(289): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(290): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(291): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(292): error C3861: 'qglDepthFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(333): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(335): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(336): error C3861: 'qglBlendFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(345): error C3861: 'qglDepthMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(347): error C3861: 'qglDepthMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(359): error C3861: 'qglColorMask': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(367): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(369): error C3861: 'qglPolygonMode': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(378): error C3861: 'qglPolygonOffset': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(379): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(380): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(382): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(383): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(415): error C3861: 'qglEnable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(417): error C3861: 'qglDisable': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(435): error C3861: 'qglStencilFunc': identifier not found
neo\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp(472): error C3861: 'qglStencilOp': identifier not found
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_Image.cpp.obj

```
neo\renderer\OpenGL\gl_Image.cpp(183): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(184): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(185): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(186): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(205): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(207): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(209): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(212): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(213): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(216): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(217): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(233): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(235): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(240): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(246): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(247): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(251): error C3861: 'qglTexParameterfv': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(252): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(253): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(258): error C3861: 'qglTexParameterfv': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(259): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(260): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(264): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(265): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(380): error C3861: 'qglGenTextures': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(403): error C3861: 'qglBindTexture': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(428): error C3861: 'qglCompressedTexImage2DARB': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(433): error C3861: 'qglTexImage2D': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(443): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(460): error C3861: 'qglDeleteTextures': identifier not found
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_Image.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\RenderSystem_init.cpp.obj

```
neo\renderer\OpenGL\gl_Image.cpp(259): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(260): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(264): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(265): error C3861: 'qglTexParameterf': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(380): error C3861: 'qglGenTextures': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(403): error C3861: 'qglBindTexture': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(428): error C3861: 'qglCompressedTexImage2DARB': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(433): error C3861: 'qglTexImage2D': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(443): error C3861: 'qglTexParameteri': identifier not found
neo\renderer\OpenGL\gl_Image.cpp(460): error C3861: 'qglDeleteTextures': identifier not found
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_Image.cpp.obj] Error 2
Compiling 'neo\renderer\RenderLog.cpp'
RenderLog.cpp
Compiling 'neo\renderer\RenderProgParm.cpp'
RenderProgParm.cpp
Compiling 'neo\renderer\RenderProgs.cpp'
Compiling 'neo\renderer\RenderSystem.cpp'
RenderProgs.cpp
RenderSystem.cpp
Compiling 'neo\renderer\RenderSystem_init.cpp'
RenderSystem_init.cpp
Compiling 'neo\renderer\RenderWorld.cpp'
RenderWorld.cpp
Compiling 'neo\renderer\RenderWorld_defs.cpp'
Compiling 'neo\renderer\RenderWorld_demo.cpp'
RenderWorld_defs.cpp
RenderWorld_demo.cpp
neo\renderer\RenderSystem_init.cpp(339): error C2664: 'void (GLDEBUGPROCARB,const void *)': cannot convert argument 1 from 'overloaded-function' to 'GLDEBUGPROCARB'
neo\renderer\RenderSystem_init.cpp(339): note: None of the functions with this name in scope match the target type
neo\renderer\RenderSystem_init.cpp(343): error C3861: 'glEnable': identifier not found
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\RenderSystem_init.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\tr_backend_rendertools.cpp.obj

```
Compiling 'neo\renderer\RenderWorld_load.cpp'
RenderWorld_load.cpp
Compiling 'neo\renderer\RenderWorld_portals.cpp'
RenderWorld_portals.cpp
Compiling 'neo\renderer\ResolutionScale.cpp'
ResolutionScale.cpp
Compiling 'neo\renderer\ScreenRect.cpp'
ScreenRect.cpp
Compiling 'neo\renderer\stblib_impls.c'
stblib_impls.c
Compiling 'neo\renderer\tr_backend_draw.cpp'
Compiling 'neo\renderer\tr_backend_rendertools.cpp'
Compiling 'neo\renderer\tr_frontend_addlights.cpp'
tr_backend_draw.cpp
tr_backend_rendertools.cpp
tr_frontend_addlights.cpp
Compiling 'neo\renderer\tr_frontend_addmodels.cpp'
tr_frontend_addmodels.cpp
neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_draw.cpp(1498): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_draw.cpp(1516): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_draw.cpp(1536): warning C4389: '!=': signed/unsigned mismatch
neo\renderer\tr_backend_rendertools.cpp(603): error C3861: 'glLoadMatrixf': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2164): error C3861: 'glEnable': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2165): error C3861: 'glClearColor': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2170): error C3861: 'glScissor': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2171): error C3861: 'glClear': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2175): error C3861: 'glScissor': identifier not found
neo\renderer\tr_backend_rendertools.cpp(2176): error C3861: 'glClear': identifier not found
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\tr_backend_rendertools.cpp.obj] Error 2
```


### warning kinds

- [7x] C4389
  - neo\d3xp\gamesys\Event.cpp(853): warning C4389: '!=': signed/unsigned mismatch
  - neo\d3xp\gamesys\Event.cpp(943): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(170): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(175): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1498): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1516): warning C4389: '!=': signed/unsigned mismatch
  - neo\renderer\tr_backend_draw.cpp(1536): warning C4389: '!=': signed/unsigned mismatch
- [6x] C4702
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(368) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1048) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1345) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1379) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1390) : warning C4702: unreachable code
  - D:\a\Doom3BFG\Doom3BFG\neo\d3xp\script\Script_Compiler.cpp(1422) : warning C4702: unreachable code
- [3x] C4245
  - neo\d3xp\Game_local.cpp(249): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\d3xp\Game_local.cpp(250): warning C4245: '=': conversion from 'int' to 'unsigned int', signed/unsigned mismatch
  - neo\renderer\CinematicBink.cpp(59): warning C4245: '=': conversion from 'int' to 'uint32', signed/unsigned mismatch
- [1x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\external\stb\stb_vorbis.h(4849) : warning C4701: potentially uninitialized local variable 'mid' used

