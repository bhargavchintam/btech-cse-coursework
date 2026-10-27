#!/usr/bin/env python3
# lab 12 - quorum replication over N replicas. a write lands on W of them, a read
# asks R of them and keeps the newest version it sees. if W + R > N the write set
# and read set must share a replica, so a read always catches the latest write.
# drop R (or W) until W + R <= N and a read can slip past a fresh write.

N = 5


def write(store, nodes, val, ver):
    for i in nodes:
        store[i] = (ver, val)


def read(store, nodes):
    return max(store[i] for i in nodes)     # highest version among the R replicas


store = [(1, "v1")] * N          # everyone starts at version 1
write(store, [0, 1, 2], "v2", 2)   # new write to a W=3 quorum

r = [2, 3, 4]
print("W=3 R=3   (W+R=6 > N=5)")
print("  write set = {0,1,2}, read set =", set(r))
print("  read ->", read(store, r), " latest")

r = [3, 4]
print("W=3 R=2   (W+R=5, not > N=5)")
print("  read set =", set(r))
print("  read ->", read(store, r), " stale, missed v2")
