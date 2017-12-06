#if( defined LIBEVENTS_H ) && !( defined LIBEVENTS_COMMON_HANDLER_H )
#define LIBEVENTS_COMMON_HANDLER_H

// EventResult
typedef enum EventResult_e {
	ERNull        = ( int )-1,
	ERSuccess     = ( int )0,
	ERFailure     = ( int )1,
	ERRecalculate = ( int )2
} EventResult_t;

#define toEventResult( N ) \
	( ( EventResult_t )( ( N >= 0 && N < 3 ) ? ( N ) : ( ERNull ) ) )

// EventHandler
typedef EventResult_t ( *EventHandler_t )( void* );

#endif