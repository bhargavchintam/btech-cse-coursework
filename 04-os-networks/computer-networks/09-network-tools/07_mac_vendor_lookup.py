#!/usr/bin/env python3
# pull the OUI (first 3 octets) off a MAC and look up the vendor
import sys

# tiny slice of the IEEE OUI list - the real one has thousands
OUI = {
    "00:00:0C": "Cisco",
    "00:0C:29": "VMware",
    "00:50:56": "VMware",
    "08:00:27": "Oracle VirtualBox",
    "00:1C:42": "Parallels",
    "00:16:3E": "Xensource",
    "B8:27:EB": "Raspberry Pi Foundation",
    "DC:A6:32": "Raspberry Pi Trading",
    "3C:5A:B4": "Google",
    "F4:5C:89": "Apple",
    "00:03:93": "Apple",
}


def lookup(mac):
    parts = mac.replace("-", ":").split(":")
    if len(parts) < 6:
        return None, None
    oui = ":".join(p.upper().zfill(2) for p in parts[:3])
    return oui, OUI.get(oui, "unknown")


if __name__ == "__main__":
    mac = sys.argv[1] if len(sys.argv) > 1 else "b8:27:eb:1a:2b:3c"
    oui, vendor = lookup(mac)
    if oui is None:
        print("bad MAC address")
    else:
        print("mac   ", mac)
        print("oui   ", oui)
        print("vendor", vendor)
