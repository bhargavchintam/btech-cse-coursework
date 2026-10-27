# IAM - Identity and Access Management

**Definition:** IAM is the AWS service used to securely control **who** (authentication) can access **what** (authorization) in your AWS account. Free to use, global (not region scoped).

## Main entities (imp)
- **User** - a person or application, has long term credentials (password, access keys).
- **Group** - a collection of users, attach a policy once and all users inherit it.
- **Role** - a set of permissions assumed temporarily. No permanent credentials. Used by EC2/Lambda or for cross account access.
- **Policy** - a JSON document defining permissions (allow/deny on actions/resources).

## Root user
- Created with the account, has full unrestricted access.
- Best practice: do NOT use root for daily work. Enable **MFA** on root, create an IAM admin user instead.

## Policy structure (2 marks)
A policy is JSON with:
- **Effect** - Allow or Deny.
- **Action** - the API calls, e.g. `s3:GetObject`.
- **Resource** - the ARN(s) it applies to.

Example:
```
{
  "Version": "2012-10-17",
  "Statement": [
    {
      "Effect": "Allow",
      "Action": ["s3:GetObject", "s3:PutObject"],
      "Resource": "arn:aws:s3:::my-bucket/*"
    }
  ]
}
```

## Types of policy
- **AWS managed** - predefined by AWS (e.g. AmazonS3ReadOnlyAccess).
- **Customer managed** - you create and reuse.
- **Inline** - embedded directly in one user/group/role.

## Role vs User (asked prev year)
| User | Role |
|------|------|
| permanent credentials | temporary credentials |
| for a person/app | assumed by services/other accounts |
| access keys / password | STS issues short lived tokens |

## Best practices
- Grant **least privilege** - only permissions actually needed.
- Enable **MFA** for privileged users.
- Use **roles** for EC2 instead of putting access keys on the instance.
- Rotate access keys, remove unused ones.
