# replacing text with re.sub
import re

s = "I have 3 cats, 2 dogs and 1 parrot"

# replace all numbers with #
print(re.sub(r'\d', '#', s))

# collapse multiple spaces into one
msg = "this    has   too     many spaces"
print(re.sub(r' +', ' ', msg))

# swap words using a backreference
name = "Kumar Ravi"
print(re.sub(r'(\w+) (\w+)', r'\2 \1', name))

# censor some words
bad = "this is dumb and stupid"
print(re.sub(r'dumb|stupid', '****', bad))

# sub can also take a function
def double(m):
    return str(int(m.group()) * 2)

print(re.sub(r'\d+', double, "buy 2 get 4 free"))

# count how many replacements happened
new, n = re.subn(r'a', 'A', "banana")
print(new, "made", n, "changes")
