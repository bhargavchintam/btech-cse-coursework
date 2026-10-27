# Unit 1 — Introduction to Operating Systems and Unix

## What an OS is
The layer between the hardware and the user/programs. It manages resources (CPU, memory, I/O, files)
and provides a convenient interface. Acts as a **resource manager** and an **extended machine**.

## Functions
Process management, memory management, file management, I/O management, protection & security,
scheduling.

## Types
- **Batch** — jobs collected and run without interaction.
- **Multiprogramming** — several jobs in memory, CPU switches when one waits.
- **Time-sharing (multitasking)** — rapid switching gives each user the feel of a dedicated machine.
- **Real-time** — guaranteed response within a deadline (hard vs soft).
- **Distributed** — resources spread across networked machines.

## Unix architecture
```
   users / applications
   ------ shell (command interpreter) ------
   ------ system call interface ------------
             kernel  (process, memory, file, device)
   ------ hardware -------------------------
```
The **kernel** is the core (always in memory); the **shell** is the user's interface; system programs
and utilities sit around them.

## System call vs library function
- A **system call** enters the kernel (mode switch to kernel mode): `fork`, `read`, `open`, `exec`.
- A **library function** runs in user space and may or may not call the kernel: `printf` (calls `write`),
  `strlen` (no syscall).

## Dual mode
The CPU runs in **user mode** (restricted) or **kernel mode** (privileged). A system call or interrupt
switches to kernel mode; privileged instructions are only allowed there — this protects the system.

## Solved
**1. Is `printf` a system call?** No — it's a C library function that eventually calls the `write` system call.
**2. Why two modes?** So user programs can't run privileged instructions directly and crash/harm the system.
