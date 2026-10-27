#!/usr/bin/env python3
# lab 13 - subnet calculator using the ipaddress module
# give it an address with a prefix like 192.168.1.0/26 and it works out the
# network address, mask, broadcast, usable host range and the host count.
import ipaddress
import sys


def main():
    cidr = sys.argv[1] if len(sys.argv) > 1 else input("network (a.b.c.d/prefix): ").strip()
    net = ipaddress.ip_network(cidr, strict=False)

    print("network   :", net.network_address)
    print("netmask   :", net.netmask)
    print("wildcard  :", net.hostmask)
    print("broadcast :", net.broadcast_address)
    print("prefix    : /%d" % net.prefixlen)

    hosts = list(net.hosts())
    print("usable    :", len(hosts))
    if hosts:
        print("first host:", hosts[0])
        print("last host :", hosts[-1])


if __name__ == "__main__":
    main()
