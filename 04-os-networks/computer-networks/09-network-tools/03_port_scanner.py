#!/usr/bin/env python3
# TCP connect scan of localhost only - lists which ports are open
import socket
import sys


def scan(host, lo, hi):
    found = []
    for port in range(lo, hi + 1):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.settimeout(0.3)
        if s.connect_ex((host, port)) == 0:
            found.append(port)
        s.close()
    return found


if __name__ == "__main__":
    host = "127.0.0.1"
    lo = int(sys.argv[1]) if len(sys.argv) > 1 else 1
    hi = int(sys.argv[2]) if len(sys.argv) > 2 else 1024

    print("scanning", host, "ports", lo, "-", hi)
    open_ports = scan(host, lo, hi)
    if open_ports:
        for p in open_ports:
            print("open", p)
    else:
        print("no open ports in range")
