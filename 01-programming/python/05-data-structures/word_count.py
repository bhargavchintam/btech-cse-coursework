# count words and their frequency
text = input("enter a sentence: ")
words = text.split()
print("total words:", len(words))

freq = {}
for w in words:
    freq[w] = freq.get(w, 0) + 1

for w in freq:
    print(w, ":", freq[w])
