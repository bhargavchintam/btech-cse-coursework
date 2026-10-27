# Pods

**Definition:** A **Pod** is the **smallest deployable unit** in Kubernetes. It wraps **one or more containers** that share storage, network and are scheduled together on the same node. (imp)

Key: you don't deploy a container directly in k8s — you deploy a **Pod** that holds the container.

## Characteristics
- Usually **one container per Pod** (most common). Multiple containers only when tightly coupled (sidecar pattern).
- Containers in a Pod **share**:
  - the same **network namespace** (same IP, can talk via `localhost`).
  - **storage volumes**.
- Pods are **ephemeral** — they can die; not self-healing on their own. Controllers (Deployment/ReplicaSet) recreate them.
- Each Pod gets its **own cluster IP** (but it changes when Pod is recreated -> that's why Services exist).

## Multi-container pattern (short)
- **Sidecar** — helper container alongside main (e.g. logging agent).
- Both share volume + network.

## Pod lifecycle phases (2 marks)
- **Pending** — accepted but containers not yet running (e.g. still scheduling / pulling image).
- **Running** — Pod bound to node, containers running.
- **Succeeded** — all containers exited successfully (0).
- **Failed** — at least one container failed.
- **Unknown** — state can't be determined.

## Sample Pod YAML (apiVersion v1)
```yaml
apiVersion: v1
kind: Pod
metadata:
  name: nginx-pod
  labels:
    app: nginx
spec:
  containers:
    - name: nginx
      image: nginx:1.19
      ports:
        - containerPort: 80
```

## Commands
```
kubectl apply -f pod.yaml
kubectl get pods
kubectl describe pod nginx-pod
kubectl logs nginx-pod
kubectl delete pod nginx-pod
```

## Important note
We rarely create bare Pods in real use — we use a **Deployment** which manages Pods for us (self-healing, scaling). Bare Pod is not recreated if it dies.

Exam: define Pod = smallest unit, one/more containers, shared network + storage, ephemeral.
