# Analysis of algorithms

Notes from the first DSA lectures. This is about measuring an algorithm without
running it on every machine - we count how the work grows as the input n gets bigger.

## Why not just use a stopwatch
Running time depends on the machine, the compiler, what else is running at the time.
Two algorithms timed on different laptops tell you nothing useful. So instead we count
the number of basic operations (comparisons, assignments) as a function of n and look
at how that count grows. The growth is what matters once n is large.

> "Constants lie, growth doesn't." - lecturer said this, it stuck.

## Asymptotic notation
Three of them, they bound the growth for large n:

- Big-O  (O)   upper bound. f(n)=O(g(n)) means f grows no faster than g. This is the
               worst case guarantee, the one we quote most.
- Omega  (Om)  lower bound. f grows at least as fast as g.
- Theta  (Th)  tight bound. f is both O(g) and Omega(g), so g is the exact growth.

We drop constants and lower terms. 3n^2 + 5n + 7 is O(n^2) - the 5n and the 7 stop
mattering once n is big enough.

## Best / average / worst case
The same algorithm behaves differently on different inputs.
- best case    - luckiest input (linear search: key is first element -> 1 compare)
- worst case   - nastiest input (key absent -> n compares)
- average case - expected over all inputs (~n/2 compares)

Worst case is usually the one we state, because it's a guarantee.

## Counting operations in loops
Rough rule: count how many times the innermost statement runs.
- single loop      for(i=0;i<n;i++)        -> n times       -> O(n)
- two nested       for i.. for j..          -> n*n           -> O(n^2)
- halve each time  while(n>1) n=n/2         -> log2(n) times -> O(log n)
- loop then a separate loop                 -> n + n         -> O(n)
- inner depends on i  0+1+..+(n-1)=n(n-1)/2  -> O(n^2)

Sequential blocks ADD, nested blocks MULTIPLY. That one line clears up most confusion.

## Space complexity
Same idea but for memory, counting extra space beyond the input.
- reverse an array in place        -> O(1) extra
- copy into a new array            -> O(n)
- recursion uses the call stack    -> O(depth), e.g. O(n) for factorial(n)

## Small complexity table
```
operation                         time
-----------------------------------------
access array element a[i]         O(1)
linear search                     O(n)
binary search (sorted array)      O(log n)
bubble / selection / insertion    O(n^2)
merge sort / quick sort (avg)     O(n log n)
push / pop on a stack             O(1)
```

The three programs here show some of this by actually counting: linear search comes
out to n compares, bubble sort to n(n-1)/2, and binary stays tiny (~log n) next to
linear. Run them for growing n and the pattern is obvious.
