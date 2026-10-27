# list all ec2 instances and their state using boto3
import boto3

ec2 = boto3.client('ec2', region_name='ap-south-1')

response = ec2.describe_instances()

for reservation in response['Reservations']:
    for inst in reservation['Instances']:
        name = ''
        for tag in inst.get('Tags', []):
            if tag['Key'] == 'Name':
                name = tag['Value']
        print(name,
              inst['InstanceId'],
              inst['InstanceType'],
              inst['State']['Name'],
              inst.get('PublicIpAddress', '-'))
