# recursion - factorial and fibonacci
def fact(n):
    if n == 0:
        return 1
    return n * fact(n-1)

def fib(n):
    if n < 2:
        return n
    return fib(n-1) + fib(n-2)

print("factorial of 5:", fact(5))
print("fibonacci series:")
for i in range(10):
    print(fib(i), end=" ")
print()
