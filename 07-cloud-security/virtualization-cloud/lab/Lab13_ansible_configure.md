# Lab 13 - Configuration management with Ansible

## Aim
Use Ansible to configure remote servers - install and start nginx and deploy an index page - using a playbook.

## Tools / Environment
- Ansible 2.9 on control node (Ubuntu 20.04)
- one or more managed nodes (Ubuntu) reachable over SSH
- inventory file + playbook (`Lab13_playbook.yml`)

## Procedure
1. Install ansible on the control node:

```
sudo apt-get update
sudo apt-get install -y ansible
ansible --version
```

2. Inventory file `hosts` grouping the managed nodes:

```
[webservers]
192.168.56.11
192.168.56.12
```

3. Test connectivity (needs SSH key set up to the nodes):

```
ansible -i hosts webservers -m ping
```

4. Playbook `Lab13_playbook.yml` - installs nginx, starts + enables it, copies index page:

```yaml
---
- name: configure web servers
  hosts: webservers
  become: yes
  tasks:
    - name: install nginx
      apt:
        name: nginx
        state: present
        update_cache: yes
    - name: start and enable nginx
      service:
        name: nginx
        state: started
        enabled: yes
    - name: copy index page
      copy:
        src: index.html
        dest: /var/www/html/index.html
```

5. Run the playbook:

```
ansible-playbook -i hosts Lab13_playbook.yml
```

## Observation / Output
- `ansible ... -m ping` returns `pong` from each node (SUCCESS).
- Playbook run shows PLAY and TASK output; each task `changed` on first run, `ok` on re-run (idempotent).
- Recap: `ok=4 changed=3 failed=0` per host.
- Browsing to each node's IP shows the custom index.html.

## Result
Remote web servers configured automatically with nginx using an Ansible playbook, idempotency verified.
