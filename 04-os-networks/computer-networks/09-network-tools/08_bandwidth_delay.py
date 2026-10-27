#!/usr/bin/env python3
# bandwidth-delay product, transmission time and effective throughput
import sys


def report(bw_mbps, rtt_ms, size_kb):
    bw = bw_mbps * 1e6            # bits/sec
    rtt = rtt_ms / 1000.0         # sec
    size = size_kb * 1024 * 8     # bits

    bdp = bw * rtt               # bits in flight to keep the pipe full
    tx = size / bw               # time to clock the data onto the link
    total = tx + rtt
    thru = size / total          # bits/sec including one round trip

    print("bandwidth   ", bw_mbps, "Mbps")
    print("rtt         ", rtt_ms, "ms")
    print("data size   ", size_kb, "KB")
    print("bdp         ", "%.0f bits = %.1f KB" % (bdp, bdp / 8 / 1024))
    print("tx time     ", "%.3f ms" % (tx * 1000))
    print("throughput  ", "%.3f Mbps" % (thru / 1e6))


if __name__ == "__main__":
    a = sys.argv[1:]
    bw = float(a[0]) if len(a) > 0 else 100.0     # Mbps
    rtt = float(a[1]) if len(a) > 1 else 20.0      # ms
    size = float(a[2]) if len(a) > 2 else 64.0     # KB
    report(bw, rtt, size)
