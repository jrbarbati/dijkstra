#include "vendor/unity.h"
#include "../src/vertex.h"
#include <stdlib.h>

void test_vertex_initialize_vertex(void)
{
	vertex expected = {'A', NULL, NULL, 1, NULL, 0};
	vertex *actual = initialize_vertex('A', 1);

	TEST_ASSERT_EQUAL_INT(expected.name, actual->name);

	free(actual->neighbors);
	free(actual->weights);
	free(actual);
}

void test_vertex_add_edge(void)
{
	vertex *source = initialize_vertex('A', 1);
	vertex *target = initialize_vertex('B', 1);

	add_edge(source, target, 10);

	TEST_ASSERT_EQUAL_INT(1, source->num_of_neighbors);
	TEST_ASSERT_EQUAL_INT(target->name, source->neighbors[0].name);
	TEST_ASSERT_EQUAL_INT(10, source->weights[0]);

	free(source->neighbors);
	free(source->weights);
	free(source->parent);
	free(source);
	free(target->neighbors);
	free(target->weights);
	free(target->parent);
	free(target);
}

void test_vertex_parent_relationship(void)
{
	vertex *child = initialize_vertex('A', 1);
	vertex *parent = initialize_vertex('B', 1);

	set_parent(child, parent);

	TEST_ASSERT_EQUAL_INT('B', child->parent->name);

	free(child->neighbors);
	free(child->weights);
	free(child->parent);
	free(child);
	free(parent->neighbors);
	free(parent->weights);
	free(parent->parent);
	free(parent);
}
