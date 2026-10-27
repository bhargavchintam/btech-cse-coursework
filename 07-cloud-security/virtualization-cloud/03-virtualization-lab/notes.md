# Virtualization lab - tools notes

## VBoxManage
- CLI front-end for VirtualBox, does everything the GUI does.
- `createvm` registers a new vm, `modifyvm` sets ram / cpu / nic.
- `storagectl` + `storageattach` add a controller and attach the disk/iso.
- `startvm` / `controlvm` for power on, off, pause, resume.
- `snapshot` take / list / restore / delete (imp for rollback before testing).
- `clonevm` makes a full or linked copy.

## virsh + virt-install (KVM)
- KVM = kernel module that turns Linux into a type-1 hypervisor.
- Needs a cpu with **vmx** (Intel) or **svm** (AMD) flag, check /proc/cpuinfo.
- `virsh list --all` lists all domains (vms) known to libvirt.
- `virt-install` creates and starts the install of a new vm.
- Disks usually qcow2 under /var/lib/libvirt/images.

## Vagrant
- Builds reproducible vm environments from a `Vagrantfile` (Ruby).
- File describes box, network, provider, provisioning.
- `vagrant up` boots it, `vagrant ssh` logs in, `vagrant destroy` removes it.
- Default provider is VirtualBox, boxes come from Vagrant Cloud e.g. ubuntu/focal64.
- Provisioners (shell, ansible) auto-configure the vm on first boot.

## VirtualBox vs KVM (differentiate)
| VirtualBox | KVM |
|---|---|
| Type-2, runs on top of host OS | Type-1, runs at kernel level |
| Windows / Mac / Linux | Linux only |
| GUI + VBoxManage | virsh / virt-manager |
| Good for desktop testing | Good for servers, cloud back-end |
