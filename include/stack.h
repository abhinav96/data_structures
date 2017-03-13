#include <stdlib.h>
#include <string.h>

typedef struct _stack* stack;

stack new_stack();
size_t stack_size(stack s);
void stack_push(stack s, void *data, size_t size);
void* stack_pop(stack s);
void* stack_peek(stack s);