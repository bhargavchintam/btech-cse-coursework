# Docker Networking

Docker gives containers a way to talk to each other and to the outside world. Uses **network drivers**. Three main / default ones asked: **bridge, host, none**. (imp)

## Why networking
- Containers are isolated by default (own network namespace).
- Need networking so containers can communicate + be reached from outside.

## Default network drivers

### 1. bridge (default)
- **Default** driver. Used when you don't specify a network.
- Docker creates a private internal network `docker0` on the host.
- Each container gets its own internal IP on that bridge.
- Containers on same bridge can talk to each other; outside access needs **port mapping** (`-p 8080:80`).
- User-defined bridge networks also allow containers to reach each other **by name** (built-in DNS).
- Best for: single-host, multiple containers.

### 2. host
- Container **shares the host's network stack** directly (no isolation of network).
- No separate IP, no port mapping needed — container port = host port.
- Faster (no NAT overhead) but less isolated, port conflicts possible.
- Best for: performance, when isolation not needed.

### 3. none
- Container has **no network** access (only loopback `lo`).
- Fully isolated networking.
- Best for: security, batch jobs that need no network.

## Comparison table (2 marks)

| Driver | IP | Port mapping needed | Isolation | Use |
|--------|----|--------------------|-----------|-----|
| bridge | own internal IP | yes (`-p`) | medium | default, multi-container single host |
| host | uses host IP | no | low | performance |
| none | none | n/a | high | no network needed |

## Other drivers (just mention)
- **overlay** — connects containers across **multiple hosts** (Docker Swarm / multi-host).
- **macvlan** — assigns a MAC address, container appears as physical device on network.

## Useful commands
```
docker network ls                       # list networks
docker network create mynet             # create user-defined bridge
docker run -d --network mynet nginx     # attach container to it
docker network inspect bridge           # details
```

Port mapping example:
```
docker run -d -p 8080:80 nginx:1.19
```
Here host port 8080 -> container port 80.

Exam: name the 3 default drivers, one line each, plus port mapping concept.
