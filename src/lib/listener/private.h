#include "./public.h"

#if( defined LIBEVENTS_H ) && ( defined LIBEVENTS_LISTENER_H )

#define SELF const PEventListener_t self

#ifndef LIBEVENTS_LISTENER_HANDLERS_H
#define LIBEVENTS_LISTENER_HANDLERS_H
/**/
/**
 *
 */
int EventListener$handlers_init( SELF );

/**
 *
 */
int EventListener$handlers_add( SELF, EventHandler_t handler );

/**
 *
 */
EventHandler_t EventListener$handlers_get( SELF, int index );

/**
 *
 */
EventHandler_t EventListener$handlers_remove( SELF, int index );

/**
 *
 */
int EventListener$handlers_clear( SELF );
/**/
#endif

#undef SELF
#endif