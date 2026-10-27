# Cloud computing - introduction

Cloud computing is renting computing over the internet instead of owning it. You don't buy servers,
rack them and run them - you use someone else's (AWS, Azure, GCP), pay for what you use, and give it
back when you're done. The NIST definition is the one they want in the exam: on-demand access to a
shared pool of configurable resources (compute, storage, network) that you can provision and release
with minimal effort.

## NIST 5 essential characteristics

These are the five things a service must have to actually be "cloud". Got asked to list them in the
internal and I forgot measured service, so writing them down properly.

- on-demand self-service - you spin up a server yourself from a console/API, no human on the other
  end approving it. Click, wait a minute, it's running.
- broad network access - reachable over the network from anything: laptop, phone, another server.
  Standard protocols, no special hardware.
- resource pooling - the provider's compute/storage is one big pool shared across many tenants
  (multi-tenancy). You don't know or care which physical machine you landed on.
- rapid elasticity - scale out and back in quickly, sometimes automatically. To the user it looks
  infinite - ask for 100 servers at 9am, drop to 5 at night.
- measured service - metered like electricity. The provider tracks vm-hours, GB stored, GB moved,
  and bills exactly that (see 02_cloud_cost_calculator.py).

## Service models - IaaS / PaaS / SaaS

How much of the stack you manage vs the provider. Lower = more control, more work.

| model | you manage                         | provider manages           | example              |
|-------|------------------------------------|----------------------------|----------------------|
| IaaS  | OS, runtime, app, data             | virtualization, servers    | EC2, Compute Engine  |
| PaaS  | app, data                          | OS, runtime, scaling       | Heroku, App Engine   |
| SaaS  | nothing, just use it               | everything                 | Gmail, Salesforce    |

IaaS hands you a bare VM - you install the OS packages, patch it, deploy your app. PaaS hands you a
place to push code and it runs - no OS to babysit. SaaS is finished software you log into. The pizza-
as-a-service analogy the lecturer used: IaaS you rent the kitchen, PaaS you get the oven and dough,
SaaS someone delivers the pizza. 01_service_model_classifier.py sorts a list of real services.

## Deployment models

Where the cloud lives and who can use it.

- public - owned by a provider, shared by anyone (AWS, Azure). Cheapest, most elastic, least control.
- private - one organisation's own cloud, on their hardware or dedicated. Most control and isolation,
  costs the most (you buy the gear). Banks, defence.
- hybrid - public + private glued together. Keep sensitive data private, burst everything else to
  public when you need scale. 03_deployment_model_advisor.py picks between these.
- community - shared by a few organisations with a common concern (several hospitals sharing a
  compliant cloud, universities sharing research compute). In between private and public.

## Pros and cons

Pros - no upfront hardware (capex becomes opex), pay-as-you-go, scales in minutes, provider handles
maintenance and uptime, reach users globally. Cons - ongoing cost can overtake buying if you run
flat-out 24/7 (the break-even point), you depend on the provider (vendor lock-in, outages take you
down too), data leaves your building so security and compliance need thought, and you need a network
connection to reach any of it.

## Cloud vs grid vs cluster

They all pool many machines, but the intent differs and this catches people out.

| feature   | cluster                | grid                        | cloud                     |
|-----------|------------------------|-----------------------------|---------------------------|
| coupling  | tight, same LAN/site   | loose, spread across sites  | virtualized, a datacenter |
| ownership | one org                | many orgs cooperating       | a provider, rented        |
| goal      | one job fast (HPC)     | share spare capacity        | on-demand elastic service |
| access    | job scheduler          | middleware                  | self-service API/console  |

- cluster - identical machines wired together on one site acting like one big computer. Runs one
  tightly-coupled workload (a simulation, a database).
- grid - many owners' machines across locations pooled for big batch jobs (SETI@home style).
  Heterogeneous, loosely coupled, best for embarrassingly-parallel work.
- cloud - virtualized, metered, self-service, elastic. You rent a slice and give it back.

> A cluster is one computer pretending to be many; a cloud is many computers pretending to be one,
> that you can rent by the hour.  -- lecture

The scheduling and load-balancing that make a datacenter work are in 05-scheduling and 06-load-
balancing; the virtualization underneath it all is 02-virtualization.
