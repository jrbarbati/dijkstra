#include "vendor/unity.h"

extern void test_vertex_initialize_vertex(void);
extern void test_vertex_add_edge(void);
extern void test_graph_add_vertex(void);
extern void test_graph_get_vertex_with_name(void);
extern void test_dijkstra_shortest_path_A_to_C(void);
extern void test_dijkstra_shortest_path_S_to_M(void);
extern void test_dijkstra_shortest_path_S_to_J(void);
extern void test_dijkstra_shortest_path_N_to_G(void);
extern void test_dijkstra_shortest_path_from_S_to_Z(void);
extern void test_dijstra_build_path(void);
extern void test_binary_heap_initialize_heap(void);
extern void test_binary_heap_push(void);
extern void test_binary_heap_push_multiple(void);
extern void test_binary_heap_push_multiple_duplicate_priority_values(void);
extern void test_binary_heap_pop_empty(void);
extern void test_binary_heap_pop(void);
extern void test_linked_list_add_to_head_empty(void);
extern void test_linked_list_add_to_head_multiple(void);
extern void test_linked_list_add_to_tail_empty(void);
extern void test_linked_list_add_to_tail_multiple(void);
extern void test_linked_list_replace_head(void);
extern void test_linked_list_replace_tail(void);
extern void test_linked_list_contains(void);

void setUp(void) {}

void tearDown(void) {}

int main()
{
	UnityBegin("test/tests.c");

	RUN_TEST(test_vertex_initialize_vertex);
	RUN_TEST(test_vertex_add_edge);
	RUN_TEST(test_graph_add_vertex);
	RUN_TEST(test_graph_get_vertex_with_name);
	RUN_TEST(test_dijkstra_shortest_path_A_to_C);
	RUN_TEST(test_dijkstra_shortest_path_S_to_M);
	RUN_TEST(test_dijkstra_shortest_path_S_to_J);
	RUN_TEST(test_dijkstra_shortest_path_N_to_G);
	RUN_TEST(test_dijkstra_shortest_path_from_S_to_Z);
	RUN_TEST(test_dijstra_build_path);
	RUN_TEST(test_binary_heap_initialize_heap);
	RUN_TEST(test_binary_heap_push);
	RUN_TEST(test_binary_heap_push_multiple);
	RUN_TEST(test_binary_heap_push_multiple_duplicate_priority_values);
	RUN_TEST(test_binary_heap_pop_empty);
	RUN_TEST(test_binary_heap_pop);
	RUN_TEST(test_linked_list_add_to_head_empty);
	RUN_TEST(test_linked_list_add_to_head_multiple);
	RUN_TEST(test_linked_list_add_to_tail_empty);
	RUN_TEST(test_linked_list_add_to_tail_multiple);
	RUN_TEST(test_linked_list_replace_head);
	RUN_TEST(test_linked_list_replace_tail);
	RUN_TEST(test_linked_list_contains);

	return UnityEnd();
}
