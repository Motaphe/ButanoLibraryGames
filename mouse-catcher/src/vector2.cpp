#include "vector2.h"

#include "bn_fixed_point.h"
#include "bn_math.h"

bn::fixed_point vector2::normalised_vector()
{
    bn::fixed magnitude = bn::sqrt((x * x) + (y * y));
    return magnitude != 0 ? bn::fixed_point(x, y) / magnitude : bn::fixed_point(x, y);
}