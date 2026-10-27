# infinite generator, but we only take what we need

def naturals():
    n = 1
    while True:
        yield n
        n += 1

def take(gen, k):
    res = []
    for x in gen:
        res.append(x)
        if len(res) == k:
            break
    return res

print(take(naturals(), 10))

# first 5 even numbers
evens = (x for x in naturals() if x % 2 == 0)
print(take(evens, 5))
