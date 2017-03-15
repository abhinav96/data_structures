#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _stack* stack;

stack new_stack();

void stack_push(stack s, void *data, size_t size);
void stack_push_char(stack s, char c);
void stack_push_uchar(stack s, unsigned char c);
void stack_push_short(stack s, short si);
void stack_push_ushort(stack s, unsigned short si);
void stack_push_int(stack s, int i);
void stack_push_uint(stack s, unsigned int i);
void stack_push_long(stack s, long l);
void stack_push_ulong(stack s, unsigned long l);
void stack_push_long_long(stack s, long long ll);
void stack_push_ulong_long(stack s, unsigned long long ll);
void stack_push_float(stack s, float f);
void stack_push_double(stack s, double d);
void stack_push_long_double(stack s, long double ld);
void stack_push_string(stack s, char *str);

void* stack_pop(stack s);
char stack_pop_char(stack s);
unsigned char stack_pop_uchar(stack s);
short stack_pop_short(stack s);
unsigned short stack_pop_ushort(stack s);
int stack_pop_int(stack s);
unsigned int stack_pop_uint(stack s);
long stack_pop_long(stack s);
unsigned long stack_pop_ulong(stack s);
long long stack_pop_long_long(stack s);
unsigned long long stack_pop_ulong_long(stack s);
float stack_pop_float(stack s);
double stack_pop_double(stack s);
long double stack_pop_long_double(stack s);
char* stack_pop_string(stack s);

void* stack_peek(stack s);
char stack_peek_char(stack s);
unsigned char stack_peek_uchar(stack s);
short stack_peek_short(stack s);
unsigned short stack_peek_ushort(stack s);
int stack_peek_int(stack s);
unsigned int stack_peek_uint(stack s);
long stack_peek_long(stack s);
unsigned long stack_peek_ulong(stack s);
long long stack_peek_long_long(stack s);
unsigned long long stack_peek_ulong_long(stack s);
float stack_peek_float(stack s);
double stack_peek_double(stack s);
long double stack_peek_long_double(stack s);
char* stack_peek_string(stack s);

bool stack_is_empty(stack s);
size_t stack_size(stack s);