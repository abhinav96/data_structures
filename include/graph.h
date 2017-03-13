#include "hash_table.h"

typedef struct _graph* graph;
typedef struct _vertex* vertex;
typedef struct _edge* edge;

graph new_graph();
void graph_add_vertex(graph g, char *label, void *data, size_t size);
linked_list graph_get_vertices(graph g);

void vertex_set_data(graph g, char *label, void *data, size_t size);
void vertex_connect(graph g, char *label1, char *label2, void *data, size_t size);
linked_list vertex_get_edges(graph g, char *label);
void vertex_mark_visited(graph g, char *label);
void vertex_mark_unvisited(graph g, char *label);
short vertex_is_visited(graph g, char *label);

void edge_set_data(edge ed, void *data, size_t size);
char* edge_get_to(edge ed);
char* edge_get_from(edge ed);
void* edge_get_data(edge ed);