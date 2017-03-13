#include "../include/priority_queue.h"

struct _priority_node {
	struct _priority_node *next;
	struct _priority_node *prev;
	long long priority;
	void *data;
};

typedef struct _priority_node* priority_node;

struct _priority_queue {
	priority_node first;
	priority_node last;
	priority_node middle;
	priority_node iterator;
	size_t length;
	size_t iterator_index;
	size_t middle_index;
};

priority_node new_priority_node(void *data, size_t size, long long priority);
size_t find_index_for_priority(priority_queue q, long long priority);
void priority_queue_add_at(priority_queue q, void *data, size_t size, long long priority, size_t index);
void priority_queue_add(priority_queue q, void *data, size_t size, long long priority);
void priority_queue_reset_middle(priority_queue q);
priority_node priority_queue_get_node_at_index(priority_queue q, size_t index);

priority_node new_priority_node(void *data, size_t size, long long priority) {
	priority_node new_pn = malloc(sizeof(*new_pn));
	void *data_copy = malloc(size);
	memcpy(data_copy, data, size);
	new_pn->data = data_copy;
	new_pn->next = NULL;
	new_pn->prev = NULL;
	new_pn->priority = priority;
	return new_pn;
}

priority_queue new_priority_queue() {
	priority_queue new_q = malloc(sizeof(*new_q));
	new_q->first = NULL;
	new_q->last = NULL;
	new_q->middle = NULL;
	new_q->iterator = NULL;
	new_q->iterator_index = 0;
	new_q->middle_index = 0;
	new_q->length = 0;
	return new_q;
}

size_t find_index_for_priority(priority_queue q, long long priority) {
	if (priority_queue_length(q) == 0) {
		return 0;
	}

	priority_node temp = NULL;
	size_t temp_index = 0;

	if (q->last->priority <= priority) {
		return q->length;
	}

	if (q->first->priority > priority) {
		return 0;
	}

	if (q->iterator != NULL && q->iterator_index < q->length) {
		if (q->iterator_index >= q->middle_index) {
			if (q->iterator->priority <= priority) {
				temp = q->iterator->next;
				temp_index = q->iterator_index + 1;
			} else if (q->middle->priority <= priority) {
				temp = q->middle->next;
				temp_index = q->middle_index + 1;
			}
		} else {
			if (q->middle->priority <= priority) {
				temp = q->middle->next;
				temp_index = q->middle_index + 1;
			} else if (q->iterator->priority <= priority) {
				temp = q->iterator->next;
				temp_index = q->iterator_index + 1;
			}
		}
	}

	if (temp == NULL) {
		if (q->middle->priority <= priority) {
			temp = q->middle->next;
			temp_index = q->middle_index + 1;
		} else {
			temp = q->first;
			temp_index = 0;
		}
	}

	while (temp != NULL && temp->priority <= priority) {
		temp = temp->next;
		++temp_index;
	}

	q->iterator = temp;
	q->iterator_index = temp_index;

	return temp_index;
}

void priority_queue_add_at(priority_queue q, void *data, size_t size, long long priority, size_t index) {
	if (index > q->length) {
		return;
	}
	if (index == q->length) {
		priority_queue_add(q, data, size, priority);
		return;
	}
	priority_node new_pn = new_priority_node(data, size, priority);
	if (q->first == NULL) {
		q->first = new_pn;
		q->last = new_pn;
		++q->length;
		priority_queue_reset_middle(q);
	} else {
		priority_node node_at_index = priority_queue_get_node_at_index(q, index);
		if (node_at_index != NULL) {
			if (index == 0) {
				q->first->prev = new_pn;
				new_pn->next = q->first;
				q->first = new_pn;
			} else {
				node_at_index->prev->next = new_pn;
				new_pn->prev = node_at_index->prev;
				new_pn->next = node_at_index;
				node_at_index->prev = new_pn;
			}
			if (index <= q->middle_index) {
				++q->middle_index;
			}
			++q->length;
			priority_queue_reset_middle(q);
		}
	}
	q->iterator = new_pn;
	q->iterator_index = index;
	return;
}

void priority_queue_add(priority_queue q, void *data, size_t size, long long priority) {
	priority_node new_pn = new_priority_node(data, size, priority);
	if (q->first == NULL) {
		q->first = new_pn;
		q->last = new_pn;
	} else {
		q->last->next = new_pn;
		new_pn->prev = q->last;
		q->last = new_pn;
	}
	++q->length;
	priority_queue_reset_middle(q);
}

void priority_queue_enqueue(priority_queue q, void *data, size_t size, long long priority) {
	size_t index = find_index_for_priority(q, priority);
	priority_queue_add_at(q, data, size, priority, index);
	return;
}

void priority_queue_reset_middle(priority_queue q) {
	size_t middle_index = q->length/2;
	if (q->middle == NULL || q->middle_index >= q->length) {
		q->middle_index = 0;
		q->middle = q->first;
		while(q->middle_index != middle_index && q->middle->next != NULL) {
			q->middle = q->middle->next;
			++q->middle_index;
		}
	} else if (q->middle_index > middle_index) {
		while(q->middle_index != middle_index) {
			q->middle = q->middle->prev;
			--q->middle_index;
		}
	} else {
		while(q->middle_index != middle_index) {
			q->middle = q->middle->next;
			++q->middle_index;
		}
	}
}

priority_node priority_queue_get_node_at_index(priority_queue q, size_t index) {
	if (q->first == NULL || index > q->length - 1) {
		return NULL;
	}
	priority_node temp = NULL;
	size_t temp_index = 0;
	size_t first = index;
	size_t last = q->length - index - 1;
	size_t middle;
	if (index < q->middle_index) {
		middle = q->middle_index - index;
	} else {
		middle = index - q->middle_index;
	}
	
	if (q->iterator == NULL || q->iterator_index >= q->length) {
		q->iterator = q->middle;
		q->iterator_index = q->middle_index;
	}
	size_t iterator;
	if (index < q->iterator_index) {
		iterator = q->iterator_index - index;
	} else {
		iterator = index - q->iterator_index;
	}

	if (iterator <= first && iterator <= middle && iterator <= last) {
		temp = q->iterator;
		temp_index = q->iterator_index;
		if (q->iterator_index < index) {
			while (temp_index != index) {
				temp = temp->next;
				++temp_index;
			}
		} else if (q->iterator_index > index) {
			while (temp_index != index) {
				temp = temp->prev;
				--temp_index;
			}
		}
	} else if (first <= middle && first <= last) {
		temp = q->first;
		temp_index = 0;
		while (temp_index != index) {
			temp = temp->next;
			++temp_index;
		}
	} else if (middle <= last) {
		temp = q->middle;
		temp_index = q->middle_index;
		if (q->middle_index < index) {
			while (temp_index != index) {
				temp = temp->next;
				++temp_index;
			}
		} else if (q->middle_index > index) {
			while (temp_index != index) {
				temp = temp->prev;
				--temp_index;
			}
		}
	} else {
		temp = q->last;
		temp_index = q->length - 1;
		while (temp_index != index) {
			temp = temp->prev;
			--temp_index;
		}
	}
	q->iterator = temp;
	q->iterator_index = temp_index;
	return temp;
}

void* priority_queue_peek(priority_queue q) {
	if (priority_queue_length(q) == 0) {
		return NULL;
	}
	return q->first->data;
}

void* priority_queue_dequeue(priority_queue q) {
	void* data = NULL;
	if (priority_queue_length(q) == 0) {
		return data;
	} else if (priority_queue_length(q) == 1) {
		data = q->first->data;
		free(q->first);
		q->middle = NULL;
		q->iterator = NULL;
		q->last = NULL;
		q->middle_index = 0;
		q->iterator_index = 0;
		q->first = NULL;
		--q->length;
		return data;
	}

	priority_node del_el = q->first;

	if (q->iterator_index == 0 && q->iterator != NULL) {
		q->iterator = q->iterator->next;
	} else {
		--q->iterator_index;
	}

	data = del_el->data;
	q->first = q->first->next;
	q->first->prev = NULL;

	if (del_el == q->last) {
		q->last = q->last->prev;
		q->last->next = NULL;
	}

	--q->length;
	--q->middle_index;

	priority_queue_reset_middle(q);
	
	free(del_el);
	return data;
}

size_t priority_queue_length(priority_queue q) {
	return q->length;
}