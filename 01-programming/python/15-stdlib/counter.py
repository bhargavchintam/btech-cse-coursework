# word frequency using Counter
from collections import Counter

text = """the quick brown fox jumps over the lazy dog
the dog was not amused the fox ran away"""

words = text.split()
c = Counter(words)

print("total words:", len(words))
print("unique words:", len(c))
print()

print("top 3 words:")
for w, n in c.most_common(3):
    print(f"  {w}: {n}")

# letter frequency too
letters = Counter(ch for ch in text.lower() if ch.isalpha())
print("\nmost common letter:", letters.most_common(1)[0])
