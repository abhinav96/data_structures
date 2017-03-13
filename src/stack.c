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

void stack_push(stack s, void *data, size_t size) {
	stack_node new_stn = new_stack_node(data, size);
	new_stn->next = s->head;
	s->head = new_stn;
	++s->size;
}

void* stack_pop(stack s) {
	if (stack_size(s) == 0) {
		return NULL;
	}
	stack_node fr = s->head;
	void *data = fr->data;
	s->head = s->head->next;
	--s->size;
	free(fr);
	return data;
}

size_t stack_size(stack s) {
	return s->size;
}

void* stack_peek(stack s) {
	if (stack_size(s) == 0) {
		return NULL;
	}
	return s->head->data;
}