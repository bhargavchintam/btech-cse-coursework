#!/bin/bash
# basic s3 bucket operations - make, upload, list, remove

bucket=s3://reva-vcc-demo-bucket
region=ap-south-1

# make bucket
aws s3 mb $bucket --region $region

# create a test file and upload it
echo "hello from s3 lab" > sample.txt
aws s3 cp sample.txt $bucket/sample.txt

# upload a whole folder
aws s3 cp ./data $bucket/data --recursive

# list bucket contents
aws s3 ls $bucket
aws s3 ls $bucket --recursive --human-readable

# download it back
aws s3 cp $bucket/sample.txt ./downloaded.txt

# remove one object
aws s3 rm $bucket/sample.txt

# remove the whole bucket (must be empty, --force empties it first)
aws s3 rb $bucket --force
