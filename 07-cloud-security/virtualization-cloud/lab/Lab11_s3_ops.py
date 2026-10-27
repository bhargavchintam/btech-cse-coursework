# basic s3 operations - create bucket, upload, list, download
import boto3

region = "ap-south-1"
bucket = "cloudlab-bucket-2020"
s3 = boto3.client("s3", region_name=region)


def create_bucket():
    s3.create_bucket(
        Bucket=bucket,
        CreateBucketConfiguration={"LocationConstraint": region},
    )
    print("created", bucket)


def upload():
    s3.upload_file("notes.txt", bucket, "notes.txt")
    print("uploaded notes.txt")


def list_objs():
    resp = s3.list_objects_v2(Bucket=bucket)
    for obj in resp.get("Contents", []):
        print(obj["Key"])


def download():
    s3.download_file(bucket, "notes.txt", "notes_copy.txt")
    print("downloaded")


if __name__ == "__main__":
    create_bucket()
    upload()
    list_objs()
    download()
