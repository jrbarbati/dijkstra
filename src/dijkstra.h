#ifndef DIJKSTRA_DIJKSTRA_H
#define DIJKSTRA_DIJKSTRA_H

#include "graph.h"
#include "linked_list.h"

linked_list *shortest_path(graph *graph, char starting_node_name, char ending_node_name);

linked_list *build_path(vertex *end);

#endif //DIJKSTRA_DIJKSTRA_H
