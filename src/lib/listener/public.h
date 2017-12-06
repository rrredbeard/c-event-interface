
#if( defined LIBEVENTS_H ) && !( defined LIBEVENTS_LISTENER_H )
#define LIBEVENTS_LISTENER_H

#include "../common/handler/public.h"

typedef struct EventHandlerNode_s EventHandlerNode_t;
typedef struct EventHandlerNode_s {
	EventHandlerNode_t* next;
	EventHandler_t      value;
};

typedef struct EventListener {
	const int   ID;
	const char* name;
	struct EventHandlerQueue {
		EventHandlerNode_t* first;
		EventHandlerNode_t* last;
		unsigned            count;
	} handlers;
} EventListener_t, *PEventListener_t;

#define SELF const PEventListener_t self

/**
 *
 */
int EventListener_factory( char* name, const PEventDispatcher_t dispatcher );

/**
 *
 */
int EventListener_on( SELF, EventHandler_t newHandler );

/**
 *
 */
int EventListener_off( SELF, EventHandler_t handler );

/**
 *
 */
int EventListener_clear( SELF );

/**
 *
 */
int EventListener_destroy( SELF );

#undef SELF
#endif
