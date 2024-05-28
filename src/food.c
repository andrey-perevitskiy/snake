#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ncurses.h>
#include "food.h"
#include "board.h"
#include "snake-const.h"

static const char food_sym [] = {
    '$', '*', '%', '&'
};
static const int food_color [] = {
    2, 3, 4, 5, 6, 7
};
static const int food_score [] = {
    5, 10, 25, 100, 250, 500, 1000
};

static int
rnd (int min, int max)
{
    return min + rand() % (max + 1 - min);
}

struct food *
food_init (void)
{
    return malloc(sizeof(struct food));
}

void
food_gen (struct food * f, struct snake * s)
{
    int is_done, i;

    srand(time(NULL));
    do {
        f->x = rnd(BOARD_LEFT + 1, BOARD_RIGHT - 1);
        f->y = rnd(BOARD_TOP + 1, BOARD_BOTTOM - 1);

        is_done = true;
        for (i = 0; i < SNAKE_MAX_LENGTH; i++)
            if (f->x == s->u[i].x && f->y == s->u[i].y)
                is_done = false;
    }
    while (!is_done);

    f->sym = food_sym[rnd(0, 3)];
    f->color = food_color[rnd(0, 5)];
    f->score = food_score[rnd(0, 6)];
}

void
food_draw (struct food * f)
{
    attron(COLOR_PAIR(f->color));
    mvaddch(f->y, f->x, f->sym);
    attroff(COLOR_PAIR(f->color));
}
