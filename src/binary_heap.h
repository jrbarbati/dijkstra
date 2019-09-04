#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include "vertex.h"
#include "graph.h"

typedef struct binary_heap
{
	vertex *vertices[MAX_NUM_OF_VERTICES + 1];
	unsigned int size;
} binary_heap;

binary_heap *initialize_heap();

void push(binary_heap *bh, vertex *n);

vertex *pop(binary_heap *bh);

void print_heap(binary_heap *bh);


#endif
