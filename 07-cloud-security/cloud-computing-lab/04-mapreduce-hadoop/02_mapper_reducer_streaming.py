#!/usr/bin/env python3

text = "apple banana apple cherry banana apple"


def mapper(line):
    out = []
    for w in line.split():
        out.append(f"{w}\t1")
    return out


def reducer(lines):
    cur = None
    total = 0
    out = []
    for line in lines:
        w, c = line.split("\t")
        c = int(c)
        if w == cur:
            total += c
        else:
            if cur is not None:
                out.append((cur, total))
            cur = w
            total = c
    if cur is not None:
        out.append((cur, total))
    return out


mapped = mapper(text)
mapped.sort()                      # the shuffle sorts by key before the reducer ever runs
for w, n in reducer(mapped):
    print(f"{w}\t{n}")
