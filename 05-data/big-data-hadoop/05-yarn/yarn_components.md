# YARN Components

The main components of YARN and their roles (imp - 2 marks / 5 marks).

## 1. ResourceManager (RM) - master
- One per cluster, the ultimate authority on resources.
- **Scheduler** - allocates resources to applications based on a scheduling policy (FIFO/Capacity/Fair). Pure scheduler - no monitoring or restart.
- **ApplicationsManager** - accepts jobs, launches the ApplicationMaster's first container, restarts AM if it fails.

## 2. NodeManager (NM) - slave
- One per slave node.
- Launches / manages **containers** on its node.
- Monitors CPU + memory usage.
- Sends heartbeat + node health to RM.

## 3. ApplicationMaster (AM)
- One per application (job).
- Requests resources (containers) from RM.
- Coordinates task execution with NodeManagers.
- Monitors task progress, handles task failures.

## 4. Container
- Resource unit = CPU + memory on one node.
- Tasks (map/reduce) run inside containers.
- Allocated by RM, launched by NM.

## Summary table
| Component | Scope | Role |
|-----------|-------|------|
| ResourceManager | cluster (1) | global resource allocation + scheduling |
| NodeManager | per node | manage containers on the node |
| ApplicationMaster | per job | negotiate resources, run/monitor tasks |
| Container | per task | resources where a task executes |

## Point
- RM has 2 sub-parts: **Scheduler** + **ApplicationsManager**.
- Scheduler only allocates; it does not restart failed tasks (that is the AM's job).
