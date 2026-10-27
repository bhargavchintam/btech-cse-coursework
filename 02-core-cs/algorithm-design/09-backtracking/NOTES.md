# Backtracking

Build a solution one piece at a time. After adding each piece check whether the partial
solution can still possibly grow into a full one - if it can't, throw the last piece away
and go back to the previous choice that still has untried options. That "go back" is the
backtrack. Nothing else to it.

The search space is a tree - the state-space tree. Each node is a partial solution, each
edge is "make the next choice". A plain brute force walks the WHOLE tree. Backtracking
prunes: the moment a node fails its check (the bounding function) we don't expand its
subtree at all. On good inputs that cuts off huge chunks of work, though the worst case
is still exponential.

> pruning is the whole game - without it backtracking IS brute force. - lecturer

## General template
```
solve(partial):
    if partial is a full solution:
        record / print it
        return
    for each choice c that extends partial:
        if c is valid (passes the bounding function):
            add c to partial
            solve(partial)
            remove c from partial      // undo - this is the backtrack
```
The undo is what lets one board/array get reused down every branch instead of copying it.
Forgetting the undo is the classic bug (lost marks on exactly that in an internal once).

## Examples
- n-queens          - one queen per row, a column is valid only if no earlier queen shares
                      its column or a diagonal. (01_n_queens.cpp)
- subset sum        - for each number decide take / skip, prune a branch the moment the
                      running sum passes the target. (02_subset_sum.cpp)
- graph m-colouring - colour vertices one by one, a colour is valid only if no adjacent
                      vertex already has it. (03_graph_coloring.cpp)
- hamiltonian cycle - extend a path vertex by vertex, and it must end on an edge back to
                      the start. (04_hamiltonian_cycle.cpp)

## Two flavours
- decision   - is there ANY solution? stop at the first (m-colouring, hamiltonian here).
- all / count - keep searching after each hit to enumerate every solution (n-queens count).

## Complexity
Worst case is the size of the state-space tree - the pruning only helps in practice, it
does not change the guarantee.

```
problem              choice at each node     worst case
--------------------------------------------------------
n-queens             a column per row        O(n!) , far less with pruning
subset sum           take / skip per item    O(2^n)
m-colouring          m colours per vertex    O(m^n)
hamiltonian cycle    next vertex on path     O(n!)
```

So exponential on paper. The reason we still use it: a decent bounding function kills most
branches near the top, so real inputs finish fast even though the guarantee is bad.
