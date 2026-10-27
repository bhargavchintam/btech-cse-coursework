# Lab 1 - Install VirtualBox and create a VM

## Aim
Install Oracle VirtualBox on host machine and create a new virtual machine, install Ubuntu 20.04 guest OS on it.

## Tools / Environment
- Host: Windows 10 / Ubuntu 18.04 desktop
- Oracle VirtualBox 6.1
- Ubuntu 20.04 LTS ISO (ubuntu-20.04-desktop-amd64.iso)
- min 4 GB RAM on host (2 GB given to guest)

## Procedure
1. Download VirtualBox 6.1 installer from virtualbox.org and run it. Keep defaults, finish install.
2. Open VirtualBox, click **New**. Name = `ubuntu-vm`, Type = Linux, Version = Ubuntu (64-bit).
3. Set memory = 2048 MB. Create virtual hard disk (VDI, dynamically allocated, 20 GB).
4. Select the VM, go to Settings -> Storage -> attach the Ubuntu ISO to the optical drive.
5. Also can create the VM from command line (VBoxManage):

```
VBoxManage createvm --name ubuntu-vm --ostype Ubuntu_64 --register
VBoxManage modifyvm ubuntu-vm --memory 2048 --cpus 2 --nic1 nat
VBoxManage createhd --filename ubuntu-vm.vdi --size 20000
VBoxManage storagectl ubuntu-vm --name "SATA" --add sata
VBoxManage storageattach ubuntu-vm --storagectl "SATA" --port 0 --device 0 --type hdd --medium ubuntu-vm.vdi
VBoxManage storageattach ubuntu-vm --storagectl "SATA" --port 1 --device 0 --type dvddrive --medium ubuntu-20.04-desktop-amd64.iso
```

6. Start the VM: `VBoxManage startvm ubuntu-vm` (or click Start in GUI).
7. Boot from ISO, follow Ubuntu installer, create user, finish install and reboot.

## Observation / Output
- VM boots into Ubuntu installer, after install the guest OS runs inside a window on host.
- `VBoxManage list vms` shows the registered VM. `VBoxManage list runningvms` shows it while running.
- Guest works independently of host, own IP via NAT (checked with `ip addr` inside guest).

## Result
VirtualBox installed and a VM created with Ubuntu 20.04 guest OS running successfully on the host.
