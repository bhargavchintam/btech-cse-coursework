# Flow and Error Control

These are the two jobs the data link layer does once framing is sorted. Flow control keeps a fast
sender from drowning a slow receiver. Error control makes sure frames that got lost or corrupted on
the way get sent again, so the layer above sees a clean, in-order stream.

## Flow control

The receiver has a finite buffer. If the sender blasts frames faster than the receiver can process
them, the buffer overflows and frames are dropped. Flow control is the feedback that throttles the
sender to the receiver's pace.

- **Stop-and-wait** - send one frame, then stop and wait for the ACK before sending the next. Dead
  simple, but the link sits idle the whole time the frame and its ACK are in flight. On a long fat
  link that is almost all the time, so it wastes the pipe.
- **Sliding window** - let the sender push up to N frames before it has to stop for an ACK. The
  window is the set of frames it may send without waiting. As ACKs come back the window slides
  forward and more frames become sendable. N is chosen so the sender never runs dry while the first
  ACK is still on the way.

## Error control - ARQ

ARQ = Automatic Repeat reQuest. The receiver checks each frame (checksum/CRC). If a frame is good it
sends an ACK, if it is bad or missing the sender eventually resends it. Three schemes:

- **Stop-and-wait ARQ** - stop-and-wait plus a timer. Send frame, start timer, wait for ACK. If the
  ACK arrives, send the next. If the timer fires first (frame lost, or the ACK lost), resend the same
  frame. The 1-bit sequence number is what lets the receiver spot a duplicate when only the ACK was
  lost.
- **Go-Back-N** - sliding window with a **cumulative** ACK. ACK n means "I have everything up to and
  including n". If frame k is lost, the receiver discards k and everything after it (it will not
  buffer out of order), so the sender times out and resends frame k **and every frame after it**.
  Simple receiver, but a single loss makes you resend a whole window.
- **Selective Repeat** - sliding window with **individual** ACKs and NAKs. The receiver buffers the
  out-of-order frames it did get and NAKs only the one it is missing. The sender resends **only that
  one frame**. Less wasted bandwidth, but the receiver needs a buffer and has to reorder, and the
  window can be at most half the sequence-number space.

## Sequence numbers

Every frame carries a sequence number so duplicates and gaps can be detected. With an m-bit field
the numbers run 0 .. 2^m - 1 and then wrap. Stop-and-wait needs just 1 bit (0/1 alternating). The
window size is bounded by the number space: Go-Back-N allows a window up to 2^m - 1, Selective
Repeat only up to 2^m / 2, otherwise a wrapped-around number is ambiguous.

## ACK / NAK, timers, timeout

- **ACK** - positive, "got it". Go-Back-N ACKs are cumulative, Selective Repeat ACKs are per frame.
- **NAK** - negative, "frame x was bad, resend it". Lets the sender react before the timer expires.
- **Timer / timeout** - each unacked frame has a timer. If no ACK comes back before it fires, the
  sender assumes the frame (or its ACK) was lost and retransmits. The timeout has to be a bit more
  than one round trip - too short and you resend frames that were fine, too long and recovery drags.

## Piggybacking

When both sides are sending data, you do not send a bare ACK frame. You tuck the ACK into the header
of a data frame going the other way - an `ack` field riding along with the payload. Saves a whole
frame. The catch is if you have no data to send back you cannot wait forever for some, so there is a
small delay timer after which you give up and send the ACK on its own.

## Efficiency / utilisation

Let Ttrans be the time to push a frame onto the link and Tprop the one-way propagation delay. The key
ratio is

    a = Tprop / Ttrans

**Stop-and-wait**: the sender is busy for Ttrans then idle for one round trip (2*Tprop) waiting for
the ACK, so

    U = Ttrans / (Ttrans + 2*Tprop) = 1 / (1 + 2a)

**Sliding window** with window N: if N frames go out back to back, the sender stays busy N*Ttrans out
of the same window,

    U = N / (1 + 2a)     capped at 1 when N >= 1 + 2a

so once N reaches 1 + 2a the link is fully used and there is no point growing the window further.

| a  | stop-and-wait U | sliding N=4 | sliding N=7 |
|----|-----------------|-------------|-------------|
| 1  | 0.333           | 1.000 (cap) | 1.000 (cap) |
| 5  | 0.091           | 0.364       | 0.636       |
| 9  | 0.053           | 0.211       | 0.368       |

> a is the number of frames that would fit "in the pipe" at once - that is exactly how many the
> window has to hold to keep the sender busy.

Got the sliding-window cap wrong in the internal - wrote N/(1+2a) = 1.33 for N=4, a=1 and left it,
but utilisation can never exceed 1, it just means the window is bigger than it needs to be.
