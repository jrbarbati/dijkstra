# Dijkstra's Shortest Path

A C implementation of Dijkstra's shortest path algorithm, written as a learning exercise in both C and graph algorithms. The goal was to implement Dijkstra's algorithm from scratch while also manually implementing every data structure it requires — no standard library containers, no third-party collections. That means the min binary heap used as the priority queue, the doubly linked list used for the visited set and path reconstruction, and the graph and vertex structures are all hand-rolled as part of the exercise.

The graph is represented as an adjacency list with weighted, directed edges.

## Project Structure

```
.
├── src/
│   ├── binary_heap.c / .h   # Min binary heap (priority queue)
│   ├── dijkstra.c / .h      # Shortest path algorithm
│   ├── graph.c / .h         # Graph structure and operations
│   ├── linked_list.c / .h   # Doubly linked list (visited set & path)
│   └── vertex.c / .h        # Vertex structure and operations
└── test/
    ├── vendor/unity.c        # Unity test framework
    ├── test_binary_heap.c
    └── test_dijkstra.c
```

## Building & Testing

### Run tests
```bash
make test
```

### Run tests with AddressSanitizer (memory error detection)
```bash
make memcheck
```

### Clean build artifacts
```bash
make clean
```

**Requirements:** Clang or GCC with C99 support.

## Usage

### 1. Define your graph size

`MAX_NUM_OF_VERTICES` defaults to `20`. Override it at compile time if needed:
```bash
make CFLAGS+="-DMAX_NUM_OF_VERTICES=50"
```

### 2. Create vertices

```c
#include "vertex.h"

// initialize_vertex(name, max_number_of_neighbors)
vertex *a = initialize_vertex('A', 3);
vertex *b = initialize_vertex('B', 2);
vertex *c = initialize_vertex('C', 1);
```

### 3. Add edges

Edges are directed and weighted.

```c
#include "vertex.h"

// add_edge(source, target, weight)
add_edge(a, b, 4);
add_edge(a, c, 2);
add_edge(b, c, 1);
```

### 4. Build the graph

```c
#include "graph.h"

graph g = {0};
// graph.vertices is a pointer — point it at your vertex array
vertex *verts[] = {a, b, c};
g.vertices = verts;

add_vertex(&g, a);
add_vertex(&g, b);
add_vertex(&g, c);
```

### 5. Run Dijkstra

```c
#include "dijkstra.h"

// shortest_path(graph, start_vertex_name, end_vertex_name)
linked_list *path = shortest_path(&g, 'A', 'C');
```

### 6. Use the result

`shortest_path` returns a `linked_list` of `char` vertex names from start to end, or `NULL` if no path exists.

```c
#include "linked_list.h"

if (path) {
    print_list(path);   // e.g. [A -- C]
    free(path);
}
```

## API Reference

### vertex

| Function | Description |
|---|---|
| `vertex *initialize_vertex(char name, unsigned int num_of_neighbors)` | Allocates and initializes a vertex. `num_of_neighbors` sets the capacity for edges. |
| `void add_edge(vertex *source, vertex *target, unsigned int weight)` | Adds a directed, weighted edge from `source` to `target`. |

### graph

| Function | Description |
|---|---|
| `void add_vertex(graph *g, vertex *v)` | Adds a vertex to the graph. |
| `vertex *get_vertex_with_name(graph *g, char name)` | Returns the vertex with the given name, or `NULL`. |
| `void print_graph(graph *g)` | Prints each vertex and its neighbors with weights. |

### dijkstra

| Function | Description |
|---|---|
| `linked_list *shortest_path(graph *g, char start, char end)` | Returns the shortest path as a linked list of vertex names, or `NULL` if unreachable. |

### binary_heap

| Function | Description |
|---|---|
| `binary_heap *initialize_heap(void)` | Allocates and returns an empty min heap. |
| `void push(binary_heap *bh, vertex *v)` | Inserts a vertex ordered by `distance_from_start`. |
| `vertex *pop(binary_heap *bh)` | Removes and returns the vertex with the lowest `distance_from_start`. |
| `int find_vertex(binary_heap *bh, char name, unsigned int priority)` | Returns the index of a vertex by name, `-2` if a lower-priority entry already exists, or `-1` if not found. |
| `void print_heap(binary_heap *bh)` | Prints the heap contents with distances. |

### linked_list

| Function | Description |
|---|---|
| `void add_to_head(linked_list *list, char name)` | Prepends a node. |
| `void add_to_tail(linked_list *list, char name)` | Appends a node. |
| `void replace_head(linked_list *list, char name)` | Replaces the head node in place. |
| `void replace_tail(linked_list *list, char name)` | Replaces the tail node in place. |
| `int contains(linked_list *list, char name)` | Returns `1` if the list contains the given name, `0` otherwise. |
| `void print_list(linked_list *list)` | Prints the list contents. |

## Implementation Notes

- The binary heap is a fixed-size array of `MAX_NUM_OF_VERTICES + 1` — index `0` is unused so that parent/child index arithmetic (`k/2`, `k*2`) works cleanly from index `1`.
- `vertex.distance_from_start` is initialized to `UINT_MAX` (`0 - 1` on an `unsigned int`) to represent infinity.
- The visited set in Dijkstra is a linked list of vertex names scanned linearly — fine for small graphs, but worth noting for larger inputs.
- Edges are directed. To model an undirected graph, call `add_edge` in both directions.
