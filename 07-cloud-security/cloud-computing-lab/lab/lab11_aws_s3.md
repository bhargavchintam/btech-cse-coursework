# Lab 11 - AWS S3 bucket: upload, download, list, and access control

**Date:** 10-11-2020

## Aim

Create an S3 bucket, put objects in it, list and download them, and switch the bucket between
private and public to see how object storage access control works.

## Tools

- AWS CLI v2, region ap-south-1
- A bucket (names are globally unique, so mine is suffixed)

## Procedure

1. Create a bucket:

   ```
   aws s3 mb s3://bhargav-cloud-lab-2020 --region ap-south-1
   ```

2. Upload a couple of files (`s3 cp`), and a whole folder with `--recursive`:

   ```
   echo "cloud lab s3 test" > notes.txt
   aws s3 cp notes.txt s3://bhargav-cloud-lab-2020/
   aws s3 cp ./data s3://bhargav-cloud-lab-2020/data --recursive
   ```

3. List what is in the bucket:

   ```
   aws s3 ls s3://bhargav-cloud-lab-2020 --recursive --human-readable
   ```

4. Download it back under a new name to prove the round trip:

   ```
   aws s3 cp s3://bhargav-cloud-lab-2020/notes.txt got-back.txt
   diff notes.txt got-back.txt && echo "same file"
   ```

5. By default the bucket blocks all public access. Try an object URL in the browser - it returns
   AccessDenied. To make one object public you first have to lift the block, then set the ACL:

   ```
   aws s3api put-public-access-block --bucket bhargav-cloud-lab-2020 \
       --public-access-block-configuration \
       "BlockPublicAcls=false,IgnorePublicAcls=false,BlockPublicPolicy=false,RestrictPublicBuckets=false"

   aws s3api put-object-acl --bucket bhargav-cloud-lab-2020 \
       --key notes.txt --acl public-read
   ```

   Now the object URL loads:

   ```
   https://bhargav-cloud-lab-2020.s3.ap-south-1.amazonaws.com/notes.txt
   ```

6. Put it back to private and empty + delete the bucket:

   ```
   aws s3api put-object-acl --bucket bhargav-cloud-lab-2020 --key notes.txt --acl private
   aws s3 rm s3://bhargav-cloud-lab-2020 --recursive
   aws s3 rb s3://bhargav-cloud-lab-2020
   ```

## Output

```
$ aws s3 ls s3://bhargav-cloud-lab-2020 --recursive --human-readable
2020-11-10 15:42:10    18 Bytes notes.txt
2020-11-10 15:42:33   1.2 KiB data/readings.csv
2020-11-10 15:42:33   340 Bytes data/config.json

$ diff notes.txt got-back.txt && echo "same file"
same file

$ curl -s -o /dev/null -w "%{http_code}\n" \
    https://bhargav-cloud-lab-2020.s3.ap-south-1.amazonaws.com/notes.txt
# before public-read:
403
# after public-read:
200
```

## Result

Objects were uploaded, listed, downloaded (byte-for-byte identical) and deleted. S3 is object
storage - flat key/value, not a filesystem, though the console shows `data/` like a folder because
of the key prefix. Access is deny-by-default: a bucket is private until you deliberately open it,
and it takes two steps (unblock public access, then a public-read ACL) - which is exactly the
friction that stops accidental data leaks.
