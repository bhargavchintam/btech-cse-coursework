# Lab 11 - AWS S3 operations

## Aim
Perform basic S3 operations - create a bucket, upload an object, list objects and download - using boto3.

## Tools / Environment
- AWS account, region ap-south-1 (Mumbai)
- Python 3.8, boto3
- script: `Lab11_s3_ops.py`
- test file `notes.txt`

## Procedure
1. Ensure credentials are configured (`aws configure`) and boto3 installed.
2. Bucket names are global and must be unique - use `cloudlab-bucket-2020`.
3. Important gotcha: for any region other than us-east-1 you MUST pass `CreateBucketConfiguration` with the `LocationConstraint`, else it errors:

```python
import boto3
region = "ap-south-1"
bucket = "cloudlab-bucket-2020"
s3 = boto3.client("s3", region_name=region)

s3.create_bucket(Bucket=bucket,
                 CreateBucketConfiguration={"LocationConstraint": region})
s3.upload_file("notes.txt", bucket, "notes.txt")

resp = s3.list_objects_v2(Bucket=bucket)
for obj in resp.get("Contents", []):
    print(obj["Key"])

s3.download_file(bucket, "notes.txt", "notes_copy.txt")
```

4. Run: `python3 Lab11_s3_ops.py`.
5. Cross check with CLI: `aws s3 ls s3://cloudlab-bucket-2020`.
6. Cleanup: `aws s3 rb s3://cloudlab-bucket-2020 --force`.

## Observation / Output
- Script prints `created cloudlab-bucket-2020`, then `uploaded notes.txt`, then lists `notes.txt`, then `downloaded`.
- `notes_copy.txt` appears in the local folder, same content as notes.txt.
- Bucket and object are visible in the S3 console under ap-south-1.

## Result
S3 bucket created and object upload / list / download performed successfully using boto3.
