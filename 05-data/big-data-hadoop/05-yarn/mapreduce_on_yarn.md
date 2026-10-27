# MapReduce on YARN

How a MapReduce job runs on YARN in Hadoop 2.x (imp).

## Background
- In Hadoop 1.x, MapReduce used **JobTracker** + **TaskTracker**.
- In Hadoop 2.x, MapReduce runs **on top of YARN** - it is just one YARN application.
- Mapping of old -> new:
  | Hadoop 1.x | YARN (2.x) |
  |-----------|-----------|
  | JobTracker | ResourceManager + ApplicationMaster |
  | TaskTracker | NodeManager |
  | slot | container |

## How a MR job runs on YARN
1. Client submits the MR job to the **ResourceManager**.
2. RM launches a container for the **MRAppMaster** (the ApplicationMaster for this MR job).
3. MRAppMaster requests containers from RM for the **map** and **reduce** tasks.
4. NodeManagers launch the containers; **map tasks** run first (with data locality).
5. Map output (intermediate key-value) is written to local disk, then **shuffle + sort** moves it to reducers.
6. **Reduce tasks** run in their containers and write final output to **HDFS**.
7. MRAppMaster monitors tasks, re-runs failed ones, then deregisters when done.

## Phases of MapReduce (recap)
- **Map** -> **Shuffle & Sort** -> **Reduce**.
- Map: process input splits, emit (key, value).
- Shuffle/Sort: group values by key, send to reducers.
- Reduce: aggregate values per key, write to HDFS.

## Points
- Each MR job gets its **own ApplicationMaster** (MRAppMaster) - so no single JobTracker bottleneck.
- Old **slots** are replaced by flexible **containers** (any mix of map/reduce).
- Because MR is just a YARN app, Spark and Tez can run on the same cluster.
