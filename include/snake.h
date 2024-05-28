#ifndef SNAKE_H

#include <stdbool.h>
#include "snake-struct.h"
#include "food-struct.h"

struct snake * snake_init (void);
void snake_refresh_dir (struct snake * s, int key);
void snake_refresh_head (struct snake * s);
void snake_draw (struct snake * s);
void snake_move (struct snake * s);
void snake_erase_tail_end (struct snake * s);
bool snake_check_collide_self (struct snake * s);
bool snake_check_collide_board (struct snake * s);
void snake_check_collide_food (struct snake * s, struct food * f);
bool snake_check_max_length (struct snake * s);

#define SNAKE_H
#endif
