<p align="center"><img src="assets/banner.svg" alt="Design and Analysis of Algorithms and Lab" width="100%"></p>

# Design and Analysis of Algorithms and Lab

C++ programs from Design and Analysis of Algorithms at **REVA University, Bengaluru** (B.Tech, fourth semester, 2018–19). My first C++ course — the [DSA repo](../data-structures/) from third semester did the data structures in C; this one does the *design techniques and analysis*, in C++.

83 programs. The folders follow Levitin's organization of algorithms by **design paradigm** — brute force, divide & conquer, decrease & conquer, and so on — because that's the way the course was taught: not "here are graphs", but "here is a technique, and here is every problem it cracks".

## Structure

| Folder | Design technique | Programs |
|---|---|---|
| `01-analysis/` | Asymptotic notation, recurrences, the master theorem | 5 |
| `02-brute-force/` | Straight off the problem statement — sorts, exhaustive search | 8 |
| `03-divide-and-conquer/` | Merge/quick sort, binary search, Strassen, Karatsuba, closest pair | 8 |
| `04-decrease-and-conquer/` | Insertion sort, DFS/BFS, topological sort, permutations | 8 |
| `05-transform-and-conquer/` | Presorting, Gaussian elimination, heaps, AVL, Horner | 6 |
| `06-space-time-tradeoffs/` | Counting sorts, hashing | 4 |
| `07-greedy/` | Prim, Kruskal, Dijkstra, Huffman, fractional knapsack | 6 |
| `08-dynamic-programming/` | Knapsack, LCS, Floyd, optimal BST, matrix chain, coin change | 9 |
| `09-backtracking/` | N-Queens, subset sum, graph colouring, Hamiltonian cycle | 4 |
| `10-branch-and-bound/` | Assignment, knapsack, TSP with bounding | 3 |
| `11-string-matching/` | Naive, Rabin-Karp, KMP, Horspool, Boyer-Moore | 5 |
| `12-np-and-approximation/` | P/NP/NP-complete, approximation algorithms | 3 |
| `lab/` | The 14 numbered lab-manual programs | 14 |

Each topic folder has a `NOTES.md` explaining the paradigm and its analysis.

## Compiling

C++, builds with `g++`. STL is used to *hold* data (`vector`, `queue`, `priority_queue`), but the algorithm itself is always written by hand — calling `std::sort` in a program whose job is to demonstrate a sort would defeat the point.

```sh
g++ -std=c++14 -Wall 03-divide-and-conquer/01_merge_sort.cpp -o merge_sort
./merge_sort
```

Most programs read their input (an array, a graph as a cost matrix, a pattern) and run once. The `lab/` sorting programs are timing experiments — they run the sort over increasing `n` with `<ctime>` and print an `n`-vs-time table so the order of growth shows on screen.

To build everything at once into `bin/`:

```sh
make          # compiles all 83 into bin/
make clean
```

## Analysis is the point

This being a DAA course, the recurring question isn't "does it work" but "how fast does it grow". A few programs make that concrete:

- `01-analysis/01_order_of_growth.cpp` prints `log n`, `n log n`, `n²`, `2ⁿ` side by side so the gap between them is visible on one screen.
- `01-analysis/05_master_theorem.cpp` reads `a, b, d` for `T(n) = a·T(n/b) + nᵈ` and tells you which of the three master-theorem cases applies and the resulting order.
- `lab/lab01_selection_sort_time.cpp` vs `lab/lab03_merge_sort_time.cpp` — run both and watch one table roughly quadruple per doubling of `n` while the other barely more than doubles.

## Lab

`lab/` holds the 14 graded programs: the three sorts with time analysis, the MST pair (Prim and Kruskal — they print the same total weight), Dijkstra, Floyd, TSP by dynamic programming, both knapsacks, subset sum, Hamiltonian cycle, N-Queens, and graph traversal. Each opens with its problem statement.

## A note on the code

Fourth-semester C++, and it reads like a C programmer who just moved to `cout`: `using namespace std;` everywhere, fixed-size `int cost[20][20]` for small graphs next to `vector` where it's easier, buffers unchecked. Left as written — it's the code I actually submitted, not a cleaned-up version.
