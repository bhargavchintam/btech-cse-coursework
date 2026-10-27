# Lab manual — Cryptography and Network Security

Every program in folders `02`–`07`, with its build line and one expected result.
Classical, number-theory and public-key programs are plain C; AES/DES/MD5/SHA/HMAC
and signatures use the OpenSSL EVP interface.

**Build:** plain C `cc file.c -o x`; OpenSSL `cc file.c -lcrypto -o x` (Linux lab box).
Run each in a scratch dir so no binaries land in the repo. Every cipher round-trips
(`decrypt(encrypt(x)) == x`); the demos print both directions.

## Part A — Classical ciphers  (`02-classical-ciphers/`)
| Program | Build & run | Expected result |
|---|---|---|
| `caesar.c` | `cc caesar.c -o caesar && ./caesar` | HELLO → KHOOR, back to HELLO |
| `monoalphabetic.c` | `cc monoalphabetic.c -o mono && ./mono` | HELLO → ITSSG (keyword alphabet) |
| `affine.c` | `cc affine.c -o affine && ./affine` | HELLO → RCLLA (a=5, b=8) |
| `atbash.c` | `cc atbash.c -o atbash && ./atbash` | HELLO → SVOOL (self-inverse) |
| `vigenere.c` | `cc vigenere.c -o vigenere && ./vigenere` | HELLO, key KEY → RIJVS |
| `vernam.c` | `cc vernam.c -o vernam && ./vernam` | HELLO → hex 10 08 0F 07 03 (XOR pad) |
| `playfair.c` | `cc playfair.c -o playfair && ./playfair` | INSTRUMENTSX → GATLMZCLRQXA |
| `hill_cipher.c` | `cc hill_cipher.c -o hill && ./hill` | HELP → HIAT (2×2 key mod 26) |
| `rail_fence.c` | `cc rail_fence.c -o rail && ./rail` | WEAREDISCOVERED → WECRERDSOEEAIVD |
| `row_column_transposition.c` | `cc row_column_transposition.c -o rct && ./rct` | …FLEEATONCE → EVLNXACDTXESEAXROFOXDEECXWIREE |

## Part B — Symmetric block ciphers  (`03-symmetric-ciphers/`)
| Program | Build & run | Expected result |
|---|---|---|
| `aes_ecb.c` | `cc aes_ecb.c -lcrypto -o aes_ecb && ./aes_ecb` | FIPS-197 → `69c4e0d86a7b0430d8cdb78070b4c55a` (MATCH) |
| `aes_cbc.c` | `cc aes_cbc.c -lcrypto -o aes_cbc && ./aes_cbc` | encrypt a sentence + decrypt, round trip ok |
| `des_cbc.c` | `cc des_cbc.c -lcrypto -o des_cbc && ./des_cbc` | DES-CBC encrypt + decrypt, round trip ok |

## Part C — Number theory  (`04-number-theory/`)
Each reads its inputs from stdin.
| Program | Build & run | Input → expected result |
|---|---|---|
| `gcd.c` | `cc gcd.c -o gcd && ./gcd` | `1071 462` → gcd = 21 |
| `extended_euclid.c` | `cc extended_euclid.c -o ee && ./ee` | `17 3120` → 17⁻¹ mod 3120 = 2753 |
| `mod_exp.c` | `cc mod_exp.c -o me && ./me` | `65 17 3233` → 65^17 mod 3233 = 2790 |
| `euler_totient.c` | `cc euler_totient.c -o et && ./et` | `3233` → phi = 3120 |
| `chinese_remainder.c` | `cc chinese_remainder.c -o crt && ./crt` | 2(3),3(5),2(7) → x = 23 (mod 105) |
| `primality_test.c` | `cc primality_test.c -o pt && ./pt` | `561` → composite; `97` → prime |

## Part D — Public-key cryptography  (`05-public-key/`)
| Program | Build & run | Expected result |
|---|---|---|
| `rsa.c` | `cc rsa.c -o rsa && ./rsa` | p=61,q=53,e=17 → n=3233, d=2753, enc(65)=2790, dec=65 |
| `diffie_hellman.c` | `cc diffie_hellman.c -o dh && ./dh` | p=23,g=5,a=6,b=15 → shared secret = 2 |
| `elgamal.c` | `cc elgamal.c -o elgamal && ./elgamal` | p=23,g=5,x=6,m=10 → (c1=10, c2=14), dec = 10 |

## Part E — Hashing & MAC  (`06-hash-functions/`, `07-message-auth/`)
| Program | Build & run | Expected result |
|---|---|---|
| `md5.c` | `cc md5.c -lcrypto -o md5 && ./md5` | MD5("abc") = `900150983cd24fb0d6963f7d28e17f72` |
| `sha256.c` | `cc sha256.c -lcrypto -o sha256 && ./sha256` | SHA-256("abc") = `ba7816bf…f20015ad` |
| `sha_family.c` | `cc sha_family.c -lcrypto -o sha_family && ./sha_family` | typed input → SHA-1/224/256/384/512, one line each |
| `hmac.c` | `cc hmac.c -lcrypto -o hmac && ./hmac` | HMAC-SHA256 = `131f3313…049a77` (key "secretkey") |
| `digital_signature.c` | `cc digital_signature.c -lcrypto -o digital_signature && ./digital_signature` | prints "signature valid"; tampered byte → rejected |
