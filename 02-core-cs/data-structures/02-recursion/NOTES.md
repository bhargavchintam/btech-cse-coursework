# Recursion

## What it is
A function that calls itself to solve a smaller version of the same problem, until it
reaches a case small enough to answer straight away. Every recursive solution needs
two parts:

- base case      - the smallest input, answered without recursing. This STOPS it.
- recursive case - break the problem into a smaller one and call yourself.

factorial is the standard example:
    fact(n) = 1               if n == 0        (base case)
    fact(n) = n * fact(n-1)   otherwise        (recursive case)

If you forget the base case, or the recursion never reaches it, it never stops and you
get a stack overflow. Did exactly that in the lab once - wrote fact(n) instead of
fact(n-1) and it just hung.

## The call stack
Each call gets its own frame on the stack with its own copy of the parameters and
locals. Calls stack up going down, then unwind coming back up:

    fact(3)
      -> fact(2)
          -> fact(1)
              -> fact(0) returns 1
          returns 1*1 = 1
      returns 2*1 = 2
    returns 3*2 = 6

Nothing above a call finishes until the call below it returns. That is why deep
recursion costs memory - every pending call is sitting on the stack waiting.

## When recursion is worth it
- problems that are naturally recursive: tree traversal, Tower of Hanoi, permutations,
  divide and conquer (merge sort, quick sort, binary search).
- the code comes out short and reads almost like the maths definition.

## When it isn't
- plain factorial / sum of digits / gcd - a loop does the same job with O(1) stack and
  no call overhead. iteration is usually faster and safer here.
- naive recursive fibonacci is a trap: fib(n) calls fib(n-1) and fib(n-2), so it keeps
  recomputing the same values -> about O(2^n). A loop does it in O(n). Go past fib(40)
  or so and you are just waiting.

Rule I go by: recurse when the problem is defined recursively and the depth stays
reasonable. Otherwise loop.

## Recursion vs iteration
```
              recursion              iteration
code          short, matches defn    more bookkeeping
memory        O(depth) on stack      O(1) usually
speed         call overhead          faster
risk          stack overflow         infinite loop if the condition is wrong
```

The 10 programs here run from the easy ones (factorial, sum of digits, gcd) up to the
ones where recursion really earns its place - Hanoi, permutations, and Ackermann, which
you basically cannot write without it.
