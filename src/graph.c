#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

void add_vertex(graph *g, vertex *n)
{
	g->vertices[g->size++] = n;
}

vertex *get_vertex_with_name(graph *g, char name)
{
	for (unsigned int i = 0; i < g->size; i++)
		if (g->vertices[i]->name == name)
			return g->vertices[i];

	return NULL;
}

void print_graph(graph *g)
{
	for (unsigned int i = 0; i < g->size; i++)
	{
		printf("%c -- %d\n", g->vertices[i]->name, g->vertices[i]->num_of_neighbors);
		for (unsigned int j = 0; j < g->vertices[i]->num_of_neighbors; j++)
			printf("\t %c (%d)\n", g->vertices[i]->neighbors[j]->name, g->vertices[i]->weights[j]);
	}
}
