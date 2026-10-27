a = int(input("a: "))
b = int(input("b: "))
c = int(input("c: "))

if a >= b and a >= c:
    big = a
elif b >= c:
    big = b
else:
    big = c

print("Largest is", big)
