#include "../include/hash_table.h"

struct pair {
	char *key;
	void *value;
	size_t size;
};

struct _hash_table {
	size_t no_of_buckets;
	size_t no_of_pairs;
	float min_load;
	float shrink_factor;
	float max_load;
	float grow_factor;
	linked_list *buckets;
};

size_t hash(const char *str);

hash_table new_hash_table(size_t no_of_buckets) {
	assert(no_of_buckets > 0);
	hash_table ht = malloc(sizeof(*ht));
	assert(ht != NULL);
	ht->no_of_buckets = no_of_buckets;
	ht->no_of_pairs = 0;
	ht->min_load = 0.15;
	ht->shrink_factor = 0.50;
	ht->max_load = 0.75;
	ht->grow_factor = 2.0;
	ht->buckets = calloc(no_of_buckets, sizeof(linked_list));
	assert(ht->buckets != NULL);
	return ht;
}

void hash_table_set_generic(hash_table ht, const char *key, const void *value, size_t size) {

	assert(ht != NULL);
	assert(key != NULL);

	void *value_copy = malloc(size);
	assert(value_copy != NULL);
	memcpy(value_copy, value, size);
	size_t key_len = strlen(key) + 1;
	void *key_copy = malloc(key_len);
	assert(key_copy != NULL);
	memcpy(key_copy, key, key_len);

	size_t key_hash = hash(key) % ht->no_of_buckets;

	linked_list bucket_list = ht->buckets[key_hash];

	if (bucket_list == NULL) {
		bucket_list = new_linked_list();
		ht->buckets[key_hash] = bucket_list;
	}

	struct pair *p = NULL;

	size_t len = linked_list_length(bucket_list);
	size_t i = 0;

	for (i = 0; i < len; ++i) {
		p = linked_list_get(bucket_list, i);
		if (strcmp(key, p->key) == 0) {
			break;
		}
	}

	if (p != NULL && i < len) {
		p->value = value_copy;
		p->size = size;
	} else {
		p = malloc(sizeof(*p));
		assert(p != NULL);
		p->key = key_copy;
		p->value = value_copy;
		p->size = size;
		linked_list_add_generic(bucket_list, p, sizeof(*p));
		free(p);
		++ht->no_of_pairs;

		if (hash_table_load(ht) > ht->max_load) {
			hash_table_rehash(ht, ht->no_of_buckets*ht->grow_factor);
		}
	}
}

void hash_table_set_char(hash_table ht, const char *key, const char value) {
	hash_table_set_generic(ht, key, &value, sizeof(value));
}

void hash_table_set_uchar(hash_table ht, const char *key, const unsigned char value) {
	hash_table_set_generic(ht, key, &value, sizeof(value));
}

void hash_table_set_short(hash_table ht, const char *key, const short value) {
	hash_table_set_generic(ht, key, &value, sizeof(value));
}

void hash_table_set_ushort(hash_table ht, const char *key, const unsigned short value) {
	hash_table_set_generic(ht, key, &value, sizeof(value));
}

void hash_table_set_int(hash_table ht, const char *key, const int value) {
	hash_table_set_generic(ht, key, &value, sizeof(value));
}

void hash_table_set_uint(hash_table ht, const char *key, const unsigned int value) {
	hash_table_set_generic(ht, key, &value, sizeof(value));
}

void hash_table_set_long(hash_table ht, const char *key, const long value) {
	hash_table_set_generic(ht, key, &value, sizeof(value));
}

void hash_table_set_ulong(hash_table ht, const char *key, const unsigned long value) {
	hash_table_set_generic(ht, key, &value, sizeof(value));
}

void hash_table_set_long_long(hash_table ht, const char *key, const long long value) {
	hash_table_set_generic(ht, key, &value, sizeof(value));
}

void hash_table_set_ulong_long(hash_table ht, const char *key, const unsigned long long value) {
	hash_table_set_generic(ht, key, &value, sizeof(value));
}

void hash_table_set_float(hash_table ht, const char *key, const float value) {
	hash_table_set_generic(ht, key, &value, sizeof(value));
}

void hash_table_set_double(hash_table ht, const char *key, const double value) {
	hash_table_set_generic(ht, key, &value, sizeof(value));
}

void hash_table_set_long_double(hash_table ht, const char *key, const long double value) {
	hash_table_set_generic(ht, key, &value, sizeof(value));
}

void hash_table_set_string(hash_table ht, const char *key, const char *value) {
	hash_table_set_generic(ht, key, value, strlen(value) + 1);
}

bool hash_table_is_set(hash_table ht, const char *key) {

	assert(ht != NULL);
	assert(key != NULL);

	size_t key_hash = hash(key) % ht->no_of_buckets;

	if (ht->buckets[key_hash] == NULL) {
		return false;
	}

	linked_list bucket_list = ht->buckets[key_hash];

	struct pair *p = NULL;

	size_t len = linked_list_length(bucket_list);
	size_t i = 0;

	for (i = 0; i < len; ++i) {
		p = linked_list_get(bucket_list, i);
		if (strcmp(key, p->key) == 0) {
			break;
		}
	}

	if (p != NULL && i < len) {
		return true;
	}
	return false;
}

void* hash_table_get(hash_table ht, const char *key) {

	assert(ht != NULL);
	assert(key != NULL);

	size_t key_hash = hash(key) % ht->no_of_buckets;

	linked_list bucket_list = ht->buckets[key_hash];

	struct pair *p = NULL;

	size_t len = linked_list_length(bucket_list);
	size_t i = 0;

	for (i = 0; i < len; ++i) {
		p = linked_list_get(bucket_list, i);
		if (strcmp(key, p->key) == 0) {
			break;
		}
	}

	assert(strcmp(key, p->key) == 0);
	return p->value;
}

char hash_table_get_char(hash_table ht, const char *key) {
	return *(char *)hash_table_get(ht, key);
}

unsigned char hash_table_get_uchar(hash_table ht, const char *key) {
	return *(unsigned char *)hash_table_get(ht, key);
}

short hash_table_get_short(hash_table ht, const char *key) {
	return *(short *)hash_table_get(ht, key);
}

unsigned short hash_table_get_ushort(hash_table ht, const char *key) {
	return *(unsigned short *)hash_table_get(ht, key);
}

int hash_table_get_int(hash_table ht, const char *key) {
	return *(int *)hash_table_get(ht, key);
}

unsigned int hash_table_get_uint(hash_table ht, const char *key) {
	return *(unsigned int *)hash_table_get(ht, key);
}

long hash_table_get_long(hash_table ht, const char *key) {
	return *(long *)hash_table_get(ht, key);
}

unsigned long hash_table_get_ulong(hash_table ht, const char *key) {
	return *(unsigned long *)hash_table_get(ht, key);
}

long long hash_table_get_long_long(hash_table ht, const char *key) {
	return *(long long *)hash_table_get(ht, key);
}

unsigned long long hash_table_get_ulong_long(hash_table ht, const char *key) {
	return *(unsigned long long *)hash_table_get(ht, key);
}

float hash_table_get_float(hash_table ht, const char *key) {
	return *(float *)hash_table_get(ht, key);
}

double hash_table_get_double(hash_table ht, const char *key) {
	return *(double *)hash_table_get(ht, key);
}

long double hash_table_get_long_double(hash_table ht, const char *key) {
	return *(long double *)hash_table_get(ht, key);
}

char* hash_table_get_string(hash_table ht, const char *key) {
	return hash_table_get(ht, key);
}

void* hash_table_unset(hash_table ht, const char *key) {

	assert(ht != NULL);
	assert(key != NULL);

	size_t key_hash = hash(key) % ht->no_of_buckets;

	linked_list bucket_list = ht->buckets[key_hash];

	struct pair *p = NULL;

	size_t len = linked_list_length(bucket_list);
	size_t i = 0;

	for (i = 0; i < len; ++i) {
		p = linked_list_get(bucket_list, i);
		if (strcmp(key, p->key) == 0) {
			break;
		}
	}

	assert(strcmp(key, p->key) == 0);
	linked_list_remove(bucket_list, i);
	free(p->key);
	void *value = p->value;
	free(p);
	--ht->no_of_pairs;
	if (linked_list_length(bucket_list) == 0) {
		free(bucket_list);
		ht->buckets[key_hash] = NULL;
	}

	if (hash_table_load(ht) < ht->min_load) {
		hash_table_rehash(ht, ht->no_of_buckets*ht->shrink_factor);
	}
	return value;
}

char hash_table_unset_char(hash_table ht, const char *key) {
	char *data = hash_table_unset(ht, key);
	char return_data = *data;
	free(data);
	return return_data;
}

unsigned char hash_table_unset_uchar(hash_table ht, const char *key) {
	unsigned char *data = hash_table_unset(ht, key);
	unsigned char return_data = *data;
	free(data);
	return return_data;
}

short hash_table_unset_short(hash_table ht, const char *key) {
	short *data = hash_table_unset(ht, key);
	short return_data = *data;
	free(data);
	return return_data;
}

unsigned short hash_table_unset_ushort(hash_table ht, const char *key) {
	unsigned short *data = hash_table_unset(ht, key);
	unsigned short return_data = *data;
	free(data);
	return return_data;
}

int hash_table_unset_int(hash_table ht, const char *key) {
	int *data = hash_table_unset(ht, key);
	int return_data = *data;
	free(data);
	return return_data;
}

unsigned int hash_table_unset_uint(hash_table ht, const char *key) {
	unsigned int *data = hash_table_unset(ht, key);
	unsigned int return_data = *data;
	free(data);
	return return_data;
}

long hash_table_unset_long(hash_table ht, const char *key) {
	long *data = hash_table_unset(ht, key);
	long return_data = *data;
	free(data);
	return return_data;
}

unsigned long hash_table_unset_ulong(hash_table ht, const char *key) {
	unsigned long *data = hash_table_unset(ht, key);
	unsigned long return_data = *data;
	free(data);
	return return_data;
}

long long hash_table_unset_long_long(hash_table ht, const char *key) {
	long long *data = hash_table_unset(ht, key);
	long long return_data = *data;
	free(data);
	return return_data;
}

unsigned long long hash_table_unset_ulong_long(hash_table ht, const char *key) {
	unsigned long long *data = hash_table_unset(ht, key);
	unsigned long long return_data = *data;
	free(data);
	return return_data;
}

float hash_table_unset_float(hash_table ht, const char *key) {
	float *data = hash_table_unset(ht, key);
	float return_data = *data;
	free(data);
	return return_data;
}

double hash_table_unset_double(hash_table ht, const char *key) {
	double *data = hash_table_unset(ht, key);
	double return_data = *data;
	free(data);
	return return_data;
}

long double hash_table_unset_long_double(hash_table ht, const char *key) {
	long double *data = hash_table_unset(ht, key);
	long double return_data = *data;
	free(data);
	return return_data;
}

char* hash_table_unset_string(hash_table ht, const char *key) {
	return hash_table_unset(ht, key);
}

float hash_table_load(hash_table ht) {
	return (ht->no_of_pairs)/(float)ht->no_of_buckets;
}

void hash_table_rehash(hash_table ht, size_t no_of_buckets) {

	assert(ht != NULL);
	assert(no_of_buckets > 0);

	linked_list *buckets = calloc(no_of_buckets, sizeof(linked_list));
	assert(buckets != NULL);
	for (size_t i = 0; i < ht->no_of_buckets; ++i) {
		if (ht->buckets[i] != NULL) {
			while (linked_list_length(ht->buckets[i])) {
				struct pair *temp_pair = linked_list_remove(ht->buckets[i], 0);
				size_t key_hash = hash(temp_pair->key) % no_of_buckets;

				if (buckets[key_hash] == NULL) {
					buckets[key_hash] = new_linked_list();
				}

				linked_list_add_generic(buckets[key_hash], temp_pair, sizeof(*temp_pair));
				free(temp_pair);
			}
			linked_list_destroy(ht->buckets[i]);
			ht->buckets[i] = NULL;
		}
	}
	free(ht->buckets);
	ht->buckets = buckets;
	ht->no_of_buckets = no_of_buckets;
}

void hash_table_set_min_load(hash_table ht, float min_load) {
	assert(ht != NULL);
	ht->min_load = min_load;
}

void hash_table_set_max_load(hash_table ht, float max_load) {
	assert(ht != NULL);
	ht->max_load = max_load;
}

float hash_table_get_min_load(hash_table ht) {
	assert(ht != NULL);
	return ht->min_load;
}

float hash_table_get_max_load(hash_table ht) {
	assert(ht != NULL);
	return ht->max_load;
}

void hash_table_set_shrink_factor(hash_table ht, float shrink_factor) {
	assert(ht != NULL);
	ht->shrink_factor = shrink_factor;
}

void hash_table_set_grow_factor(hash_table ht, float grow_factor) {
	assert(ht != NULL);
	ht->grow_factor = grow_factor;
}

float hash_table_get_shrink_factor(hash_table ht) {
	assert(ht != NULL);
	return ht->shrink_factor;
}

float hash_table_get_grow_factor(hash_table ht) {
	assert(ht != NULL);
	return ht->grow_factor;
}

// https://stackoverflow.com/questions/7666509/hash-function-for-string
size_t hash(const char *str) {
	size_t hash = 5381;
	size_t c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}

void hash_table_destroy(hash_table ht) {
	if (ht == NULL) {
		return;
	}
	for (size_t i = 0; i < ht->no_of_buckets; ++i) {
		if (ht->buckets[i] != NULL) {
			while (linked_list_length(ht->buckets[i])) {
				struct pair *temp_pair = linked_list_remove(ht->buckets[i], 0);
				free(temp_pair->key);
				free(temp_pair->value);
				free(temp_pair);
			}
			linked_list_destroy(ht->buckets[i]);
		}
	}
	free(ht->buckets);
	free(ht);
}