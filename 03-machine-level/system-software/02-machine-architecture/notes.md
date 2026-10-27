# Unit 2 — SIC and SIC/XE Machine Architecture

## SIC
- **Memory:** 2¹⁵ = 32,768 bytes; a *word* is 3 bytes (24 bits), addressed by its lowest byte.
- **Registers:** A (accumulator), X (index), L (linkage), PC, SW — each 24 bits.
- **Instruction format (24 bits):** 8-bit opcode + 1-bit x + 15-bit address.
- **Addressing:** direct (x=0, TA = address) and indexed (x=1, TA = address + (X)).

## SIC/XE
- **Memory:** 2²⁰ = 1,048,576 bytes (1 MB).
- **Extra registers:** B (base), S, T, and F (48-bit floating point).
- **Five instruction formats:**

| Format | Size | Layout |
|---|---|---|
| 1 | 8 bits | opcode |
| 2 | 16 bits | opcode + r1 + r2 |
| 3 | 24 bits | opcode(6) + n i x b p e + disp(12) |
| 4 | 32 bits | opcode(6) + n i x b p e + address(20) |

## Addressing modes (flags n, i)
- **Simple:** n=1, i=1 (or n=0,i=0 for SIC-compatible)
- **Immediate:** n=0, i=1 (operand is the value, `#`)
- **Indirect:** n=1, i=0 (operand is the address of the address, `@`)
- **Indexed:** x=1 (add contents of X)
- **PC-relative:** p=1, TA = (PC) + disp, disp is signed −2048…+2047
- **Base-relative:** b=1, TA = (B) + disp, disp is 0…4095
- **e=1** selects format 4 (20-bit direct address).

## Solved
**1. Encode STL RETADR** (STL = 14), format 3, PC-relative. RETADR at 0030, PC after fetch = 0003.
Byte 1 = opcode with n=i=1 → `17`. Flags xbpe = 0010. disp = 0030 − 0003 = 02D.
**Ans:** object code = **17202D**.

**2. Range of PC-relative displacement?** 12-bit signed → **−2048 to +2047**.
