# Brute force

Second unit. Brute force is the most straightforward way to solve a problem - you go
straight off the problem statement and the definitions, no cleverness. Sort by
repeatedly picking the smallest, search by looking at every element, match a pattern by
trying it at every position. It is usually the first algorithm anyone writes for a
problem, and often the slowest.

It matters because it is the baseline. Almost every problem has a brute-force solution,
it is easy to get right, and its output is the reference you check the clever
O(n log n) version against. And when n is small, brute force is all you need.

> "Never look down on brute force. On a small input it is correct, quick to write, and
> impossible to argue with." - lecturer.

## The sorting pair
Both are Theta(n^2), both dead simple.

- Selection sort - n-1 passes; each pass scans the unsorted tail, finds the minimum and
  swaps it into place. The comparison count is fixed at n(n-1)/2 whatever the input.
- Bubble sort - compare adjacent pairs and swap if out of order; each pass floats the
  largest remaining element to the end. Also n(n-1)/2 comparisons in the plain form.

## Sequential search
Walk the array left to right until the key turns up or you run out - Theta(n) worst
case. The sentinel variant parks a copy of the key just past the end, so the loop needs
only one test (a[i]==key) instead of two; it still stops, on the sentinel if nowhere
else. Same order, a little less work per step. (03_sequential_search.cpp does both.)

## Brute-force string matching
Text of length n, pattern of length m. Line the pattern up at shift 0 and compare left
to right; on a mismatch slide one position right and start the compare over. Worst case
Theta(nm) - text "aaaa...a" against pattern "aaab" backtracks m characters at every
shift. Fine for short patterns, and the base every faster matcher improves on.

## Exhaustive search
Brute force for combinatorial problems - generate every candidate, keep the best.

- 0/1 knapsack - every subset of n items is a candidate, so 2^n of them. Take each that
  fits the capacity, keep the highest value. O(2^n).
- Travelling salesman - every ordering of the cities is a tour, (n-1)! once you fix the
  start city. Add up each round trip, keep the cheapest. O(n!).
- Assignment - one job per worker, so every permutation of the jobs is a candidate, n!
  of them. Keep the cheapest total. O(n!).

next_permutation from <algorithm> hands us the orderings - the point here is the
exhaustive idea, not the permutation trick. These blow up fast: 15! is already about
10^12, so exhaustive search is more a definition of the problem than a method you run
for large n. That pain is exactly what motivates the later units - divide-and-conquer,
greedy, dynamic programming.

## Complexity table
```
program                          brute-force cost
--------------------------------------------------
selection / bubble sort          Theta(n^2)
sequential search                Theta(n)
string matching                  O(nm)
closest pair (all pairs)         Theta(n^2)
knapsack (all subsets)           O(2^n)
TSP (all tours)                  O(n!)
assignment (all permutations)    O(n!)
```
