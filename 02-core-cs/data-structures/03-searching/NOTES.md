# Searching

Finding the position of a key in an array. Two basic ones this semester -
linear and binary - plus interpolation and a couple of variations.

## Linear search
Walk through the array one by one and compare each element with the key. Works
on ANY array, sorted or not - that is its only real advantage. Slow for large
arrays because worst case you touch every element.

## Binary search
Repeatedly look at the middle element and throw away half the array. Only works
if the array is SORTED - this is the precondition, forget it and you get wrong
answers. Each step compares key with a[mid] and moves left (high = mid - 1) or
right (low = mid + 1).

> Sir in class: "binary search on an unsorted array is not an error the compiler
> catches, it just quietly gives you the wrong answer."

Got this wrong in the lab the first time - searched an unsorted array and it said
"not found" for a value that was clearly there. Sorted the array first, worked.

## Interpolation search
Like binary search but instead of always taking the middle it *estimates* where
the key probably is, from the values at low and high:

    probe = low + ((key - a[low]) * (high - low)) / (a[high] - a[low])

Good when the data is sorted AND spread out evenly (like 10, 20, 30, ...). On
that kind of data it can reach O(log log n). On skewed data it slows to O(n).
Have to guard against a[high] == a[low] or you divide by zero.

## Sentinel linear search
Small trick - copy the key into the slot just past the end as a "sentinel", so
the loop is guaranteed to stop and you drop the i < n test every iteration. Same
O(n) but a little faster in practice. Need one spare slot in the array.

## First and last occurrence
When the sorted array has duplicates a normal binary search finds *some* match,
not necessarily the first or last one. Trick: when you hit the key, don't stop -
keep searching left for the first index, right for the last.

## Complexity

| search           | best | worst    | precondition     |
|------------------|------|----------|------------------|
| linear           | O(1) | O(n)     | none             |
| sentinel linear  | O(1) | O(n)     | one spare slot   |
| binary           | O(1) | O(log n) | sorted           |
| interpolation    | O(1) | O(n)     | sorted + uniform |

Space is O(1) for the iterative versions. Recursive binary search uses O(log n)
of stack for the calls.
