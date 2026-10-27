# tuples
t = (1, 2, 3, 4, 3, 2)
print("tuple:", t)
print("length:", len(t))
print("count of 2:", t.count(2))
print("index of 4:", t.index(4))

# packing and unpacking
point = 3, 5
x, y = point
print("x =", x, "y =", y)

# tuples cannot be changed
try:
    t[0] = 99
except TypeError:
    print("can't change a tuple")

# swap using tuples
a, b = 10, 20
a, b = b, a
print("after swap:", a, b)
