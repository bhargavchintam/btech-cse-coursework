# lambda functions
square = lambda x: x * x
add = lambda a, b: a + b
print(square(6))
print(add(3, 8))

nums = [1, 2, 3, 4, 5, 6]
evens = list(filter(lambda x: x % 2 == 0, nums))
doubled = list(map(lambda x: x * 2, nums))
print("evens:", evens)
print("doubled:", doubled)

# sort by second item
pairs = [(1, 3), (2, 1), (4, 2)]
pairs.sort(key=lambda p: p[1])
print("sorted:", pairs)
