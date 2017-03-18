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
	void *data_copy = malloc(size);
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
		while(list->middle_index != middle_index && list->middle->next != NULL) {
			list->middle = list->middle->next;
			++list->middle_index;
		}
	} else if (list->middle_index > middle_index) {
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
}

void linked_list_add(linked_list list, void *data, size_t size) {
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

node linked_list_get_node_at_index(linked_list list, size_t index) {
	if (list->first == NULL || index > list->length - 1) {
		return NULL;
	}
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
	if (temp != NULL) {
		return temp->data;
	}
	return NULL;
}

void* linked_list_remove(linked_list list, size_t index) {
	void* data = NULL;
	if (list->length == 0) {
		return data;
	} else if (list->length == 1) {
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
	if (del_el != NULL) {
		list->iterator = del_el->prev;
		list->iterator_index = index - 1;
		data = del_el->data;
		if (index == list->middle_index) {
			if (list->middle_index > 0) {
				--list->middle_index;
			}
			list->middle = list->middle->prev;
		} else if (index < list->middle_index) {
			if (list->middle_index > 0) {
				--list->middle_index;
			}
		}
		if (del_el == list->first) {
			list->first = list->first->next;
			list->first->prev = NULL;
		} else if (del_el == list->last) {
			list->last = list->last->prev;
			list->last->next = NULL;
		} else {
			del_el->prev->next = del_el->next;
			del_el->next->prev = del_el->prev;
		}

		--list->length;
		free(del_el);
		
		reset_middle(list);
	}
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

void linked_list_add_at(linked_list list, void *data, size_t size, size_t index) {
	if (index > list->length) {
		return;
	}
	if (index == list->length) {
		linked_list_add(list, data, size);
		return;
	}
	node new_el = new_node(data, size);
	if (list->first == NULL) {
		list->first = new_el;
		list->last = new_el;
		++list->length;
		reset_middle(list);
	} else {
		node node_at_index = linked_list_get_node_at_index(list, index);
		if (node_at_index != NULL) {
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
		}
	}
	list->iterator = new_el;
	list->iterator_index = index;
	return;
}

size_t linked_list_length(linked_list list) {
	return list->length;
}