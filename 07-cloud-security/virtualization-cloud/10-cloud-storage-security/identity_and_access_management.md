# Identity and Access Management (IAM)

**Definition:** IAM = the framework of policies and tech that ensures the **right identities** have the **right access** to the **right resources** at the **right time**. Controls *who can do what* in the cloud.

## Two core ideas (don't confuse them)
- **Authentication (AuthN)** — *who are you?* verify identity. (password, MFA, keys)
- **Authorization (AuthZ)** — *what are you allowed to do?* grant/deny permissions.

## IAM building blocks (AWS terms as example)
- **User** — an identity for a person or app.
- **Group** — collection of users sharing permissions.
- **Role** — a set of permissions that can be *assumed* temporarily (by a user, service or app). No long-term credentials.
- **Policy** — a document (JSON) that defines allowed/denied actions on resources.

## Key principles
- **Least privilege** — give only the minimum permissions needed. (most important, asked)
- **MFA (multi-factor auth)** — password + second factor (OTP, token) → stronger login.
- **Separation of duties** — split sensitive tasks across people.
- **Role-based access control (RBAC)** — assign permissions by role/job, not per person.
- **Rotate credentials** — change keys/passwords regularly, don't hardcode.
- **Federation / SSO** — use existing identity (e.g. corporate AD, Google) to log in once.

## Example: AWS IAM
- create users, put them in groups, attach policies.
- use **roles** for EC2/Lambda to access other services (no keys stored on the instance).
- enable **MFA** on the root account, don't use root day-to-day.

## Quick table

| Term | Meaning |
|------|---------|
| Authentication | verify identity (who) |
| Authorization | grant permissions (what) |
| User / Group | identities and their collections |
| Role | temporary assumable permissions |
| Policy | JSON defining allow/deny |
| Least privilege | minimum access needed |
| MFA | extra factor beyond password |

IAM is the **first line of defence** in cloud — most attacks start with stolen or over-permissive credentials.
