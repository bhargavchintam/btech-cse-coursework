# YARN Schedulers

The RM **Scheduler** decides how resources are shared among applications. Three types (imp).

## 1. FIFO Scheduler
- **First In First Out** - jobs run in the order they are submitted.
- Simple, single queue.
- **Drawback:** a big job blocks small jobs (no sharing). Not good for shared clusters.

## 2. Capacity Scheduler
- Cluster divided into **multiple queues**, each with a guaranteed **capacity** (% of resources).
- Different teams/orgs get their own queue.
- A queue can **borrow** unused capacity from other queues (elasticity).
- **Default scheduler** in most Hadoop distributions.

## 3. Fair Scheduler
- Resources shared **fairly / equally** among all running jobs over time.
- A small job gets resources quickly, does not wait for a big job to finish.
- On average every job gets an **equal share**.
- Developed by Facebook.

## Comparison
| Scheduler | Idea | Good for |
|-----------|------|----------|
| FIFO | order of submission | simple / test clusters |
| Capacity | fixed queues with guaranteed capacity | multi-team shared cluster |
| Fair | equal share among jobs | mixed small + big jobs |

## Points
- FIFO = simplest but big job blocks others.
- **Capacity** = default; queue-based with guaranteed minimum.
- **Fair** = every job gets an equal average share.
