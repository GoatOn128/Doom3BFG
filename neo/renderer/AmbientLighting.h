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

If you have questions concerning the license or the applicable additional terms, you should contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#ifndef __AMBIENTLIGHTING_H__
#define __AMBIENTLIGHTING_H__

/*
===============================================================================

	Baked ambient lighting

	Bakes a six direction ambient color per point of the map into an octree
	of samples and adds it to dynamic models at runtime so they never go
	fully black where the shadow map lights do not reach them.

	Adapted from the Wolfenstein: The New Order baked ambient system
	(references/wolfnto-reversedengineered). That material is decompiled
	proprietary code and is not GPL-compatible; this is a re-implementation
	on this engine's idlib with its own file layout.

	File layout of the "<map>.ambient" file:
	int magic, int numNodes, int numSamples, float mins[3], float rootSize,
	int depth, then numNodes node_t entries, then numSamples sample_t
	entries. The children of a leaf level node are sample indices instead
	of node indices, AMBIENT_EMPTY marks a missing entry.
===============================================================================
*/

const int AMBIENT_MAGIC = 0x21155701;
// index of an empty child entry
const unsigned short AMBIENT_EMPTY = 0xFFFF;
// the six channel directions, +X, -X, +Y, -Y, +Z, -Z
const int AMBIENT_NUM_CHANNELS = 6;

class idAmbientLighting {
public:
	// an octree node, the children are node indices below the leaf level
	// and sample indices at the leaf level
	struct node_t {
		unsigned short	children[8];
	};
	// one ambient sample, the origin is stored as grid coordinates in
	// leafSize units so it fits in 16 bits
	struct sample_t {
		byte			channels[AMBIENT_NUM_CHANNELS][3];
		short			origin[3];
	};

						idAmbientLighting();
						~idAmbientLighting();

	void				Clear();
	// loads a "<map>.ambient" file, clears the data and returns false when
	// the file does not exist or is not valid
	bool				Load( const char *fileName );
	bool				IsLoaded() const { return fileData != NULL; }

	// fills channels[6][3] with the six direction colors in the 0 to 1
	// range, returns false when no baked data covers the point
	bool				SampleChannels( const idVec3 &point, float channels[6][3] ) const;
	// the average color of all channels, used as the fill color of a model
	bool				SampleFillColor( const idVec3 &point, idVec3 &color ) const;

private:
	byte *				fileData;
	const node_t *		nodes;
	int					numNodes;
	const sample_t *	samples;
	int					numSamples;

	idVec3				mins;			// the corner of the root cube
	float				rootSize;		// the size of the root cube
	int					depth;			// octree levels down to the leaves
};

extern idAmbientLighting ambientLighting;

// bakes "<map>.ambient" and "<map>_globalShadows2.bin" for the loaded map
void R_BakeAmbient_f( const idCmdArgs &args );
// loads the baked data of a map, called when the map is loaded
void R_LoadAmbientAndGlobalShadows( const char *mapName );

extern idCVar r_useAmbientLighting;
extern idCVar r_ambientFillScale;
extern idCVar r_ambientBakeMinNodeSize;
extern idCVar r_ambientBakeSkyBrightness;
extern idCVar r_ambientBakeLightScale;
extern idCVar r_globalShadowMapSize;

#endif /* !__AMBIENTLIGHTING_H__ */
