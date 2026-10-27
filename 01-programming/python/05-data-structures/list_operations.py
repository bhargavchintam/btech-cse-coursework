# some common list operations
nums = [4, 1, 7, 3, 9, 2]
print("list:", nums)

nums.append(10)
print("after append:", nums)

nums.insert(0, 0)
print("after insert:", nums)

nums.remove(7)
print("after remove 7:", nums)

x = nums.pop()
print("popped:", x)
print("now:", nums)

print("index of 9:", nums.index(9))
print("count of 3:", nums.count(3))
print("min:", min(nums), "max:", max(nums), "sum:", sum(nums))

nums.sort()
print("sorted:", nums)

nums.reverse()
print("reversed:", nums)
