def add(a, b):
    return a + b

def is_even(n):
    return n % 2 == 0

def greet(name):
    print("hello " + name)

def factorial(n):
    f = 1
    for i in range(1, n + 1):
        f = f * i
    return f

print(add(5, 3))
print(is_even(10))
print(is_even(7))
greet("bhargav")
print(factorial(5))
