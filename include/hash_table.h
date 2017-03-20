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
	long double: hash_table_set_long_double \
	)(X, Y, Z)

hash_table new_hash_table(size_t no_of_buckets);

void hash_table_set_generic(hash_table ht, char *key, void *value, size_t size);
void hash_table_set_char(hash_table ht, char *key, char data);
void hash_table_set_uchar(hash_table ht, char *key, unsigned char data);
void hash_table_set_short(hash_table ht, char *key, short data);
void hash_table_set_ushort(hash_table ht, char *key, unsigned short data);
void hash_table_set_int(hash_table ht, char *key, int data);
void hash_table_set_uint(hash_table ht, char *key, unsigned int data);
void hash_table_set_long(hash_table ht, char *key, long data);
void hash_table_set_ulong(hash_table ht, char *key, unsigned long data);
void hash_table_set_long_long(hash_table ht, char *key, long long data);
void hash_table_set_ulong_long(hash_table ht, char *key, unsigned long long data);
void hash_table_set_float(hash_table ht, char *key, float data);
void hash_table_set_double(hash_table ht, char *key, double data);
void hash_table_set_long_double(hash_table ht, char *key, long double data);
void hash_table_set_string(hash_table ht, char *key, char *data);

void* hash_table_get(hash_table ht, char *key);
char hash_table_get_char(hash_table ht, char *key);
unsigned char hash_table_get_uchar(hash_table ht, char *key);
short hash_table_get_short(hash_table ht, char *key);
unsigned short hash_table_get_ushort(hash_table ht, char *key);
int hash_table_get_int(hash_table ht, char *key);
unsigned int hash_table_get_uint(hash_table ht, char *key);
long hash_table_get_long(hash_table ht, char *key);
unsigned long hash_table_get_ulong(hash_table ht, char *key);
long long hash_table_get_long_long(hash_table ht, char *key);
unsigned long long hash_table_get_ulong_long(hash_table ht, char *key);
float hash_table_get_float(hash_table ht, char *key);
double hash_table_get_double(hash_table ht, char *key);
long double hash_table_get_long_double(hash_table ht, char *key);
char* hash_table_get_string(hash_table ht, char *key);

void* hash_table_unset(hash_table ht, char *key);

float hash_table_load(hash_table ht);

void hash_table_rehash(hash_table ht, size_t no_of_buckets);