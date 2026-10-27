provider "aws" {
  region = var.region
}

resource "aws_security_group" "ssh" {
  name        = "allow-ssh"
  description = "ssh in from anywhere"

  ingress {
    from_port   = 22
    to_port     = 22
    protocol    = "tcp"
    cidr_blocks = ["0.0.0.0/0"]
  }

  egress {
    from_port   = 0
    to_port     = 0
    protocol    = "-1"
    cidr_blocks = ["0.0.0.0/0"]
  }
}

resource "aws_instance" "web" {
  ami                    = var.ami
  instance_type          = var.instance_type
  vpc_security_group_ids = [aws_security_group.ssh.id]

  tags = {
    Name = "web-1"
  }
}

resource "aws_s3_bucket" "store" {
  bucket = var.bucket_name
}
