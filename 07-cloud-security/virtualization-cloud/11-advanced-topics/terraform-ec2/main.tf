# launch a single ec2 instance for the lab

provider "aws" {
  region = var.region
}

resource "aws_instance" "web" {
  ami           = "ami-0885b1f6bd170450c"
  instance_type = var.instance_type

  tags = {
    Name = "vcc-web"
    env  = "lab"
  }
}
