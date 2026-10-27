# Control flow

Making decisions and repeating things.

## if / elif / else
Indentation matters, the body must be indented (4 spaces).

```python
if x > 0:
    print("positive")
elif x == 0:
    print("zero")
else:
    print("negative")
```

You can have as many `elif` as you want. `elif` and `else` are optional.

## while
Repeats as long as the condition is True.

```python
i = 1
while i <= 5:
    print(i)
    i += 1
```

Don't forget to change the variable inside, otherwise it loops forever.

## for and range
`range(a, b)` gives numbers from a up to b-1.

```python
for i in range(1, 6):
    print(i)      # 1 2 3 4 5
```

- `range(n)` -> 0 .. n-1
- `range(a, b)` -> a .. b-1
- `range(a, b, step)` -> with a step

## break and continue
- `break` stops the loop early.
- `continue` skips to the next round.

## leap year rule
Divisible by 4, but century years must be divisible by 400.
So 2000 is a leap year, 1900 is not.

> Reversing a number: keep taking `n % 10` for the last digit and `n // 10` to drop it.
