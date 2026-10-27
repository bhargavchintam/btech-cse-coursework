# set operations
a = {1, 2, 3, 4, 5}
b = {4, 5, 6, 7, 8}
print("a =", a)
print("b =", b)
print("union:", a | b)
print("intersection:", a & b)
print("difference:", a - b)
print("symmetric difference:", a ^ b)

a.add(10)
print("after add:", a)
a.discard(1)
print("after discard:", a)

print("is {2,3} subset:", {2, 3} <= a)
