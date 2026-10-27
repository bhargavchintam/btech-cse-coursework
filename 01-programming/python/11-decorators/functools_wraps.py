# wraps keeps the original name and docstring
from functools import wraps

def deco(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        return func(*args, **kwargs)
    return wrapper

@deco
def add(a, b):
    "add two numbers"
    return a + b

print(add(2, 3))
print(add.__name__)
print(add.__doc__)
# without wraps, __name__ would be 'wrapper'
