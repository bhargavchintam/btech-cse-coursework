a = int(input("a: "))
b = int(input("b: "))

print("before:", a, b)
a, b = b, a
print("after:", a, b)
