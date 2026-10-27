# Transform and conquer

The trick here is: don't attack the problem head on. First TRANSFORM it into something
easier, then solve that. The transform + the solve together are still cheaper than the
brute force. Levitin splits it into three flavours.

## The three flavours

**1. Instance simplification** - transform to a simpler instance of the SAME problem.
Presorting is the standard one: many problems get easy once the data is sorted.
- element uniqueness: sort, then one scan - a duplicate can only sit next to its twin.
- mode (most frequent value): sort, then the equal values are in one run, just measure runs.
- searching a lot: sort once (n log n), then every search is binary (log n).
Brute force uniqueness is n^2 (all pairs). Presort makes it n log n + n = n log n.

**2. Representation change** - same instance, DIFFERENT data structure or form.
- heap: rearrange the array so it obeys the heap property, then heap sort / priority queue.
- Horner's rule: rewrite a+bx+cx^2+dx^3 as ((d*x+c)*x+b)*x+a. Same polynomial, nested form,
  n multiplications instead of ~n^2.
- Gaussian elimination: turn the coefficient matrix into upper-triangular, then back-substitute.
- AVL / 2-3 trees: keep a BST balanced so height stays log n.

**3. Problem reduction** - transform to a DIFFERENT problem you already know how to solve.
- lcm(a,b) = a*b / gcd(a,b)  -> reduce lcm to gcd (Euclid).
- counting paths / many graph questions -> reduce to matrix multiplication.
- lots of optimisation problems -> reduce to linear programming.

> "If you can't solve it, change it into a problem you already solved." - lecturer, unit 5.

## Presorting template

```
sort the array                 // n log n, the transform
scan / one pass on sorted data // n, the easy solve
```

## Horner - why it's the good one

Naive evaluation computes each power x^k separately, so degree n costs about n(n+1)/2 mults.
Horner factors x out at every step:

```
p = coeff[highest]
for each lower coeff c:  p = p * x + c
```

n multiplications and n additions, full stop. It also gives synthetic division for free.

## Heap in one line

Array viewed as a complete binary tree: node i has children 2i+1 and 2i+2 (0-indexed).
Max-heap => parent >= children, so the max is always at index 0. Build is O(n) (not n log n,
the bound is tighter than it looks), each delete-max is log n.

## Complexity table

```
problem / method                    transform        after transform     total
--------------------------------------------------------------------------------
element uniqueness (presort)        sort  n log n     scan  n             n log n
mode (presort)                      sort  n log n     scan  n             n log n
heap sort                           build heap  n     n * delete  n log n n log n
Horner evaluation                   -                 n mults            O(n)
Gaussian elimination (n x n)        to triangular n^3 back-sub  n^2       n^3
AVL insert / search                 rotations O(1)    height  log n       log n
lcm via gcd                         -                 Euclid  log n       O(log n)
```

Brute force for comparison: uniqueness n^2, naive polynomial eval n^2, unbalanced BST can
degrade to n. The transform is what buys the better order.
