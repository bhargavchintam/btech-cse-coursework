# calculator functions in a module

def add(a, b):
    return a + b


def sub(a, b):
    return a - b


def mul(a, b):
    return a * b


def div(a, b):
    if b == 0:
        return None
    return a / b


if __name__ == "__main__":
    # quick self test, only runs when this file is run directly
    print(add(2, 3))
    print(sub(10, 4))
    print(mul(6, 7))
    print(div(20, 5))
    print(div(5, 0))
