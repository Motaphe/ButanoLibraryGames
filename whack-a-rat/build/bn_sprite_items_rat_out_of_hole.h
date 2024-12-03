#ifndef BN_SPRITE_ITEMS_RAT_OUT_OF_HOLE_H
#define BN_SPRITE_ITEMS_RAT_OUT_OF_HOLE_H

#include "bn_sprite_item.h"

//{{BLOCK(rat_out_of_hole_bn_gfx)

//======================================================================
//
//	rat_out_of_hole_bn_gfx, 32x32@4, 
//	+ palette 20 entries, lz77 compressed
//	+ 16 tiles lz77 compressed
//	Total size: 40 + 448 = 488
//
//	Time-stamp: 2024-12-03, 07:27:15
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_RAT_OUT_OF_HOLE_BN_GFX_H
#define GRIT_RAT_OUT_OF_HOLE_BN_GFX_H

#define rat_out_of_hole_bn_gfxTilesLen 448
extern const bn::tile rat_out_of_hole_bn_gfxTiles[16];

#define rat_out_of_hole_bn_gfxPalLen 40
extern const bn::color rat_out_of_hole_bn_gfxPal[16];

#endif // GRIT_RAT_OUT_OF_HOLE_BN_GFX_H

//}}BLOCK(rat_out_of_hole_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item rat_out_of_hole(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(rat_out_of_hole_bn_gfxTiles, 16), bpp_mode::BPP_4, compression_type::LZ77, 1), 
            sprite_palette_item(span<const color>(rat_out_of_hole_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::LZ77));
}

#endif

