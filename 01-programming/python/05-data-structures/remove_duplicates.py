# remove duplicates from a list
nums = [1, 2, 2, 3, 4, 4, 4, 5, 1]

# keeping the order
seen = []
for x in nums:
    if x not in seen:
        seen.append(x)
print("without duplicates:", seen)

# quick way using set (order not kept)
print("using set:", set(nums))
