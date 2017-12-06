# 1 "src/lib/libevents.h"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 330 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "src/lib/libevents.h" 2

# 1 "src/lib/./dispatcher/public.h" 1

# 1 "src/lib/./dispatcher/../common/queue/public.h" 1

typedef struct QueueNode_s QueueNode_t;
typedef struct QueueNode_s {
	QueueNode_t* next;
	void*        value;
};

typedef struct Queue_s {
	QueueNode_t* head;
	QueueNode_t* tail;
	int          count;
} Queue_t;

typedef struct QueueInterface_s {
	const Queue_t* ( *factory )( void );
	const int ( *destroy )( Queue_t* );

	const QueueNode_t* ( *peek )( Queue_t* );
	const int ( *add )( Queue_t*, QueueNode_t* );
	const QueueNode_t* ( *poll )( Queue_t* );

	struct QueueNodeInterface_s {
		const QueueNode_t* ( *factory )( void );
		const int ( *destroy )( QueueNode_t* );
	} Node;
} QueueInterface_t;
# 6 "src/lib/./dispatcher/public.h" 2
# 1 "src/lib/./dispatcher/../event/public.h" 1

# 1 "src/lib/./dispatcher/../event/../dispatcher/public.h" 1
# 6 "src/lib/./dispatcher/../event/public.h" 2
# 1 "src/lib/./dispatcher/../event/../listener/public.h" 1

# 1 "src/lib/./dispatcher/../event/../listener/../common/handler/public.h" 1

typedef enum EventResult_e {
	ERNull        = ( int )-1,
	ERSuccess     = ( int )0,
	ERFailure     = ( int )1,
	ERRecalculate = ( int )2
} EventResult_t;

typedef EventResult_t ( *EventHandler_t )( void* );
# 6 "src/lib/./dispatcher/../event/../listener/public.h" 2

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

int EventListener_factory( char* name, const PEventDispatcher_t dispatcher );

int EventListener_on( const PEventListener_t self, EventHandler_t newHandler );

int EventListener_off( const PEventListener_t self, EventHandler_t handler );

int EventListener_clear( const PEventListener_t self );

int EventListener_destroy( const PEventListener_t self );
# 7 "src/lib/./dispatcher/../event/public.h" 2

typedef enum EventState_e { ESRunning, ESWaiting, ESExited } EventState;

typedef struct Event_s {
	const void* handlerArgs;
	const int   listenerID;
	EventState  state;
} Event_t, *PEvent_t;

PEvent_t Event_factory( const int listenerID );

int Event_emit( const PEvent_t self, PEventDispatcher_t dispatcher,
                void* args );

int Event_destroyer( const PEvent_t self );
# 7 "src/lib/./dispatcher/../event/../dispatcher/public.h" 2
# 1 "src/lib/./dispatcher/../listener/public.h" 1
# 8 "src/lib/./dispatcher/../event/../dispatcher/public.h" 2

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

PEventDispatcher_t EventDispatcher_factory( void );

int EventDispatcher_destroyer( const PEventDispatcher_t self );

int EventDispatcher_handle( const PEventDispatcher_t self, PEvent_t event );
# 5 "src/lib/libevents.h" 2
# 1 "src/lib/./event/public.h" 1
# 6 "src/lib/libevents.h" 2
# 1 "src/lib/./listener/public.h" 1
# 7 "src/lib/libevents.h" 2
