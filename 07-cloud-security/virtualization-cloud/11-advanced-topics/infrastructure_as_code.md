# Infrastructure as Code (IaC)

**Definition:** **Infrastructure as Code (IaC)** is the practice of **managing and provisioning IT infrastructure (servers, networks, storage) through machine-readable code / config files**, instead of manual setup through a console or GUI. (imp)

You write the desired infra in code -> a tool reads it -> creates the infra automatically.

## Why IaC (problem with manual)
- Manual setup (clicking in console) is **slow, error-prone, not repeatable**.
- Hard to reproduce the same environment (dev vs prod drift).
- No version control, no history.

IaC fixes this — infra becomes **repeatable, versioned, automated**.

## Approaches (2 marks)

### 1. Declarative ("what")
- You describe the **desired end state**; tool figures out how to get there.
- e.g. **Terraform**, AWS CloudFormation.
- Preferred approach.

### 2. Imperative ("how")
- You write the **step-by-step commands** to reach the state.
- e.g. scripts, Ansible (mostly).

## Advantages (imp)
- **Consistency** — same config every time, no drift.
- **Repeatable** — recreate identical env easily.
- **Version control** — infra code in Git, track changes, rollback.
- **Speed / automation** — provision quickly, no manual clicks.
- **Documentation** — the code itself documents the infra.
- Fewer human errors.

## Key concepts
- **Idempotency** — running the same config repeatedly gives the same result (no duplicate resources).
- **State** — tool tracks current infra state (e.g. Terraform state file).

## Tools (2020) (imp)
- **Terraform** (HashiCorp) — declarative, multi-cloud, uses HCL. (`terraform init/plan/apply`)
- **AWS CloudFormation** — AWS-specific, JSON/YAML templates.
- **Ansible** — configuration management + provisioning (YAML playbooks).
- **Chef**, **Puppet** — configuration management.

## Provisioning vs Configuration management (short)
- **Provisioning** (create infra) — Terraform, CloudFormation.
- **Configuration management** (set up software on existing servers) — Ansible, Chef, Puppet.

## Small Terraform example (0.12/0.13 era)
```hcl
provider "aws" {
  region = "us-east-1"
}

resource "aws_instance" "web" {
  ami           = "ami-0abcdef1234567890"
  instance_type = "t2.micro"
}
```

Exam: define IaC, declarative vs imperative, name Terraform + CloudFormation, list advantages (consistency, versioning, automation).
