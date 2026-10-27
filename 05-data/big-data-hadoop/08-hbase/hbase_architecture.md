# HBase Architecture

Master-slave architecture. Three main components: **HMaster**, **Region Servers**, **Zookeeper**. Storage on **HDFS**.

## HMaster (master)
- Assigns **regions** to region servers.
- Handles load balancing across region servers.
- Handles DDL operations — create, delete, alter table.
- Monitors region servers (via Zookeeper), reassigns regions if a RS fails.
- Not in the read/write data path -> if HMaster down, cluster still serves reads/writes for a while.
- Can run multiple HMasters, one active + others standby (Zookeeper elects active). (imp)

## Region Server (slave)
- Serves the actual data — handles client read/write requests.
- Runs on the DataNode of Hadoop cluster (data locality).
- Manages a set of **regions**.
- Components inside a RS:
  - **WAL (Write Ahead Log)** — every write first written to WAL on HDFS (for recovery after crash).
  - **BlockCache** — read cache, keeps frequently read data in memory (LRU).
  - **MemStore** — write cache, one per column family per region. Holds new data in memory before flush.
  - **HFile** — MemStore flushed to disk as HFile on HDFS. Actual sorted key-value storage.

## Region
- **Definition:** A region is a contiguous, sorted range of rows of a table, split by row key range (start key -> end key).
- Table starts as one region. As it grows past a threshold it **auto-splits** into two.
- Regions distributed across region servers -> horizontal scaling.
- One region served by exactly one region server at a time.

## Zookeeper
- Coordination service for the cluster.
- Keeps track of which region servers are alive (heartbeat / ephemeral nodes).
- Active HMaster election.
- Stores location of the **META** table -> client uses it to find regions.
- If a RS session with Zookeeper expires -> HMaster notified -> region reassigned.

## Read/Write flow (short)
- Client asks Zookeeper -> gets META location -> reads META to find which RS holds the region -> talks to that RS directly.
- Write: WAL -> MemStore -> (later) flush to HFile.
- Read: check BlockCache, then MemStore, then HFile.

## META table
- Special catalog table `hbase:meta`. Maps table regions -> region server. Location kept in Zookeeper.

Diagram (asked prev year): Client -> Zookeeper -> META -> RegionServer(Region -> MemStore/WAL/HFile) -> HDFS.
