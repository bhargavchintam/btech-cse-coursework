#!/usr/bin/env python3
import math

docs = [
    "the cat sat on the mat",
    "the dog sat on the log",
    "the cat chased the dog",
]
toks = [d.split() for d in docs]
vocab = sorted({w for t in toks for w in t})
N = len(docs)

df = {w: sum(w in t for t in toks) for w in vocab}
idf = {w: math.log(N / df[w]) for w in vocab}


def tfidf(t):
    m = len(t)
    return {w: t.count(w) / m * idf[w] for w in set(t)}


for i, t in enumerate(toks):
    w = tfidf(t)
    print(f"doc{i}:")
    for term in sorted(w):
        print(f"  {term:8s} {w[term]:.4f}")

print("\nterm   df  idf")
for w in vocab:
    print(f"  {w:8s} {df[w]}  {idf[w]:.4f}")
