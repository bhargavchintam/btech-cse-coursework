#!/usr/bin/env python3
# lab 3 - word count done the MapReduce way. map turns each line into (word, 1)
# pairs, shuffle groups the pairs by word, reduce adds up the counts. same
# pieces Hadoop runs across a cluster, here on one box with plain dicts.

from collections import defaultdict

text = """the quick brown fox
the lazy dog and the quick cat
brown fox brown dog""".splitlines()


def mapper(line):
    return [(w, 1) for w in line.split()]


def shuffle(pairs):
    g = defaultdict(list)
    for w, c in pairs:
        g[w].append(c)
    return g


def reducer(word, counts):
    return word, sum(counts)


pairs = []
for line in text:
    pairs += mapper(line)

grouped = shuffle(pairs)
counts = [reducer(w, c) for w, c in grouped.items()]

for w, c in sorted(counts, key=lambda x: (-x[1], x[0])):
    print(f"{w:8} {c}")
print(f"\ntotal words = {sum(c for _, c in counts)}")
