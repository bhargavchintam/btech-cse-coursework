# launch an ec2 instance using boto3
import boto3

region = 'ap-south-1'
ec2 = boto3.client('ec2', region_name=region)

response = ec2.run_instances(
    ImageId='ami-0c94855ba95c71c99',
    InstanceType='t2.micro',
    KeyName='my-key',
    MinCount=1,
    MaxCount=1,
    SecurityGroupIds=['sg-0123456789abcdef0'],
    TagSpecifications=[
        {
            'ResourceType': 'instance',
            'Tags': [{'Key': 'Name', 'Value': 'web-server'}]
        }
    ]
)

instance_id = response['Instances'][0]['InstanceId']
print('launched instance', instance_id)

# wait until its running
waiter = ec2.get_waiter('instance_running')
waiter.wait(InstanceIds=[instance_id])
print('instance is now running')
