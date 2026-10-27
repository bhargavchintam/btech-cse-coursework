# IaaS — Infrastructure as a Service

**Definition (NIST):** capability provided to the consumer is to **provision processing, storage, networks and other fundamental computing resources**, where the consumer can deploy and run arbitrary software including OS and applications.
- consumer does **not** manage/control the underlying cloud infra
- consumer **does** control OS, storage, deployed apps, and some networking (e.g. host firewalls)

Lowest layer of the three — you get raw infra, build the rest yourself. (imp)

## What provider gives you
- virtual machines (compute)
- storage (block / object)
- network — virtual networks, load balancers, IP
- sometimes: physical machines, firewalls

## What you (consumer) manage
- OS (patching, config)
- middleware, runtime
- your applications & data

Rule of thumb: **provider = up to virtualization; you = OS and above.**

## Examples (2020)
- **AWS EC2**
- **Microsoft Azure Virtual Machines**
- **Google Compute Engine**
- DigitalOcean droplets
- Rackspace

## Pros / cons

| Pros | Cons |
|------|------|
| full control over OS + stack | you patch and secure the OS |
| flexible, pay-per-use | more admin effort than PaaS/SaaS |
| good for custom / legacy apps | need sysadmin skills |
| easy to scale | you handle scaling logic |

## When to use
- migrating existing servers to cloud (lift-and-shift)
- need specific OS / custom software
- want maximum control

Analogy i use: IaaS = renting an empty flat — walls and plumbing given, you bring furniture (OS, apps).
