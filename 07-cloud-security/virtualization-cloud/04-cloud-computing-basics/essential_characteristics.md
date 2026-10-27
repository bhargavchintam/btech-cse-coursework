# Five essential characteristics

Per NIST. All five must be present for something to count as cloud. (asked prev year — "List and explain the five essential characteristics", 10 marks)

## 1. On-demand self-service
Consumer provisions compute, storage etc. **automatically, as needed, without any human interaction** with the provider. e.g. spin up a VM from a web console at 2am, no ticket, no phone call.

## 2. Broad network access
Capabilities available over the network and accessed through **standard mechanisms** — so any client works: laptop, mobile, tablet, thin client. Nothing tied to one special device.

## 3. Resource pooling
Provider's resources pooled to serve **multiple consumers** using a **multi-tenant** model. Physical/virtual resources assigned and reassigned per demand.
- Consumer generally has **no control / knowledge** of exact location of resources (location independence).
- May specify at higher level — country, region, datacenter.
- Pooled: storage, processing, memory, network bandwidth.

## 4. Rapid elasticity
Capabilities **provisioned and released elastically**, sometimes automatically, to scale rapidly with demand. To the consumer the resources often *appear unlimited* and can be bought in any quantity anytime.
- scale out (add) during peak, scale in (remove) after — e.g. sale day traffic.

## 5. Measured service
Cloud systems **automatically control and optimise** resource use by metering (pay-per-use, metering at some level of abstraction — storage, bandwidth, active accounts).
- Usage monitored, controlled, reported → transparency for both provider and consumer.
- This is what enables the **pay-as-you-go** billing.

## Quick recall
On-demand self-service, Broad network access, Resource pooling, Rapid elasticity, Measured service.
Mnemonic i use: **O-B-R-R-M**.

| Characteristic | One-line meaning |
|----------------|------------------|
| On-demand self-service | user provisions himself, no human at provider end |
| Broad network access | reachable over network from any standard device |
| Resource pooling | multi-tenant, shared pool, location independent |
| Rapid elasticity | scale up/down fast, looks unlimited |
| Measured service | metered usage → pay per use |
