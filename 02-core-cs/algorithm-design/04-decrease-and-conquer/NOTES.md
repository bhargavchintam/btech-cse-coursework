# Decrease and conquer

Third design paradigm of the course. The idea: relate an instance of size n to the SAME
problem on a smaller instance, solve the smaller one, then extend that answer back up to
size n. Only ONE smaller subproblem each step - that is what separates it from divide and
conquer, which splits into several pieces and then combines them.

Usually written top-down as recursion, but almost every one also has a clean bottom-up
(iterative) version - same relation, just built up from the base instead of peeled down
from n.

## The three variants

**1. Decrease by a constant** (nearly always by 1)
    shrink n to n-1, solve that, then fit the nth element back in.
    T(n) = T(n-1) + f(n)
    insertion sort, DFS, BFS, topological sort, generating permutations / subsets.
    f(n) constant -> Theta(n);  f(n) = n -> Theta(n^2).

**2. Decrease by a constant factor** (nearly always by 2)
    throw away a fixed FRACTION each step, so the size falls n -> n/2 -> n/4 -> ...
    T(n) = T(n/2) + f(n)
    binary search, the fake-coin weighing, russian peasant multiplication, a^n by squaring.
    Because the size halves, only about log n steps -> the cheap ones are Theta(log n).

**3. Decrease by a variable amount**
    the chunk you cut off is not fixed, it depends on the data.
    Euclid: gcd(m,n) = gcd(n, m mod n) - the drop m -> m mod n is different every call.
    also interpolation search and quickselect (partition, then recurse on one side only).

> "Divide and conquer solves many small problems. Decrease and conquer solves one." - lecturer

## Insertion sort - the model example (decrease by one)
Assume a[0..i-1] is already sorted. Take a[i], slide it left past everything larger, drop
it in place -> now a[0..i] is sorted. Repeat for i = 1..n-1.
Already-sorted input -> n-1 compares -> Theta(n). Reverse-sorted -> Theta(n^2).

## Binary search view (decrease by a factor)
Compare with the middle element. Either done, or step into ONE half - the other half is
gone for good. n -> n/2 each time, so Theta(log n). It is decrease-by-half and not divide
and conquer precisely because we only ever recurse into a single side.

## Complexity table
```
program                          reduction        time
---------------------------------------------------------------
insertion sort                   n -> n-1         O(n^2) worst, O(n) best
DFS / BFS (adjacency matrix)     one vertex       O(V^2)
topological sort (source rem.)   one vertex       O(V^2)
all permutations of n            n -> n-1         O(n!)  (n! lines out)
all subsets of n                 n -> n-1         O(2^n) (2^n lines out)
binary search                    n -> n/2         O(log n)
fake coin (halving)              n -> n/2         O(log n) weighings
russian peasant multiply         n -> n/2         O(log n) additions
Euclid's gcd                     variable         O(log n)
```

DFS/BFS come out O(V^2) here only because I stored the graph as an adjacency matrix; with
adjacency lists they are O(V+E). Got that mixed up in the internal once.
