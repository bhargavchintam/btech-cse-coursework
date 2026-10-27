# higher order functions take or return other functions

def apply(func, x):
    return func(x)

print(apply(abs, -5))
print(apply(str, 42))

def make_greeting(word):
    def greet(name):
        return word + ", " + name
    return greet

hi = make_greeting("Hi")
print(hi("Ravi"))

def do_all(func, items):
    return [func(i) for i in items]

print(do_all(lambda x: x * 10, [1, 2, 3]))
