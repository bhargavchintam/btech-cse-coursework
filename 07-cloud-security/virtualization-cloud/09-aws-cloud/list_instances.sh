#!/bin/bash
# list ec2 instances with name, id, state and public ip

region=ap-south-1

aws ec2 describe-instances \
  --region $region \
  --query 'Reservations[].Instances[].{Name:Tags[?Key==`Name`]|[0].Value,ID:InstanceId,State:State.Name,IP:PublicIpAddress,Type:InstanceType}' \
  --output table

# only running ones
echo "running instances:"
aws ec2 describe-instances \
  --region $region \
  --filters "Name=instance-state-name,Values=running" \
  --query 'Reservations[].Instances[].InstanceId' \
  --output text
