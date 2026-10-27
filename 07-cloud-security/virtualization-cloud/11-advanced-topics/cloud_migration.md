# Cloud Migration

**Definition:** **Cloud migration** is the process of moving an organization's data, applications, and IT workloads from **on-premises (or one cloud)** to a **cloud environment**. (imp)

## Why migrate (drivers)
- Cost savings (no data centre / hardware).
- Scalability + elasticity.
- Faster deployment, agility.
- Reliability / disaster recovery.
- Access from anywhere.
- Reduce maintenance burden.

## The 6 R's of migration (imp — commonly asked)
Strategies to migrate an application:

1. **Rehost** ("lift and shift") — move app as-is to cloud (e.g. onto EC2), no code change. Fastest, least optimized.
2. **Replatform** ("lift, tinker and shift") — small optimizations while moving (e.g. move DB to managed RDS), no major rewrite.
3. **Repurchase** — drop existing app, move to a different product, usually **SaaS** (e.g. move to Salesforce).
4. **Refactor / Re-architect** — redesign app to be cloud-native (e.g. break monolith into microservices, use serverless). Most effort, most benefit.
5. **Retire** — decommission apps no longer needed.
6. **Retain** — keep some apps **on-premises** (not ready / not worth moving) for now.

## Migration phases (2 marks)
1. **Assess / Plan** — inventory apps, dependencies, choose strategy, estimate cost.
2. **Migrate / Move** — actually transfer data + apps.
3. **Optimize / Validate** — test, tune performance, secure, monitor.

## Migration types (by scope)
- On-premises -> cloud.
- Cloud -> cloud (one provider to another).
- Cloud -> on-premises (reverse migration / repatriation).

## Challenges
- **Downtime** during migration.
- **Data security + compliance**.
- Large data transfer time / cost.
- **Vendor lock-in**.
- App compatibility / dependencies.
- Skill gap in team.

## Tools (2020, just mention)
- **AWS**: Migration Hub, Database Migration Service (DMS), Server Migration Service, Snowball (bulk data transfer).

Exam: define migration, list the **6 R's** with one line each, mention phases + challenges.
