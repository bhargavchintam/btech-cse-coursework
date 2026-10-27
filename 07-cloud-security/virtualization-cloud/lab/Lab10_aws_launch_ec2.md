# Lab 10 - Launch an EC2 instance on AWS

## Aim
Launch an AWS EC2 instance (t2.micro, free tier) programmatically using the boto3 Python SDK.

## Tools / Environment
- AWS account (free tier), region us-east-1
- Python 3.8, boto3
- AWS CLI configured with access keys
- script: `Lab10_launch_ec2.py`

## Procedure
1. Install boto3 and configure credentials:

```
pip install boto3
aws configure
```

(enter Access Key, Secret Key, region us-east-1, output json)

2. Make sure a key pair `mykey` exists (EC2 -> Key Pairs) and note an Amazon Linux 2 AMI id for the region.
3. The script uses `ec2.run_instances` with the AMI, instance type t2.micro, key name and a Name tag:

```python
import boto3
ec2 = boto3.client("ec2", region_name="us-east-1")
resp = ec2.run_instances(
    ImageId="ami-0c94855ba95c71c99",
    InstanceType="t2.micro",
    KeyName="mykey",
    MinCount=1,
    MaxCount=1,
    TagSpecifications=[{"ResourceType": "instance",
                        "Tags": [{"Key": "Name", "Value": "cloudlab-ec2"}]}],
)
print("launched", resp["Instances"][0]["InstanceId"])
```

4. Run it: `python3 Lab10_launch_ec2.py`.
5. Verify in console (EC2 -> Instances) or CLI:

```
aws ec2 describe-instances --filters "Name=tag:Name,Values=cloudlab-ec2"
```

6. Terminate afterwards to avoid charges:

```
aws ec2 terminate-instances --instance-ids <id>
```

## Observation / Output
- Script prints `launched i-0abc123...` with the new instance id.
- In EC2 console the instance shows state `pending` then `running`, type t2.micro, tag Name=cloudlab-ec2.
- describe-instances returns the instance details (public IP once running).

## Result
EC2 instance launched successfully on AWS using boto3.
