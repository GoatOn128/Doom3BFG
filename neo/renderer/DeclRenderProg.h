#ifndef __DECLRENDERPROG_H__
#define __DECLRENDERPROG_H__

/*
Render program declaration for the renderprog system migration.

Adapted from the Wolfenstein: The New Order idDeclRenderProg interface
reconstructed under references/wolfnto-reversedengineered (declrenderprog.h).
That material is decompiled proprietary code and is not GPL-compatible; this
is a re-implementation on this engine's idlib. The platform resource manager,
the generated-file cache, and the console targets of the original are dropped;
PC GLSL is the only target.
*/

#include "framework/DeclManager.h"
#include "idlib/Str.h"
#include "idlib/containers/StaticList.h"

#include "ParmBlock.h"

class idImage;

/*
Per-decl data filled in by the parser. The inherit, state, flags, and
interaction blocks are parsed now; the parms and hlsl_vp/hlsl_fp blocks are
consumed when the renderprog generator lands. The glState bit layout follows
the TNO layout so later phases stay compatible.
*/
struct renderProgData_t {
	renderProgData_t() { Clear(); }

	void				Clear();
	renderProgData_t &	operator=( const renderProgData_t & other );

	idStr				inheritsFrom;
	unsigned int		compoundCheckSum;
	unsigned int		parentCheckSum;
	idList<idStr>		dependencies;
	unsigned long long	glState;			// gl state bits
	idParmBlock			parmBlock;			// parms{} block expressions
	idStaticList<short, 42>	vertexParms;	// uniform parms used by the vertex program
	idStaticList<short, 42>	fragmentParms;	// uniform parms used by the fragment program
	idStaticList<short, 16>	textureParms;	// texture parms used by either program
	idStaticList<short, 16>	samplerParms;	// sampler for each texture parm
	int					flags;				// perforated, sky, modelfade
	float				stageSort;			// sort value computed from the parm block
	bool				hasInteractions;	// has _point/_spot/_parallel variants
	bool				hasAlphaToCoverage;
	bool				has16BitScaleBias;
	bool				hasHardwareSkinning;
	bool				hasVertexTexture;
	bool				hasClip;
	bool				hasDepthOutput;
	bool				hasBranchStripping;
	unsigned int		vertexMask;			// vertex attributes used by the vertex program
	unsigned short		fragmentOutputs;		// number of fragment outputs
	idStr				vertexCode;
	idStr				fragmentCode;
};

class idDeclRenderProg : public idDecl {
public:
	idDeclRenderProg() { Clear(); }
	virtual					~idDeclRenderProg() { FreeData(); }

	virtual const char *	DefaultDefinition() const;
	virtual bool			Parse( const char *text, const int textLength, bool allowBinaryVersion );
	virtual void			FreeData();
	virtual size_t			Size() const { return sizeof( idDeclRenderProg ); }
	virtual void			List() const;
	virtual void			Print() const;

	// reset to the default state; an immediate FreeData() must be safe
	void					Clear();

	// true if any of the parm lists references the given parm
	bool					ProgUsesParm( const idRenderProgParm * parm ) const;

	// light interaction variants (_point/_spot/_parallel), resolved when the
	// decl has an interaction block; entries may be null
	const idDeclRenderProg *	GetInteractionVariant( int lightType ) const { return versions[lightType]; }

	renderProgData_t	data;

private:
	const idDeclRenderProg *	inheritsFromDecl;
	unsigned int			vertexProgramChecksum;
	unsigned int			fragmentProgramChecksum;
	bool					hasDerived;		// some other renderprog inherits from this one
	idStaticList<const idDeclRenderProg *, 3> versions;
};

#endif
