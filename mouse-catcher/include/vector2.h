#ifndef VECTOR2_H
#define VECTOR2_H

#include "bn_fixed.h"
#include "bn_fixed_point.h"

struct vector2
{
  bn::fixed x;
  bn::fixed y;

  bn::fixed_point normalised_vector();
};

#endif