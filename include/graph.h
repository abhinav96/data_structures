#include "hash_table.h"

typedef struct _graph* graph;
typedef struct _vertex* vertex;
typedef struct _edge* edge;

graph new_graph();
void graph_add_vertex(graph g, const char *label, const void *data, size_t size);
linked_list graph_get_vertices(graph g);

void vertex_set_data(graph g, const char *label, const void *data, size_t size);
edge vertex_connect(graph g, const char *from_label, const char *to_label);
linked_list vertex_get_edges(graph g, const char *label);
void vertex_mark_visited(graph g, const char *label);
void vertex_mark_unvisited(graph g, const char *label);
bool vertex_is_visited(graph g, const char *label);

void edge_set_data(edge ed, const void *data, size_t size);
void edge_set_weight(edge ed, long long weight);
long long edge_get_weight(edge ed);
char* edge_get_to(edge ed);
char* edge_get_from(edge ed);
void* edge_get_data(edge ed);

long long graph_min_distance(graph g, const char *from_label, const char *to_label);