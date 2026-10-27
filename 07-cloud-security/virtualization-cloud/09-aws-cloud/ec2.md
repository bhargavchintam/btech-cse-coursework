# EC2 - Elastic Compute Cloud

**Definition:** EC2 is a web service that provides resizable virtual servers (called **instances**) in the AWS cloud. IaaS offering.

- You rent virtual machines by the second/hour.
- Full control - choose OS, install software, root/admin access.

## Key concepts
- **AMI (Amazon Machine Image)** - template with OS + software used to launch an instance. e.g. Amazon Linux 2, Ubuntu 20.04.
- **Instance type** - the hardware sizing (vCPU + RAM). e.g. `t2.micro` (1 vCPU, 1 GB), `m5.large`.
- **Key pair** - public/private key for SSH login. AWS keeps public key, you download the .pem private key.
- **Security group** - virtual firewall, controls inbound/outbound traffic at instance level. Stateful.
- **User data** - bootstrap script run at first boot (install packages etc.).

## Instance families (imp)
| Family | Use |
|--------|-----|
| t (t2/t3) | general purpose, burstable, cheap |
| m | general purpose, balanced |
| c | compute optimized |
| r | memory optimized |
| g/p | GPU |

## Instance lifecycle
- **pending -> running -> stopping -> stopped -> terminated**
- Stop = shut down, EBS root volume kept, no compute charge (still pay for storage).
- Terminate = delete instance, root volume deleted by default.

## Storage for EC2
- **EBS (Elastic Block Store)** - network attached block volume, persists independent of instance. Like a virtual hard disk.
- **Instance store** - physically attached, ephemeral, data lost on stop/terminate.

## Pricing models (2 marks)
- **On-demand** - pay per hour/second, no commitment.
- **Reserved** - 1 or 3 yr commit, up to ~70% cheaper.
- **Spot** - bid on spare capacity, cheapest, can be interrupted.
- **Dedicated host** - physical server dedicated to you.

## Connecting to a linux instance
```
chmod 400 mykey.pem
ssh -i mykey.pem ec2-user@<public-ip>
```

## Elastic IP
- Static public IPv4 address you can attach to an instance. Normal public IP changes on stop/start; Elastic IP stays fixed.
