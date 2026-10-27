# HDFS Architecture

**Definition:** HDFS follows a **master-slave architecture**. One master (NameNode) manages the file system namespace and metadata; many slaves (DataNodes) store the actual data blocks. (imp)

## Components
- **NameNode (master)** — one per cluster. Stores metadata: file names, directory tree, permissions, block-to-DataNode mapping. Does NOT store actual data.
- **DataNode (slave)** — many per cluster. Stores actual file blocks on local disk. Serves read/write requests from clients. Sends heartbeat + block report to NameNode.
- **Secondary NameNode** — helper, not a backup/standby. Periodically merges fsimage + edits log (checkpointing) to keep NameNode startup fast.

## Diagram (explain with a diagram)

```
                 +------------------+
   metadata ops  |    NameNode      |   (master: namespace + block map)
   +------------>|  fsimage + edits |
   |             +------------------+
   |                 ^        ^
   | (1) file info   | heartbeat + block report
   |                 |        |
+--------+       +--------+ +--------+ +--------+
| Client |------>|DataNode| |DataNode| |DataNode|   (slaves: store blocks)
+--------+ (2)   |  b1 b3 | |  b1 b2 | |  b2 b3 |
   read/write    +--------+ +--------+ +--------+
   blocks
```

- Client first contacts **NameNode** to get block locations (metadata only).
- Client then reads/writes **blocks directly** from/to DataNodes. Bulk data never flows through NameNode.

## Blocks
- File is split into blocks of 128 MB (default). Last block can be smaller.
- Each block replicated **3 times** (default) on different DataNodes.
- e.g. a 500 MB file = 4 blocks (128 + 128 + 128 + 116 MB), each stored 3x.

## Heartbeat and block report
- **Heartbeat** — DataNode sends signal every 3 sec. No heartbeat for ~10 min → NameNode marks DataNode dead, re-replicates its blocks elsewhere.
- **Block report** — DataNode reports the list of blocks it holds so NameNode keeps the block map current.

## NameNode vs DataNode (differentiate)

| NameNode | DataNode |
|----------|----------|
| Master | Slave |
| One per cluster (SPOF in single-NN setup) | Many per cluster |
| Stores metadata only | Stores actual blocks |
| High RAM machine | Commodity machine |
| Failure = whole cluster down | Failure = blocks re-replicated, cluster runs |
