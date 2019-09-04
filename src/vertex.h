#ifndef DIJKSTRA_VERTEX_H
#define DIJKSTRA_VERTEX_H

typedef struct vertex 
{
	char name;
	struct vertex **neighbors;
	unsigned int *weights;
	unsigned int num_of_neighbors;
	struct vertex *parent;
	unsigned int distance_from_start;
} vertex;


vertex *initialize_vertex(char name, unsigned int num_of_neighbors);

void add_edge(vertex *source, vertex *target, unsigned int weight);

#endif //DIJKSTRA_VERTEX_H
