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

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms.
You should have received a copy of these additional terms immediately following
the terms and conditions of the GNU General Public License which accompanied the
Doom 3 BFG Edition Source Code.  If not, please request a copy in writing from
id Software at the address below.

If you have questions concerning this license, the applicable additional terms,
or would like to contact id Software, please write:

id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================*/

// MDM model support ported from the Wolfenstein: Enemy Territory GPL Source
// Code (Copyright (C) 1999-2010 id Software LLC, a ZeniMax Media company).
// The ET source is GPLv3 like this engine and is also vendored in this
// repository under references/etwolf. The shared skeletal base lives in
// Model_wolf.cpp.

#ifndef __MODEL_MDM_H__
#define __MODEL_MDM_H__

#include "Model_wolf.h"

// MDM: mesh and tags from the .mdm, skeleton and frames from the sibling .mdx
class idRenderModelMDM : public idRenderModelWolfSkeletal {
public:
					idRenderModelMDM() {}
	virtual			~idRenderModelMDM() {}

protected:
	virtual void	DecodeFrame( int frameNum, idJointQuat *jointQuats ) const;
	virtual bool	LoadWolfFile( const char *fileName );
};

#endif /* !__MODEL_MDM_H__ */
