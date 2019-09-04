#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

linked_node *initialize_linked_node(char name);

void add_to_head(linked_list *list, char name)
{
	linked_node *ln = initialize_linked_node(name);

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

void add_to_tail(linked_list *list, char name)
{
	linked_node *ln = initialize_linked_node(name);

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
}

void replace_head(linked_list *list, char name)
{
	if (list->size == 0)
		return;

	linked_node *ln = initialize_linked_node(name);

	linked_node *curr_head = list->head;

	curr_head->next->prev = ln;
	ln->next = curr_head->next;
	list->head = ln;

	free(curr_head);
}

void replace_tail(linked_list *list, char name)
{
	if (list->size == 0)
		return;

	linked_node *ln = initialize_linked_node(name);

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
		if (curr_node->data == name)
			return 1;

	return 0;
}

linked_node *initialize_linked_node(char name)
{
	linked_node *ln = calloc(1, sizeof(linked_node));
	ln->data = name;

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
		printf("%c -- ", curr_node->data);
		curr_node = curr_node->next;
	}

	printf("%c]\n", curr_node->data);
}
