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

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 BFG Edition Source Code.  If not, please request a copy in writing to id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

If you have questions concerning this license or the applicable additional terms, you may contact in writing to id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#include "precompiled.h"
#pragma hdrstop

#include "Lexer.h"
#include "framework/FileSystem.h"

#include "Q3ShaderConverter.h"

// set by Q3WaveExpr when any shader uses a wave function
static bool q3NeedWaveTables = false;

// Formats a string through the engine formatter (Str.h redirects vsnprintf).
static idStr Q3Str( const char *fmt, ... ) {
	char buffer[32048];
	va_list argptr;
	va_start( argptr, fmt );
	idStr::vsnPrintf( buffer, sizeof( buffer ), fmt, argptr );
	va_end( argptr );
	idStr out = buffer;
	return out;
}

// Prints a float without trailing zeros; integral values print as integers.
static idStr Q3Float( float f ) {
	if ( f == (float)(int)f && idMath::Abs( f ) < 100000.0f ) {
		return Q3Str( "%d", (int)f );
	}
	char buf[64];
	idStr::snPrintf( buf, sizeof( buf ), "%f", f );
	int len = (int)strlen( buf );
	while ( len > 0 && buf[len-1] == '0' ) {
		len--;
	}
	if ( len > 0 && buf[len-1] == '.' ) {
		len--;
	}
	buf[len] = '\0';
	idStr out = buf;
	return out;
}

// Trims leading and trailing whitespace off a string.
static idStr Q3Trim( const char *s ) {
	while ( *s == ' ' || *s == '\t' || *s == '\r' || *s == '\n' ) {
		s++;
	}
	int len = (int)strlen( s );
	while ( len > 0 && ( s[len-1] == ' ' || s[len-1] == '\t' || s[len-1] == '\r' || s[len-1] == '\n' ) ) {
		len--;
	}
	if ( len > 1023 ) {
		len = 1023;
	}
	char buf[1024];
	idStr::snPrintf( buf, sizeof( buf ), "%.*s", len, s );
	idStr out = buf;
	return out;
}

// Reads the texture name of a map directive. The lexer hands the leading
// '$' of the Quake 3 built-in maps back as its own token, so the name is
// reassembled here.
static void Q3ReadMapName( idLexer &src, idToken &mapTok ) {
	idToken nameTok;
	if ( mapTok == "$" && src.ReadToken( &nameTok ) ) {
		mapTok = "$";
		mapTok += nameTok.c_str();
	}
}

// Doom 3 picks the image type from whatever file is on disk when the
// extension is left off, so the Quake 3 image extensions are stripped
// from every emitted image name.
static idStr Q3ImageName( const char *name ) {
	idStr out = name;
	static const char *q3ImageExts[] = { ".tga", ".jpg", ".jpeg", ".png" };
	const int numExts = (int)( sizeof( q3ImageExts ) / sizeof( q3ImageExts[0] ) );
	for ( int i = 0; i < numExts; i++ ) {
		const int extLen = (int)strlen( q3ImageExts[i] );
		if ( out.Length() > extLen && idStr::Icmp( out.c_str() + out.Length() - extLen, q3ImageExts[i] ) == 0 ) {
			out = out.Left( out.Length() - extLen );
			break;
		}
	}
	return out;
}

/*
=================
Q3WaveExpr

Builds a Doom 3 expression for a Quake 3 wave function with the given
base, amplitude, phase and frequency. The Doom 3 table lookup scales the
index by the table domain and wraps at 1.0, so the wave tables cover one
full cycle and are indexed with plain cycle values (time * freq + phase).
=================
*/
static idStr Q3WaveExpr( const char *func, float base, float amp, float phase, float freq, bool &valid ) {
	idStr b = Q3Float( base ).c_str();
	idStr a = Q3Float( amp ).c_str();
	idStr p = Q3Float( phase ).c_str();
	idStr f = Q3Float( freq ).c_str();

	if ( idStr::Icmp( func, "sin" ) == 0 ) {
		q3NeedWaveTables = true;
		valid = true;
		return Q3Str( "( %s + %s * q3waveSin[ time * %s + %s ] )", b.c_str(), a.c_str(), f.c_str(), p.c_str() );
	}
	if ( idStr::Icmp( func, "square" ) == 0 ) {
		q3NeedWaveTables = true;
		valid = true;
		return Q3Str( "( %s + %s * ( q3waveSquare[ time * %s + %s ] * 2 - 1 ) )", b.c_str(), a.c_str(), f.c_str(), p.c_str() );
	}
	if ( idStr::Icmp( func, "triangle" ) == 0 ) {
		q3NeedWaveTables = true;
		valid = true;
		return Q3Str( "( %s + %s * q3waveTriangle[ time * %s + %s ] )", b.c_str(), a.c_str(), f.c_str(), p.c_str() );
	}
	if ( idStr::Icmp( func, "sawtooth" ) == 0 ) {
		q3NeedWaveTables = true;
		valid = true;
		return Q3Str( "( %s + %s * q3waveSawtooth[ time * %s + %s ] )", b.c_str(), a.c_str(), f.c_str(), p.c_str() );
	}
	if ( idStr::Icmp( func, "inversesawtooth" ) == 0 ) {
		q3NeedWaveTables = true;
		valid = true;
		return Q3Str( "( %s + %s * q3waveInversesawtooth[ time * %s + %s ] )", b.c_str(), a.c_str(), f.c_str(), p.c_str() );
	}

	valid = false;
	return idStr();
}

/*
=================
Q3WaveTable

Returns the name of the Doom 3 wave table that holds the values of a
Quake 3 wave function, or NULL when the function has no table. Used
by the deformVertexes conversion, which looks the wave up outside of
an expression.
=================
*/
static const char *Q3WaveTable( const char *func ) {
	if ( idStr::Icmp( func, "sin" ) == 0 ) {
		q3NeedWaveTables = true;
		return "q3waveSin";
	}
	if ( idStr::Icmp( func, "square" ) == 0 ) {
		q3NeedWaveTables = true;
		return "q3waveSquare";
	}
	if ( idStr::Icmp( func, "triangle" ) == 0 ) {
		q3NeedWaveTables = true;
		return "q3waveTriangle";
	}
	if ( idStr::Icmp( func, "sawtooth" ) == 0 ) {
		q3NeedWaveTables = true;
		return "q3waveSawtooth";
	}
	if ( idStr::Icmp( func, "inversesawtooth" ) == 0 ) {
		q3NeedWaveTables = true;
		return "q3waveInversesawtooth";
	}
	return NULL;
}

// Quake 3 surfaceparms with a matching Doom 3 material keyword; any other
// surfaceparm falls back to a comment.
typedef struct {
	const char *	q3;			// Quake 3 surfaceparm
	const char *	d3;			// matching Doom 3 material keyword
} q3SurfaceParmMap_t;

static const q3SurfaceParmMap_t q3SurfaceParmMap[] = {
	{ "solid",			"solid" },			// may need to override a clearSolid
	{ "nonsolid",		"nonsolid" },		// clears the solid flag
	{ "water",			"water" },
	{ "playerclip",		"playerclip" },
	{ "monsterclip",	"monsterclip" },
	{ "slick",			"slick" },
	{ "noimpact",		"noimpact" },		// don't make impact explosions or marks
	{ "nodamage",		"nodamage" },		// no falling damage when hitting
	{ "ladder",			"ladder" },			// climbable
	{ "nosteps",		"nosteps" },		// no footsteps
	{ "metalsteps",	"metal" },			// metal step sound type
	{ "flesh",			"flesh" },
	{ "glass",			"glass" },
	{ "trans",			"translucent" },
	{ "trigger",		"trigger" },
	{ "areaportal",	"areaportal" },
	{ "discrete",		"discrete" },		// surfaces are not merged together
	{ "nofragment",	"noFragment" },
};

static const int q3NumSurfaceParms = (int)( sizeof( q3SurfaceParmMap ) / sizeof( q3SurfaceParmMap[0] ) );

// Emits the Doom 3 equivalent of a Quake 3 surfaceparm.
static void Q3SurfaceParm( const char *parm, idStr &dest, Q3ShaderConverter *conv ) {
	for ( int i = 0; i < q3NumSurfaceParms; i++ ) {
		if ( idStr::Icmp( parm, q3SurfaceParmMap[i].q3 ) == 0 ) {
			dest += "\t";
			dest += q3SurfaceParmMap[i].d3;
			dest += "\n";
			return;
		}
	}
	dest += Q3Str( "\t//surfaceparm %s\n", parm ).c_str();
	conv->numWarnings++;
}

// Keeps an unsupported directive as a //comment together with its arguments.
static void Q3UnknownDirective( idLexer &src, const char *token, const char *indent, idStr &dest, Q3ShaderConverter *conv ) {
	idStr rest;
	src.ReadRestOfLine( rest );
	dest += indent;
	dest += "//";
	dest += token;
	idStr trimmed = Q3Trim( rest.c_str() );
	if ( trimmed.Length() > 0 ) {
		dest += " ";
		dest += trimmed.c_str();
	}
	dest += "\n";
	conv->numWarnings++;
}

// One converted stage.
struct q3Stage_t {
	idStr		text;			// converted Doom 3 stage lines
	idStr		dropComment;	// set when the stage is dropped entirely
	idStr		mapName;		// texture of a plain map directive
	idStr		deformText;	// material level deform line collected from a stage
	idStr		promoteNote;	// comment emitted above the diffusemap promotion
	bool		plainMap;		// the stage is nothing but a single map line
};

/*
=================
Q3ParseStage

Parses one Quake 3 stage (the open brace has just been consumed) into
Doom 3 stage lines. Directives without a Doom 3 equivalent are kept as
"// q3:" comments so no information is silently lost. Stages built
around $lightmap / $lightimage are dropped: the Doom 3 lighting model
has no lightmaps.
=================
*/
static void Q3ParseStage( idLexer &src, const char *shaderName, q3Stage_t &stage, Q3ShaderConverter *conv ) {
	idToken token;

	stage.plainMap = true;
	bool dropped = false;

	while ( src.ExpectAnyToken( &token ) ) {
		if ( token == "}" ) {
			break;
		}
		if ( dropped ) {
			// swallow the rest of a dropped (lightmap) stage
			src.SkipRestOfLine();
			continue;
		}

		if ( !token.Icmp( "map" ) ) {
			idToken mapTok;
			if ( !src.ReadToken( &mapTok ) ) {
				continue;
			}
			Q3ReadMapName( src, mapTok );
			if ( !mapTok.Icmp( "$lightmap" ) || !mapTok.Icmp( "$lightimage" ) ) {
				dropped = true;
				stage.plainMap = false;
				stage.dropComment = Q3Str( "//dropped stage with map %s (the Doom 3 lighting model has no lightmaps)", mapTok.c_str() ).c_str();
				continue;
			}
			if ( !mapTok.Icmp( "$whiteimage" ) ) {
				stage.plainMap = false;
				stage.text += "\t\tmap _white\n";
				continue;
			}
			if ( mapTok[0] == '$' ) {
				// unknown Quake 3 built-in map
				stage.plainMap = false;
				stage.text += Q3Str( "\t\t//map %s\n", mapTok.c_str() ).c_str();
				conv->numWarnings++;
				continue;
			}
			idStr image = Q3ImageName( mapTok.c_str() );
			stage.mapName = image.c_str();
			stage.text += "\t\tmap ";
			stage.text += image.c_str();
			stage.text += "\n";
			continue;
		}

		if ( !token.Icmp( "clampMap" ) ) {
			idToken mapTok;
			if ( !src.ReadToken( &mapTok ) ) {
				continue;
			}
			Q3ReadMapName( src, mapTok );
			stage.plainMap = false;
			idStr image = Q3ImageName( mapTok.c_str() );
			stage.mapName = image.c_str();
			stage.text += "\t\tclamp\n\t\tmap ";
			stage.text += image.c_str();
			stage.text += "\n";
			continue;
		}

		if ( !token.Icmp( "animMap" ) ) {
			float fps = src.ParseFloat();
			stage.plainMap = false;
			idStr line = "animMap ";
			line += Q3Float( fps ).c_str();
			idToken frame;
			int numFrames = 0;
			while ( src.ReadTokenOnLine( &frame ) ) {
				line += " ";
				line += Q3ImageName( frame.c_str() ).c_str();
				numFrames++;
			}
			if ( numFrames == 0 ) {
				src.Warning( "animMap stage in shader '%s' has no frames", shaderName );
				conv->numWarnings++;
			}
			stage.text += "\t\t";
			stage.text += line.c_str();
			stage.text += "\n";
			continue;
		}

		if ( !token.Icmp( "blendFunc" ) ) {
			idToken blendSrc, blendDst;
			stage.plainMap = false;
			if ( !src.ReadToken( &blendSrc ) ) {
				continue;
			}
			if ( src.ReadToken( &blendDst ) && blendDst != "}" ) {
				if ( !blendSrc.Icmp( "GL_SRC_ALPHA" ) && !blendDst.Icmp( "GL_ONE_MINUS_SRC_ALPHA" ) ) {
					stage.text += "\t\tblend blend\n";
				} else if ( !blendSrc.Icmp( "GL_ONE" ) && !blendDst.Icmp( "GL_ONE" ) ) {
					stage.text += "\t\tblend add\n";
				} else if ( ( !blendSrc.Icmp( "GL_DST_COLOR" ) && !blendDst.Icmp( "GL_ZERO" ) ) ||
							( !blendSrc.Icmp( "GL_ZERO" ) && !blendDst.Icmp( "GL_SRC_COLOR" ) ) ) {
					stage.text += "\t\tblend filter\n";
				} else if ( !blendSrc.Icmp( "GL_ONE" ) && !blendDst.Icmp( "GL_ZERO" ) ) {
					// straight copy, the Doom 3 default for opaque stages
				} else {
					stage.text += Q3Str( "\t\tblend %s, %s\n", blendSrc.c_str(), blendDst.c_str() ).c_str();
				}
				continue;
			}
			if ( blendDst == "}" ) {
				src.UnreadToken( &blendDst );
			}
			// single token shorthand form
			if ( !blendSrc.Icmp( "add" ) || !blendSrc.Icmp( "gl_add" ) ) {
				stage.text += "\t\tblend add\n";
			} else if ( !blendSrc.Icmp( "filter" ) || !blendSrc.Icmp( "gl_filter" ) ) {
				stage.text += "\t\tblend filter\n";
			} else if ( !blendSrc.Icmp( "blend" ) || !blendSrc.Icmp( "alpha" ) ) {
				stage.text += "\t\tblend blend\n";
			} else {
				Q3UnknownDirective( src, token.c_str(), "\t\t", stage.text, conv );
			}
			continue;
		}

		if ( !token.Icmp( "rgbGen" ) ) {
			idToken genTok;
			if ( !src.ReadToken( &genTok ) ) {
				continue;
			}
			if ( !genTok.Icmp( "identity" ) || !genTok.Icmp( "identityLighting" ) ) {
				continue;	// the Doom 3 default
			}
			if ( !genTok.Icmp( "lightingDiffuse" ) && stage.plainMap ) {
				// a plain map stage with rgbGen lightingDiffuse is exactly what
				// the Doom 3 interaction pass lights, so the stage promotes to
				// the material diffusemap instead of rendering unlit
				stage.promoteNote = "//rgbGen lightingDiffuse is lit by the interaction pass";
				continue;
			}
			stage.plainMap = false;
			if ( !genTok.Icmp( "vertex" ) || !genTok.Icmp( "exactVertex" ) ) {
				stage.text += "\t\tvertexColor\n";
				continue;
			}
			if ( !genTok.Icmp( "oneMinusVertex" ) ) {
				stage.text += "\t\tinverseVertexColor\n";
				continue;
			}
			if ( !genTok.Icmp( "entity" ) || !genTok.Icmp( "oneMinusEntity" ) || !genTok.Icmp( "lightingDiffuse" ) ) {
				stage.text += Q3Str( "\t\tvertexColor //rgbGen %s approximated\n", genTok.c_str() ).c_str();
				continue;
			}
			if ( !genTok.Icmp( "wave" ) ) {
				idToken funcTok;
				src.ReadToken( &funcTok );
				float base = src.ParseFloat();
				float amp = src.ParseFloat();
				float phase = src.ParseFloat();
				float freq = src.ParseFloat();
				bool valid = false;
				idStr expr = Q3WaveExpr( funcTok.c_str(), base, amp, phase, freq, valid );
				if ( valid ) {
					stage.text += Q3Str( "\t\trgb %s\n", expr.c_str() ).c_str();
				} else {
					stage.text += Q3Str( "\t\t//rgbGen wave %s (no Doom 3 equivalent)\n", funcTok.c_str() ).c_str();
					conv->numWarnings++;
				}
				continue;
			}
			if ( !genTok.Icmp( "const" ) ) {
				float vals[3] = { 0.0f, 0.0f, 0.0f };
				int numVals = 0;
				idToken valTok;
				while ( numVals < 3 && src.ReadTokenOnLine( &valTok ) ) {
					if ( valTok == "(" || valTok == ")" ) {
						continue;
					}
					vals[numVals] = valTok.GetFloatValue();
					numVals++;
				}
				if ( numVals == 3 ) {
					stage.text += Q3Str( "\t\tred %s\n\t\tgreen %s\n\t\tblue %s\n",
						Q3Float( vals[0] ).c_str(), Q3Float( vals[1] ).c_str(), Q3Float( vals[2] ).c_str() ).c_str();
				} else {
					stage.text += "\t\t//rgbGen const\n";
					conv->numWarnings++;
				}
				continue;
			}
			stage.text += Q3Str( "\t\t//rgbGen %s\n", genTok.c_str() ).c_str();
			conv->numWarnings++;
			continue;
		}

		if ( !token.Icmp( "alphaGen" ) ) {
			idToken genTok;
			if ( !src.ReadToken( &genTok ) ) {
				continue;
			}
			if ( !genTok.Icmp( "identity" ) ) {
				continue;	// the Doom 3 default
			}
			stage.plainMap = false;
			if ( !genTok.Icmp( "wave" ) ) {
				idToken funcTok;
				src.ReadToken( &funcTok );
				float base = src.ParseFloat();
				float amp = src.ParseFloat();
				float phase = src.ParseFloat();
				float freq = src.ParseFloat();
				bool valid = false;
				idStr expr = Q3WaveExpr( funcTok.c_str(), base, amp, phase, freq, valid );
				if ( valid ) {
					stage.text += Q3Str( "\t\talpha %s\n", expr.c_str() ).c_str();
				} else {
					stage.text += Q3Str( "\t\t//alphaGen wave %s (no Doom 3 equivalent)\n", funcTok.c_str() ).c_str();
					conv->numWarnings++;
				}
				continue;
			}
			if ( !genTok.Icmp( "const" ) ) {
				float v = src.ParseFloat();
				stage.text += Q3Str( "\t\talpha %s\n", Q3Float( v ).c_str() ).c_str();
				continue;
			}
			if ( !genTok.Icmp( "vertex" ) ) {
				stage.text += "\t\tvertexColor\n";
				continue;
			}
			if ( !genTok.Icmp( "oneMinusVertex" ) ) {
				stage.text += "\t\tinverseVertexColor\n";
				continue;
			}
			stage.text += Q3Str( "\t\t//alphaGen %s\n", genTok.c_str() ).c_str();
			conv->numWarnings++;
			continue;
		}

		if ( !token.Icmp( "alphaFunc" ) ) {
			idToken funcTok;
			stage.plainMap = false;
			if ( !src.ReadToken( &funcTok ) ) {
				continue;
			}
			if ( !funcTok.Icmp( "GE128" ) ) {
				stage.text += "\t\talphaTest 0.5\n";
			} else if ( !funcTok.Icmp( "GT0" ) ) {
				stage.text += "\t\talphaTest 0.01\n";
			} else if ( !funcTok.Icmp( "LT128" ) ) {
				stage.text += "\t\t//alphaFunc LT128\n";
				conv->numWarnings++;
			} else {
				stage.text += Q3Str( "\t\t//alphaFunc %s\n", funcTok.c_str() ).c_str();
				conv->numWarnings++;
			}
			continue;
		}

		if ( !token.Icmp( "tcGen" ) ) {
			idToken genTok;
			stage.plainMap = false;
			if ( !src.ReadToken( &genTok ) ) {
				continue;
			}
			if ( !genTok.Icmp( "environment" ) ) {
				stage.text += "\t\ttexGen reflect\n";
				continue;
			}
			// vector and base have no direct equivalent; eat their arguments
			src.SkipRestOfLine();
			stage.text += Q3Str( "\t\t//tcGen %s\n", genTok.c_str() ).c_str();
			conv->numWarnings++;
			continue;
		}

		if ( !token.Icmp( "tcMod" ) ) {
			idToken modTok;
			stage.plainMap = false;
			if ( !src.ReadToken( &modTok ) ) {
				continue;
			}
			if ( !modTok.Icmp( "scroll" ) ) {
				float s = src.ParseFloat();
				float t = src.ParseFloat();
				stage.text += Q3Str( "\t\ttranslate ( time * %s ), ( time * %s )\n", Q3Float( s ).c_str(), Q3Float( t ).c_str() ).c_str();
				continue;
			}
			if ( !modTok.Icmp( "scale" ) ) {
				float s = src.ParseFloat();
				float t = src.ParseFloat();
				stage.text += Q3Str( "\t\tscale ( %s ), ( %s )\n", Q3Float( s ).c_str(), Q3Float( t ).c_str() ).c_str();
				continue;
			}
			if ( !modTok.Icmp( "rotate" ) ) {
				float deg = src.ParseFloat();
				// degrees per second becomes cycles per second
				stage.text += Q3Str( "\t\trotate ( time * %s )\n", Q3Float( deg / 360.0f ).c_str() ).c_str();
				continue;
			}
			if ( !modTok.Icmp( "stretch" ) ) {
				idToken funcTok;
				src.ReadToken( &funcTok );
				float base = src.ParseFloat();
				float amp = src.ParseFloat();
				float phase = src.ParseFloat();
				float freq = src.ParseFloat();
				bool valid = false;
				idStr expr = Q3WaveExpr( funcTok.c_str(), base, amp, phase, freq, valid );
				if ( valid ) {
					stage.text += Q3Str( "\t\tcenterScale ( %s ), ( %s )\n", expr.c_str(), expr.c_str() ).c_str();
				} else {
					stage.text += Q3Str( "\t\t//tcMod stretch %s (no Doom 3 equivalent)\n", funcTok.c_str() ).c_str();
					conv->numWarnings++;
				}
				continue;
			}
			if ( !modTok.Icmp( "turb" ) ) {
				// tcMod turb <base> <amplitude> <phase> <frequency>
				// Quake 3 never reads the base and always uses the sin table;
				// the Doom 3 turbulent deform is the same texture coordinate
				// wobble, but it is a material level directive, so the line is
				// collected here and merged once the whole shader is parsed
				src.ParseFloat();	// the base is never read by Quake 3
				float amp = src.ParseFloat();
				float phase = src.ParseFloat();
				float freq = src.ParseFloat();
				// the Doom 3 turbulent lookup adds the time offset twice, so
				// the Quake 3 frequency and phase are halved; the domain is
				// picked so the y axis weight matches Quake 3's 1/1024 per
				// unit phase
				idStr timeOfs;
				if ( freq != 0.0f && phase != 0.0f ) {
					timeOfs = Q3Str( "( ( time * %s ) + %s )", Q3Float( freq * 0.5f ).c_str(), Q3Float( phase * 0.5f ).c_str() ).c_str();
				} else if ( freq != 0.0f ) {
					timeOfs = Q3Str( "( time * %s )", Q3Float( freq * 0.5f ).c_str() ).c_str();
				} else {
					timeOfs = Q3Float( phase * 0.5f ).c_str();
				}
				stage.deformText = Q3Str( "\tdeform turbulent %s %s %s %s //tcMod turb\n",
					Q3WaveTable( "sin" ), Q3Float( amp ).c_str(), timeOfs.c_str(),
					Q3Float( 1.0f / ( 1024.0f * 0.007f ) ).c_str() ).c_str();
				continue;
			}
			Q3UnknownDirective( src, token.c_str(), "\t\t", stage.text, conv );
			// transform carries its arguments on the same line
			continue;
		}

		if ( !token.Icmp( "depthWrite" ) ) {
			idToken valTok;
			stage.plainMap = false;
			if ( src.ReadTokenOnLine( &valTok ) && ( !valTok.Icmp( "false" ) || valTok == "0" ) ) {
				stage.text += "\t\tmaskDepth\n";
			}
			continue;
		}

		if ( !token.Icmp( "depthFunc" ) ) {
			idToken funcTok;
			if ( !src.ReadToken( &funcTok ) ) {
				continue;
			}
			if ( !funcTok.Icmp( "lequal" ) || !funcTok.Icmp( "equal" ) || !funcTok.Icmp( "always" ) || !funcTok.Icmp( "disable" ) ) {
				// the depth function is written out as is, the engine keyword
				// keeps the automatic depth mask of the surface type
				stage.plainMap = false;
				stage.text += Q3Str( "\t\tdepthFunc %s\n", funcTok.c_str() ).c_str();
			} else {
				stage.text += Q3Str( "\t\t//depthFunc %s\n", funcTok.c_str() ).c_str();
				conv->numWarnings++;
			}
			continue;
		}

		if ( !token.Icmp( "detail" ) ) {
			continue;	// the Doom 3 interaction shader handles detail stages on its own
		}

		// Quake II style stage keywords kept by Doom 3 under the same names
		if ( !token.Icmp( "rotate" ) ) {
			float deg = src.ParseFloat();
			stage.plainMap = false;
			// degrees per second becomes cycles per second
			stage.text += Q3Str( "\t\trotate ( time * %s )\n", Q3Float( deg / 360.0f ).c_str() ).c_str();
			continue;
		}
		if ( !token.Icmp( "scroll" ) ) {
			float s = src.ParseFloat();
			float t = src.ParseFloat();
			stage.plainMap = false;
			stage.text += Q3Str( "\t\ttranslate ( time * %s ), ( time * %s )\n", Q3Float( s ).c_str(), Q3Float( t ).c_str() ).c_str();
			continue;
		}
		if ( !token.Icmp( "scale" ) ) {
			float s = src.ParseFloat();
			float t = src.ParseFloat();
			stage.plainMap = false;
			stage.text += Q3Str( "\t\tscale ( %s ), ( %s )\n", Q3Float( s ).c_str(), Q3Float( t ).c_str() ).c_str();
			continue;
		}
		if ( !token.Icmp( "centerScale" ) ) {
			float s = src.ParseFloat();
			float t = src.ParseFloat();
			stage.plainMap = false;
			stage.text += Q3Str( "\t\tcenterScale ( %s ), ( %s )\n", Q3Float( s ).c_str(), Q3Float( t ).c_str() ).c_str();
			continue;
		}
		if ( !token.Icmp( "shear" ) ) {
			float s = src.ParseFloat();
			float t = src.ParseFloat();
			stage.plainMap = false;
			stage.text += Q3Str( "\t\tshear ( %s ), ( %s )\n", Q3Float( s ).c_str(), Q3Float( t ).c_str() ).c_str();
			continue;
		}
		if ( !token.Icmp( "texgen" ) ) {
			idToken genTok;
			stage.plainMap = false;
			if ( !src.ReadToken( &genTok ) ) {
				continue;
			}
			if ( !genTok.Icmp( "environment" ) ) {
				stage.text += "\t\ttexGen reflect\n";
			} else {
				src.SkipRestOfLine();
				stage.text += Q3Str( "\t\t//texgen %s\n", genTok.c_str() ).c_str();
				conv->numWarnings++;
			}
			continue;
		}

		Q3UnknownDirective( src, token.c_str(), "\t\t", stage.text, conv );
	}

	if ( dropped ) {
		stage.plainMap = false;
	}
}

// Wraps converted stage lines into a braced stage block.
static idStr Q3StageBlock( const q3Stage_t &stage ) {
	idStr block = "\t{\n";
	block += stage.text.c_str();
	block += "\t}\n";
	return block;
}

/*
=================
Q3ParseShaderDirective

Parses one material level Quake 3 directive into Doom 3 material lines.
=================
*/
static void Q3ParseShaderDirective( idLexer &src, const idToken &token, idStr &dest, Q3ShaderConverter *conv ) {
	if ( !token.Icmp( "qer_editorimage" ) ) {
		idToken image;
		if ( src.ReadTokenOnLine( &image ) ) {
			dest += "\tqer_editorimage ";
			dest += Q3ImageName( image.c_str() ).c_str();
			dest += "\n";
		}
		return;
	}

	if ( !token.Icmp( "polygonOffset" ) ) {
		dest += "\tpolygonOffset\n";
		return;
	}

	if ( !token.Icmp( "sort" ) ) {
		idToken sortTok;
		if ( src.ReadTokenOnLine( &sortTok ) ) {
			dest += "\tsort ";
			dest += sortTok.c_str();
			dest += "\n";
		}
		return;
	}

	if ( !token.Icmp( "cull" ) ) {
		idToken cullTok;
		if ( src.ReadTokenOnLine( &cullTok ) ) {
			if ( !cullTok.Icmp( "none" ) || !cullTok.Icmp( "disable" ) || !cullTok.Icmp( "twosided" ) ) {
				dest += "\ttwoSided\n";
			} else if ( !cullTok.Icmp( "backside" ) || !cullTok.Icmp( "back" ) ) {
				dest += "\tbackSided\n";
			}
			// frontside / frontSidedefault is the Doom 3 default
		}
		return;
	}

	if ( !token.Icmp( "deformVertexes" ) ) {
		idToken deformTok;
		if ( src.ReadTokenOnLine( &deformTok ) ) {
			if ( !deformTok.Icmp( "autosprite" ) ) {
				dest += "\tdeform sprite\n";
				return;
			}
			if ( !deformTok.Icmp( "wave" ) ) {
				// deformVertexes wave <div> <func> <base> <amplitude> <phase> <freq>
				const float div = src.ParseFloat();
				idToken funcTok;
				if ( src.ReadTokenOnLine( &funcTok ) ) {
					const float base = src.ParseFloat();
					const float amp = src.ParseFloat();
					const float phase = src.ParseFloat();
					const float freq = src.ParseFloat();
					const char *table = Q3WaveTable( funcTok.c_str() );
					if ( table == NULL ) {
						dest += Q3Str( "\t//deformVertexes wave %s (no Doom 3 equivalent)\n", funcTok.c_str() ).c_str();
						conv->numWarnings++;
						return;
					}
					// the wave deform looks the value up in a table that covers one
					// cycle, and the square table stores 1 and 0, so the base and
					// amplitude are moved to the range Quake 3 squares between
					float outBase = base;
					float outAmp = amp;
					if ( idStr::Icmp( funcTok.c_str(), "square" ) == 0 ) {
						outBase = base - amp;
						outAmp = amp * 2.0f;
					}
					if ( freq == 0.0f ) {
						// a zero frequency freezes the wave in Quake 3
						dest += Q3Str( "\tdeform wave %s 0 %s %s %s 0\n", table,
							Q3Float( outBase ).c_str(), Q3Float( outAmp ).c_str(), Q3Float( phase ).c_str() ).c_str();
					} else {
						// Quake 3 divides the vertex position sum by the spread
						const float spread = ( div != 0.0f ) ? ( 1.0f / div ) : 100.0f;
						dest += Q3Str( "\tdeform wave %s %s %s %s %s ( time * %s )\n", table,
							Q3Float( spread ).c_str(), Q3Float( outBase ).c_str(), Q3Float( outAmp ).c_str(),
							Q3Float( phase ).c_str(), Q3Float( freq ).c_str() ).c_str();
					}
				}
				return;
			}
			if ( !deformTok.Icmp( "bulge" ) ) {
				// deformVertexes bulge <width> <height> <speed>
				const float width = src.ParseFloat();
				const float height = src.ParseFloat();
				const float speed = src.ParseFloat();
				// the Doom 3 bulge counts texture coordinate cycles while
				// Quake 3 counts radians, and the sin table covers one cycle
				const float twoPi = idMath::PI * 2.0f;
				q3NeedWaveTables = true;
				dest += Q3Str( "\tdeform bulge q3waveSin %s %s ( time * %s )\n",
					Q3Float( width / twoPi ).c_str(), Q3Float( height ).c_str(),
					Q3Float( speed / twoPi ).c_str() ).c_str();
				return;
			}
			if ( !deformTok.Icmp( "normal" ) ) {
				// deformVertexes normal <amplitude> <frequency>
				const float amplitude = src.ParseFloat();
				const float freq = src.ParseFloat();
				dest += Q3Str( "\tdeform normal %s ( time * %s )\n",
					Q3Float( amplitude ).c_str(), Q3Float( freq ).c_str() ).c_str();
				return;
			}
			Q3UnknownDirective( src, token.c_str(), "\t", dest, conv );
		}
		return;
	}

	if ( !token.Icmp( "surfaceparm" ) ) {
		idToken parmTok;
		if ( src.ReadTokenOnLine( &parmTok ) ) {
			Q3SurfaceParm( parmTok.c_str(), dest, conv );
		}
		return;
	}

	Q3UnknownDirective( src, token.c_str(), "\t", dest, conv );
}

/*
=================
Q3ParseShader

Parses one Quake 3 shader into a
complete Doom 3 material.
=================
*/
static idStr Q3ParseShader( idLexer &src, const char *shaderName, Q3ShaderConverter *conv ) {
	idToken token;
	idStr body;
	idStr stages;
	idStr deformLine;
	q3Stage_t pending;
	bool havePending = false;

	while ( src.ExpectAnyToken( &token ) ) {
		if ( token == "}" ) {
			break;
		}
		if ( token == "{" ) {
			q3Stage_t stage;
			Q3ParseStage( src, shaderName, stage, conv );
			if ( stage.deformText.Length() > 0 ) {
				if ( deformLine.Length() > 0 ) {
					stages += "\t//tcMod turb dropped, the material already has a turbulent deform\n";
					conv->numWarnings++;
				} else {
					deformLine = stage.deformText;
				}
			}
			if ( stage.dropComment.Length() > 0 ) {
				conv->numStagesDropped++;
				stages += "\t";
				stages += stage.dropComment.c_str();
				stages += "\n";
				continue;
			}
			if ( havePending ) {
				// a second real stage: the held map stage stays a stage, unless
				// it is a diffuse lighting stage that promotes to the material
				// diffusemap
				if ( pending.promoteNote.Length() > 0 ) {
					body += "\t";
					body += pending.promoteNote.c_str();
					body += "\n";
					body += "\tdiffusemap ";
					body += pending.mapName.c_str();
					body += "\n";
					conv->numStages++;
				} else {
					stages += Q3StageBlock( pending ).c_str();
					conv->numStages++;
				}
				havePending = false;
			} else if ( stage.plainMap ) {
				pending = stage;
				havePending = true;
				continue;
			}
			stages += Q3StageBlock( stage ).c_str();
			conv->numStages++;
			continue;
		}
		Q3ParseShaderDirective( src, token, body, conv );
	}

	if ( havePending ) {
		if ( pending.promoteNote.Length() > 0 ) {
			body += "\t";
			body += pending.promoteNote.c_str();
			body += "\n";
		}
		body += "\tdiffusemap ";
		body += pending.mapName.c_str();
		body += "\n";
		conv->numStages++;
	}

	// the Doom 3 material only carries one deform, so a converted
	// deformVertexes deform wins over the collected turbulent wobble
	if ( deformLine.Length() > 0 ) {
		if ( body.Find( "\tdeform ", false ) >= 0 ) {
			stages += "\t//tcMod turb dropped, the material already has a deform\n";
			conv->numWarnings++;
		} else {
			body += deformLine.c_str();
		}
	}

	idStr out = "material ";
	out += shaderName;
	out += "\n{\n";
	out += body.c_str();
	out += stages.c_str();
	out += "}\n\n";
	return out;
}

/*
=================
Q3WriteWaveTables
=================
*/
static void Q3WriteWaveTables( const char *outputDir ) {
	const int numValues = 64;
	idStr out;

	out += "table q3waveSin\n{\n\t{\n";
	for ( int i = 0; i < numValues; i++ ) {
		float v = idMath::Sin( ( idMath::PI * 2.0f ) * ( i / (float)numValues ) );
		out += Q3Str( "\t\t%s%s\n", Q3Float( v ).c_str(), i == numValues - 1 ? "" : "," ).c_str();
	}
	out += "\t}\n}\n\n";

	// Q3 square: base + amp for the first half of the cycle, base - amp after;
	// the expression multiplies by 2 and subtracts 1
	out += "table q3waveSquare\n{\n\tsnap\n\t{\n\t\t1,\n\t\t0\n\t}\n}\n\n";

	// Q3 triangle runs 0 -> 1 -> 0 -> -1 -> 0 over one full cycle
	out += "table q3waveTriangle\n{\n\t{\n";
	for ( int i = 0; i < numValues; i++ ) {
		float u = i / (float)numValues;
		float v;
		if ( u < 0.25f ) {
			v = u * 4.0f;
		} else if ( u < 0.75f ) {
			v = 2.0f - u * 4.0f;
		} else {
			v = u * 4.0f - 4.0f;
		}
		out += Q3Str( "\t\t%s%s\n", Q3Float( v ).c_str(), i == numValues - 1 ? "" : "," ).c_str();
	}
	out += "\t}\n}\n\n";

	out += "table q3waveSawtooth\n{\n\t{\n";
	for ( int i = 0; i < numValues; i++ ) {
		float v = i / (float)numValues;
		out += Q3Str( "\t\t%s%s\n", Q3Float( v ).c_str(), i == numValues - 1 ? "" : "," ).c_str();
	}
	out += "\t}\n}\n\n";

	out += "table q3waveInversesawtooth\n{\n\t{\n";
	for ( int i = 0; i < numValues; i++ ) {
		float v = 1.0f - i / (float)numValues;
		out += Q3Str( "\t\t%s%s\n", Q3Float( v ).c_str(), i == numValues - 1 ? "" : "," ).c_str();
	}
	out += "\t}\n}\n\n";

	idStr path = Q3Str( "%s/_waves.mtr", outputDir );
	fileSystem->WriteFile( path.c_str(), out.c_str(), out.Length() );
}

/*
=================
Q3ConvertShaderFile

Converts one .shader file into a .mtr file under the output directory.
=================
*/
static void Q3ConvertShaderFile( const char *relativePath, const char *outputDir, Q3ShaderConverter *conv ) {
	void *buffer = NULL;
	int length = fileSystem->ReadFile( relativePath, &buffer );
	if ( length <= 0 || buffer == NULL ) {
		common->Printf( S_COLOR_RED "could not read %s" S_COLOR_WHITE "\n", relativePath );
		return;
	}

	idLexer src( LEXFL_ALLOWPATHNAMES | LEXFL_NODOLLARPRECOMPILE | LEXFL_NOFATALERRORS );
	src.LoadMemory( (const char *)buffer, length, relativePath );

	idStr out;
	idToken token;
	int shadersBefore = conv->numShaders;
	while ( src.ReadToken( &token ) ) {
		if ( token == "}" ) {
			continue;	// stray brace, keep going
		}
		idToken brace;
		if ( !src.ReadToken( &brace ) ) {
			break;
		}
		if ( brace != "{" ) {
			src.Warning( "expected '{' after shader '%s'", token.c_str() );
			src.SkipRestOfLine();
			continue;
		}
		out += Q3ParseShader( src, token.c_str(), conv ).c_str();
		conv->numShaders++;
	}
	src.FreeSource();
	fileSystem->FreeFile( buffer );

	int numConverted = conv->numShaders - shadersBefore;
	if ( out.Length() == 0 ) {
		return;
	}

	// scripts/base_floor.shader -> materials/base_floor.mtr
	const char *base = relativePath;
	for ( const char *p = relativePath; *p != '\0'; p++ ) {
		if ( *p == '/' || *p == '\\' ) {
			base = p + 1;
		}
	}
	int baseLen = 0;
	while ( base[baseLen] != '\0' && base[baseLen] != '.' ) {
		baseLen++;
	}

	idStr outPath = Q3Str( "%s/%.*s.mtr", outputDir, baseLen, base );
	fileSystem->WriteFile( outPath.c_str(), out.c_str(), out.Length() );
	common->Printf( S_COLOR_GREEN "converted %d shader%s from %s to %s" S_COLOR_WHITE "\n",
		numConverted, numConverted == 1 ? "" : "s", relativePath, outPath.c_str() );
}

/*
=================
Q3ShaderConverter::Q3ShaderConverter
=================
*/
Q3ShaderConverter::Q3ShaderConverter() {
	numShaders = 0;
	numStages = 0;
	numStagesDropped = 0;
	numWarnings = 0;
	needWaveTables = false;
}

/*
=================
Q3ShaderConverter::ConvertShaders

Converts every shader file with the given extension under sourceDir.
Returns true when at least one shader was written.
=================
*/
bool Q3ShaderConverter::ConvertShaders( const char *sourceDir, const char *sourceExtension, const char *outputDir ) {
	q3NeedWaveTables = false;

	idFileList *files = fileSystem->ListFilesTree( sourceDir, sourceExtension, true );
	if ( files != NULL ) {
		int numFiles = files->GetNumFiles();
		for ( int i = 0; i < numFiles; i++ ) {
			Q3ConvertShaderFile( files->GetFile( i ), outputDir, this );
		}
		fileSystem->FreeFileList( files );
	}

	if ( q3NeedWaveTables ) {
		needWaveTables = true;
		Q3WriteWaveTables( outputDir );
	}

	return numShaders > 0;
}
