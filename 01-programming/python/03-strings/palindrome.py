s = input("Enter a word: ")
s = s.lower()

if s == s[::-1]:
    print("Palindrome")
else:
    print("Not a palindrome")
