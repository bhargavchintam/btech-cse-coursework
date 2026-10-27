# Hadoop Versions - 1.x vs 2.x vs 3.x

Differentiate the Hadoop versions (imp).

## Hadoop 1.x
- Components: **HDFS + MapReduce** only.
- **No YARN.**
- Resource management + job scheduling done by **JobTracker** and **TaskTracker**.
- JobTracker did both scheduling and monitoring -> bottleneck, single point of failure.
- Only **MapReduce** could run (no other frameworks).
- Max ~4000 nodes per cluster.

## Hadoop 2.x
- **YARN introduced** (this is the biggest change - imp).
- JobTracker/TaskTracker replaced by **ResourceManager, NodeManager, ApplicationMaster**.
- Now non-MapReduce frameworks (Spark, Tez) can also run on the cluster.
- **NameNode High Availability (HA)** - active + standby NameNode (removes SPOF).
- Default block size 128 MB.
- Scales to ~10,000 nodes.

## Hadoop 3.x
- **Erasure coding** in HDFS - storage overhead ~50% instead of 200% (replication uses 3x storage; EC is cheaper).
- Supports **more than 2 NameNodes** for HA.
- YARN improvements, GPU / Docker support.
- Requires **Java 8+**.
- Default block size 128 MB.

## Comparison table
| Feature | 1.x | 2.x | 3.x |
|---------|-----|-----|-----|
| YARN | No | Yes | Yes |
| Processing | MapReduce only | any (Spark etc.) | any |
| Resource mgmt | JobTracker/TaskTracker | RM/NM/AM | RM/NM/AM |
| NameNode HA | No | Yes (2 NN) | Yes (>2 NN) |
| Fault tolerance | replication | replication | replication + erasure coding |
| Storage overhead | 3x | 3x | ~1.5x (EC) |

## One-liners to remember
- **Hadoop 1.x has NO YARN.**
- **YARN was added in Hadoop 2.x.**
- Erasure coding is the highlight of **3.x**.
