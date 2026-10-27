# Python quick reference

Everything in one place so I don't have to dig through each folder before a lab or exam.
Python 3 (3.6/3.7). Run a file with `python3 file.py`.

## Data types

| type | example | notes |
|------|---------|-------|
| int | `5`, `-3` | whole numbers, no size limit |
| float | `3.14`, `2.0` | decimals |
| bool | `True`, `False` | really 1 and 0 |
| str | `"hi"`, `'hi'` | text, immutable |
| list | `[1, 2, 3]` | ordered, mutable |
| tuple | `(1, 2)` | ordered, immutable |
| set | `{1, 2}` | unordered, no duplicates |
| dict | `{"a": 1}` | key -> value |
| NoneType | `None` | the "nothing" value |

`type(x)` tells the type. `int("5")`, `float("3.1")`, `str(9)`, `list("abc")` convert.

## Operators

| kind | operators |
|------|-----------|
| arithmetic | `+  -  *  /  //  %  **` |
| comparison | `==  !=  <  >  <=  >=` |
| logical | `and  or  not` |
| assignment | `=  +=  -=  *=  /=  //=` |
| membership | `in`, `not in` |
| identity | `is`, `is not` |

`/` always gives a float, `//` floor-divides, `%` is remainder, `**` is power.

## Strings

Immutable. Index with `s[0]`, slice with `s[a:b:step]`, reverse with `s[::-1]`.

| method | does |
|--------|------|
| `s.upper()` / `s.lower()` | change case |
| `s.strip()` | trim spaces (also `lstrip`/`rstrip`) |
| `s.split(sep)` | string -> list |
| `sep.join(list)` | list -> string |
| `s.replace(a, b)` | swap text |
| `s.find(x)` / `s.index(x)` | position (find gives -1, index errors) |
| `s.count(x)` | how many x |
| `s.startswith(x)` / `s.endswith(x)` | check ends |
| `s.isdigit()` / `s.isalpha()` | what's inside |

f-string: `f"{name} is {age}"`. Also `"{} {}".format(a, b)`.

## Lists

| method | does |
|--------|------|
| `a.append(x)` | add at end |
| `a.insert(i, x)` | add at index i |
| `a.extend(b)` | add all of b |
| `a.remove(x)` | drop first x |
| `a.pop(i)` | remove + return (last if no i) |
| `a.sort()` / `a.reverse()` | in place |
| `a.index(x)` / `a.count(x)` | lookups |
| `sorted(a)` | returns a new sorted list |

## Dicts

| thing | does |
|-------|------|
| `d[k]` | get (errors if missing) |
| `d.get(k, default)` | safe get |
| `d[k] = v` | set / update |
| `del d[k]` | remove |
| `d.keys()` `d.values()` `d.items()` | views |
| `k in d` | membership (checks keys) |

Loop: `for k, v in d.items():`

## Sets

`a | b` union, `a & b` intersection, `a - b` difference, `a ^ b` symmetric diff.
`a.add(x)`, `a.discard(x)`. Great for removing duplicates: `list(set(nums))`.

## Control flow

```python
if x > 0:
    ...
elif x == 0:
    ...
else:
    ...

for i in range(1, 5):     # 1,2,3,4
    ...

while cond:
    ...
    break        # leave loop
    continue     # skip to next round
```

`range(stop)`, `range(start, stop)`, `range(start, stop, step)` — stop not included.

## Functions

```python
def add(a, b):
    return a + b

def greet(name, msg="hi"):     # default arg
    print(msg, name)

def total(*args):              # any number of positional
    return sum(args)

def info(**kwargs):            # keyword args as a dict
    ...
```

lambda: `sq = lambda x: x * x`. Small one-liners only.

## Comprehensions

```python
[x*x for x in range(5)]              # list
[x for x in nums if x % 2 == 0]      # with filter
{x: x*x for x in range(5)}           # dict
{x % 3 for x in nums}                # set
(x*x for x in range(5))              # generator (lazy)
```

## Classes

```python
class Dog:
    kind = "dog"                 # class attribute

    def __init__(self, name):    # constructor
        self.name = name         # instance attribute

    def speak(self):
        return self.name + " barks"

    def __str__(self):           # what print() shows
        return f"Dog({self.name})"

d = Dog("Rex")
```

Inheritance: `class Puppy(Dog):` then `super().__init__(name)`.
Common dunders: `__init__`, `__str__`, `__len__`, `__eq__`, `__add__`, `__call__`.

## Files and exceptions

```python
with open("f.txt", "w") as f:    # w write, r read, a append
    f.write("hi\n")

with open("f.txt") as f:
    for line in f:
        print(line.strip())

try:
    ...
except ValueError as e:
    ...
except (TypeError, KeyError):
    ...
else:
    ...        # ran if no error
finally:
    ...        # always runs
```

Raise your own: `raise ValueError("bad")`. Custom: `class MyError(Exception): pass`.

## Common built-ins

| built-in | does |
|----------|------|
| `len(x)` | length |
| `range(...)` | number sequence |
| `enumerate(x)` | index + item pairs |
| `zip(a, b)` | pair up two iterables |
| `map(f, x)` | apply f to each |
| `filter(f, x)` | keep where f is true |
| `sorted(x, key=..., reverse=...)` | new sorted list |
| `sum`, `min`, `max`, `abs`, `round` | number helpers |
| `any(x)` / `all(x)` | true if any / all true |
| `input()`, `print()` | I/O |

`map` and `filter` give lazy objects — wrap in `list(...)` to see them.

## Standard library pointers

| module | handy bits |
|--------|-----------|
| `math` | `pi`, `sqrt`, `factorial`, `gcd`, `ceil`, `floor` |
| `random` | `randint`, `choice`, `shuffle`, `random`, `sample` |
| `datetime` | `date.today()`, `datetime.now()`, `timedelta` |
| `collections` | `Counter`, `defaultdict`, `namedtuple`, `deque` |
| `itertools` | `count`, `cycle`, `chain`, `combinations`, `permutations` |
| `functools` | `reduce`, `partial`, `wraps`, `lru_cache` |
| `re` | `match`, `search`, `findall`, `sub`, `group` |
| `os` / `sys` | paths, env, `sys.argv` |
| `json` / `csv` | read/write structured files |

## re (regex) cheats

`.` any char, `\d` digit, `\w` word char, `\s` space, `+` 1+, `*` 0+, `?` optional,
`^` start, `$` end, `[...]` set, `(...)` group. `re.findall(pat, text)` grabs all matches.
