#if defined( __GNUC__ ) || defined( __GNUG__ )

// Anonymous function
#define lambda( return_type, function_body ) \
	( {                                      \
		return_type __fn__ function_body;    \
		__fn__;                              \
	} )

// Get pointer from stack element   #lazyPeople
#define pointer( T, S )               \
	( {                               \
		T     __tmp__ = ( ( T )S );   \
		void* __pt__  = &( __tmp__ ); \
		__pt__;                       \
	} )
#define PT( T, S ) pointer( T, S )

// Rename the functions to use the
// structure syntax for the passage
// of parameters
// NB: it support max 5 arguments
//
// source: https://blog.noctua-software.com/named-parameters-in-c.html
#define FE_0( a, a0, X ) a0( 0, X )
#define FE_1( a, a0, X, ... ) a( 1, X ) FE_0( a, a0, __VA_ARGS__ )
#define FE_2( a, a0, X, ... ) a( 2, X ) FE_1( a, a0, __VA_ARGS__ )
#define FE_3( a, a0, X, ... ) a( 3, X ) FE_2( a, a0, __VA_ARGS__ )
#define FE_4( a, a0, X, ... ) a( 4, X ) FE_3( a, a0, __VA_ARGS__ )
#define GET_MACRO( _0, _1, _2, _3, _4, NAME, ... ) NAME
#define FOR_EACH( a, a0, ... )                             \
	GET_MACRO( __VA_ARGS__, FE_4, FE_3, FE_2, FE_1, FE_0 ) \
	( a, a0, __VA_ARGS__ )

#define ARGS_STRUCT_ATTR( n, attr ) \
	union {                         \
		attr, _##n;                 \
	};

#define ARGS_STRUCT( ... )                                          \
	struct {                                                        \
		FOR_EACH( ARGS_STRUCT_ATTR, ARGS_STRUCT_ATTR, __VA_ARGS__ ) \
	}

#define ARGS_PASS( n, attr ) _args._##n,
#define ARGS_PASS0( n, attr ) _args._##n
#define PASS_STRUCT( ... ) FOR_EACH( ARGS_PASS, ARGS_PASS0, __VA_ARGS__ )

/** i've modified a little bit the following macro
 * to add the initial zero-filled parameters
 * so you can avoid writing all of it
 *
 * renamedFunc(.x=1, .y=0, .z=3) => renamedFunc(.x=1, .z=3)
 */
#define CALL_NAMED_ARGS( func, args, ... )                      \
	( {                                                         \
		ARGS_STRUCT args _pre = { __VA_ARGS__ }, _args = { 0 }; \
		_args = _pre;                                           \
		func( PASS_STRUCT args );                               \
	} )

#else
#error "Compile this source with 'gcc' or 'g++'"
#endif