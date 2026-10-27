#!/usr/bin/env python3
# lab 4 - two load balancers over a pool of servers. round robin cycles through
# them in order; least-connections sends each request to whoever is holding the
# fewest live connections right now.

servers = ["s0", "s1", "s2", "s3"]


class RoundRobin:
    def __init__(self, servers):
        self.servers = servers
        self.i = 0

    def pick(self):
        s = self.servers[self.i]
        self.i = (self.i + 1) % len(self.servers)   # wrap around the pool
        return s


class LeastConn:
    def __init__(self, servers):
        self.live = {s: 0 for s in servers}

    def pick(self):
        s = min(self.live, key=self.live.get)
        self.live[s] += 1
        return s

    def done(self, s):
        self.live[s] -= 1


rr = RoundRobin(servers)
print("round robin, 10 requests:")
print(" ", [rr.pick() for _ in range(10)])

lc = LeastConn(servers)
reqs = [(0, 5), (1, 4), (2, 4), (3, 3), (4, 2), (5, 2), (6, 3), (7, 2)]  # arrival, duration
active = []
print("\nleast-connections:")
for t, dur in reqs:
    still = []
    for done_at, s in active:
        if done_at <= t:
            lc.done(s)
        else:
            still.append((done_at, s))
    active = still
    s = lc.pick()
    active.append((t + dur, s))
    print(f"  t={t} req(dur {dur}) -> {s}   live={lc.live}")
