# a decorator written as a class using __call__

class CountCalls:
    def __init__(self, func):
        self.func = func
        self.count = 0

    def __call__(self, *args, **kwargs):
        self.count += 1
        print("call number", self.count)
        return self.func(*args, **kwargs)

@CountCalls
def hello():
    print("hello")

hello()
hello()
hello()
