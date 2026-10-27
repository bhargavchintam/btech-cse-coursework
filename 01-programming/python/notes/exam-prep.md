# Exam prep

Practice programs and short questions grouped by phase. Most of these map to something
already in the unit folders — try them from scratch first, then check.

## Phase 1 — basics and control flow

Practice programs:
- swap two numbers with and without a temp variable
- area of circle / simple interest
- even or odd, largest of three numbers
- check prime, print primes up to n
- factorial, sum of first n numbers, multiplication table
- fibonacci series, reverse a number, armstrong number, leap year
- print star / number patterns (right triangle, pyramid, diamond, floyd, pascal)

Short questions:
- difference between `/`, `//`, `%`
- what does `range(2, 10, 2)` give?
- `break` vs `continue`
- why is `int(input())` needed instead of just `input()`?
- how to check a leap year (the 4 / 100 / 400 rule)

## Phase 2 — strings

Practice programs:
- reverse a string, check palindrome
- count vowels, count words, character frequency
- check two words are anagrams
- swap case of every letter
- toggle / title-case a sentence

Short questions:
- why are strings immutable? what does `s[0] = 'x'` do?
- what does `s[::-1]` do and why?
- `split()` vs `join()`
- `find()` vs `index()`

## Phase 3 — data structures

Practice programs:
- list operations: append, insert, remove, sort, search
- remove duplicates from a list
- bubble sort and binary search
- matrix addition and transpose using nested lists
- set operations (union, intersection, difference)
- tuple packing / unpacking
- word frequency using a dict

Short questions:
- list vs tuple vs set vs dict — pick when to use each
- why must dict keys be immutable?
- `d[k]` vs `d.get(k)` — what's the difference when k is missing?
- how does slicing `a[1:4]` work, is the stop included?

## Phase 4 — functions

Practice programs:
- gcd (euclid), power of a number
- factorial and fibonacci with recursion
- functions with default and keyword arguments
- `*args` and `**kwargs`
- lambda to square / sort by a key
- show local vs global scope

Short questions:
- `return` vs `print`
- what is a default argument, and the mutable-default gotcha
- difference between positional, keyword, `*args`, `**kwargs`
- what is recursion, what is a base case
- what does `global` / `nonlocal` do?

## Phase 5 — comprehensions

Practice programs:
- squares of 1..n with a list comprehension
- filter even numbers with a comprehension
- dict comprehension mapping number -> square
- flatten a nested list with a nested comprehension
- set comprehension for unique remainders

Short questions:
- rewrite a for-loop that builds a list as a comprehension
- list comprehension vs generator expression (`[]` vs `()`)

## Phase 6 — OOP

Practice programs:
- a class with `__init__` and a method (Student, Circle...)
- encapsulation with a "private" balance
- single and multiple inheritance, use `super()`
- polymorphism: same method name in two classes
- magic methods: `__str__`, `__add__`, `__len__`
- abstract base class with `abc`
- class methods and static methods

Short questions:
- class vs object
- `self` — what is it?
- constructor — what runs and when
- method overriding, and what `super()` does
- instance attribute vs class attribute
- what do `@staticmethod` and `@classmethod` change?

## Phase 7 — files and exceptions

Practice programs:
- write lines to a file, read them back
- append mode vs write mode
- read/write a CSV, read/write JSON
- `try/except/else/finally`
- raise and catch a custom exception

Short questions:
- file modes `r`, `w`, `a` — what each does
- why use `with open(...)`?
- `try/except` flow, when does `finally` run?
- difference between an error and an exception you catch

## Phase 8 — advanced

Modules:
- put functions in a module and import it (`import`, `from ... import`, `as`)
- explain the `if __name__ == "__main__":` guard

Decorators:
- a decorator that prints before/after a call
- a timer decorator
- decorator that takes an argument
- why use `functools.wraps`

Generators / iterators:
- a fibonacci generator with `yield`
- an infinite generator + `itertools.islice`
- a class that is its own iterator (`__iter__`, `__next__`)
- `yield from`

Functional:
- `map`, `filter`, `reduce` on a list
- closures and why they remember variables
- higher-order functions, function composition
- `functools.partial`

Regex:
- validate an email, extract phone numbers
- capture groups, `re.sub` to replace text
- explain `\d`, `\w`, `+`, `*`, `^`, `$`

Standard library:
- `Counter` for word frequency, `defaultdict`, `namedtuple`, `deque`
- `datetime` — today's date, difference between two dates
- `random` — dice roll, pick a random item

Short questions:
- generator vs list — memory difference
- what does `yield` do that `return` doesn't?
- what is a decorator, in one sentence
- closure vs regular function
