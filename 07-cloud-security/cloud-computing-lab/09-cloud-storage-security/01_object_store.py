#!/usr/bin/env python3
import hashlib


class Store:
    def __init__(self):
        self.buckets = {}

    def make_bucket(self, name):
        if name in self.buckets:
            raise ValueError("bucket exists: " + name)
        self.buckets[name] = {}
        print(f"created bucket {name}")

    def put(self, bucket, key, data):
        b = data if isinstance(data, bytes) else data.encode()
        etag = hashlib.md5(b).hexdigest()
        self.buckets[bucket][key] = {"data": b, "size": len(b), "etag": etag}
        print(f"put {bucket}/{key}  size={len(b)}  etag={etag}")
        return etag

    def get(self, bucket, key):
        obj = self.buckets[bucket][key]
        print(f"get {bucket}/{key}  size={obj['size']}  etag={obj['etag']}")
        return obj["data"]

    def list(self, bucket):
        keys = sorted(self.buckets[bucket])
        print(f"list {bucket}  ({len(keys)} objects)")
        for k in keys:
            obj = self.buckets[bucket][k]
            print(f"  {k:12} {obj['size']:5}  {obj['etag']}")
        return keys

    def delete(self, bucket, key):
        del self.buckets[bucket][key]
        print(f"delete {bucket}/{key}")


store = Store()
store.make_bucket("photos")
store.put("photos", "cat.jpg", "some binary image bytes here")
store.put("photos", "dog.jpg", "another set of image bytes")
store.put("photos", "notes.txt", "plain text object")
store.list("photos")

data = store.get("photos", "cat.jpg")
print("read back:", data.decode())

store.delete("photos", "dog.jpg")
store.list("photos")
