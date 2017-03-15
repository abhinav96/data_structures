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

void stack_push_char(stack s, char c) {
	stack_push(s, &c, sizeof(char));
}

void stack_push_uchar(stack s, unsigned char c) {
	stack_push(s, &c, sizeof(unsigned char));
}

void stack_push_short(stack s, short si) {
	stack_push(s, &si, sizeof(short));
}

void stack_push_ushort(stack s, unsigned short si) {
	stack_push(s, &si, sizeof(unsigned short));
}

void stack_push_int(stack s, int i) {
	stack_push(s, &i, sizeof(int));
}

void stack_push_uint(stack s, unsigned int i) {
	stack_push(s, &i, sizeof(unsigned int));
}

void stack_push_long(stack s, long l) {
	stack_push(s, &l, sizeof(long));
}

void stack_push_ulong(stack s, unsigned long l) {
	stack_push(s, &l, sizeof(unsigned long));
}

void stack_push_long_long(stack s, long long ll) {
	stack_push(s, &ll, sizeof(long long));
}

void stack_push_ulong_long(stack s, unsigned long long ll) {
	stack_push(s, &ll, sizeof(unsigned long long));
}

void stack_push_float(stack s, float f) {
	stack_push(s, &f, sizeof(float));
}

void stack_push_double(stack s, double d) {
	stack_push(s, &d, sizeof(double));
}

void stack_push_long_double(stack s, long double ld) {
	stack_push(s, &ld, sizeof(long double));
}

void stack_push_string(stack s, char *str) {
	stack_push(s, str, strlen(str));
}

void* stack_pop(stack s) {
	stack_node fr = s->head;
	void *data = fr->data;
	s->head = s->head->next;
	--s->size;
	free(fr);
	return data;
}

char stack_pop_char(stack s) {
	char *c = stack_pop(s);
	char return_char = *c;
	free(c);
	return return_char;
}

unsigned char stack_pop_uchar(stack s) {
	unsigned char *c = stack_pop(s);
	unsigned char return_char = *c;
	free(c);
	return return_char;
}

short stack_pop_short(stack s) {
	short *sh = stack_pop(s);
	short return_short = *sh;
	free(sh);
	return return_short;
}

unsigned short stack_pop_ushort(stack s) {
	unsigned short *sh = stack_pop(s);
	unsigned short return_short = *sh;
	free(sh);
	return return_short;
}

int stack_pop_int(stack s) {
	int *i = stack_pop(s);
	int return_int = *i;
	free(i);
	return return_int;
}

unsigned int stack_pop_uint(stack s) {
	unsigned int *i = stack_pop(s);
	unsigned int return_int = *i;
	free(i);
	return return_int;
}

long stack_pop_long(stack s) {
	long *l = stack_pop(s);
	long return_long = *l;
	free(l);
	return return_long;
}

unsigned long stack_pop_ulong(stack s) {
	unsigned long *l = stack_pop(s);
	unsigned long return_long = *l;
	free(l);
	return return_long;
}

long long stack_pop_long_long(stack s) {
	long long *ll = stack_pop(s);
	long long return_long_long = *ll;
	free(ll);
	return return_long_long;
}

unsigned long long stack_pop_ulong_long(stack s) {
	unsigned long long *ll = stack_pop(s);
	unsigned long long return_long_long = *ll;
	free(ll);
	return return_long_long;
}

float stack_pop_float(stack s) {
	float *fl = stack_pop(s);
	float return_float = *fl;
	free(fl);
	return return_float;
}

double stack_pop_double(stack s) {
	double *d = stack_pop(s);
	double return_double = *d;
	free(d);
	return return_double;
}

long double stack_pop_long_double(stack s) {
	long double *ld = stack_pop(s);
	long double return_long_double = *ld;
	free(ld);
	return return_long_double;
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