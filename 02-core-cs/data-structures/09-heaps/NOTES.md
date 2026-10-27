# Heaps

A heap is a complete binary tree stored in an array. Complete = every level full
except maybe the last, which fills left to right. Because it is complete there are
no gaps, so we can throw away the pointers and just use an array.

## Array representation
Two conventions, both used in the programs here.

1-indexed (root at 1), used in 01_max_heap and 02_min_heap:
- parent of i  -> i/2
- left child   -> 2*i
- right child  -> 2*i + 1

0-indexed (root at 0), used in heap_sort, heapify, kth_largest:
- parent of i  -> (i-1)/2
- left child   -> 2*i + 1
- right child  -> 2*i + 2

## Max-heap vs min-heap
- Max-heap: every parent >= its children, so the largest is at the root.
- Min-heap: every parent <= its children, so the smallest is at the root.
The heap only guarantees the root, NOT full sorted order. Siblings can be in any order.

## Insert - sift up
Put the new element at the end (keeps it complete), then swap it up with its parent
while it is bigger than the parent (max-heap). Stops when it reaches the root or the
parent is bigger. Height is log n so at most log n swaps.

## Delete-max - sift down
The max is at the root. Move the last element to the root, shrink the size, then push
it down: keep swapping with the larger of its two children while a child is bigger.
Again at most log n swaps.

## Build-heap (heapify)
Given a random array, start from the last internal node (n/2 - 1) and sift_down each
node going up to the root. Looks like O(n log n) but the tight bound is O(n) because
most nodes are near the bottom and barely move.

## Heap sort
Build a max-heap. Then repeatedly swap the root (max) with the last element, shrink
the heap by one, and sift_down the new root. After n steps the array is sorted
ascending. In place, O(n log n), not stable.

## Priority queue
A heap is the natural way to build a priority queue - insert an item with a priority,
and dequeue always returns the highest (or lowest) priority item in O(log n). Used in
Dijkstra, Huffman coding, CPU scheduling.

## Complexity

| operation    | time      |
|--------------|-----------|
| insert       | O(log n)  |
| delete-max   | O(log n)  |
| peek max/min | O(1)      |
| build-heap   | O(n)      |
| heap sort    | O(n log n)|
| search       | O(n)      |

> sir said in class: a heap is "half sorted" - enough order to grab the max fast,
> not enough to list everything in order without work.

Got the sift-down wrong in the lab first time - I compared with the left child only
and forgot to pick the larger child, so it broke the heap. Have to check both children.
