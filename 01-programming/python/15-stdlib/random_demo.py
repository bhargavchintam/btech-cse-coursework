# random module
import random

random.seed(1)   # seed so the output is the same each run

print("random float:", random.random())
print("randint 1-6:", random.randint(1, 6))
print("uniform:", random.uniform(1, 10))

nums = [10, 20, 30, 40, 50]
print("choice:", random.choice(nums))
print("sample of 3:", random.sample(nums, 3))

random.shuffle(nums)
print("shuffled:", nums)

# roll two dice a few times
for i in range(3):
    a = random.randint(1, 6)
    b = random.randint(1, 6)
    print(f"roll {i+1}: {a} + {b} = {a+b}")
