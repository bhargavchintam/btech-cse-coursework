# MapReduce and Hadoop

Big data is the case where the data is too big or comes in too fast for one machine to store and
process on its own. The old answer was buy a bigger machine (scale up); it runs out - there's only
so big a single box you can build, and it's expensive. The cloud answer is scale out: throw a pile
of ordinary machines at it and split the work. Hadoop is the framework that made that practical for
batch jobs - it does the splitting, the moving of data, and the recovery when a machine dies, so you
only write the map and reduce logic.

Two halves to Hadoop: HDFS stores the data across the machines, MapReduce (later YARN) runs the
computation next to where the data sits. "Move the computation to the data, not the data to the
computation" - shipping code is cheap, shipping terabytes over the network is not.

## The MapReduce paradigm

Three stages. You write two of them, the framework does the middle one.

- **map** - runs on each input split independently. Takes a record, emits zero or more (key, value)
  pairs. In word count: for each word emit (word, 1). Fully parallel, no map talks to another map.
- **shuffle / sort** - the framework's job. It collects every pair from every mapper, groups them by
  key, and sorts the keys. After this, all the values for one key are together on one reducer. This
  is the expensive step (it's where the network traffic happens) and it's the part you don't code.
- **reduce** - runs on each key group. Takes (key, list-of-values), emits the answer for that key.
  In word count: sum the list of 1s. Reducers are parallel across keys too.

The shape is always the same: `(k1,v1) -> map -> (k2,v2)* -> shuffle -> (k2, [v2]) -> reduce -> (k3,v3)*`.
This is the same key-group-then-aggregate pattern from the Data Mining repo (frequent itemsets, the
grouping there was by candidate). Once you see it as group-by it stops being mysterious.

## Word count walked through

Input, three lines:

```
the cluster runs the job
the job reads data from the cluster
map and reduce process the data
```

map emits a (word, 1) for every word - 18 pairs total. shuffle groups them by word:

```
the -> [1,1,1,1,1]   cluster -> [1,1]   job -> [1,1]   data -> [1,1]
runs -> [1]  reads -> [1]  from -> [1]  map -> [1]  and -> [1]  reduce -> [1]  process -> [1]
```

reduce sums each list: `the 5, cluster 2, job 2, data 2`, everything else 1. That's `01_wordcount_mapreduce.py`.
Sum of all counts = 18 = number of words in, so nothing got lost. Hello-world of big data, but the
whole point is those three lines would run unchanged over a petabyte on a thousand machines.

## HDFS - the storage layer

HDFS is a distributed filesystem tuned for big files and streaming reads, not for lots of tiny files
or random writes. Two kinds of daemon:

- **namenode** - the master. Holds the metadata: the directory tree, and for every file which blocks
  make it up and which datanodes hold them. It does NOT hold the file data itself. One namenode is a
  single point of failure, which is why real clusters run a standby - the internal asked this and I
  only wrote "backup namenode", should've said standby + edit log.
- **datanode** - the workers. Store the actual blocks and report in to the namenode with a heartbeat.

A file is split into **blocks** (default 128 MB, big on purpose so the seek cost is tiny next to the
read). Each block is replicated - **replication factor** default 3 - onto different datanodes, and
Hadoop tries to put copies on different racks. So a machine (or a whole rack) can die and every block
still has a live copy; the namenode notices the missing heartbeat and re-replicates from a surviving
copy. Big blocks + replication is also what makes data-local map tasks possible: the scheduler puts a
map task on a node that already has the block.

| thing | who | holds |
|-------|-----|-------|
| namenode | master | metadata: tree + block->datanode map |
| datanode | worker | the actual data blocks + heartbeats |
| block | 128 MB piece of a file | replicated x3 across datanodes |

## YARN - the resource layer

In Hadoop 1 the MapReduce engine also did the cluster scheduling and it didn't scale. Hadoop 2 split
that out into **YARN** (Yet Another Resource Negotiator), so the cluster can run more than just
MapReduce (Spark, Tez...) on the same machines.

- **ResourceManager** - global, hands out cluster resources (containers = a slice of ram + cpu).
- **NodeManager** - per machine, launches and watches containers on its node.
- **ApplicationMaster** - one per job, asks the RM for containers and drives that job's tasks.

So MapReduce on YARN: the AM asks for containers, runs map tasks (data-local where it can), then
reduce tasks, and reports done. Storage (HDFS) and compute (YARN) are separate concerns - that split
is the whole architecture in one line.

> Hadoop's real trick isn't map and reduce, it's that it hides failure. Machines die mid-job and the
> job still finishes, because the data has 3 copies and a dead task just re-runs somewhere else. -- lab

The Python and Java files here are the *pattern*, run on one machine with no Hadoop installed - the
distribution, the shuffle-over-network, and the fault tolerance are exactly what a real cluster adds.
