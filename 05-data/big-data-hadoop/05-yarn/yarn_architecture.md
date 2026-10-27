# YARN Architecture

YARN follows a **master-slave** architecture with 4 main parts (imp - explain with diagram).

## Components
- **ResourceManager (RM)** - master, one per cluster.
- **NodeManager (NM)** - slave, one per node.
- **ApplicationMaster (AM)** - one per application/job.
- **Container** - a bundle of resources (CPU + memory) on a node where a task runs.

## Diagram (text)
```
                        +---------------------------+
   Master               |     ResourceManager       |
                        |  (Scheduler + AppsManager)|
                        +-------------+-------------+
                                      |
        ------------------------------+------------------------------
        |                             |                             |
  +-----+------+              +-------+------+              +--------+-----+
  | NodeManager|              | NodeManager  |              | NodeManager  |
  |            |              |              |              |              |
  | +--------+ |              | +----------+ |              | +----------+ |
  | |AppMaster||              | |Container | |              | |Container | |
  | +--------+ |              | +----------+ |              | +----------+ |
  | |Container||              | |Container | |              |              |
  | +--------+ |              | +----------+ |              |              |
  +------------+              +--------------+              +--------------+
```

## ResourceManager - two parts
- **Scheduler** - allocates resources to applications (does NOT monitor or restart tasks). Uses FIFO / Capacity / Fair scheduler.
- **ApplicationsManager (ApplicationManager)** - accepts job submissions, launches the first container for the **ApplicationMaster**, restarts AM on failure.

## NodeManager
- Runs on every slave node.
- Launches and monitors **containers**.
- Reports node health + resource usage (heartbeat) to RM.

## ApplicationMaster
- **One per application**, runs inside a container.
- Negotiates resources (containers) from the RM.
- Works with NodeManagers to run and monitor the application's tasks.

## Container
- Logical bundle of resources (e.g. 2 GB RAM + 1 vCPU) on a single node.
- The actual place where a map/reduce task runs.

## Note
- RM = global master; NM = per-node slave; AM = per-job manager; Container = where work runs.
