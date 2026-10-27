# Lab 8 - Deploy a Pod on Kubernetes

## Aim
Set up a single-node Kubernetes cluster with Minikube and deploy an nginx Pod using a YAML manifest.

## Tools / Environment
- Minikube 1.9 with VirtualBox / docker driver
- kubectl 1.18
- pod manifest (see `Lab08_pod.yaml`), image `nginx:1.19`

## Procedure
1. Start the cluster:

```
minikube start --driver=virtualbox
kubectl get nodes
```

2. Pod manifest (`Lab08_pod.yaml`):

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

3. Apply it:

```
kubectl apply -f Lab08_pod.yaml
```

4. Check pod status and details:

```
kubectl get pods
kubectl describe pod nginx-pod
```

5. Port-forward to test the pod:

```
kubectl port-forward pod/nginx-pod 8080:80
```

6. Open `http://localhost:8080`. Delete pod when done: `kubectl delete -f Lab08_pod.yaml`.

## Observation / Output
- `kubectl get nodes` shows one node `Ready`.
- `kubectl get pods` shows `nginx-pod` going ContainerCreating -> Running, 1/1.
- describe shows events: pulled nginx:1.19, created and started container.
- nginx page loads via the port-forward.

## Result
Kubernetes cluster started and an nginx Pod deployed and accessed successfully.
