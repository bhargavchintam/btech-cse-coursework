# Patterns

Printing shapes with stars and numbers. Good practice for nested loops.

## the idea
The outer loop is the row, the inner loop (or a string trick) is what's in that row.

```python
for i in range(1, n + 1):
    print("*" * i)
```

`"*" * i` repeats the star i times. Very handy, avoids an inner loop.

## end=""
By default `print` adds a newline. Use `end=""` to stay on the same line, then a
plain `print()` at the end to break the line.

```python
for j in range(1, i + 1):
    print(j, end="")
print()
```

## pyramid spacing
For a centered pyramid, row i needs `n - i` leading spaces and `2*i - 1` stars.

```
    *
   ***
  *****
```

## floyd's triangle
Numbers 1, 2, 3, ... filled row by row. Keep one counter that never resets.

## pascal's triangle
Each row starts and ends with 1, and every middle value is the sum of the two
values above it. Build the next row from the current one.

> Tip: build the shape on paper first, count the spaces, then translate to loops.
