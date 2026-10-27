#!/usr/bin/env python3

A = [[1, 2, 3],
     [4, 5, 6]]

B = [[7, 8],
     [9, 10],
     [11, 12]]

m = len(A)
n = len(A[0])
p = len(B[0])


def mapper(A, B):
    pairs = []
    for i in range(m):
        for k in range(n):
            for j in range(p):
                pairs.append(((i, j), ("A", k, A[i][k])))
    for k in range(n):
        for j in range(p):
            for i in range(m):
                pairs.append(((i, j), ("B", k, B[k][j])))
    return pairs


def shuffle(pairs):
    groups = {}
    for key, val in pairs:
        groups.setdefault(key, []).append(val)
    return groups


def reducer(vals):
    a, b = {}, {}
    for tag, k, v in vals:
        if tag == "A":
            a[k] = v
        else:
            b[k] = v
    return sum(a[k] * b[k] for k in a)


def plain(A, B):
    C = [[0] * p for _ in range(m)]
    for i in range(m):
        for j in range(p):
            for k in range(n):
                C[i][j] += A[i][k] * B[k][j]
    return C


groups = shuffle(mapper(A, B))
C = [[0] * p for _ in range(m)]
for (i, j), vals in groups.items():
    C[i][j] = reducer(vals)

ref = plain(A, B)
for row in C:
    print(row)
print("matches plain product:", C == ref)
