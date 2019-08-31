#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "vertex.h"

typedef struct linked_node
{
	vertex data;
	struct linked_node *next;
	struct linked_node *prev;
} linked_node;

typedef struct linked_list
{
	linked_node *head;
	linked_node *tail;
	int size;
} linked_list;

void add_to_head(linked_list *list, vertex *n);
void add_to_tail(linked_list *list, vertex *n);
void replace_head(linked_list *list, vertex *n);
void replace_tail(linked_list *list, vertex *n);
int contains(linked_list *list, char name);
void print_list(linked_list *list);

#endif
