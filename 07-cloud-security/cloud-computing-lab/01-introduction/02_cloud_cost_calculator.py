#!/usr/bin/env python3
# Bindu Bhargava  18-08-20

vm_rate = 0.10      # per vm-hour
sto_rate = 0.15     # per GB-month
bw_rate = 0.10      # per GB transferred


def bill(vm_hours, storage_gb, bandwidth_gb):
    vm = vm_hours * vm_rate
    sto = storage_gb * sto_rate
    bw = bandwidth_gb * bw_rate
    return vm, sto, bw


vm_hours = 3000
storage_gb = 1000
bandwidth_gb = 2500

vm, sto, bw = bill(vm_hours, storage_gb, bandwidth_gb)
cloud_monthly = vm + sto + bw

print("pay-as-you-go, one month")
print(f"  compute : {vm_hours} vm-hours x {vm_rate} = {vm:.2f}")
print(f"  storage : {storage_gb} GB x {sto_rate} = {sto:.2f}")
print(f"  bandwidth: {bandwidth_gb} GB x {bw_rate} = {bw:.2f}")
print(f"  total   : {cloud_monthly:.2f}")

# on-prem: buy the hardware once (capex), then power/cooling/admin every month
capex = 12000
onprem_monthly = 200

print("\non-prem vs cloud")
print(f"  on-prem : {capex} upfront + {onprem_monthly}/month")
print(f"  cloud   : {cloud_monthly:.0f}/month, nothing upfront")

diff = cloud_monthly - onprem_monthly
be = capex / diff
print(f"\ncloud costs {diff:.0f} more per month but skips the {capex} capex")
print(f"break-even = {capex} / {diff:.0f} = {be:.1f} months")

for n in (12, 24, 36):
    op = capex + onprem_monthly * n
    cl = cloud_monthly * n
    who = "cloud cheaper" if cl < op else "on-prem cheaper"
    print(f"  at {n} months: on-prem={op:.0f}  cloud={cl:.0f}  -> {who}")
