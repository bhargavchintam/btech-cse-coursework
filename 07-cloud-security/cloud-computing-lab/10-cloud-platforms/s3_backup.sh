#!/bin/bash
set -e

SRC="$1"
BUCKET="$2"

if [ -z "$SRC" ] || [ -z "$BUCKET" ]; then
    echo "usage: $0 <dir> <bucket>"
    exit 1
fi

STAMP=$(date +%Y-%m-%d-%H%M%S)

aws s3 sync "$SRC" "s3://$BUCKET/backup-$STAMP/" --delete

echo "backed up $SRC to s3://$BUCKET/backup-$STAMP/"
