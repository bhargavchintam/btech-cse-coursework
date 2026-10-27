# Lab 4 - Install Docker and run a container

## Aim
Install Docker engine on Ubuntu and run a container from a public image (hello-world and nginx).

## Tools / Environment
- Ubuntu 20.04
- Docker CE 19.03
- images: `hello-world`, `nginx:1.19`

## Procedure
1. Install docker from the convenience script (or apt repo):

```
sudo apt-get update
sudo apt-get install -y docker.io
```

2. Start and enable the docker service:

```
sudo systemctl start docker
sudo systemctl enable docker
```

3. Check version and info: `docker --version`, `docker info`.
4. Run the test container:

```
sudo docker run hello-world
```

5. Run nginx in detached mode with port mapping:

```
sudo docker run -d --name web -p 8080:80 nginx:1.19
```

6. List containers and check logs:

```
docker ps
docker logs web
```

7. Open `http://localhost:8080` - nginx page. Stop and remove:

```
docker stop web
docker rm web
```

## Observation / Output
- `docker run hello-world` prints "Hello from Docker!" confirming engine works.
- `docker ps` shows the `web` container up, port 0.0.0.0:8080->80/tcp.
- nginx default page loads on localhost:8080.

## Result
Docker installed and containers run successfully from public images.
