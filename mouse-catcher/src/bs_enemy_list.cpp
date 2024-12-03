#include "bs_enemy_list.h"

#include "bn_random.h"

namespace bs
{
    bn::random random_number;

    enemy_list::enemy_list()
    {
    }

    void enemy_list::update()
    {
        if (!_enemy_list.full())
        {
            auto random_x = random_number.get_int(constants::screen_half_width * 2) - constants::screen_half_width;
            auto random_y = random_number.get_int(constants::screen_half_height * 2) - constants::screen_half_height;
            auto random_tta = random_number.get_int(constants::max_enemy_time_to_appear);
            auto random_ttl = random_number.get_int(constants::max_enemy_time_to_live);

            bs::enemy enemy = bs::enemy(bn::fixed_point(random_x, random_y), random_tta, random_ttl);
            _enemy_list.emplace_back(enemy);
        }

        for (int i = 0; i < _enemy_list.size(); i++)
        {
            _enemy_list[i].update();

            if (!_enemy_list[i].is_alive())
            {
                _enemy_list.erase(_enemy_list.begin() + i);
            }
        }
    }
}