# a basic decorator wraps a function

def greet(func):
    def wrapper():
        print("before call")
        func()
        print("after call")
    return wrapper

@greet
def hello():
    print("hello there")

hello()
