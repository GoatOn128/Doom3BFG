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

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 BFG Edition Source Code.  If not, please request a copy in writing to id Software at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing to id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#ifndef __MENUFORMAT_H__
#define __MENUFORMAT_H__

// Team Arena / RTCW / ET .menu support, translated onto the Doom 3 window system at gui load time.
class idMenuFormat {
public:
	// translate the named menuDef from the ui_menuFiles set into Doom 3 gui source
	static bool			TranslateMenuDef( const char *menuName, idStr &out );
	// legacy menu stack, driven by the menu_open / menu_close console commands
	static void			OpenMenu( const char *menuName );
	static void			CloseMenu( const char *menuName );
	static void			CloseAllMenus();
	static bool			IsActive();
	static void			DrawActiveMenus( int time );
	// returns true when an open menu consumed the event
	static bool			ProcessEvent( const sysEvent_t *event );
};

#endif /* !__MENUFORMAT_H__ */
