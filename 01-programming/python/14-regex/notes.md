# Regular expressions (re module)

`import re` and write patterns as raw strings `r'...'` so backslashes don't get eaten.

## Main functions
| function | what it does |
|----------|--------------|
| `re.match(p, s)` | match only at the start of s |
| `re.search(p, s)` | first match anywhere |
| `re.findall(p, s)` | list of all matches |
| `re.finditer(p, s)` | iterator of match objects |
| `re.sub(p, rep, s)` | replace matches |
| `re.fullmatch(p, s)` | whole string must match |

search/match return a match object (or None). Use `m.group()` to get the text.

## Common patterns
| pattern | meaning |
|---------|---------|
| `\d` | a digit, `\D` a non-digit |
| `\w` | word char (letter/digit/_) |
| `\s` | whitespace |
| `.` | any char (except newline) |
| `^` `$` | start / end |
| `*` `+` `?` | 0+, 1+, 0 or 1 |
| `{n}` `{n,m}` | exactly n / between n and m |
| `[abc]` | one of a b c |
| `a|b` | a or b |

## Groups
`( )` makes a capture group, get them with `m.group(1)`, `m.groups()`.
Named groups: `(?P<name>...)` then `m.group('name')` or `m.groupdict()`.
In `re.sub` you refer back to a group with `\1`, `\2`.

```python
m = re.search(r'(\d+)-(\d+)', "12-34")
m.group(1)   # '12'
m.group(2)   # '34'
```

> match() only looks at the START. To find something in the middle use search() or findall().
> Always test the pattern, it is very easy to get it slightly wrong.
