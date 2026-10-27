# a closure remembers variables from the enclosing scope

def make_counter():
    count = 0
    def counter():
        nonlocal count
        count += 1
        return count
    return counter

c = make_counter()
print(c())
print(c())
print(c())

def multiplier(n):
    def mul(x):
        return x * n
    return mul

times3 = multiplier(3)
times5 = multiplier(5)
print(times3(10))
print(times5(10))
