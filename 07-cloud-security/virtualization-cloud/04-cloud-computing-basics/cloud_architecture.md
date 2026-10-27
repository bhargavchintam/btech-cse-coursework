# Cloud architecture

Cloud architecture = the components + subcomponents needed for cloud computing, and how they connect. Split broadly into **front end** and **back end**, joined by a **network** (usually the internet).

## Front end
The **client side**, what the user sees and works with.
- client device + application/interface used to reach the cloud.
- e.g. web browser, thin client, mobile app.
- job: send request to back end, display results.

## Back end
The **cloud (provider) side** — does the actual work. Contains:
- **Huge resource pool** — servers, storage, VMs.
- **Application** — the software/service the user asked for.
- **Service** — IaaS / PaaS / SaaS delivered.
- **Runtime cloud** — provides execution env (via virtualization / hypervisor).
- **Storage** — where data lives.
- **Management** — coordinates apps, resources, does provisioning, monitoring, load balancing.
- **Security** — encryption, access control, firewalls, virtual firewalls.

## The middle — network
Front end and back end talk over a network, mostly the **internet**. Sometimes intranet for private cloud.

## Text diagram

```
[ Front end ]                       [ Back end ]
 client device  ---- internet ----   management + security
 browser / app                       runtime cloud (hypervisor)
                                      servers | storage | services
```

## Supporting pieces (worth a mention)
- **Hypervisor** — runs the VMs on back end hardware.
- **Middleware** — lets networked machines talk to each other.
- **Load balancer** — spreads incoming requests across servers.

Points to write: front end = user side, back end = provider side, connected by network; back end holds the pool, mgmt and security. (2 marks if asked as "define front end / back end")
