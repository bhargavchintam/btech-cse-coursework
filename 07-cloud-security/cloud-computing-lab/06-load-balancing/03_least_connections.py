#!/usr/bin/env python3

servers = ["s1", "s2", "s3"]
conns = {s: 0 for s in servers}


def pick():
    return min(servers, key=lambda s: conns[s])


ops = ["open", "open", "open", "open",
       "close s1", "open", "close s2", "open", "open"]

for op in ops:
    if op.startswith("close"):
        s = op.split()[1]
        if conns[s] > 0:
            conns[s] -= 1
        print(f"{op:10} {conns}")
    else:
        s = pick()
        conns[s] += 1
        print(f"open -> {s}   {conns}")

print("\nactive connections:", conns)
