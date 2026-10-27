# Comprehensions

A short way to build a list / dict / set from a loop.

## List comprehension
`[expr for item in iterable if condition]`
```
squares = [x*x for x in range(5)]
evens = [x for x in range(20) if x % 2 == 0]
```
Same as a for loop with `append`, just shorter.

## Dict comprehension
`{key: value for ...}`
```
{x: x*x for x in range(5)}
```

## Set comprehension
`{expr for ...}` - drops duplicates automatically.
```
{c for c in "hello" if c in "aeiou"}
```

## Nested
```
flat = [x for row in matrix for x in row]
```
Read it left to right, like nested for loops.

## Generator expression
Same idea but with `()`. Does not build the whole list - it yields one item
at a time, so it saves memory on big data.
```
total = sum(x for x in range(1000000))
```

> a generator can only be looped through once, then it is empty.
