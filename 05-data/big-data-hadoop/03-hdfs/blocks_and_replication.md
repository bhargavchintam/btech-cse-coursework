# Blocks and Replication

## Block
**Definition:** A **block** is the smallest unit of data that HDFS reads/writes. A large file is split into blocks and stored across DataNodes. (2 marks)

- Default block size = **128 MB** in Hadoop 2.x and 3.x.
- In Hadoop 1.x the default was **64 MB**.
- Configured by `dfs.blocksize` in `hdfs-site.xml`.
- Last block of a file may be smaller than 128 MB (no wasted space — a 20 MB file uses only 20 MB on disk, not a full block).

### Why block size is large (imp)
- **Reduce NameNode metadata** — fewer blocks per file means fewer entries to track in NameNode RAM.
- **Reduce seek time** — with big blocks, disk seek time becomes tiny compared to transfer time, so reads are mostly sequential (high throughput).
- Rule of thumb: seek time ≈ 10 ms, transfer rate ≈ 100 MB/s → block ~128 MB keeps seek overhead ~1%.

### Block example
File = 500 MB, block = 128 MB
→ 128 + 128 + 128 + 116 = **4 blocks**.

## Replication
**Definition:** **Replication** = storing multiple copies of each block on different DataNodes for fault tolerance and availability. (imp)

- Default **replication factor = 3**.
- Configured by `dfs.replication` in `hdfs-site.xml`.
- Can be set per file with `hdfs dfs -setrep`.
- 500 MB file with 4 blocks and RF 3 → 12 block copies stored, 1500 MB raw disk used.

### Rack awareness (replica placement)
For RF = 3 the default placement is:
- **1st replica** — on the local node (or a random node if client is outside cluster).
- **2nd replica** — on a node in a **different rack**.
- **3rd replica** — on a **different node in the same rack** as the 2nd.

Reason: survive a whole rack failure while not using too much cross-rack bandwidth.

### Under- / over-replication
- **Under-replicated** — a DataNode died, fewer than RF copies exist → NameNode schedules new copies.
- **Over-replicated** — more copies than RF (e.g. dead node comes back) → NameNode deletes extras.

## Quick facts (asked prev year)
| Item | Value |
|------|-------|
| Default block size (Hadoop 2/3) | 128 MB |
| Old block size (Hadoop 1) | 64 MB |
| Default replication factor | 3 |
| Block size config key | dfs.blocksize |
| Replication config key | dfs.replication |
