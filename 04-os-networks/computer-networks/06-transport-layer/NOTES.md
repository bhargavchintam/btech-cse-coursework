# Transport Layer

The transport layer sits between the application and the network layer. The network layer (IP) gets a
packet from one host to another; the transport layer gets it to the right *process* on that host and,
if you asked for it, makes the delivery reliable. So it turns host-to-host delivery into
process-to-process delivery.

Two protocols do almost all the work: UDP and TCP.

## Ports and sockets

IP addresses find the machine. A port (16-bit, 0-65535) finds the process on it. The pair
(IP + port) on each side plus the protocol is what identifies a connection. A socket is the
programming handle to that endpoint.

- 0-1023 are well known ports: 80 HTTP, 53 DNS, 25 SMTP, 22 SSH, 67/68 DHCP.
- The transport layer demultiplexes: an arriving segment carries a destination port, and the OS
  hands it to whichever process is bound to that port. `05_port_multiplexing.cpp` shows this.

## UDP

User Datagram Protocol. Connectionless and unreliable, and that is the whole point - it is thin.
You send a datagram and hope. No handshake, no acks, no ordering, no flow control. The header is
just 8 bytes: source port, dest port, length, checksum. Good for DNS, DHCP, video, VoIP, anything
where a lost packet is cheaper than the delay of retransmitting it.

## TCP

Transmission Control Protocol. Connection oriented, reliable, ordered byte stream. It costs more but
you get a lot for it.

The unit is a **segment**. Header is 20 bytes minimum: ports, a 32-bit sequence number, a 32-bit
acknowledgement number, flags (SYN, ACK, FIN, RST, PSH, URG), window size, checksum.

**Sequence and ack numbers** count bytes, not segments. seq says "this segment starts at byte X of
my stream". ack says "I have everything up to byte Y, send Y next". That byte counting is how TCP
detects loss and reorders.

**3-way handshake** to open (see `04_three_way_handshake.cpp`):

    client -> SYN  seq=x
    server -> SYN,ACK  seq=y ack=x+1
    client -> ACK  seq=x+1 ack=y+1

SYN and FIN each eat one sequence number even though they carry no data, which is why the acks are
+1. **Teardown** is a 4-way FIN exchange because each side closes its own direction:

    FIN -> , <- ACK , <- FIN , ACK ->

## Flow control vs congestion control

Two different problems, people mix them up.

- **Flow control** stops a fast sender from drowning a slow *receiver*. The receiver advertises a
  window (rwnd) in every ack saying how much buffer it has free. Sender never sends more unacked
  data than that. Sliding window.
- **Congestion control** stops the senders from drowning the *network* in the middle. There is no
  single field for it, the sender infers congestion from loss and keeps its own window, cwnd. The
  amount actually in flight is `min(rwnd, cwnd)`.

### Congestion control phases (`03_congestion_control.cpp`)

- **Slow start** - cwnd starts at 1 MSS and *doubles* every RTT. Exponential, so not that slow.
  Runs until cwnd hits ssthresh (the threshold).
- **Congestion avoidance** - once past ssthresh, cwnd grows by 1 MSS per RTT. Linear, careful.
- **On loss** - this is the AIMD idea: additive increase, multiplicative decrease. Set
  ssthresh = cwnd/2, and drop cwnd (halve it in fast recovery, or all the way to 1 in old Tahoe).
- **Fast retransmit** - three duplicate acks mean a segment was lost; resend it right away instead
  of waiting for the timeout to fire.

The RTO (retransmit timeout) itself is estimated from measured RTTs with Jacobson/Karels:
SRTT is a smoothed average (EWMA), DevRTT tracks how much the samples vary, and
RTO = SRTT + 4*DevRTT. Done in `06_rtt_estimation.cpp`.

> Slow start is exponential and congestion avoidance is linear - do not get those backwards in the exam.

## Traffic shaping: leaky bucket vs token bucket

Both smooth bursty traffic, but differently.

| | Leaky bucket | Token bucket |
|---|---|---|
| output | fixed rate, always steady | can burst up to the tokens saved |
| idle time | wasted, no credit built up | tokens accumulate up to the cap |
| overflow | excess packets dropped | packets wait for a token |
| shape | rigid | flexible, allows bursts |

Leaky bucket (`01_leaky_bucket.cpp`) is a bucket with a hole - water leaks out at a constant rate no
matter how fast it pours in, and if the bucket is full the overflow spills (drop). Token bucket
(`02_token_bucket.cpp`) fills with tokens at a fixed rate up to a cap; a packet needs a token to
leave, so a host that was quiet for a while has saved tokens and can send a burst. Token bucket is
the more forgiving of the two.

## Files here

- 01 leaky bucket, 02 token bucket - traffic shaping traces
- 03 congestion window - slow start / avoidance / halving on loss
- 04 three way handshake + FIN teardown with seq/ack numbers
- 05 port multiplexing - route segments to processes by port
- 06 rtt estimation - SRTT, DevRTT and RTO the Jacobson way
