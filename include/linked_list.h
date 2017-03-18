#include <stdlib.h>
#include <string.h>

typedef struct _linked_list* linked_list;

linked_list new_linked_list();

void linked_list_add(linked_list list, void *data, size_t size);

void linked_list_add_at(linked_list list, void *data, size_t size, size_t index);

void* linked_list_get(linked_list list, size_t index);

void* linked_list_remove(linked_list list, size_t index);
char linked_list_remove_char(linked_list list, size_t index);
unsigned char linked_list_remove_uchar(linked_list list, size_t index);
short linked_list_remove_short(linked_list list, size_t index);
unsigned short linked_list_remove_ushort(linked_list list, size_t index);
int linked_list_remove_int(linked_list list, size_t index);
unsigned int linked_list_remove_uint(linked_list list, size_t index);
long linked_list_remove_long(linked_list list, size_t index);
unsigned long linked_list_remove_ulong(linked_list list, size_t index);
long long linked_list_remove_long_long(linked_list list, size_t index);
unsigned long long linked_list_remove_ulong_long(linked_list list, size_t index);
float linked_list_remove_float(linked_list list, size_t index);
double linked_list_remove_double(linked_list list, size_t index);
long double linked_list_remove_long_double(linked_list list, size_t index);
char* linked_list_remove_string(linked_list list, size_t index);

size_t linked_list_length(linked_list list);