# Standard library tour

Python comes with a big standard library. A few modules I keep using.

## collections
| type | use for |
|------|---------|
| `Counter` | counting items, `.most_common(n)` |
| `defaultdict` | dict where missing keys get a default |
| `namedtuple` | tiny class with named fields |
| `deque` | fast append/pop on both ends |

```python
Counter("hello")          # Counter({'l': 2, 'h': 1, 'e': 1, 'o': 1})
d = defaultdict(int); d['x'] += 1
```

## datetime
`date`, `datetime`, `timedelta`.
- `datetime.now()` current time
- `strftime` -> string, `strptime` -> parse a string
- subtract two dates to get a `timedelta`, read `.days`

Format codes: `%Y` year, `%m` month, `%d` day, `%H:%M` time, `%A` weekday name.

## random
- `random()` float 0-1, `randint(a, b)` inclusive
- `choice(seq)`, `sample(seq, k)`, `shuffle(seq)` (in place)
- `seed(n)` makes it repeatable

## os / os.path
- `getcwd()`, `listdir(path)`, `environ`
- `path.join`, `path.exists`, `path.isfile`, `path.splitext`

## itertools
- `count`, `cycle`, `repeat` are infinite - slice them
- `permutations`, `combinations`, `product`
- `chain`, `accumulate`, `groupby`

> deque is much faster than a list for popping from the left.
> groupby only groups items that are next to each other, sort first if needed.
