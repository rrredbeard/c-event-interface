#include <stdio.h>

//#include "../src/util/sections/levels.h"
//#define SECTION_LEVEL SECTION_LEVEL_Info

#define DEBUG
#include "../src/util/sections/sections.h"

int main( void ) {

    printf( "\nStart:\n" );
    ERROR_SECTION( { printf( "ErrorSection\n" ); } );
    WARN_SECTION( { printf( "WarnSection\n" ); } );
    INFO_SECTION( { printf( "InfoSection\n" ); } );
    VERBOSE_SECTION( { printf( "VerboseSection\n" ); } );
    DEBUG_SECTION( { printf( "DebugSection\n" ); } );
    SILLY_SECTION( { printf( "SillySection\n" ); } );

    return 0;
}