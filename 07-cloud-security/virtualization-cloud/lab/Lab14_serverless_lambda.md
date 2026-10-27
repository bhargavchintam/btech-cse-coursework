# Lab 14 - Serverless function with AWS Lambda

## Aim
Create a simple AWS Lambda function (serverless) that takes an event and returns a JSON response, and invoke it.

## Tools / Environment
- AWS account, region us-east-1
- AWS Lambda, Python 3.8 runtime
- AWS CLI
- handler code: `Lab14_lambda_function.py`

## Procedure
1. The function handler takes `(event, context)`, reads a name from the event and returns a message:

```python
import json

def handler(event, context):
    name = event.get("name", "world")
    msg = "hello " + name
    return {
        "statusCode": 200,
        "body": json.dumps({"message": msg}),
    }
```

2. Zip the code for upload:

```
zip function.zip Lab14_lambda_function.py
```

3. Create the function (needs an IAM execution role ARN):

```
aws lambda create-function \
  --function-name hello-lambda \
  --runtime python3.8 \
  --handler Lab14_lambda_function.handler \
  --role arn:aws:iam::123456789012:role/lambda-basic-role \
  --zip-file fileb://function.zip
```

4. Invoke it with a test event, save output:

```
aws lambda invoke \
  --function-name hello-lambda \
  --payload '{"name": "reva"}' \
  out.json
```

5. Check `out.json`. Can also test from the Lambda console with a test event.
6. Cleanup: `aws lambda delete-function --function-name hello-lambda`.

## Observation / Output
- create-function returns the function config JSON (FunctionArn, Runtime python3.8, Handler).
- invoke returns `"StatusCode": 200` and writes `out.json`.
- `out.json` body: `{"statusCode": 200, "body": "{\"message\": \"hello reva\"}"}`.
- No server managed by us - AWS runs the code on demand (serverless).

## Result
Serverless Lambda function created, deployed and invoked successfully, returning the expected JSON response.
