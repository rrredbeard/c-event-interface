#ifndef UTIL_MACRO_H
#define UTIL_MACRO_H

#include <stdlib.h>

#define __str__( x ) #x
#define STRING( x ) __str__( x )

#define START_MACRO() do {
#define $END_MACRO() \
	}                \
	while( 0 )

#define new_( T ) ( ( T* )malloc( sizeof( T ) ) )
#define new_zf( T ) ( ( T* )calloc( 1, sizeof( T ) ) )
#define newArray_( T, S ) ( ( T* )malloc( ( S ) * sizeof( T ) ) )
#define newArray_zf( T, S ) ( ( T* )calloc( ( S ), sizeof( T ) ) )

#endif /*UTIL_ERROR_H*/