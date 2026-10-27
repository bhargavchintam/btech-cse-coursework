# Lab 14 - Bring up OpenStack with DevStack and launch an instance

**Date:** 15-12-2020

## Aim

Stand up a single-node OpenStack cloud using DevStack, then launch a VM instance from the Horizon
dashboard and the CLI - to see the pieces of a private cloud (compute, image, network) from the
provider side instead of as a customer.

## Tools

- Ubuntu 20.04 VM, 4 vCPU, 8 GB RAM, 40 GB disk (DevStack is heavy)
- DevStack, `victoria` release branch
- OpenStack services: Keystone, Nova, Glance, Neutron, Horizon

## Procedure

1. Fresh Ubuntu VM. Make a `stack` user (DevStack refuses to run as root):

   ```
   sudo useradd -s /bin/bash -d /opt/stack -m stack
   echo "stack ALL=(ALL) NOPASSWD: ALL" | sudo tee /etc/sudoers.d/stack
   sudo su - stack
   ```

2. Clone DevStack:

   ```
   git clone https://opendev.org/openstack/devstack -b stable/victoria
   cd devstack
   ```

3. Minimal `local.conf` (set the admin/service passwords):

   ```
   [[local|localrc]]
   ADMIN_PASSWORD=lab-secret
   DATABASE_PASSWORD=$ADMIN_PASSWORD
   RABBIT_PASSWORD=$ADMIN_PASSWORD
   SERVICE_PASSWORD=$ADMIN_PASSWORD
   HOST_IP=10.0.2.15
   ```

4. Build the cloud. This pulls every service and configures it - takes 20-30 minutes:

   ```
   ./stack.sh
   ```

   When it finishes it prints the Horizon URL and the admin login.

5. Source the admin credentials so the `openstack` CLI works:

   ```
   source openrc admin admin
   openstack service list
   ```

6. Launch an instance from the CLI (DevStack pre-loads a tiny CirrOS image and a `m1.tiny` flavor):

   ```
   openstack flavor list
   openstack image list
   openstack network list

   openstack server create --flavor m1.tiny --image cirros-0.5.1-x86_64-disk \
       --network private demo-vm

   openstack server list
   ```

7. Or do the same in **Horizon**: log in at the printed URL as `admin`, go
   Project -> Compute -> Instances -> **Launch Instance**, pick the CirrOS image, `m1.tiny` flavor
   and the `private` network, and launch. The instance shows up in both the dashboard and
   `openstack server list`.

## Output

```
$ ./stack.sh
=========================
DevStack Component Timing
=========================
Total runtime      1784
...
This is your host IP address: 10.0.2.15
Horizon is now available at http://10.0.2.15/dashboard
Keystone is serving at http://10.0.2.15/identity/
The default users are: admin and demo

$ openstack server list
+--------------------------------------+---------+--------+------------------------+
| ID                                   | Name    | Status | Networks               |
+--------------------------------------+---------+--------+------------------------+
| 4f1c9e2a-77b8-4c0d-9a3e-11d2c4a6f8b1 | demo-vm | ACTIVE | private=10.0.0.14      |
+--------------------------------------+---------+--------+------------------------+
```

## Result

DevStack brought up a working single-node OpenStack, and a CirrOS instance was launched from both
the CLI and Horizon. This is the same model as AWS but self-hosted: Nova is the compute service
(the EC2 equivalent), Glance stores images, Neutron does the networking and Keystone handles auth.
Seeing it from the operator side makes clear that a "public cloud" is just these services run at
huge scale with billing bolted on.
