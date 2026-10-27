# Network Tools (Python)

Small command line tools built on the Python standard library. No pip, no scapy, no requests -
everything here uses modules that ship with Python 3: `ipaddress`, `socket`, `struct`, `hashlib`,
`time`, `sys`. The point was to see how much of the plumbing you already have without installing
anything. Turns out most of it.

Run any of them with `python3 NN_name.py`, most take an argument and fall back to a sensible default.

## What each one does

| file | does | main stdlib |
|---|---|---|
| 01_subnet_calculator.py | network addr, mask, broadcast, host range, usable count | `ipaddress` |
| 02_ip_info.py | class A-E, private/public/loopback/multicast, reverse pointer | `ipaddress` |
| 03_port_scanner.py | TCP connect scan of localhost, lists open ports | `socket` |
| 04_connectivity_check.py | is host:port reachable and how long the connect took | `socket`, `time` |
| 05_packet_parser.py | decode a hex Ethernet+IPv4+TCP header into fields | `struct`, `socket` |
| 06_checksum_calculator.py | internet checksum of some bytes, then verify it | (pure) |
| 07_mac_vendor_lookup.py | OUI off a MAC -> vendor from a small table | (pure) |
| 08_bandwidth_delay.py | bandwidth-delay product, tx time, throughput | (pure) |

## ipaddress module

This is the one that saves the most work. `ipaddress.ip_network("192.168.1.0/24")` hands you an
object that already knows `.network_address`, `.netmask`, `.broadcast_address`, `.num_addresses`,
and iterating `net.hosts()` gives the usable addresses. So the subnet calculator is mostly just
printing what the object already worked out. A /24 has 254 usable hosts, a /26 has 62 - the module
and my arithmetic (`num_addresses - 2`) agree.

`ip_address("10.0.0.5")` gives you `.is_private`, `.is_loopback`, `.is_multicast`, `.is_global` and
`.reverse_pointer` (the `5.0.0.10.in-addr.arpa` form used for reverse DNS). Address classes A-E come
from the first octet, so I still work that out by hand from `int(ip) >> 24`.

## sockets for scanning / reachability

A TCP connect scan just tries to `connect()` to each port. `connect_ex()` is the handy one - it
returns the error number instead of raising, so 0 means the port is open and anything else means
closed or filtered. Short timeout so closed ports don't hang. **Localhost only here** - port
scanning machines you don't own is not a good idea and not the point of the exercise.

The connectivity check is the same idea for one port, timed with `time.perf_counter()`. This is a
TCP-connect test, NOT an ICMP ping. Real ping uses a raw socket and raw sockets need root, so a
connect check is the portable way to answer "can I reach this service".

## parsing a header with struct

`struct.unpack` reads binary fields with a format string. `!` means network byte order (big
endian), `H` is a 16-bit int, `I` is 32-bit, so `struct.unpack("!HH", data[t:t+4])` pulls the two
TCP ports at once. The layout I walk through:

```
Ethernet 14 bytes : dst MAC(6) src MAC(6) ethertype(2)
IPv4     20 bytes : ver/IHL(1) ... proto(1) ... src IP(4) dst IP(4)
TCP      20 bytes : src port(2) dst port(2) seq(4) ack(4) offset/flags(2) ...
```

IHL is the low nibble of the first IP byte and it counts 32-bit words, so `(byte & 0x0f) * 4` gives
the header length in bytes - that's how you know where TCP starts. `socket.inet_ntoa` turns the 4
IP bytes back into dotted form. TCP flags live in one byte: URG ACK PSH RST SYN FIN as bits, so a
SYN packet shows flag byte 0x02.

## the internet checksum

Same algorithm IPv4, TCP and UDP all use. Sum the data as 16-bit words, fold any carry from the top
16 bits back into the low 16, then take the ones complement. To verify, you drop the computed value
into the checksum field and run the sum again over the whole thing - a valid header sums back to
zero. Used the classic IP header example (result `0xb861`) to check mine.

> The fold-the-carry step is the bit people forget in the internal. Without it the value is wrong
> for anything that overflows 16 bits.

## bandwidth-delay product

BDP = bandwidth x round-trip time, i.e. how many bits can be "in flight" on the link at once. It's
why a fat but long link (satellite) needs a big TCP window - if the window is smaller than the BDP
you spend most of the time waiting for ACKs and never fill the pipe. Transmission time is just
`size / bandwidth`, separate from propagation delay. These get mixed up a lot: transmission time is
clocking bits onto the wire, propagation is them travelling down it.

## MAC / OUI

The first 3 octets of a MAC are the OUI (Organizationally Unique Identifier), assigned by the IEEE
to a vendor; the last 3 are the NIC id. So `b8:27:eb` -> Raspberry Pi. The real IEEE list has
thousands of entries - I hardcoded a handful to show the lookup.
