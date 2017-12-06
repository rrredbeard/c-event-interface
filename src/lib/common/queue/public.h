#if( defined LIBEVENTS_H ) && !( defined LIBEVENTS_COMMON_QUEUE_H )
#define LIBEVENTS_COMMON_QUEUE_H

// Generic Queue structure
typedef struct QueueNode_s QueueNode_t;
typedef struct QueueNode_s {
	QueueNode_t* next;
	void*        value;
};

typedef struct Queue_s {
	QueueNode_t* head;
	QueueNode_t* tail;
	int          count;
} Queue_t;

typedef struct QueueInterface_s {
	const Queue_t* ( *factory )( void );
	const int ( *destroy )( Queue_t* );
	/************/
	const QueueNode_t* ( *peek )( Queue_t* );
	const int ( *add )( Queue_t*, QueueNode_t* );
	const QueueNode_t* ( *poll )( Queue_t* );
	/***********************************************/
	struct QueueNodeInterface_s {
		const QueueNode_t* ( *factory )( void );
		const int ( *destroy )( QueueNode_t* );
	} Node;
} QueueInterface_t;

#endif