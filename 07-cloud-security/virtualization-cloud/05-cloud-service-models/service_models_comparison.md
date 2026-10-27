# Service models — comparison

Three service models per NIST: **IaaS, PaaS, SaaS**. Difference is *how much the provider manages* vs *how much you manage*. (asked prev year — "Differentiate IaaS, PaaS and SaaS with examples", 10 marks)

## Who manages what

Legend: **P** = provider manages, **C** = consumer (you) manages.

| Layer | On-premises | IaaS | PaaS | SaaS |
|-------|-------------|------|------|------|
| Applications | C | C | C | **P** |
| Data | C | C | C | **P** |
| Runtime | C | C | **P** | **P** |
| Middleware | C | C | **P** | **P** |
| OS | C | C | **P** | **P** |
| Virtualization | C | **P** | **P** | **P** |
| Servers | C | **P** | **P** | **P** |
| Storage | C | **P** | **P** | **P** |
| Networking | C | **P** | **P** | **P** |

Reading it: as you go IaaS → PaaS → SaaS the provider takes over more layers, you manage less.

## Quick comparison

| Basis | IaaS | PaaS | SaaS |
|-------|------|------|------|
| You get | raw infra (VM, storage, network) | platform to run code | ready-to-use software |
| You manage | OS + above | app + data | just settings/data |
| User | sysadmin / infra team | developers | end users |
| Control | most | medium | least |
| Examples | EC2, Azure VM, Compute Engine | Elastic Beanstalk, App Engine, Heroku | Gmail, Office 365, Salesforce |
| Analogy | empty flat | furnished flat | hotel room |

## One-line each
- **IaaS** — rent infrastructure, build everything above OS yourself.
- **PaaS** — rent a platform, just deploy your code.
- **SaaS** — rent finished software, just use it.

## Pizza-as-a-service (the classic memory aid)
- On-prem = make pizza at home (you buy everything).
- IaaS = take-and-bake (kitchen/oven given).
- PaaS = pizza delivery (they cook, you provide table/drinks).
- SaaS = dine at restaurant (everything done for you).
