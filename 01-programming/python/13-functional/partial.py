# partial fixes some of the arguments ahead of time
from functools import partial

def power(base, exp):
    return base ** exp

square = partial(power, exp=2)
cube = partial(power, exp=3)
print(square(5))
print(cube(2))

# fix the first argument instead
def add3(a, b, c):
    return a + b + c

add10 = partial(add3, 10)
print(add10(20, 30))

# handy with built-ins too
to_bin = partial(int, base=2)
print(to_bin("1010"))
