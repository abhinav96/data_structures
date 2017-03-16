#include "../include/stack.h"

struct _stack_node {
	struct _stack_node *next;
	void *data;
};

typedef struct _stack_node* stack_node;

struct _stack {
	stack_node head;
	size_t size;
};

stack_node new_stack_node(void *data, size_t size) {
	stack_node new_stn = malloc(sizeof(*new_stn));
	new_stn->next = NULL;
	void *data_copy = malloc(size);
	memcpy(data_copy, data, size);
	new_stn->data = data_copy;
	return new_stn;
}

stack new_stack() {
	stack new_s = malloc(sizeof(*new_s));
	new_s->head = NULL;
	new_s->size = 0;
	return new_s;
}

void stack_push_generic(stack s, void *data, size_t size) {
	stack_node new_stn = new_stack_node(data, size);
	new_stn->next = s->head;
	s->head = new_stn;
	++s->size;
}

void stack_push_char(stack s, char data) {
	stack_push_generic(s, &data, sizeof(data));
}

void stack_push_uchar(stack s, unsigned char data) {
	stack_push_generic(s, &data, sizeof(data));
}

void stack_push_short(stack s, short data) {
	stack_push_generic(s, &data, sizeof(data));
}

void stack_push_ushort(stack s, unsigned short data) {
	stack_push_generic(s, &data, sizeof(data));
}

void stack_push_int(stack s, int data) {
	stack_push_generic(s, &data, sizeof(data));
}

void stack_push_uint(stack s, unsigned int data) {
	stack_push_generic(s, &data, sizeof(data));
}

void stack_push_long(stack s, long data) {
	stack_push_generic(s, &data, sizeof(data));
}

void stack_push_ulong(stack s, unsigned long data) {
	stack_push_generic(s, &data, sizeof(data));
}

void stack_push_long_long(stack s, long long data) {
	stack_push_generic(s, &data, sizeof(data));
}

void stack_push_ulong_long(stack s, unsigned long long data) {
	stack_push_generic(s, &data, sizeof(data));
}

void stack_push_float(stack s, float data) {
	stack_push_generic(s, &data, sizeof(data));
}

void stack_push_double(stack s, double data) {
	stack_push_generic(s, &data, sizeof(data));
}

void stack_push_long_double(stack s, long double data) {
	stack_push_generic(s, &data, sizeof(data));
}

void stack_push_string(stack s, char *data) {
	stack_push_generic(s, data, strlen(data));
}

void* stack_pop(stack s) {
	stack_node free_node = s->head;
	void *data = free_node->data;
	s->head = s->head->next;
	--s->size;
	free(free_node);
	return data;
}

char stack_pop_char(stack s) {
	char *data = stack_pop(s);
	char return_data = *data;
	free(data);
	return return_data;
}

unsigned char stack_pop_uchar(stack s) {
	unsigned char *data = stack_pop(s);
	unsigned char return_data = *data;
	free(data);
	return return_data;
}

short stack_pop_short(stack s) {
	short *data = stack_pop(s);
	short return_data = *data;
	free(data);
	return return_data;
}

unsigned short stack_pop_ushort(stack s) {
	unsigned short *data = stack_pop(s);
	unsigned short return_data = *data;
	free(data);
	return return_data;
}

int stack_pop_int(stack s) {
	int *data = stack_pop(s);
	int return_data = *data;
	free(data);
	return return_data;
}

unsigned int stack_pop_uint(stack s) {
	unsigned int *data = stack_pop(s);
	unsigned int return_data = *data;
	free(data);
	return return_data;
}

long stack_pop_long(stack s) {
	long *data = stack_pop(s);
	long return_data = *data;
	free(data);
	return return_data;
}

unsigned long stack_pop_ulong(stack s) {
	unsigned long *data = stack_pop(s);
	unsigned long return_data = *data;
	free(data);
	return return_data;
}

long long stack_pop_long_long(stack s) {
	long long *data = stack_pop(s);
	long long return_data = *data;
	free(data);
	return return_data;
}

unsigned long long stack_pop_ulong_long(stack s) {
	unsigned long long *data = stack_pop(s);
	unsigned long long return_data = *data;
	free(data);
	return return_data;
}

float stack_pop_float(stack s) {
	float *data = stack_pop(s);
	float return_data = *data;
	free(data);
	return return_data;
}

double stack_pop_double(stack s) {
	double *data = stack_pop(s);
	double return_data = *data;
	free(data);
	return return_data;
}

long double stack_pop_long_double(stack s) {
	long double *data = stack_pop(s);
	long double return_data = *data;
	free(data);
	return return_data;
}

char* stack_pop_string(stack s) {
	return stack_pop(s);
}

void* stack_peek(stack s) {
	return s->head->data;
}

char stack_peek_char(stack s) {
	return *(char *)s->head->data;
}

unsigned char stack_peek_uchar(stack s) {
	return *(unsigned char *)s->head->data;
}

short stack_peek_short(stack s) {
	return *(short *)s->head->data;
}

unsigned short stack_peek_ushort(stack s) {
	return *(unsigned short *)s->head->data;
}

int stack_peek_int(stack s) {
	return *(int *)s->head->data;
}

unsigned int stack_peek_uint(stack s) {
	return *(unsigned int *)s->head->data;
}

long stack_peek_long(stack s) {
	return *(long *)s->head->data;
}

unsigned long stack_peek_ulong(stack s) {
	return *(unsigned long *)s->head->data;
}

long long stack_peek_long_long(stack s) {
	return *(long long *)s->head->data;
}

unsigned long long stack_peek_ulong_long(stack s) {
	return *(unsigned long long *)s->head->data;
}

float stack_peek_float(stack s) {
	return *(float *)s->head->data;
}

double stack_peek_double(stack s) {
	return *(double *)s->head->data;
}

long double stack_peek_long_double(stack s) {
	return *(long double *)s->head->data;
}

char* stack_peek_string(stack s) {
	return s->head->data;
}

bool stack_is_empty(stack s) {
	return !stack_size(s);
}

size_t stack_size(stack s) {
	return s->size;
}