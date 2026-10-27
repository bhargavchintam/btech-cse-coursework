# tuple cannot change after making it
point = (10, 20)
print(point)
print(point[0])

days = ("mon", "tue", "wed")
print(len(days))

nums = {1, 2, 3, 3, 2, 1}
print(nums)

a = {1, 2, 3, 4}
b = {3, 4, 5, 6}
print(a | b)
print(a & b)
print(a - b)

nums.add(10)
print(nums)
