# Unit 9 — Memory Organization

## The memory hierarchy

One memory that is large, fast and cheap at the same time does not exist, so machines
stack several: a tiny fast one next to the CPU, bigger and slower ones behind it.

Rough 2018 numbers:

| Level         | Typical size    | Access time  | Cost (approx)  | Technology     |
|---------------|-----------------|--------------|----------------|----------------|
| Registers     | under 1 KB      | ~0.3 ns      | part of CPU    | flip-flops     |
| L1 cache      | 32–64 KB/core   | ~1 ns        | ~$500/GB       | SRAM           |
| L2/L3 cache   | 256 KB – 16 MB  | 3–15 ns      | high           | SRAM           |
| Main memory   | 4–16 GB         | 50–100 ns    | ~$8/GB (DDR4)  | DRAM           |
| SSD           | 128 GB – 1 TB   | ~100 µs      | ~$0.25/GB      | flash          |
| Hard disk     | 500 GB – 4 TB   | 5–10 ms      | ~$0.04/GB      | magnetic       |

Each step down: bigger, slower, cheaper per byte. Disk is about ten million times
slower than a register — that gap is why every level in between exists.

## SRAM vs DRAM

SRAM cell: six transistors wired as a flip-flop. Holds its bit as long as power is on.
Fast, but six transistors per bit means low density and high cost.

DRAM cell: one transistor plus one capacitor. The bit is charge on the capacitor.
One transistor per bit gives huge density, but the capacitor leaks — the charge is
gone within tens of milliseconds. So the controller must periodically read every row
and write it back: refresh, roughly every 64 ms per row. Reading a cell also drains
it, so every read is internally followed by a write-back.

| .            | SRAM              | DRAM                    |
|--------------|-------------------|-------------------------|
| cell         | 6-transistor FF   | 1 transistor + 1 cap    |
| speed        | ~1 ns             | 50–100 ns               |
| density      | low               | high                    |
| cost per bit | high              | low                     |
| refresh      | not needed        | every ~64 ms            |
| used in      | caches            | main memory             |

Remember: DRAM needs refresh, SRAM doesn't — do not mix these up like I did in IA1.

## ROM family

- ROM (mask ROM): contents fixed at manufacture, can never change.
- PROM: user programs it once by blowing internal fuses, irreversible.
- EPROM: erase the whole chip with ~20 min of UV light through a quartz window, then reprogram.
- EEPROM: erased electrically, byte at a time, in circuit — but writes are slow.
- Flash: EEPROM erased in large blocks instead of bytes, so denser and faster; pen drives and SSDs.

## Memory chip organization

A "128 x 8" chip stores 128 words of 8 bits: 7 address lines, 8 data lines, a chip
select (CS), and read/write control. Inside, the cells sit in a matrix and a decoder
picks the addressed row.

To build a bigger memory from small chips, two moves:

- **Wider word**: put chips side by side, same address and CS to all, each chip
  supplies its own slice of the data bus.
- **More words (deeper)**: stack rows of chips and let a decoder on the upper address
  bits pick which row's CS is active.

**Worked: build 1K x 16 from 128 x 8 chips.**

- Width: 16 / 8 = 2 chips per row (low byte + high byte).
- Depth: 1024 / 128 = 8 rows. 8 rows need a 3-to-8 decoder.
- Total chips = 8 x 2 = **16**.
- 1K needs 10 address bits: A6..A0 go to every chip, A9..A7 go to the decoder.

```
A9 A8 A7 --> 3-to-8 decoder --> CS0 ... CS7
A6..A0  ---------------------> all chips

         low byte    high byte
row 0    [128x8]     [128x8]    <- CS0
row 1    [128x8]     [128x8]    <- CS1
  ...
row 7    [128x8]     [128x8]    <- CS7
                d7..d0    d15..d8
```

## Cache and locality

Cache works because of the principle of locality:

- **Temporal locality**: what was used recently will likely be used again soon
  (loop counters, the loop body itself).
- **Spatial locality**: addresses near a used address will likely be used soon
  (arrays walked in order, sequential instructions).

So on a miss we fetch a whole block (not one byte) — that bets on spatial locality.
And we keep the block in the cache afterwards — that bets on temporal locality.

## Mapping functions

Every mapping answers the same question: given a memory address, where in the cache
may its block live. The address is cut into fields; offset always picks the byte
inside the block.

**Direct mapped** — each block has exactly one possible line: line = block mod (number of lines).

```
+-----------+-----------+----------+
|    tag    |   index   |  offset  |
+-----------+-----------+----------+
```

Cheap (one comparator) but two hot blocks with the same index keep evicting each other.

**Fully associative** — a block may sit in any line. No index field at all; compare
the tag against every line at once.

```
+-----------------------+----------+
|          tag          |  offset  |
+-----------------------+----------+
```

No conflicts, but one comparator per line — too expensive except for tiny caches (and TLBs).

**k-way set associative** — the compromise. Lines are grouped into sets of k; the set
field picks the set, the block may sit in any of the k lines of that set.

```
+-----------+-----------+----------+
|    tag    |    set    |  offset  |
+-----------+-----------+----------+
```

Direct mapped is 1-way; fully associative is k = number of lines.

> Sir's shortcut: offset bits from the block size, index bits from the number of
> lines (or sets), tag is whatever is left over. Draw the boxes first.

## Worked example — 64 KB space, 1 KB cache, 16 B blocks

64 KB address space means 16-bit addresses. Blocks of 16 B, so offset = log2 16 = 4 bits.
Number of lines = 1024 / 16 = 64.

**Direct mapped:** index = log2 64 = 6 bits, tag = 16 − 6 − 4 = **6 bits**.

```
 15      10 9        4 3      0
+----------+----------+--------+
| tag (6)  | index(6) | off(4) |
+----------+----------+--------+
```

**2-way set associative:** sets = 64 / 2 = 32, set field = log2 32 = 5 bits,
tag = 16 − 5 − 4 = **7 bits**.

```
 15       9 8       4 3      0
+----------+---------+--------+
| tag (7)  | set (5) | off(4) |
+----------+---------+--------+
```

Splitting address 0x2A57 (lines below are the output of cache_mapping.c on this setup):

Direct mapped:

```
tag = 6 bits, index = 6 bits, offset = 4 bits
addr 0x2A57 = 001010 100101 0111   tag=10 index=37 offset=7
```

2-way:

```
tag = 7 bits, set = 5 bits, offset = 4 bits
addr 0x2A57 = 0010101 00101 0111   tag=21 set=5 offset=7
```

So in the direct cache the block can only go to line 37; in the 2-way cache it goes
to either line of set 5. Going from direct to 2-way the index shrank by one bit and
the tag grew by one — halving the sets always costs one tag bit. Got this backwards
in IA2, worth staring at.

## Replacement policies

Only needed when a set is full (direct mapped never chooses — there is one place).

- **LRU**: evict the least recently used line. Best match for temporal locality.
  For 2-way it is one bit per set (which way was touched last); beyond ~4-way the
  bookkeeping gets expensive.
- **FIFO**: evict the line loaded earliest, regardless of use. Cheap counter, but
  can throw out a line that is still hot.
- **Random**: pick any line. Almost free in hardware and surprisingly close to LRU
  for large caches.

## Write policies

- **Write-through**: every write updates cache and main memory. Memory is always
  current, logic is simple, but writes are slow — usually paired with a write buffer.
- **Write-back**: write only the cache copy and set the line's **dirty bit**. The
  block is written to memory only when it gets evicted (and only if dirty). Less
  memory traffic, but memory can be stale and a miss may cost two transfers
  (write old block back, then fetch new one).

The dirty bit belongs to write-back only — write-through has nothing to write back.

## Average access time

With hit ratio h, cache time tc, and main memory time tm (paid on a miss, on top of
the cache lookup):

t_avg = h·tc + (1 − h)(tc + tm) = tc + (1 − h)·tm

**Worked:** h = 0.95, tc = 10 ns, tm = 100 ns.

t_avg = 10 + 0.05 × 100 = **15 ns**

Exam trap: some questions define the miss time as the *total* time on a miss, then
t_avg = h·tc + (1 − h)·tm = 0.95 × 10 + 0.05 × 100 = 14.5 ns. Read the wording; the
default in class was the first form.

## Virtual memory in brief

Each process sees its own large contiguous address space. Hardware plus OS map
virtual **pages** (typically 4 KB) onto physical frames; the mapping lives in the
**page table** in main memory. If the page is not in memory at all — page fault —
the OS brings it from disk. Same hierarchy idea again, with main memory acting as a
cache for the disk.

A page table walk costs an extra memory access per translation, so the CPU keeps a
**TLB** — a small, fully associative cache of recently used page-table entries.
TLB hit: translation is essentially free. TLB miss: walk the page table.

## Solved numericals

**1.** A machine has 32-bit addresses and a direct-mapped cache of 64 KB with 32 B
blocks. Find the field widths.

- offset = log2 32 = 5 bits
- lines = 64 KB / 32 B = 2048, so index = log2 2048 = 11 bits
- tag = 32 − 11 − 5 = 16 bits

**Ans:** tag 16, index 11, offset 5.

**2.** Main memory is 16 MB. Cache is 2 KB, block size 64 B, 4-way set associative.
Find the field widths.

- address = log2 16M = 24 bits
- offset = log2 64 = 6 bits
- lines = 2048 / 64 = 32; sets = 32 / 4 = 8, so set field = log2 8 = 3 bits
- tag = 24 − 3 − 6 = 15 bits

**Ans:** tag 15, set 3, offset 6.

**3.** A cache has hit ratio 0.9, cache access time 20 ns, and a miss costs a further
150 ns for main memory. Find the average access time, and again if the hit ratio
improves to 0.95.

- t_avg = 20 + (1 − 0.9) × 150 = 20 + 15 = 35 ns
- at h = 0.95: t_avg = 20 + 0.05 × 150 = 27.5 ns

**Ans:** 35 ns; improving h to 0.95 brings it down to 27.5 ns.
