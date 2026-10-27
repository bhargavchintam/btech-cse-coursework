# Files and exceptions

## Opening files
`open(name, mode)`. Best to use `with`, it closes the file automatically.

```python
with open("data.txt", "w") as f:
    f.write("hi\n")
```

| mode | meaning |
|------|---------|
| `"r"` | read (default), error if missing |
| `"w"` | write, wipes the file first |
| `"a"` | append, adds to the end |
| `"r+"` | read and write |

Ways to read: `f.read()` whole thing, `f.readline()` one line, `f.readlines()` list,
or just loop `for line in f:` (each line keeps its `\n`, so `.strip()` it).

## csv
```python
import csv
with open("people.csv", "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(["name", "age"])
```
Reading gives back a list of strings per row. Use `newline=""` when writing so you
don't get blank lines on Windows.

## json
Turns Python dicts/lists into text and back.

| function | does |
|----------|------|
| `json.dump(obj, f)` | write object to a file |
| `json.load(f)` | read object from a file |
| `json.dumps(obj)` | object to a string |
| `json.loads(s)` | string to an object |

## try / except
```python
try:
    n = int(input())
except ValueError:
    print("not a number")
```
`except SomeError as e:` gives you the error object to print.

## finally
The `finally` block runs no matter what, even after a `return`. Good for cleanup.

## raise + custom exceptions
`raise ValueError("bad")` to throw one yourself. Make your own by subclassing
`Exception`:

```python
class TooSmall(Exception):
    pass
```

## common errors

| error | when |
|-------|------|
| `ValueError` | right type, wrong value (`int("x")`) |
| `TypeError` | wrong type (`"a" + 1`) |
| `IndexError` | list index out of range |
| `KeyError` | dict key not found |
| `ZeroDivisionError` | divide by 0 |
| `FileNotFoundError` | opening a missing file |

> Catch the specific error you expect. A bare `except:` hides real bugs.
