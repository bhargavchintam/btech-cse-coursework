# Docker Architecture

**Definition:** Docker is an open-source **platform to build, ship and run applications inside containers**. It follows a **client-server architecture**.

## Main components (imp)

### 1. Docker Client
- The CLI (`docker`) the user interacts with.
- User types commands like `docker run`, `docker build`, `docker pull`.
- Client sends these to the Docker daemon (via REST API / sockets).
- Client and daemon can be on same machine or different hosts.

### 2. Docker Daemon (dockerd)
- The **server / background process**. Does the actual work.
- Listens for requests from the client.
- Manages images, containers, networks, volumes.
- Builds images, runs containers.

### 3. Docker Images
- Read-only **template** used to create containers.
- Built from a **Dockerfile**.
- Made of layers (each instruction = a layer).

### 4. Docker Containers
- Running (or stopped) **instance of an image**.
- Isolated, has its own filesystem/network.

### 5. Docker Registry
- Storage + distribution of images.
- **Docker Hub** is the default public registry.
- Can have private registries too.
- `docker pull` downloads from registry, `docker push` uploads to it.

## How it works (flow) (2 marks)
1. User runs `docker run nginx` on the **client**.
2. Client passes command to the **daemon**.
3. Daemon checks if `nginx` image is local. If not, **pulls** it from the **registry** (Docker Hub).
4. Daemon creates a **container** from that image and runs it.

```
docker CLI  --->  Docker daemon (dockerd)  --->  Registry (Docker Hub)
 (client)          builds/runs                    stores images
                       |
                  Images -> Containers
```

## Key terms recap
- **Client** — sends commands.
- **Daemon** — does the work.
- **Image** — template.
- **Container** — running instance.
- **Registry** — stores/distributes images (Docker Hub default).

Exam tip: draw the client -> daemon -> registry diagram, then explain each of the 5 components.
