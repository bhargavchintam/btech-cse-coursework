#!/usr/bin/env python3
# internet checksum - ones complement of the 16-bit word sum
import sys

# classic IP header example, checksum field (bytes 10-11) left as 0000
SAMPLE = "45000073000040004011 0000 c0a80001 c0a800c7".replace(" ", "")


def checksum(data):
    if len(data) % 2:
        data += b"\x00"
    s = 0
    for i in range(0, len(data), 2):
        s += (data[i] << 8) + data[i + 1]
        s = (s & 0xffff) + (s >> 16)      # fold the carry back in
    return ~s & 0xffff


if __name__ == "__main__":
    hexstr = sys.argv[1] if len(sys.argv) > 1 else SAMPLE
    data = bytes.fromhex(hexstr)

    c = checksum(data)
    print("checksum  ", "0x%04x" % c)

    # drop it back into the header and it should now sum to zero
    filled = data[:10] + bytes([c >> 8, c & 0xff]) + data[12:]
    print("verify    ", "0x%04x" % checksum(filled), "(0 means valid)")
