# fibonacci numbers with a generator

def fib(n):
    a, b = 0, 1
    for i in range(n):
        yield a
        a, b = b, a + b

for x in fib(10):
    print(x, end=" ")
print()
