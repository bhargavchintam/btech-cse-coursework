#!/usr/bin/env python3

class Node:
    def __init__(self, name, cpu, mem):
        self.name = name
        self.cpu = cpu
        self.mem = mem
        self.pods = []

    def fits(self, pod):
        return self.cpu >= pod.cpu and self.mem >= pod.mem

    def place(self, pod):
        self.cpu -= pod.cpu
        self.mem -= pod.mem
        self.pods.append(pod.name)


class Pod:
    def __init__(self, name, cpu, mem):
        self.name = name
        self.cpu = cpu
        self.mem = mem


def schedule(pods, nodes):
    rejected = []
    for pod in pods:
        cand = [n for n in nodes if n.fits(pod)]
        if not cand:
            rejected.append(pod)
            continue
        # best-fit: pick the node left with the least room
        node = min(cand, key=lambda n: (n.cpu - pod.cpu) + (n.mem - pod.mem))
        node.place(pod)
    return rejected


nodes = [
    Node("node-1", 4000, 8192),
    Node("node-2", 2000, 4096),
    Node("node-3", 1000, 2048),
]

pods = [
    Pod("api-1", 500, 1024),
    Pod("api-2", 500, 1024),
    Pod("worker", 1000, 2048),
    Pod("cache", 800, 3072),
    Pod("db", 1500, 4096),
    Pod("batch", 2000, 2048),
    Pod("huge", 8000, 16384),
]

rejected = schedule(pods, nodes)

for n in nodes:
    print(n.name, "cpu left", n.cpu, "mem left", n.mem, "->", n.pods)

if rejected:
    print("rejected:", [p.name for p in rejected])
else:
    print("rejected: none")
