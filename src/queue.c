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

void queue_enqueue_generic(queue q, void *data, size_t size) {
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

void queue_enqueue_char(queue q, char data) {
	queue_enqueue_generic(q, &data, sizeof(data));
}

void queue_enqueue_uchar(queue q, unsigned char data) {
	queue_enqueue_generic(q, &data, sizeof(data));
}

void queue_enqueue_short(queue q, short data) {
	queue_enqueue_generic(q, &data, sizeof(data));
}

void queue_enqueue_ushort(queue q, unsigned short data) {
	queue_enqueue_generic(q, &data, sizeof(data));
}

void queue_enqueue_int(queue q, int data) {
	queue_enqueue_generic(q, &data, sizeof(data));
}

void queue_enqueue_uint(queue q, unsigned int data) {
	queue_enqueue_generic(q, &data, sizeof(data));
}

void queue_enqueue_long(queue q, long data) {
	queue_enqueue_generic(q, &data, sizeof(data));
}

void queue_enqueue_ulong(queue q, unsigned long data) {
	queue_enqueue_generic(q, &data, sizeof(data));
}

void queue_enqueue_long_long(queue q, long long data) {
	queue_enqueue_generic(q, &data, sizeof(data));
}

void queue_enqueue_ulong_long(queue q, unsigned long long data) {
	queue_enqueue_generic(q, &data, sizeof(data));
}

void queue_enqueue_float(queue q, float data) {
	queue_enqueue_generic(q, &data, sizeof(data));
}

void queue_enqueue_double(queue q, double data) {
	queue_enqueue_generic(q, &data, sizeof(data));
}

void queue_enqueue_long_double(queue q, long double data) {
	queue_enqueue_generic(q, &data, sizeof(data));
}

void queue_enqueue_string(queue q, char *data) {
	queue_enqueue_generic(q, data, strlen(data));
}

void* queue_dequeue(queue q) {
	queue_node free_node = q->tail;
	void *data = free_node->data;
	q->tail = q->tail->prev;
	--q->length;
	free(free_node);
	return data;
}

char queue_dequeue_char(queue q) {
	char *data = queue_dequeue(q);
	char return_data = *data;
	free(data);
	return return_data;
}

unsigned char queue_dequeue_uchar(queue q) {
	unsigned char *data = queue_dequeue(q);
	unsigned char return_data = *data;
	free(data);
	return return_data;
}

short queue_dequeue_short(queue q) {
	short *data = queue_dequeue(q);
	short return_data = *data;
	free(data);
	return return_data;
}

unsigned short queue_dequeue_ushort(queue q) {
	unsigned short *data = queue_dequeue(q);
	unsigned short return_data = *data;
	free(data);
	return return_data;
}

int queue_dequeue_int(queue q) {
	int *data = queue_dequeue(q);
	int return_data = *data;
	free(data);
	return return_data;
}

unsigned int queue_dequeue_uint(queue q) {
	unsigned int *data = queue_dequeue(q);
	unsigned int return_data = *data;
	free(data);
	return return_data;
}

long queue_dequeue_long(queue q) {
	long *data = queue_dequeue(q);
	long return_data = *data;
	free(data);
	return return_data;
}

unsigned long queue_dequeue_ulong(queue q) {
	unsigned long *data = queue_dequeue(q);
	unsigned long return_data = *data;
	free(data);
	return return_data;
}

long long queue_dequeue_long_long(queue q) {
	long long *data = queue_dequeue(q);
	long long return_data = *data;
	free(data);
	return return_data;
}

unsigned long long queue_dequeue_ulong_long(queue q) {
	unsigned long long *data = queue_dequeue(q);
	unsigned long long return_data = *data;
	free(data);
	return return_data;
}

float queue_dequeue_float(queue q) {
	float *data = queue_dequeue(q);
	float return_data = *data;
	free(data);
	return return_data;
}

double queue_dequeue_double(queue q) {
	double *data = queue_dequeue(q);
	double return_data = *data;
	free(data);
	return return_data;
}

long double queue_dequeue_long_double(queue q) {
	long double *data = queue_dequeue(q);
	long double return_data = *data;
	free(data);
	return return_data;
}

char* queue_dequeue_string(queue q) {
	return queue_dequeue(q);
}

void* queue_peek(queue q) {
	return q->tail->data;
}

char queue_peek_char(queue q) {
	return *(char *)q->tail->data;
}

unsigned char queue_peek_uchar(queue q) {
	return *(unsigned char *)q->tail->data;
}

short queue_peek_short(queue q) {
	return *(short *)q->tail->data;
}

unsigned short queue_peek_ushort(queue q) {
	return *(unsigned short *)q->tail->data;
}

int queue_peek_int(queue q) {
	return *(int *)q->tail->data;
}

unsigned int queue_peek_uint(queue q) {
	return *(unsigned int *)q->tail->data;
}

long queue_peek_long(queue q) {
	return *(long *)q->tail->data;
}

unsigned long queue_peek_ulong(queue q) {
	return *(unsigned long *)q->tail->data;
}

long long queue_peek_long_long(queue q) {
	return *(long long *)q->tail->data;
}

unsigned long long queue_peek_ulong_long(queue q) {
	return *(unsigned long long *)q->tail->data;
}

float queue_peek_float(queue q) {
	return *(float *)q->tail->data;
}

double queue_peek_double(queue q) {
	return *(double *)q->tail->data;
}

long double queue_peek_long_double(queue q) {
	return *(long double *)q->tail->data;
}

char* queue_peek_string(queue q) {
	return q->tail->data;
}

bool queue_is_empty(queue q) {
	return !queue_length(q);
}

size_t queue_length(queue q) {
	return q->length;
}