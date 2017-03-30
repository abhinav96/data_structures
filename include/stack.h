#include "linked_list.h"

typedef linked_list stack;

#define stack_push(X, Y) _Generic((Y), \
	char*: linked_list_add_string_at, \
	char: linked_list_add_char_at, \
	unsigned char: linked_list_add_uchar_at, \
	short: linked_list_add_short_at, \
	unsigned short: linked_list_add_ushort_at, \
	int: linked_list_add_int_at, \
	unsigned int: linked_list_add_uint_at, \
	long: linked_list_add_long_at, \
	unsigned long: linked_list_add_ulong_at, \
	long long: linked_list_add_long_long_at, \
	unsigned long long: linked_list_add_ulong_long_at, \
	float: linked_list_add_float_at, \
	double: linked_list_add_double_at, \
	long double: linked_list_add_long_double_at \
	)(X, Y, 0)

#define new_stack() new_linked_list()
#define stack_destroy(A) linked_list_destroy(A)

#define stack_push_generic(A, B, C) linked_list_add_generic_at(A, B, C, 0)

#define stack_pop(A) linked_list_remove(A, 0)
#define stack_pop_char(A) linked_list_remove_char(A, 0)
#define stack_pop_uchar(A) linked_list_remove_uchar(A, 0)
#define stack_pop_short(A) linked_list_remove_short(A, 0)
#define stack_pop_ushort(A) linked_list_remove_ushort(A, 0)
#define stack_pop_int(A) linked_list_remove_int(A, 0)
#define stack_pop_uint(A) linked_list_remove_uint(A, 0)
#define stack_pop_long(A) linked_list_remove_long(A, 0)
#define stack_pop_ulong(A) linked_list_remove_ulong(A, 0)
#define stack_pop_long_long(A) linked_list_remove_long_long(A, 0)
#define stack_pop_ulong_long(A) linked_list_remove_ulong_long(A, 0)
#define stack_pop_float(A) linked_list_remove_float(A, 0)
#define stack_pop_double(A) linked_list_remove_double(A, 0)
#define stack_pop_long_double(A) linked_list_remove_long_double(A, 0)
#define stack_pop_string(A) linked_list_remove_string(A, 0)

#define stack_peek(A) linked_list_get(A, 0)
#define stack_peek_char(A) linked_list_get_char(A, 0)
#define stack_peek_uchar(A) linked_list_get_uchar(A, 0)
#define stack_peek_short(A) linked_list_get_short(A, 0)
#define stack_peek_ushort(A) linked_list_get_ushort(A, 0)
#define stack_peek_int(A) linked_list_get_int(A, 0)
#define stack_peek_uint(A) linked_list_get_uint(A, 0)
#define stack_peek_long(A) linked_list_get_long(A, 0)
#define stack_peek_ulong(A) linked_list_get_ulong(A, 0)
#define stack_peek_long_long(A) linked_list_get_long_long(A, 0)
#define stack_peek_ulong_long(A) linked_list_get_ulong_long(A, 0)
#define stack_peek_float(A) linked_list_get_float(A, 0)
#define stack_peek_double(A) linked_list_get_double(A, 0)
#define stack_peek_long_double(A) linked_list_get_long_double(A, 0)
#define stack_peek_string(A) linked_list_get_string(A, 0)

#define stack_size(A) linked_list_length(A)

#define stack_is_empty(A) (bool)!linked_list_length(A)