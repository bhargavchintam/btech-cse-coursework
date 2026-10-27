# Greedy algorithms

The greedy idea: at every step make the choice that looks best RIGHT NOW - the local
optimum - and never take it back. No looking ahead, no undoing. You hope that a chain of
locally best choices lands on the globally best answer. Often it does not, but for the
right problems it does, and then greedy is the fastest thing going.

## When does greedy actually work
A greedy algorithm is correct only when the problem has both:

- greedy-choice property - a globally optimal solution can be reached by making the
  locally optimal (greedy) choice at each step. You never have to reconsider it later.
- optimal substructure - an optimal solution contains optimal solutions to its
  subproblems. (DP needs this too; greedy needs it AND the greedy-choice property.)

If the greedy choice can paint you into a corner, greedy is wrong and you fall back to
DP or backtracking. 0/1 knapsack is the standard trap: grabbing the best value/weight
item first can waste capacity, so 0/1 needs DP. The FRACTIONAL knapsack, where you may
take a piece of an item, IS greedy - take the best ratio first, cut the last one to fit.

> got this wrong in the internal - wrote greedy for 0/1 knapsack. it is NOT greedy.
> greedy is only correct for the fractional version. remember the difference.

## The general shape
```
arrange the candidates by some greedy key (usually a sort)
solution = empty
for each candidate in that order:
    if adding it keeps the solution feasible:
        add it
return solution
```
The whole design is choosing the right key. Prim picks the cheapest edge leaving the
tree; Kruskal the cheapest edge that makes no cycle; Huffman merges the two rarest
symbols; job sequencing takes the fattest profit that still fits an open slot.

## Examples in this folder
- Prim / Kruskal - minimum spanning tree, two different greedy keys, same total.
- Dijkstra - shortest paths, always expand the nearest unfinished vertex.
- Huffman - optimal prefix codes, repeatedly merge the two smallest frequencies.
- Fractional knapsack - sort by value/weight, take greedily, fraction the last item.
- Job sequencing - sort by profit, place each job in the latest free slot before its deadline.

## Proof style
Greedy correctness is usually argued by an EXCHANGE argument: take any optimal solution,
show you can swap in the greedy choice without making it worse, so the greedy solution is
at least as good as the optimum. Prim and Kruskal lean on the cut property - the lightest
edge crossing any cut is safe to add to the MST.

## Complexity
```
algorithm               time                 note
--------------------------------------------------------------
Prim (matrix)           O(V^2)               O(E log V) with a heap
Kruskal                 O(E log E)           sort edges + union-find
Dijkstra (matrix)       O(V^2)               O(E log V) with a heap
Huffman                 O(n log n)           n heap pushes and pops
Fractional knapsack     O(n log n)           the sort dominates
Job sequencing          O(n^2)               n jobs x scan of slots
```
Almost every greedy cost is "the sort" plus a linear pass - that is why greedy is quick.
The hard part was never the running time, it is proving the greedy choice is safe.
