# Deployments and ReplicaSets

Both are controllers that manage Pods. Deployment sits on top of ReplicaSet. (imp)

## ReplicaSet
**Definition:** A **ReplicaSet** ensures a specified number of **identical Pod replicas** are running at all times.
- If a Pod dies, ReplicaSet **creates a new one** (self-healing).
- If there are extra, it deletes them.
- Uses a **selector (matchLabels)** to know which Pods it owns.
- apiVersion: `apps/v1`.

Maintains **desired count** = actual count.

## Deployment
**Definition:** A **Deployment** is a higher-level controller that **manages ReplicaSets** and provides declarative updates, **rolling updates and rollbacks** to Pods.
- You normally create a **Deployment**, not a ReplicaSet directly.
- Deployment creates and manages a ReplicaSet, which in turn manages Pods.
- apiVersion: `apps/v1`.

Hierarchy:
```
Deployment  ->  ReplicaSet  ->  Pods  ->  containers
```

## What Deployment adds over ReplicaSet (2 marks)
- **Rolling update** — update Pods gradually (new version) with zero downtime.
- **Rollback** — revert to previous version if update fails (`kubectl rollout undo`).
- **Scaling** — easily change replica count.
- Version / revision history.

## Sample Deployment YAML (apps/v1) (imp)
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
`selector.matchLabels` must match `template.metadata.labels` (`app: nginx`). Common mistake if they don't match.

## Commands
```
kubectl apply -f deploy.yaml
kubectl get deployments
kubectl get rs                          # replicasets
kubectl scale deployment nginx-deploy --replicas=5
kubectl set image deployment/nginx-deploy nginx=nginx:1.19    # triggers rolling update
kubectl rollout status deployment/nginx-deploy
kubectl rollout undo deployment/nginx-deploy                  # rollback
```

## Difference table
| Point | ReplicaSet | Deployment |
|-------|-----------|------------|
| Job | Keep N Pods running | Manages ReplicaSets + updates |
| Rolling update | No | Yes |
| Rollback | No | Yes |
| Used directly | Rarely | Yes (recommended) |

Exam: Deployment manages ReplicaSet manages Pods; Deployment gives rolling update + rollback.
