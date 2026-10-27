# Lab 8 - Multi-container app with Docker Compose

**Date:** 06-10-2020

## Aim

Run a two-container app - a Flask web service and a Redis store - with a single `docker-compose up`,
so the containers come up together on one network and can talk by service name.

## Tools

- Docker 19.03.12, docker-compose 1.26.2
- Flask web container + Redis container

## Procedure

1. Project layout:

   ```
   compose-demo/
     app.py
     requirements.txt
     Dockerfile
     docker-compose.yml
   ```

2. `app.py` - a hit counter that keeps its count in Redis:

   ```python
   from flask import Flask
   import redis

   app = Flask(__name__)
   r = redis.Redis(host="redis", port=6379)   # "redis" is the compose service name

   @app.route("/")
   def hits():
       n = r.incr("hits")
       return f"visit number {n}\n"

   if __name__ == "__main__":
       app.run(host="0.0.0.0", port=8080)
   ```

   `requirements.txt`:

   ```
   flask==1.1.2
   redis==3.5.3
   ```

   `Dockerfile` - same as Lab 7 (python:3.8-slim, install reqs, run app.py).

3. `docker-compose.yml`:

   ```yaml
   version: "3.8"

   services:
     web:
       build: .
       ports:
         - "8080:8080"
       depends_on:
         - redis
     redis:
       image: redis:6-alpine
   ```

4. Bring the whole thing up (build web, pull redis, start both):

   ```
   docker-compose up -d
   docker-compose ps
   ```

5. Hit the web service a few times - the counter should climb because Redis is holding it:

   ```
   curl http://localhost:8080/
   curl http://localhost:8080/
   curl http://localhost:8080/
   ```

6. Tear it down:

   ```
   docker-compose down
   ```

## Output

```
$ docker-compose up -d
Creating network "compose-demo_default" with the default driver
Creating compose-demo_redis_1 ... done
Creating compose-demo_web_1   ... done

$ docker-compose ps
        Name                    Command        State    Ports
------------------------------------------------------------------------
compose-demo_redis_1  docker-entrypoint.sh ...  Up      6379/tcp
compose-demo_web_1    python app.py             Up      0.0.0.0:8080->8080/tcp

$ curl http://localhost:8080/
visit number 1
$ curl http://localhost:8080/
visit number 2
$ curl http://localhost:8080/
visit number 3
```

## Result

Compose read the YAML and started both containers on a shared network. The web container reaches
Redis just by the hostname `redis` - Compose wires up DNS between services, so there is no IP to
hard-code. The count survives across requests because it lives in the Redis container, not in the
web process. `depends_on` makes sure redis starts before web.
