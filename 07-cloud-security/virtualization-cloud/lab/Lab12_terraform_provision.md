# Lab 12 - Provision AWS infra with Terraform

## Aim
Use Terraform (Infrastructure as Code) to provision an EC2 instance on AWS declaratively.

## Tools / Environment
- Terraform 0.12 / 0.13
- AWS account, region us-east-1, credentials via aws configure
- config file: `Lab12_main.tf`

## Procedure
1. Install terraform and check: `terraform version`.
2. Write the config - provider block + aws_instance resource + an output for the public IP:

```hcl
provider "aws" {
  region = "us-east-1"
}

resource "aws_instance" "web" {
  ami           = "ami-0c94855ba95c71c99"
  instance_type = "t2.micro"
  key_name      = "mykey"
  tags = {
    Name = "cloudlab-web"
  }
}

output "public_ip" {
  value = aws_instance.web.public_ip
}
```

3. Initialise the working dir (downloads aws provider plugin):

```
terraform init
```

4. Preview the plan:

```
terraform plan
```

5. Apply to create the resources (type `yes` to confirm):

```
terraform apply
```

6. Destroy when done so nothing keeps running:

```
terraform destroy
```

## Observation / Output
- `terraform init` prints "Terraform has been successfully initialized!".
- `terraform plan` shows `1 to add, 0 to change, 0 to destroy` (aws_instance.web).
- `terraform apply` creates the instance and prints `public_ip = <ip>` in outputs.
- Instance visible in EC2 console; `terraform destroy` removes it (`1 destroyed`).

## Result
EC2 instance provisioned and destroyed declaratively using Terraform.
