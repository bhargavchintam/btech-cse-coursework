# Compliance and governance

## Definitions
- **Compliance** — meeting the rules: laws, regulations, industry standards that apply to your data.
- **Governance** — the org's own framework of policies, roles, controls to *manage and oversee* cloud use so it stays compliant and aligned with business goals.

Compliance = follow external rules; governance = internal control to make sure you do.

## Major regulations / standards (2020)
- **GDPR** — EU data protection law (2018). Rules on personal data of EU citizens, right to be forgotten, data residency. Heavy fines.
- **HIPAA** — US healthcare data (patient health info).
- **PCI DSS** — payment card / credit card data security.
- **ISO/IEC 27001** — international standard for information security management (ISMS).
- **SOC 2** — audit report on a service org's security controls.
- **FedRAMP** — US govt cloud security authorisation.

## Key governance concepts
- **Data residency / sovereignty** — data may be legally required to stay in a certain country. Pick provider regions accordingly.
- **Data classification** — label data by sensitivity, apply controls per class.
- **Audit & logging** — keep records of access/changes (e.g. AWS CloudTrail) for accountability.
- **Policies & standards** — define what's allowed, who approves, how resources are configured.
- **Roles & responsibility** — clear ownership (RACI), tie into shared responsibility model.
- **Continuous monitoring** — check config against policy (e.g. AWS Config).

## Shared responsibility w.r.t compliance
Provider gives **compliant infrastructure** (certified datacenters), but the **customer** is responsible for using it in a compliant way (config, data handling, access). Being on a certified cloud does **not** make *you* automatically compliant. (imp)

## Quick table

| Standard | Applies to |
|----------|-----------|
| GDPR | EU personal data |
| HIPAA | US health data |
| PCI DSS | card / payment data |
| ISO 27001 | info security mgmt (general) |
| SOC 2 | service provider controls |
| FedRAMP | US govt cloud |

Exam points: define compliance vs governance, name 3-4 regulations, data residency, and that compliance is a *shared* responsibility.
