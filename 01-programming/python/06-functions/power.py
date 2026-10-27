# power of a number
def power(base, exp):
    res = 1
    for i in range(exp):
        res *= base
    return res

# recursive version
def power2(base, exp):
    if exp == 0:
        return 1
    return base * power2(base, exp-1)

print(power(2, 5))
print(power(3, 3))
print(power2(2, 10))
