# Kubernetes Architecture

**Definition:** **Kubernetes (k8s)** is an open-source **container orchestration** system — automates deployment, scaling and management of containerized apps across a cluster of machines.

A k8s cluster = **Master (control plane)** + **Worker nodes**. (imp — draw this)

```
        CONTROL PLANE (master)                    WORKER NODE
   +-----------------------------+          +----------------------+
   | api-server                  |          | kubelet              |
   | etcd                        | <------> | kube-proxy           |
   | scheduler                   |          | container runtime    |
   | controller-manager          |          |   -> Pods -> containers
   +-----------------------------+          +----------------------+
```

## Control Plane components (master) (imp)

### 1. kube-apiserver
- **Front-end** of the control plane. All communication goes through it.
- Exposes the k8s **REST API**. `kubectl` talks to this.
- Validates requests, updates etcd.

### 2. etcd
- Distributed **key-value store**.
- Stores **all cluster state / config data** (the single source of truth).
- If etcd is lost, cluster state is lost -> back it up.

### 3. kube-scheduler
- Decides **which node** a new Pod runs on.
- Considers resources, constraints, affinity, taints.

### 4. kube-controller-manager
- Runs **controllers** — background loops that keep actual state = desired state.
- e.g. node controller, replication controller, endpoints controller.
- (cloud-controller-manager handles cloud-provider specific bits.)

## Worker Node components (imp)

### 1. kubelet
- **Agent** running on each worker node.
- Talks to api-server, makes sure containers described in Pods are running and healthy.

### 2. kube-proxy
- Handles **networking** on the node.
- Maintains network rules, enables Service communication / load balancing to Pods.

### 3. Container runtime
- Software that actually **runs containers**.
- e.g. **Docker** (2020), containerd, CRI-O.

## Flow (2 marks)
1. User runs `kubectl apply -f deploy.yaml`.
2. Request hits **api-server**, state saved in **etcd**.
3. **scheduler** picks a node for the Pod.
4. **kubelet** on that node tells the **container runtime** to start the containers.
5. **controller-manager** keeps watching to maintain desired state; **kube-proxy** wires up networking.

## One-liners
- Control plane = brain (api-server, etcd, scheduler, controller-manager).
- Worker = muscle (kubelet, kube-proxy, container runtime), runs the actual Pods.
