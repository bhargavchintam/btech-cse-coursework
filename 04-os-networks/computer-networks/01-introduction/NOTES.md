# Introduction to Computer Networks

A network is a set of devices (hosts) linked so they can share data. To talk to each other they
have to agree on a lot of things - how the bits go on the wire, how they are addressed, how errors
are caught, what the messages mean. That is a huge job, so it is split into layers. Each layer does
one part and talks to the same layer on the other machine, using the layer below it.

## OSI reference model

Seven layers, top to bottom. Data going down gets a header added at each layer (encapsulation),
and the unit at each layer has its own name (the PDU).

| # | Layer | Job | PDU |
|---|---|---|---|
| 7 | Application | interface to the user's program (HTTP, FTP, SMTP, DNS) | data / message |
| 6 | Presentation | translation, encryption, compression - data format | data |
| 5 | Session | opens, manages and closes conversations between apps | data |
| 4 | Transport | end to end delivery, ports, reliability, flow control | segment |
| 3 | Network | logical (IP) addressing and routing across networks | packet |
| 2 | Data link | framing, MAC addressing, error control on one link | frame |
| 1 | Physical | the actual bits as signals on the medium | bit |

Mnemonic I used: "All People Seem To Need Data Processing" (7 down to 1).

- Physical - voltages, pins, cable, data rate. Just moves raw bits.
- Data link - groups bits into frames, puts MAC addresses on, catches bit errors with a CRC.
  Split into LLC and MAC sublayers.
- Network - the packet gets a source and destination IP, and routers decide the path hop by hop.
- Transport - TCP or UDP. Port numbers pick the right process. TCP adds reliability, ordering,
  flow control; UDP is bare.
- Session - dialog control, keeps track of whose turn it is, checkpoints.
- Presentation - the "syntax" layer. Character encoding, encryption, compression live here.
- Application - the protocols the user actually touches.

## TCP/IP model

The model the internet is really built on. Fewer layers, and it came from working code, not a
committee. Four layers:

| TCP/IP layer | maps to OSI | examples |
|---|---|---|
| Application | 5+6+7 | HTTP, FTP, DNS, SMTP |
| Transport | 4 | TCP, UDP |
| Internet | 3 | IP, ICMP, ARP |
| Network access | 1+2 | Ethernet, Wi-Fi |

## OSI vs TCP/IP

Both are layered and both let each layer be swapped without touching the others. Differences:

- OSI has 7 layers, TCP/IP has 4 (OSI's top three squashed into one Application layer).
- OSI was designed first as a reference, then protocols. TCP/IP was the protocols first, model after.
- OSI splits presentation and session out; TCP/IP just doesn't bother with separate layers for them.
- Nobody runs pure OSI. TCP/IP is what actually runs the internet. OSI is the teaching model.

## Network types by size

- **PAN** - personal area, a few metres. Bluetooth, a phone talking to earbuds.
- **LAN** - local area, one building or campus. Ethernet / Wi-Fi. High speed, one owner.
- **MAN** - metropolitan, a city. A cable TV network, connects LANs across town.
- **WAN** - wide area, country to global. The internet is the biggest WAN. Slower per link, leased.

## Topologies

| topology | pros | cons |
|---|---|---|
| bus | cheap, little cable, easy to add | one backbone break kills all; collisions |
| star | one break isolates one node; easy to manage | central hub/switch is a single point of failure |
| ring | equal access, predictable timing | one node/link down can break the loop |
| mesh | very robust, many paths, no single failure | huge cabling cost, n(n-1)/2 links |

Star is what most real LANs use now (everyone into a switch). Mesh shows up in the backbone
where you can't afford an outage.

## Transmission modes

- **Simplex** - one direction only. Keyboard to computer, TV broadcast.
- **Half duplex** - both directions but one at a time. Walkie-talkie, old hubs.
- **Full duplex** - both directions at once. Phone call, modern switched Ethernet.

## Delay types

Total delay a packet sees on a link is the sum of:

- **Transmission delay** - time to push all the bits out = packet size / bandwidth.
- **Propagation delay** - time for a bit to travel the distance = distance / propagation speed.
- **Processing delay** - router checks the header, does the lookup.
- **Queuing delay** - packet waits in a buffer behind others.

Transmission depends on how fast the link is; propagation depends on how long the wire is. People
mix these two up. The bandwidth-delay product (bandwidth x propagation delay) is how many bits are
"in flight" on the link at once - useful for sizing windows.

> The layer model is the one thing you will be asked in every internal - know each layer, its PDU
> and one protocol.
