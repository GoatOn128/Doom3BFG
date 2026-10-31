#ifndef __PARMBLOCK_H__
#define __PARMBLOCK_H__

#include "RenderProgParm.h"
#include "idlib/containers/List.h"
#include "idlib/math/Vector.h"

/*
Parm block expression system for the renderprog migration: a list of
operations that write render parms, with constants, write masks, and
inheritance through parent blocks.

Adapted from the Wolfenstein: The New Order idParmBlock reconstructed under
references/wolfnto-reversedengineered (parmblock.h/parmblock.cpp). That
material is decompiled proprietary code and is not GPL-compatible; this is a
re-implementation on this engine's idlib.
*/

// Operation types; the numbering matches the TNO ordering.
enum expOpType_t {
	OP_TYPE_UNMASKED_MOVE_CONSTANT = 0,
	OP_TYPE_UNMASKED_MOVE = 1,
	OP_TYPE_MOVE_CONSTANT = 2,
	OP_TYPE_MOVE = 3,
	OP_TYPE_SWIZZLE = 4,
	OP_TYPE_ADD = 5,
	OP_TYPE_SUBTRACT = 6,
	OP_TYPE_MULTIPLY = 7,
	OP_TYPE_DOT3 = 8,
	OP_TYPE_DOT4 = 9,
	OP_TYPE_DIVIDE = 10,
	OP_TYPE_MOD = 11,
	OP_TYPE_GT = 12,
	OP_TYPE_GE = 13,
	OP_TYPE_LT = 14,
	OP_TYPE_LE = 15,
	OP_TYPE_EQ = 16,
	OP_TYPE_NE = 17,
	OP_TYPE_AND = 18,
	OP_TYPE_OR = 19,
	OP_TYPE_TABLE = 20
};

// Any parm index at or above this value means "no parm".
static const short INVALID_PARM_INDEX = 2175;

// Bits 0-4 hold the operation type, bits 5-8 the parm type, bits 9-12 the
// write mask.
struct expOp_t {
	unsigned short	type;
	short			parmIndexDest;
	short			parmIndexA;
	short			parmIndexB;

	const idRenderProgParm *	GetDest() const;
	const idRenderProgParm *	GetA() const;
};

class idParmBlock {
public:
	int				NumOps() const { return ops.Num(); }
	const expOp_t &	GetOp( int index ) const { return ops[index]; }

	bool			SetsRenderParm( const idRenderProgParm * parm ) const;
	void			Clear();
	void			CopyFrom( const idParmBlock & other );
	void			Append( const idParmBlock & other );
	void			AddOp( const expOp_t & operation, const parmValue_t & constant );
	void			RemoveRedundantOperations();
	void			ClearParm( const idRenderProgParm * parm );

	void			SetParm( const idRenderProgParm * parm, const parmValue_t & value );
	void			SetParm( const idRenderProgParm * parm, const idRenderProgParm * sourceParm );
	void			SetParm( const idRenderProgParm * parm, const idVec4 & value );
	void			SetParm( const idRenderProgParm * parm, float value );
	void			SetFloat( const idRenderProgParm * parm, float value );
	void			SetVec4( const idRenderProgParm * parm, const idVec4 & value );
	void			SetImage( const idRenderProgParm * parm, const idImage * image );

	float			GetFloat( const idRenderProgParm * parm, const idParmBlock * parentBlock = nullptr ) const;
	int				GetInteger( const idRenderProgParm * parm, const idParmBlock * parentBlock = nullptr ) const;
	idVec4			GetVector( const idRenderProgParm * parm, const idParmBlock * parentBlock = nullptr ) const;
	const idImage *	GetImage( const idRenderProgParm * parm, const idParmBlock * parentBlock = nullptr ) const;

	bool			IsEqualSimple( const idParmBlock & other ) const;
	bool			operator==( const idParmBlock & other ) const;
	bool			operator!=( const idParmBlock & other ) const { return !( *this == other ); }

	idList<expOp_t>		ops;
	idList<parmValue_t>	constants;

private:
	void			GetRenderParmFromOps_r( parmValue_t & parmValue, int numOps, int parmIndex, const idParmBlock * parentBlock ) const;
};

#endif
