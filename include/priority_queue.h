#include <stdlib.h>
#include <string.h>

typedef struct _priority_queue* priority_queue;

priority_queue new_priority_queue();
size_t priority_queue_length(priority_queue q);
void priority_queue_enqueue(priority_queue q, void *data, size_t size, long long priority);
void* priority_queue_dequeue(priority_queue q);
void* priority_queue_peek(priority_queue q);