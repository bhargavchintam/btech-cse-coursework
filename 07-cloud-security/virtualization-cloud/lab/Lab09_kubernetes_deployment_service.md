# Lab 9 - Kubernetes Deployment and Service

## Aim
Create a Deployment (3 replicas of nginx) and expose it using a NodePort Service so it is reachable from outside the cluster.

## Tools / Environment
- Minikube 1.9, kubectl 1.18
- manifests: `Lab09_deployment.yaml` (apps/v1), `Lab09_service.yaml` (v1)
- image `nginx:1.19`

## Procedure
1. Deployment manifest (`Lab09_deployment.yaml`), note `selector.matchLabels` matches pod template labels:

```yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: nginx-deploy
  labels:
    app: nginx
spec:
  replicas: 3
  selector:
    matchLabels:
      app: nginx
  template:
    metadata:
      labels:
        app: nginx
    spec:
      containers:
        - name: nginx
          image: nginx:1.19
          ports:
            - containerPort: 80
```

2. Service manifest (`Lab09_service.yaml`), NodePort selects pods by the same label:

```yaml
apiVersion: v1
kind: Service
metadata:
  name: nginx-svc
spec:
  type: NodePort
  selector:
    app: nginx
  ports:
    - port: 80
      targetPort: 80
      nodePort: 30080
```

3. Apply both:

```
kubectl apply -f Lab09_deployment.yaml
kubectl apply -f Lab09_service.yaml
```

4. Check the objects:

```
kubectl get deploy
kubectl get pods
kubectl get svc
```

5. Get the URL from minikube and open it:

```
minikube service nginx-svc --url
```

6. Scale the deployment to test self-healing / scaling:

```
kubectl scale deployment nginx-deploy --replicas=5
```

## Observation / Output
- `kubectl get deploy` shows `nginx-deploy   3/3` ready.
- `kubectl get pods` lists 3 pods (then 5 after scaling), all Running.
- `kubectl get svc` shows `nginx-svc` NodePort with 80:30080/TCP.
- Deleting a pod, the deployment recreates it automatically (controller keeps desired count).
- nginx page loads on the minikube service URL.

## Result
Deployment with 3 replicas created, exposed via NodePort Service, scaling and self-healing verified.
