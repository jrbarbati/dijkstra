#include "vendor/unity.h"
#include "../src/linked_list.h"
#include <stdlib.h>

void test_linked_list_add_to_head_empty(void)
{
	vertex n = {'A', NULL, NULL, 0, NULL, 0};
	linked_list *list = calloc(1, sizeof(linked_list));

	add_to_head(list, &n);

	TEST_ASSERT_EQUAL_INT(1, list->size);
	TEST_ASSERT_EQUAL_INT('A', list->head->data->name);
	TEST_ASSERT_EQUAL_INT('A', list->tail->data->name);

	free(list);
}

void test_linked_list_add_to_head_multiple(void)
{
	vertex a = {'A', NULL, NULL, 0, NULL, 0};
	vertex b = {'B', NULL, NULL, 0, NULL, 0};
	vertex c = {'C', NULL, NULL, 0, NULL, 0};
	linked_list *list = calloc(1, sizeof(linked_list));

	add_to_head(list, &a);
	add_to_head(list, &b);
	add_to_head(list, &c);

	TEST_ASSERT_EQUAL_INT(3, list->size);
	TEST_ASSERT_EQUAL_INT('C', list->head->data->name);
	TEST_ASSERT_EQUAL_INT('B', list->head->next->data->name);
	TEST_ASSERT_EQUAL_INT('A', list->head->next->next->data->name);

	for (linked_node *curr_node = list->tail->prev; curr_node->prev != NULL; curr_node = curr_node->prev)
		free(curr_node->next);

	free(list);
}

void test_linked_list_add_to_tail_empty(void)
{
	vertex n = {'A', NULL, NULL, 0, NULL, 0};
	linked_list *list = calloc(1, sizeof(linked_list));

	add_to_tail(list, &n);

	TEST_ASSERT_EQUAL_INT(1, list->size);
	TEST_ASSERT_EQUAL_INT('A', list->head->data->name);
	TEST_ASSERT_EQUAL_INT('A', list->tail->data->name);

	free(list);
}

void test_linked_list_add_to_tail_multiple(void)
{
	vertex a = {'A', NULL, NULL, 0, NULL, 0};
	vertex b = {'B', NULL, NULL, 0, NULL, 0};
	vertex c = {'C', NULL, NULL, 0, NULL, 0};
	linked_list *list = calloc(1, sizeof(linked_list));

	add_to_tail(list, &a);
	add_to_tail(list, &b);
	add_to_tail(list, &c);

	TEST_ASSERT_EQUAL_INT(3, list->size);
	TEST_ASSERT_EQUAL_INT('A', list->head->data->name);
	TEST_ASSERT_EQUAL_INT('B', list->head->next->data->name);
	TEST_ASSERT_EQUAL_INT('C', list->head->next->next->data->name);

	for (linked_node *curr_node = list->tail->prev; curr_node->prev != NULL; curr_node = curr_node->prev)
		free(curr_node->next);

	free(list);
}

void test_linked_list_replace_head(void)
{
	vertex a = {'A', NULL, NULL, 0, NULL, 0};
	vertex b = {'B', NULL, NULL, 0, NULL, 0};
	vertex c = {'C', NULL, NULL, 0, NULL, 0};
	vertex d = {'D', NULL, NULL, 0, NULL, 0};
	linked_list *list = calloc(1, sizeof(linked_list));

	add_to_head(list, &a);
	add_to_tail(list, &b);
	add_to_tail(list, &c);

	replace_head(list, &d);

	TEST_ASSERT_EQUAL_INT(3, list->size);
	TEST_ASSERT_EQUAL_INT('D', list->head->data->name);
	TEST_ASSERT_EQUAL_INT('B', list->head->next->data->name);
	TEST_ASSERT_EQUAL_INT('C', list->head->next->next->data->name);

	for (linked_node *curr_node = list->tail->prev; curr_node->prev != NULL; curr_node = curr_node->prev)
		free(curr_node->next);

	free(list);
}

void test_linked_list_replace_tail(void)
{
	vertex a = {'A', NULL, NULL, 0, NULL, 0};
	vertex b = {'B', NULL, NULL, 0, NULL, 0};
	vertex c = {'C', NULL, NULL, 0, NULL, 0};
	vertex d = {'D', NULL, NULL, 0, NULL, 0};
	linked_list *list = calloc(1, sizeof(linked_list));

	add_to_head(list, &a);
	add_to_tail(list, &b);
	add_to_tail(list, &c);

	replace_tail(list, &d);

	TEST_ASSERT_EQUAL_INT(3, list->size);
	TEST_ASSERT_EQUAL_INT('A', list->head->data->name);
	TEST_ASSERT_EQUAL_INT('B', list->head->next->data->name);
	TEST_ASSERT_EQUAL_INT('D', list->head->next->next->data->name);

	for (linked_node *curr_node = list->tail->prev; curr_node->prev != NULL; curr_node = curr_node->prev)
		free(curr_node->next);

	free(list);
}

void test_linked_list_contains(void)
{
	vertex a = {'A', NULL, NULL, 0, NULL, 0};
	vertex b = {'B', NULL, NULL, 0, NULL, 0};
	vertex c = {'C', NULL, NULL, 0, NULL, 0};
	linked_list *list = calloc(1, sizeof(linked_list));

	add_to_head(list, &a);
	add_to_tail(list, &b);
	add_to_tail(list, &c);

	TEST_ASSERT_TRUE(contains(list, 'A'));
	TEST_ASSERT_TRUE(contains(list, 'B'));
	TEST_ASSERT_TRUE(contains(list, 'C'));
	TEST_ASSERT_FALSE(contains(list, 'D'));

	for (linked_node *curr_node = list->tail->prev; curr_node->prev != NULL; curr_node = curr_node->prev)
		free(curr_node->next);

	free(list);
}
