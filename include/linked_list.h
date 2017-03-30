#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

typedef struct _linked_list* linked_list;

#define linked_list_add(X, Y) _Generic((Y), \
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

#define linked_list_add_at(X, Y, Z) _Generic((Y), \
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
	)(X, Y, Z)

linked_list new_linked_list();
void linked_list_destroy(linked_list list);

void linked_list_add_generic(linked_list list, void *data, size_t size);
void linked_list_add_char(linked_list list, char data);
void linked_list_add_uchar(linked_list list, unsigned char data);
void linked_list_add_short(linked_list list, short data);
void linked_list_add_ushort(linked_list list, unsigned short data);
void linked_list_add_int(linked_list list, int data);
void linked_list_add_uint(linked_list list, unsigned int data);
void linked_list_add_long(linked_list list, long data);
void linked_list_add_ulong(linked_list list, unsigned long data);
void linked_list_add_long_long(linked_list list, long long data);
void linked_list_add_ulong_long(linked_list list, unsigned long long data);
void linked_list_add_float(linked_list list, float data);
void linked_list_add_double(linked_list list, double data);
void linked_list_add_long_double(linked_list list, long double data);
void linked_list_add_string(linked_list list, char *data);

void linked_list_add_generic_at(linked_list list, void *data, size_t size, size_t index);
void linked_list_add_char_at(linked_list list, char data, size_t index);
void linked_list_add_uchar_at(linked_list list, unsigned char data, size_t index);
void linked_list_add_short_at(linked_list list, short data, size_t index);
void linked_list_add_ushort_at(linked_list list, unsigned short data, size_t index);
void linked_list_add_int_at(linked_list list, int data, size_t index);
void linked_list_add_uint_at(linked_list list, unsigned int data, size_t index);
void linked_list_add_long_at(linked_list list, long data, size_t index);
void linked_list_add_ulong_at(linked_list list, unsigned long data, size_t index);
void linked_list_add_long_long_at(linked_list list, long long data, size_t index);
void linked_list_add_ulong_long_at(linked_list list, unsigned long long data, size_t index);
void linked_list_add_float_at(linked_list list, float data, size_t index);
void linked_list_add_double_at(linked_list list, double data, size_t index);
void linked_list_add_long_double_at(linked_list list, long double data, size_t index);
void linked_list_add_string_at(linked_list list, char *data, size_t index);

void* linked_list_get(linked_list list, size_t index);
char linked_list_get_char(linked_list list, size_t index);
unsigned char linked_list_get_uchar(linked_list list, size_t index);
short linked_list_get_short(linked_list list, size_t index);
unsigned short linked_list_get_ushort(linked_list list, size_t index);
int linked_list_get_int(linked_list list, size_t index);
unsigned int linked_list_get_uint(linked_list list, size_t index);
long linked_list_get_long(linked_list list, size_t index);
unsigned long linked_list_get_ulong(linked_list list, size_t index);
long long linked_list_get_long_long(linked_list list, size_t index);
unsigned long long linked_list_get_ulong_long(linked_list list, size_t index);
float linked_list_get_float(linked_list list, size_t index);
double linked_list_get_double(linked_list list, size_t index);
long double linked_list_get_long_double(linked_list list, size_t index);
char* linked_list_get_string(linked_list list, size_t index);

void* linked_list_remove(linked_list list, size_t index);
char linked_list_remove_char(linked_list list, size_t index);
unsigned char linked_list_remove_uchar(linked_list list, size_t index);
short linked_list_remove_short(linked_list list, size_t index);
unsigned short linked_list_remove_ushort(linked_list list, size_t index);
int linked_list_remove_int(linked_list list, size_t index);
unsigned int linked_list_remove_uint(linked_list list, size_t index);
long linked_list_remove_long(linked_list list, size_t index);
unsigned long linked_list_remove_ulong(linked_list list, size_t index);
long long linked_list_remove_long_long(linked_list list, size_t index);
unsigned long long linked_list_remove_ulong_long(linked_list list, size_t index);
float linked_list_remove_float(linked_list list, size_t index);
double linked_list_remove_double(linked_list list, size_t index);
long double linked_list_remove_long_double(linked_list list, size_t index);
char* linked_list_remove_string(linked_list list, size_t index);

size_t linked_list_length(linked_list list);