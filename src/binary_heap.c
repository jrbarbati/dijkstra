#include "binary_heap.h"
#include <stdio.h>
#include <stdlib.h>

void swim(binary_heap *bh);
void sink(binary_heap *bh);
void swap(binary_heap *bh, int index1, int index2);
int find_vertex(binary_heap *bh, char name, unsigned int priority);

binary_heap *initialize_heap()
{
	return calloc(1, sizeof(binary_heap));
}

void push(binary_heap *bh, vertex *n)
{
	int vertex_index = find_vertex(bh, n->name, n->distance_from_start);

	if (vertex_index == -2)
		return;

	unsigned int index = vertex_index >= 0 ? vertex_index : bh->size + 1;

	bh->vertices[index] = *n;

	if (index == bh->size + 1)
		bh->size++;

	swim(bh);
}

void pop(binary_heap *bh, vertex *n)
{
	if (bh->size == 0)
		return;

	n->name = bh->vertices[1].name;
	n->neighbors = bh->vertices[1].neighbors;
	n->weights = bh->vertices[1].weights;
	n->num_of_neighbors = bh->vertices[1].num_of_neighbors;
	n->distance_from_start = bh->vertices[1].distance_from_start;

	swap(bh, 1, bh->size);
	vertex empty_vertex = {'\0', NULL, NULL, 0, NULL, 0 - 1};
	bh->vertices[bh->size] = empty_vertex;
	bh->size--;

	sink(bh);
}

void swim(binary_heap *bh)
{
	int k = bh->size;
	while (k > 1 && bh->vertices[k / 2].distance_from_start > bh->vertices[k].distance_from_start)
	{
		swap(bh, k, k / 2);
		k /= 2;
	}
}

void sink(binary_heap *bh)
{
	unsigned int k = 1;

	while (k <= bh->size && (bh->vertices[k].distance_from_start > bh->vertices[k * 2].distance_from_start || bh->vertices[k].distance_from_start > bh->vertices[k * 2 + 1].distance_from_start))
	{
		if (bh->vertices[k].distance_from_start > bh->vertices[k * 2].distance_from_start)
			swap(bh, k, k * 2);
		if (bh->vertices[k].distance_from_start > bh->vertices[k * 2 + 1].distance_from_start)
			swap(bh, k, k * 2 + 1);

		k *= 2;
	}
}

void swap(binary_heap *bh, int index1, int index2)
{
	vertex temp_vertex = bh->vertices[index1];
	bh->vertices[index1] = bh->vertices[index2];
	bh->vertices[index2] = temp_vertex;
}

/*
 * Finds the index of the incoming vertex if it already exists in the binary heap
 * If the vertex exists in the binary heap, but we already have a lower priority for that vertex, returns -2
 * If the vertex doesn't exist in the binary heap, returns -1
 */
int find_vertex(binary_heap *bh, char name, unsigned int priority)
{
	for (unsigned int i = 1; i <= bh->size; i++)
		if (bh->vertices[i].name == name)
			return bh->vertices[i].distance_from_start < priority ? -2 : i;

	return -1; 
}

void print_heap(binary_heap *bh)
{
	if (bh->size == 0)
	{
		printf("[]\n");
		return;
	}

	unsigned int i;
	printf("[");

	for (i = 1; i < bh->size; i++)
		printf("%c (%d) (%d) -- ", bh->vertices[i].name, bh->vertices[i].distance_from_start, bh->vertices[i].num_of_neighbors);

	printf("%c (%d) (%d)]\n", bh->vertices[i].name, bh->vertices[i].distance_from_start, bh->vertices[i].num_of_neighbors);
}
