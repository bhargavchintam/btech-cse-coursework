#!/usr/bin/env python3
import hashlib

servers = ["s0", "s1", "s2", "s3"]


def pick(ip):
    h = hashlib.md5(ip.encode()).hexdigest()
    return servers[int(h, 16) % len(servers)]


clients = ["203.0.113.5", "198.51.100.22", "192.0.2.9",
           "203.0.113.5", "10.1.1.1", "198.51.100.22"]
for ip in clients:
    print(f"{ip:16} -> {pick(ip)}")

print("\nsame ip three times, always the same server:")
for _ in range(3):
    print("  203.0.113.5 ->", pick("203.0.113.5"))
