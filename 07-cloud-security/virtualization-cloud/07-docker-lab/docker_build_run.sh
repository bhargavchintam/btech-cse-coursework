#!/bin/bash
# build the flask image and run the container
set -e

img="flask-hello"
name="flask-demo"

docker build -t "$img" ./flask-app

# remove old container if it exists
docker rm -f "$name" 2>/dev/null

docker run -d --name "$name" -p 5000:5000 "$img"

echo "flask running on http://localhost:5000"
docker ps
