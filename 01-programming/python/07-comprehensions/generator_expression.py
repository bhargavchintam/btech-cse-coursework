# generator expressions
gen = (x*x for x in range(1, 6))
for v in gen:
    print(v, end=" ")
print()

# sum without building a list first
total = sum(x for x in range(1, 101))
print("sum 1..100:", total)

nums = [3, 7, 2, 8, 5]
print("max:", max(n for n in nums))

# generators are lazy, can be used only once
g = (x for x in range(3))
print(list(g))
print(list(g))   # empty now
