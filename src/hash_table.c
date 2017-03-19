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
	float grow_factor;
	float max_load;
	float shrink_factor;
	linked_list *buckets;
};

size_t hash(char *str);

hash_table new_hash_table(size_t no_of_buckets) {
	if (no_of_buckets == 0) {
		no_of_buckets = 100;
	}
	hash_table ht = malloc(sizeof(*ht));
	ht->no_of_buckets = no_of_buckets;
	ht->no_of_pairs = 0;
	ht->min_load = 0.15;
	ht->shrink_factor = 0.50;
	ht->max_load = 0.75;
	ht->grow_factor = 2.0;
	ht->buckets = calloc(no_of_buckets, sizeof(linked_list));
	return ht;
}

void hash_table_set(hash_table ht, char *key, void *value, size_t size) {
	void *value_copy = malloc(size);
	memcpy(value_copy, value, size);
	size_t key_len = strlen(key) + 1;
	void *key_copy = malloc(key_len);
	memcpy(key_copy, key, key_len);

	size_t key_hash = hash(key) % ht->no_of_buckets;

	linked_list bucket_list = ht->buckets[key_hash];

	if (bucket_list == NULL) {
		bucket_list = new_linked_list();
		ht->buckets[key_hash] = bucket_list;
	}

	struct pair *p = linked_list_get(bucket_list, 0);

	size_t i = 1;

	while (p != NULL && strcmp(key, p->key) != 0) {
		p = linked_list_get(bucket_list, i);
		++i;
	}

	if (p != NULL) {
		p->value = value_copy;
		p->size = size;
	} else {
		p = malloc(sizeof(*p));
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

void* hash_table_get(hash_table ht, char *key) {
	size_t key_hash = hash(key) % ht->no_of_buckets;

	linked_list bucket_list = ht->buckets[key_hash];

	if (bucket_list == NULL) {
		return NULL;
	}

	struct pair *p = linked_list_get(bucket_list, 0);

	size_t i = 1;

	while (p != NULL && strcmp(key, p->key) != 0) {
		p = linked_list_get(bucket_list, i);
		++i;
	}

	if (p != NULL) {
		return p->value;
	}
	return NULL;
}

void* hash_table_unset(hash_table ht, char *key) {
	size_t key_hash = hash(key) % ht->no_of_buckets;

	linked_list bucket_list = ht->buckets[key_hash];

	if (bucket_list == NULL) {
		return NULL;
	}

	struct pair *p = linked_list_get(bucket_list, 0);

	size_t i = 1;

	while (p != NULL && strcmp(key, p->key) != 0) {
		p = linked_list_get(bucket_list, i);
		++i;
	}

	if (p != NULL) {
		linked_list_remove(bucket_list, i - 1);
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
	return NULL;
}

float hash_table_load(hash_table ht) {
	return (ht->no_of_pairs)/(float)ht->no_of_buckets;
}

void hash_table_rehash(hash_table ht, size_t no_of_buckets) {
	linked_list *buckets = calloc(no_of_buckets, sizeof(linked_list));
	for (int i = 0; i < ht->no_of_buckets; ++i) {
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
			free(ht->buckets[i]);
			ht->buckets[i] = NULL;
		}
	}
	free(ht->buckets);
	ht->buckets = buckets;
	ht->no_of_buckets = no_of_buckets;
}

// https://stackoverflow.com/questions/7666509/hash-function-for-string
size_t hash(char *str) {
	size_t hash = 5381;
	size_t c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}