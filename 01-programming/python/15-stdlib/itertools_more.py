# more itertools tools
import itertools

# count, cycle and repeat are infinite so slice them
c = itertools.count(10, 2)
print("count:", [next(c) for _ in range(5)])

cy = itertools.cycle("AB")
print("cycle:", [next(cy) for _ in range(5)])

print("repeat:", list(itertools.repeat("x", 3)))

# permutations and combinations
print("perms:", list(itertools.permutations([1, 2, 3], 2)))
print("combos:", list(itertools.combinations([1, 2, 3], 2)))
print("product:", list(itertools.product("AB", [1, 2])))

# chain joins iterables
print("chain:", list(itertools.chain([1, 2], [3, 4], [5])))

# accumulate gives running totals
print("running sum:", list(itertools.accumulate([1, 2, 3, 4])))

# groupby groups consecutive equal items
data = "aaabbbcca"
for k, g in itertools.groupby(data):
    print(k, len(list(g)))
