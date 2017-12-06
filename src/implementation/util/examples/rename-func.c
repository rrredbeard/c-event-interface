#include "../src/implementation/util/gnu-high-level-syntax.h"
#include <stdio.h>

int func( int x, int y ) {
	int ret = x + y;
	printf( "%s(%d, %d) -> %d\n", __PRETTY_FUNCTION__, x, y, ret );
	return ret;
}

// func2 will call `func` using named arguments.
#define func2( ... ) CALL_NAMED_ARGS( func, ( int x, int y ), __VA_ARGS__ )

int main( void ) {
	int ret[ 4 ] = { 0 };
	ret[ 0 ] = func2(.y = 5, .x = 20 );
	ret[ 1 ] = func2(.x = 10 );
	ret[ 2 ] = func2(.y = 10 );
	ret[ 3 ]            = func2();

	return 0;
}
