# MapReduce Data Flow

End-to-end path of data through a job. Draw this diagram in the exam. (imp)

```
HDFS input
   |
   v
InputFormat -> InputSplits
   |
   v
RecordReader -> (k1,v1) records
   |
   v
   MAP  (k1,v1) -> list(k2,v2)      [runs on many nodes in parallel]
   |
   v
[Combiner]  (optional local mini-reduce)
   |
   v
Partitioner  (decides which reducer each key goes to)
   |
   v  ============ shuffle over network ============
   |
   v
Sort / Merge  -> (k2, list(v2))     [grouped + sorted by key]
   |
   v
  REDUCE  (k2, list(v2)) -> list(k3,v3)
   |
   v
OutputFormat -> RecordWriter
   |
   v
HDFS output  (part-r-00000, part-r-00001, ...)
```

## Step by step
1. **Input splits:** `InputFormat` computes splits from the input path. One split per map task. A split is logical (offsets), a block is physical.
2. **RecordReader:** converts a split into (key, value) records for `map()`.
3. **Map:** user code emits intermediate pairs to an in-memory **circular buffer** (default 100 MB, `mapreduce.task.io.sort.mb`). At 80% full it **spills** to local disk.
4. **Combine (optional):** runs on each spill to reduce the amount of data before it goes over the network.
5. **Partition:** each key -> a partition number (default `HashPartitioner`), one partition per reducer.
6. **Shuffle:** reduce tasks copy their partition from every map task via HTTP.
7. **Sort / merge:** copied spills are merge-sorted so keys arrive in order and grouped.
8. **Reduce:** user `reduce()` runs once per key.
9. **Output:** `OutputFormat` + `RecordWriter` write final pairs to HDFS.

## How many maps and reduces
- **Maps** = number of input splits (driven by data size, not user-set directly).
- **Reduces** = `job.setNumReduceTasks(n)`, default 1.

## Reducer count scenarios

| Reducers | Effect |
|----------|--------|
| 0        | map-only job, map output straight to HDFS, no shuffle/sort |
| 1        | all keys to one reducer, single sorted output file, no parallelism in reduce |
| n (>1)   | keys split across n reducers by partitioner, n output files, parallel |

## Data locality (imp)
Scheduler tries to place a map task where the block already lives:
- **data-local** (same node) — best
- **rack-local** (same rack) — next best
- **off-rack** — worst, costs network bandwidth

Reduce tasks have no locality — they always pull from all mappers.
