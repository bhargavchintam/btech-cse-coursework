#!/usr/bin/env python3
# subnet calc - give it a network/CIDR, prints the useful numbers
import ipaddress
import sys


def show(cidr):
    net = ipaddress.ip_network(cidr, strict=False)
    n = net.num_addresses

    print("cidr      ", net.with_prefixlen)
    print("network   ", net.network_address)
    print("netmask   ", net.netmask)
    print("wildcard  ", net.hostmask)
    print("broadcast ", net.broadcast_address)
    if n > 2:
        print("host range", net[1], "-", net[-2])
        print("usable    ", n - 2)
    else:
        # /31 and /32, no room for a broadcast + gateway split
        print("host range", net[0], "-", net[-1])
        print("usable    ", n)


if __name__ == "__main__":
    cidr = sys.argv[1] if len(sys.argv) > 1 else "192.168.1.0/24"
    show(cidr)
