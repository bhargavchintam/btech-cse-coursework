# small math helper module

def add(a, b):
    return a + b


def sub(a, b):
    return a - b


def square(n):
    return n * n


def factorial(n):
    r = 1
    for i in range(2, n + 1):
        r *= i
    return r


pi = 3.14159
