# Services

**Problem:** Pods are **ephemeral** and their **IPs change** when recreated. So we can't rely on Pod IP directly. A **Service** gives a **stable endpoint (fixed IP + DNS name)** to reach a set of Pods. (imp)

**Definition:** A **Service** is an abstraction that defines a logical set of Pods (selected by **labels**) and a policy to access them, with a stable IP and built-in **load balancing** across those Pods.

## How it selects Pods
- Uses **selector (labels)** — e.g. `selector: app: nginx`.
- Traffic to the Service is load-balanced across all matching Pods.
- kube-proxy sets up the routing rules.

## Service types (imp — commonly asked)

### 1. ClusterIP (default)
- Exposes the Service on an **internal cluster IP only**.
- Reachable **only inside the cluster**.
- Used for internal communication between services (e.g. frontend -> backend).

### 2. NodePort
- Exposes the Service on a **static port on every node's IP**.
- Accessible from **outside** the cluster via `<NodeIP>:<NodePort>`.
- Port range: **30000–32767**.
- Builds on top of ClusterIP.

### 3. LoadBalancer
- Exposes the Service **externally** using a **cloud provider's load balancer** (AWS ELB, GCP LB, etc.).
- Gets an external IP. Best for production external access.
- Builds on top of NodePort + ClusterIP.

### (also) ExternalName
- Maps Service to an external DNS name (CNAME). Just mention.

## Comparison table (2 marks)

| Type | Access | Use |
|------|--------|-----|
| ClusterIP | Internal only (default) | Service-to-service inside cluster |
| NodePort | External via NodeIP:port (30000–32767) | Dev / testing external access |
| LoadBalancer | External via cloud LB | Production external access |

Layering: ClusterIP < NodePort < LoadBalancer (each builds on the previous).

## Sample Service YAML (v1)
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
    - port: 80          # service port
      targetPort: 80    # container port
      nodePort: 30080   # external port on node (NodePort only)
```

## Commands
```
kubectl apply -f service.yaml
kubectl get svc
kubectl describe svc nginx-svc
```

Exam: define Service (stable endpoint + load balancing for Pods), list the 3 types with access scope.
