#!/usr/bin/env python3

docs = {
    "d1": "the cat sat on the mat",
    "d2": "the dog sat on the log",
    "d3": "cat and dog are friends",
}


def mapper(docid, text):
    return [(w, docid) for w in text.split()]


def shuffle(pairs):
    groups = {}
    for w, d in pairs:
        groups.setdefault(w, set()).add(d)
    return groups


pairs = []
for docid, text in docs.items():
    pairs += mapper(docid, text)

idx = shuffle(pairs)
for w in sorted(idx):
    print(f"{w}: {sorted(idx[w])}")
