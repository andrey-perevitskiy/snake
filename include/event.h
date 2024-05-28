#ifndef EVENT_H

#include <stdbool.h>

#define KEY_ESC 0x1b

bool event_check_exit (int key);
void event_lose ();
void event_win ();

#define EVENT_H
#endif
