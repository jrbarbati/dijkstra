#include "vendor/unity.h"
#include "../src/binary_heap.h"
#include <stdlib.h>

void test_binary_heap_initialize_heap(void)
{
	binary_heap *bh = initialize_heap();

	TEST_ASSERT_EQUAL_INT(21, sizeof(bh->vertices) / sizeof(void *));
	TEST_ASSERT_EQUAL_INT(0, bh->size);

	free(bh);
}

void test_binary_heap_push(void)
{
	vertex n = {'A', NULL, NULL, 0, NULL, 2};
	binary_heap *bh = initialize_heap();

	push(bh, &n);

	TEST_ASSERT_EQUAL_INT(1, bh->size);
	TEST_ASSERT_EQUAL_INT(2, bh->vertices[1]->distance_from_start);
	TEST_ASSERT_EQUAL_INT('A', bh->vertices[1]->name);

	free(bh);
}

void test_binary_heap_push_multiple(void)
{
	vertex a = {'A', NULL, NULL, 1, NULL, 2};
	vertex b = {'B', NULL, NULL, 2, NULL, 5};
	vertex c = {'C', NULL, NULL, 3, NULL, 1};
	binary_heap *bh = initialize_heap();

	push(bh, &a);
	push(bh, &b);
	push(bh, &c);

	TEST_ASSERT_EQUAL_INT(3, bh->size);

	TEST_ASSERT_EQUAL_INT('C', bh->vertices[1]->name);
	TEST_ASSERT_EQUAL_INT(1, bh->vertices[1]->distance_from_start);
	TEST_ASSERT_EQUAL_INT(3, bh->vertices[1]->num_of_neighbors);

	TEST_ASSERT_EQUAL_INT('B', bh->vertices[2]->name);
	TEST_ASSERT_EQUAL_INT(5, bh->vertices[2]->distance_from_start);
	TEST_ASSERT_EQUAL_INT(2, bh->vertices[2]->num_of_neighbors);

	TEST_ASSERT_EQUAL_INT('A', bh->vertices[3]->name);
	TEST_ASSERT_EQUAL_INT(2, bh->vertices[3]->distance_from_start);
	TEST_ASSERT_EQUAL_INT(1, bh->vertices[3]->num_of_neighbors);


	free(bh);
}

void test_binary_heap_push_multiple_duplicate_priority_values(void)
{
	vertex a = {'A', NULL, NULL, 0, NULL, 2};
	vertex b = {'B', NULL, NULL, 0, NULL, 5};
	vertex c = {'C', NULL, NULL, 0, NULL, 1};
	vertex d = {'D', NULL, NULL, 0, NULL, 2};
	binary_heap *bh = initialize_heap();

	push(bh, &a);
	push(bh, &b);
	push(bh, &c);
	push(bh, &d);

	TEST_ASSERT_EQUAL_INT(4, bh->size);

	TEST_ASSERT_EQUAL_INT('C', bh->vertices[1]->name);
	TEST_ASSERT_EQUAL_INT(1, bh->vertices[1]->distance_from_start);

	TEST_ASSERT_EQUAL_INT('D', bh->vertices[2]->name);
	TEST_ASSERT_EQUAL_INT(2, bh->vertices[2]->distance_from_start);

	TEST_ASSERT_EQUAL_INT('A', bh->vertices[3]->name);
	TEST_ASSERT_EQUAL_INT(2, bh->vertices[3]->distance_from_start);

	TEST_ASSERT_EQUAL_INT('B', bh->vertices[4]->name);
	TEST_ASSERT_EQUAL_INT(5, bh->vertices[4]->distance_from_start);

	free(bh);
}

void test_binary_heap_push_already_exists(void)
{
	vertex a = {'A', NULL, NULL, 0, NULL, 2};
	vertex b = {'B', NULL, NULL, 0, NULL, 5};
	vertex c = {'C', NULL, NULL, 0, NULL, 1};
	vertex d = {'D', NULL, NULL, 0, NULL, 4};
	vertex b_dup = {'B', NULL, NULL, 0, NULL, 3};
	binary_heap *bh = initialize_heap();

	push(bh, &a);
	push(bh, &b);
	push(bh, &c);
	push(bh, &d);

	TEST_ASSERT_EQUAL_INT(4, bh->size);

	TEST_ASSERT_EQUAL_INT('C', bh->vertices[1]->name);
	TEST_ASSERT_EQUAL_INT(1, bh->vertices[1]->distance_from_start);

	TEST_ASSERT_EQUAL_INT('D', bh->vertices[2]->name);
	TEST_ASSERT_EQUAL_INT(4, bh->vertices[2]->distance_from_start);

	TEST_ASSERT_EQUAL_INT('A', bh->vertices[3]->name);
	TEST_ASSERT_EQUAL_INT(2, bh->vertices[3]->distance_from_start);

	TEST_ASSERT_EQUAL_INT('B', bh->vertices[4]->name);
	TEST_ASSERT_EQUAL_INT(5, bh->vertices[4]->distance_from_start);


	push(bh, &b_dup);

	TEST_ASSERT_EQUAL_INT(5, bh->size);

	TEST_ASSERT_EQUAL_INT('C', bh->vertices[1]->name);
	TEST_ASSERT_EQUAL_INT(1, bh->vertices[1]->distance_from_start);

	TEST_ASSERT_EQUAL_INT('B', bh->vertices[2]->name);
	TEST_ASSERT_EQUAL_INT(3, bh->vertices[2]->distance_from_start);

	TEST_ASSERT_EQUAL_INT('A', bh->vertices[3]->name);
	TEST_ASSERT_EQUAL_INT(2, bh->vertices[3]->distance_from_start);

	TEST_ASSERT_EQUAL_INT('B', bh->vertices[4]->name);
	TEST_ASSERT_EQUAL_INT(5, bh->vertices[4]->distance_from_start);

	TEST_ASSERT_EQUAL_INT('D', bh->vertices[5]->name);
	TEST_ASSERT_EQUAL_INT(4, bh->vertices[5]->distance_from_start);


	free(bh);
}

void test_binary_heap_pop_empty(void)
{
	binary_heap *bh = initialize_heap();

	vertex *popped = pop(bh);

	TEST_ASSERT_NULL(popped);

	free(bh);
}

void test_binary_heap_pop(void)
{	
	vertex a = {'A', NULL, NULL, 0, NULL, 2};
	vertex b = {'B', NULL, NULL, 0, NULL, 5};
	vertex c = {'C', NULL, NULL, 0, NULL, 1};
	vertex *popped;
	binary_heap *bh = initialize_heap();

	push(bh, &a);
	push(bh, &b);
	push(bh, &c);

	popped = pop(bh);

	TEST_ASSERT_EQUAL_INT('C', popped->name);

	TEST_ASSERT_EQUAL_INT(2, bh->size);

	TEST_ASSERT_EQUAL_INT('A', bh->vertices[1]->name);
	TEST_ASSERT_EQUAL_INT(2, bh->vertices[1]->distance_from_start);

	TEST_ASSERT_EQUAL_INT('B', bh->vertices[2]->name);
	TEST_ASSERT_EQUAL_INT(5, bh->vertices[2]->distance_from_start);

	popped = pop(bh);

	TEST_ASSERT_EQUAL_INT('A', popped->name);

	TEST_ASSERT_EQUAL_INT(1, bh->size);
		
	TEST_ASSERT_EQUAL_INT('B', bh->vertices[1]->name);
	TEST_ASSERT_EQUAL_INT(5, bh->vertices[1]->distance_from_start);

	free(popped);
	free(bh);
}
