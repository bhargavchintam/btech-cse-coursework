# list comprehensions
squares = [x*x for x in range(1, 11)]
print("squares:", squares)

evens = [x for x in range(20) if x % 2 == 0]
print("evens:", evens)

words = ["hello", "world", "python"]
lengths = [len(w) for w in words]
print("lengths:", lengths)

upper = [w.upper() for w in words]
print("upper:", upper)
