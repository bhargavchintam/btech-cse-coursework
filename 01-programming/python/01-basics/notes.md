# Basics

First unit. Getting comfortable with printing, variables and simple input/output.

## print
`print()` writes to the screen. Multiple items separated by comma get a space between them.

```python
print("a =", 5)   # a = 5
```

## variables
No need to declare a type. Just assign. The type comes from the value.

```python
name = "Ravi"
age = 19
pi = 3.14
```

You can reassign a variable to a different type later, Python won't stop you.

## data types
| type  | example      |
|-------|--------------|
| int   | `10`         |
| float | `3.14`       |
| str   | `"hi"`       |
| bool  | `True`       |
| list  | `[1, 2, 3]`  |
| tuple | `(4, 5)`     |
| dict  | `{"x": 1}`   |

`type(x)` tells you the type of x.

## operators
`+ - * /` and also:
- `//` floor division (drops the fraction)
- `%` remainder
- `**` power

`/` always gives a float, `10 / 2` is `5.0`.

## input
`input()` always returns a string. Wrap it in `int()` or `float()` to get a number.

```python
n = int(input("number: "))
```

> Careful: `int(input())` on non-number text will crash. That's fine for now.

## swap
Python lets you swap without a temp variable:

```python
a, b = b, a
```
