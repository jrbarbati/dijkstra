#ifndef DIJKSTRA_GRAPH_H
#define DIJKSTRA_GRAPH_H

#include "vertex.h"

#ifndef MAX_NUM_OF_VERTICES
#define MAX_NUM_OF_VERTICES 20
#endif

typedef struct graph
{
    vertex *vertices;
    unsigned int size;
} graph;

void add_vertex(graph *g, vertex *n);

vertex get_vertex_with_name(graph *g, char name);

void print_graph(graph *g);

#endif //DIJKSTRA_GRAPH_H
