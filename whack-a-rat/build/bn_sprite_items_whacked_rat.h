#ifndef BN_SPRITE_ITEMS_WHACKED_RAT_H
#define BN_SPRITE_ITEMS_WHACKED_RAT_H

#include "bn_sprite_item.h"

//{{BLOCK(whacked_rat_bn_gfx)

//======================================================================
//
//	whacked_rat_bn_gfx, 32x32@4, 
//	+ palette 20 entries, lz77 compressed
//	+ 16 tiles lz77 compressed
//	Total size: 40 + 340 = 380
//
//	Time-stamp: 2024-12-03, 07:27:15
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_WHACKED_RAT_BN_GFX_H
#define GRIT_WHACKED_RAT_BN_GFX_H

#define whacked_rat_bn_gfxTilesLen 340
extern const bn::tile whacked_rat_bn_gfxTiles[16];

#define whacked_rat_bn_gfxPalLen 40
extern const bn::color whacked_rat_bn_gfxPal[16];

#endif // GRIT_WHACKED_RAT_BN_GFX_H

//}}BLOCK(whacked_rat_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item whacked_rat(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(whacked_rat_bn_gfxTiles, 16), bpp_mode::BPP_4, compression_type::LZ77, 1), 
            sprite_palette_item(span<const color>(whacked_rat_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::LZ77));
}

#endif

