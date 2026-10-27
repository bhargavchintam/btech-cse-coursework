# check if a number is prime
n = int(input("Enter a number: "))

if n < 2:
    print(n, "is not prime")
else:
    prime = True
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            prime = False
            break
    if prime:
        print(n, "is prime")
    else:
        print(n, "is not prime")
