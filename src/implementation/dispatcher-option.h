
#if( defined LIBEVENTS_H ) && ( defined LIBEVENTS_DISPATCHER_H ) \
    && !( defined LIBEVENTS_DISPATCHER_OPTION_H )
#define LIBEVENTS_DISPATCHER_OPTION_H

#include <unistd.h>

typedef struct EventDispatcherOption_s { unsigned short thread_no; };
#define EVENT_DISPATCHER_OPT_THREAD_MAX ( sysconf( _SC_NPROCESSORS_ONLN ) * 2 )
#define EVENT_DISPATCHER_OPT_THREAD_MIN 1

#endif
