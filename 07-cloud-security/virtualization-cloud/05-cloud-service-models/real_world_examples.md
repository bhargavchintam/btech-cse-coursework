# Real-world examples of service models

Map each model to products you actually use — helps in the exam to give an example per point.

## IaaS in the wild
- **AWS EC2** — rent VMs by the hour, pick OS, size.
- **Azure Virtual Machines** — Windows/Linux VMs.
- **Google Compute Engine** — VMs on Google's infra.
- **DigitalOcean droplets** — simple VMs, popular with students/startups.
- typical user: a company doing lift-and-shift of its servers to cloud.

## PaaS in the wild
- **Heroku** — push code, it runs; big with early-stage apps.
- **Google App Engine** — deploy web apps, auto-scaled.
- **AWS Elastic Beanstalk** — upload app, AWS handles capacity/scaling.
- **Azure App Service** — host web apps/APIs.
- typical user: a dev team shipping a web app without touching servers.

## SaaS in the wild
- **Gmail / Google Workspace** — email + docs in browser.
- **Microsoft Office 365** — Word/Excel/Outlook online.
- **Salesforce** — CRM.
- **Dropbox** — file storage/sync.
- **Zoom, Slack, Netflix** — all delivered as a service.
- typical user: anyone — no technical setup needed.

## FaaS in the wild
- **AWS Lambda** — run functions on events (e.g. resize an image when uploaded to S3).
- **Azure Functions**, **Google Cloud Functions** — same idea.

## One combined table

| Model | Example products | Typical user |
|-------|-----------------|--------------|
| IaaS | EC2, Azure VM, Compute Engine | infra / sysadmin team |
| PaaS | Heroku, App Engine, Beanstalk | app developers |
| SaaS | Gmail, Office 365, Salesforce | end users |
| FaaS | Lambda, Azure/GCP Functions | developers (event code) |

## A single company using all layers
An e-commerce startup might: run its database on **EC2 (IaaS)**, host the web app on **Heroku (PaaS)**, use **Office 365 (SaaS)** internally, and process order-confirmation emails with **Lambda (FaaS)**. Good example to write for "explain with a scenario".
