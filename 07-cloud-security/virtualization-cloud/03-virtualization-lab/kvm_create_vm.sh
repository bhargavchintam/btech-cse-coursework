#!/bin/bash
# create a kvm/qemu vm with virt-install

vm_name="kvm-ubuntu"
iso="/var/lib/libvirt/images/ubuntu-20.04.iso"
disk="/var/lib/libvirt/images/$vm_name.qcow2"

virt-install \
  --name "$vm_name" \
  --ram 2048 \
  --vcpus 2 \
  --disk path="$disk",size=20,format=qcow2 \
  --os-variant ubuntu20.04 \
  --cdrom "$iso" \
  --network network=default \
  --graphics vnc

echo "started install for $vm_name"
