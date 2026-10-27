# Lab 5 - Build a Docker image from a Dockerfile

## Aim
Write a Dockerfile for a small Flask app and build a custom Docker image, then run a container from it.

## Tools / Environment
- Docker CE 19.03
- base image `python:3.8-slim`
- app: simple Flask app (`app.py`, `requirements.txt`)
- Dockerfile (see `Lab05_Dockerfile`)

## Procedure
1. Project files - `app.py`:

```python
from flask import Flask
app = Flask(__name__)

@app.route("/")
def home():
    return "hello from flask in docker"

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
```

`requirements.txt`:

```
flask==1.1.2
```

2. Dockerfile:

```dockerfile
FROM python:3.8-slim
WORKDIR /app
COPY requirements.txt .
RUN pip install -r requirements.txt
COPY . .
EXPOSE 5000
CMD ["python", "app.py"]
```

3. Build the image (tag it):

```
docker build -t myflaskapp:1.0 .
```

4. List images: `docker images`.
5. Run a container from the image:

```
docker run -d --name flask -p 5000:5000 myflaskapp:1.0
```

6. Test: `curl http://localhost:5000`.

## Observation / Output
- Build output shows each step (FROM, WORKDIR, COPY, RUN pip install, EXPOSE, CMD) and ends with "Successfully tagged myflaskapp:1.0".
- `docker images` lists `myflaskapp   1.0`.
- curl returns `hello from flask in docker`.

## Result
Custom Docker image built from Dockerfile and container run successfully.
