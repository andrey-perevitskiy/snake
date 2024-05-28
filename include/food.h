#ifndef FOOD_H

#include "food-struct.h"
#include "snake-struct.h"

struct food * food_init (void);
void food_gen (struct food * f, struct snake * s);
void food_draw (struct food * f);

#define FOOD_H
#endif
