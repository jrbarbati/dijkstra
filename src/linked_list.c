#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

linked_node *initialize_linked_node(vertex *v);

void add_to_head(linked_list *list, vertex *v)
{
	linked_node *ln = initialize_linked_node(v);

	if (list->size == 0)
	{
		list->head = ln;
		list->tail = ln;
	}
	else 
	{
		linked_node *curr_head = list->head;

		ln->next = curr_head;
		curr_head->prev = ln;

		list->head = ln;
	}

	list->size++;
}

void add_to_tail(linked_list *list, vertex *v)
{
	printf("Before add_to_tail: ");
	print_list(list);
	linked_node *ln = initialize_linked_node(v);

	if (list->size == 0)
	{
		list->head = ln;
		list->tail = ln;
	}
	else 
	{
		linked_node *curr_tail = list->tail;

		ln->prev = curr_tail;
		curr_tail->next = ln;

		list->tail = ln;
	}

	list->size++;
	printf("After add_to_tail: ");
	print_list(list);
}

void replace_head(linked_list *list, vertex *v)
{
	if (list->size == 0)
		return;

	linked_node *ln = initialize_linked_node(v);

	linked_node *curr_head = list->head;

	curr_head->next->prev = ln;
	ln->next = curr_head->next;
	list->head = ln;

	free(curr_head);
}

void replace_tail(linked_list *list, vertex *v)
{
	if (list->size == 0)
		return;

	linked_node *ln = initialize_linked_node(v);

	linked_node *curr_tail = list->tail;

	curr_tail->prev->next = ln;
	ln->prev = curr_tail->prev;
	list->tail = ln;

	free(curr_tail);
}

int contains(linked_list *list, char name)
{
	linked_node *curr_node;

	for (curr_node = list->head; curr_node != NULL; curr_node = curr_node->next)
		if (curr_node->data->name == name)
			return 1;

	return 0;
}

linked_node *initialize_linked_node(vertex *v)
{
	linked_node *ln = calloc(1, sizeof(linked_node));
	ln->data = v;

	return ln;
}

void print_list(linked_list *list)
{
	if (list->size == 0)
	{
		printf("[]\n");
		return;
	}

	linked_node *curr_node = list->head;
	printf("[");

	while (curr_node->next != NULL)
	{
		printf("%c -- ", curr_node->data->name);
		curr_node = curr_node->next;
	}

	printf("%c]\n", curr_node->data->name);
}
