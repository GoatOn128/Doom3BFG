#ifndef __DECLRENDERPROGATTRIBS_H__
#define __DECLRENDERPROGATTRIBS_H__

/*
Render program attribute tables and shader construction info for the
renderprog system migration.

Adapted from the Wolfenstein: The New Order idDeclRenderProgAttribs
reconstructed under references/wolfnto-reversedengineered
(declrenderprogattribs.h). That material is decompiled proprietary code and
is not GPL-compatible; this is a re-implementation on this engine's idlib.
The console attribute tables (PC_D3D, 360, PS3, Orbis) of the original are
dropped; PC GLSL is the only target.
*/

#include "idlib/Str.h"
#include "idlib/containers/StaticList.h"

enum renderProgAttribType_t {
	AT_VS_IN = 1 << 1,
	AT_VS_OUT = 1 << 2,
	AT_PS_IN = 1 << 3,
	AT_PS_OUT = 1 << 4,
	AT_PS_INOUT = 1 << 5,
};

struct attribInfo_t {
	const char *	type;
	const char *	name;
	const char *	semantic;
	const char *	glsl;
	int				bind;
	int				flags;
	int				vertexMask;
};

extern attribInfo_t attribsPC[];

enum programType_t {
	PROGRAM_TYPE_VERTEX = 0,
	PROGRAM_TYPE_FRAGMENT = 1,
};

struct shaderConstructInfo_t {
	shaderConstructInfo_t() { Clear(); }

	void			Clear();

	bool			parsed;
	idStr			headerString;
	idStr			sourceString;
	idStr			outputAttribInitString;
	idStaticList<attribInfo_t, 16>	inAttribs;
	idStaticList<attribInfo_t, 16>	outAttribs;
};

#endif
