#!/bin/bash
# common docker commands i keep forgetting

docker images
docker ps
docker ps -a

docker pull nginx:1.19

# run nginx detached, host 8080 -> container 80
docker run -d --name web -p 8080:80 nginx:1.19

docker build -t myapp:latest .
docker exec -it web bash
docker logs web

docker stop web
docker rm web
docker rmi nginx:1.19
