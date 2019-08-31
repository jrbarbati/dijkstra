#include "dijkstra.h"
#include "binary_heap.h"
#include <stdio.h>
#include <stdlib.h>

linked_list *shortest_path(graph *graph, char starting_vertex_name, char ending_vertex_name)
{
	vertex *curr_vertex = calloc(1, sizeof(vertex));
	linked_list *visited = calloc(1, sizeof(linked_list));
	binary_heap *priority_queue = initialize_heap();
	
	vertex start = get_vertex_with_name(graph, starting_vertex_name);
	start.distance_from_start = 0;

	push(priority_queue, &start);

	while (priority_queue->size != 0)
	{
		pop(priority_queue, curr_vertex);

		if (curr_vertex->name == ending_vertex_name)
			break;

		add_to_tail(visited, curr_vertex);

		for (unsigned int i = 0; i < curr_vertex->num_of_neighbors; i++)
		{
			if (contains(visited, curr_vertex->neighbors[i].name))
				continue;

			vertex parent = {
				curr_vertex->name, 
				curr_vertex->neighbors, 
				curr_vertex->weights, 
				curr_vertex->num_of_neighbors, 
				curr_vertex->parent, 
				curr_vertex->distance_from_start
			};

			vertex next = {
				curr_vertex->neighbors[i].name, 
				curr_vertex->neighbors[i].neighbors, 
				curr_vertex->neighbors[i].weights,
				curr_vertex->neighbors[i].num_of_neighbors,
				&parent,
				curr_vertex->distance_from_start + curr_vertex->weights[i]
			};

			push(priority_queue, &next);
		}
	}

	linked_list *path = build_path(curr_vertex);

	free(visited);
	free(priority_queue);
	free(curr_vertex);

	return path;
}

linked_list *build_path(vertex *end)
{
	linked_list *path = calloc(1, sizeof(linked_list));
	vertex *curr_vertex = end;

	while (curr_vertex != NULL)
	{
		add_to_head(path, curr_vertex);
		curr_vertex = curr_vertex->parent;
	}

	return path;
}
