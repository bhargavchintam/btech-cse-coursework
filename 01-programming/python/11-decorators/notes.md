# Decorators

A decorator is a function that takes a function and returns a new function that
wraps the old one. Lets you add behaviour (logging, timing, counting) without
touching the original code.

## The @ syntax
```python
@greet
def hello():
    ...
```
is just shorthand for `hello = greet(hello)`.

## Basic shape
```python
def deco(func):
    def wrapper(*args, **kwargs):
        # do stuff before
        res = func(*args, **kwargs)
        # do stuff after
        return res
    return wrapper
```
Use `*args, **kwargs` so the wrapper works for any function. And `return res`
so the wrapped function's return value doesn't get lost.

## Decorator that takes arguments
Need one more layer: outer function takes the arg, returns the real decorator.
```python
def repeat(n):
    def deco(func):
        def wrapper(*a, **k):
            for i in range(n):
                func(*a, **k)
        return wrapper
    return deco

@repeat(3)
def say(m): print(m)
```

## functools.wraps
Wrapping replaces the function's `__name__` and `__doc__` with the wrapper's.
`@wraps(func)` copies them back so the original still looks like itself.

| without wraps | with wraps |
|---------------|------------|
| `add.__name__` -> `'wrapper'` | `add.__name__` -> `'add'` |

## Class as a decorator
A class with `__call__` can be used as a decorator. `__init__` gets the
function, `__call__` runs on every call - handy for keeping state like a count.

> Order matters when stacking: the closest `@` to the function runs first.
