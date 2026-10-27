# composing functions - output of one feeds into the next

def compose(f, g):
    return lambda x: f(g(x))

def inc(x):
    return x + 1

def double(x):
    return x * 2

inc_then_double = compose(double, inc)
print(inc_then_double(5))   # (5+1)*2 = 12

# compose a whole list of functions, right to left
def compose_all(*funcs):
    def inner(x):
        for f in reversed(funcs):
            x = f(x)
        return x
    return inner

pipeline = compose_all(double, inc, inc)
print(pipeline(3))   # ((3+1)+1)*2 = 10
