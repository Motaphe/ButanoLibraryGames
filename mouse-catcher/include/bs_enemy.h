#ifndef BS_ENEMY_H
#define BS_ENEMY_H

#include "bn_sprite_ptr.h"
#include "bn_fixed_point.h"

namespace bs
{
    class enemy
    {
    public:
        enemy(bn::fixed_point position, int time_to_appear, int time_to_live);

        bn::sprite_ptr draw();
        void update();
        bool is_alive();
        bn::fixed_point get_position();

        bool operator==(const enemy &rhs)
        {
            return (
                rhs._alive == _alive &&
                rhs._position == _position &&
                rhs._sprite == _sprite &&
                rhs._time_to_appear == _time_to_appear &&
                rhs._time_to_live == _time_to_live &&
                rhs._visible == _visible);
        }

    private:
        bn::sprite_ptr _sprite;
        bn::fixed_point _position;
        int _time_to_appear;
        int _time_to_live;
        bool _alive;
        bool _visible;

        void _set_visible(bool visible);
    };
}

#endif