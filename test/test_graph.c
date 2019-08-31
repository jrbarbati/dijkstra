#include "vendor/unity.h"
#include "../src/graph.h"
#include <stdlib.h>

void test_graph_add_vertex(void)
{
	vertex n = {'A', NULL, NULL, 1, NULL, 0};
	
	graph *g = calloc(1, sizeof(graph));
	g->vertices = calloc(1, sizeof(vertex));

	add_vertex(g, &n);

	TEST_ASSERT_EQUAL_INT(1, g->size);
	TEST_ASSERT_EQUAL_INT(n.name, g->vertices[0].name);

	free(g->vertices);
	free(g);
}

void test_graph_get_vertex_with_name(void)
{
	vertex *a = initialize_vertex('A', 1);
	vertex *b = initialize_vertex('B', 2);
	vertex *c = initialize_vertex('C', 1);
	
	graph *g = calloc(1, sizeof(graph));
	g->vertices = calloc(3, sizeof(vertex));

	add_edge(a, b, 1);
	add_edge(b, a, 1);
	add_edge(b, c, 1);
	add_edge(c, b, 1);

	add_vertex(g, a);
	add_vertex(g, b);
	add_vertex(g, c);

	vertex wanted = get_vertex_with_name(g, 'B');

	TEST_ASSERT_EQUAL_INT('B', wanted.name);
	TEST_ASSERT_EQUAL_INT(2, wanted.num_of_neighbors);

	free(a);
	free(b);
	free(c);
	free(g->vertices);
	free(g);
}
