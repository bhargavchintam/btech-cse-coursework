# Dockerfile Basics

**Definition:** A **Dockerfile** is a plain text file containing a set of **instructions** that Docker reads to automatically build an image. Each instruction adds a layer.

Build command: `docker build -t myapp:1.0 .`

## Common instructions (imp — explain each)

### FROM
- Sets the **base image**. Must be the first instruction.
- e.g. `FROM python:3.8-slim`, `FROM node:14`, `FROM nginx:1.19`.

### WORKDIR
- Sets the working directory inside the image for later instructions.
- e.g. `WORKDIR /app`.

### COPY
- Copies files/folders from host (build context) into the image.
- e.g. `COPY . /app` or `COPY requirements.txt .`
- (ADD is similar but also handles URLs / tar extraction — COPY preferred for plain copy.)

### RUN
- Executes a command at **build time**, result becomes a new layer.
- Used to install packages.
- e.g. `RUN pip install -r requirements.txt`, `RUN apt-get update`.

### EXPOSE
- Documents the **port** the container app listens on.
- e.g. `EXPOSE 80`, `EXPOSE 5000`.
- informational only — actual publishing done with `-p` at `docker run`.

### CMD
- The **default command** run when the container **starts** (run time, not build time).
- Only one CMD effective (last one wins).
- Exec form preferred: `CMD ["python", "app.py"]`.

(ENTRYPOINT is related — sets a fixed executable; CMD then gives default args.)

## Order of instructions
Typical order: FROM -> WORKDIR -> COPY -> RUN -> EXPOSE -> CMD.

## Sample Dockerfile (flask app)
```dockerfile
FROM python:3.8-slim
WORKDIR /app
COPY requirements.txt .
RUN pip install -r requirements.txt
COPY . .
EXPOSE 5000
CMD ["python", "app.py"]
```

## RUN vs CMD (asked prev year)
| RUN | CMD |
|-----|-----|
| Runs at **build** time | Runs at **container start** (run) time |
| Creates image layer | Does not create layer |
| Many RUN allowed | Only last CMD used |
| e.g. install packages | e.g. start the app |

Exam: list instructions, one line each, then write a small Dockerfile example.
