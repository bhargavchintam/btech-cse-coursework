#!/usr/bin/env python3


class Server:
    def __init__(self, name, up=True):
        self.name = name
        self.up = up


class LB:
    def __init__(self, servers):
        self.servers = servers
        self.i = 0

    def healthy(self):
        return [s for s in self.servers if s.up]

    def pick(self):
        pool = self.healthy()
        if not pool:
            return None
        srv = pool[self.i % len(pool)]
        self.i += 1
        return srv


servers = [Server("s0"), Server("s1"), Server("s2")]
lb = LB(servers)


def check():
    for s in servers:
        print(f"  {s.name}: {'up' if s.up else 'DOWN'}")


print("health check:")
check()
print("routing 6 requests:")
for r in range(6):
    print(f"  req {r} -> {lb.pick().name}")

print("\ns1 goes down")
servers[1].up = False
print("health check:")
check()
print("routing 6 requests (healthy only):")
for r in range(6):
    print(f"  req {r} -> {lb.pick().name}")
