# a few handy itertools functions
import itertools

# count is infinite so break out
for i in itertools.count(10, 2):
    if i > 20:
        break
    print(i, end=" ")
print()

# cycle repeats forever
colors = itertools.cycle(["red", "green"])
for i in range(5):
    print(next(colors), end=" ")
print()

print(list(itertools.combinations([1, 2, 3], 2)))
print(list(itertools.permutations([1, 2, 3], 2)))
print(list(itertools.chain([1, 2], [3, 4], [5])))
print(list(itertools.accumulate([1, 2, 3, 4])))
