def greet(name, msg="good morning"):
    print(name + ", " + msg)

greet("bhargav")
greet("ravi", "good evening")

def power(base, exp=2):
    return base ** exp

print(power(5))
print(power(2, 10))

def bill(amount, tax=5):
    return amount + amount * tax / 100

print(bill(200))
print(bill(200, 12))
