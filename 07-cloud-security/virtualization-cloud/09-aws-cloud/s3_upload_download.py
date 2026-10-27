# upload and download a file from s3 using boto3
import boto3

bucket = 'reva-vcc-demo-bucket'
s3 = boto3.client('s3')

# upload local file -> s3 key
s3.upload_file('sample.txt', bucket, 'sample.txt')
print('uploaded sample.txt')

# download it back to a new name
s3.download_file(bucket, 'sample.txt', 'downloaded.txt')
print('downloaded to downloaded.txt')

# list objects in the bucket
resp = s3.list_objects_v2(Bucket=bucket)
for obj in resp.get('Contents', []):
    print(obj['Key'], obj['Size'], 'bytes')
