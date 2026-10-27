# Hadoop Architecture

Hadoop follows a **master-slave** architecture (imp - explain with diagram).

## Two layers
1. **Storage layer -> HDFS**
   - Master: **NameNode**
   - Slaves: **DataNodes**
2. **Processing / resource layer -> YARN** (with MapReduce)
   - Master: **ResourceManager**
   - Slaves: **NodeManagers**

## Master-slave diagram (text)
```
                +------------------+        +---------------------+
   Masters      |    NameNode      |        |  ResourceManager    |
                | (HDFS metadata)  |        | (cluster resources) |
                +--------+---------+        +----------+----------+
                         |                             |
        -----------------+--------------+--------------+-----------------
        |                |                             |                |
   +----+----+     +-----+----+                  +-----+----+     +-----+----+
   | DataNode |    | DataNode |   ...            |NodeManager|    |NodeManager|
   |  +block  |    |  +block  |                  | +Container|    | +Container|
   +----------+    +----------+                  +----------+     +----------+
        Slaves (each node runs a DataNode + a NodeManager)
```

## How it works
- A big file is split into **blocks** (default 128 MB in Hadoop 2.x/3.x).
- Blocks are distributed and **replicated** across DataNodes (default replication = 3).
- **NameNode** stores only metadata (which block is on which DataNode); it does not store actual data.
- **DataNodes** store the actual data blocks and send heartbeats to the NameNode.
- For a job, **ResourceManager** allocates resources; **NodeManagers** run the tasks in **containers** on the slave nodes.
- **Data locality** - tasks are run on the node that holds the data block to avoid network transfer.

## Points
- Master node keeps metadata; slave nodes keep data + do the work.
- One cluster = 1 NameNode (master) + many DataNodes (slaves).
- Failure of a DataNode is handled by replication.
