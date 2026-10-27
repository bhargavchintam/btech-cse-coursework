# swap the case of each letter
s = input("Enter a string: ")

res = ""
for ch in s:
    if ch.isupper():
        res += ch.lower()
    elif ch.islower():
        res += ch.upper()
    else:
        res += ch

print(res)
