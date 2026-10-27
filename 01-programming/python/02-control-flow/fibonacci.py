# print first n fibonacci numbers
n = int(input("How many terms: "))

a, b = 0, 1
for i in range(n):
    print(a, end=" ")
    a, b = b, a + b
print()
