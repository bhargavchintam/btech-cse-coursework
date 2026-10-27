# Lab 7 - Build and run a container with Docker

**Date:** 22-09-2020

## Aim

Write a Dockerfile for a small web app, build an image from it, run the image as a container and
map a port out to the host so the app is reachable from a browser.

## Tools

- Docker 19.03.12 on the Ubuntu VM from Lab 1
- A one-file Flask app

## Procedure

1. Make a project folder with the app and a Dockerfile:

   ```
   mkdir hello-docker && cd hello-docker
   ```

   `app.py`:

   ```python
   from flask import Flask
   app = Flask(__name__)

   @app.route("/")
   def home():
       return "hello from a container\n"

   if __name__ == "__main__":
       app.run(host="0.0.0.0", port=8080)
   ```

   `requirements.txt`:

   ```
   flask==1.1.2
   ```

   `Dockerfile`:

   ```
   FROM python:3.8-slim
   WORKDIR /app
   COPY requirements.txt .
   RUN pip install -r requirements.txt
   COPY app.py .
   EXPOSE 8080
   CMD ["python", "app.py"]
   ```

2. Build the image and tag it:

   ```
   docker build -t hello:1.0 .
   ```

3. Run it as a container, mapping host port 8080 to container port 8080, detached:

   ```
   docker run -d -p 8080:8080 --name web hello:1.0
   ```

4. Check it is running and hit it:

   ```
   docker ps
   curl http://localhost:8080/
   ```

5. Look at the logs, then stop and remove it:

   ```
   docker logs web
   docker stop web
   docker rm web
   ```

## Output

```
$ docker build -t hello:1.0 .
Successfully built 7c3a1f9e2b04
Successfully tagged hello:1.0

$ docker ps
CONTAINER ID   IMAGE       COMMAND            STATUS         PORTS                    NAMES
b91d2e4a77c1   hello:1.0   "python app.py"    Up 4 seconds   0.0.0.0:8080->8080/tcp   web

$ curl http://localhost:8080/
hello from a container
```

## Result

The Dockerfile was built into an image and run as a container. `-p 8080:8080` publishes the
container's port on the host, so the app answers on localhost even though it lives inside its own
isolated filesystem and process space. The image is portable - the same `hello:1.0` runs anywhere
Docker does, no "works on my machine" step.
