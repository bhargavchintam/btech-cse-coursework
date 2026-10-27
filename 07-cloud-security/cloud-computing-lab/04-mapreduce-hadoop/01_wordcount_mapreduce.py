#!/usr/bin/env python3

text = """the cluster runs the job
the job reads data from the cluster
map and reduce process the data"""


def mapper(line):
    return [(w, 1) for w in line.split()]


def shuffle(pairs):
    groups = {}
    for w, c in pairs:
        groups.setdefault(w, []).append(c)
    return groups


def reducer(w, counts):
    return w, sum(counts)


pairs = []
for line in text.splitlines():
    pairs += mapper(line)

groups = shuffle(pairs)
counts = dict(reducer(w, c) for w, c in groups.items())

for w, n in sorted(counts.items(), key=lambda kv: (-kv[1], kv[0])):
    print(f"{w}\t{n}")
