#!/bin/bash
# common kubectl commands used in the k8s lab

# create the namespace first
kubectl create -f namespace.yaml

# apply the config and secret
kubectl apply -f configmap.yaml
kubectl apply -f secret.yaml

# run the pod and the deployment
kubectl apply -f pod.yaml
kubectl apply -f deployment.yaml
kubectl apply -f replicaset.yaml

# expose it
kubectl apply -f service_clusterip.yaml
kubectl apply -f service_nodeport.yaml

# check whats running
kubectl get pods
kubectl get pods -o wide
kubectl get deployments
kubectl get rs
kubectl get svc
kubectl get all

# details of a pod / deployment
kubectl describe pod nginx-pod
kubectl describe deployment nginx-deployment
kubectl describe svc nginx-nodeport

# scale the deployment up to 5
kubectl scale deployment nginx-deployment --replicas=5

# logs and exec
kubectl logs nginx-pod
kubectl exec -it nginx-pod -- /bin/bash

# clean up
kubectl delete -f service_nodeport.yaml
kubectl delete -f service_clusterip.yaml
kubectl delete deployment nginx-deployment
kubectl delete rs nginx-rs
kubectl delete pod nginx-pod
kubectl delete -f namespace.yaml
