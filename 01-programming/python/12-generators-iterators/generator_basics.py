# generators use yield instead of return

def count_up(n):
    i = 1
    while i <= n:
        yield i
        i += 1

g = count_up(5)
print(next(g))
print(next(g))

for x in count_up(3):
    print(x)

print(list(count_up(4)))
