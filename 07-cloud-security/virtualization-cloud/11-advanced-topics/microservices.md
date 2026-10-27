# Microservices

**Definition:** **Microservices** is an architectural style where an application is built as a collection of **small, independent services**, each doing one business function, communicating over the network (usually REST APIs / messaging). (imp)

Opposite of **monolithic** architecture (whole app as one single unit).

## Monolithic vs Microservices (asked prev year)

| Point | Monolithic | Microservices |
|-------|-----------|---------------|
| Structure | Single large unit | Many small services |
| Deployment | Deploy whole app | Deploy each service independently |
| Scaling | Scale entire app | Scale only needed service |
| Tech stack | One stack for all | Each service can use different stack |
| Failure | One bug can crash whole app | Failure isolated to one service |
| Codebase | One big codebase | Small separate codebases |
| Dev speed | Slows as app grows | Teams work in parallel |

## Characteristics
- Each service is **independently deployable** and **loosely coupled**.
- Organized around **business capability** (e.g. user-service, order-service, payment-service).
- Each can have its **own database** (decentralized data).
- Communicate via **REST / HTTP** or **message queues** (async).
- Often deployed in **containers** (Docker) + orchestrated by **Kubernetes**.

## Advantages
- Independent deployment + scaling.
- Fault isolation — one service down doesn't take whole app down.
- Technology flexibility (polyglot).
- Easier for large teams to work in parallel.
- Faster releases.

## Disadvantages (2 marks)
- **Complexity** — many services to manage.
- **Network overhead / latency** — services talk over network.
- **Distributed system problems** — harder debugging, testing, monitoring.
- Data consistency across services is hard (no single DB).
- Needs DevOps maturity (CI/CD, monitoring).

## Supporting concepts (short)
- **API Gateway** — single entry point, routes to right service.
- **Service discovery** — services find each other.
- **Load balancing**, **containers + orchestration** (Docker + k8s).

## Relation to cloud / containers
Microservices go hand-in-hand with **containers and Kubernetes** — each microservice in its own container, scaled independently.

Exam: define microservices, contrast with monolith (table), list pros/cons.
