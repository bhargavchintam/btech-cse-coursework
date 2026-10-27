# Network Layer

The network layer moves packets from a source host to a destination host across many links,
possibly hopping through several routers on the way. The data link layer only knows about one
hop (machine to next machine on the same wire). This layer is the one that knows the whole path.
Its unit is the IP datagram, and its job is addressing (giving every host a number) and routing
(picking the next hop toward the destination).

## IPv4 addressing

An IPv4 address is 32 bits, written as four dotted decimals, one per byte: `192.168.1.10`. Two
parts: a network part and a host part. Everything on the same network shares the network part.

### Classful (the old way)

The first bits of the address decided the class, which fixed where the network/host split fell.

| class | first bits | first octet | net/host split | use |
|-------|-----------|-------------|----------------|-----|
| A | 0 | 1 - 126 | 8 / 24 | huge networks |
| B | 10 | 128 - 191 | 16 / 16 | medium |
| C | 110 | 192 - 223 | 24 / 8 | small, 254 hosts |
| D | 1110 | 224 - 239 | - | multicast |
| E | 1111 | 240 - 255 | - | reserved / experimental |

127.x.x.x is loopback and sits inside class A's range but is not used for real hosts. Classful
wasted addresses badly - if you needed 300 hosts a class C (254) was too small so you took a
class B (65534) and threw most of it away.

### Classless / CIDR

CIDR drops the fixed classes. You write the split explicitly as a prefix length after a slash:
`192.168.1.0/24` means the first 24 bits are the network. The `/n` is the same thing as a subnet
mask - a run of n ones followed by zeros. `/24` is `255.255.255.0`, `/26` is `255.255.255.192`.

## Subnetting and the mask

The mask is what you AND with the address to get the network. `ip & mask = network`. Flip the
mask and OR it in and you get the broadcast: `network | ~mask`. The usable host range is
everything between, minus those two (network address and broadcast address are not assignable).

Example, `192.168.1.10/26`:

- mask `255.255.255.192`, block size 64
- network `192.168.1.0`, broadcast `192.168.1.63`
- first host `192.168.1.1`, last host `192.168.1.62`, so 62 usable

Subnetting = borrow bits from the host part to make more networks. Borrow b bits and you get
`2^b` subnets, each with `2^(hostbits) - 2` hosts. Borrow 3 from a /24 -> /27, 8 subnets of 30
hosts each. You trade host count for subnet count.

## Routing

A router keeps a table mapping destination networks to a next hop. Two families of algorithm
build those tables.

- **Link state** - every router floods a description of its own links to everyone, so each
  router ends up with the full map and runs Dijkstra on it to get shortest paths. OSPF works
  this way. Dijkstra is the same one from the DAA repo, greedy, picks the closest unvisited node
  each step. Fast to converge, needs more memory (whole topology).
- **Distance vector** - a router only knows its neighbors' distances. It runs Bellman-Ford:
  "cost to X through neighbour N = cost to N + N's cost to X", takes the minimum, and tells its
  neighbours its vector. RIP works this way. Simpler, but slow to react to changes.

Both must agree on the shortest cost for the same graph - link state computes it centrally,
distance vector reaches it by exchanging vectors round after round.

### Count to infinity

Distance vector's weak spot. If a link goes down, the bad news travels slowly while routers keep
believing each other's stale routes, and the cost creeps up 1 at a time toward infinity before
it settles. Split horizon (don't advertise a route back to the neighbour you learned it from)
and poison reverse are the patches. Link state doesn't have this problem.

> Bellman-Ford relaxes every edge n-1 times; Dijkstra needs non-negative weights, Bellman-Ford
> tolerates negatives and can spot a negative cycle.

## ARP and RARP

IP addresses are layer 3, but to actually put a frame on the wire you need the layer 2 MAC
address. ARP (Address Resolution Protocol) bridges the two: a host broadcasts "who has
192.168.1.5?" and the owner replies with its MAC. The answer goes in the ARP cache so you don't
ask again every packet. RARP is the reverse (MAC -> IP), used by diskless machines at boot,
mostly replaced by DHCP now.

## ICMP

The error and diagnostic protocol that rides on top of IP. It carries no user data - it reports
problems. Destination unreachable, time exceeded (TTL hit 0), echo request/reply. `ping` is echo
request/reply, `traceroute` deliberately sends low-TTL packets and reads the time-exceeded
replies to map the hops.

## Fragmentation

Every link has an MTU, the biggest frame it will carry (Ethernet is 1500). If a datagram is
bigger than the next link's MTU, the router splits it into fragments. Each fragment is its own
datagram with the same ID, a fragment offset (counted in 8-byte units, which is why every
fragment except the last carries a multiple of 8 bytes of data), and the MF (more fragments)
flag set on all but the last. The destination reassembles using ID + offset. If DF (don't
fragment) is set instead, an oversize datagram is dropped and an ICMP message comes back.

## IPv4 header

20 bytes without options. The fields that matter:

| field | bits | what it is |
|-------|------|-----------|
| version | 4 | 4 for IPv4 |
| IHL | 4 | header length in 32-bit words |
| total length | 16 | header + data, bytes |
| identification | 16 | groups fragments of one datagram |
| flags | 3 | DF, MF |
| fragment offset | 13 | position of this fragment, in 8-byte units |
| TTL | 8 | hop limit, decremented each router, 0 = drop |
| protocol | 8 | 6 = TCP, 17 = UDP, 1 = ICMP |
| header checksum | 16 | covers the header only |
| source address | 32 | sender IP |
| destination address | 32 | receiver IP |

## Files here

- 01 subnet calculator, 02 number of subnets, 03 CIDR <-> mask.
- 04 Dijkstra, 05 Bellman-Ford - single source shortest paths.
- 06 distance vector, 07 link state - build the routing table for every node.
- 08 longest-prefix-match lookup, 09 ARP simulation, 10 IP fragmentation.
