
#if( defined LIBEVENTS_H ) && ( defined LIBEVENTS_DISPATCHER_H )

#include "./public.h"

#define SELF const PEventDispatcher_t self

#ifndef LIBEVENTS_DISPATCHER_LISTENERS_H
#define LIBEVENTS_DISPATCHER_LISTENERS_H
/**/
/**
 *
 */
int EventDispatcher$listeners_init( SELF );

/**
 *
 */
int EventDispatcher$listeners_add( SELF, PEventListener_t listener );

/**
 *
 */
PEventListener_t EventDispatcher$listeners_get( SELF, char* name );

/**
 *
 */
int EventDispatcher$listeners_remove( SELF, char* name );

/**
 *
 */
int EventDispatcher$listeners_clear( SELF );
/**/
#endif

#ifndef LIBEVENTS_DISPATCHER_CONSUMERS_H
#define LIBEVENTS_DISPATCHER_CONSUMERS_H
/**/

/**
 *
 */
int EventDispatcher$consumers_init( SELF );

/**
 *
 */
int EventDispatcher$consumers_setOption( SELF, EventDispatcherOption_t opt );

/**
 *
 */
int EventDispatcher$consumers_start( SELF );

/**
 *
 */
int EventDispatcher$consumers_stop( SELF );

/**
 *
 */
int EventDispatcher$consumers_clear( SELF );

/**
 *
 */
int EventDispatcher$consumers_destroyer( SELF );

/**/
#endif

#ifndef LIBEVENTS_DISPATCHER_EVENTQUEUE_H
#define LIBEVENTS_DISPATCHER_EVENTQUEUE_H
/**/

/**
 *
 */
int EventDispatcher$eventQueue_init( SELF );

/**
 *
 */
int EventDispatcher$eventQueue_insert( SELF, PEvent_t event );

/**
 *
 */
PEvent_t EventDispatcher$eventQueue_fetch( SELF );

/**
 *
 */
int EventDispatcher$eventQueue_clear( SELF );

/**
 *
 */
int EventDispatcher$eventQueue_destroyer( SELF );

/**/
#endif

#undef SELF
#endif