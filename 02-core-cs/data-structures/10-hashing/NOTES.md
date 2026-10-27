# Hashing

Searching an array is O(n), a balanced tree is O(log n). Hashing tries to do better -
average O(1) search - by computing WHERE a key should sit instead of comparing our way
to it.

## Hash table and hash function
A hash table is an array of slots. A hash function maps a key to an index:
`index = h(key)`. The simplest one for integers is the division method:
`h(key) = key % SIZE`. A good hash function spreads keys evenly and is fast to compute.
SIZE being a prime number helps spread them better.

## Load factor
`load factor = number of keys / table size`. It measures how full the table is. As it
grows, collisions get more likely and performance drops. For open addressing we keep it
below about 0.7; past that you rehash into a bigger table.

## Collision
Two different keys hashing to the same index is a collision. Cannot be avoided in
general (more possible keys than slots), so we need a resolution method.

## Separate chaining
Each slot holds a linked list (a "chain"). On collision, add the key to that slot's
list. Insert is O(1), search walks one chain. Table can hold more keys than slots.
Simple, and delete is easy. Downside is the extra pointer memory. -> 01_hash_chaining

## Open addressing
All keys live in the array itself. On collision, probe for another empty slot using
some sequence. Load factor must stay below 1.

- Linear probing: try h, h+1, h+2, ... (mod SIZE). Easy, but keys clump together in
  runs ("primary clustering") which slows things down. Delete needs a "deleted" marker
  so a search does not stop early at a hole. -> 02_hash_linear_probing
- Quadratic probing: try h, h+1, h+4, h+9, ... (h + i*i). Spreads the probes out and
  avoids primary clustering, but two keys with the same home slot still follow the same
  path ("secondary clustering"). -> 03_hash_quadratic_probing
- Double hashing: the step size itself comes from a second hash,
  `(h1(key) + i*h2(key)) % SIZE`. h2 must never be 0. Best spread of the three. -> 04

## When to use which
- Chaining: unknown or growing number of keys, frequent deletes.
- Linear probing: small tables, cache friendly, few deletes.
- Quadratic / double hashing: when clustering with linear probing hurts.

## Complexity

| operation | average | worst |
|-----------|---------|-------|
| insert    | O(1)    | O(n)  |
| search    | O(1)    | O(n)  |
| delete    | O(1)    | O(n)  |

Worst case is O(n) when every key collides into one slot / one long chain. A good hash
function and a low load factor keep us near the average.

> lecturer: "a hash table is a trade - you spend memory (empty slots) to buy speed."

In the lab I forgot the deleted-marker in linear probing and search kept stopping at
the emptied slot, so half my keys "disappeared". Marking the slot deleted (not empty)
fixed it.
