#include "precompiled.h"
#pragma hdrstop

#include "DeclRenderProg.h"

/*
Adapted from the Wolfenstein: The New Order idDeclRenderProg and decl render
prog generator reconstructed under references/wolfnto-reversedengineered
(declrenderprog.cpp, declrenderproggenerator.cpp). That material is decompiled
proprietary code and is not GPL-compatible; this is a re-implementation on
this engine's idlib.

Phase 2 scope: the decl parses the inherit, state, flags, and interaction
blocks and skips the parms and hlsl_vp/hlsl_fp blocks until the renderprog
generator lands.
*/

/*
gl state bits stored in renderProgData_t::glState, following the TNO layout:

blend src           0x01 - 0x07
blend dst           0x08 - 0x38
depthMask           0x40
colorMask           0x380
alphaMask           0x400
wireframe           0x800
polygonOffset       0x1000
depthFunc           0x2000 - 0x6000
twoSided            0x8000
backSided           0x10000
alphaCoverage       0x20000
blendOp             0x40000 - 0xC0000
stencil ref         << 20
stencil mask        << 28
stencil func        1 - 7 << 36
stencil ops         3-bit fields starting at 0x8000000000 << shift
*/

static void NormalizeStateToken( idToken & token ) {
	token.ToUpper();
	token.StripLeading( "GL_" );
}

static bool ReadStateToken( idLexer * src, idToken & token ) {
	if ( src->ReadToken( &token ) ) {
		return true;
	}
	src->Warning( "EOF in program." );
	return false;
}

/*
=================
ParseState
=================
*/
static bool ParseState( idLexer * src, renderProgData_t * data ) {
	idToken token;
	if ( !src->ExpectTokenString( "{" ) ) {
		return false;
	}
	while ( src->ReadToken( &token ) ) {
		if ( token.Icmp( "}" ) == 0 ) {
			return true;
		}

		if ( token.Icmp( "blend" ) == 0 ) {
			if ( !ReadStateToken( src, token ) ) {
				return false;
			}
			NormalizeStateToken( token );
			if ( token.Icmp( "ONE" ) == 0 ) {
			} else if ( token.Icmp( "ZERO" ) == 0 ) { data->glState |= 0x1;
			} else if ( token.Icmp( "DST_COLOR" ) == 0 ) { data->glState |= 0x2;
			} else if ( token.Icmp( "ONE_MINUS_DST_COLOR" ) == 0 ) { data->glState |= 0x3;
			} else if ( token.Icmp( "SRC_ALPHA" ) == 0 ) { data->glState |= 0x4;
			} else if ( token.Icmp( "ONE_MINUS_SRC_ALPHA" ) == 0 ) { data->glState |= 0x5;
			} else if ( token.Icmp( "DST_ALPHA" ) == 0 ) { data->glState |= 0x6;
			} else if ( token.Icmp( "ONE_MINUS_DST_ALPHA" ) == 0 ) { data->glState |= 0x7;
			} else {
				src->Warning( "bad blend mode %s", token.c_str() );
				return false;
			}
			if ( !ReadStateToken( src, token ) ) {
				return false;
			}
			NormalizeStateToken( token );
			if ( token.Icmp( "ZERO" ) == 0 ) {
			} else if ( token.Icmp( "ONE" ) == 0 ) { data->glState |= 0x8;
			} else if ( token.Icmp( "SRC_COLOR" ) == 0 ) { data->glState |= 0x10;
			} else if ( token.Icmp( "ONE_MINUS_SRC_COLOR" ) == 0 ) { data->glState |= 0x18;
			} else if ( token.Icmp( "SRC_ALPHA" ) == 0 ) { data->glState |= 0x20;
			} else if ( token.Icmp( "ONE_MINUS_SRC_ALPHA" ) == 0 ) { data->glState |= 0x28;
			} else if ( token.Icmp( "DST_ALPHA" ) == 0 ) { data->glState |= 0x30;
			} else if ( token.Icmp( "ONE_MINUS_DST_ALPHA" ) == 0 ) { data->glState |= 0x38;
			} else {
				src->Warning( "bad blend mode %s", token.c_str() );
				return false;
			}
		} else if ( token.Icmp( "blendOp" ) == 0 ) {
			if ( !ReadStateToken( src, token ) ) {
				return false;
			}
			NormalizeStateToken( token );
			if ( token.Icmp( "ADD" ) == 0 ) {
			} else if ( token.Icmp( "MIN" ) == 0 ) { data->glState |= 0x80000;
			} else if ( token.Icmp( "MAX" ) == 0 ) { data->glState |= 0xC0000;
			} else if ( token.Icmp( "SUB" ) == 0 ) { data->glState |= 0x40000;
			} else {
				src->Warning( "bad blend op %s", token.c_str() );
				return false;
			}
		} else if ( token.Icmp( "depthFunc" ) == 0 ) {
			if ( !ReadStateToken( src, token ) ) {
				return false;
			}
			NormalizeStateToken( token );
			if ( token.Icmp( "LEQUAL" ) == 0 ) {
			} else if ( token.Icmp( "GREATER" ) == 0 ) { data->glState |= 0x2000;
			} else if ( token.Icmp( "ALWAYS" ) == 0 ) { data->glState |= 0x4000;
			} else if ( token.Icmp( "EQUAL" ) == 0 ) { data->glState |= 0x6000;
			} else {
				src->Warning( "bad depthFunc %s", token.c_str() );
				return false;
			}
		} else if ( token.Icmp( "wireframe" ) == 0 ) {
			data->glState |= 0x800;
		} else if ( token.Icmp( "alphaCoverage" ) == 0 ) {
			data->glState |= 0x20000;
			data->hasAlphaToCoverage = true;
		} else if ( token.Icmp( "depthMask" ) == 0 ) {
			data->glState |= 0x40;
		} else if ( token.Icmp( "colorMask" ) == 0 ) {
			data->glState |= 0x380;
		} else if ( token.Icmp( "alphaMask" ) == 0 ) {
			data->glState |= 0x400;
		} else if ( token.Icmp( "twoSided" ) == 0 ) {
			data->glState |= 0x8000;
		} else if ( token.Icmp( "backSided" ) == 0 ) {
			data->glState |= 0x10000;
		} else if ( token.Icmp( "polygonOffset" ) == 0 ) {
			data->glState |= 0x1000;
		} else if ( token.Icmp( "stencilOp" ) == 0 ) {
			for ( int shift = 0; shift < 9; shift += 3 ) {
				if ( !ReadStateToken( src, token ) ) {
					return false;
				}
				NormalizeStateToken( token );
				unsigned long long operation = 0;
				if ( token.Icmp( "KEEP" ) == 0 ) { operation = 0;
				} else if ( token.Icmp( "ZERO" ) == 0 ) { operation = 0x8000000000ull;
				} else if ( token.Icmp( "REPLACE" ) == 0 ) { operation = 0x10000000000ull;
				} else if ( token.Icmp( "INCR" ) == 0 ) { operation = 0x18000000000ull;
				} else if ( token.Icmp( "DECR" ) == 0 ) { operation = 0x20000000000ull;
				} else if ( token.Icmp( "INVERT" ) == 0 ) { operation = 0x28000000000ull;
				} else if ( token.Icmp( "INCR_WRAP" ) == 0 ) { operation = 0x30000000000ull;
				} else if ( token.Icmp( "DECR_WRAP" ) == 0 ) { operation = 0x38000000000ull;
				} else {
					src->Warning( "bad stencilOp %s", token.c_str() );
					return false;
				}
				data->glState |= operation << shift;
			}
		} else if ( token.Icmp( "stencilFunc" ) == 0 ) {
			if ( !ReadStateToken( src, token ) ) {
				return false;
			}
			NormalizeStateToken( token );
			if ( token.Icmp( "ALWAYS" ) == 0 ) {
			} else if ( token.Icmp( "LESS" ) == 0 ) { data->glState |= 0x1000000000ull;
			} else if ( token.Icmp( "LEQUAL" ) == 0 ) { data->glState |= 0x2000000000ull;
			} else if ( token.Icmp( "GREATER" ) == 0 ) { data->glState |= 0x3000000000ull;
			} else if ( token.Icmp( "GEQUAL" ) == 0 ) { data->glState |= 0x4000000000ull;
			} else if ( token.Icmp( "EQUAL" ) == 0 ) { data->glState |= 0x5000000000ull;
			} else if ( token.Icmp( "NOTEQUAL" ) == 0 ) { data->glState |= 0x6000000000ull;
			} else if ( token.Icmp( "NEVER" ) == 0 ) { data->glState |= 0x7000000000ull;
			} else {
				src->Warning( "bad stencilFunc %s", token.c_str() );
				return false;
			}
			if ( src->ReadTokenOnLine( &token ) ) {
				data->glState |= ( unsigned long long )( token.type == TT_NUMBER ? token.GetIntValue() : 0 ) << 20;
			}
			if ( src->ReadTokenOnLine( &token ) ) {
				data->glState |= ( unsigned long long )( token.type == TT_NUMBER ? token.GetIntValue() : 0 ) << 28;
			}
		} else {
			src->Warning( "Unknown drawing state option '%s'", token.c_str() );
		}
	}
	src->Warning( "Unexpected EOF in state block" );
	return false;
}

/*
=================
ParseFlags
=================
*/
static bool ParseFlags( idLexer * src, renderProgData_t * data ) {
	idToken token;
	if ( !src->ExpectTokenString( "{" ) ) {
		return false;
	}
	while ( src->ReadToken( &token ) ) {
		if ( token.Icmp( "}" ) == 0 ) {
			return true;
		}
		if ( token.Icmp( "perforated" ) == 0 ) {
			data->flags |= 1;
		} else if ( token.Icmp( "sky" ) == 0 ) {
			data->flags |= 2;
		} else if ( token.Icmp( "modelfade" ) == 0 ) {
			data->flags |= 4;
		} else {
			src->Warning( "Unknown flag option '%s'", token.c_str() );
		}
	}
	src->Warning( "Unexpected EOF in flags block" );
	return false;
}

/*
=================
renderProgData_t::Clear
=================
*/
void renderProgData_t::Clear() {
	inheritsFrom.Clear();
	compoundCheckSum = 0;
	parentCheckSum = 0;
	dependencies.Clear();
	glState = 0;
	parmBlock.Clear();
	vertexParms.Clear();
	fragmentParms.Clear();
	textureParms.Clear();
	samplerParms.Clear();
	flags = 0;
	stageSort = 0.0f;
	hasInteractions = false;
	hasAlphaToCoverage = false;
	has16BitScaleBias = false;
	hasHardwareSkinning = false;
	hasVertexTexture = false;
	hasClip = false;
	hasDepthOutput = false;
	hasBranchStripping = false;
	vertexMask = 0;
	fragmentOutputs = 0;
	vertexCode.Clear();
	fragmentCode.Clear();
}

/*
=================
renderProgData_t::operator=
=================
*/
renderProgData_t & renderProgData_t::operator=( const renderProgData_t & other ) {
	if ( this == &other ) {
		return *this;
	}
	inheritsFrom = other.inheritsFrom;
	compoundCheckSum = other.compoundCheckSum;
	parentCheckSum = other.parentCheckSum;
	dependencies = other.dependencies;
	glState = other.glState;
	parmBlock.CopyFrom( other.parmBlock );
	vertexParms = other.vertexParms;
	fragmentParms = other.fragmentParms;
	textureParms = other.textureParms;
	samplerParms = other.samplerParms;
	flags = other.flags;
	stageSort = other.stageSort;
	hasInteractions = other.hasInteractions;
	hasAlphaToCoverage = other.hasAlphaToCoverage;
	has16BitScaleBias = other.has16BitScaleBias;
	hasHardwareSkinning = other.hasHardwareSkinning;
	hasVertexTexture = other.hasVertexTexture;
	hasClip = other.hasClip;
	hasDepthOutput = other.hasDepthOutput;
	hasBranchStripping = other.hasBranchStripping;
	vertexMask = other.vertexMask;
	fragmentOutputs = other.fragmentOutputs;
	vertexCode = other.vertexCode;
	fragmentCode = other.fragmentCode;
	return *this;
}

/*
=================
idDeclRenderProg::Clear
=================
*/
void idDeclRenderProg::Clear() {
	data.Clear();
	inheritsFromDecl = nullptr;
	vertexProgramChecksum = 0;
	fragmentProgramChecksum = 0;
	hasDerived = false;
	versions.Clear();
	versions.Append( this );
	versions.Append( this );
	versions.Append( this );
}

/*
=================
idDeclRenderProg::FreeData
=================
*/
void idDeclRenderProg::FreeData() {
	Clear();
}

/*
=================
idDeclRenderProg::DefaultDefinition
=================
*/
const char * idDeclRenderProg::DefaultDefinition() const {
	return "{\tstate { depthFunc GL_LEQUAL }\n"
		"\thlsl_vp {\n"
		"\t\tresult.position.x = dot4( vertex.position, $mvpMatrixX );\n"
		"\t\tresult.position.y = dot4( vertex.position, $mvpMatrixY );\n"
		"\t\tresult.position.z = dot4( vertex.position, $mvpMatrixZ );\n"
		"\t\tresult.position.w = dot4( vertex.position, $mvpMatrixW );\n"
		"\t}\n"
		"\thlsl_fp {\n"
		"\t\tresult.color = float4( 0.2, 1.0, 0.4, 1.0 );\n"
		"\t}\n"
		"}\n";
}

/*
=================
idDeclRenderProg::Parse
=================
*/
bool idDeclRenderProg::Parse( const char * text, const int textLength, bool allowBinaryVersion ) {
	idLexer src;
	idToken token;

	Clear();

	src.LoadMemory( text, textLength, GetFileName(), GetLineNum() );
	src.SetFlags( DECL_LEXER_FLAGS );
	src.SkipUntilString( "{" );

	bool parsedShader = false;
	while ( src.ReadToken( &token ) ) {
		if ( token.Icmp( "}" ) == 0 ) {
			break;
		} else if ( token.Icmp( "inherit" ) == 0 ) {
			if ( data.glState != 0 || data.flags != 0 || data.parmBlock.NumOps() != 0 || parsedShader ) {
				src.Warning( "'inherit' MUST come before all other commands" );
				MakeDefault();
				return false;
			}
			if ( !src.ReadToken( &token ) ) {
				src.Warning( "Unexpected EOF after 'inherit'" );
				MakeDefault();
				return false;
			}
			const idDeclRenderProg * parent = static_cast< const idDeclRenderProg * >( declManager->FindType( DECL_RENDERPROG, token, false ) );
			if ( parent == nullptr ) {
				src.Warning( "Unknown RenderProg %s", token.c_str() );
				MakeDefault();
				return false;
			}
			data = parent->data;
			data.inheritsFrom = parent->GetName();
			data.parentCheckSum = data.compoundCheckSum;
			inheritsFromDecl = parent;
			const_cast< idDeclRenderProg * >( parent )->hasDerived = true;
		} else if ( token.Icmp( "parms" ) == 0 ) {
			// the parm block expression parser lands with the renderprog generator
			src.SkipBracedSection( true );
		} else if ( token.Icmp( "state" ) == 0 ) {
			data.glState = 0;
			data.hasAlphaToCoverage = false;
			if ( !ParseState( &src, &data ) ) {
				MakeDefault();
				return false;
			}
		} else if ( token.Icmp( "flags" ) == 0 ) {
			data.flags = 0;
			if ( !ParseFlags( &src, &data ) ) {
				MakeDefault();
				return false;
			}
		} else if ( token.Icmp( "interaction" ) == 0 ) {
			data.hasInteractions = true;
		} else if ( token.Icmp( "hlsl_vp" ) == 0 || token.Icmp( "hlsl_fp" ) == 0 ) {
			// the shader body translation lands with the renderprog generator
			src.SkipBracedSection( true );
			parsedShader = true;
		} else {
			src.Warning( "Unknown program type: %s", token.c_str() );
			MakeDefault();
			return false;
		}
	}

	if ( data.hasInteractions ) {
		idStr variant( GetName() );
		variant.Append( "_point" );
		versions[0] = static_cast< const idDeclRenderProg * >( declManager->FindType( DECL_RENDERPROG, variant, false ) );
		variant = GetName();
		variant.Append( "_spot" );
		versions[1] = static_cast< const idDeclRenderProg * >( declManager->FindType( DECL_RENDERPROG, variant, false ) );
		variant = GetName();
		variant.Append( "_parallel" );
		versions[2] = static_cast< const idDeclRenderProg * >( declManager->FindType( DECL_RENDERPROG, variant, false ) );
	}

	return true;
}

/*
=================
idDeclRenderProg::List
=================
*/
void idDeclRenderProg::List() const {
	idLib::Printf( "%2i %2i %2i %s\n", data.vertexParms.Num(), data.fragmentParms.Num(), data.textureParms.Num(), GetName() );
}

/*
=================
idDeclRenderProg::Print
=================
*/
void idDeclRenderProg::Print() const {
	const idStaticList<short, 42> * uniformParms[2] = { &data.vertexParms, &data.fragmentParms };
	const char * uniformHeadings[2] = { "--- vertex uniforms ---\n", "--- fragment uniforms ---\n" };
	for ( int group = 0; group < 2; group++ ) {
		idLib::Printf( "%s", uniformHeadings[group] );
		for ( int index = 0; index < uniformParms[group]->Num(); index++ ) {
			const char * name = renderProgParms.GetParmNameForIndex( ( *uniformParms[group] )[index] );
			idLib::Printf( "%s\n", name != nullptr ? name : "<badParmIndex>" );
		}
	}
	const idStaticList<short, 16> * textureParms[2] = { &data.textureParms, &data.samplerParms };
	const char * textureHeadings[2] = { "--- textures ---\n", "--- samplers ---\n" };
	for ( int group = 0; group < 2; group++ ) {
		idLib::Printf( "%s", textureHeadings[group] );
		for ( int index = 0; index < textureParms[group]->Num(); index++ ) {
			const char * name = renderProgParms.GetParmNameForIndex( ( *textureParms[group] )[index] );
			idLib::Printf( "%s\n", name != nullptr ? name : "<badParmIndex>" );
		}
	}
}

/*
=================
idDeclRenderProg::ProgUsesParm
=================
*/
bool idDeclRenderProg::ProgUsesParm( const idRenderProgParm * parm ) const {
	if ( parm == nullptr ) {
		return false;
	}
	const short parmIndex = ( short )parm->GetIndex();
	const idStaticList<short, 42> * uniformParms[2] = { &data.vertexParms, &data.fragmentParms };
	for ( int group = 0; group < 2; group++ ) {
		for ( int index = 0; index < uniformParms[group]->Num(); index++ ) {
			if ( ( *uniformParms[group] )[index] == parmIndex ) {
				return true;
			}
		}
	}
	const idStaticList<short, 16> * textureParms[2] = { &data.textureParms, &data.samplerParms };
	for ( int group = 0; group < 2; group++ ) {
		for ( int index = 0; index < textureParms[group]->Num(); index++ ) {
			if ( ( *textureParms[group] )[index] == parmIndex ) {
				return true;
			}
		}
	}
	return false;
}
