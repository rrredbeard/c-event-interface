#include <stdio.h>

typedef struct Arguments_s { int x, y, z; } Arguments_t, *PArguments_t;

int func( void* args ) {
	return ( ( PArguments_t )args )->z;
}

int getZ( Arguments_t args ) {
	return args.z;
}

#define _pt( T, S )                   \
	( {                               \
		T     __tmp__ = ( ( T )S );   \
		void* __pt__  = &( __tmp__ ); \
		__pt__;                       \
	} )

#define STRUCT_AS_VALUE \
	{ .x = 1, .y = 2, .z = 3 }

int main( void ) {

	printf( "Result: %d/%d\n", func( _pt( Arguments_t, STRUCT_AS_VALUE ) ),
	        getZ( ( Arguments_t )STRUCT_AS_VALUE ) );

	return 0;
}