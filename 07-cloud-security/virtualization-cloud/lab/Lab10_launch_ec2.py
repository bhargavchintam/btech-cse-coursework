# launch a t2.micro ec2 instance
import boto3

region = "us-east-1"
ec2 = boto3.client("ec2", region_name=region)


def launch():
    resp = ec2.run_instances(
        ImageId="ami-0c94855ba95c71c99",
        InstanceType="t2.micro",
        KeyName="mykey",
        MinCount=1,
        MaxCount=1,
        TagSpecifications=[
            {
                "ResourceType": "instance",
                "Tags": [{"Key": "Name", "Value": "cloudlab-ec2"}],
            }
        ],
    )
    iid = resp["Instances"][0]["InstanceId"]
    print("launched", iid)
    return iid


if __name__ == "__main__":
    launch()
