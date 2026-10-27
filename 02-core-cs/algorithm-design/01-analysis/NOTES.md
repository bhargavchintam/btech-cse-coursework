# Analysis of algorithms

First unit of DAA. Same idea as the analysis we did in DSA, but pushed harder -
recurrences and the master theorem come in here. The point is to judge an algorithm
by how its cost GROWS with the input size n, not by timing it once on one laptop.

## Asymptotic notation
Three bounds on the growth for large n:

- Big-O   (O)    upper bound. f(n)=O(g(n)) => f grows no faster than g. Worst-case
                 guarantee, the one quoted most often.
- Omega   (Om)   lower bound. f grows at least as fast as g.
- Theta   (Th)   tight bound. f is O(g) AND Omega(g), so g is the exact growth.

Drop constants and lower-order terms: 3n^2 + 5n + 7 is Theta(n^2). Once n is large the
5n and the 7 do not matter.

> "O is a promise you will not do worse. Theta is the truth." - lecturer.

## Orders of growth
From slowest-growing to fastest. This ordering is worth memorising:

```
1  <  log n  <  n  <  n log n  <  n^2  <  n^3  <  2^n  <  n!
```

log n barely moves, 2^n explodes. An n^2 algorithm on n=10^5 is already 10^10 steps -
too slow. That gap is the whole reason we care about the order and not the constant.
(01_order_of_growth.cpp prints these columns side by side so the gap is visible.)

## Best / average / worst case
Same algorithm, different inputs:
- best     - luckiest input (linear search, key first -> 1 compare)
- worst    - nastiest input (key absent -> n compares)
- average  - expected over all inputs (~n/2 compares)

We usually state the worst case because it is a guarantee.

## Counting the basic operation
Pick the operation that runs most often (a comparison, an addition) and count it as a
function of n.
- sum 1..n            -> the addition runs n times          -> Theta(n)
- max of n elements   -> n-1 comparisons                    -> Theta(n)
- two nested loops    -> n*n                                 -> Theta(n^2)
- halving loop        -> log2(n)                             -> Theta(log n)

Sequential blocks ADD, nested blocks MULTIPLY.

## Recurrence relations
When an algorithm is recursive, its running time is written as a recurrence and then
solved. Two we solve by unfolding (see 04_recurrence_examples.cpp):

- T(n) = T(n-1) + n,  T(0)=0     unfolds to  n + (n-1) + ... + 1 = n(n+1)/2 => Theta(n^2)
- T(n) = 2T(n/2) + n, T(1)=1     unfolds to  n + n + ... (log n levels) => Theta(n log n)

Methods: substitution (guess and prove by induction), recursion tree, and for the
divide-and-conquer shape, the master theorem below.

## Master theorem
For divide and conquer of the form

```
T(n) = a T(n/b) + f(n),   a >= 1,  b > 1,   f(n) = n^d
```

compare d with log_b(a). Let e = log_b(a):

- Case 1:  d < e     ->  T(n) = Theta(n^e)          (leaves dominate)
- Case 2:  d = e     ->  T(n) = Theta(n^d log n)    (balanced, every level equal)
- Case 3:  d > e     ->  T(n) = Theta(n^d)          (root/top level dominates)

Examples:
- merge sort   a=2,b=2,d=1: e=1, d=e -> Theta(n log n)     (case 2)
- binary search a=1,b=2,d=0: e=0, d=e -> Theta(log n)      (case 2)
- Strassen     a=7,b=2,d=2: e=2.807, d<e -> Theta(n^2.807) (case 1)

05_master_theorem.cpp reads a, b, d and prints which case and the resulting order.

## Amortized idea
Sometimes a single operation is occasionally expensive but rare, so the AVERAGE over a
long sequence is cheap. Classic case: pushing into a dynamic array (vector). Most pushes
are O(1); once in a while it doubles and copies everything (O(n)), but that cost is spread
over the next n cheap pushes, so each push is O(1) *amortized*. It is a per-sequence
average, not a per-call worst case - different from average-case analysis.

## Small table
```
algorithm / operation            time
------------------------------------------
array access a[i]                O(1)
binary search                    O(log n)
linear scan / sum / max          O(n)
merge sort, quick sort (avg)     O(n log n)
selection / bubble sort          O(n^2)
all subsets (0/1 knapsack)       O(2^n)
all permutations (TSP)           O(n!)
```
