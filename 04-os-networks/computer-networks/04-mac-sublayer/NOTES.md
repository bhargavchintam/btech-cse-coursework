# Medium Access Control (MAC) sublayer

When many stations share one channel (one wire, one radio band), only one can transmit at a time or
their signals collide and both are lost. The MAC sublayer is the set of rules that decide whose turn
it is. This is the lower half of the data link layer (the upper half is LLC).

Three families of methods:

- **Random access** - no station is in charge, everyone contends. ALOHA, CSMA, CSMA/CD, CSMA/CA.
- **Controlled access** - stations take turns by some agreed scheme. Polling, token passing.
- **Channelization** - the channel is split up. FDMA, TDMA, CDMA.

## Random access

### Pure ALOHA
Oldest scheme (Hawaii, 1970s). A station sends whenever it has a frame. If two overlap, they
collide, and after a random backoff both resend. A frame is safe only if no other frame starts in
the window of 2 frame-times around it (the "vulnerable time" is 2T).

    S = G * e^(-2G)

S is throughput (successful frames per frame-time), G is the offered load (all attempts). The peak
is at G = 0.5 where S = 1/(2e) = 0.184. So pure ALOHA maxes out at about 18% of the channel.

### Slotted ALOHA
Same idea but time is divided into slots and a station may only start at the beginning of a slot.
That halves the vulnerable time to one frame-time, so:

    S = G * e^(-G)

Peak at G = 1, S = 1/e = 0.368. Doubling the max to about 37% just by adding slots.

### CSMA
"Carrier Sense Multiple Access" - listen before you talk. Check if the channel is busy first.
Persistence methods differ in what you do when it IS busy:

- **1-persistent** - keep sensing, and the moment it goes idle, send. Greedy, so if two were both
  waiting they collide immediately.
- **non-persistent** - if busy, wait a random time, then sense again. Fewer collisions, but you
  can waste idle time.
- **p-persistent** (slotted channels) - when idle, send with probability p, defer to next slot
  with probability 1-p. A compromise between the two.

Sensing does not kill collisions completely because of propagation delay - two stations can both
sense idle before either's signal arrives.

### CSMA/CD
Collision Detection - used by classic Ethernet. Sense the channel; while transmitting keep
listening, and if you detect a collision, stop immediately, send a jam signal, and back off. No
point finishing a frame that's already garbage. Backoff is **binary exponential**: after the k-th
collision, wait a random number of slot-times in the range [0, 2^k - 1], with k capped at 10 (and
give up after 16 tries). More collisions -> bigger random range -> less chance of colliding again.

### CSMA/CA
Collision Avoidance - used by Wi-Fi, where a station can't listen while it sends (can't detect its
own collision on radio). So it avoids instead: sense idle, wait a random backoff, and use
acknowledgements plus optional RTS/CTS to reserve the channel. No ACK means it assumes a collision
and retries.

## Controlled access - token passing

A special frame, the **token**, circulates around the stations (Token Ring, Token Bus). Only the
station holding the token may transmit. When it's done (or its time is up) it passes the token on.
No collisions ever, and access is fair and bounded - you know the worst-case wait. Downside is the
overhead of passing the token even when the ring is idle, and recovering a lost token is fiddly.

## Throughput / utilisation

For a channel, the parameter that matters is

    a = propagation time / transmission time  (Tp / Tf)

The stop-and-wait style channel efficiency is

    U = 1 / (1 + 2a)

Small a (short link or long frames) means high utilisation; large a means you spend most of the
time waiting for the signal to travel and utilisation drops.

## Summary

| method | collisions | max throughput |
|---|---|---|
| pure ALOHA | yes | 0.184 (18%) |
| slotted ALOHA | yes | 0.368 (37%) |
| CSMA/CD | detected, aborted | high on short LANs |
| token passing | none | high, bounded wait |

> Remember the two ALOHA maxima - 1/(2e) and 1/e - they come up every year. I lost a mark once for
> writing 0.5 as the throughput instead of the load G at which the max happens.
