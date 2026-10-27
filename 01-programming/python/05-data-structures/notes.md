# Data Structures

Notes on lists, tuples, sets and dicts.

## List
Ordered, mutable, allows duplicates. `nums = [1, 2, 3]`

| method | what it does |
|--------|--------------|
| append(x) | add x at the end |
| insert(i, x) | put x at index i |
| remove(x) | remove first x |
| pop(i) | remove and return item at i (last if no i) |
| index(x) | position of first x |
| count(x) | how many x |
| sort() | sort in place |
| reverse() | reverse in place |

## Slicing
`a[start:stop:step]` - stop is not included.
```
a = [10, 20, 30, 40, 50]
a[1:3]   -> [20, 30]
a[::-1]  -> reversed
```

## Tuple
Like a list but immutable. `t = (1, 2, 3)`. Good for fixed data.
Packing / unpacking: `x, y = 3, 5`. Swap: `a, b = b, a`.

## Set
Unordered, no duplicates. `s = {1, 2, 3}`.

| operation | symbol |
|-----------|--------|
| union | `a \| b` |
| intersection | `a & b` |
| difference | `a - b` |
| symmetric diff | `a ^ b` |

## Dict
Key-value pairs. `d = {'a': 1}`.
- `d.get(k, default)` - safe lookup, no error if key missing
- `d.keys()`, `d.values()`, `d.items()`
- loop with `for k, v in d.items():`

> remember: keys must be unique and immutable (str, int, tuple).
