# Divide and conquer

Second design paradigm of the course (after brute force). The idea is old and simple:
if a problem on size n is hard, break it into a few smaller copies of the SAME problem,
solve those, then stitch the answers together. Three steps, every time:

- divide   - split the input into a subproblems, each about n/b the size
- conquer  - solve each subproblem recursively (recursion bottoms out at a trivial size)
- combine  - merge the sub-answers into the answer for the whole

Merge sort is the cleanest example: divide the array in two, sort each half, MERGE the two
sorted halves. The real work sits in the combine step. Quicksort flips it - the work is in
the divide (the partition) and the combine does nothing.

## The recurrence and the master theorem
Splitting into a pieces of size n/b with f(n) work to divide+combine gives

```
T(n) = a T(n/b) + f(n)
```

which is exactly the shape the master theorem (see 01-analysis/NOTES.md) was built for.
Compare d (from f(n) = n^d) against e = log_b(a):

- merge sort    a=2, b=2, f(n)=n   -> d=1, e=1, case 2 -> Theta(n log n)
- binary search a=1, b=2, f(n)=1   -> d=0, e=0, case 2 -> Theta(log n)
- max & min     a=2, b=2, f(n)=1   -> leaves dominate  -> Theta(n)
- Strassen      a=7, b=2, f(n)=n^2 -> d=2 < 2.807, case 1 -> Theta(n^2.807)

The trick that makes Strassen and Karatsuba interesting is that they lower a. Ordinary 2x2
matrix multiply does 8 recursive multiplies (a=8 -> n^3); Strassen rearranges the algebra to
need only 7 (a=7 -> n^2.807). Karatsuba does the same for big-number multiplication, 4 half
multiplies down to 3 (n^2 -> n^1.585). Fewer subproblems, smaller exponent.

## When it helps
D&C wins when the combine step is cheap next to the work saved by splitting. If combining
costs as much as just solving directly, you gain nothing. It also needs the subproblems to be
independent - overlapping subproblems are the job of dynamic programming (unit 08), not this.

> got asked in the internal: if quicksort is divide & conquer why is it O(n^2) worst case?
> because a bad pivot splits n into 0 and n-1, the halves are not balanced, so the recurrence
> is T(n)=T(n-1)+n, not T(n)=2T(n/2)+n. the balanced split is the whole point.

## Files here
```
01_merge_sort.cpp           recursive merge, work in the combine
02_quick_sort.cpp           Lomuto partition, work in the divide
03_binary_search.cpp        throw away one half each step
04_max_min.cpp              max and min together, ~3n/2 comparisons
05_karatsuba_multiply.cpp   big multiply, 3 half multiplies not 4
06_strassen_matrix.cpp      2x2 matrix, 7 products not 8
07_closest_pair.cpp         points in a plane, strip merge
08_count_inversions.cpp     piggyback on the merge step
```

## Complexity table
```
algorithm             recurrence                order
------------------------------------------------------------
binary search         T(n)=T(n/2)+1             O(log n)
max & min             T(n)=2T(n/2)+2            O(n)
merge sort            T(n)=2T(n/2)+n            O(n log n)
quick sort (avg)      T(n)=2T(n/2)+n            O(n log n)
quick sort (worst)    T(n)=T(n-1)+n             O(n^2)
count inversions      T(n)=2T(n/2)+n            O(n log n)
closest pair          T(n)=2T(n/2)+n log n      O(n log^2 n)
karatsuba             T(n)=3T(n/2)+n            O(n^1.585)
strassen              T(n)=7T(n/2)+n^2          O(n^2.807)
```
