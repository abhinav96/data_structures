#include "../include/graph.h"

struct _graph {
	linked_list labels;
	hash_table vertices;
};

struct _vertex {
	void *data;
	short visited;
	linked_list connections;
};

struct _edge {
	char *from;
	char *to;
	void *data;
};

graph new_graph() {
	graph g = malloc(sizeof(*g));
	g->labels = new_linked_list();
	g->vertices = new_hash_table(20);
	return g;
}

vertex new_vertex() {
	vertex vx = malloc(sizeof(*vx));
	vx->visited = 0;
	vx->data = NULL;
	vx->connections = new_linked_list();
	return vx;
}

edge new_edge(char *from, char *to, void *data, size_t size) {
	edge ed = malloc(sizeof(*ed));
	size_t from_size = strlen(from) + 1;
	size_t to_size = strlen(to) + 1;
	char *from_copy = malloc(from_size);
	memcpy(from_copy, from, from_size);
	char *to_copy = malloc(to_size);
	memcpy(to_copy, to, to_size);
	void *data_copy = malloc(size);
	memcpy(data_copy, data, size);
	ed->from = from_copy;
	ed->to = to_copy;
	ed->data = data_copy;
	return ed;
}

void graph_add_vertex(graph g, char *label, void *data, size_t size) {
	if (hash_table_get(g->vertices, label) == NULL) {
		linked_list_add_generic(g->labels, label, strlen(label) + 1);
		vertex vx = new_vertex();
		void *data_copy = malloc(size);
		memcpy(data_copy, data, size);
		vx->data = data_copy;
		hash_table_set(g->vertices, label, vx, sizeof(*vx));
		free(vx);
	}
}

linked_list graph_get_vertices(graph g) {
	return g->labels;
}

void vertex_set_data(graph g, char *label, void *data, size_t size) {
	vertex vx = hash_table_get(g->vertices, label);
	if (vx != NULL) {
		void *data_copy = malloc(size);
		memcpy(data_copy, data, size);
		free(vx->data);
		vx->data = data_copy;
	}
}

void vertex_connect(graph g, char *label1, char *label2, void *data, size_t size) {
	vertex vx1 = hash_table_get(g->vertices, label1);
	vertex vx2 = hash_table_get(g->vertices, label2);
	if (vx1 != NULL && vx2 != NULL) {
		edge ed = new_edge(label1, label2, data, size);
		linked_list_add_generic(vx1->connections, ed, sizeof(*ed));
		free(ed);
	}
}

linked_list vertex_get_edges(graph g, char *label) {
	vertex vx = hash_table_get(g->vertices, label);
	if (vx != NULL) {
		return vx->connections;
	}
	return NULL;
}

void vertex_mark_visited(graph g, char *label) {
	vertex vx = hash_table_get(g->vertices, label);
	if (vx != NULL) {
		vx->visited = 1;
	}
}

void vertex_mark_unvisited(graph g, char *label) {
	vertex vx = hash_table_get(g->vertices, label);
	if (vx != NULL) {
		vx->visited = 0;
	}
}

short vertex_is_visited(graph g, char *label) {
	vertex vx = hash_table_get(g->vertices, label);
	if (vx != NULL) {
		return vx->visited;
	}
	return -1;
}

void edge_set_data(edge ed, void *data, size_t size) {
	void *data_copy = malloc(size);
	memcpy(data_copy, data, size);
	free(ed->data);
	ed->data = data_copy;
}

char* edge_get_to(edge ed) {
	return ed->to;
}

char* edge_get_from(edge ed) {
	return ed->from;
}

void* edge_get_data(edge ed) {
	return ed->data;
}