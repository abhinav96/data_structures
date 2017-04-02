#include "linked_list.h"

typedef struct _hash_table* hash_table;

#define hash_table_set(X, Y, Z) _Generic((Z), \
	char*: hash_table_set_string, \
	char: hash_table_set_char, \
	unsigned char: hash_table_set_uchar, \
	short: hash_table_set_short, \
	unsigned short: hash_table_set_ushort, \
	int: hash_table_set_int, \
	unsigned int: hash_table_set_uint, \
	long: hash_table_set_long, \
	unsigned long: hash_table_set_ulong, \
	long long: hash_table_set_long_long, \
	unsigned long long: hash_table_set_ulong_long, \
	float: hash_table_set_float, \
	double: hash_table_set_double, \
	long double: hash_table_set_long_double, \
	const char*: hash_table_set_string, \
	const char: hash_table_set_char, \
	const unsigned char: hash_table_set_uchar, \
	const short: hash_table_set_short, \
	const unsigned short: hash_table_set_ushort, \
	const int: hash_table_set_int, \
	const unsigned int: hash_table_set_uint, \
	const long: hash_table_set_long, \
	const unsigned long: hash_table_set_ulong, \
	const long long: hash_table_set_long_long, \
	const unsigned long long: hash_table_set_ulong_long, \
	const float: hash_table_set_float, \
	const double: hash_table_set_double, \
	const long double: hash_table_set_long_double \
	)(X, Y, Z)

hash_table new_hash_table(size_t no_of_buckets);
void hash_table_destroy(hash_table ht);

void hash_table_set_generic(hash_table ht, const char *key, const void *value, size_t size);
void hash_table_set_char(hash_table ht, const char *key, const char value);
void hash_table_set_uchar(hash_table ht, const char *key, const unsigned char value);
void hash_table_set_short(hash_table ht, const char *key, const short value);
void hash_table_set_ushort(hash_table ht, const char *key, const unsigned short value);
void hash_table_set_int(hash_table ht, const char *key, const int value);
void hash_table_set_uint(hash_table ht, const char *key, const unsigned int value);
void hash_table_set_long(hash_table ht, const char *key, const long value);
void hash_table_set_ulong(hash_table ht, const char *key, const unsigned long value);
void hash_table_set_long_long(hash_table ht, const char *key, const long long value);
void hash_table_set_ulong_long(hash_table ht, const char *key, const unsigned long long value);
void hash_table_set_float(hash_table ht, const char *key, const float value);
void hash_table_set_double(hash_table ht, const char *key, const double value);
void hash_table_set_long_double(hash_table ht, const char *key, const long double value);
void hash_table_set_string(hash_table ht, const char *key, const char *value);

bool hash_table_is_set(hash_table ht, const char *key);

void* hash_table_get(hash_table ht, const char *key);
char hash_table_get_char(hash_table ht, const char *key);
unsigned char hash_table_get_uchar(hash_table ht, const char *key);
short hash_table_get_short(hash_table ht, const char *key);
unsigned short hash_table_get_ushort(hash_table ht, const char *key);
int hash_table_get_int(hash_table ht, const char *key);
unsigned int hash_table_get_uint(hash_table ht, const char *key);
long hash_table_get_long(hash_table ht, const char *key);
unsigned long hash_table_get_ulong(hash_table ht, const char *key);
long long hash_table_get_long_long(hash_table ht, const char *key);
unsigned long long hash_table_get_ulong_long(hash_table ht, const char *key);
float hash_table_get_float(hash_table ht, const char *key);
double hash_table_get_double(hash_table ht, const char *key);
long double hash_table_get_long_double(hash_table ht, const char *key);
char* hash_table_get_string(hash_table ht, const char *key);

void* hash_table_unset(hash_table ht, const char *key);
char hash_table_get_char(hash_table ht, const char *key);
unsigned char hash_table_get_uchar(hash_table ht, const char *key);
short hash_table_get_short(hash_table ht, const char *key);
unsigned short hash_table_get_ushort(hash_table ht, const char *key);
int hash_table_get_int(hash_table ht, const char *key);
unsigned int hash_table_get_uint(hash_table ht, const char *key);
long hash_table_get_long(hash_table ht, const char *key);
unsigned long hash_table_get_ulong(hash_table ht, const char *key);
long long hash_table_get_long_long(hash_table ht, const char *key);
unsigned long long hash_table_get_ulong_long(hash_table ht, const char *key);
float hash_table_get_float(hash_table ht, const char *key);
double hash_table_get_double(hash_table ht, const char *key);
long double hash_table_get_long_double(hash_table ht, const char *key);
char* hash_table_get_string(hash_table ht, const char *key);

float hash_table_load(hash_table ht);
void hash_table_set_min_load(hash_table ht, float min_load);
void hash_table_set_max_load(hash_table ht, float max_load);
float hash_table_get_min_load(hash_table ht);
float hash_table_get_max_load(hash_table ht);
void hash_table_set_shrink_factor(hash_table ht, float shrink_factor);
void hash_table_set_grow_factor(hash_table ht, float grow_factor);
float hash_table_get_shrink_factor(hash_table ht);
float hash_table_get_grow_factor(hash_table ht);

void hash_table_rehash(hash_table ht, size_t no_of_buckets);