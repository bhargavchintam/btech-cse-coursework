#!/usr/bin/env python3
# lab 14 - TCP connect port scanner, localhost only
# tries a normal connect to each port in the range. if connect_ex returns 0 the
# three way handshake finished so the port is open, anything else is closed.
import socket
import sys

host = "127.0.0.1"


def main():
    start, end = 1, 1024
    if len(sys.argv) == 3:
        start, end = int(sys.argv[1]), int(sys.argv[2])

    print("scanning %s ports %d-%d" % (host, start, end))
    for port in range(start, end + 1):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.settimeout(0.2)
        if s.connect_ex((host, port)) == 0:
            print("port %d open" % port)
        s.close()
    print("done")


if __name__ == "__main__":
    main()
