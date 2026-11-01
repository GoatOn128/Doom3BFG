/*
===========================================================================

Doom 3 BFG Edition GPL Source Code
Copyright (C) 1993-2012 id Software LLC, a ZeniMax Media company.

This file is part of the Doom 3 BFG Edition GPL Source Code ("Doom 3 BFG Edition Source Code").

Doom 3 BFG Edition Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Doom 3 BFG Edition Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Doom 3 BFG Edition Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 BFG Edition Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/
/*
** QGL.H
*/

/*
** QGL.H

Transition shim over the glad 2 loader. All GL entry points now live in the
global gladGL function-pointer context, which win_glimp.cpp loads right after
the rendering context is created and made current. The old qgl* names are
kept as macros so the existing call sites compile unchanged while the qgl
function-pointer wrapper is removed in stages.
*/

#ifndef __QGL_H__
#define __QGL_H__

#include <glad/gl.h>

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef WINAPI
#define WINAPI
#endif

// the global GL function-pointer context; loaded with
// gladLoaderLoadGLContext( &gladGL ) once the context is current
extern GladGLContext gladGL;

typedef void (*GLExtension_t)(void);

#ifdef __cplusplus
extern "C" {
#endif

GLExtension_t GLimp_ExtensionPointer( const char *name );

#ifdef __cplusplus
}
#endif

#ifdef _WIN32
#define qwglCreateContext wglCreateContext
#define qwglDeleteContext wglDeleteContext
#define qwglMakeCurrent	wglMakeCurrent
#define qwglSwapBuffers SwapBuffers
#define qwglGetProcAddress wglGetProcAddress
#endif

// old-style qgl names forwarded to the matching glad context member
#define qglActiveTextureARB gladGL.ActiveTextureARB
#define qglAlphaFunc gladGL.AlphaFunc
#define qglArrayElement gladGL.ArrayElement
#define qglAttachShader gladGL.AttachShader
#define qglBegin gladGL.Begin
#define qglBeginQueryARB gladGL.BeginQueryARB
#define qglBindAttribLocation gladGL.BindAttribLocation
#define qglBindBufferARB gladGL.BindBufferARB
#define qglBindBufferRange gladGL.BindBufferRange
#define qglBindFragDataLocation gladGL.BindFragDataLocation
#define qglBindMultiTextureEXT gladGL.BindMultiTextureEXT
#define qglBindTexture gladGL.BindTexture
#define qglBindVertexArray gladGL.BindVertexArray
#define qglBlendFunc gladGL.BlendFunc
#define qglBufferDataARB gladGL.BufferDataARB
#define qglBufferSubDataARB gladGL.BufferSubDataARB
#define qglClear gladGL.Clear
#define qglClearColor gladGL.ClearColor
#define qglClearDepth gladGL.ClearDepth
#define qglClearStencil gladGL.ClearStencil
#define qglClientWaitSync gladGL.ClientWaitSync
#define qglColor3fv gladGL.Color3fv
#define qglColor4fv gladGL.Color4fv
#define qglColor4ubv gladGL.Color4ubv
#define qglColorMask gladGL.ColorMask
#define qglCompileShader gladGL.CompileShader
#define qglCompressedTexImage2DARB gladGL.CompressedTexImage2DARB
#define qglCompressedTexSubImage2DARB gladGL.CompressedTexSubImage2DARB
#define qglCopyBufferSubDataARB gladGL.CopyBufferSubData
#define qglCopyTexImage2D gladGL.CopyTexImage2D
#define qglCreateProgram gladGL.CreateProgram
#define qglCreateShader gladGL.CreateShader
#define qglCullFace gladGL.CullFace
#define qglDebugMessageCallbackARB gladGL.DebugMessageCallbackARB
#define qglDebugMessageControlARB gladGL.DebugMessageControlARB
#define qglDebugMessageInsertARB gladGL.DebugMessageInsertARB
#define qglDeleteBuffersARB gladGL.DeleteBuffersARB
#define qglDeleteProgram gladGL.DeleteProgram
#define qglDeleteQueriesARB gladGL.DeleteQueriesARB
#define qglDeleteShader gladGL.DeleteShader
#define qglDeleteSync gladGL.DeleteSync
#define qglDeleteTextures gladGL.DeleteTextures
#define qglDeleteVertexArrays gladGL.DeleteVertexArrays
#define qglDepthBoundsEXT gladGL.DepthBoundsEXT
#define qglDepthFunc gladGL.DepthFunc
#define qglDepthMask gladGL.DepthMask
#define qglDetachShader gladGL.DetachShader
#define qglDisable gladGL.Disable
#define qglDisableVertexAttribArrayARB gladGL.DisableVertexAttribArrayARB
#define qglDrawBuffer gladGL.DrawBuffer
#define qglDrawElementsBaseVertex gladGL.DrawElementsBaseVertex
#define qglDrawPixels gladGL.DrawPixels
#define qglEnable gladGL.Enable
#define qglEnableVertexAttribArrayARB gladGL.EnableVertexAttribArrayARB
#define qglEnd gladGL.End
#define qglEndQueryARB gladGL.EndQueryARB
#define qglFenceSync gladGL.FenceSync
#define qglFinish gladGL.Finish
#define qglFlush gladGL.Flush
#define qglGenBuffersARB gladGL.GenBuffersARB
#define qglGenQueriesARB gladGL.GenQueriesARB
#define qglGenTextures gladGL.GenTextures
#define qglGenVertexArrays gladGL.GenVertexArrays
#define qglGetBufferParameterivARB gladGL.GetBufferParameterivARB
#define qglGetBufferPointervARB gladGL.GetBufferPointervARB
#define qglGetBufferSubDataARB gladGL.GetBufferSubDataARB
#define qglGetCompressedTexImageARB gladGL.GetCompressedTexImageARB
#define qglGetDebugMessageLogARB gladGL.GetDebugMessageLogARB
#define qglGetError gladGL.GetError
#define qglGetFloatv gladGL.GetFloatv
#define qglGetIntegerv gladGL.GetIntegerv
#define qglGetProgramInfoLog gladGL.GetProgramInfoLog
#define qglGetProgramiv gladGL.GetProgramiv
#define qglGetQueryivARB gladGL.GetQueryivARB
#define qglGetQueryObjectivARB gladGL.GetQueryObjectivARB
#define qglGetQueryObjectui64vEXT gladGL.GetQueryObjectui64vEXT
#define qglGetQueryObjectuivARB gladGL.GetQueryObjectuivARB
#define qglGetShaderInfoLog gladGL.GetShaderInfoLog
#define qglGetShaderiv gladGL.GetShaderiv
#define qglGetString gladGL.GetString
#define qglGetStringi gladGL.GetStringi
#define qglGetUniformBlockIndex gladGL.GetUniformBlockIndex
#define qglGetUniformLocation gladGL.GetUniformLocation
#define qglIsBufferARB gladGL.IsBufferARB
#define qglIsQueryARB gladGL.IsQueryARB
#define qglIsSync gladGL.IsSync
#define qglLineWidth gladGL.LineWidth
#define qglLinkProgram gladGL.LinkProgram
#define qglLoadIdentity gladGL.LoadIdentity
#define qglLoadMatrixf gladGL.LoadMatrixf
#define qglMapBufferARB gladGL.MapBufferARB
#define qglMapBufferRange gladGL.MapBufferRange
#define qglMatrixMode gladGL.MatrixMode
#define qglOrtho gladGL.Ortho
#define qglPixelStorei gladGL.PixelStorei
#define qglPolygonMode gladGL.PolygonMode
#define qglPolygonOffset gladGL.PolygonOffset
#define qglPopAttrib gladGL.PopAttrib
#define qglPopMatrix gladGL.PopMatrix
#define qglProgramParameteri gladGL.ProgramParameteri
#define qglPushAttrib gladGL.PushAttrib
#define qglPushMatrix gladGL.PushMatrix
#define qglRasterPos2f gladGL.RasterPos2f
#define qglReadBuffer gladGL.ReadBuffer
#define qglReadPixels gladGL.ReadPixels
#define qglScissor gladGL.Scissor
#define qglShadeModel gladGL.ShadeModel
#define qglShaderSource gladGL.ShaderSource
#define qglStencilFunc gladGL.StencilFunc
#define qglStencilFuncSeparate gladGL.StencilFuncSeparate
#define qglStencilOp gladGL.StencilOp
#define qglStencilOpSeparate gladGL.StencilOpSeparate
#define qglTexImage2D gladGL.TexImage2D
#define qglTexParameterf gladGL.TexParameterf
#define qglTexParameterfv gladGL.TexParameterfv
#define qglTexParameteri gladGL.TexParameteri
#define qglTexSubImage2D gladGL.TexSubImage2D
#define qglUniform1i gladGL.Uniform1i
#define qglUniform4fv gladGL.Uniform4fv
#define qglUniformBlockBinding gladGL.UniformBlockBinding
#define qglUnmapBufferARB gladGL.UnmapBufferARB
#define qglUseProgram gladGL.UseProgram
#define qglVertex3f gladGL.Vertex3f
#define qglVertex3fv gladGL.Vertex3fv
#define qglVertexAttribPointerARB gladGL.VertexAttribPointerARB
#define qglVertexPointer gladGL.VertexPointer
#define qglViewport gladGL.Viewport

#endif
