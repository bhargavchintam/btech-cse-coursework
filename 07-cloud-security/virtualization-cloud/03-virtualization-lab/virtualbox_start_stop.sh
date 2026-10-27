#!/bin/bash
# start and stop a virtualbox vm

vm_name="ubuntu-test"

# start headless (no window)
VBoxManage startvm "$vm_name" --type headless

# start with gui:
# VBoxManage startvm "$vm_name" --type gui

# pause / resume
# VBoxManage controlvm "$vm_name" pause
# VBoxManage controlvm "$vm_name" resume

# graceful shutdown via acpi
VBoxManage controlvm "$vm_name" acpipowerbutton

# hard power off
# VBoxManage controlvm "$vm_name" poweroff
