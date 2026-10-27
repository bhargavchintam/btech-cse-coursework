# YARN Job Execution Flow

Steps of how an application runs on YARN (imp - asked prev year).

## Steps
1. **Client submits** the application (job) to the **ResourceManager**.
2. RM's **ApplicationsManager** finds a NodeManager and launches a **container** to start the **ApplicationMaster**.
3. **ApplicationMaster** registers itself with the RM (so client can track status).
4. AM **requests resources** (containers) from the RM's **Scheduler** for its tasks.
5. RM grants containers; AM contacts the relevant **NodeManagers** to launch tasks in those containers.
6. **NodeManagers** start the containers and run the tasks (map / reduce).
7. Tasks report progress + status back to the **ApplicationMaster**.
8. On completion, AM **deregisters** from the RM and its containers are released.
9. Client gets the result / final status.

## Flow diagram (text)
```
Client --(1) submit job--> ResourceManager
ResourceManager --(2) start container--> NodeManager --> ApplicationMaster
ApplicationMaster --(3) register--> ResourceManager
ApplicationMaster --(4) ask for containers--> ResourceManager (Scheduler)
ApplicationMaster --(5) launch tasks--> NodeManagers (Containers)
Containers --(7) report progress--> ApplicationMaster
ApplicationMaster --(8) job done, deregister--> ResourceManager
```

## Points to remember
- The **first container** always runs the ApplicationMaster.
- AM (not RM) is responsible for **monitoring** and **restarting** failed tasks.
- RM only allocates resources; it stays out of per-task details.
- Heartbeats: NM -> RM, and tasks -> AM.
