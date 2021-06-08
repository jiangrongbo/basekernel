#ifndef EVENT_H
#define EVENT_H

#include <kernel/types.h>

struct event {
	uint16_t type;
	uint16_t code;
	int16_t  x;
	int16_t  y;
};

#define EVENT_CLOSE          (1<<0)
#define EVENT_MOUSE_MOVE     (1<<1)
#define EVENT_BUTTON_UP      (1<<2)
#define EVENT_BUTTON_DOWN    (1<<3)
#define EVENT_KEY_UP         (1<<4)
#define EVENT_KEY_DOWN       (1<<5)
#define EVENT_RESIZE         (1<<6)
#define EVENT_REVEAL         (1<<7)
#define EVENT_HIDE           (1<<8)

void event_post( uint16_t type, uint16_t code, int16_t x, int16_t y );
int  event_read( struct event *e, int size );
int  event_read_nonblock( struct event *e, int size );
int event_read_keyboard();

void event_init();

#endif
