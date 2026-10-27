# Unit 3 — Symmetric Block Ciphers (DES, AES)

A symmetric cipher uses one shared secret key for both encrypt and decrypt. A *block* cipher
transforms a fixed-size block of bits at a time (DES 64-bit, AES 128-bit); a stream cipher works
bit/byte at a time. This unit is the two workhorse block ciphers and how we chain blocks with modes.

## The two structures

| | DES | AES |
|---|---|---|
| Type | Feistel network | Substitution-Permutation Network (SPN) |
| Block | 64 bits | 128 bits |
| Key | 56 bits (+8 parity → 64) | 128 / 192 / 256 bits |
| Rounds | 16 | 10 / 12 / 14 |
| Year | 1977 (IBM/NBS) | 2001 (Rijndael, NIST) |
| Status | broken by brute force (56-bit key too short) | current standard |

### DES — Feistel
- Split the 64-bit block into L and R halves (32 bits each).
- Each round: `L_i = R_{i-1}`, `R_i = L_{i-1} XOR f(R_{i-1}, K_i)`.
- The round function f: expand R 32→48, XOR with 48-bit round key, 8 S-boxes 48→32, permute.
- 16 rounds, then swap. Decryption is the *same* network with round keys in reverse order — the
  elegance of Feistel: f never has to be invertible.
- 56-bit key ⇒ 2^56 keys, brute-forced in the 1990s. **3DES** (encrypt-decrypt-encrypt with 2 or 3
  keys) stretched its life but is slow.

### AES — SPN
- State is a 4×4 byte matrix. Each round does four steps:
  - **SubBytes** — byte substitution through a fixed S-box (the *confusion* / non-linearity).
  - **ShiftRows** — cyclically shift rows 0,1,2,3 by 0,1,2,3 bytes.
  - **MixColumns** — mix each column by matrix multiply in GF(2^8) (the *diffusion*).
  - **AddRoundKey** — XOR the round key from the key schedule.
- AES-128 = 10 rounds; the last round skips MixColumns. No Feistel — the whole block changes each round.

> Feistel encrypts half a block per round and reuses one function for both directions; SPN touches
> every byte every round, which is why AES needs fewer rounds for more security.

## Confusion and diffusion (Shannon)
- **Confusion** — make the relation between key and ciphertext as complex as possible. Delivered by
  substitution (S-boxes). Statistics of the ciphertext should not leak the key.
- **Diffusion** — spread the influence of one plaintext bit over many ciphertext bits. Delivered by
  permutation / MixColumns. Flipping one input bit should flip ~half the output bits (avalanche).
- A strong cipher needs both, layered over many rounds.

## Modes of operation
A block cipher only encrypts one block; a *mode* extends it to a whole message.

| Mode | Rule | Notes |
|---|---|---|
| **ECB** | each block encrypted independently: `C_i = E(P_i)` | equal plaintext blocks → equal ciphertext blocks. Leaks patterns (the "ECB penguin"). Avoid for real data. |
| **CBC** | `C_i = E(P_i XOR C_{i-1})`, `C_0` seeded by an IV | identical blocks now differ; needs a fresh random IV per message. Decrypt: `P_i = D(C_i) XOR C_{i-1}`. |

The IV must be unpredictable but need not be secret; it is shipped alongside the ciphertext. Both
modes need the message padded to a whole number of blocks (PKCS#7 pad here, added by EVP).

## Solved — one AES-128 block (FIPS-197 test vector)
```
key       = 000102030405060708090a0b0c0d0e0f
plaintext = 00112233445566778899aabbccddeeff
AES-128-ECB, padding off (single raw block)
```
**Ans:** ciphertext `69c4e0d86a7b0430d8cdb78070b4c55a` — reproduced exactly by `aes_ecb.c`.

## Solved — why ECB is unsafe
Encrypt the two-block message `AAAAAAAAAAAAAAAA|AAAAAAAAAAAAAAAA` (both blocks identical) under ECB.
Since `C_i = E(P_i)` with no chaining, both output blocks are identical too — an attacker sees the
repetition without knowing the key.
**Ans:** ECB reveals plaintext structure; CBC fixes it by feeding `C_{i-1}` into the next block.

## Programs in this folder
- `aes_ecb.c` — AES-128-ECB, verifies the FIPS-197 vector above, then decrypts back.
- `aes_cbc.c` — AES-128-CBC with a 16-byte IV; encrypt a sentence, decrypt, confirm round trip.
- `des_cbc.c` — DES-CBC via `EVP_des_cbc()`; same encrypt/decrypt round trip.

All three use the OpenSSL 3.x EVP API (`EVP_EncryptInit_ex` / `EVP_EncryptUpdate` /
`EVP_EncryptFinal_ex`), not the deprecated low-level calls.
Build: `cc file.c -lcrypto -o x` on a Linux lab box.
