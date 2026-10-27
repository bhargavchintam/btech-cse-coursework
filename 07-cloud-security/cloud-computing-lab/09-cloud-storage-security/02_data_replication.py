#!/usr/bin/env python3
# quorum replication across N nodes. W + R > N so any read quorum overlaps the last write.

n = 5
w = 3
r = 3
print(f"N={n} W={w} R={r}   W+R={w + r} > N -> strong consistency\n")

nodes = [{"val": "v0", "ver": 1} for _ in range(n)]


def write(idx, val, ver):
    for i in idx:
        nodes[i] = {"val": val, "ver": ver}
    print(f"write {val!r} v{ver} to nodes {idx}  (quorum {len(idx)}/{w})")


def read(idx):
    got = sorted((nodes[i]["ver"], nodes[i]["val"], i) for i in idx)
    ver, val, i = got[-1]        # newest wins
    print(f"read nodes {idx} -> newest {val!r} v{ver} (from node {i})")
    return val


print("start: every node holds v0")
write([0, 1, 2], "v1", 2)        # nodes 3,4 were down, missed this write
print("nodes 3,4 stale:", [f"{i}:{nd['val']}" for i, nd in enumerate(nodes)])

val = read([2, 3, 4])            # a read quorum that is mostly the stale nodes
assert val == "v1"
print("-> got the latest even though 2 of 3 read nodes were stale\n")

print("counter-example, W=2 R=2 (W+R=4 <= N):")
c = [{"val": "v0", "ver": 1} for _ in range(n)]
for i in (0, 1):
    c[i] = {"val": "v1", "ver": 2}
ver, val = sorted((c[i]["ver"], c[i]["val"]) for i in (2, 3))[-1]
print(f"  wrote v1 to [0,1], read [2,3] -> {val!r} v{ver}  (disjoint sets, missed the write)")
