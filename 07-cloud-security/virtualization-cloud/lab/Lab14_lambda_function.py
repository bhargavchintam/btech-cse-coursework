# simple lambda handler
import json


def handler(event, context):
    name = event.get("name", "world")
    msg = "hello " + name
    return {
        "statusCode": 200,
        "body": json.dumps({"message": msg}),
    }
