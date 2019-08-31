#include "vertex.h"
#include <stdlib.h>
#include <stdio.h>

vertex *initialize_vertex(char name, unsigned int num_of_neighbors)
{
	vertex *n = calloc(1, sizeof(vertex));
	n->name = name;
	n->neighbors = calloc(num_of_neighbors, sizeof(vertex));
	n->weights = calloc(num_of_neighbors, sizeof(unsigned int));
	n->parent = calloc(1, sizeof(vertex));
	n->distance_from_start = 0 - 1;

	return n;
}

void add_edge(vertex *source, vertex *target, unsigned int weight)
{
	source->neighbors[source->num_of_neighbors] = *target;
	source->weights[source->num_of_neighbors++] = weight;
}

void set_parent(vertex *child, vertex *parent)
{
	child->parent->name = parent->name;
}
