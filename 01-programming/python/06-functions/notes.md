# Functions

A reusable block of code. Define with `def`, call it by name.

```
def add(a, b):
    return a + b
```

## Arguments
- **positional** - `add(3, 4)`, matched by order
- **default** - `def greet(name, msg="hi")`, msg is optional
- **keyword** - `student(age=20, name="ravi")`, order does not matter
- **\*args** - collects extra positional args into a tuple
- **\*\*kwargs** - collects extra keyword args into a dict

```
def total(*nums):
    return sum(nums)
```

## return
A function with no `return` gives back `None`.

## Lambda
A small one-line anonymous function.
```
square = lambda x: x * x
```
Useful with `map`, `filter`, `sorted`.

## Recursion
Function that calls itself. Must have a base case or it never stops.
```
def fact(n):
    if n == 0:
        return 1
    return n * fact(n-1)
```

## Scope
- a variable made inside a function is **local**
- use `global x` to change a global variable from inside a function

> gotcha: don't use a mutable default like `def f(x=[])` - the same list gets shared between calls.
