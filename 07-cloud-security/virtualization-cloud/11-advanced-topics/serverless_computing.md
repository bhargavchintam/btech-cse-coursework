# Serverless Computing

**Definition:** **Serverless computing** is a cloud execution model where the cloud provider **manages the servers** and dynamically allocates resources — the developer only writes and deploys **code (functions)**, and pays only for actual execution. (imp)

"Serverless" doesn't mean no servers — servers exist, but they're **abstracted away** from the developer.

## Key idea — FaaS
- Main form is **FaaS (Function as a Service)**.
- You upload small functions; provider runs them on demand.
- Examples: **AWS Lambda**, Azure Functions, Google Cloud Functions.

## Characteristics
- **No server management** — no provisioning, patching, scaling done by you.
- **Event-driven** — function runs in response to a trigger/event (HTTP request, file upload to S3, DB change, queue message).
- **Auto-scaling** — scales up/down automatically, even to zero.
- **Pay-per-use** — billed for execution time (per ms) + number of invocations. No cost when idle.
- **Stateless** — functions don't keep local state between runs.

## Advantages
- No infra management -> less ops work.
- Cost efficient (no charge when idle).
- Automatic scaling.
- Faster time to market.

## Disadvantages / limitations (2 marks)
- **Cold start** — first invocation after idle has startup delay (imp).
- Execution **time limits** (e.g. Lambda had 15 min max in 2020).
- **Vendor lock-in** — code tied to provider's platform.
- Hard to debug / monitor.
- Not good for long-running or stateful tasks.

## Serverless vs traditional / containers
| Point | Traditional / VM | Serverless (FaaS) |
|-------|------------------|-------------------|
| Server mgmt | You manage | Provider manages |
| Scaling | Manual / configured | Automatic (to zero) |
| Billing | For running server (always) | Per execution only |
| State | Stateful possible | Stateless |
| Unit | VM / container | Function |

## Use cases
- REST APIs / backends, image/file processing on upload, scheduled jobs (cron), IoT event handling, chatbots.

## Also note — BaaS
Besides FaaS, serverless also includes **BaaS (Backend as a Service)** — ready backend services (auth, DB) like Firebase.

Exam: define serverless, FaaS = AWS Lambda, event-driven + pay-per-use + auto-scale, mention cold start as drawback.
