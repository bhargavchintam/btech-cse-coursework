a = input("First word: ").lower()
b = input("Second word: ").lower()

if sorted(a) == sorted(b):
    print("Anagram")
else:
    print("Not an anagram")
