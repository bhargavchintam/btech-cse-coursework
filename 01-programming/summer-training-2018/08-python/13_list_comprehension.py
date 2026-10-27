squares = [i * i for i in range(1, 11)]
print(squares)

evens = [i for i in range(1, 21) if i % 2 == 0]
print(evens)

names = ["kohli", "dhoni", "rohit"]
caps = [n.upper() for n in names]
print(caps)

pairs = [(i, i * i) for i in range(1, 6)]
print(pairs)
