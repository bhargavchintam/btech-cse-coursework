# time how long a function takes
import time

def timer(func):
    def wrapper(*args, **kwargs):
        start = time.time()
        res = func(*args, **kwargs)
        end = time.time()
        print(func.__name__, "took", round(end - start, 4), "seconds")
        return res
    return wrapper

@timer
def slow_sum(n):
    total = 0
    for i in range(n):
        total += i
    return total

print(slow_sum(1000000))
