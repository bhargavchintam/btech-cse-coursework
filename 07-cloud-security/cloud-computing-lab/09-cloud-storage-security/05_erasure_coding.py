#!/usr/bin/env python3
# erasure code with k data blocks + one XOR parity, survives losing any single block

def xor(a, b):
    return bytes(x ^ y for x, y in zip(a, b))


def split(data, k):
    bs = -(-len(data) // k)          # ceil, so every block is the same length
    data = data.ljust(bs * k, b"\x00")
    return [data[i * bs:(i + 1) * bs] for i in range(k)]


def parity(blocks):
    p = bytes(len(blocks[0]))
    for b in blocks:
        p = xor(p, b)
    return p


def recover(blocks, par, lost):
    p = par
    for i, b in enumerate(blocks):
        if i != lost:
            p = xor(p, b)            # xor parity with every survivor
    return p


k = 4
data = b"erasure coding keeps the object safe across many disks"
blocks = split(data, k)
par = parity(blocks)

print(f"k={k}  block size={len(blocks[0])}")
for i, b in enumerate(blocks):
    print(f"  block{i}: {b}")
print("  parity:", par)

lost = 2
print(f"\nlose block{lost}")
kept = list(blocks)
kept[lost] = bytes(len(par))         # gone, treat as zeros
rec = recover(kept, par, lost)
print("recovered:", rec)
assert rec == blocks[lost]
print("block matches:", rec == blocks[lost])

kept[lost] = rec
full = b"".join(kept).rstrip(b"\x00")
assert full == data
print("object intact:", full == data)
