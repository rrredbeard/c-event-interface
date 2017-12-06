#include <stdlib.h>
#define NOEVENT 0

typedef void* ( *EventHandler )( void* );

void* doNothing( void* p ) { /*do nothing absolutely*/
    return NULL;
}
typedef struct _event { EventHandler handler; } Event, *PEvent;

Event          AllEvents[ 1000 ];
unsigned short counter = 0;

void InitEvents() {
    LOCK( AllEvents );
    for( int i = 0; i < 1000; i++ ) {
        AllEvents[ i ].handler = doNothing;
    }
    UNLOCK( AllEvents );
}
void AddEvent( int EventType, EventHandler ev_handler ) {
    LOCK( AllEvents );
    AllEvents[ EventType ].handler = ev_handler;
    UNLOCK( AllEvents );
}

void RemoveEvent( int EventType, EventHandler ev_handler ) {
    LOCK( AllEvents );
    AllEvents[ EventType ] = doNothing;
    UNLOCK( AllEvents ); /*to safeguard the event loop*/
}

/*to be run in separate thread*/
void EventLoop() {
    int          event = NOEVENT;
    EventHandler handler;
    while( 1 ) {
        while( event == NOEVENT ) {
            event = GetEvents();
        }
        handler = AllEvents[ event ].handler;
        handler( NULL ); /*perform on an event*/
    }
}