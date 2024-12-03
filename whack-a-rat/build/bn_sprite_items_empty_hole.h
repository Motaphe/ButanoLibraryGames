#ifndef BN_SPRITE_ITEMS_EMPTY_HOLE_H
#define BN_SPRITE_ITEMS_EMPTY_HOLE_H

#include "bn_sprite_item.h"

//{{BLOCK(empty_hole_bn_gfx)

//======================================================================
//
//	empty_hole_bn_gfx, 32x32@4, 
//	+ palette 20 entries, lz77 compressed
//	+ 16 tiles lz77 compressed
//	Total size: 40 + 288 = 328
//
//	Time-stamp: 2024-12-03, 07:27:15
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_EMPTY_HOLE_BN_GFX_H
#define GRIT_EMPTY_HOLE_BN_GFX_H

#define empty_hole_bn_gfxTilesLen 288
extern const bn::tile empty_hole_bn_gfxTiles[16];

#define empty_hole_bn_gfxPalLen 40
extern const bn::color empty_hole_bn_gfxPal[16];

#endif // GRIT_EMPTY_HOLE_BN_GFX_H

//}}BLOCK(empty_hole_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item empty_hole(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(empty_hole_bn_gfxTiles, 16), bpp_mode::BPP_4, compression_type::LZ77, 1), 
            sprite_palette_item(span<const color>(empty_hole_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::LZ77));
}

#endif

