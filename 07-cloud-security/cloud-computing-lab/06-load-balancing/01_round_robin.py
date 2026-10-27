#!/usr/bin/env python3

servers = ["10.0.0.1", "10.0.0.2", "10.0.0.3"]


class RoundRobin:
    def __init__(self, servers):
        self.servers = servers
        self.i = 0

    def pick(self):
        srv = self.servers[self.i % len(self.servers)]  # wrap around the list
        self.i += 1
        return srv


lb = RoundRobin(servers)
counts = {s: 0 for s in servers}

for r in range(10):
    srv = lb.pick()
    counts[srv] += 1
    print(f"req {r} -> {srv}")

print("\ndistribution")
for s in servers:
    print(f"  {s}: {counts[s]}")
