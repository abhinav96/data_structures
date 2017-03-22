#include "linked_list.h"

typedef linked_list queue;

#define queue_enqueue(X, Y) _Generic((Y), \
	char*: linked_list_add_string, \
	char: linked_list_add_char, \
	unsigned char: linked_list_add_uchar, \
	short: linked_list_add_short, \
	unsigned short: linked_list_add_ushort, \
	int: linked_list_add_int, \
	unsigned int: linked_list_add_uint, \
	long: linked_list_add_long, \
	unsigned long: linked_list_add_ulong, \
	long long: linked_list_add_long_long, \
	unsigned long long: linked_list_add_ulong_long, \
	float: linked_list_add_float, \
	double: linked_list_add_double, \
	long double: linked_list_add_long_double \
	)(X, Y)

#define new_queue() new_linked_list()

#define queue_enqueue_generic(A, B, C) linked_list_add_generic(A, B, C)

#define queue_dequeue(A) linked_list_remove(A, 0)
#define queue_dequeue_char(A) linked_list_remove_char(A, 0)
#define queue_dequeue_uchar(A) linked_list_remove_uchar(A, 0)
#define queue_dequeue_short(A) linked_list_remove_short(A, 0)
#define queue_dequeue_ushort(A) linked_list_remove_ushort(A, 0)
#define queue_dequeue_int(A) linked_list_remove_int(A, 0)
#define queue_dequeue_uint(A) linked_list_remove_uint(A, 0)
#define queue_dequeue_long(A) linked_list_remove_long(A, 0)
#define queue_dequeue_ulong(A) linked_list_remove_ulong(A, 0)
#define queue_dequeue_long_long(A) linked_list_remove_long_long(A, 0)
#define queue_dequeue_ulong_long(A) linked_list_remove_ulong_long(A, 0)
#define queue_dequeue_float(A) linked_list_remove_float(A, 0)
#define queue_dequeue_double(A) linked_list_remove_double(A, 0)
#define queue_dequeue_long_double(A) linked_list_remove_long_double(A, 0)
#define queue_dequeue_string(A) linked_list_remove_string(A, 0)

#define queue_peek(A) linked_list_get(A, 0)
#define queue_peek_char(A) linked_list_get_char(A, 0)
#define queue_peek_uchar(A) linked_list_get_uchar(A, 0)
#define queue_peek_short(A) linked_list_get_short(A, 0)
#define queue_peek_ushort(A) linked_list_get_ushort(A, 0)
#define queue_peek_int(A) linked_list_get_int(A, 0)
#define queue_peek_uint(A) linked_list_get_uint(A, 0)
#define queue_peek_long(A) linked_list_get_long(A, 0)
#define queue_peek_ulong(A) linked_list_get_ulong(A, 0)
#define queue_peek_long_long(A) linked_list_get_long_long(A, 0)
#define queue_peek_ulong_long(A) linked_list_get_ulong_long(A, 0)
#define queue_peek_float(A) linked_list_get_float(A, 0)
#define queue_peek_double(A) linked_list_get_double(A, 0)
#define queue_peek_long_double(A) linked_list_get_long_double(A, 0)
#define queue_peek_string(A) linked_list_get_string(A, 0)

#define queue_length(A) linked_list_length(A)

#define queue_is_empty(A) (bool)!linked_list_length(A)