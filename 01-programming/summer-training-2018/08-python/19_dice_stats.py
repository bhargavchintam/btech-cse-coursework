import random

counts = {1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0}

for i in range(100):
    face = random.randint(1, 6)
    counts[face] = counts[face] + 1

for face in counts:
    print(f"{face} came {counts[face]} times")

print("total rolls =", sum(counts.values()))
