# Lab 9 - Deploy an app to Kubernetes (Minikube)

**Date:** 20-10-2020

## Aim

Deploy the container from Lab 7 onto a local Kubernetes cluster with Minikube: apply a Deployment,
expose it as a Service, watch the pods, then scale the replica count up and down.

## Tools

- Minikube 1.13.1, kubectl 1.19.2
- The `hello:1.0` image from Lab 7

## Procedure

1. Start a single-node cluster:

   ```
   minikube start --driver=docker
   kubectl get nodes
   ```

2. Build the image inside Minikube's Docker so the cluster can find it without a registry:

   ```
   eval $(minikube docker-env)
   docker build -t hello:1.0 .
   ```

3. `deployment.yaml` - 2 replicas of the app:

   ```yaml
   apiVersion: apps/v1
   kind: Deployment
   metadata:
     name: hello
   spec:
     replicas: 2
     selector:
       matchLabels:
         app: hello
     template:
       metadata:
         labels:
           app: hello
       spec:
         containers:
           - name: hello
             image: hello:1.0
             imagePullPolicy: Never
             ports:
               - containerPort: 8080
   ```

4. Apply it and watch the pods come up:

   ```
   kubectl apply -f deployment.yaml
   kubectl get pods
   ```

5. Expose the Deployment as a NodePort Service and open it:

   ```
   kubectl expose deployment hello --type=NodePort --port=8080
   kubectl get svc hello
   minikube service hello --url
   ```

6. Scale to 4 replicas, confirm, then scale back to 2:

   ```
   kubectl scale deployment hello --replicas=4
   kubectl get pods
   kubectl scale deployment hello --replicas=2
   ```

7. Clean up:

   ```
   kubectl delete service hello
   kubectl delete deployment hello
   minikube stop
   ```

## Output

```
$ kubectl get pods
NAME                     READY   STATUS    RESTARTS   AGE
hello-6c9f7d8b5c-4kx2n   1/1     Running   0          12s
hello-6c9f7d8b5c-r7ph9   1/1     Running   0          12s

$ kubectl scale deployment hello --replicas=4
deployment.apps/hello scaled

$ kubectl get pods
NAME                     READY   STATUS    RESTARTS   AGE
hello-6c9f7d8b5c-4kx2n   1/1     Running   0          40s
hello-6c9f7d8b5c-r7ph9   1/1     Running   0          40s
hello-6c9f7d8b5c-mq8vd   1/1     Running   0          6s
hello-6c9f7d8b5c-t2wln   1/1     Running   0          6s

$ minikube service hello --url
http://192.168.49.2:31480
```

## Result

kubectl applied the Deployment and Kubernetes kept the requested number of pods running. `kubectl
scale` changed the replica count and the extra pods appeared in seconds - this is the self-healing,
declarative model: you state how many you want and the controller makes reality match. The Service
gives the pods one stable address and load-balances across whichever replicas are up.
