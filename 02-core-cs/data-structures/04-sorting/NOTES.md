# Sorting

Arranging elements in order (ascending here). Did a lot of these this semester.
The first three are the O(n^2) "simple" sorts, then the faster ones, then the
non-comparison integer sorts.

## Stable vs unstable
A sort is STABLE if two equal elements keep their original relative order. Matters
when records are sorted by one field and you don't want an earlier ordering
disturbed.
Stable: bubble, insertion, merge, counting.
Unstable: selection, shell, quick, heap.

## In-place
In-place = sorts using O(1) extra space, just moving things inside the array.
Bubble, selection, insertion, shell, quick, heap are in-place. Merge needs an
extra array to merge into. Counting, radix and bucket use extra arrays too.

## The sorts
- Bubble - compare adjacent pairs, swap if out of order, big values "bubble" to
  the end. Wrote the plain version, no swapped-flag shortcut.
- Selection - find the minimum of the unsorted part and put it in place. Does the
  fewest swaps of any of these.
- Insertion - take each element and slide it into the sorted left part. Very fast
  when the array is already nearly sorted.
- Shell - insertion sort but comparing elements a "gap" apart, gap halves down to 1.
- Merge - split in half, sort each half, merge them. O(n log n) no matter what.
- Quick - pick a pivot, partition into smaller/larger, recurse. Fast in practice
  but O(n^2) worst case on bad pivots. Used Lomuto partition (pivot = last).
- Heap - build a max heap, swap the root to the end, shrink and re-heapify.
- Counting - count how many of each value, then write them back. No comparisons,
  but needs a small integer range.
- Radix - counting sort applied digit by digit, least significant digit first.
- Bucket - scatter values into buckets by range, sort each bucket, join them.

Counting, radix and bucket here all assume non-negative integers.

## Complexity

| sort      | best       | average    | worst      | stable | in-place |
|-----------|------------|------------|------------|--------|----------|
| bubble    | O(n^2)     | O(n^2)     | O(n^2)     | yes    | yes      |
| selection | O(n^2)     | O(n^2)     | O(n^2)     | no     | yes      |
| insertion | O(n)       | O(n^2)     | O(n^2)     | yes    | yes      |
| shell     | O(n log n) | depends    | O(n^2)     | no     | yes      |
| merge     | O(n log n) | O(n log n) | O(n log n) | yes    | no       |
| quick     | O(n log n) | O(n log n) | O(n^2)     | no     | yes      |
| heap      | O(n log n) | O(n log n) | O(n log n) | no     | yes      |
| counting  | O(n+k)     | O(n+k)     | O(n+k)     | yes    | no       |
| radix     | O(d(n+k))  | O(d(n+k))  | O(d(n+k))  | yes    | no       |
| bucket    | O(n+k)     | O(n+k)     | O(n^2)     | yes    | no       |

k = range of the values, d = number of digits.

## Which to use when
- Small or nearly-sorted array: insertion.
- Need a guaranteed O(n log n): merge or heap.
- General fast in-memory sort: quick, with a reasonable pivot.
- Integer keys in a small range: counting or radix, beats the O(n log n) bound.
- Need stability: merge (or counting).

Bubble is really only for teaching - it is almost never the right choice in
practice.
