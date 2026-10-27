# AWS - Introduction

**Definition:** AWS (Amazon Web Services) is a public cloud platform by Amazon that provides on-demand compute, storage, networking and other services on a pay-as-you-go basis.

- Launched 2006. Largest cloud provider by market share.
- Follows the **utility computing** model - pay only for what you use, no upfront hardware.

## Why AWS (imp)
- No capital expenditure on servers - convert capex to opex.
- Elastic - scale up/down as demand changes.
- Global reach - deploy close to users, low latency.
- Managed services - AWS handles the undifferentiated heavy lifting (patching, HA).

## Global infrastructure
- **Region** - a physical geographic area (e.g. us-east-1 N.Virginia, ap-south-1 Mumbai). Each region isolated.
- **Availability Zone (AZ)** - one or more datacenters within a region, isolated power/network. A region has 2+ AZs. Spread workload across AZs for fault tolerance.
- **Edge location** - endpoints used by CloudFront (CDN) for caching content near users.

Region vs AZ vs Edge (2 marks):

| Term | Meaning |
|------|---------|
| Region | geographic area, has many AZs |
| AZ | isolated datacenter(s) in a region |
| Edge location | CDN cache point, more numerous than regions |

## Core service categories
- **Compute** - EC2, Lambda, Elastic Beanstalk, ECS.
- **Storage** - S3, EBS, EFS, Glacier.
- **Database** - RDS, DynamoDB, Redshift.
- **Networking** - VPC, Route 53, CloudFront, ELB.
- **Security & identity** - IAM, KMS, Security Groups.

## Ways to access AWS
- Management Console (web UI).
- AWS CLI - command line, e.g. `aws ec2 describe-instances`.
- SDKs - boto3 (python), aws-sdk (java/js) etc.

## Shared responsibility model (asked prev year)
- AWS is responsible for security **OF** the cloud (hardware, physical, hypervisor).
- Customer is responsible for security **IN** the cloud (data, IAM, OS patching, firewall rules).

## Pricing basics
- Pay as you go, no long term contract.
- **Free tier** - 750 hrs/month t2.micro EC2, 5 GB S3 for first 12 months.
- Reserved instances - cheaper for 1/3 yr commitment. Spot instances - spare capacity, big discount but can be reclaimed.
