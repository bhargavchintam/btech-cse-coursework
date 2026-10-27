#!/bin/bash
# launch a t2.micro ec2 instance with the cli

ami=ami-0c94855ba95c71c99
type=t2.micro
key=my-key
sg=sg-0123456789abcdef0
subnet=subnet-0123456789abcdef0
region=ap-south-1

echo "launching instance..."
aws ec2 run-instances \
  --image-id $ami \
  --instance-type $type \
  --key-name $key \
  --security-group-ids $sg \
  --subnet-id $subnet \
  --count 1 \
  --region $region \
  --tag-specifications 'ResourceType=instance,Tags=[{Key=Name,Value=web-server}]'

echo "done - check the console or run list_instances.sh"
