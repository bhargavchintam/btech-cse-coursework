# Lab 7 - Docker volumes and networking

## Aim
Demonstrate data persistence using Docker volumes and container-to-container communication using a user-defined bridge network.

## Tools / Environment
- Docker CE 19.03
- images: `mysql:5.7`, `alpine:3.12`, `nginx:1.19`

## Procedure
1. Create a named volume and inspect it:

```
docker volume create mydata
docker volume ls
docker volume inspect mydata
```

2. Run a container that mounts the volume, write a file, remove container, then re-mount to prove persistence:

```
docker run -it --name c1 -v mydata:/data alpine:3.12 sh -c "echo persisted > /data/note.txt"
docker rm c1
docker run --rm -v mydata:/data alpine:3.12 cat /data/note.txt
```

3. Bind mount a host directory (host path -> container path):

```
docker run -d --name web -v /home/student/site:/usr/share/nginx/html -p 8080:80 nginx:1.19
```

4. Create a user-defined bridge network:

```
docker network create mynet
docker network ls
```

5. Run two containers on it and test name resolution (containers reach each other by name on a user network):

```
docker run -d --name db --network mynet mysql:5.7
docker run -it --name app --network mynet alpine:3.12 sh
# inside app container:
ping -c 2 db
```

## Observation / Output
- After removing c1 and starting a new container on the same volume, `note.txt` still shows `persisted` - data survived.
- Files placed in the host `site` folder appear on the nginx page (bind mount).
- On `mynet`, `ping db` from the app container resolves the name and gets replies (default bridge does NOT give name resolution, user-defined does).

## Result
Volumes persist data beyond container lifetime and containers on a user-defined network communicate by name.
