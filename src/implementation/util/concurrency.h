#ifndef UTIL_CONCURRENCY_H
#define UTIL_CONCURRENCY_H

#include "./sections/sections.h"
#include "./error.h"
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

#define PTHREAD_ERROR( R, M ) \
	GENERIC_ERROR_HELPER( ( ( R ) != 0 ), ( R ), "Pthread: " M )

#define SECTION_REQUIRE( mutex, S )                                          \
	START_MACRO();                                                           \
	EXIT_IF_NULL( mutex );                                                   \
	PTHREAD_ERROR( pthread_mutex_lock( mutex ), "on locking '" #mutex "'" ); \
	/*****************************************/                              \
	__protected_section( S ); /* do stuff ****/                              \
	/*****************************************/                              \
	PTHREAD_ERROR( pthread_mutex_unlock( mutex ),                            \
	               "on unlocking '" #mutex "'" );                            \
	END_MACRO()

#endif /*UTIL_CONCURRENCY_H*/