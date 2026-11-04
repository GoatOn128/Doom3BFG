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

#include "precompiled.h"
#pragma hdrstop

#include "tr_local.h"

#include "Model_local.h"
#include "Model_spr.h"

void R_DeriveTangentsWithoutNormals( srfTriangles_t *tri );

/***********************************************************************

	idRenderModelSPR

***********************************************************************/

static const char *SPR_SnapshotName = "_SPR_Snapshot_";

// dsprite_t ident "IDSP" and version
#define SPRITE_IDENT	( ( 'P' << 24 ) + ( 'S' << 16 ) + ( 'D' << 8 ) + 'I' )
#define SPRITE_VERSION	1

// spriteframetype_t
#define SPR_SINGLE	0
#define SPR_GROUP	1

// all header fields are little endian in the file
static int SPRInt( const byte *p ) {
	return ( int )p[0] | ( ( int )p[1] << 8 ) | ( ( int )p[2] << 16 ) | ( ( int )p[3] << 24 );
}

static float SPRFloat( const byte *p ) {
	int v = SPRInt( p );
	float f;
	memcpy( &f, &v, 4 );
	return f;
}

/*
=============
SPR_LoadQ1Palette

The Quake 1 palette is the 768 raw RGB bytes of gfx/palette.lmp.
It is read once and cached for all sprite loads.
=============
*/
static bool SPR_LoadQ1Palette( byte palette[768] ) {
	static byte		cachedPalette[768];
	static bool		checked = false;
	static bool		valid = false;

	if ( !checked ) {
		checked = true;
		byte *buffer = NULL;
		int len = fileSystem->ReadFile( "gfx/palette.lmp", ( void ** )&buffer );
		if ( buffer != NULL && len >= 768 ) {
			memcpy( cachedPalette, buffer, 768 );
			valid = true;
		}
		fileSystem->FreeFile( buffer );
		if ( !valid ) {
			common->Warning( "SPR loader couldn't read the Quake 1 palette from gfx/palette.lmp\n" );
		}
	}

	if ( valid ) {
		memcpy( palette, cachedPalette, 768 );
	}
	return valid;
}

/*
================
SPR embedded images

The decoded frames are handed to the image manager through a generator
function. The registry keeps the RGBA data for the life of the process,
entries with the same name are replaced when a model reloads.
================
*/
struct sprEmbeddedImage_t {
	idStr		name;
	byte *		pic;
	int			width;
	int			height;
};

static idList<sprEmbeddedImage_t, TAG_MODEL> sprEmbeddedImages;

static sprEmbeddedImage_t *SPR_FindEmbeddedImage( const char *name ) {
	for ( int i = 0; i < sprEmbeddedImages.Num(); i++ ) {
		if ( sprEmbeddedImages[i].name.Icmp( name ) == 0 ) {
			return &sprEmbeddedImages[i];
		}
	}
	return NULL;
}

static void SPR_RegisterEmbeddedImage( const char *name, byte *pic, int width, int height ) {
	sprEmbeddedImage_t *existing = SPR_FindEmbeddedImage( name );
	if ( existing != NULL ) {
		Mem_Free( existing->pic );
		existing->pic = pic;
		existing->width = width;
		existing->height = height;
		return;
	}
	sprEmbeddedImage_t &entry = sprEmbeddedImages.Alloc();
	entry.name = name;
	entry.pic = pic;
	entry.width = width;
	entry.height = height;
}

// the sampler parameters must match what an implicit material asks for, or
// the image manager would create a second, empty file image with the same name
static void SPR_GenerateEmbeddedImage( idImage *image ) {
	const sprEmbeddedImage_t *src = SPR_FindEmbeddedImage( image->GetName() );
	if ( src == NULL ) {
		common->Warning( "SPR generator missing the pixels for %s\n", image->GetName() );
		image->MakeDefault();
		return;
	}
	image->GenerateImage( src->pic, src->width, src->height, TF_DEFAULT, TR_CLAMP, TD_DEFAULT );
}

/*
=================
idRenderModelSPR::idRenderModelSPR
=================
*/
idRenderModelSPR::idRenderModelSPR() {
}

/*
=================
idRenderModelSPR::~idRenderModelSPR
=================
*/
idRenderModelSPR::~idRenderModelSPR() {
	// the base destructor calls PurgeModel again, which is a no-op then
	PurgeModel();
}

/*
=================
idRenderModelSPR::InitFromFile
=================
*/
void idRenderModelSPR::InitFromFile( const char *fileName ) {
	name = fileName;
	LoadModel();
}

/*
=================
idRenderModelSPR::LoadModel

Used for initial loads, reloadModel, and reloading the data of purged
models. Upon exit the model will be valid, possibly as a default model.
=================
*/
void idRenderModelSPR::LoadModel() {
	if ( !purged ) {
		PurgeModel();
	}
	purged = false;

	if ( !LoadSPRFile() ) {
		frames.Clear();
		MakeDefaultModel();
	}
}

/*
===================
idRenderModelSPR::LoadSPRFile
===================
*/
bool idRenderModelSPR::LoadSPRFile() {
	byte *buffer = NULL;
	int len = fileSystem->ReadFile( name, ( void ** )&buffer, &timeStamp );
	if ( buffer == NULL || len < 36 ) {
		common->Warning( "SPR loader was unable to load model %s\n", name.c_str() );
		fileSystem->FreeFile( buffer );
		return false;
	}

	// dsprite_t: ident, version, type, boundingradius, width, height,
	// numframes, beamlength, synctype
	if ( SPRInt( buffer + 0 ) != SPRITE_IDENT || SPRInt( buffer + 4 ) != SPRITE_VERSION ) {
		common->Warning( "%s has the wrong ident or version\n", name.c_str() );
		fileSystem->FreeFile( buffer );
		return false;
	}

	int numframes = SPRInt( buffer + 24 );
	if ( numframes < 1 || numframes > SPR_MAX_FRAMES ) {
		common->Warning( "%s has an invalid number of frames (%i)\n", name.c_str(), numframes );
		fileSystem->FreeFile( buffer );
		return false;
	}

	byte palette[768];
	if ( !SPR_LoadQ1Palette( palette ) ) {
		fileSystem->FreeFile( buffer );
		return false;
	}

	idStr imageBase = name;
	imageBase.StripFileExtension();

	int pos = 36;
	for ( int i = 0; i < numframes; i++ ) {
		if ( pos + 4 > len ) {
			fileSystem->FreeFile( buffer );
			return false;
		}
		int frametype = SPRInt( buffer + pos );
		pos += 4;
		if ( frametype == SPR_SINGLE ) {
			if ( !AddFrame( buffer, pos, len, imageBase, palette ) ) {
				fileSystem->FreeFile( buffer );
				return false;
			}
		} else if ( frametype == SPR_GROUP ) {
			if ( pos + 4 > len ) {
				fileSystem->FreeFile( buffer );
				return false;
			}
			int subframes = SPRInt( buffer + pos );
			pos += 4;
			if ( subframes < 1 || subframes > SPR_MAX_FRAMES ) {
				fileSystem->FreeFile( buffer );
				return false;
			}
			// the group intervals are flattened away, the game code
			// drives the timing through the frame shader parms
			pos += subframes * 4;
			for ( int j = 0; j < subframes; j++ ) {
				if ( !AddFrame( buffer, pos, len, imageBase, palette ) ) {
					fileSystem->FreeFile( buffer );
					return false;
				}
			}
		} else {
			common->Warning( "%s has an unknown frame type (%i)\n", name.c_str(), frametype );
			fileSystem->FreeFile( buffer );
			return false;
		}
	}

	fileSystem->FreeFile( buffer );

	// the reference bounds are the union of all frame bounds
	bounds.Clear();
	for ( int i = 0; i < frames.Num(); i++ ) {
		const sprFrame_t &fr = frames[i];
		idBounds frameBounds;
		frameBounds.Clear();
		frameBounds.AddPoint( idVec3( 0.0f, fr.left, fr.down ) );
		frameBounds.AddPoint( idVec3( 0.0f, fr.right, fr.up ) );
		bounds.AddBounds( frameBounds );
	}

	return true;
}

/*
===================
idRenderModelSPR::AddFrame

Decodes one frame block into an embedded image and a frame entry.
===================
*/
bool idRenderModelSPR::AddFrame( const byte *data, int &pos, int len, const idStr &imageBase, byte palette[768] ) {
	if ( frames.Num() >= SPR_MAX_FRAMES ) {
		return false;
	}
	if ( pos + 16 > len ) {
		return false;
	}

	// dspriteframe_t: origin[2], width, height, then the pixels
	float originX = SPRFloat( data + pos );
	float originY = SPRFloat( data + pos + 4 );
	int w = SPRInt( data + pos + 8 );
	int h = SPRInt( data + pos + 12 );
	pos += 16;
	if ( w <= 0 || h <= 0 || w > 4096 || h > 4096 || pos + w * h > len ) {
		return false;
	}

	const byte *pixels = data + pos;
	pos += w * h;

	byte *pic = ( byte * )Mem_Alloc( w * h * 4, TAG_IMAGE );
	// expand through the palette, bottom up; index 255 is transparent
	for ( int y = 0; y < h; y++ ) {
		const byte *inRow = pixels + y * w;
		byte *outRow = pic + ( h - 1 - y ) * w * 4;
		for ( int x = 0; x < w; x++ ) {
			byte index = inRow[x];
			byte *out = outRow + x * 4;
			if ( index == 255 ) {
				out[0] = out[1] = out[2] = out[3] = 0;
			} else {
				out[0] = palette[index*3+0];
				out[1] = palette[index*3+1];
				out[2] = palette[index*3+2];
				out[3] = 255;
			}
		}
	}
	// give transparent pixels the color of an opaque neighbor so mipmaps
	// don't smear black into the edges
	for ( int y = 0; y < h; y++ ) {
		for ( int x = 0; x < w; x++ ) {
			byte *out = pic + ( y * w + x ) * 4;
			if ( out[3] != 0 ) {
				continue;
			}
			const byte *neighbor = NULL;
			if ( x > 0 ) {
				neighbor = out - 4;
			} else if ( x < w - 1 ) {
				neighbor = out + 4;
			}
			if ( neighbor == NULL || neighbor[3] == 0 ) {
				if ( y > 0 ) {
					neighbor = out - w * 4;
				} else if ( y < h - 1 ) {
					neighbor = out + w * 4;
				}
			}
			if ( neighbor != NULL && neighbor[3] != 0 ) {
				out[0] = neighbor[0];
				out[1] = neighbor[1];
				out[2] = neighbor[2];
			}
		}
	}

	idStr imageName;
	imageName.Format( "%s_%i", imageBase.c_str(), frames.Num() );
	SPR_RegisterEmbeddedImage( imageName, pic, w, h );
	globalImages->ImageFromFunction( imageName, SPR_GenerateEmbeddedImage );

	sprFrame_t &frame = frames.Alloc();
	frame.material = declManager->FindMaterial( imageName );
	frame.width = w;
	frame.height = h;
	frame.left = originX;
	frame.right = originX + w;
	frame.up = originY;
	frame.down = originY - h;

	return true;
}

/*
===================
idRenderModelSPR::PurgeModel

Frees all the data, but leaves the class around for dangling references,
which can regenerate the data with LoadModel().
===================
*/
void idRenderModelSPR::PurgeModel() {
	idRenderModelStatic::PurgeModel();

	frames.Clear();
}

/*
=================
idRenderModelSPR::TouchData

Models that are already loaded at level start time will still touch
their materials to make sure they are kept loaded.
=================
*/
void idRenderModelSPR::TouchData() {
	for ( int i = 0; i < frames.Num(); i++ ) {
		if ( frames[i].material != NULL ) {
			frames[i].material = declManager->FindMaterial( frames[i].material->GetName() );
		}
	}
}

/*
=================
idRenderModelSPR::IsDynamicModel
=================
*/
dynamicModel_t idRenderModelSPR::IsDynamicModel() const {
	return DM_CACHED;
}

/*
=================
idRenderModelSPR::GetFrameParms

Reads the frame the entity wants to show.
=================
*/
void idRenderModelSPR::GetFrameParms( const struct renderEntity_s *ent, int &frame ) const {
	frame = 0;

	if ( ent == NULL ) {
		return;
	}

	frame = idMath::Ftoi( ent->shaderParms[SHADERPARM_MD3_FRAME] );
	frame = idMath::ClampInt( 0, frames.Num() - 1, frame );
}

/*
=================
idRenderModelSPR::InstantiateDynamicModel

Builds a quad on the Y/Z plane from the current frame extents.
=================
*/
idRenderModel *idRenderModelSPR::InstantiateDynamicModel( const struct renderEntity_s *ent, const viewDef_t *view, idRenderModel *cachedModel ) {
	if ( cachedModel != NULL && !r_useCachedDynamicModels.GetBool() ) {
		delete cachedModel;
		cachedModel = NULL;
	}

	if ( purged ) {
		common->DWarning( "model %s instantiated while purged", Name() );
		LoadModel();
	}

	if ( frames.Num() == 0 ) {
		delete cachedModel;
		return NULL;
	}

	int frame = 0;
	GetFrameParms( ent, frame );
	const sprFrame_t &fr = frames[frame];

	const idMaterial *shader = fr.material;
	if ( ent != NULL && ent->customShader != NULL ) {
		shader = ent->customShader;
	}
	if ( shader == NULL ) {
		shader = declManager->FindMaterial( "_default" );
	}
	if ( !shader || ( !shader->IsDrawn() && !shader->SurfaceCastsShadow() ) ) {
		delete cachedModel;
		return NULL;
	}

	idRenderModelStatic *staticModel;
	if ( cachedModel != NULL ) {
		assert( dynamic_cast<idRenderModelStatic *>( cachedModel ) != NULL );
		assert( idStr::Icmp( cachedModel->Name(), SPR_SnapshotName ) == 0 );
		staticModel = static_cast<idRenderModelStatic *>( cachedModel );
	} else {
		staticModel = new (TAG_MODEL) idRenderModelStatic;
		staticModel->InitEmpty( SPR_SnapshotName );
	}

	srfTriangles_t *tri;
	int surfaceNum = 0;
	if ( staticModel->FindSurfaceWithId( 0, surfaceNum ) ) {
		tri = staticModel->surfaces[surfaceNum].geometry;
	} else {
		modelSurface_t &surf = staticModel->surfaces.Alloc();
		surf.id = 0;
		surf.shader = NULL;
		surf.geometry = R_AllocStaticTriSurf();
		tri = surf.geometry;
		R_AllocStaticTriSurfVerts( tri, 4 );
		R_AllocStaticTriSurfIndexes( tri, 6 );
	}
	staticModel->surfaces[surfaceNum].shader = shader;

	tri->numVerts = 4;
	tri->numIndexes = 6;

	idDrawVert *verts = tri->verts;
	verts[0].Clear();
	verts[0].xyz = idVec3( 0.0f, fr.left, fr.up );
	verts[0].SetTexCoord( 0.0f, 1.0f );

	verts[1].Clear();
	verts[1].xyz = idVec3( 0.0f, fr.right, fr.up );
	verts[1].SetTexCoord( 1.0f, 1.0f );

	verts[2].Clear();
	verts[2].xyz = idVec3( 0.0f, fr.right, fr.down );
	verts[2].SetTexCoord( 1.0f, 0.0f );

	verts[3].Clear();
	verts[3].xyz = idVec3( 0.0f, fr.left, fr.down );
	verts[3].SetTexCoord( 0.0f, 0.0f );

	for ( int i = 0; i < 4; i++ ) {
		verts[i].SetNormal( 1.0f, 0.0f, 0.0f );
		verts[i].SetTangent( 0.0f, 1.0f, 0.0f );
		verts[i].SetBiTangent( 0.0f, 0.0f, 1.0f );
		for ( int c = 0; c < 4; c++ ) {
			verts[i].color[c] = 255;
			verts[i].color2[c] = 255;
		}
	}

	tri->indexes[0] = 0;
	tri->indexes[1] = 3;
	tri->indexes[2] = 2;
	tri->indexes[3] = 0;
	tri->indexes[4] = 2;
	tri->indexes[5] = 1;

	// build the tangents for interaction lighting, keeping the normals
	R_DeriveTangentsWithoutNormals( tri );

	R_BoundTriSurf( tri );

	staticModel->bounds = tri->bounds;

	return staticModel;
}

/*
=====================
idRenderModelSPR::Bounds
=====================
*/
idBounds idRenderModelSPR::Bounds( const struct renderEntity_s *ent ) const {
	if ( ent == NULL || frames.Num() == 0 ) {
		return bounds;
	}

	int frame = 0;
	GetFrameParms( ent, frame );
	const sprFrame_t &fr = frames[frame];

	idBounds ret;
	ret.Clear();
	ret.AddPoint( idVec3( 0.0f, fr.left, fr.down ) );
	ret.AddPoint( idVec3( 0.0f, fr.right, fr.up ) );
	return ret;
}

/*
==============
idRenderModelSPR::List
==============
*/
void idRenderModelSPR::List() const {
	common->Printf( " %7i bytes %3i frames %s", Memory(), frames.Num(), Name() );

	if ( defaulted ) {
		common->Printf( " (DEFAULTED)" );
	}

	common->Printf( "\n" );
}

/*
===============
idRenderModelSPR::Memory
===============
*/
int idRenderModelSPR::Memory() const {
	int total = sizeof( *this );
	total += frames.MemoryUsed();
	total += frames.Num() * sizeof( sprFrame_t );
	return total;
}
