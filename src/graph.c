#include "../include/graph.h"

struct _graph {
	linked_list labels;
	hash_table vertices;
};

struct _vertex {
	void *data;
	bool visited;
	linked_list connections;
};

struct _edge {
	char *from;
	char *to;
	void *data;
	long long weight;
};

graph new_graph() {
	graph g = malloc(sizeof(*g));
	assert(g != NULL);
	g->labels = new_linked_list();
	g->vertices = new_hash_table(20);
	return g;
}

vertex new_vertex() {
	vertex vx = malloc(sizeof(*vx));
	assert(vx != NULL);
	vx->visited = 0;
	vx->data = NULL;
	vx->connections = new_linked_list();
	return vx;
}

edge new_edge(const char *from, const char *to) {

	edge ed = malloc(sizeof(*ed));
	assert(ed != NULL);
	size_t from_size = strlen(from) + 1;
	size_t to_size = strlen(to) + 1;
	char *from_copy = malloc(from_size);
	assert(from_copy != NULL);
	memcpy(from_copy, from, from_size);
	char *to_copy = malloc(to_size);
	assert(to_copy != NULL);
	memcpy(to_copy, to, to_size);
	ed->from = from_copy;
	ed->to = to_copy;
	ed->data = NULL;
	ed->weight = 0;
	return ed;
}

void graph_add_vertex(graph g, const char *label, const void *data, size_t size) {

	assert(g != NULL);
	assert(label != NULL);

	if (!hash_table_is_set(g->vertices, label)) {
		linked_list_add(g->labels, label);
	}
	vertex vx = new_vertex();
	void *data_copy = malloc(size);
	assert(data_copy != NULL);
	memcpy(data_copy, data, size);
	vx->data = data_copy;
	hash_table_set_generic(g->vertices, label, vx, sizeof(*vx));
	free(vx);
}

linked_list graph_get_vertices(graph g) {
	assert(g != NULL);
	return g->labels;
}

void find_min_distance(graph g, const char *from_label, const char *to_label, long long curr_cost, hash_table lookup) {
	hash_table_set(lookup, from_label, curr_cost);	
	if (strcmp(from_label, to_label) == 0) {
		return;
	}
	linked_list edges = vertex_get_edges(g, from_label);
	edge temp_edge;
	size_t list_length = linked_list_length(edges);
	for (int i = 0; i < list_length; ++i) {
		temp_edge = linked_list_get(edges, i);
		if ((!hash_table_is_set(lookup, edge_get_to(temp_edge)))
			|| hash_table_get_long_long(lookup, edge_get_to(temp_edge)) > curr_cost + edge_get_weight(temp_edge)) {

			find_min_distance(g, edge_get_to(temp_edge), to_label, curr_cost + edge_get_weight(temp_edge), lookup);
		}
	}
	return;
}

long long graph_min_distance(graph g, const char *from_label, const char *to_label) {

	assert(g != NULL);
	assert(from_label != NULL);
	assert(to_label != NULL);

	hash_table lookup = new_hash_table(1.3*linked_list_length(graph_get_vertices(g)));
	find_min_distance(g, from_label, to_label, 0, lookup);
	long long dist = LLONG_MAX;
	if (hash_table_is_set(lookup, to_label)) {
		dist = hash_table_get_long_long(lookup, to_label);
	}
	hash_table_destroy(lookup);
	return dist;
}

void vertex_set_data(graph g, const char *label, const void *data, size_t size) {

	assert(g != NULL);
	assert(label != NULL);

	vertex vx = hash_table_get(g->vertices, label);
	void *data_copy = malloc(size);
	assert(data_copy != NULL);
	memcpy(data_copy, data, size);
	free(vx->data);
	vx->data = data_copy;
}

edge vertex_connect(graph g, const char *from_label, const char *to_label) {

	assert(g != NULL);
	assert(from_label != NULL);
	assert(to_label != NULL);

	vertex vx1 = hash_table_get(g->vertices, from_label);
	edge ed = new_edge(from_label, to_label);
	linked_list_add_generic(vx1->connections, ed, sizeof(*ed));
	free(ed);
	return linked_list_get(vx1->connections, linked_list_length(vx1->connections) - 1);
}

linked_list vertex_get_edges(graph g, const char *label) {

	assert(g != NULL);
	assert(label != NULL);

	vertex vx = hash_table_get(g->vertices, label);
	return vx->connections;
}

void vertex_mark_visited(graph g, const char *label) {

	assert(g != NULL);
	assert(label != NULL);

	vertex vx = hash_table_get(g->vertices, label);
	vx->visited = true;
}

void vertex_mark_unvisited(graph g, const char *label) {
	
	assert(g != NULL);
	assert(label != NULL);

	vertex vx = hash_table_get(g->vertices, label);
	vx->visited = false;
}

bool vertex_is_visited(graph g, const char *label) {
	
	assert(g != NULL);
	assert(label != NULL);

	vertex vx = hash_table_get(g->vertices, label);
	return vx->visited;
}

void edge_set_data(edge ed, const void *data, size_t size) {

	assert(ed != NULL);

	void *data_copy = malloc(size);
	assert(data_copy != NULL);
	memcpy(data_copy, data, size);
	free(ed->data);
	ed->data = data_copy;
}

void edge_set_weight(edge ed, long long weight) {
	assert(ed != NULL);
	ed->weight = weight;
}

long long edge_get_weight(edge ed) {
	assert(ed != NULL);
	return ed->weight;
}

char* edge_get_to(edge ed) {
	assert(ed != NULL);
	return ed->to;
}

char* edge_get_from(edge ed) {
	assert(ed != NULL);
	return ed->from;
}

void* edge_get_data(edge ed) {
	assert(ed != NULL);
	return ed->data;
}