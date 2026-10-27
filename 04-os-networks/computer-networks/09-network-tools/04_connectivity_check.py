#!/usr/bin/env python3
# reachability by TCP connect (not real ICMP ping - that needs root)
import socket
import sys
import time


def check(host, port, timeout=2.0):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.settimeout(timeout)
    t0 = time.perf_counter()
    try:
        s.connect((host, port))
        dt = (time.perf_counter() - t0) * 1000
        print("%s:%d reachable in %.2f ms" % (host, port, dt))
    except OSError as e:
        print("%s:%d not reachable (%s)" % (host, port, e))
    finally:
        s.close()


if __name__ == "__main__":
    host = sys.argv[1] if len(sys.argv) > 1 else "127.0.0.1"
    port = int(sys.argv[2]) if len(sys.argv) > 2 else 80
    check(host, port)
