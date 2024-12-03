#ifndef BS_CONSTANTS_H
#define BS_CONSTANTS_H

#include "bn_display.h"

namespace bs::constants
{
    const auto screen_half_width = bn::display::width() / 2;
    const auto screen_half_height = bn::display::height() / 2;
    const auto max_enemies = 5;
    const auto max_enemy_time_to_appear = 5000;
    const auto max_enemy_time_to_live = 5000;
}

#endif
