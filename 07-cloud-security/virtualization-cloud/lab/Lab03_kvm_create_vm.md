# Lab 3 - Create a VM using KVM

## Aim
Install KVM (type-1 / hardware assisted virtualization on Linux) and create a virtual machine using virt-install / virsh.

## Tools / Environment
- Host: Ubuntu 20.04 with VT-x/AMD-V enabled in BIOS
- KVM, QEMU, libvirt, virt-manager
- Ubuntu 20.04 ISO for guest

## Procedure
1. Check if CPU supports virtualization (should be > 0):

```
egrep -c '(vmx|svm)' /proc/cpuinfo
```

2. Install KVM and tools:

```
sudo apt-get update
sudo apt-get install -y qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils virt-manager virtinst
```

3. Add user to libvirt and kvm groups, then re-login:

```
sudo usermod -aG libvirt $USER
sudo usermod -aG kvm $USER
```

4. Verify libvirtd is running: `sudo systemctl status libvirtd`.
5. Create the VM with virt-install:

```
sudo virt-install \
  --name ubuntu-kvm \
  --ram 2048 \
  --vcpus 2 \
  --disk path=/var/lib/libvirt/images/ubuntu-kvm.qcow2,size=20 \
  --os-variant ubuntu20.04 \
  --cdrom /home/student/ubuntu-20.04-desktop-amd64.iso \
  --network network=default
```

6. Manage the VM with virsh:

```
virsh list --all
virsh start ubuntu-kvm
virsh shutdown ubuntu-kvm
```

## Observation / Output
- `egrep -c '(vmx|svm)'` returns non-zero -> virtualization supported.
- virt-install opens a console (or virt-manager GUI) to run the Ubuntu installer.
- `virsh list --all` shows `ubuntu-kvm` with its state (running / shut off).

## Result
KVM installed and a guest VM created and managed using virt-install and virsh.
