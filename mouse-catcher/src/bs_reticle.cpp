#include "bs_reticle.h"
#include "bs_constants.h"
#include "vector2.h"

#include "bn_sprite_items_reticle_sprite.h"

#include "bn_math.h"
#include "bn_keypad.h"

namespace bs
{
    const bn::fixed kSpeed = 0.1;
    const bn::fixed kMaxSpeed = 1;
    const bn::fixed kDeceleration = 5;

    vector2 velocity;

    reticle::reticle() : _sprite(draw())
    {
    }

    void reticle::update()
    {
        movement();
    }

    bn::sprite_ptr reticle::draw()
    {
        auto reticle_ptr = bn::sprite_items::reticle_sprite.create_sprite(0, 0);
        reticle_ptr.set_z_order(-1);
        return reticle_ptr;
    }

    void reticle::movement()
    {
        vector2 direction;

        if (bn::keypad::right_held())
        {
            direction.x = 1;
        }
        else if (bn::keypad::left_held())
        {
            direction.x = -1;
        }

        if (bn::keypad::down_held())
        {
            direction.y = 1;
        }
        else if (bn::keypad::up_held())
        {
            direction.y = -1;
        }

        if (direction.x != 0)
        {
            auto max_velocity = kMaxSpeed * direction.normalised_vector().x();
            auto higher_velocity = velocity.x + kSpeed * direction.normalised_vector().x();
            velocity.x = abs(max_velocity) < abs(higher_velocity) ? max_velocity : higher_velocity;
        }
        else
        {
            auto lower_velocity = velocity.x / kDeceleration;
            velocity.x = abs(lower_velocity) > kSpeed ? lower_velocity : 0;
        }

        if (direction.y != 0)
        {
            auto max_velocity = kMaxSpeed * direction.normalised_vector().y();
            auto higher_velocity = velocity.y + kSpeed * direction.normalised_vector().y();
            velocity.y = abs(max_velocity) < abs(higher_velocity) ? max_velocity : higher_velocity;
        }
        else
        {
            auto lower_velocity = velocity.y / kDeceleration;
            velocity.y = abs(lower_velocity) > kSpeed ? lower_velocity : 0;
        }

        wrap_around_screen();

        _sprite.set_position(_sprite.x() + velocity.x, _sprite.y() + velocity.y);
    }

    void reticle::wrap_around_screen()
    {
        if (_sprite.x() < -constants::screen_half_width)
        {
            _sprite.set_x(constants::screen_half_width);
        }
        else if (_sprite.x() > constants::screen_half_width)
        {
            _sprite.set_x(-constants::screen_half_width);
        }

        if (_sprite.y() < -constants::screen_half_height)
        {
            _sprite.set_y(constants::screen_half_height);
        }
        else if (_sprite.y() > constants::screen_half_height)
        {
            _sprite.set_y(-constants::screen_half_height);
        }
    }
}