
#ifndef UTIL_SECTIONS_H
#define UTIL_SECTIONS_H

#include "./levels.h"
#include "../macro.h"

#ifndef SECTION_LEVEL
//**
#define SECTION_LEVEL SECTION_LEVEL_Debug
#pragma message " SECTION_LEVEL has been set to level: " STRING( SECTION_LEVEL_Debug )
/**/
#endif

#define __protected_section( S ) ( 0, ( S ) )

/*
ERROR_SECTION
WARN_SECTION
INFO_SECTION
VERBOSE_SECTION
DEBUG_SECTION
SILLY_SECTION
*/

#if( SECTION_LEVEL >= SECTION_LEVEL_Error )
#define ERROR_SECTION( S ) __protected_section( S );
#else
#define ERROR_SECTION( S ) ( 0 );
#endif

#if( SECTION_LEVEL >= SECTION_LEVEL_Warn )
#define WARN_SECTION( S ) __protected_section( S );
#else
#define WARN_SECTION( S ) ( 0 );
#endif

#if( SECTION_LEVEL >= SECTION_LEVEL_Info )
#define INFO_SECTION( S ) __protected_section( S );
#else
#define INFO_SECTION( S ) ( 0 );
#endif

#if( SECTION_LEVEL >= SECTION_LEVEL_Verbose )
#define VERBOSE_SECTION( S ) __protected_section( S );
#else
#define VERBOSE_SECTION( S ) ( 0 );
#endif

#if( SECTION_LEVEL >= SECTION_LEVEL_Debug )
#define DEBUG_SECTION( S ) __protected_section( S );
#else
#define DEBUG_SECTION( S ) ( 0 );
#endif

#if( SECTION_LEVEL >= SECTION_LEVEL_Silly )
#define SILLY_SECTION( S ) __protected_section( S );
#else
#define SILLY_SECTION( S ) ( 0 );
#endif

#else
//**
#error "DEBUG costant is not defined"
/**/
#endif