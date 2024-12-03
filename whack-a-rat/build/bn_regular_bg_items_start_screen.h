#ifndef BN_REGULAR_BG_ITEMS_START_SCREEN_H
#define BN_REGULAR_BG_ITEMS_START_SCREEN_H

#include "bn_regular_bg_item.h"

//{{BLOCK(start_screen_bn_gfx)

//======================================================================
//
//	start_screen_bn_gfx, 256x256@8, 
//	+ palette 74 entries, lz77 compressed
//	+ 1023 tiles (t|f reduced) lz77 compressed
//	+ regular map (flat), lz77 compressed, 32x32 
//	Total size: 148 + 31772 + 2304 = 34224
//
//	Time-stamp: 2024-12-03, 07:27:15
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_START_SCREEN_BN_GFX_H
#define GRIT_START_SCREEN_BN_GFX_H

#define start_screen_bn_gfxTilesLen 31772
extern const bn::tile start_screen_bn_gfxTiles[2046];

#define start_screen_bn_gfxMapLen 2304
extern const bn::regular_bg_map_cell start_screen_bn_gfxMap[1152];

#define start_screen_bn_gfxPalLen 148
extern const bn::color start_screen_bn_gfxPal[64];

#endif // GRIT_START_SCREEN_BN_GFX_H

//}}BLOCK(start_screen_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item start_screen(
            regular_bg_tiles_item(span<const tile>(start_screen_bn_gfxTiles, 2046), bpp_mode::BPP_8, compression_type::LZ77), 
            bg_palette_item(span<const color>(start_screen_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::LZ77),
            regular_bg_map_item(start_screen_bn_gfxMap[0], size(32, 32), compression_type::LZ77, 1, false));
}

#endif

