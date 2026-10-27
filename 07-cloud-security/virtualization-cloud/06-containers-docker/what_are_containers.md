# What are Containers

**Definition:** A **container** is a lightweight, standalone, executable package that bundles an application together with its dependencies (libraries, binaries, config) so it runs the same on any machine.

Key point: a container **shares the host OS kernel** — it does NOT carry its own guest OS. This is why it is much lighter than a VM. (imp)

## Why containers came up
- "Works on my machine" problem — app runs on dev laptop but fails on server due to different libs/versions.
- Container packages app + deps together, so env stays consistent from dev to test to prod.
- Faster to start (seconds), less memory, more of them fit on one host.

## Characteristics
- **Lightweight** — no guest OS, only app + libs.
- **Portable** — build once, run anywhere Docker/container runtime is present.
- **Isolated** — each container has its own filesystem, process space, network (using Linux namespaces).
- **Fast startup** — seconds, sometimes less. VM takes minutes to boot.
- **Ephemeral** — treated as disposable, spin up / throw away easily.

## How isolation is done (2 marks)
Containers use two Linux kernel features:
- **Namespaces** — give each container its own view of process IDs, network, mounts, users, etc. (isolation)
- **cgroups (control groups)** — limit and account resources (CPU, memory) per container.

## Image vs container (short)
- **Image** — the read-only template / blueprint (packaged app + deps).
- **Container** — a running instance of an image.

One image -> many containers.

## Common uses
- Microservices — each service in its own container.
- CI/CD pipelines — consistent build/test env.
- Packaging apps for cloud deployment.

w.r.t exams: define container, state that it shares host kernel, list characteristics, mention namespaces + cgroups.
