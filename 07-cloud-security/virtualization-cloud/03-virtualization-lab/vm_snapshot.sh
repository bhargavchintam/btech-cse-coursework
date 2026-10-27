#!/bin/bash
# take, list and restore snapshots of a vm

vm_name="ubuntu-test"
snap="clean-install"

VBoxManage snapshot "$vm_name" take "$snap" --description "fresh ubuntu install"

VBoxManage snapshot "$vm_name" list

# restore back to a snapshot (vm must be powered off)
# VBoxManage snapshot "$vm_name" restore "$snap"

# delete a snapshot
# VBoxManage snapshot "$vm_name" delete "$snap"
