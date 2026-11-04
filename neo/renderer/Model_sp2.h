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

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms.  You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 BFG Edition Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning the license or the applicable additional terms, you may contact in writing to id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#ifndef __MODEL_SP2_H__
#define __MODEL_SP2_H__

#include "Model_common.h"

/*
========================================================================

.SP2 Quake 2 sprite files

The frames are fixed size records that reference their images by name,
the same way the Quake 2 loader looked them up. The game code selects
the frame with the MD3 frame shader parms, like the MD3 loader does.

========================================================================
*/

#define SP2_MAX_FRAMES	1024

/*
===============================================================================

	SP2 animated sprite model

===============================================================================
*/

class idRenderModelSP2 : public idRenderModelStatic {
public:
							idRenderModelSP2();
	virtual					~idRenderModelSP2();

	virtual void			InitFromFile( const char *fileName );
	virtual bool			SupportsBinaryModel() { return false; }
	virtual void			PurgeModel();
	virtual void			LoadModel();
	virtual void			TouchData();
	virtual void			List() const;
	virtual int				Memory() const;
	virtual dynamicModel_t	IsDynamicModel() const;
	virtual idRenderModel *	InstantiateDynamicModel( const struct renderEntity_s *ent, const viewDef_t *view, idRenderModel *cachedModel );
	virtual idBounds		Bounds( const struct renderEntity_s *ent ) const;

private:
	struct sp2Frame_t {
		const idMaterial *	material;
		int					width;
		int					height;
		float				left;		// distances from the sprite origin to the frame edges
		float				right;
		float				up;
		float				down;
	};

	idList<sp2Frame_t, TAG_MODEL>	frames;

	bool			LoadSP2File();
	void			GetFrameParms( const struct renderEntity_s *ent, int &frame ) const;
};

#endif /* !__MODEL_SP2_H__ */
