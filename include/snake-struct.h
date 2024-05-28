#ifndef SNAKE_STRUCT_H

#include "unit.h"

struct snake {
    struct unit * u;
    int len;
    int score;
};

#define SNAKE_STRUCT_H
#endif
