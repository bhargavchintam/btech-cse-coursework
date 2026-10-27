# Algorithm design techniques

The four big paradigms from the algorithms unit. Each one is a way of THINKING about a
problem, not a single fixed algorithm. The same problem can sometimes fit more than one -
knapsack is greedy when fractional but needs DP when it's 0/1.

## 1. Divide and Conquer
Break the problem into smaller subproblems of the SAME type, solve them (usually by
recursion), then combine the answers. The subproblems don't overlap each other.

Steps: divide -> conquer (recurse on the parts) -> combine.

Examples: binary search, merge sort, quick sort, finding max and min together, fast power
(x^n in log n), quickselect, Strassen's matrix multiply.

> "If you can cut it in half and the halves don't need to talk to each other, reach for divide
> and conquer."

When it applies: the problem splits cleanly into independent parts and combining them is
cheap. The running time usually comes out as a recurrence T(n) = a T(n/b) + f(n), which you
solve with the Master theorem.

## 2. Greedy
Build the answer one step at a time. At each step take the choice that looks best RIGHT NOW
and never undo it. Simple and fast, but only correct when the problem has the greedy-choice
property together with optimal substructure. When it doesn't, greedy quietly gives a wrong
answer.

Examples: fractional knapsack (sort by value/weight), activity selection (pick earliest
finish), job sequencing with deadlines, Huffman coding, Prim's, Kruskal's, Dijkstra.

When it applies: a local best choice ends up being part of a global best answer. This has to
be PROVED, you can't just assume it. 0/1 knapsack looks greedy but greedy fails on it, which
is exactly why that one needs DP.

## 3. Dynamic Programming
Also splits into subproblems, but here the subproblems OVERLAP - the same one is needed over
and over. So we solve each once and store the result in a table instead of recomputing it.
Two styles: top-down (memoized recursion) and bottom-up (fill the table iteratively).

Two conditions must both hold: optimal substructure AND overlapping subproblems.

Examples: 0/1 knapsack, longest common subsequence, coin change (minimum coins), matrix
chain multiplication, Floyd-Warshall, edit distance, Bellman-Ford.

When it applies: brute force keeps recomputing the same subproblem. DP stores it and reuses
it, usually turning an exponential brute force into a polynomial one.

## 4. Backtracking
Build the solution one choice at a time and abandon a partial solution the moment it can't
lead anywhere valid ("backtrack"). It's a depth-first search over the space of choices with
pruning.

Examples: N-queens, rat in a maze, subset sum, graph colouring, Hamiltonian path, sudoku,
generating permutations.

When it applies: you're searching for an arrangement that satisfies some constraints and you
can tell early that a partial choice is already doomed. Worst case is still exponential, but
the pruning cuts a lot of the tree in practice.

## Quick comparison

| Paradigm         | Subproblems     | Key idea                     | Typical cost         |
|------------------|-----------------|------------------------------|----------------------|
| Divide & conquer | independent     | split, recurse, combine      | often O(n log n)     |
| Greedy           | one pass        | best local choice, no undo   | O(n) or O(n log n)   |
| Dynamic prog.    | overlapping     | store and reuse subresults   | often O(n^2), O(n*W) |
| Backtracking     | tree of choices | try, prune, undo             | exponential (pruned) |

## The one that trips everyone up
Greedy vs DP. Fractional knapsack - greedy works. 0/1 knapsack - greedy FAILS, need DP.
Got this wrong in the lab test, assumed the sort-by-ratio trick carries over to 0/1. It
doesn't. You can't take a fraction of an item, so a locally best pick can block a better
combination later.
