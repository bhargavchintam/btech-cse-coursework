# Unit 8 — Memory Management

## Allocation of a partition
When a process needs memory, pick a free block:
- **First fit** — the first block big enough (fast).
- **Best fit** — the smallest block that fits (least leftover, but slow and leaves tiny holes).
- **Worst fit** — the largest block (leaves a usable remainder).

**Fragmentation:** *external* (free memory split into small scattered holes), *internal* (allocated
block bigger than needed).

## Paging
Logical memory is split into **pages**, physical memory into **frames** of the same size; a **page table**
maps page → frame. Removes external fragmentation. A logical address = (page number, offset).

## Page replacement (on a page fault, when no free frame)
| Algorithm | Evict | On the standard string (3 frames) |
|---|---|---|
| **FIFO** | oldest loaded page | 15 faults (can show Belady's anomaly) |
| **LRU** | least recently used | 12 faults |
| **Optimal** | the one not needed for the longest | 9 faults (the lower bound) |

(reference string 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1 — see `fifo_page.cpp` / `lru_page.cpp` / `optimal_page.cpp`)

## Solved
**1. Which page-replacement algorithm is optimal?** OPT (Belady's) — evict the page used farthest in the
future; it gives the minimum faults but needs future knowledge, so it's a benchmark only.
**2. Best fit vs worst fit for external fragmentation?** Best fit leaves many tiny unusable holes;
worst fit leaves larger, more reusable remainders.
