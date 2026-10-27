#!/usr/bin/env python3
from collections import deque


class Throttled:
    def __init__(self, n):
        self.state = ["AVAILABLE"] * n   # the vm index table
        self.queue = deque()

    def find(self):
        for i, s in enumerate(self.state):
            if s == "AVAILABLE":
                return i
        return -1

    def request(self, rid):
        vm = self.find()
        if vm == -1:
            self.queue.append(rid)
            print(f"req {rid}: no free vm -> queued")
        else:
            self.state[vm] = "BUSY"
            print(f"req {rid}: -> vm{vm}")
        return vm

    def release(self, vm):
        self.state[vm] = "AVAILABLE"
        print(f"vm{vm} freed")
        if self.queue:
            rid = self.queue.popleft()
            print(f"  dequeue req {rid}")
            self.request(rid)


lb = Throttled(3)
for rid in range(5):
    lb.request(rid)

print()
lb.release(1)
lb.release(0)

print("\nfinal table:", lb.state)
print("still queued:", list(lb.queue))
