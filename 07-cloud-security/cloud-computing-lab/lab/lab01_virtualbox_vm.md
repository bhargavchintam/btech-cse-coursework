# Lab 1 - Create and boot an Ubuntu VM in Oracle VirtualBox

**Date:** 21-07-2020

## Aim

Install a guest OS (Ubuntu 20.04 Server) as a virtual machine on Oracle VirtualBox and boot it,
to see hardware virtualization first hand before moving on to the cloud proper.

## Tools

- Oracle VirtualBox 6.1 (host: Windows 10, 8 GB RAM)
- ubuntu-20.04.1-live-server-amd64.iso

## Procedure

1. Download the Ubuntu Server ISO from releases.ubuntu.com/20.04/.

2. In VirtualBox click **New** and set:
   - Name: `cloud-lab`
   - Type: Linux, Version: Ubuntu (64-bit)
   - Memory: 2048 MB
   - Create a virtual hard disk now, VDI, dynamically allocated, 15 GB

3. Same thing from the command line instead of the wizard (VBoxManage ships with VirtualBox):

   ```
   VBoxManage createvm --name cloud-lab --ostype Ubuntu_64 --register
   VBoxManage modifyvm cloud-lab --memory 2048 --cpus 2 --nic1 nat
   VBoxManage createhd --filename cloud-lab.vdi --size 15360
   VBoxManage storagectl cloud-lab --name SATA --add sata --controller IntelAhci
   VBoxManage storageattach cloud-lab --storagectl SATA --port 0 --device 0 \
       --type hdd --medium cloud-lab.vdi
   VBoxManage storageattach cloud-lab --storagectl SATA --port 1 --device 0 \
       --type dvddrive --medium ubuntu-20.04.1-live-server-amd64.iso
   ```

4. Boot the VM off the ISO:

   ```
   VBoxManage startvm cloud-lab
   ```

5. Step through the Ubuntu installer - language, keyboard, use the whole 15 GB disk,
   set hostname `cloud-lab`, user `bhargav`, tick **Install OpenSSH server**.

6. When it says installation complete, remove the ISO and reboot:

   ```
   VBoxManage storageattach cloud-lab --storagectl SATA --port 1 --device 0 \
       --type dvddrive --medium none
   VBoxManage controlvm cloud-lab reset
   ```

7. Log in at the console and check the guest:

   ```
   lsb_release -a
   free -m
   nproc
   ```

## Output

```
$ lsb_release -a
Distributor ID: Ubuntu
Description:    Ubuntu 20.04.1 LTS
Release:        20.04
Codename:       focal

$ free -m
              total        used        free
Mem:           1987         180        1500

$ nproc
2
```

Guest sees 2 vCPUs and ~2 GB RAM - exactly what `modifyvm` handed it, carved out of the host.

## Result

An Ubuntu 20.04 VM was created, installed and booted under VirtualBox. The hypervisor gives the
guest its own virtual CPU, memory and disk while the host OS keeps running underneath - which is
the same idea a cloud provider uses to pack many tenants onto one physical machine.
