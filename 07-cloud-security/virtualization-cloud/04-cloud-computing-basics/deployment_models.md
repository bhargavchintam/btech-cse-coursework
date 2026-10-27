# Deployment models

Four of them per NIST. Deployment model = *who owns / who can use* the cloud (as opposed to service model which is *what layer* is delivered). (imp)

## 1. Public cloud
Infra provisioned for **open use by general public**. Owned, managed, operated by the provider, exists **on the provider's premises**.
- multi-tenant, pay-as-you-go.
- e.g. AWS, Microsoft Azure, Google Cloud.
- pros: no capex, elastic, cheap to start. cons: less control, shared, data-location concerns.

## 2. Private cloud
Provisioned for **exclusive use by a single organisation** (may have many business units).
- owned/managed by the org, a third party, or both. On-prem or off-prem.
- pros: more control, security, compliance. cons: capex high, org handles maintenance.
- e.g. a bank running its own OpenStack / VMware cloud internally.

## 3. Community cloud
Provisioned for exclusive use by a **specific community of consumers** from organisations that have **shared concerns** (mission, security requirements, policy, compliance).
- costs shared among the members, so cheaper than private for that group.
- e.g. several govt departments, or a group of hospitals sharing a cloud.

## 4. Hybrid cloud
**Composition of two or more** distinct clouds (private, community or public) that remain unique entities but are **bound together** by standardised / proprietary technology enabling data and application portability.
- typical use: keep sensitive data on private, burst to public for extra capacity ("**cloud bursting**").
- best of both — control + elasticity.

## Differentiate (comparison table)

| Basis | Public | Private | Community | Hybrid |
|-------|--------|---------|-----------|--------|
| Used by | general public | single org | a specific community | mix |
| Owned by | provider | org / third party | community / third party | combination |
| Cost | lowest, pay-per-use | high (capex) | shared among members | medium |
| Security control | least | most | medium | tunable |
| Example | AWS, Azure, GCP | internal VMware/OpenStack | govt / hospital group | private + public bursting |

Don't confuse the 4 deployment models with the 3 service models — common mix-up in the exam.
