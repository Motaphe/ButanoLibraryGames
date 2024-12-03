#ifndef BS_RETICLE_H
#define BS_RETICLE_H

#include "bn_sprite_ptr.h"

namespace bs
{
    class reticle
    {
    public:
        reticle();
        
        void update();

    private:
        bn::sprite_ptr _sprite;

        bn::sprite_ptr draw();
        void movement();
        void wrap_around_screen();
    };
}
#endif
