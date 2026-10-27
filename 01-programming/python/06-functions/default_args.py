# default arguments
def greet(name, msg="good morning"):
    print(msg, name)

def power(base, exp=2):
    return base ** exp

greet("amit")
greet("amit", "good night")
print(power(5))
print(power(2, 3))
