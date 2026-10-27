# Cloud service providers

CSP = company that owns and runs cloud infra and rents it out. Big three = **AWS, Azure, GCP**. (know at least these three + a couple of services each)

## 1. Amazon Web Services (AWS)
- Launched **2006**, market leader (largest share).
- Regions worldwide, split into Availability Zones.
- Key services:
  - **EC2** — virtual servers (IaaS compute)
  - **S3** — object storage
  - **EBS** — block storage for EC2
  - **RDS** — managed databases
  - **Lambda** — serverless / FaaS
  - **VPC** — virtual network
  - **IAM** — identity & access

## 2. Microsoft Azure
- Launched **2010**, second largest.
- Strong in enterprise (integrates with Windows Server, Active Directory, Office 365).
- Key services:
  - **Azure Virtual Machines** — compute
  - **Blob Storage** — object storage
  - **Azure Functions** — serverless
  - **AKS** — managed Kubernetes
  - **Azure AD** — identity

## 3. Google Cloud Platform (GCP)
- Google's public cloud. Strong in data / analytics / ML and containers (Kubernetes came from Google).
- Key services:
  - **Compute Engine** — VMs
  - **Cloud Storage** — object storage
  - **App Engine** — PaaS
  - **GKE** — managed Kubernetes
  - **Cloud Functions** — serverless
  - **BigQuery** — analytics

## Other providers (name if asked "others")
IBM Cloud, Oracle Cloud, Alibaba Cloud, DigitalOcean, Salesforce (SaaS/PaaS).

## Compare the big three

| | AWS | Azure | GCP |
|--|-----|-------|-----|
| Launched | 2006 | 2010 | 2011 |
| Compute | EC2 | Virtual Machines | Compute Engine |
| Object storage | S3 | Blob Storage | Cloud Storage |
| Serverless | Lambda | Azure Functions | Cloud Functions |
| Managed k8s | EKS | AKS | GKE |
| Strength | biggest, widest services | enterprise / MS stack | data & ML, containers |
