# bubble sort and binary search
nums = [5, 2, 9, 1, 7, 3]

for i in range(len(nums)):
    for j in range(len(nums)-1-i):
        if nums[j] > nums[j+1]:
            nums[j], nums[j+1] = nums[j+1], nums[j]
print("sorted:", nums)

# binary search
key = 7
lo = 0
hi = len(nums) - 1
pos = -1
while lo <= hi:
    mid = (lo + hi) // 2
    if nums[mid] == key:
        pos = mid
        break
    elif nums[mid] < key:
        lo = mid + 1
    else:
        hi = mid - 1

if pos == -1:
    print(key, "not found")
else:
    print(key, "found at index", pos)
