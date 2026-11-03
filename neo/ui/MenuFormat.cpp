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

#include "precompiled.h"
#pragma hdrstop

#include "MenuFormat.h"
#include "UserInterfaceLocal.h"

idCVar ui_menuFiles( "ui_menuFiles", "ui/menus.txt", CVAR_SYSTEM | CVAR_ARCHIVE, "list of legacy .menu files to load" );

// one entry per .menu file listed in the menus file
struct menuFileEntry_t {
	idStr			fileName;
	bool			indexed;
	idStrList		menuNames;
};

// one entry per open legacy menu, the top of the stack is the last entry
struct menuStackEntry_t {
	idUserInterfaceLocal *	gui;
	idStr			name;
};

static idList<menuFileEntry_t>		menuFiles;
static idList<menuStackEntry_t>		menuStack;
static idStrList				warnedKeywords;
static bool					menusIndexed = false;

/*
====================
WarnSkip

Unsupported keywords warn once per session so a broken menu file cannot spam the console.
====================
*/
static void WarnSkip( const char *keyword ) {
	for ( int i = 0; i < warnedKeywords.Num(); i++ ) {
		if ( idStr::Icmp( warnedKeywords[i], keyword ) == 0 ) {
			return;
		}
	}
	warnedKeywords.Append( keyword );
	idLib::Printf( "MenuFormat: unsupported keyword \"%s\" skipped\n", keyword );
}

/*
====================
LoadMenuText
====================
*/
static bool LoadMenuText( const char *fileName, idStr &text ) {
	void * buffer = NULL;
	const int len = fileSystem->ReadFile( fileName, &buffer );
	if ( len <= 0 || buffer == NULL ) {
		if ( buffer != NULL ) {
			fileSystem->FreeFile( buffer );
		}
		return false;
	}
	// the file system appends a terminating zero to the buffer
	text = static_cast<const char *>( buffer );
	fileSystem->FreeFile( buffer );
	return true;
}

/*
====================
StripPreprocessorLines

TA/ET .menu files can carry cpp-style directives; turn those lines into comments.
====================
*/
static void StripPreprocessorLines( idStr &text ) {
	int lineStart = 0;
	for ( int i = 0; i <= text.Length(); i++ ) {
		if ( i == text.Length() || text[i] == '\n' ) {
			int j = lineStart;
			while ( j < i && ( text[j] == ' ' || text[j] == '\t' || text[j] == '\r' ) ) {
				j++;
			}
			if ( j < i && text[j] == '#' ) {
				text[j] = '/';
				if ( j + 1 < i ) {
					text[j + 1] = '/';
				} else {
					text[j] = ' ';
				}
			}
			lineStart = i + 1;
		}
	}
}

/*
====================
AddMenuFile
====================
*/
static void AddMenuFile( const char *fileName ) {
	for ( int i = 0; i < menuFiles.Num(); i++ ) {
		if ( idStr::Icmp( menuFiles[i].fileName, fileName ) == 0 ) {
			return;
		}
	}
	menuFileEntry_t &entry = menuFiles.Alloc();
	entry.fileName = fileName;
	entry.indexed = false;
	entry.menuNames.Clear();
}

/*
====================
IndexMenusFile

Read the menus file (TA ui/menus.txt layout) and collect the loadMenu entries.
====================
*/
static void IndexMenusFile() {
	menusIndexed = true;
	menuFiles.Clear();
	idStr text;
	if ( !LoadMenuText( ui_menuFiles.GetString(), text ) ) {
		idLib::Printf( "MenuFormat: couldn't read \"%s\"\n", ui_menuFiles.GetString() );
		return;
	}
	idLexer src( LEXFL_NOFATALERRORS | LEXFL_ALLOWPATHNAMES );
	src.LoadMemory( text, text.Length(), ui_menuFiles.GetString() );
	idToken token;
	while ( src.ReadToken( &token ) ) {
		if ( token.Icmp( "loadMenu" ) != 0 ) {
			continue;
		}
		if ( !src.ReadToken( &token ) ) {
			break;
		}
		if ( token == "{" ) {
			// loadMenu { "ui/main.menu" } form
			if ( src.ReadToken( &token ) ) {
				AddMenuFile( token );
			}
			while ( src.ReadToken( &token ) && token != "}" ) {
			}
		} else {
			// bare loadMenu "ui/main.menu" form
			AddMenuFile( token );
		}
	}
}

/*
====================
IndexMenuFile

Collect the menuDef names of one .menu file, ignoring nested itemDef names.
====================
*/
static void IndexMenuFile( menuFileEntry_t &entry ) {
	entry.indexed = true;
	entry.menuNames.Clear();
	idStr text;
	if ( !LoadMenuText( entry.fileName, text ) ) {
		return;
	}
	StripPreprocessorLines( text );
	idLexer src( LEXFL_NOFATALERRORS | LEXFL_ALLOWPATHNAMES );
	src.LoadMemory( text, text.Length(), entry.fileName );
	idToken token;
	while ( src.ReadToken( &token ) ) {
		if ( token.Icmp( "menuDef" ) != 0 ) {
			continue;
		}
		if ( !src.ReadToken( &token ) || token != "{" ) {
			continue;
		}
		// take the name from the top level of the block, nested itemDefs are skipped by the depth count
		int depth = 1;
		while ( depth > 0 && src.ReadToken( &token ) ) {
			if ( token == "{" ) {
				depth++;
			} else if ( token == "}" ) {
				depth--;
			} else if ( depth == 1 && token.Icmp( "name" ) == 0 ) {
				if ( src.ReadToken( &token ) ) {
					entry.menuNames.Append( token );
				}
			}
		}
	}
}

/*
====================
CollectBlockTokens

The lexer sits right behind an opening brace; collect through the matching close brace.
====================
*/
static bool CollectBlockTokens( idLexer &src, idStrList &tokens ) {
	int depth = 1;
	idToken token;
	while ( depth > 0 && src.ReadToken( &token ) ) {
		if ( token == "{" ) {
			depth++;
			tokens.Append( "{" );
		} else if ( token == "}" ) {
			depth--;
			if ( depth > 0 ) {
				tokens.Append( "}" );
			}
		} else {
			tokens.Append( token );
		}
	}
	return depth == 0;
}

/*
====================
TranslateCommand

One ET menu script command becomes one or more Doom 3 gui statements.
====================
*/
static void TranslateCommand( const idCmdArgs &args, idStr &out ) {
	const char *cmd = args.Argv( 0 );
	if ( idStr::Icmp( cmd, "close" ) == 0 && args.Argc() >= 2 ) {
		out += va( "set cmd \"menu_close %s\"; ", args.Argv( 1 ) );
	} else if ( idStr::Icmp( cmd, "open" ) == 0 && args.Argc() >= 2 ) {
		out += va( "set cmd \"menu_open %s\"; ", args.Argv( 1 ) );
	} else if ( idStr::Icmp( cmd, "closeall" ) == 0 || idStr::Icmp( cmd, "closeallothermenus" ) == 0 ) {
		out += "set cmd \"menu_closeall\"; ";
	} else if ( idStr::Icmp( cmd, "setcvar" ) == 0 && args.Argc() >= 3 ) {
		out += va( "set cmd \"set %s %s\"; ", args.Argv( 1 ), args.Argv( 2 ) );
	} else if ( idStr::Icmp( cmd, "clearcvar" ) == 0 && args.Argc() >= 2 ) {
		out += va( "set cmd \"reset %s\"; ", args.Argv( 1 ) );
	} else if ( ( idStr::Icmp( cmd, "exec" ) == 0 || idStr::Icmp( cmd, "execnow" ) == 0 ) && args.Argc() >= 2 ) {
		out += va( "set cmd \"%s\"; ", args.Args() );
	} else if ( idStr::Icmp( cmd, "setfocus" ) == 0 && args.Argc() >= 2 ) {
		out += va( "setFocus \"%s\"; ", args.Argv( 1 ) );
	} else if ( idStr::Icmp( cmd, "show" ) == 0 && args.Argc() >= 2 ) {
		out += va( "set \"%s::visible\" \"1\"; ", args.Argv( 1 ) );
	} else if ( idStr::Icmp( cmd, "hide" ) == 0 && args.Argc() >= 2 ) {
		out += va( "set \"%s::visible\" \"0\"; ", args.Argv( 1 ) );
	} else {
		WarnSkip( va( "script command \"%s\"", cmd ) );
	}
}

/*
====================
TranslateScript

ET item/menu scripts are semicolon separated command lists.
====================
*/
static void TranslateScript( const char *script, idStr &out ) {
	idStr work = script;
	const int len = work.Length();
	int start = 0;
	while ( start <= len ) {
		int end = start;
		while ( end < len && work[end] != ';' ) {
			end++;
		}
		idCmdArgs args;
		args.TokenizeString( work.Mid( start, end - start ).c_str(), false );
		if ( args.Argc() > 0 ) {
			TranslateCommand( args, out );
		}
		if ( end >= len ) {
			break;
		}
		start = end + 1;
	}
}

/*
====================
NormalizeItemType

ET files carry the item type as a number, menudef.h names work too.
====================
*/
static const char *NormalizeItemType( const char *type ) {
	// ITEM_TYPE_* values from the vendored menudef.h, in order
	static const char *typeNames[] = {
		"text", "button", "radiobutton", "checkbox", "editfield", "combo",
		"listbox", "model", "ownerdraw", "numericfield", "slider", "yesno",
		"multi", "bind", "menumodel", "timeout_counter", "tricheckbox"
	};
	if ( type[0] >= '0' && type[0] <= '9' ) {
		const int index = atoi( type );
		if ( index >= 0 && index < static_cast<int>( sizeof( typeNames ) / sizeof( typeNames[0] ) ) ) {
			return typeNames[index];
		}
		return "text";
	}
	return type;
}

/*
====================
TranslateTextAlign

ET alignment values line up with the D3 ones except ET's second center mode.
====================
*/
static const char *TranslateTextAlign( const char *align ) {
	if ( idStr::Icmp( align, "3" ) == 0 ) {
		return "1";
	}
	return align;
}

/*
====================
ColorTokens

The four rgba tokens of an ET color or rect keyword as one string.
====================
*/
static const char *ColorTokens( const idStrList &tokens, int i ) {
	return va( "%s %s %s %s", tokens[i + 1].c_str(), tokens[i + 2].c_str(), tokens[i + 3].c_str(), tokens[i + 4].c_str() );
}

/*
====================
ParseCvarList

cvarStrList/cvarFloatList blocks are label/value pairs, ";" and "," separated,
collected into the ";" separated choice and value lists. Returns the tokens consumed.
====================
*/
static int ParseCvarList( const idStrList &tokens, int start, idStr &choices, idStr &values ) {
	int i = start;
	if ( i >= tokens.Num() || tokens[i] != "{" ) {
		return 1;
	}
	i++;
	while ( i < tokens.Num() && tokens[i] != "}" ) {
		if ( tokens[i] == ";" || tokens[i] == "," ) {
			i++;
			continue;
		}
		idStr label = tokens[i];
		choices += label;
		choices += ";";
		i++;
		if ( i < tokens.Num() && tokens[i] != "}" && tokens[i] != ";" && tokens[i] != "," ) {
			values += tokens[i];
			values += ";";
			i++;
		} else {
			// malformed pair, use the label as its own value to keep the lists aligned
			values += label;
			values += ";";
		}
	}
	if ( i < tokens.Num() ) {
		i++;	// the closing brace
	}
	return i - start;
}

/*
====================
TranslateItemDef
====================
*/
static void TranslateItemDef( const idStrList &tokens, int itemIndex, idStr &out ) {
	// collected item state with ET defaults
	idStr itemType = "text";
	idStr name, text, background, cvar, focusSound, textalign, textalignx, textaligny, textscale, maxchars;
	idStr backcolor, forecolor, bordercolor, hovercolor, bordersize;
	idStr choices, values, low, high;
	idStrList enterScripts, exitScripts, actionScripts;
	idStr itemOnEnter;
	idStr rect[4];
	bool haveRect = false;
	bool visible = true;
	bool numeric = false;
	bool shadow = false;

	int i = 0;
	while ( i < tokens.Num() ) {
		const idStr &key = tokens[i];
		int skip = 1;

		if ( key == "type" && i + 1 < tokens.Num() ) {
			itemType = NormalizeItemType( tokens[i + 1] );
			skip = 2;
		} else if ( key == "name" && i + 1 < tokens.Num() ) {
			name = tokens[i + 1];
			skip = 2;
		} else if ( key == "rect" && i + 4 < tokens.Num() ) {
			for ( int j = 0; j < 4; j++ ) {
				rect[j] = tokens[i + 1 + j];
			}
			haveRect = true;
			skip = 5;
		} else if ( key == "visible" && i + 1 < tokens.Num() ) {
			visible = ( atoi( tokens[i + 1] ) != 0 );
			skip = 2;
		} else if ( key == "border" && i + 1 < tokens.Num() ) {
			if ( atoi( tokens[i + 1] ) >= 1 && bordersize.Length() == 0 ) {
				bordersize = "1";
			}
			skip = 2;
		} else if ( key == "bordersize" && i + 1 < tokens.Num() ) {
			bordersize = tokens[i + 1];
			skip = 2;
		} else if ( key == "backcolor" && i + 4 < tokens.Num() ) {
			backcolor = ColorTokens( tokens, i );
			skip = 5;
		} else if ( key == "forecolor" && i + 4 < tokens.Num() ) {
			forecolor = ColorTokens( tokens, i );
			skip = 5;
		} else if ( key == "bordercolor" && i + 4 < tokens.Num() ) {
			bordercolor = ColorTokens( tokens, i );
			skip = 5;
		} else if ( key == "focuscolor" && i + 4 < tokens.Num() ) {
			hovercolor = ColorTokens( tokens, i );
			skip = 5;
		} else if ( key == "background" && i + 1 < tokens.Num() ) {
			background = tokens[i + 1];
			skip = 2;
		} else if ( key == "text" && i + 1 < tokens.Num() ) {
			text = tokens[i + 1];
			skip = 2;
		} else if ( key == "textalign" && i + 1 < tokens.Num() ) {
			textalign = TranslateTextAlign( tokens[i + 1] );
			skip = 2;
		} else if ( key == "textalignx" && i + 1 < tokens.Num() ) {
			textalignx = tokens[i + 1];
			skip = 2;
		} else if ( key == "textaligny" && i + 1 < tokens.Num() ) {
			textaligny = tokens[i + 1];
			skip = 2;
		} else if ( key == "textscale" && i + 1 < tokens.Num() ) {
			textscale = tokens[i + 1];
			skip = 2;
		} else if ( key == "textstyle" && i + 1 < tokens.Num() ) {
			const int style = atoi( tokens[i + 1] );
			if ( style == 3 || style == 5 || style == 6 ) {
				shadow = true;
			} else if ( style != 0 ) {
				WarnSkip( "textstyle" );
			}
			skip = 2;
		} else if ( key == "style" && i + 1 < tokens.Num() ) {
			if ( atoi( tokens[i + 1] ) != 1 ) {
				WarnSkip( "style" );
			}
			skip = 2;
		} else if ( key == "cvar" && i + 1 < tokens.Num() ) {
			cvar = tokens[i + 1];
			skip = 2;
		} else if ( ( key == "maxChars" || key == "maxPaintChars" ) && i + 1 < tokens.Num() ) {
			maxchars = tokens[i + 1];
			skip = 2;
		} else if ( key == "focusSound" && i + 1 < tokens.Num() ) {
			focusSound = tokens[i + 1];
			skip = 2;
		} else if ( key == "action" && i + 1 < tokens.Num() ) {
			actionScripts.Append( tokens[i + 1] );
			skip = 2;
		} else if ( ( key == "mouseEnter" || key == "onFocus" ) && i + 1 < tokens.Num() ) {
			enterScripts.Append( tokens[i + 1] );
			skip = 2;
		} else if ( ( key == "mouseExit" || key == "leaveFocus" ) && i + 1 < tokens.Num() ) {
			exitScripts.Append( tokens[i + 1] );
			skip = 2;
		} else if ( key == "onEnter" && i + 1 < tokens.Num() ) {
			itemOnEnter = tokens[i + 1];
			skip = 2;
		} else if ( key == "cvarFloat" ) {
			// slider range, either flat or braced: cvar, default, min, max
			int j = i + 1;
			const bool braced = ( j < tokens.Num() && tokens[j] == "{" );
			if ( braced ) {
				j++;
			}
			idStr args[4];
			int argCount = 0;
			while ( j < tokens.Num() && argCount < 4 ) {
				if ( tokens[j] == "}" ) {
					if ( braced ) {
						j++;
					}
					break;
				}
				if ( tokens[j] == ";" || tokens[j] == "," ) {
					j++;
					continue;
				}
				args[argCount++] = tokens[j];
				j++;
			}
			if ( argCount >= 4 ) {
				cvar = args[0];
				low = args[2];
				high = args[3];
			}
			skip = j - i;
		} else if ( key == "cvarStrList" || key == "cvarFloatList" ) {
			// label/value pairs into the ";" separated choice and value lists
			skip = ParseCvarList( tokens, i + 1, choices, values );
		} else if ( key == "decoration" ) {
			// plain windows never take focus on their own, nothing to do
		} else if ( key == "group" && i + 1 < tokens.Num() ) {
			// no item groups in the D3 window system, ignore
			skip = 2;
		} else if ( key == "notselectable" || key == "wrapped" || key == "autowrapped" || key == "noToggle" ) {
			// ET listbox/text flags without a value
			WarnSkip( key );
		} else if ( key == "feeder" || key == "ownerdraw" || key == "ownerdrawFlag" || key == "special" ||
				key == "columns" || key == "elementwidth" || key == "elementheight" || key == "elementtype" ||
				key == "horizontalscroll" || key == "addColorRange" || key == "addColorRangeRel" ||
				key == "contextmenu" || key == "tooltip" || key == "tooltipalignx" || key == "tooltipaligny" ||
				key == "voteFlag" || key == "textfile" || key == "textasint" || key == "textasfloat" ||
				key == "textfont" || key == "showCvar" || key == "hideCvar" || key == "enableCvar" ||
				key == "disableCvar" || key == "settingDisabled" || key == "settingEnabled" ||
				key == "cvarListUndefined" || key == "cvarTest" || key == "model_angle" || key == "model_animplay" ||
				key == "model_fovx" || key == "model_fovy" || key == "model_origin" || key == "model_rotation" ||
				key == "asset_model" || key == "asset_shader" || key == "mouseEnterText" || key == "mouseExitText" ||
				key == "cinematic" || key == "execKey" || key == "execKeyInt" || key == "align" ||
				key == "accept" || key == "doubleclick" || key == "onEsc" || key == "origin" ) {
			// keywords that need systems this pass does not have (ownerdraw, feeders, models, ...)
			WarnSkip( key );
			skip = 2;
		} else if ( key == "{" || key == "}" ) {
			// stray brace from a block this pass does not track, ignore
		} else {
			WarnSkip( key );
		}

		i += skip;
	}

	// pick the window class from the ET item type
	idStr windowClass = "windowDef";
	if ( itemType == "editfield" || itemType == "numericfield" ) {
		windowClass = "editDef";
		numeric = ( itemType == "numericfield" );
	} else if ( itemType == "slider" ) {
		windowClass = "sliderDef";
	} else if ( itemType == "checkbox" || itemType == "radiobutton" || itemType == "yesno" ||
			itemType == "multi" || itemType == "combo" || itemType == "tricheckbox" ) {
		windowClass = "choiceDef";
	} else if ( itemType == "bind" ) {
		windowClass = "bindDef";
	} else if ( itemType != "text" && itemType != "button" && itemType != "timeout_counter" ) {
		// listbox/model/menumodel/ownerdraw keep their static parts as a plain window
		WarnSkip( va( "item type \"%s\"", itemType.c_str() ) );
	}

	if ( name.Length() == 0 ) {
		name = va( "item%d", itemIndex );
	}

	out += "\t";
	out += windowClass;
	out += " {\n";
	out += va( "\t\tname \"%s\"\n", name.c_str() );
	if ( haveRect ) {
		out += va( "\t\trect %s %s %s %s\n", rect[0].c_str(), rect[1].c_str(), rect[2].c_str(), rect[3].c_str() );
	}
	out += va( "\t\tvisible %i\n", visible ? 1 : 0 );
	if ( text.Length() > 0 ) {
		out += va( "\t\ttext \"%s\"\n", text.c_str() );
	}
	if ( textalign.Length() > 0 ) {
		out += va( "\t\ttextalign %s\n", textalign.c_str() );
	}
	if ( textalignx.Length() > 0 ) {
		out += va( "\t\ttextalignx %s\n", textalignx.c_str() );
	}
	if ( textaligny.Length() > 0 ) {
		out += va( "\t\ttextaligny %s\n", textaligny.c_str() );
	}
	if ( textscale.Length() > 0 ) {
		out += va( "\t\ttextscale %s\n", textscale.c_str() );
	}
	if ( shadow ) {
		out += "\t\tshadow 1\n";
	}
	if ( backcolor.Length() > 0 ) {
		out += va( "\t\tbackcolor %s\n", backcolor.c_str() );
	}
	if ( forecolor.Length() > 0 ) {
		out += va( "\t\tforecolor %s\n", forecolor.c_str() );
	}
	if ( bordercolor.Length() > 0 ) {
		out += va( "\t\tbordercolor %s\n", bordercolor.c_str() );
	}
	if ( hovercolor.Length() > 0 ) {
		out += va( "\t\thovercolor %s\n", hovercolor.c_str() );
	}
	if ( bordersize.Length() > 0 ) {
		out += va( "\t\tbordersize %s\n", bordersize.c_str() );
	}
	if ( background.Length() > 0 ) {
		out += va( "\t\tbackground \"%s\"\n", background.c_str() );
	}

	if ( windowClass == "editDef" ) {
		if ( cvar.Length() > 0 ) {
			out += va( "\t\tcvar \"%s\"\n", cvar.c_str() );
		}
		if ( maxchars.Length() > 0 ) {
			out += va( "\t\tmaxchars %s\n", maxchars.c_str() );
		}
		if ( numeric ) {
			out += "\t\tnumeric 1\n";
		}
	} else if ( windowClass == "sliderDef" ) {
		if ( cvar.Length() > 0 ) {
			out += va( "\t\tcvar \"%s\"\n", cvar.c_str() );
		}
		if ( low.Length() > 0 ) {
			out += va( "\t\tlow %s\n", low.c_str() );
		}
		if ( high.Length() > 0 ) {
			out += va( "\t\thigh %s\n", high.c_str() );
		}
	} else if ( windowClass == "choiceDef" ) {
		if ( choices.Length() == 0 ) {
			// checkbox style items become a two entry choice list
			choices = "Off;On;";
			values = "0;1;";
		}
		out += va( "\t\tchoices \"%s\"\n", choices.c_str() );
		out += va( "\t\tvalues \"%s\"\n", values.Length() > 0 ? values.c_str() : choices.c_str() );
		out += "\t\tchoicetype 1\n";
		if ( cvar.Length() > 0 ) {
			out += va( "\t\tcvar \"%s\"\n", cvar.c_str() );
		}
	} else if ( windowClass == "bindDef" ) {
		if ( cvar.Length() > 0 ) {
			out += va( "\t\tbind \"%s\"\n", cvar.c_str() );
		}
	}

	idStr onEnter, onExit, onAction, onEnterKey;
	if ( focusSound.Length() > 0 ) {
		onEnter += va( "localSound \"%s\"; ", focusSound.c_str() );
	}
	for ( int j = 0; j < enterScripts.Num(); j++ ) {
		TranslateScript( enterScripts[j], onEnter );
	}
	for ( int j = 0; j < exitScripts.Num(); j++ ) {
		TranslateScript( exitScripts[j], onExit );
	}
	for ( int j = 0; j < actionScripts.Num(); j++ ) {
		TranslateScript( actionScripts[j], onAction );
	}
	if ( itemOnEnter.Length() > 0 ) {
		TranslateScript( itemOnEnter, onEnterKey );
	}
	if ( onEnter.Length() > 0 ) {
		out += va( "\t\tonMouseEnter { %s}\n", onEnter.c_str() );
	}
	if ( onExit.Length() > 0 ) {
		out += va( "\t\tonMouseExit { %s}\n", onExit.c_str() );
	}
	if ( onAction.Length() > 0 ) {
		out += va( "\t\tonAction { %s}\n", onAction.c_str() );
	}
	if ( onEnterKey.Length() > 0 ) {
		out += va( "\t\tonEnter { %s}\n", onEnterKey.c_str() );
	}
	out += "\t}\n";
}

/*
====================
TranslateMenuBlock
====================
*/
static void TranslateMenuBlock( const idStrList &tokens, idStr &out ) {
	// menuDef state with ET defaults
	idStr name = "menu";
	idStr rect;
	bool haveRect = false;
	bool fullscreen = false;
	bool modal = false;
	bool visible = true;
	idStr backcolor, forecolor, bordercolor, hovercolor, bordersize, background;
	idStr activateScript, deactivateScript, escScript, enterScript;
	idStr items;
	int itemIndex = 0;

	int i = 0;
	while ( i < tokens.Num() ) {
		const idStr &key = tokens[i];
		int skip = 1;

		if ( key == "itemDef" && i + 1 < tokens.Num() && tokens[i + 1] == "{" ) {
			// collect the nested itemDef block and translate it as a child window
			idStrList itemTokens;
			i += 2;
			int depth = 1;
			while ( i < tokens.Num() ) {
				if ( tokens[i] == "{" ) {
					depth++;
				} else if ( tokens[i] == "}" ) {
					depth--;
					if ( depth == 0 ) {
						i++;
						break;
					}
				}
				itemTokens.Append( tokens[i] );
				i++;
			}
			TranslateItemDef( itemTokens, itemIndex, items );
			itemIndex++;
			continue;
		}

		if ( key == "name" && i + 1 < tokens.Num() ) {
			name = tokens[i + 1];
			skip = 2;
		} else if ( key == "rect" && i + 4 < tokens.Num() ) {
			rect = ColorTokens( tokens, i );
			haveRect = true;
			skip = 5;
		} else if ( key == "fullscreen" && i + 1 < tokens.Num() ) {
			fullscreen = ( atoi( tokens[i + 1] ) != 0 );
			skip = 2;
		} else if ( key == "visible" && i + 1 < tokens.Num() ) {
			visible = ( atoi( tokens[i + 1] ) != 0 );
			skip = 2;
		} else if ( key == "border" && i + 1 < tokens.Num() ) {
			if ( atoi( tokens[i + 1] ) >= 1 && bordersize.Length() == 0 ) {
				bordersize = "1";
			}
			skip = 2;
		} else if ( key == "borderSize" && i + 1 < tokens.Num() ) {
			bordersize = tokens[i + 1];
			skip = 2;
		} else if ( key == "backcolor" && i + 4 < tokens.Num() ) {
			backcolor = ColorTokens( tokens, i );
			skip = 5;
		} else if ( key == "forecolor" && i + 4 < tokens.Num() ) {
			forecolor = ColorTokens( tokens, i );
			skip = 5;
		} else if ( key == "bordercolor" && i + 4 < tokens.Num() ) {
			bordercolor = ColorTokens( tokens, i );
			skip = 5;
		} else if ( key == "focuscolor" && i + 4 < tokens.Num() ) {
			hovercolor = ColorTokens( tokens, i );
			skip = 5;
		} else if ( key == "background" && i + 1 < tokens.Num() ) {
			background = tokens[i + 1];
			skip = 2;
		} else if ( key == "style" && i + 1 < tokens.Num() ) {
			if ( atoi( tokens[i + 1] ) != 1 ) {
				WarnSkip( "style" );
			}
			skip = 2;
		} else if ( key == "modal" ) {
			// ET flag without a value
			modal = true;
		} else if ( key == "onOpen" && i + 1 < tokens.Num() ) {
			activateScript = tokens[i + 1];
			skip = 2;
		} else if ( key == "onClose" && i + 1 < tokens.Num() ) {
			deactivateScript = tokens[i + 1];
			skip = 2;
		} else if ( key == "onESC" && i + 1 < tokens.Num() ) {
			escScript = tokens[i + 1];
			skip = 2;
		} else if ( key == "onEnter" && i + 1 < tokens.Num() ) {
			enterScript = tokens[i + 1];
			skip = 2;
		} else if ( key == "fadeClamp" || key == "fadeCycle" || key == "fadeAmount" ) {
			// ET menu fades have no D3 window equivalent yet
			skip = 2;
		} else if ( key == "alwaysontop" || key == "outOfBoundsClick" ) {
			// stack semantics, the legacy menu stack covers both
		} else if ( key == "ownerdraw" || key == "ownerdrawFlag" || key == "soundLoop" || key == "cinematic" ||
				key == "onTimeout" || key == "execKey" || key == "execKeyInt" || key == "itemHotkeyMode" ||
				key == "disablecolor" || key == "outlinecolor" ) {
			WarnSkip( key );
			skip = 2;
		} else if ( key == "{" || key == "}" ) {
			// stray brace, ignore
		} else {
			WarnSkip( key );
		}

		i += skip;
	}

	out += "windowDef {\n";
	out += va( "\tname \"%s\"\n", name.c_str() );
	if ( !haveRect && fullscreen ) {
		rect = "0 0 640 480";
	}
	if ( rect.Length() > 0 ) {
		out += va( "\trect %s\n", rect.c_str() );
	}
	out += va( "\tvisible %i\n", visible ? 1 : 0 );
	out += "\tmenugui 1\n";
	if ( modal ) {
		out += "\tmodal 1\n";
	}
	if ( backcolor.Length() > 0 ) {
		out += va( "\tbackcolor %s\n", backcolor.c_str() );
	}
	if ( forecolor.Length() > 0 ) {
		out += va( "\tforecolor %s\n", forecolor.c_str() );
	}
	if ( bordercolor.Length() > 0 ) {
		out += va( "\tbordercolor %s\n", bordercolor.c_str() );
	}
	if ( hovercolor.Length() > 0 ) {
		out += va( "\thovercolor %s\n", hovercolor.c_str() );
	}
	if ( bordersize.Length() > 0 ) {
		out += va( "\tbordersize %s\n", bordersize.c_str() );
	}
	if ( background.Length() > 0 ) {
		out += va( "\tbackground \"%s\"\n", background.c_str() );
	}

	idStr onActivate, onDeactivate, onEsc, onEnter;
	if ( activateScript.Length() > 0 ) {
		TranslateScript( activateScript, onActivate );
		if ( onActivate.Length() > 0 ) {
			out += va( "\tonActivate { %s}\n", onActivate.c_str() );
		}
	}
	if ( deactivateScript.Length() > 0 ) {
		TranslateScript( deactivateScript, onDeactivate );
		if ( onDeactivate.Length() > 0 ) {
			out += va( "\tonDeactivate { %s}\n", onDeactivate.c_str() );
		}
	}
	if ( escScript.Length() > 0 ) {
		TranslateScript( escScript, onEsc );
		if ( onEsc.Length() > 0 ) {
			out += va( "\tonESC { %s}\n", onEsc.c_str() );
		}
	}
	if ( enterScript.Length() > 0 ) {
		TranslateScript( enterScript, onEnter );
		if ( onEnter.Length() > 0 ) {
			out += va( "\tonEnter { %s}\n", onEnter.c_str() );
		}
	}

	out += items;
	out += "}\n";
}

/*
====================
TranslateMenuFile
====================
*/
static bool TranslateMenuFile( const char *fileName, const char *menuName, idStr &out ) {
	idStr text;
	if ( !LoadMenuText( fileName, text ) ) {
		idLib::Printf( "MenuFormat: couldn't read \"%s\"\n", fileName );
		return false;
	}
	StripPreprocessorLines( text );
	idLexer src( LEXFL_NOFATALERRORS | LEXFL_ALLOWPATHNAMES );
	src.LoadMemory( text, text.Length(), fileName );
	idToken token;
	while ( src.ReadToken( &token ) ) {
		if ( token.Icmp( "menuDef" ) != 0 ) {
			continue;
		}
		if ( !src.ReadToken( &token ) || token != "{" ) {
			continue;
		}
		idStrList tokens;
		if ( !CollectBlockTokens( src, tokens ) ) {
			continue;
		}
		// the menu name can sit anywhere at the top level of the block
		int depth = 0;
		for ( int i = 0; i + 1 < tokens.Num(); i++ ) {
			if ( tokens[i] == "{" ) {
				depth++;
			} else if ( tokens[i] == "}" ) {
				depth--;
			} else if ( depth == 0 && idStr::Icmp( tokens[i], "name" ) == 0 && idStr::Icmp( tokens[i + 1], menuName ) == 0 ) {
				TranslateMenuBlock( tokens, out );
				return true;
			}
		}
	}
	return false;
}

/*
====================
idMenuFormat::TranslateMenuDef
====================
*/
bool idMenuFormat::TranslateMenuDef( const char *menuName, idStr &out ) {
	out.Clear();
	if ( menuName == NULL || menuName[0] == '\0' ) {
		return false;
	}
	if ( !menusIndexed ) {
		IndexMenusFile();
	}
	for ( int i = 0; i < menuFiles.Num(); i++ ) {
		if ( !menuFiles[i].indexed ) {
			IndexMenuFile( menuFiles[i] );
		}
		for ( int j = 0; j < menuFiles[i].menuNames.Num(); j++ ) {
			if ( idStr::Icmp( menuFiles[i].menuNames[j], menuName ) == 0 ) {
				return TranslateMenuFile( menuFiles[i].fileName, menuName, out );
			}
		}
	}
	return false;
}

/*
====================
idMenuFormat::CloseMenu
====================
*/
void idMenuFormat::CloseMenu( const char *menuName ) {
	idStr name = menuName;
	for ( int i = menuStack.Num() - 1; i >= 0; i-- ) {
		if ( idStr::Icmp( menuStack[i].name, name ) != 0 ) {
			continue;
		}
		idUserInterfaceLocal *gui = menuStack[i].gui;
		menuStack.RemoveIndex( i );
		const char *cmd = gui->Activate( false, Sys_Milliseconds() );
		if ( cmd != NULL && cmd[0] != '\0' ) {
			cmdSystem->BufferCommandText( CMD_EXEC_NOW, cmd );
		}
		return;
	}
}

/*
====================
idMenuFormat::CloseAllMenus
====================
*/
void idMenuFormat::CloseAllMenus() {
	while ( menuStack.Num() > 0 ) {
		idUserInterfaceLocal *gui = menuStack[menuStack.Num() - 1].gui;
		menuStack.RemoveIndex( menuStack.Num() - 1 );
		const char *cmd = gui->Activate( false, Sys_Milliseconds() );
		if ( cmd != NULL && cmd[0] != '\0' ) {
			cmdSystem->BufferCommandText( CMD_EXEC_NOW, cmd );
		}
	}
}

/*
====================
idMenuFormat::OpenMenu
====================
*/
void idMenuFormat::OpenMenu( const char *menuName ) {
	// re-opening moves the menu to the top of the stack
	CloseMenu( menuName );
	idUserInterface *gui = uiManager->FindGui( va( "menu_%s", menuName ), true, true, false );
	if ( gui == NULL ) {
		common->Printf( "menu_open: couldn't load legacy menu \"%s\"\n", menuName );
		return;
	}
	menuStackEntry_t &entry = menuStack.Alloc();
	entry.gui = static_cast<idUserInterfaceLocal *>( gui );
	entry.name = menuName;
	entry.gui->SetCursor( 320.0f, 240.0f );
	const char *cmd = entry.gui->Activate( true, Sys_Milliseconds() );
	if ( cmd != NULL && cmd[0] != '\0' ) {
		cmdSystem->BufferCommandText( CMD_EXEC_NOW, cmd );
	}
}

/*
====================
idMenuFormat::IsActive
====================
*/
bool idMenuFormat::IsActive() {
	return menuStack.Num() > 0;
}

/*
====================
idMenuFormat::DrawActiveMenus
====================
*/
void idMenuFormat::DrawActiveMenus( int time ) {
	for ( int i = 0; i < menuStack.Num(); i++ ) {
		menuStack[i].gui->Redraw( time, false );
	}
	if ( menuStack.Num() > 0 ) {
		menuStack[menuStack.Num() - 1].gui->DrawCursor();
	}
}

/*
====================
idMenuFormat::ProcessEvent
====================
*/
bool idMenuFormat::ProcessEvent( const sysEvent_t *event ) {
	if ( menuStack.Num() == 0 ) {
		return false;
	}
	menuStackEntry_t &entry = menuStack[menuStack.Num() - 1];
	idStr menuName = entry.name;
	bool updateVisuals = false;
	const char *cmd = entry.gui->HandleEvent( event, Sys_Milliseconds(), &updateVisuals );
	const bool handled = ( cmd != NULL && cmd[0] != '\0' );
	if ( handled ) {
		cmdSystem->BufferCommandText( CMD_EXEC_NOW, cmd );
	}
	// ET behavior: ESC drops the top menu even when no onESC script handled it
	if ( event->evType == SE_KEY && event->evValue == K_ESCAPE && event->evValue2 == 1 && !handled ) {
		CloseMenu( menuName );
	}
	return true;
}

CONSOLE_COMMAND( menu_open, "opens a legacy TA/RTCW/ET menu by menuDef name", NULL ) {
	if ( args.Argc() < 2 ) {
		common->Printf( "usage: menu_open <menuDef name>\n" );
		return;
	}
	idMenuFormat::OpenMenu( args.Argv( 1 ) );
}

CONSOLE_COMMAND( menu_close, "closes a legacy menu by menuDef name", NULL ) {
	if ( args.Argc() < 2 ) {
		common->Printf( "usage: menu_close <menuDef name>\n" );
		return;
	}
	idMenuFormat::CloseMenu( args.Argv( 1 ) );
}

CONSOLE_COMMAND( menu_closeall, "closes all legacy menus", NULL ) {
	idMenuFormat::CloseAllMenus();
}

CONSOLE_COMMAND( menu_list, "lists the menuDef names found in the legacy menus file", NULL ) {
	if ( !menusIndexed ) {
		IndexMenusFile();
	}
	common->Printf( "legacy menus from \"%s\":\n", ui_menuFiles.GetString() );
	for ( int i = 0; i < menuFiles.Num(); i++ ) {
		if ( !menuFiles[i].indexed ) {
			IndexMenuFile( menuFiles[i] );
		}
		for ( int j = 0; j < menuFiles[i].menuNames.Num(); j++ ) {
			common->Printf( "  %s (%s)\n", menuFiles[i].menuNames[j].c_str(), menuFiles[i].fileName.c_str() );
		}
	}
}

CONSOLE_COMMAND( menu_check, "prints the translated Doom 3 gui source of a legacy menu", NULL ) {
	if ( args.Argc() < 2 ) {
		common->Printf( "usage: menu_check <menuDef name>\n" );
		return;
	}
	idStr source;
	if ( !idMenuFormat::TranslateMenuDef( args.Argv( 1 ), source ) ) {
		common->Printf( "menu_check: no menuDef \"%s\" found\n", args.Argv( 1 ) );
		return;
	}
	common->Printf( "%s\n", source.c_str() );
}

CONSOLE_COMMAND( menu_reload, "closes all legacy menus and drops the parsed menu caches", NULL ) {
	idMenuFormat::CloseAllMenus();
	menusIndexed = false;
	warnedKeywords.Clear();
	common->Printf( "legacy menu caches cleared\n" );
}
