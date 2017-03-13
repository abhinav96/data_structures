#include <stdlib.h>
#include <string.h>

typedef struct _linked_list* linked_list;

linked_list new_linked_list();
size_t linked_list_length(linked_list list);
void linked_list_add(linked_list list, void *data, size_t size);
void linked_list_add_at(linked_list list, void *data, size_t size, size_t index);
void* linked_list_get(linked_list list, size_t index);
void* linked_list_remove(linked_list list, size_t index);