# FaaS / Serverless

Newer model, not in the original NIST three but examiners started asking it. Often called a form of **serverless** computing.

**Definition:** FaaS (Function as a Service) lets you run **individual functions / pieces of code** in response to events, **without managing any servers**. Provider runs the code only when triggered and bills per execution.

"Serverless" does **not** mean no servers — it means *you don't manage the servers*, provider handles all of it.

## How it works
1. write a small function (e.g. resize an image)
2. upload it to the provider
3. attach a **trigger** — HTTP request, file upload, DB change, timer, queue message
4. on the event, provider spins it up, runs it, tears it down
5. you pay only for the execution time / invocations

## Key features
- **event-driven** — runs on triggers
- **auto-scaling** — 0 to thousands of instances automatically
- **scale to zero** — no cost when idle (no requests → no charge)
- **stateless** — each invocation independent, no local state kept
- **short-lived** — functions have a max runtime (e.g. minutes)

## Examples (2020)
- **AWS Lambda** (the pioneer, 2014)
- **Azure Functions**
- **Google Cloud Functions**
- IBM Cloud Functions (OpenWhisk)

## Pros / cons

| Pros | Cons |
|------|------|
| pay only when running (cheap for spiky loads) | cold-start latency |
| no server management at all | not for long-running jobs |
| auto-scales instantly | harder to debug / monitor |
| fast to deploy small features | vendor lock-in (function format) |

## FaaS vs the others
- more abstracted than **PaaS** — in PaaS the app runs continuously; in FaaS only the function runs, only when called.
- sometimes listed as **BaaS + FaaS = serverless**.

Common use: image processing, webhooks, REST API backends, scheduled tasks, IoT event handling.
