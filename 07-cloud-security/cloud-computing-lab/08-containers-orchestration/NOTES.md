# Containers and orchestration

A VM virtualises the hardware - you get a full guest OS with its own kernel, booted on top of a
hypervisor. A container virtualises the OS instead. Every container on a host shares that host's
kernel and is just a set of isolated processes (Linux namespaces for what it can see, cgroups for
how much it can use). So a container carries only the app and its libraries, not a whole OS. That's
why it's megabytes instead of gigabytes and starts in a fraction of a second - there's no boot.

|            | VM                        | Container                    |
|------------|---------------------------|------------------------------|
| isolates   | hardware (own kernel)     | the OS (shared kernel)       |
| size       | GBs, full guest OS        | MBs, app + libs              |
| start time | tens of seconds (boots)   | milliseconds (just a process)|
| runs on    | hypervisor                | container engine (Docker)    |

The trade: VMs give harder isolation (a separate kernel per guest), containers give density and
speed. Most cloud workloads run containers and only fall back to VMs when they need the stronger
boundary.

## Docker

Docker is the engine that builds and runs containers. The pieces:

- image - a read-only template: the filesystem plus the command to run. This is what you ship.
- layers - an image is built in layers, one per Dockerfile instruction, stacked and cached. If a
  layer hasn't changed Docker reuses the cached one, so rebuilds are fast. Two images off the same
  base share the base layers on disk instead of each keeping a copy.
- Dockerfile - the recipe. FROM a base, COPY the code in, set WORKDIR, EXPOSE a port, CMD the
  process to start. `docker build` reads it top to bottom and produces the image.
- registry - where images live (Docker Hub, ECR, GCR). `push` uploads, `pull` downloads. The k8s
  manifest just names an image and the node pulls it from there.
- container - a running instance of an image. `docker run` takes the image, adds a writable layer
  on top, and starts the CMD as an isolated process.

Run lifecycle: build -> (push/pull) -> run -> the CMD process is PID 1 in the container -> it
runs until it exits or you stop it -> a stopped container can be restarted or removed. The image
stays put; containers are the throwaway instances.

## docker-compose

One container is one process. A real app is a few of them - a web tier, a cache, a database - that
need to come up together and talk. Compose describes the whole set in one YAML file: each service
names its image (or a build), its ports, its env, and `depends_on` for start order. `docker compose
up` brings the lot up on a shared network where they reach each other by service name. My
compose here is the web app plus a redis, web depends_on redis. Good for one machine / dev; it does
not spread containers across a fleet - that's the orchestrator's job.

## Kubernetes

Once you have containers on many machines you need something to place them, keep them running, and
route traffic. That's orchestration, and Kubernetes is the standard one. You hand it the desired
state and it works to match it.

- pod - the smallest unit k8s schedules. One (sometimes a few tightly-coupled) containers sharing a
  network address. Pods are disposable - if one dies it isn't nursed back, a fresh one replaces it.
- replicaset - keeps N copies of a pod alive. If a pod dies it starts another to get back to N.
- deployment - what you actually write. Owns a replicaset and manages rollouts: change the image
  and it rolls pods over gradually, and can roll back. My k8s-deployment.yaml asks for 3 replicas.
- service - pods come and go with changing IPs, so a service is one stable name/IP in front of them
  and load-balances across the healthy pods. My k8s-service.yaml puts one in front of the web pods.

Two things k8s gives you for free once the state is declared:

- scaling - bump replicas from 3 to 10 (or let a HorizontalPodAutoscaler do it off CPU) and the
  scheduler places the new pods on nodes with room. The bin-packing side of that placement is what
  01_container_scheduler.py simulates - each pod needs some cpu/mem and has to land on a node that
  still has the capacity, same shape as the VM->host packing in 07-cloud-simulation.
- self-healing - the control loop constantly compares actual vs desired. Node dies, pod crashes,
  gets OOM-killed - the replicaset notices the count dropped and recreates. A readiness probe (I put
  one on /health) tells the service to hold traffic until a new pod is actually ready.

> Containers are how you package, orchestration is how you run them at scale. Docker builds and runs
> one; Kubernetes keeps a thousand of them in the state you asked for.  -- lab notes

Mixed these up in the internal: an image is the template, a container is the running instance, a pod
is what k8s wraps a container in. Three different layers, don't say "image" when you mean "pod".
