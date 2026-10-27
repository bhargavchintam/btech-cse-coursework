#!/usr/bin/env python3
# classify an IPv4 address - class, type, reverse pointer
import ipaddress
import sys


def klass(ip):
    first = int(ip) >> 24
    if first < 128:
        return "A"
    if first < 192:
        return "B"
    if first < 224:
        return "C"
    if first < 240:
        return "D (multicast)"
    return "E (reserved)"


def info(s):
    ip = ipaddress.ip_address(s)
    if ip.version != 4:
        print("not IPv4")
        return

    kind = "public"
    if ip.is_loopback:
        kind = "loopback"
    elif ip.is_private:
        kind = "private"
    elif ip.is_multicast:
        kind = "multicast"
    elif ip.is_reserved:
        kind = "reserved"

    print("address ", ip)
    print("class   ", klass(ip))
    print("type    ", kind)
    print("global  ", ip.is_global)
    print("reverse ", ip.reverse_pointer)


if __name__ == "__main__":
    s = sys.argv[1] if len(sys.argv) > 1 else "192.168.1.10"
    info(s)
