#include "bs_enemy.h"

#include "bn_sprite_items_enemy_sprite.h"

#include "bn_log.h"

namespace bs
{
    enemy::enemy(bn::fixed_point position, int time_to_appear, int time_to_live) : _sprite(draw()),
                                                                                   _alive(true),
                                                                                   _visible(false)
    {
        _position = position;
        _time_to_appear = time_to_appear;
        _time_to_live = time_to_live;
        _sprite = draw();
    }

    bn::sprite_ptr enemy::draw()
    {
        return bn::sprite_items::enemy_sprite.create_sprite(_position);
    }

    void enemy::update()
    {
        _set_visible(_visible);
        BN_LOG("tta: ", _time_to_appear);

        if (_time_to_appear == 0)
        {
            _visible = true;
        }
        else
        {
            _time_to_appear--;
        }

        if (_time_to_live == 0)
        {
            _visible = false;
            _alive = false;
        }
        else if (_time_to_appear == 0)
        {
            _time_to_live--;
        }
    }

    bool enemy::is_alive()
    {
        return _alive;
    }

    bn::fixed_point enemy::get_position()
    {
        return _position;
    }

    void enemy::_set_visible(bool visible)
    {
        _sprite.set_visible(visible);
    }
}