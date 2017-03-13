#include "../include/queue.h"

struct _queue_node {
	struct _queue_node *prev;
	void *data;
};

typedef struct _queue_node* queue_node;

struct _queue {
	queue_node head;
	queue_node tail;
	size_t length;
};

queue_node new_queue_node(void *data, size_t size) {
	queue_node new_qn = malloc(sizeof(*new_qn));
	new_qn->prev = NULL;
	void *data_copy = malloc(size);
	memcpy(data_copy, data, size);
	new_qn->data = data_copy;
	return new_qn;
}

queue new_queue() {
	queue new_q = malloc(sizeof(*new_q));
	new_q->head = NULL;
	new_q->tail = NULL;
	new_q->length = 0;
	return new_q;
}

void queue_enqueue(queue q, void *data, size_t size) {
	queue_node new_qn = new_queue_node(data, size);

	if (queue_length(q) == 0) {
		q->head = new_qn;
		q->tail = new_qn;
	} else {
		q->head->prev = new_qn;
		q->head = q->head->prev;
	}
	++q->length;
	return;
}

void* queue_dequeue(queue q) {
	if (queue_length(q) == 0) {
		return NULL;
	}

	queue_node fr = q->tail;
	void *data = fr->data;
	q->tail = q->tail->prev;
	--q->length;
	free(fr);
	return data;
}

void* queue_peek(queue q) {
	if (queue_length(q) == 0) {
		return NULL;
	}
	return q->tail->data;
}

size_t queue_length(queue q) {
	return q->length;
}