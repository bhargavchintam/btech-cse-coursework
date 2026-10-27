# Experiment 12 — Direct Mapped Cache Simulation

**Date:** 07/12/2018

## Aim
To simulate a direct mapped cache over a fixed address trace in C, report hit or miss
for every access and compute the final hit ratio.

## Tools
gcc (C program, no HDL simulation this week). Compiled with `gcc -std=c99 -Wall cache_mapping.c -o cache_mapping`.

## Theory
In a direct mapped cache each memory block has exactly one line it can occupy:
line = block mod (number of lines). The address splits into tag, index and offset —
the index picks the line, the stored tag is compared against the address tag, and a
match is a hit. It needs only one comparator, but two blocks that share an index keep
evicting each other even when the rest of the cache is empty. These conflict misses
are what the trace below is built to show.

## Design
Cache 512 B, block 32 B → 16 lines. 12-bit addresses:
```
 11      9 8       5 4      0
+---------+---------+--------+
| tag (3) | index(4)| off(5) |
+---------+---------+--------+
```
One tag array of 16 entries initialised to −1 (empty). For each address: block =
addr >> 5, line = block mod 16, tag = block / 16; compare, count, replace on miss.
Blocks 2 and 18 both map to line 2, and blocks 13 and 29 both map to line 13, so the
trace ping-pongs between them to force conflict misses.

## Code
- `cache_mapping.c` — trace of 16 addresses, prints block/line/tag and hit or miss per access, then the hit ratio

## Observations
```
  #  addr   block  line  tag  result
  1  0x040     2     2    0   miss
  2  0x044     2     2    0   hit
  3  0x240    18     2    1   miss
  4  0x040     2     2    0   miss
  5  0x100     8     8    0   miss
  6  0x108     8     8    0   hit
  7  0x24C    18     2    1   miss
  8  0x100     8     8    0   hit
  9  0x3A0    29    13    1   miss
 10  0x3BC    29    13    1   hit
 11  0x1A0    13    13    0   miss
 12  0x040     2     2    0   miss
 13  0x048     2     2    0   hit
 14  0x3A0    29    13    1   miss
 15  0x108     8     8    0   hit
 16  0x800    64     0    4   miss
```
```
hits = 6 / 16, hit ratio = 0.38
```

## Result
The simulation gives 6 hits out of 16 accesses, hit ratio 0.38 (sequence
MHMMMHMHMHMMHMHM, checked by hand). Accesses 3, 4, 7 and 12 are conflict misses
between blocks 2 and 18 on line 2 — the cache is mostly empty yet they still evict
each other, which is the weakness of direct mapping.
