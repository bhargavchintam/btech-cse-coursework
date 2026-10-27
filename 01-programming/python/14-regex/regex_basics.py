# basic regex with the re module
import re

s = "the year 2019 was good, 2020 was odd"

# search finds the first match anywhere
m = re.search(r'\d+', s)
print("first number:", m.group())
print("at index", m.start(), "to", m.end())

# match only checks the start of the string
print(re.match(r'the', s))
print(re.match(r'year', s))   # None, doesn't start with year

# findall gets all matches as a list
nums = re.findall(r'\d+', s)
print("all numbers:", nums)

# fullmatch checks the whole string
print(bool(re.fullmatch(r'[a-z ,0-9]+', s)))

# some common patterns
print(re.findall(r'\w+', "hello world_1 foo"))
print(re.findall(r'\s', "a b\tc"))
print(re.findall(r'[aeiou]', "education"))

# anchors
print(re.search(r'good$', "not good"))
print(re.search(r'^not', "not good"))

# quantifiers
print(re.findall(r'ab*', "a ab abb abbb"))
print(re.findall(r'ab+', "a ab abb"))
print(re.findall(r'ab?', "a ab abb"))
