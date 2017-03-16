#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _queue* queue;

#define queue_enqueue(X, Y) _Generic((Y), \
	char*: queue_enqueue_string, \
	char: queue_enqueue_char, \
	unsigned char: queue_enqueue_uchar, \
	short: queue_enqueue_short, \
	unsigned short: queue_enqueue_ushort, \
	int: queue_enqueue_int, \
	unsigned int: queue_enqueue_uint, \
	long: queue_enqueue_long, \
	unsigned long: queue_enqueue_ulong, \
	long long: queue_enqueue_long_long, \
	unsigned long long: queue_enqueue_ulong_long, \
	float: queue_enqueue_float, \
	double: queue_enqueue_double, \
	long double: queue_enqueue_long_double \
	)(X, Y)

queue new_queue();

void queue_enqueue_generic(queue q, void *data, size_t size);
void queue_enqueue_char(queue q, char data);
void queue_enqueue_uchar(queue q, unsigned char data);
void queue_enqueue_short(queue q, short data);
void queue_enqueue_ushort(queue q, unsigned short data);
void queue_enqueue_int(queue q, int data);
void queue_enqueue_uint(queue q, unsigned int data);
void queue_enqueue_long(queue q, long data);
void queue_enqueue_ulong(queue q, unsigned long data);
void queue_enqueue_long_long(queue q, long long data);
void queue_enqueue_ulong_long(queue q, unsigned long long data);
void queue_enqueue_float(queue q, float data);
void queue_enqueue_double(queue q, double data);
void queue_enqueue_long_double(queue q, long double data);
void queue_enqueue_string(queue q, char *data);

void* queue_dequeue(queue q);
char queue_dequeue_char(queue q);
unsigned char queue_dequeue_uchar(queue q);
short queue_dequeue_short(queue q);
unsigned short queue_dequeue_ushort(queue q);
int queue_dequeue_int(queue q);
unsigned int queue_dequeue_uint(queue q);
long queue_dequeue_long(queue q);
unsigned long queue_dequeue_ulong(queue q);
long long queue_dequeue_long_long(queue q);
unsigned long long queue_dequeue_ulong_long(queue q);
float queue_dequeue_float(queue q);
double queue_dequeue_double(queue q);
long double queue_dequeue_long_double(queue q);
char* queue_dequeue_string(queue q);

void* queue_peek(queue q);
char queue_peek_char(queue q);
unsigned char queue_peek_uchar(queue q);
short queue_peek_short(queue q);
unsigned short queue_peek_ushort(queue q);
int queue_peek_int(queue q);
unsigned int queue_peek_uint(queue q);
long queue_peek_long(queue q);
unsigned long queue_peek_ulong(queue q);
long long queue_peek_long_long(queue q);
unsigned long long queue_peek_ulong_long(queue q);
float queue_peek_float(queue q);
double queue_peek_double(queue q);
long double queue_peek_long_double(queue q);
char* queue_peek_string(queue q);

bool queue_is_empty(queue q);
size_t queue_length(queue q);