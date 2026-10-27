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
