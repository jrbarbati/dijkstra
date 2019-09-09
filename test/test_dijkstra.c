#include "vendor/unity.h"
#include "../src/dijkstra.h"
#include <stdlib.h>

graph *create_graph();
void print_path(linked_list *path);

void test_dijkstra_shortest_path_A_to_C(void)
{
	graph *g = create_graph();
	linked_list *path = shortest_path(g, 'A', 'C');

	TEST_ASSERT_NOT_NULL(path);

	TEST_ASSERT_EQUAL_INT(3, path->size);
	TEST_ASSERT_EQUAL_INT('A', path->head->data);
	TEST_ASSERT_EQUAL_INT('B', path->head->next->data);
	TEST_ASSERT_EQUAL_INT('C', path->head->next->next->data);
}

void test_dijkstra_shortest_path_S_to_M(void)
{
	graph *g = create_graph();
	linked_list *path = shortest_path(g, 'S', 'M');

	TEST_ASSERT_NOT_NULL(path);

	TEST_ASSERT_EQUAL_INT(4, path->size);
	TEST_ASSERT_EQUAL_INT('S', path->head->data);
	TEST_ASSERT_EQUAL_INT('B', path->head->next->data);
	TEST_ASSERT_EQUAL_INT('C', path->head->next->next->data);
	TEST_ASSERT_EQUAL_INT('M', path->head->next->next->next->data);
}

void test_dijkstra_shortest_path_S_to_J(void)
{
	graph *g = create_graph();
	linked_list *path = shortest_path(g, 'S', 'J');

	TEST_ASSERT_NOT_NULL(path);

	TEST_ASSERT_EQUAL_INT(4, path->size);
	TEST_ASSERT_EQUAL_INT('S', path->head->data);
	TEST_ASSERT_EQUAL_INT('A', path->head->next->data);
	TEST_ASSERT_EQUAL_INT('E', path->head->next->next->data);
	TEST_ASSERT_EQUAL_INT('J', path->head->next->next->next->data);
}

void test_dijkstra_shortest_path_N_to_G(void)
{
	graph *g = create_graph();
	linked_list *path = shortest_path(g, 'N', 'G');

	TEST_ASSERT_NOT_NULL(path);

	TEST_ASSERT_EQUAL_INT(10, path->size);
	TEST_ASSERT_EQUAL_INT('N', path->head->data);
	TEST_ASSERT_EQUAL_INT('L', path->head->next->data);
	TEST_ASSERT_EQUAL_INT('M', path->head->next->next->data);
	TEST_ASSERT_EQUAL_INT('C', path->head->next->next->next->data);
	TEST_ASSERT_EQUAL_INT('B', path->head->next->next->next->next->data);
	TEST_ASSERT_EQUAL_INT('A', path->head->next->next->next->next->next->data);
	TEST_ASSERT_EQUAL_INT('E', path->head->next->next->next->next->next->next->data);
	TEST_ASSERT_EQUAL_INT('H', path->head->next->next->next->next->next->next->next->data);
	TEST_ASSERT_EQUAL_INT('F', path->head->next->next->next->next->next->next->next->next->data);
	TEST_ASSERT_EQUAL_INT('G', path->head->next->next->next->next->next->next->next->next->next->data);
}

void test_dijkstra_shortest_path_from_S_to_Z(void)
{
	graph *g = create_graph();
	linked_list *path = shortest_path(g, 'S', 'Z');

	TEST_ASSERT_NOT_NULL(path)

	TEST_ASSERT_EQUAL_INT(5, path->size);
	TEST_ASSERT_EQUAL_INT('S', path->head->data);
	TEST_ASSERT_EQUAL_INT('A', path->head->next->data);
	TEST_ASSERT_EQUAL_INT('E', path->head->next->next->data);
	TEST_ASSERT_EQUAL_INT('K', path->head->next->next->next->data);
	TEST_ASSERT_EQUAL_INT('Z', path->head->next->next->next->next->data);

}

void test_dijstra_build_path(void)
{
	vertex start = {'S', NULL, NULL, 0, NULL, 0};
	vertex a = {'A', NULL, NULL, 0, &start, 1};
	vertex b = {'B', NULL, NULL, 0, &a, 2};
	vertex c = {'C', NULL, NULL, 0, &b, 3};

	linked_list *path = build_path(&c);

	TEST_ASSERT_EQUAL_INT(4, path->size);
	TEST_ASSERT_EQUAL_INT('S', path->head->data);
	TEST_ASSERT_EQUAL_INT('A', path->head->next->data);
	TEST_ASSERT_EQUAL_INT('B', path->head->next->next->data);
	TEST_ASSERT_EQUAL_INT('C', path->head->next->next->next->data);
}

graph *create_graph()
{
	graph *g = calloc(1, sizeof(graph));
	g->vertices = calloc(MAX_NUM_OF_VERTICES, sizeof(vertex));

	vertex *start = initialize_vertex('S', 3);
	vertex *A = initialize_vertex('A', 4);
	vertex *B = initialize_vertex('B', 3);
	vertex *C = initialize_vertex('C', 4);
	vertex *D = initialize_vertex('D', 1);
	vertex *E = initialize_vertex('E', 4);
	vertex *F = initialize_vertex('F', 3);
	vertex *G = initialize_vertex('G', 1);
	vertex *H = initialize_vertex('H', 3);
	vertex *I = initialize_vertex('I', 2);
	vertex *J = initialize_vertex('J', 3);
	vertex *K = initialize_vertex('K', 3);
	vertex *L = initialize_vertex('L', 3);
	vertex *M = initialize_vertex('M', 3);
	vertex *N = initialize_vertex('N', 3);
	vertex *end = initialize_vertex('Z', 3);

	add_edge(start, A, 2);
	add_edge(start, B, 1);
	add_edge(start, F, 10);
	add_edge(A, start, 2);
	add_edge(A, B, 2);
	add_edge(A, C, 5);
	add_edge(A, E, 1);
	add_edge(B, start, 1);
	add_edge(B, A, 2);
	add_edge(B, C, 1);
	add_edge(C, A, 5);
	add_edge(C, B, 1);
	add_edge(C, D, 3);
	add_edge(C, M, 7);
	add_edge(D, C, 3);
	add_edge(E, A, 1);
	add_edge(E, H, 1);
	add_edge(E, J, 8);
	add_edge(E, K, 9);
	add_edge(F, start, 10);
	add_edge(F, G, 4);
	add_edge(F, H, 1);
	add_edge(G, F, 4);
	add_edge(H, E, 1);
	add_edge(H, F, 1);
	add_edge(H, I, 5);
	add_edge(I, H, 5);
	add_edge(I, J, 6);
	add_edge(J, E, 8);
	add_edge(J, I, 6);
	add_edge(J, end, 13);
	add_edge(K, E, 9);
	add_edge(K, L, 4);
	add_edge(K, end, 7);
	add_edge(L, K, 4);
	add_edge(L, M, 1);
	add_edge(L, N, 2);
	add_edge(M, C, 7);
	add_edge(M, L, 1);
	add_edge(M, N, 6);
	add_edge(N, L, 2);
	add_edge(N, M, 6);
	add_edge(N, end, 7);
	add_edge(end, J, 13);
	add_edge(end, K, 7);
	add_edge(end, N, 7);

	add_vertex(g, start);
	add_vertex(g, A);
	add_vertex(g, B);
	add_vertex(g, C);
	add_vertex(g, D);
	add_vertex(g, E);
	add_vertex(g, F);
	add_vertex(g, G);
	add_vertex(g, H);
	add_vertex(g, I);
	add_vertex(g, J);
	add_vertex(g, K);
	add_vertex(g, L);
	add_vertex(g, M);
	add_vertex(g, N);
	add_vertex(g, end);

	return g;
}

void print_path(linked_list *path)
{
	linked_node *curr_node = path->head;

	while (curr_node->next != NULL)
	{
		printf("%c -> ", curr_node->data);
		curr_node = curr_node->next;
	}

	printf("%c\n", curr_node->data);
}
