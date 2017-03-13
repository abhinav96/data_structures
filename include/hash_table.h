#include "linked_list.h"

typedef struct _hash_table* hash_table;

hash_table new_hash_table(size_t no_of_buckets);
void hash_table_set(hash_table ht, char *key, void *value, size_t size);
void* hash_table_get(hash_table ht, char *key);
void* hash_table_unset(hash_table ht, char *key);
float hash_table_load(hash_table ht);
void hash_table_rehash(hash_table ht, size_t no_of_buckets);