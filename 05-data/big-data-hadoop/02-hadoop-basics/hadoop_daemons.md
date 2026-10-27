# Hadoop Daemons

Daemons = background processes that run in a Hadoop cluster (imp - list and explain).

## The 5 daemons
| Daemon | Type | Layer |
|--------|------|-------|
| **NameNode** | master | HDFS |
| **DataNode** | slave | HDFS |
| **ResourceManager** | master | YARN |
| **NodeManager** | slave | YARN |
| **Secondary NameNode** | helper | HDFS |

## 1. NameNode (master - HDFS)
- Stores the **metadata** - file names, block locations, permissions.
- Manages the file system namespace.
- Does not store actual data.
- Single point of failure in Hadoop 1.x (fixed by HA in 2.x).

## 2. DataNode (slave - HDFS)
- Stores the actual **data blocks**.
- Serves read/write requests from clients.
- Sends **heartbeat** + block report to NameNode.

## 3. ResourceManager (master - YARN)
- Manages **cluster resources** (CPU, memory).
- Schedules jobs across the cluster.

## 4. NodeManager (slave - YARN)
- Runs on each slave node.
- Manages **containers** and monitors resource usage on that node.
- Reports node status to ResourceManager.

## 5. Secondary NameNode (helper - HDFS)
- **NOT a backup** of NameNode (common misconception - imp).
- Periodically merges the **edit log** with the **fsimage** (checkpointing).
- Reduces NameNode restart time.

## Where they run
- Master node: NameNode, ResourceManager, (Secondary NameNode).
- Each slave node: DataNode + NodeManager.
