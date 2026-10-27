# list all s3 buckets in the account
import boto3

s3 = boto3.client('s3')

response = s3.list_buckets()

print('buckets:')
for bucket in response['Buckets']:
    print('-', bucket['Name'], bucket['CreationDate'])
