# a decorator that itself takes an argument

def repeat(n):
    def deco(func):
        def wrapper(*args, **kwargs):
            for i in range(n):
                func(*args, **kwargs)
        return wrapper
    return deco

@repeat(3)
def say(msg):
    print(msg)

say("hi")
