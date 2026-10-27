# create an s3 bucket in a non us-east-1 region
import boto3

region = 'ap-south-1'
bucket_name = 'reva-vcc-demo-bucket'

s3 = boto3.client('s3', region_name=region)

# for any region other than us-east-1 you MUST pass LocationConstraint,
# otherwise the call fails with IllegalLocationConstraintException
s3.create_bucket(
    Bucket=bucket_name,
    CreateBucketConfiguration={'LocationConstraint': region}
)

print('created bucket', bucket_name, 'in', region)
