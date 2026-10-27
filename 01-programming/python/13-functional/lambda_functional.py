# lambda - small anonymous functions

add = lambda a, b: a + b
print(add(3, 4))

# sort pairs by the second item
pairs = [(1, 3), (2, 1), (3, 2)]
pairs.sort(key=lambda p: p[1])
print(pairs)

# sort names by length
names = ["Ravi", "Al", "Sunita", "Om"]
print(sorted(names, key=lambda s: len(s)))

# lambdas kept in a list
funcs = [lambda x: x + 1, lambda x: x * 2, lambda x: x ** 2]
for f in funcs:
    print(f(5), end=" ")
print()
