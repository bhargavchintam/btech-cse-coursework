# SaaS — Software as a Service

**Definition (NIST):** capability provided is to **use the provider's applications running on a cloud infra**. Apps accessible from various client devices through a thin client interface such as a **web browser** (or a program interface).
- consumer does **not** manage/control the underlying infra OR even individual application capabilities (except limited user-specific config settings)

Top layer. You just **use** ready software — nothing to install or maintain.

## What provider gives you
- the whole application, ready to use
- everything below it: infra, OS, runtime, app, data storage, updates
- access over browser / app

## What you manage
- almost nothing — just your **user settings** and your **data inside the app**

Rule of thumb: **provider = everything; you = just use it.**

## Examples (2020)
- **Gmail / Google Workspace** (G Suite)
- **Microsoft Office 365**
- **Salesforce** (CRM)
- **Dropbox**
- Slack, Zoom, Netflix (as a service)

## Pros / cons

| Pros | Cons |
|------|------|
| zero installation / maintenance | least control / customisation |
| access anywhere, any device | data sits with provider (privacy) |
| automatic updates | needs internet always |
| subscription, no capex | vendor lock-in, hard to migrate data |

## When to use
- end-users need working software, not to build anything
- email, CRM, office docs, collaboration
- want fastest possible adoption

Analogy: SaaS = staying in a hotel — you don't own or furnish anything, just use the room.

Layer summary: **IaaS < PaaS < SaaS** in terms of how much the provider manages (SaaS = provider manages the most). See service_models_comparison.md.
