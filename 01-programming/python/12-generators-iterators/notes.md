# Generators and Iterators

## Iterator
An object you can call `next()` on to get the next value, until it raises
`StopIteration`. A `for` loop does this for you behind the scenes.

To make your own iterator class you need two methods:
- `__iter__` - returns the iterator (usually `self`)
- `__next__` - returns the next value, or raises `StopIteration` when done

```python
class Countdown:
    def __init__(self, start): self.n = start
    def __iter__(self): return self
    def __next__(self):
        if self.n <= 0: raise StopIteration
        self.n -= 1
        return self.n + 1
```

## Generator
A much easier way - just use `yield` inside a function. Python builds the
iterator for you. Each `yield` hands back a value and pauses; the next `next()`
resumes right after it.

```python
def count_up(n):
    i = 1
    while i <= n:
        yield i
        i += 1
```

`next(g)` gets one value at a time. `list(g)` or a `for` loop drains it.
A generator can only be walked once.

## Generator expression
Like a list comp but with `()` - lazy, doesn't build the whole list.
```python
evens = (x for x in nums if x % 2 == 0)
```

## Infinite generators
`while True: yield ...` never stops on its own, so consume with a `break` or a
`take(gen, k)` helper. `itertools.count` and `itertools.cycle` are infinite too.

## yield from
Delegates to another iterable instead of looping and yielding each item.
```python
def both():
    yield from letters()
    yield from numbers()
```

## Some itertools
| function | does |
|----------|------|
| `count(start, step)` | infinite counting |
| `cycle(seq)` | repeat a sequence forever |
| `chain(a, b)` | join iterables end to end |
| `accumulate(seq)` | running totals |
| `combinations(seq, r)` | r-length combos |
| `permutations(seq, r)` | r-length orderings |

> Generators save memory - they make values one at a time instead of storing all.
