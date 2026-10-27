#!/bin/bash
# create a new virtualbox vm using VBoxManage

vm_name="ubuntu-test"
iso="/home/student/isos/ubuntu-20.04.iso"
vdi="$HOME/VirtualBox VMs/$vm_name/$vm_name.vdi"

VBoxManage createvm --name "$vm_name" --ostype Ubuntu_64 --register

VBoxManage modifyvm "$vm_name" --memory 2048 --cpus 2 --nic1 nat

VBoxManage createhd --filename "$vdi" --size 20000

VBoxManage storagectl "$vm_name" --name "SATA Controller" --add sata --controller IntelAhci

VBoxManage storageattach "$vm_name" --storagectl "SATA Controller" \
  --port 0 --device 0 --type hdd --medium "$vdi"

VBoxManage storageattach "$vm_name" --storagectl "SATA Controller" \
  --port 1 --device 0 --type dvddrive --medium "$iso"

echo "vm $vm_name created"
