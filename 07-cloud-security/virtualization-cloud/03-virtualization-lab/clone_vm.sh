#!/bin/bash
# clone an existing vm

src="ubuntu-test"
dst="ubuntu-clone"

VBoxManage clonevm "$src" --name "$dst" --register

echo "cloned $src -> $dst"
VBoxManage list vms
