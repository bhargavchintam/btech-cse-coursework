#!/bin/bash
# create a security group and open ssh + http

vpc=vpc-0123456789abcdef0
region=ap-south-1

# create the group, capture the returned id
sg_id=$(aws ec2 create-security-group \
  --group-name web-sg \
  --description "allow ssh and http" \
  --vpc-id $vpc \
  --region $region \
  --query 'GroupId' \
  --output text)

echo "created security group $sg_id"

# allow ssh (22) from my ip only
aws ec2 authorize-security-group-ingress \
  --group-id $sg_id \
  --protocol tcp --port 22 --cidr 203.0.113.10/32 \
  --region $region

# allow http (80) from anywhere
aws ec2 authorize-security-group-ingress \
  --group-id $sg_id \
  --protocol tcp --port 80 --cidr 0.0.0.0/0 \
  --region $region

echo "rules added"
