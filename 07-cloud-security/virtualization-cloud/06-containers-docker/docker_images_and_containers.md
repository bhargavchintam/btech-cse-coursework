# Docker Images and Containers

Two most basic Docker objects. Often asked to differentiate. (imp)

## Docker Image
**Definition:** An **image** is a read-only template / blueprint that contains the app, its dependencies, libraries and config needed to run.
- Built from a **Dockerfile**.
- Made of **layers** — each Dockerfile instruction (FROM, RUN, COPY...) adds a layer.
- Layers are cached and reused -> faster builds, saves space.
- Immutable (read-only).
- Identified by name + tag, e.g. `nginx:1.19`, `python:3.8-slim`.

## Docker Container
**Definition:** A **container** is a running (or stopped) **instance of an image**.
- When image is run, Docker adds a thin **writable layer** on top of the read-only image layers.
- Has its own filesystem, process, network (isolated).
- Ephemeral — can be started, stopped, deleted.

Relation: **one image -> many containers**.

## Image vs Container table

| Point | Image | Container |
|-------|-------|-----------|
| Nature | Read-only template | Running instance of image |
| State | Static / immutable | Live, has writable layer |
| Made from | Dockerfile | An image |
| Analogy | Class (OOP) | Object |
| Count | One image | Many containers from it |

## Common commands (2 marks)

Images:
```
docker build -t myapp:1.0 .    # build image from Dockerfile
docker images                  # list images
docker pull nginx:1.19         # download from registry
docker rmi myapp:1.0           # remove image
```

Containers:
```
docker run -d -p 8080:80 nginx:1.19   # run container (detached)
docker ps                             # list running containers
docker ps -a                          # list all (incl stopped)
docker stop <id>                      # stop
docker rm <id>                        # remove
docker logs <id>                      # view logs
docker exec -it <id> bash             # get shell inside container
```

## Image layers (short)
- Base layer (e.g. `python:3.8`), then each instruction stacks a layer.
- Only writable layer is the container's top layer. When container deleted, that layer is lost (unless volume used).

Analogy line for exam: image is like a **class**, container is like an **object** created from it.
