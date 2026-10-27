#!/bin/bash
# check cpu support for hardware virtualization (vmx=intel, svm=amd)

count=$(egrep -c '(vmx|svm)' /proc/cpuinfo)

if [ "$count" -gt 0 ]; then
    echo "virtualization supported ($count cpu threads)"
else
    echo "no hardware virtualization support on this cpu"
fi

# check kvm kernel modules loaded
lsmod | grep kvm

# list libvirt domains
virsh list --all
