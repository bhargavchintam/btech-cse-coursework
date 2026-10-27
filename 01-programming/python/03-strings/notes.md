# Strings

Strings are sequences of characters. They are immutable, you can't change a character in place.

## indexing and slicing
```python
s = "python"
s[0]      # 'p'
s[-1]     # 'n'  (last)
s[0:3]    # 'pyt'
s[::-1]   # 'nohtyp'  (reverse trick)
```

## common methods
| method        | does                              |
|---------------|-----------------------------------|
| `upper()`     | to uppercase                      |
| `lower()`     | to lowercase                      |
| `strip()`     | remove surrounding spaces         |
| `split()`     | break into a list of words        |
| `join(list)`  | glue a list into one string       |
| `replace(a,b)`| replace a with b                  |
| `find(x)`     | index of x, or -1 if not there    |
| `startswith()`| True/False                        |
| `isupper()` / `islower()` | check the case        |

## useful ideas
- `len(s)` gives the length.
- `for ch in s:` loops over each character.
- `ch in "aeiou"` checks membership.
- reverse with the slice `s[::-1]`.

> Strings are immutable. To "change" one you build a new string, e.g. `res += ch`.

## palindrome
A word that reads the same forwards and backwards. Just compare `s == s[::-1]`.

## anagram
Two words with the same letters. Sort both and compare: `sorted(a) == sorted(b)`.
