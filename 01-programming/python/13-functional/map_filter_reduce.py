# map, filter and reduce
from functools import reduce

nums = [1, 2, 3, 4, 5, 6]

squares = list(map(lambda x: x * x, nums))
print(squares)

evens = list(filter(lambda x: x % 2 == 0, nums))
print(evens)

total = reduce(lambda a, b: a + b, nums)
print(total)

prod = reduce(lambda a, b: a * b, nums)
print(prod)
