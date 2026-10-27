# dict comprehensions
squares = {x: x*x for x in range(1, 6)}
print(squares)

names = ["ravi", "sita", "john"]
d = {n: len(n) for n in names}
print(d)

# swap keys and values
prices = {'apple': 50, 'banana': 20}
swapped = {v: k for k, v in prices.items()}
print(swapped)
