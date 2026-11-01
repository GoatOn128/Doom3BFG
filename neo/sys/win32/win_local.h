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

#ifndef __WIN_LOCAL_H__
#define __WIN_LOCAL_H__

#include <windows.h>
// Windows OpenGL extension entry points and attributes, inlined from the
// Khronos WGL extension specifications (WGL_EXT_swap_control,
// WGL_ARB_pixel_format, WGL_ARB_create_context) instead of the old wglext.h
typedef BOOL (WINAPI *PFNWGLSWAPINTERVALEXTPROC)( int interval );
typedef BOOL (WINAPI *PFNWGLCHOOSEPIXELFORMATARBPROC)( HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats );
typedef HGLRC (WINAPI *PFNWGLCREATECONTEXTATTRIBSARBPROC)( HDC hDC, HGLRC hShareContext, const int *attribList );

#ifndef WGL_CONTEXT_DEBUG_BIT_ARB
#define WGL_CONTEXT_DEBUG_BIT_ARB					0x00000001
#define WGL_CONTEXT_MAJOR_VERSION_ARB				0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB				0x2092
#define WGL_CONTEXT_FLAGS_ARB						0x2094
#define WGL_CONTEXT_PROFILE_MASK_ARB				0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB			0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB	0x00000002
// WGL_ARB_create_context error codes returned by GetLastError()
#define ERROR_INVALID_VERSION_ARB					0x2095
#define ERROR_INVALID_PROFILE_ARB					0x2096
#define WGL_DOUBLE_BUFFER_ARB						0x2011
#define WGL_RED_BITS_ARB							0x2015
#define WGL_GREEN_BITS_ARB							0x2017
#define WGL_BLUE_BITS_ARB							0x2018
#define WGL_ALPHA_BITS_ARB							0x201A
#define WGL_DEPTH_BITS_ARB							0x2022
#define WGL_STENCIL_BITS_ARB						0x2023
#define WGL_SAMPLE_BUFFERS_ARB						0x2042
#define WGL_SAMPLES_ARB								0x2043
// WGL_ARB_pixel_format selection attributes used by GLW_ChoosePixelFormat
#define WGL_DRAW_TO_WINDOW_ARB						0x2001
#define WGL_PIXEL_TYPE_ARB							0x2003
#define WGL_SUPPORT_OPENGL_ARB						0x2010
#define WGL_TYPE_RGBA_ARB							0x202B
#endif
#include "win_input.h"

// WGL_EXT_swap_interval
extern	PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;

// WGL_ARB_pixel_format
extern	PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;

#define	WINDOW_STYLE	(WS_OVERLAPPED|WS_BORDER|WS_CAPTION|WS_VISIBLE|WS_THICKFRAME|WS_SYSMENU)

void	Sys_QueEvent( sysEventType_t type, int value, int value2, int ptrLength, void *ptr, int inputDeviceNum );

void	Sys_CreateConsole();
void	Sys_DestroyConsole();

char	*Sys_ConsoleInput ();

void	Win_SetErrorText( const char *text );

cpuid_t	Sys_GetCPUId();

uint64 Sys_Microseconds();

// window procedure
LRESULT CALLBACK MainWndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void Conbuf_AppendText( const char *msg );

struct Win32Vars_t {
	HWND			hWnd;
	HINSTANCE		hInstance;

	bool			activeApp;			// changed with WM_ACTIVATE messages
	bool			movingWindow;		// inhibit mouse grab when dragging the window

	OSVERSIONINFOEX	osversion;

	cpuid_t			cpuid;

	// when we get a windows message, we store the time off so keyboard processing
	// can know the exact time of an event (not really needed now that we use async direct input)
	int				sysMsgTime;

	bool			windowClassRegistered;

	WNDPROC			wndproc;

	HDC				hDC;							// handle to device context
	HGLRC			hGLRC;						// handle to GL rendering context
	PIXELFORMATDESCRIPTOR pfd;
	int				pixelformat;

	int				desktopBitsPixel;
	int				desktopWidth, desktopHeight;

	int				cdsFullscreen;	// 0 = not fullscreen, otherwise monitor number

	idFileHandle	log_fp;

	unsigned short	oldHardwareGamma[3][256];
	// desktop gamma is saved here for restoration at exit

	static idCVar	sys_arch;
	static idCVar	sys_cpustring;
	static idCVar	win_outputEditString;
	static idCVar	win_viewlog;
	static idCVar	win_timerUpdate;

	CRITICAL_SECTION criticalSections[MAX_CRITICAL_SECTIONS];

	int				wglErrors;

};

extern Win32Vars_t	win32;

#endif /* !__WIN_LOCAL_H__ */
