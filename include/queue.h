#include <stdlib.h>
#include <string.h>

typedef struct _queue* queue;

queue new_queue();
size_t queue_length(queue q);
void queue_enqueue(queue q, void *data, size_t size);
void* queue_dequeue(queue q);
void* queue_peek(queue q);