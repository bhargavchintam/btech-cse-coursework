n = int(input("Enter a number: "))

rev = 0
temp = n
while temp > 0:
    d = temp % 10
    rev = rev * 10 + d
    temp //= 10

print("Reversed:", rev)
