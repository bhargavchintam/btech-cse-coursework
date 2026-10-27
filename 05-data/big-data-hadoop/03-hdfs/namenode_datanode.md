# NameNode and DataNode

## NameNode (master)
**Definition:** The **NameNode** is the master daemon that manages the file system namespace and stores all metadata. (imp)

Metadata it holds:
- File and directory names, the whole directory tree.
- File → block mapping (which blocks make up a file).
- Block → DataNode mapping (which DataNodes hold each block) — this is **not persisted**, it is rebuilt from block reports on startup.
- Permissions, ownership, replication factor.

Metadata is kept **in RAM** for fast access, and persisted on disk as two files:
- **fsimage** — a snapshot of the full namespace at the last checkpoint.
- **edits log (editlog)** — record of every change since the last fsimage.

- On startup NameNode loads fsimage, replays edits, then waits for block reports (safe mode) before serving.
- **Single Point of Failure (SPOF)** in a single-NameNode setup — if it dies, the cluster is unusable. Solved by HA (Active + Standby NameNode using a shared edits + ZooKeeper failover).

## DataNode (slave)
**Definition:** A **DataNode** is a slave daemon that stores the actual data blocks and serves read/write requests. (2 marks)

- Stores blocks as files on its local disk.
- Sends **heartbeat** every 3 sec so NameNode knows it is alive.
- Sends **block report** listing all blocks it holds.
- Performs block creation, deletion, replication on NameNode's instruction.
- Handles the **write pipeline** — forwards blocks to the next DataNode.

## Secondary NameNode (not a backup!)
**Definition:** The **Secondary NameNode** performs **checkpointing** — periodically merges fsimage + edits into a new fsimage so the edits log does not grow forever and NameNode restarts stay fast. (asked prev year)

- It is **NOT** a standby / hot backup of the NameNode. Common misconception.
- Checkpoint steps: pulls fsimage + edits from NameNode → merges into new fsimage → copies it back.

## Comparison (differentiate)
| Feature | NameNode | DataNode |
|---------|----------|----------|
| Role | Master | Slave |
| Stores | Metadata (fsimage, edits) | Actual data blocks |
| Count | One (per namespace) | Many |
| Memory | High RAM | Normal, big disk |
| On failure | Cluster down (SPOF) | Blocks re-replicated, cluster runs |
| Daemon | NameNode | DataNode |
