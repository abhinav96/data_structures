#include "../include/linked_list.h"

struct _node {
	struct _node *next;
	struct _node *prev;
	void *data;
};

typedef struct _node* node;

struct _linked_list {
	node first;
	node last;
	node middle;
	node iterator;
	size_t length;
	size_t iterator_index;
	size_t middle_index;
};

node new_node(void *data, size_t size);
node linked_list_get_node_at_index(linked_list list, size_t index);
void reset_middle(linked_list list);

linked_list new_linked_list() {
	linked_list new_ll = malloc(sizeof(*new_ll));
	assert(new_ll != NULL);
	new_ll->first = NULL;
	new_ll->last = NULL;
	new_ll->middle = NULL;
	new_ll->iterator = NULL;
	new_ll->iterator_index = 0;
	new_ll->middle_index = 0;
	new_ll->length = 0;
	return new_ll;
}

node new_node(void *data, size_t size) {
	node new_el = malloc(sizeof(*new_el));
	assert(new_el != NULL);
	void *data_copy = malloc(size);
	assert(data_copy != NULL);
	memcpy(data_copy, data, size);
	new_el->data = data_copy;
	new_el->next = NULL;
	new_el->prev = NULL;
	return new_el;
}

void reset_middle(linked_list list) {
	size_t middle_index = list->length/2;

	if (list->middle == NULL) {
		list->middle_index = 0;
		list->middle = list->first;
	}

	if (list->middle_index > middle_index) {
		while(list->middle_index != middle_index) {
			list->middle = list->middle->prev;
			--list->middle_index;
		}
	} else {
		while(list->middle_index != middle_index) {
			list->middle = list->middle->next;
			++list->middle_index;
		}
	}
	assert(list->middle_index == list->length/2);
}

void linked_list_add_generic(linked_list list, void *data, size_t size) {
	assert(list != NULL);
	node new_el = new_node(data, size);
	if (list->first == NULL) {
		list->first = new_el;
		list->last = new_el;
	} else {
		list->last->next = new_el;
		new_el->prev = list->last;
		list->last = new_el;
	}
	++list->length;
	reset_middle(list);
}

void linked_list_add_char(linked_list list, char data) {
	linked_list_add_generic(list, &data, sizeof(data));
}

void linked_list_add_uchar(linked_list list, unsigned char data) {
	linked_list_add_generic(list, &data, sizeof(data));
}

void linked_list_add_short(linked_list list, short data) {
	linked_list_add_generic(list, &data, sizeof(data));
}

void linked_list_add_ushort(linked_list list, unsigned short data) {
	linked_list_add_generic(list, &data, sizeof(data));
}

void linked_list_add_int(linked_list list, int data) {
	linked_list_add_generic(list, &data, sizeof(data));
}

void linked_list_add_uint(linked_list list, unsigned int data) {
	linked_list_add_generic(list, &data, sizeof(data));
}

void linked_list_add_long(linked_list list, long data) {
	linked_list_add_generic(list, &data, sizeof(data));
}

void linked_list_add_ulong(linked_list list, unsigned long data) {
	linked_list_add_generic(list, &data, sizeof(data));
}

void linked_list_add_long_long(linked_list list, long long data) {
	linked_list_add_generic(list, &data, sizeof(data));
}

void linked_list_add_ulong_long(linked_list list, unsigned long long data) {
	linked_list_add_generic(list, &data, sizeof(data));
}

void linked_list_add_float(linked_list list, float data) {
	linked_list_add_generic(list, &data, sizeof(data));
}

void linked_list_add_double(linked_list list, double data) {
	linked_list_add_generic(list, &data, sizeof(data));
}

void linked_list_add_long_double(linked_list list, long double data) {
	linked_list_add_generic(list, &data, sizeof(data));
}

void linked_list_add_string(linked_list list, char *data) {
	linked_list_add_generic(list, data, strlen(data) + 1);
}

node linked_list_get_node_at_index(linked_list list, size_t index) {

	assert(list != NULL);
	assert(index < linked_list_length(list));

	node temp = NULL;
	size_t temp_index = 0;
	size_t first = index;
	size_t last = list->length - index - 1;
	size_t middle;
	if (index < list->middle_index) {
		middle = list->middle_index - index;
	} else {
		middle = index - list->middle_index;
	}
	
	if (list->iterator == NULL || list->iterator_index >= list->length) {
		list->iterator = list->middle;
		list->iterator_index = list->middle_index;
	}
	size_t iterator;
	if (index < list->iterator_index) {
		iterator = list->iterator_index - index;
	} else {
		iterator = index - list->iterator_index;
	}

	if (iterator <= first && iterator <= middle && iterator <= last) {
		temp = list->iterator;
		temp_index = list->iterator_index;
		if (list->iterator_index < index) {
			while (temp_index != index) {
				temp = temp->next;
				++temp_index;
			}
		} else if (list->iterator_index > index) {
			while (temp_index != index) {
				temp = temp->prev;
				--temp_index;
			}
		}
	} else if (first <= middle && first <= last) {
		temp = list->first;
		temp_index = 0;
		while (temp_index != index) {
			temp = temp->next;
			++temp_index;
		}
	} else if (middle <= last) {
		temp = list->middle;
		temp_index = list->middle_index;
		if (list->middle_index < index) {
			while (temp_index != index) {
				temp = temp->next;
				++temp_index;
			}
		} else if (list->middle_index > index) {
			while (temp_index != index) {
				temp = temp->prev;
				--temp_index;
			}
		}
	} else {
		temp = list->last;
		temp_index = list->length - 1;
		while (temp_index != index) {
			temp = temp->prev;
			--temp_index;
		}
	}
	list->iterator = temp;
	list->iterator_index = temp_index;
	return temp;
}

void* linked_list_get(linked_list list, size_t index) {
	node temp = linked_list_get_node_at_index(list, index);
	return temp->data;
}

char linked_list_get_char(linked_list list, size_t index) {
	return *(char *)linked_list_get(list, index);
}

unsigned char linked_list_get_uchar(linked_list list, size_t index) {
	return *(unsigned char *)linked_list_get(list, index);
}

short linked_list_get_short(linked_list list, size_t index) {
	return *(short *)linked_list_get(list, index);
}

unsigned short linked_list_get_ushort(linked_list list, size_t index) {
	return *(unsigned short *)linked_list_get(list, index);
}

int linked_list_get_int(linked_list list, size_t index) {
	return *(int *)linked_list_get(list, index);
}

unsigned int linked_list_get_uint(linked_list list, size_t index) {
	return *(unsigned int *)linked_list_get(list, index);
}

long linked_list_get_long(linked_list list, size_t index) {
	return *(long *)linked_list_get(list, index);
}

unsigned long linked_list_get_ulong(linked_list list, size_t index) {
	return *(unsigned long *)linked_list_get(list, index);
}

long long linked_list_get_long_long(linked_list list, size_t index) {
	return *(long long *)linked_list_get(list, index);
}

unsigned long long linked_list_get_ulong_long(linked_list list, size_t index) {
	return *(unsigned long long *)linked_list_get(list, index);
}

float linked_list_get_float(linked_list list, size_t index) {
	return *(float *)linked_list_get(list, index);
}

double linked_list_get_double(linked_list list, size_t index) {
	return *(double *)linked_list_get(list, index);
}

long double linked_list_get_long_double(linked_list list, size_t index) {
	return *(long double *)linked_list_get(list, index);
}

char* linked_list_get_string(linked_list list, size_t index) {
	return linked_list_get(list, index);
}

void* linked_list_remove(linked_list list, size_t index) {
	
	assert(list != NULL);
	assert(index < linked_list_length(list));

	void* data = NULL;
	if (list->length == 1) {
		data = list->first->data;
		free(list->first);
		list->middle = NULL;
		list->iterator = NULL;
		list->last = NULL;
		list->middle_index = 0;
		list->iterator_index = 0;
		list->first = NULL;
		--list->length;
		return data;
	}

	node del_el = linked_list_get_node_at_index(list, index);
	list->iterator = del_el->prev;
	list->iterator_index = index - 1;
	data = del_el->data;

	if (index == list->middle_index) {
		list->middle = list->middle->prev;
	}
	if (index <= list->middle_index) {
		--list->middle_index;
	}

	if (index == 0) {
		list->first = list->first->next;
		list->first->prev = NULL;
	} else if (index == list->length - 1) {
		list->last = list->last->prev;
		list->last->next = NULL;
	} else {
		del_el->prev->next = del_el->next;
		del_el->next->prev = del_el->prev;
	}
	list->iterator_index = index;
	list->iterator = del_el->next;

	--list->length;
	free(del_el);
	
	reset_middle(list);

	assert(list->middle_index == list->length/2);
	return data;
}

char linked_list_remove_char(linked_list list, size_t index) {
	char *data = linked_list_remove(list, index);
	char return_data = *data;
	free(data);
	return return_data;
}

unsigned char linked_list_remove_uchar(linked_list list, size_t index) {
	unsigned char *data = linked_list_remove(list, index);
	unsigned char return_data = *data;
	free(data);
	return return_data;
}

short linked_list_remove_short(linked_list list, size_t index) {
	short *data = linked_list_remove(list, index);
	short return_data = *data;
	free(data);
	return return_data;
}

unsigned short linked_list_remove_ushort(linked_list list, size_t index) {
	unsigned short *data = linked_list_remove(list, index);
	unsigned short return_data = *data;
	free(data);
	return return_data;
}

int linked_list_remove_int(linked_list list, size_t index) {
	int *data = linked_list_remove(list, index);
	int return_data = *data;
	free(data);
	return return_data;
}

unsigned int linked_list_remove_uint(linked_list list, size_t index) {
	unsigned int *data = linked_list_remove(list, index);
	unsigned int return_data = *data;
	free(data);
	return return_data;
}

long linked_list_remove_long(linked_list list, size_t index) {
	long *data = linked_list_remove(list, index);
	long return_data = *data;
	free(data);
	return return_data;
}

unsigned long linked_list_remove_ulong(linked_list list, size_t index) {
	unsigned long *data = linked_list_remove(list, index);
	unsigned long return_data = *data;
	free(data);
	return return_data;
}

long long linked_list_remove_long_long(linked_list list, size_t index) {
	long long *data = linked_list_remove(list, index);
	long long return_data = *data;
	free(data);
	return return_data;
}

unsigned long long linked_list_remove_ulong_long(linked_list list, size_t index) {
	unsigned long long *data = linked_list_remove(list, index);
	unsigned long long return_data = *data;
	free(data);
	return return_data;
}

float linked_list_remove_float(linked_list list, size_t index) {
	float *data = linked_list_remove(list, index);
	float return_data = *data;
	free(data);
	return return_data;
}

double linked_list_remove_double(linked_list list, size_t index) {
	double *data = linked_list_remove(list, index);
	double return_data = *data;
	free(data);
	return return_data;
}

long double linked_list_remove_long_double(linked_list list, size_t index) {
	long double *data = linked_list_remove(list, index);
	long double return_data = *data;
	free(data);
	return return_data;
}

char* linked_list_remove_string(linked_list list, size_t index) {
	return linked_list_remove(list, index);
}

void linked_list_add_generic_at(linked_list list, void *data, size_t size, size_t index) {

	assert(list != NULL);
	assert(index <= linked_list_length(list));

	if (index == list->length) {
		linked_list_add_generic(list, data, size);
		return;
	}
	node new_el = new_node(data, size);
	node node_at_index = linked_list_get_node_at_index(list, index);
	if (index == 0) {
		list->first->prev = new_el;
		new_el->next = list->first;
		list->first = new_el;
	} else {
		node_at_index->prev->next = new_el;
		new_el->prev = node_at_index->prev;
		new_el->next = node_at_index;
		node_at_index->prev = new_el;
	}
	if (index <= list->middle_index) {
		++list->middle_index;
	}
	++list->length;
	reset_middle(list);
	list->iterator = new_el;
	list->iterator_index = index;
	assert(list->middle_index == list->length/2);
	return;
}

void linked_list_add_char_at(linked_list list, char data, size_t index) {
	linked_list_add_generic_at(list, &data, sizeof(data), index);
}

void linked_list_add_uchar_at(linked_list list, unsigned char data, size_t index) {
	linked_list_add_generic_at(list, &data, sizeof(data), index);
}

void linked_list_add_short_at(linked_list list, short data, size_t index) {
	linked_list_add_generic_at(list, &data, sizeof(data), index);
}

void linked_list_add_ushort_at(linked_list list, unsigned short data, size_t index) {
	linked_list_add_generic_at(list, &data, sizeof(data), index);
}

void linked_list_add_int_at(linked_list list, int data, size_t index) {
	linked_list_add_generic_at(list, &data, sizeof(data), index);
}

void linked_list_add_uint_at(linked_list list, unsigned int data, size_t index) {
	linked_list_add_generic_at(list, &data, sizeof(data), index);
}

void linked_list_add_long_at(linked_list list, long data, size_t index) {
	linked_list_add_generic_at(list, &data, sizeof(data), index);
}

void linked_list_add_ulong_at(linked_list list, unsigned long data, size_t index) {
	linked_list_add_generic_at(list, &data, sizeof(data), index);
}

void linked_list_add_long_long_at(linked_list list, long long data, size_t index) {
	linked_list_add_generic_at(list, &data, sizeof(data), index);
}

void linked_list_add_ulong_long_at(linked_list list, unsigned long long data, size_t index) {
	linked_list_add_generic_at(list, &data, sizeof(data), index);
}

void linked_list_add_float_at(linked_list list, float data, size_t index) {
	linked_list_add_generic_at(list, &data, sizeof(data), index);
}

void linked_list_add_double_at(linked_list list, double data, size_t index) {
	linked_list_add_generic_at(list, &data, sizeof(data), index);
}

void linked_list_add_long_double_at(linked_list list, long double data, size_t index) {
	linked_list_add_generic_at(list, &data, sizeof(data), index);
}

void linked_list_add_string_at(linked_list list, char *data, size_t index) {
	linked_list_add_generic_at(list, data, strlen(data), index);
}

size_t linked_list_length(linked_list list) {
	assert(list != NULL);
	return list->length;
}

void linked_list_destroy(linked_list list) {
	if (list == NULL) {
		return;
	}
	node temp = list->first;
	while (temp != NULL) {
		node temp_next = temp->next;
		free(temp->data);
		free(temp);
		temp = temp_next;
	}
	free(list);
}