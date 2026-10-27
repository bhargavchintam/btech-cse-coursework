#!/usr/bin/env python3

ids = [1, 2, 3, 4, 5]
alive = {1, 2, 3, 4}        # 5 was the leader and just crashed

def higher(p):
    return [q for q in ids if q > p]

def announce(p):
    print(f"p{p} won, sends COORDINATOR")
    for q in ids:
        if q != p and q in alive:
            print(f"  p{p} -> COORDINATOR -> p{q}")

def election(p):
    print(f"p{p} starts an election")
    replies = []
    for q in higher(p):
        print(f"  p{p} -> ELECTION -> p{q}")
        if q in alive:
            print(f"  p{q} -> OK -> p{p}")
            replies.append(q)
    if not replies:
        announce(p)
        return p
    return election(max(replies))       # highest that answered takes over


print("leader p5 stopped responding, p2 notices\n")
leader = election(2)
print(f"\nnew leader: p{leader}")
