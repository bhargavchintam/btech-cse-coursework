# Docker Volumes

**Problem:** Container filesystem is **ephemeral** — when a container is deleted, data written inside it is lost. Volumes solve this by **persisting data** outside the container's writable layer. (imp)

## Why volumes
- Persist data beyond container life (databases, uploads, logs).
- Share data between containers.
- Share data between host and container.

## Types of data storage in Docker

### 1. Bind mount
- Mounts a **specific file/folder from the host** into the container.
- You give the exact host path.
- e.g. `-v /home/user/data:/app/data`.
- Data lives at the host path you chose; managed by **you**, not Docker.
- Good for: dev (mount source code so changes reflect live), config files.
- Downside: depends on host directory structure -> less portable.

### 2. Named volume (Docker-managed)
- Created and managed by **Docker**, stored under Docker's area (`/var/lib/docker/volumes/`).
- Referenced by a **name**, not a host path.
- e.g. `-v mydata:/app/data` (mydata is a named volume).
- Good for: production, databases — Docker handles location.
- More portable, easier to back up.

### 3. tmpfs (just mention)
- Stored in **host memory** only, not on disk. Gone when container stops. Used for temporary/sensitive data.

## Bind mount vs Named volume (asked prev year)

| Point | Bind mount | Named volume |
|-------|-----------|--------------|
| Location | Any host path you specify | Docker-managed area |
| Managed by | User | Docker |
| Portability | Less (tied to host path) | More |
| Syntax | `-v /host/path:/container/path` | `-v volname:/container/path` |
| Best for | Development, live code | Production, DB data |

## Commands (2 marks)
```
docker volume create mydata          # create named volume
docker volume ls                     # list volumes
docker volume inspect mydata         # details
docker volume rm mydata              # remove

# use named volume
docker run -d -v mydata:/var/lib/mysql mysql:5.7

# use bind mount
docker run -d -v /home/user/site:/usr/share/nginx/html nginx:1.19
```

## Key line for exam
Bind mount = you point to a host path (you manage). Named volume = Docker creates and manages storage, you just give it a name. Both keep data alive after the container is gone.
