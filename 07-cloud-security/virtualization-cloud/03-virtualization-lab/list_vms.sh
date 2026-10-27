#!/bin/bash
# list virtualbox vms

echo "all vms:"
VBoxManage list vms

echo "running vms:"
VBoxManage list runningvms

echo "supported ostypes:"
VBoxManage list ostypes | head
