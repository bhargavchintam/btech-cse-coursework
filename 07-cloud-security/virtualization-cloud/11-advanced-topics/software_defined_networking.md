# Software Defined Networking (SDN)

**Definition:** **SDN** is a networking approach that **separates the control plane (decides where traffic goes) from the data plane (actually forwards the traffic)**, and manages the network centrally through **software (a controller)**. (imp)

Core idea: decouple control from forwarding, control network via software programmatically.

## Traditional network problem
- In traditional networks, each device (router/switch) has **both** control + data plane built-in.
- Config done device-by-device -> hard to manage, not flexible, vendor-locked.

## The two planes (imp)
- **Control plane** — the "brain". Decides **how** packets should be routed (routing decisions, logic). In SDN this is moved to a **central SDN controller**.
- **Data plane** (forwarding plane) — the "muscle". Actually **forwards packets** based on rules from the control plane. Stays on the switches.

SDN **separates** these two.

## SDN Architecture — 3 layers (2 marks)
```
   Application Layer   (network apps, business logic)
          |  Northbound API (e.g. REST)
   Control Layer       (SDN Controller - the brain)
          |  Southbound API (e.g. OpenFlow)
   Infrastructure Layer (switches/routers - data plane)
```

1. **Application layer** — network applications (firewall, load balancer, monitoring).
2. **Control layer** — the **SDN controller**, central brain, has global view of network.
3. **Infrastructure / Data layer** — physical/virtual switches & routers that forward traffic.

- **Northbound API** — between application layer and controller (e.g. REST API).
- **Southbound API** — between controller and switches. **OpenFlow** is the main protocol (imp).

## Advantages
- **Centralized management** — control whole network from one controller.
- **Programmable / flexible** — configure via software, automate.
- Vendor-independent (open standards like OpenFlow).
- Faster changes, easier to scale.
- Better use in cloud / data centres.

## Disadvantages
- Central controller = **single point of failure** (needs redundancy).
- Security of controller is critical.
- Complexity in large deployments.

## Key terms recap
- Control plane = decisions (brain). Data plane = forwarding (muscle).
- **SDN controller** = centralized brain.
- **OpenFlow** = southbound protocol.

Exam: SDN separates control plane from data plane; draw the 3-layer diagram; name OpenFlow.
