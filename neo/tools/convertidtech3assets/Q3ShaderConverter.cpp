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
	dest += Q3Str( "\t// q3: surfaceparm %s\n", parm ).c_str();
	conv->numWarnings++;
}

// Keeps an unsupported directive as a // q3: comment together with its arguments.
static void Q3UnknownDirective( idLexer &src, const char *token, const char *indent, idStr &dest, Q3ShaderConverter *conv ) {
	idStr rest;
	src.ReadRestOfLine( rest );
	dest += indent;
	dest += "// q3: ";
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
			if ( !mapTok.Icmp( "$lightmap" ) || !mapTok.Icmp( "$lightimage" ) ) {
				dropped = true;
				stage.plainMap = false;
				stage.dropComment = Q3Str( "// q3: dropped stage with map %s (the Doom 3 lighting model has no lightmaps)", mapTok.c_str() ).c_str();
				continue;
			}
			if ( !mapTok.Icmp( "$whiteimage" ) ) {
				stage.plainMap = false;
				stage.text += "\t\tmap _white\n";
				continue;
			}
			stage.mapName = mapTok.c_str();
			stage.text += "\t\tmap ";
			stage.text += mapTok.c_str();
			stage.text += "\n";
			continue;
		}

		if ( !token.Icmp( "clampMap" ) ) {
			idToken mapTok;
			if ( !src.ReadToken( &mapTok ) ) {
				continue;
			}
			stage.plainMap = false;
			stage.mapName = mapTok.c_str();
			stage.text += "\t\tclamp\n\t\tmap ";
			stage.text += mapTok.c_str();
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
				line += frame.c_str();
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
			stage.plainMap = false;
			if ( !genTok.Icmp( "vertex" ) || !genTok.Icmp( "exactVertex" ) ) {
				stage.text += "\t\tvertexColor\n";
				continue;
			}
			if ( !genTok.Icmp( "entity" ) || !genTok.Icmp( "oneMinusEntity" ) || !genTok.Icmp( "lightingDiffuse" ) ) {
				stage.text += Q3Str( "\t\tvertexColor // q3: rgbGen %s approximated\n", genTok.c_str() ).c_str();
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
					stage.text += Q3Str( "\t\t// q3: rgbGen wave %s (no Doom 3 equivalent)\n", funcTok.c_str() ).c_str();
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
					stage.text += "\t\t// q3: rgbGen const\n";
					conv->numWarnings++;
				}
				continue;
			}
			stage.text += Q3Str( "\t\t// q3: rgbGen %s\n", genTok.c_str() ).c_str();
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
					stage.text += Q3Str( "\t\t// q3: alphaGen wave %s (no Doom 3 equivalent)\n", funcTok.c_str() ).c_str();
					conv->numWarnings++;
				}
				continue;
			}
			if ( !genTok.Icmp( "const" ) ) {
				float v = src.ParseFloat();
				stage.text += Q3Str( "\t\talpha %s\n", Q3Float( v ).c_str() ).c_str();
				continue;
			}
			stage.text += Q3Str( "\t\t// q3: alphaGen %s\n", genTok.c_str() ).c_str();
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
				stage.text += "\t\t// q3: alphaFunc LT128\n";
				conv->numWarnings++;
			} else {
				stage.text += Q3Str( "\t\t// q3: alphaFunc %s\n", funcTok.c_str() ).c_str();
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
			stage.text += Q3Str( "\t\t// q3: tcGen %s\n", genTok.c_str() ).c_str();
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
			Q3UnknownDirective( src, token.c_str(), "\t\t", stage.text, conv );
			// stretch, turb and transform carry their arguments on the same line
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
			idStr rest;
			src.ReadRestOfLine( rest );
			stage.text += Q3Str( "\t\t// q3: depthFunc %s\n", Q3Trim( rest.c_str() ).c_str() ).c_str();
			continue;
		}

		if ( !token.Icmp( "detail" ) ) {
			continue;	// the Doom 3 interaction shader handles detail stages on its own
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
			dest += image.c_str();
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

Parses one Quake 3 shader (the open brace has just been consumed) into a
complete Doom 3 material. A shader whose only kept stage is a single
plain map is promoted to a material level diffusemap; as soon as a second
stage arrives the held map stage is flushed as a real stage.
=================
*/
static idStr Q3ParseShader( idLexer &src, const char *shaderName, Q3ShaderConverter *conv ) {
	idToken token;
	idStr body;
	idStr stages;
	q3Stage_t pending;
	bool havePending = false;

	while ( src.ExpectAnyToken( &token ) ) {
		if ( token == "}" ) {
			break;
		}
		if ( token == "{" ) {
			q3Stage_t stage;
			Q3ParseStage( src, shaderName, stage, conv );
			if ( stage.dropComment.Length() > 0 ) {
				conv->numStagesDropped++;
				stages += "\t";
				stages += stage.dropComment.c_str();
				stages += "\n";
				continue;
			}
			if ( havePending ) {
				// a second real stage: the held map stage stays a stage
				stages += Q3StageBlock( pending ).c_str();
				conv->numStages++;
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
		body += "\tdiffusemap ";
		body += pending.mapName.c_str();
		body += "\n";
		conv->numStages++;
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

Writes the shared wave tables backing the converted wave expressions.
Each table covers one full cycle; the Doom 3 table lookup interpolates
and wraps the cycle index on its own.
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

	out += "table q3waveTriangle\n{\n\t{\n";
	for ( int i = 0; i < numValues; i++ ) {
		float u = i / (float)numValues;
		float v = 1.0f - idMath::Fabs( 1.0f - u * 2.0f );
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

	idStr path = Q3Str( "%s/_q3waves.mtr", outputDir );
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
		common->Printf( "^1could not read %s^7\n", relativePath );
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

	// scripts/base_floor.shader -> materials/q3/base_floor.mtr
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
	common->Printf( "^2converted %d shader%s from %s to %s^7\n",
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
