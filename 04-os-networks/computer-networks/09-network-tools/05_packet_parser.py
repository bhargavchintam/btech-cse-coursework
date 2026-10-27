#!/usr/bin/env python3
# Bindu Bhargava   18-10-19
# parse a hex dump of an Ethernet + IPv4 + TCP header into its fields
import socket
import struct
import sys

# sample frame: 192.168.0.1:54321 -> 192.168.0.200:80, TCP SYN
SAMPLE = ("aabbccddeeff112233445566" "0800"
          "4500003c1c4640004006b1e6c0a80001c0a800c8"
          "d431005012345678000000005002721000000000")

FLAGS = [(0x20, "URG"), (0x10, "ACK"), (0x08, "PSH"),
         (0x04, "RST"), (0x02, "SYN"), (0x01, "FIN")]


def mac(b):
    return ":".join("%02x" % x for x in b)


def parse(hexstr):
    data = bytes.fromhex(hexstr)

    dst_mac = data[0:6]
    src_mac = data[6:12]
    etype = struct.unpack("!H", data[12:14])[0]

    ip = 14                      # IP header starts after the 14 byte ethernet
    ihl = (data[ip] & 0x0f) * 4
    proto = data[ip + 9]
    src_ip = socket.inet_ntoa(data[ip + 12:ip + 16])
    dst_ip = socket.inet_ntoa(data[ip + 16:ip + 20])

    tcp = ip + ihl
    src_port, dst_port = struct.unpack("!HH", data[tcp:tcp + 4])
    seq, ack = struct.unpack("!II", data[tcp + 4:tcp + 12])
    fbyte = data[tcp + 13]
    on = [name for bit, name in FLAGS if fbyte & bit]

    print("--- ethernet ---")
    print("dst mac  ", mac(dst_mac))
    print("src mac  ", mac(src_mac))
    print("ethertype", hex(etype))
    print("--- ipv4 ---")
    print("src ip   ", src_ip)
    print("dst ip   ", dst_ip)
    print("protocol ", proto, "(TCP)" if proto == 6 else "")
    print("--- tcp ---")
    print("src port ", src_port)
    print("dst port ", dst_port)
    print("seq      ", seq)
    print("ack      ", ack)
    print("flags    ", " ".join(on) if on else "-")


if __name__ == "__main__":
    parse(sys.argv[1] if len(sys.argv) > 1 else SAMPLE)
