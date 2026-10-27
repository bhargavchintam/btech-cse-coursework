# VPC - Virtual Private Cloud

**Definition:** A VPC is a logically isolated virtual network within AWS where you launch resources. You control the IP range, subnets, routing and gateways. Region scoped.

- Like having your own private datacenter network inside AWS.
- Defined by a **CIDR block**, e.g. `10.0.0.0/16`.

## Components (imp)
- **Subnet** - a range of IPs within the VPC, tied to one AZ.
  - **Public subnet** - has a route to the internet gateway.
  - **Private subnet** - no direct internet route.
- **Internet Gateway (IGW)** - attaches to VPC, allows communication with the internet.
- **Route table** - rules that decide where traffic goes. Each subnet associated with one.
- **NAT Gateway** - lets private subnet instances reach the internet outbound (for updates) without being reachable inbound.

## Security layers (2 marks)
| Security Group | NACL (Network ACL) |
|----------------|--------------------|
| instance level | subnet level |
| stateful (return traffic auto allowed) | stateless (must allow both directions) |
| allow rules only | allow and deny rules |
| evaluated as a whole | rules evaluated in number order |

## Default VPC
- AWS creates a default VPC per region with a public subnet in each AZ, an IGW and a route to it - so new instances get internet access out of the box.

## Typical setup
- VPC `10.0.0.0/16`.
- Public subnet `10.0.1.0/24` -> route 0.0.0.0/0 to IGW -> web servers.
- Private subnet `10.0.2.0/24` -> route 0.0.0.0/0 to NAT -> database servers.

## Connectivity options
- **VPC Peering** - connect two VPCs privately.
- **VPN** - encrypted tunnel from on-prem to VPC.
- **Direct Connect** - dedicated physical line from datacenter to AWS.

## CIDR quick recall
- `/16` = 65536 addresses, `/24` = 256 addresses.
- AWS reserves 5 IPs in every subnet (first 4 + last 1).
