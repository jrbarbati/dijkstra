#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct linked_node
{
	char data;
	struct linked_node *next;
	struct linked_node *prev;
} linked_node;

typedef struct linked_list
{
	linked_node *head;
	linked_node *tail;
	int size;
} linked_list;

void add_to_head(linked_list *list, char name);

void add_to_tail(linked_list *list, char name);

void replace_head(linked_list *list, char name);

void replace_tail(linked_list *list, char name);

int contains(linked_list *list, char name);

void print_list(linked_list *list);

#endif
