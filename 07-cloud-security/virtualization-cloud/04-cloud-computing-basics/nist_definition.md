# NIST definition of cloud computing

Standard reference = **NIST SP 800-145** (authors Peter Mell & Tim Grance). Most textbook defns are lifted from here, so learn it as given. (imp)

**Definition:** Cloud computing is a model for enabling ubiquitous, convenient, on-demand network access to a shared pool of configurable computing resources (e.g. networks, servers, storage, applications, services) that can be rapidly provisioned and released with minimal management effort or service provider interaction.

Break the defn into keywords for a 5-mark answer:
- **on-demand** — user gets resources when needed, no waiting on humans
- **network access** — reached over the network (internet / intranet)
- **shared pool** — many users draw from the same physical infra
- **configurable** — networks, servers, storage etc. can be picked as required
- **rapidly provisioned and released** — scale up/down fast
- **minimal management effort** — self-service, provider not involved every time

## The NIST model has three parts

NIST says the cloud model is *composed of*:
1. **5 essential characteristics**
2. **3 service models** — IaaS, PaaS, SaaS
3. **4 deployment models** — private, community, public, hybrid

Remember the 5-3-4 split, examiners ask counts directly.

| Part | Count | Members |
|------|-------|---------|
| Essential characteristics | 5 | on-demand self-service, broad network access, resource pooling, rapid elasticity, measured service |
| Service models | 3 | IaaS, PaaS, SaaS |
| Deployment models | 4 | private, community, public, hybrid |

## Why a standard defn at all

Before NIST every vendor called their product "cloud". The defn gives one common yardstick so buyers can compare offerings and decide if something is genuinely cloud or just hosting. w.r.t exams — if any one of the 5 characteristics is missing, it is *not* full cloud.
