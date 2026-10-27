# set comprehensions
nums = [1, 2, 2, 3, 4, 4, 5]
squares = {x*x for x in nums}
print(squares)

s = "hello world"
vowels = {c for c in s if c in "aeiou"}
print("vowels:", vowels)
