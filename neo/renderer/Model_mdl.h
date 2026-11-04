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

#ifndef __MODEL_MDL_H__
#define __MODEL_MDL_H__

#include "Model_common.h"

/*
========================================================================

.MDL Quake 1 models

The skins are raw indexed images embedded in the file, the frames are
packed vertex blocks. Skin and frame groups are flattened, the game code
selects the frames with the MD3 frame shader parms, like the MD3 loader
does.

========================================================================
*/

#define MDL_MAX_FRAMES	1024
#define MDL_MAX_VERTS	4096
#define MDL_MAX_TRIS	8192
#define MDL_MAX_SKINS	64

/*
===============================================================================

	MDL animated model

===============================================================================
*/

class idRenderModelMDL : public idRenderModelStatic {
public:
							idRenderModelMDL();
	virtual					~idRenderModelMDL();

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
	// one vertex position and normal per frame
	struct mdlVert_t {
		idVec3		xyz;
		idVec3		normal;
	};

	struct mdlFrame_t {
		mdlVert_t *	verts;
		idBounds	bounds;
	};

	// one triangle corner references one vertex, the texture coordinates
	// are final because the backside shift depends on the triangle
	struct mdlTri_t {
		int			xyz[3];
		idVec2		st[3];
	};

	idList<mdlFrame_t, TAG_MODEL>	frames;
	mdlTri_t *			tris;
	int					numVerts;
	int					numTris;
	const idMaterial *	shader;
	idStr				imageBase;
	int					skinWidth;
	int					skinHeight;
	int					skinCount;
	idVec3				mdlScale;
	idVec3				mdlOrigin;

	bool			LoadMDLFile();
	bool			DecodeSkin( const byte *data, int &pos, int len, byte palette[768] );
	bool			DecodeFrame( const byte *data, int &pos, int len );
	void			FreeData();
	void			GetFrameParms( const struct renderEntity_s *ent, int &frame, int &lastFrame, float &backLerp ) const;
};

#endif /* !__MODEL_MDL_H__ */
