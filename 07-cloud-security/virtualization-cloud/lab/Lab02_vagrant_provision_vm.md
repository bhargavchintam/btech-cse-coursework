# Lab 2 - Provision a VM using Vagrant

## Aim
Use Vagrant to automatically create and provision a VirtualBox VM (Ubuntu focal) with nginx installed, using a Vagrantfile.

## Tools / Environment
- VirtualBox 6.1 (provider)
- Vagrant 2.2.x
- box: `ubuntu/focal64`
- Vagrantfile (see `Lab02_Vagrantfile`)

## Procedure
1. Install Vagrant, check version: `vagrant --version`.
2. Make a project folder and add the box:

```
mkdir vagrant-lab && cd vagrant-lab
vagrant box add ubuntu/focal64
```

3. Put the Vagrantfile in the folder. It sets box, private network IP, port forward 8080->80, and a shell provisioner that installs nginx:

```ruby
Vagrant.configure("2") do |config|
  config.vm.box = "ubuntu/focal64"
  config.vm.network "private_network", ip: "192.168.56.10"
  config.vm.network "forwarded_port", guest: 80, host: 8080
  config.vm.provider "virtualbox" do |vb|
    vb.memory = 1024
    vb.cpus = 2
  end
  config.vm.provision "shell", inline: <<-SHELL
    apt-get update
    apt-get install -y nginx
  SHELL
end
```

4. Bring up the VM: `vagrant up`. Vagrant downloads box (first time), boots VM, runs provisioner.
5. SSH into it: `vagrant ssh`. Check nginx: `systemctl status nginx`.
6. Open `http://localhost:8080` on host - nginx welcome page.
7. To stop: `vagrant halt`. To delete: `vagrant destroy -f`.

## Observation / Output
- `vagrant up` output shows box import, network config, then the shell provisioner running apt-get and installing nginx.
- `vagrant status` shows the machine `running (virtualbox)`.
- nginx default page loads at localhost:8080.

## Result
VM provisioned automatically with Vagrant, nginx installed via provisioner without any manual OS setup.
