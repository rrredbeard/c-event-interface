
#if( defined LIBEVENTS_H ) && !( defined LIBEVENTS_EVENT_H )
#define LIBEVENTS_EVENT_H

#include "../dispatcher/public.h"
#include "../listener/public.h"

typedef enum EventState_e { ESRunning, ESWaiting, ESExited } EventState;

typedef struct Event_s {
	const void* handlerArgs;
	const int   listenerID;
	EventState  state;
} Event_t, *PEvent_t;

#define SELF const PEvent_t self

/**
 *
 */
PEvent_t Event_factory( const int listenerID );

/**
 *
*/
int Event_emit( SELF, PEventDispatcher_t dispatcher, void* args );

/**
 *
 */
int Event_destroyer( SELF );

#undef SELF
#endif
