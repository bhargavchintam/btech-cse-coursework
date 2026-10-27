# Features of HDFS

List and explain the main features of HDFS. (imp)

## Fault tolerance
- Each block replicated (default **3** copies) on different DataNodes.
- If a DataNode dies, blocks are still available from other replicas.
- NameNode detects the dead node (no heartbeat ~10 min) and **re-replicates** the lost blocks to restore RF.

## High throughput
- Data split into blocks and stored across many machines → read/write in **parallel**.
- Optimised for **batch processing** and streaming access, not low-latency random reads.
- Large block size (128 MB) keeps disk seek overhead low → mostly sequential I/O.

## Rack awareness
- HDFS knows which rack each DataNode is on.
- Replica placement uses this: keep one replica on another rack to survive a full rack failure, keep others in the same rack to save cross-rack bandwidth. (asked prev year)
- Also used to read from the **nearest** DataNode.

## Data locality
- **Move computation to data**, not data to computation.
- MapReduce/YARN tries to run a task on the same node that holds the block → less network traffic.

## Scalability (horizontal)
- Add more commodity DataNodes to grow storage and throughput.
- Scales to thousands of nodes and PB-scale data.

## Reliability / replication
- Write-once-read-many + replication → data is safe and consistent.
- Under-replicated blocks are automatically fixed by the NameNode.

## Commodity hardware
- Runs on cheap, standard machines — no special/costly hardware needed.
- Assumes failures are normal and handles them in software.

## Streaming data access
- Designed for reading whole files sequentially (batch), high sustained bandwidth over first-record latency.

## Quick recap table
| Feature | How HDFS gives it |
|---------|-------------------|
| Fault tolerance | Block replication + re-replication |
| High throughput | Parallel access across DataNodes |
| Rack awareness | Smart replica placement |
| Data locality | Computation runs near the block |
| Scalability | Add DataNodes horizontally |
| Low cost | Commodity hardware |
