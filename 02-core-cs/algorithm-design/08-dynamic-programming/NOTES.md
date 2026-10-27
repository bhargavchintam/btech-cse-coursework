# Dynamic programming

Eighth design paradigm. DP is for problems that break into subproblems that OVERLAP -
the same smaller problem is asked again and again. Plain recursion re-solves each one from
scratch (fibonacci recursion is 2^n calls). DP solves every distinct subproblem ONCE, stores
the answer in a table, and reuses it. Trade memory for time.

## When DP applies
Two properties, both required:

- **Overlapping subproblems** - the recursion keeps hitting the same subproblem. If every
  subproblem were distinct, there is nothing to reuse and plain divide-and-conquer is enough.
- **Optimal substructure** - an optimal answer is built from optimal answers to subproblems.
  Shortest path 0..k through j uses the shortest 0..j and j..k. (This fails for longest
  *simple* path, so DP does not apply there.)

If both hold, write the recurrence and fill a table.

## Two ways to fill the table
Same recurrence, opposite direction:

- **Memoization (top-down)** - keep the natural recursion, but before computing check a memo
  table; if the answer is stored return it, else compute and store. Only touches the
  subproblems actually needed. (fibmemo in 01_fibonacci_dp.cpp.)
- **Bottom-up (tabulation)** - solve the smallest subproblems first, loop upward filling the
  table so every value you read is already there. No recursion, usually a couple of nested
  loops. (fibtable in the same file.)

> "Memoization is lazy, tabulation is eager. Same answers, and for the exam know both." - lecturer.

Bottom-up is usually a hair faster (no call overhead) and lets you drop to a 1-D rolling array;
memoization is easier to write from the recurrence and skips unused states.

## The examples in this folder
- **fibonacci** (01) - the toy case. f(n)=f(n-1)+f(n-2). Shows memo vs table side by side.
- **binomial coefficient** (02) - C(n,k)=C(n-1,k-1)+C(n-1,k), Pascal's triangle is the table.
- **Warshall** (03) - transitive closure. r[i][j] |= r[i][k] && r[k][j], k as the outer loop.
- **Floyd** (04) - same triple loop as Warshall but with min and addition instead of OR/AND:
  d[i][j] = min(d[i][j], d[i][k]+d[k][j]). All-pairs shortest paths.
- **0/1 knapsack** (05) - K[i][w] = max(K[i-1][w], val[i]+K[i-1][w-wt[i]]). Table of items x weight.
- **LCS** (06) - if chars match L[i][j]=L[i-1][j-1]+1 else max of the two neighbours. Backtrack
  through the table to recover the actual subsequence.
- **optimal BST** (07) - cost[i][j] = min over root r of cost[i][r-1]+cost[r+1][j] + sum of
  frequencies. Fill by increasing chain length.
- **coin change** (08) - dp[a] = min over coins of dp[a-coin]+1. Minimum coins for an amount.
- **matrix chain** (09) - m[i][j] = min over split k of m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j].

Warshall and Floyd are the same algorithm shape (Floyd-Warshall) - that k-in-the-middle idea
is worth seeing twice. Got the loop order wrong once in the internal: k MUST be the outer loop,
not i. If i is outer the intermediate vertices are not all considered.

## Complexity
```
problem                 table size     time        notes
--------------------------------------------------------------------
fibonacci               O(n)           O(n)        1-D, rolling array -> O(1) space
binomial C(n,k)         O(n*k)         O(n*k)
Warshall / Floyd        O(n^2)         O(n^3)      n = vertices
0/1 knapsack            O(n*W)         O(n*W)      pseudo-polynomial (W in the size)
LCS                     O(m*n)         O(m*n)
optimal BST             O(n^2)         O(n^3)      three nested loops
coin change             O(amount)      O(amount*coins)
matrix chain            O(n^2)         O(n^3)
```

Knapsack is "pseudo-polynomial": O(nW) looks polynomial but W is a numeric value, not the input
size in bits, so it is exponential in the number of bits of W. Still the standard exam answer.
