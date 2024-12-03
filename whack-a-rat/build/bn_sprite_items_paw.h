#ifndef BN_SPRITE_ITEMS_PAW_H
#define BN_SPRITE_ITEMS_PAW_H

#include "bn_sprite_item.h"

//{{BLOCK(paw_bn_gfx)

//======================================================================
//
//	paw_bn_gfx, 32x32@4, 
//	+ palette 20 entries, lz77 compressed
//	+ 16 tiles lz77 compressed
//	Total size: 40 + 376 = 416
//
//	Time-stamp: 2024-12-03, 07:27:15
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PAW_BN_GFX_H
#define GRIT_PAW_BN_GFX_H

#define paw_bn_gfxTilesLen 376
extern const bn::tile paw_bn_gfxTiles[16];

#define paw_bn_gfxPalLen 40
extern const bn::color paw_bn_gfxPal[16];

#endif // GRIT_PAW_BN_GFX_H

//}}BLOCK(paw_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item paw(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(paw_bn_gfxTiles, 16), bpp_mode::BPP_4, compression_type::LZ77, 1), 
            sprite_palette_item(span<const color>(paw_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::LZ77));
}

#endif

