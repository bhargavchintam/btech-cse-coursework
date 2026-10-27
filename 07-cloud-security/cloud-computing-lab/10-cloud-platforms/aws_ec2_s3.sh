#!/bin/bash
set -e

REGION="ap-south-1"
AMI="ami-xxxxxxxx"          # region has to match the AMI
KEY="<your-key>"
BUCKET="my-unique-bucket-2020"

aws configure set region "$REGION"

SG_ID=$(aws ec2 create-security-group \
    --group-name web-sg \
    --description "http + ssh" \
    --query 'GroupId' --output text)

aws ec2 authorize-security-group-ingress \
    --group-id "$SG_ID" --protocol tcp --port 22 --cidr 0.0.0.0/0
aws ec2 authorize-security-group-ingress \
    --group-id "$SG_ID" --protocol tcp --port 80 --cidr 0.0.0.0/0

aws ec2 run-instances \
    --image-id "$AMI" \
    --instance-type t2.micro \
    --key-name "$KEY" \
    --security-group-ids "$SG_ID" \
    --count 1

aws s3api create-bucket \
    --bucket "$BUCKET" \
    --region "$REGION" \
    --create-bucket-configuration LocationConstraint="$REGION"

echo "hello s3" > index.html
aws s3 cp index.html "s3://$BUCKET/"

aws s3 ls
