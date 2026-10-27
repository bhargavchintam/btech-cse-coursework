#!/bin/bash
set -e

PROJECT="<your-project>"
ZONE="asia-south1-a"
BUCKET="my-unique-bucket-2020"

gcloud config set project "$PROJECT"
gcloud config set compute/zone "$ZONE"

gcloud compute instances create web-1 \
    --machine-type e2-micro \
    --image-family debian-12 \
    --image-project debian-cloud

gsutil mb -l asia-south1 "gs://$BUCKET/"

echo "hello gcs" > index.html
gsutil cp index.html "gs://$BUCKET/"

gcloud compute instances list
