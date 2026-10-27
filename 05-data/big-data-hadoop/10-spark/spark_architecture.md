# Spark Architecture

**Definition:** Spark follows a **master-slave** architecture. One **driver** (master) coordinates many **executors** (workers/slaves) through a **cluster manager**. (imp)

## Main components
1. **Driver program**
   - Runs the `main()` and creates the **SparkContext** (entry point).
   - Builds the **DAG** of the job, splits into stages and tasks.
   - Schedules tasks on executors, collects results.
   - One driver per application.

2. **Cluster Manager**
   - Allocates resources (CPU, memory) across the cluster.
   - Types: **Standalone**, **YARN**, **Mesos**, (later Kubernetes).
   - Driver asks cluster manager for executors.

3. **Executor**
   - JVM process on a **worker node**. Launched for one application, lives for its lifetime.
   - Runs the **tasks**, keeps RDD partitions / cached data in memory.
   - Reports status back to driver.

4. **Worker node** — slave machine that hosts executors.

## Key terms
- **SparkContext** (`sc`) — connection to the cluster, tells Spark how/where to run. `SparkSession` wraps it from 2.0.
- **Job** — full computation triggered by an **action**.
- **Stage** — set of tasks separated by a **shuffle** boundary.
- **Task** — unit of work sent to one executor, works on one **partition**.
- **DAG** — Directed Acyclic Graph of RDD dependencies; **DAG Scheduler** turns it into stages.

## Execution flow (asked prev year)
1. User submits app (`spark-submit`).
2. Driver starts, creates SparkContext.
3. SparkContext requests executors from cluster manager.
4. Driver builds DAG from transformations, DAG scheduler splits into stages/tasks.
5. Tasks sent to executors, run in parallel on partitions.
6. Results returned to driver (action).

```
            +----------------+
            | Driver (sc)    |
            +--------+-------+
                     |
            +--------v--------+
            | Cluster Manager |   (YARN / Standalone / Mesos)
            +--------+--------+
          +----------+----------+
          |                     |
   +------v-----+        +------v-----+
   | Executor   |        | Executor   |
   | (worker 1) |        | (worker 2) |
   +------------+        +------------+
```

## Deploy modes
- **Client mode** — driver runs on the submitting machine.
- **Cluster mode** — driver runs inside the cluster (on a worker), managed by cluster manager.
