# armstrong number (3 digit): sum of cubes of digits equals the number
n = int(input("Enter a number: "))

temp = n
s = 0
while temp > 0:
    d = temp % 10
    s += d ** 3
    temp //= 10

if s == n:
    print(n, "is an Armstrong number")
else:
    print(n, "is not an Armstrong number")
