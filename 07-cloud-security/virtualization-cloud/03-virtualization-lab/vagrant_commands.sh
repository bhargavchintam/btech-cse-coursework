#!/bin/bash
# common vagrant commands

# boot the vm (reads Vagrantfile in current dir)
vagrant up

# ssh into the running vm
vagrant ssh

# show status
vagrant status

# reload after editing Vagrantfile
vagrant reload

# re-run provisioners
vagrant provision

# stop the vm
vagrant halt

# remove the vm completely
vagrant destroy -f
