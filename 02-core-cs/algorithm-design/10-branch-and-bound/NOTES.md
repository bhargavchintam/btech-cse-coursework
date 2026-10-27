# Branch and bound

Backtracking's cousin, but for OPTIMISATION problems - find the cheapest or most valuable
solution, not just any valid one. Same state-space tree, same idea of not expanding
hopeless subtrees. The difference is HOW we decide a subtree is hopeless.

For every node we compute a BOUND - an optimistic estimate of the best answer reachable
anywhere inside that subtree. For a minimisation problem that is a lower bound (the
subtree cannot possibly do better than this); for maximisation it is an upper bound. We
also keep the best complete solution found so far. Then:

- minimisation: if a node's lower bound >= best-so-far, prune it - it cannot beat what we
  already hold.
- maximisation: if a node's upper bound <= best-so-far, prune it.

The bound has to be optimistic but valid - it must never rule out the real optimum. A
tighter bound prunes more branches, so most of the effort in a B&B is designing the bound.

> backtracking asks "is this valid?", branch and bound asks "can this still WIN?". - lecturer

## Which node next
Order for picking the next live node to expand:
- FIFO / LIFO  - a queue or a stack; LIFO is basically DFS.
- least cost   - a priority queue keyed on the bound, expand the most promising node first.
                 It usually reaches a good solution soonest so pruning starts earlier. The
                 three programs here use DFS with a bound, which is the simplest form.

## Examples
- assignment problem  - assign worker by worker, bound = cost so far + each remaining
                        worker's cheapest still-free job. (01_assignment_problem.cpp)
- 0/1 knapsack        - include / exclude each item, upper bound = greedily fill the leftover
                        capacity fractionally. (02_knapsack_bb.cpp)
- travelling salesman - grow the tour city by city, lower bound = cost so far + each
                        remaining city's cheapest outgoing edge. (03_tsp_bb.cpp)

## Complexity
Still exponential in the worst case - a useless bound prunes nothing and you walk the whole
tree. A good bound makes it fast on real inputs but never improves the guarantee.

```
problem              tree size      bound used
--------------------------------------------------------
assignment (n x n)   O(n!)          cheapest free job per remaining worker
0/1 knapsack         O(2^n)         fractional-knapsack value
TSP (n cities)       O(n!)          cheapest outgoing edge per remaining city
```

The knapsack bound is the fractional (greedy) knapsack value, which is always >= the 0/1
value - exactly the optimistic-but-valid upper bound we need.
