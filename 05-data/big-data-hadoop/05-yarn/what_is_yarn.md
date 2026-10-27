# What is YARN

**Definition:** YARN (**Yet Another Resource Negotiator**) is the **resource management and job scheduling** layer of Hadoop, introduced in **Hadoop 2.x**.

- Sits between HDFS (storage) and the processing frameworks.
- Also called the **operating system of Hadoop**.

## Why YARN was needed (imp)
- In Hadoop 1.x, **JobTracker** did both resource management + job scheduling + monitoring -> bottleneck and single point of failure.
- Only **MapReduce** could run.
- YARN split these responsibilities and made the cluster **multi-tenant** - many frameworks can share the same cluster.

## What YARN does
- Manages **cluster resources** (CPU, memory).
- Schedules and monitors jobs.
- Allows **MapReduce, Spark, Tez, etc.** to run on the same cluster.

## Before vs after YARN
| | Hadoop 1.x | Hadoop 2.x (YARN) |
|--|-----------|-------------------|
| Resource mgmt | JobTracker | ResourceManager |
| Task mgmt | TaskTracker | NodeManager |
| Per-job mgmt | JobTracker | ApplicationMaster |
| Frameworks | MapReduce only | any (Spark, Tez, MR) |

## Key point
- YARN separates **resource management** from the **processing framework**.
- This makes Hadoop a general-purpose **data processing platform**, not just MapReduce.
