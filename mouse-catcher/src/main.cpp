#include "bs_reticle.h"
#include "bs_enemy_list.h"

#include "bn_regular_bg_items_background.h"

#include "bn_core.h"
#include "bn_regular_bg_ptr.h"

int main()
{
    bn::core::init();
    bn::regular_bg_ptr background = bn::regular_bg_items::background.create_bg(0, 0);
    bs::reticle reticle = bs::reticle();
    bs::enemy_list enemy_list = bs::enemy_list();

    while (true)
    {
        reticle.update();
        enemy_list.update();
        bn::core::update();
    }
}