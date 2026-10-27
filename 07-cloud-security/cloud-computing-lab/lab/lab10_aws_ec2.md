# Lab 10 - Launch an AWS EC2 instance and SSH in

**Date:** 03-11-2020

## Aim

Launch a virtual server on AWS EC2 (from the console and again with the CLI), then connect to it
over SSH from the local machine.

## Tools

- AWS Free Tier account
- AWS CLI v2 configured with `aws configure` (region ap-south-1, Mumbai)
- A t2.micro instance running Amazon Linux 2

## Procedure

### Console

1. EC2 dashboard -> **Launch Instance**.
2. AMI: Amazon Linux 2. Instance type: t2.micro (free tier).
3. Key pair: create one named `lab-key`, download `lab-key.pem`.
4. Security group: allow SSH (port 22) from My IP only.
5. Launch, wait until Instance State is `running`, copy the Public IPv4 DNS.

### CLI (same thing, scripted)

Placeholders like `ami-xxxx` and `sg-xxxx` are the real IDs from your account.

1. Create the key pair and lock down the private key:

   ```
   aws ec2 create-key-pair --key-name lab-key \
       --query 'KeyMaterial' --output text > lab-key.pem
   chmod 400 lab-key.pem
   ```

2. Launch a t2.micro:

   ```
   aws ec2 run-instances \
       --image-id ami-0a23ccb2cdd9286bb \
       --instance-type t2.micro \
       --key-name lab-key \
       --security-group-ids sg-0abc1234 \
       --count 1
   ```

3. Wait for it and read back the public DNS:

   ```
   aws ec2 describe-instances \
       --filters "Name=instance-state-name,Values=running" \
       --query 'Reservations[].Instances[].[InstanceId,PublicDnsName]' \
       --output table
   ```

4. SSH in (user is `ec2-user` on Amazon Linux):

   ```
   ssh -i lab-key.pem ec2-user@ec2-13-232-11-45.ap-south-1.compute.amazonaws.com
   ```

5. On the instance, check what you got:

   ```
   uname -a
   cat /proc/cpuinfo | grep -c processor
   curl http://169.254.169.254/latest/meta-data/instance-type
   ```

6. When done, terminate so it stops billing:

   ```
   aws ec2 terminate-instances --instance-ids i-0abc123def456
   ```

## Output

```
$ aws ec2 run-instances ... 
{
    "Instances": [
        {
            "InstanceId": "i-0abc123def456",
            "InstanceType": "t2.micro",
            "State": { "Name": "pending" }
        }
    ]
}

$ ssh -i lab-key.pem ec2-user@ec2-13-232-11-45.ap-south-1.compute.amazonaws.com
       __|  __|_  )
       _|  (     /   Amazon Linux 2 AMI
      ___|\___|___|

[ec2-user@ip-172-31-8-14 ~]$ curl http://169.254.169.254/latest/meta-data/instance-type
t2.micro
```

## Result

An EC2 instance was launched two ways and reached over SSH. EC2 is IaaS - AWS hands you a bare
virtual machine and you own everything above it. The security group is the firewall (only my IP on
port 22), and the key pair is how you authenticate - AWS keeps the public key, you keep the .pem.
The instance was terminated afterwards so the free-tier hours are not wasted.
