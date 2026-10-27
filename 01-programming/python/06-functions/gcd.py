# gcd using euclid's algorithm
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

print("gcd of 12 and 18:", gcd(12, 18))
print("gcd of 48 and 36:", gcd(48, 36))
print("gcd of 7 and 5:", gcd(7, 5))
