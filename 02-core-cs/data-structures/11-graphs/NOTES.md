# Graphs

A graph is vertices (V) joined by edges (E). Edges can be directed or undirected, weighted or not.
Unlike a tree it can have cycles and more than one path between two vertices.

## Representations
- **Adjacency matrix** — an n×n array, `a[i][j] = 1` (or the weight) if there's an edge i→j.
  Simple, O(1) edge lookup, but O(n²) space even for a sparse graph.
- **Adjacency list** — each vertex keeps a list of its neighbours. O(V+E) space, better for sparse
  graphs, which most real graphs are.

## Traversals
- **BFS** — visit level by level from a source, uses a **queue**. Gives shortest path in edges for an
  unweighted graph.
- **DFS** — go as deep as possible, then backtrack. Uses a **stack** (or recursion). Basis for cycle
  detection, topological sort, connected components.

## Spanning trees
A spanning tree connects all V vertices with V-1 edges and no cycle. **Minimum spanning tree** = the
one with least total weight.
- **Prim** — grow the tree one vertex at a time, always add the cheapest edge leaving the tree.
- **Kruskal** — sort all edges, add the cheapest that doesn't make a cycle (checked with union-find).

Both give the same total weight (the MST weight is unique when edge weights are distinct).

## Shortest paths
- **Dijkstra** — single source, non-negative weights. Greedy, picks the nearest unvisited vertex each step.
- **Bellman-Ford** — single source, handles negative edges, detects a negative cycle. Slower.
- **Floyd-Warshall** — all pairs, a triple loop over an intermediate vertex k.

## Topological sort
Linear ordering of a **DAG** so every edge u→v has u before v. Kahn's method: repeatedly remove a
vertex with in-degree 0.

> A topological order only exists if the graph has no cycle. If you can't empty the queue, there's a cycle.

## Complexity (V vertices, E edges)

| Algorithm | Adjacency matrix | Adjacency list |
|---|---|---|
| BFS / DFS | O(V²) | O(V+E) |
| Dijkstra | O(V²) | O(E log V) with a heap |
| Bellman-Ford | — | O(V·E) |
| Floyd-Warshall | O(V³) | O(V³) |
| Prim | O(V²) | O(E log V) |
| Kruskal | O(E log E) | O(E log E) |

Most of my programs use the adjacency matrix — it's easier to read from the user in the lab, even if it
wastes space.
