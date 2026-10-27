# Data Link Layer

Layer 2. Takes the raw bit stream from the physical layer and turns it into something
the network layer can trust - it groups bits into **frames**, puts a header and trailer
around them, and handles error detection/correction and (in the next folder) flow control.
Two sublayers: LLC on top, MAC below (MAC is folder 04).

A frame is just: **header + payload + trailer**. The header carries addresses and control
info, the payload is the network-layer packet, and the trailer usually carries the error
check (FCS - frame check sequence). The whole job of this layer is node-to-node delivery
over a single link, not end-to-end.

## Framing

The receiver has to know where a frame starts and ends. Four ways:

- **Byte count** - first field says how many bytes the frame has. Simple, but if that count
  byte gets corrupted the receiver loses sync for the rest of the stream. `09_byte_count_framing.cpp`.
- **Byte / character stuffing** - frame delimited by flag bytes `DLE STX` ... `DLE ETX`.
  If a `DLE` appears in the actual data it gets doubled (`DLE DLE`) so it isn't mistaken for
  a control sequence. Receiver removes one of each doubled pair. `02_character_stuffing.cpp`.
- **Bit stuffing** - flag is `01111110`. After **five consecutive 1s** in the data the sender
  stuffs a `0`, so the flag pattern can never appear inside the payload. Receiver deletes the
  0 that follows five 1s. `01_bit_stuffing.cpp`. This is what HDLC uses.
- Physical layer coding violations (not done here).

Character stuffing is byte-oriented so it's tied to 8-bit chars; bit stuffing works on any
bit count, which is why the newer protocols use it.

## Error detection

Noise flips bits. We add redundant bits so the receiver can tell something went wrong.

- **Parity / VRC** (vertical redundancy check) - one bit per unit. Even parity makes the total
  number of 1s even, odd parity makes it odd. Catches any odd number of bit errors, misses even
  ones. `03_parity_vrc.cpp`.
- **LRC** (longitudinal redundancy check) - parity computed down each column of a block of bytes,
  giving one extra LRC byte. It's just the XOR of all the data bytes. Catches a lot more than a
  single parity bit but still misses some 2-bit patterns. `04_lrc.cpp`.
- **2D parity** - VRC across rows *and* LRC down columns. A single-bit error shows up as one bad
  row and one bad column, and where they cross is the bad bit - so 2D parity can actually *locate*
  (and fix) a single error. `10_two_dimensional_parity.cpp`.
- **Internet checksum** - used by IP/TCP/UDP. Add up the data as 16-bit words in 1s-complement
  (fold the carry back in), then send the complement of the sum. Receiver adds everything up
  *including* the checksum and should get all 1s, i.e. complement 0. `05_checksum.cpp`.
- **CRC** - the strong one, treats the bits as a polynomial and divides (mod-2) by a generator
  polynomial. The remainder is the FCS, appended to the frame. Receiver divides the whole thing
  by the same generator and gets **0** if there was no error. See below.

## CRC

`06_crc.cpp` uses CRC-CCITT, generator `10001000000100001` which is x^16 + x^12 + x^5 + 1.

Sender appends `(len(gen) - 1)` zeros to the data, does mod-2 division (XOR, no borrows/carries),
and the remainder replaces those zeros. Worked example from the program:

```
data      1101011011
remainder 1011111011001101
codeword  11010110111011111011001101
```

Receiver divides the codeword by the generator: remainder all-zero = clean, anything else = error.
I flipped one bit in the program to show the receiver remainder go non-zero.

> divide with XOR, not subtraction - there are no carries in mod-2. Got that wrong in the internal
> the first time and every remainder came out garbage.

## Error correction (Hamming)

Detection just tells you to ask for a resend. Hamming code actually **corrects** a single-bit
error at the receiver (forward error correction).

Parity bits go at the positions that are powers of 2 (1, 2, 4, 8, ...). For m data bits you need
r parity bits where `2^r >= m + r + 1`. Parity bit at position p checks every position whose index
has that bit set. `07_hamming_code.cpp` builds it - data `1011` gives the (7,4) codeword `0110011`.

At the receiver (`08_hamming_correction.cpp`) recompute each parity check; the failing checks, added
up, give the **syndrome** - and the syndrome *is* the position of the bad bit. Flip it and you're
back to the original. Codeword `0110111` (error in bit 5) -> syndrome 5 -> corrected to `0110011`.
Syndrome 0 means no error.

| scheme          | adds        | detects            | corrects       |
|-----------------|-------------|--------------------|----------------|
| parity / VRC    | 1 bit       | odd # of errors    | no             |
| LRC             | 1 byte      | most burst errors  | no             |
| 2D parity       | row+col     | single + many      | single bit     |
| checksum        | 16 bits     | many               | no             |
| CRC             | FCS (16 b)  | bursts up to r     | no             |
| Hamming         | r bits      | single (+detect 2) | single bit     |

CRC is what actually rides in the frame trailer on real links (Ethernet uses CRC-32). Hamming
shows up more in memory (ECC RAM) than on the wire, but it's the standard FEC example.
