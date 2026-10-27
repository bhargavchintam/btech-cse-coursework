# Functional programming

Treating functions as values - passing them around, returning them, building
small pieces and combining them.

## map, filter, reduce
- `map(func, seq)` - apply func to every item
- `filter(func, seq)` - keep items where func is true
- `reduce(func, seq)` - fold the whole thing into one value (needs `functools`)

```python
list(map(lambda x: x*x, nums))
list(filter(lambda x: x % 2 == 0, nums))
reduce(lambda a, b: a + b, nums)   # sum
```
map and filter give back lazy objects, so wrap in `list()` to see them.

## lambda
A one-line anonymous function. `lambda a, b: a + b` is the same idea as a small
`def`. Great as a `key=` for `sorted`/`sort`, or when you need a quick throwaway.
Don't force big logic into one - use `def` then.

## Closures
An inner function that remembers variables from the function that made it.
```python
def multiplier(n):
    def mul(x): return x * n
    return mul
times3 = multiplier(3)   # remembers n = 3
```
Use `nonlocal` if the inner function needs to reassign an outer variable
(like a running counter).

## functools.partial
Locks in some arguments and gives back a new function.
```python
square = partial(power, exp=2)
to_bin = partial(int, base=2)
```

## Higher order functions
Any function that takes a function as an argument or returns one. `map`,
`filter`, `sorted(key=...)` are all higher order. You can write your own too.

## Composition
Chaining functions so one's output is the next one's input.
```python
def compose(f, g):
    return lambda x: f(g(x))
```

> Small functions that do one thing are easy to test and easy to combine.
