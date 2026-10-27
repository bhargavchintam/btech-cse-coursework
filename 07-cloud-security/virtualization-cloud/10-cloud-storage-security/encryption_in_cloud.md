# Encryption in cloud

**Definition:** encryption = converting **plaintext** into **ciphertext** using an algorithm + key, so only someone with the key can read it. Main tool for confidentiality of cloud data.

## Two types
- **Symmetric** — same key to encrypt and decrypt. Fast, used for bulk data. e.g. **AES** (AES-256 common).
- **Asymmetric** — key pair: **public key** encrypts, **private key** decrypts. Slower, used for key exchange, signatures. e.g. **RSA**.

Common pattern: use asymmetric to exchange a symmetric key, then symmetric for the actual data.

## Encrypt data in every state
- **at rest** — data stored on disk/storage → encrypt with AES-256. e.g. S3 server-side encryption, EBS encryption.
- **in transit** — data moving over network → **TLS/SSL** (HTTPS).
- **in use** — data in memory while processed → hardest, uses secure enclaves.

## Who does the encryption (at rest)
- **Server-side encryption (SSE)** — provider encrypts data as it's written.
  - **SSE-S3** — provider manages the keys entirely.
  - **SSE-KMS** — keys managed in a Key Management Service, more control + audit.
- **Client-side encryption** — you encrypt *before* uploading; provider never sees plaintext. Most control.

## Key management (critical)
- Encryption is only as strong as **key protection**. If key leaks, encryption is useless.
- Use a **KMS (Key Management Service)** — e.g. **AWS KMS** — to create, store, rotate keys.
- **rotate keys** regularly, never hardcode keys in code/repos.
- consider **HSM** (Hardware Security Module) for high-security keys.

## Quick table

| Aspect | Detail |
|--------|--------|
| Symmetric | one key, fast, AES-256, bulk data |
| Asymmetric | key pair, slower, RSA, key exchange |
| At rest | AES-256, SSE-S3 / SSE-KMS / client-side |
| In transit | TLS / SSL (HTTPS) |
| Key management | KMS, rotate, HSM, never hardcode |

Exam line: encryption protects confidentiality, but **key management** is what actually makes it secure.
