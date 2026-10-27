# Space and time trade-offs

The trade: spend some extra memory now so the algorithm runs faster later. The whole
chapter is built on that one bargain. Levitin splits it into two styles.

## Input enhancement
Preprocess (part of) the input into an auxiliary table, then let the table do the work.
- comparison counting sort - for each element count how many are smaller; that count IS
  its final index. One n^2 counting pass, then place. (01_comparison_counting_sort.cpp)
- distribution counting sort - when the values sit in a small range [lo..hi], build a
  frequency table, turn it into a distribution (running sum) table, and drop each element
  straight into its slot. Linear, and stable if you fill right to left.
  (02_distribution_counting_sort.cpp)
- the pattern shift tables in Horspool / Boyer-Moore (chapter 11) are the same idea:
  preprocess the pattern once, then skip.

## Prestructuring
Don't touch the algorithm - store the data in a structure that makes access cheap. The
big one is hashing.

## Hashing
A hash function h(k) maps a key to an index in a table of size m, usually h(k) = k % m.
Ideally O(1) to insert and search. Two keys can land on the same index - a collision -
and there are two schools for dealing with it:

- open hashing / separate chaining - each cell holds a linked list; colliding keys just
  get added to the list. The table never fills up. Search cost = length of that chain.
  (03_open_hashing.cpp)
- closed hashing / open addressing - everything lives in the array itself. On a collision
  probe the next slot (linear probing: h+1, h+2, ... mod m) until an empty one turns up.
  The table can fill, so keep the load factor a = n/m well under 1. (04_closed_hashing.cpp)

load factor a = (keys) / (table size). Chaining still works at a > 1; linear probing
degrades badly as a approaches 1 because of clustering.

> "extra space buys you time only if the preprocessing is cheaper than what it saves."

## Complexity
```
method                         time                 space
-----------------------------------------------------------------
comparison counting sort       Theta(n^2)           n
distribution counting sort     Theta(n)             n + range
hashing - insert/search avg    O(1)                 m
hashing - insert/search worst  O(n)                 m
```
distribution counting beats an n log n sort only when the value range is small - that is
the catch, the table size is the price you pay.
