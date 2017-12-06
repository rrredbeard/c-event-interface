#ifndef UTIL_ERROR_H
#define UTIL_ERROR_H

#include "./macro.h"
#include "./sections/sections.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define PRINT_POSITION_ERROR()                                                \
	DEBUG_SECTION( {                                                          \
		fprintf( stderr, "function:'%s' at %d on %s", __FUNCTION__, __LINE__, \
		         __FILE__ );                                                  \
	} )

#define GENERIC_ERROR_HELPER( cond, errCode, msg )               \
	START_MACRO();                                               \
	if( cond ) {                                                 \
		fprintf( stderr, "%s: %s\n", msg, strerror( errCode ) ); \
		PRINT_POSITION_ERROR();                                  \
		exit( EXIT_FAILURE );                                    \
	}                                                            \
	END_MACRO()

////////////////////////

#define EXIT_IF_NULL( Pointer )                            \
	GENERIC_ERROR_HELPER( ( ( Pointer ) == NULL ), EFAULT, \
	                      "Null Pointer -> " STRING( Pointer ) )

#endif /*UTIL_ERROR_H*/
