
#if( defined LIBEVENTS_H ) && !( defined LIBEVENTS_DISPATCHER_H )
#define LIBEVENTS_DISPATCHER_H

#include "../common/queue/public.h"
#include "../event/public.h"
#include "../listener/public.h"

/**
 * 
 */
typedef struct EventDispatcherOption_s EventDispatcherOption_t;

typedef struct EventDispatcher_s {
	struct {
		EventListener_t* start;
		int              count;
	} listeners;
	struct {
		void* first;
		int   count;
	} consumers;

	const Queue_t* eventQueue;

	const EventDispatcherOption_t _option
} EventDispatcher_t, *PEventDispatcher_t;

#define SELF const PEventDispatcher_t self

/**
 *
 */
PEventDispatcher_t EventDispatcher_factory( void );

/**
 *
 */
int EventDispatcher_destroyer( SELF );

/**
 *
 */
int EventDispatcher_handle( SELF, PEvent_t event );

#undef SELF
#endif