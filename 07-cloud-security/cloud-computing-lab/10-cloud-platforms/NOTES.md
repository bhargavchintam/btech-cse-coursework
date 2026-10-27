# Cloud platforms

The big three are AWS (Amazon), GCP (Google) and Azure (Microsoft). They all sell the same idea -
rent compute, storage and networking by the hour instead of buying servers - so the services line up
almost one to one across them. Different names, same box. Once you know EC2 you basically know
Compute Engine, you just have to learn the new word for it.

Everything in this folder is example commands and config. The shell scripts are the aws/gcloud calls
you would actually run, but they need real credentials and an account, so they carry placeholders
(<your-key>, ami-xxxxxxxx, my-unique-bucket) and I never pointed them at a live account.

## Service map

| what it is        | AWS                | GCP                  | Azure                |
|-------------------|--------------------|----------------------|----------------------|
| VMs / compute     | EC2                | Compute Engine       | Virtual Machines     |
| object storage    | S3                 | Cloud Storage        | Blob Storage         |
| managed SQL       | RDS                | Cloud SQL            | Azure SQL Database   |
| serverless func   | Lambda             | Cloud Functions      | Azure Functions      |
| virtual network   | VPC                | VPC                  | VNet                 |
| managed k8s       | EKS                | GKE                  | AKS                  |
| IAM / accounts    | IAM                | Cloud IAM            | Entra ID (AD)        |
| CLI               | aws                | gcloud / gsutil      | az                   |

The one that trips people up is storage. S3 / Cloud Storage / Blob are object stores - you put and
get whole blobs by key, there is no filesystem, no partial writes. That is not the same as a disk you
attach to a VM (EBS on AWS, Persistent Disk on GCP). Object store = buckets and keys, block store =
a volume the VM mounts. Got that mixed up in the internal.

## Compute

An EC2 instance is a VM. You pick an AMI (the image - OS + preinstalled stuff), an instance type
(t2.micro, e2-micro... this is the size, cores + RAM), a key pair for SSH, and a security group for
the firewall. GCP is the same shape: an image family, a machine type, and firewall rules. The scripts
here launch one small instance each - t2.micro on AWS, e2-micro on GCP, both the free-tier size.

## Storage

Buckets need a globally unique name - not unique to your account, unique across all of AWS. So every
example uses something like my-unique-bucket-2020 and you would change it. Upload is just a copy:
`aws s3 cp file s3://bucket/`, `gsutil cp file gs://bucket/`. s3_backup.sh wraps `aws s3 sync` so a
whole directory goes up under a timestamped prefix - that is the closest thing to a real backup job
here.

## Regions and availability zones

A region is a geographic area - ap-south-1 is Mumbai, asia-south1 is also Mumbai on GCP. Inside a
region there are several availability zones (ap-south-1a, ap-south-1b...), each a separate datacenter
building with its own power and network. The point: a zone can fail on its own. If you want to survive
one datacenter going down you spread across zones; if you want to survive a whole region going down
(rare) you go multi-region, which is more expensive and slower because the data has to cross the
country. Latency and price both go up the further apart things are - same tradeoff as the replication
work in 09.

> Pick the region closest to your users for latency, and watch that data-transfer between regions is
> billed. Cross-region egress is where the surprise bills come from.  -- lab

## Infrastructure as Code

Clicking around the AWS console to make a VM is fine once. Doing it for thirty machines, or rebuilding
the same setup in a second region, is not - you will miss something. IaC is writing the
infrastructure down as code so it is repeatable and reviewable, and so tearing it all down is one
command.

- Terraform (HashiCorp) - provider-neutral, one tool for AWS, GCP, Azure. You describe the resources
  you want in HCL and it works out the create/update/delete calls. `terraform plan` shows the diff
  before `terraform apply` does it. This is what main.tf / variables.tf here are.
- CloudFormation - AWS only, YAML/JSON templates. Same idea, locked to Amazon.

Terraform is declarative: you write the end state, not the steps. Run apply twice and the second run
does nothing because the state already matches - that is the bit that felt strange coming from the
shell scripts, where running twice makes a second bucket. variables.tf keeps region/ami/type/bucket
out of main.tf so the same config works for another environment by just changing a default.

## CLI tools

Each provider ships a command-line tool that talks to its API: `aws`, `gcloud` (plus `gsutil` for
storage), `az`. First thing you do is authenticate - `aws configure` drops your access key and region
into a credentials file, `gcloud auth login` opens a browser. After that every console action has a
command equivalent, which is what makes the scripts in this folder possible. None of them run without
that auth step, which is the whole reason they stay as examples.

## The files

- aws_ec2_s3.sh   - configure region, security group, launch EC2, make a bucket, upload, list
- gcp_compute.sh  - gcloud: a Compute Engine VM, a bucket, upload an object, list instances
- s3_backup.sh    - sync a local dir to a bucket under a timestamped prefix ($1 dir, $2 bucket)
- main.tf         - Terraform: aws provider, security group, EC2 instance, S3 bucket
- variables.tf    - the region / instance_type / ami / bucket_name variables with defaults
