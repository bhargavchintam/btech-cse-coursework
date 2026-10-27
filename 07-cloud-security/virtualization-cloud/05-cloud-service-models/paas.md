# PaaS — Platform as a Service

**Definition (NIST):** capability provided is to **deploy onto the cloud infra consumer-created or acquired applications** created using programming languages, libraries, services and tools supported by the provider.
- consumer does **not** manage/control the underlying infra (network, servers, OS, storage)
- consumer **does** control the deployed applications and possibly config settings for the app-hosting env

Middle layer. You bring **code**, provider gives the **platform** (OS + runtime + middleware) to run it.

## What provider gives you
- OS, runtime (e.g. Java, Python, Node)
- middleware, databases
- development tools, build/deploy pipeline
- scaling handled for you

## What you manage
- your application code
- your data
- app-level config

Rule of thumb: **provider = up to runtime; you = app + data.**

## Examples (2020)
- **AWS Elastic Beanstalk**
- **Google App Engine**
- **Microsoft Azure App Service**
- **Heroku**
- Red Hat OpenShift

## Pros / cons

| Pros | Cons |
|------|------|
| focus only on code, no server admin | less control over the stack |
| fast deployment | limited to supported languages/runtimes |
| built-in scaling | possible vendor lock-in |
| team collaboration on one platform | debugging platform-level issues is hard |

## When to use
- developers want to ship apps without managing servers
- rapid app development, APIs, microservices
- don't want to handle OS patching

Analogy: PaaS = renting a fully-furnished flat — just move in with your stuff (your code).
