// RSA sign a message and verify it, OpenSSL EVP.  cc digital_signature.c -lcrypto -o digital_signature && ./digital_signature
#include<stdio.h>
#include<string.h>
#include<openssl/evp.h>
#include<openssl/rsa.h>

int main(){
    char msg[]="transfer 1000 to alice";

    EVP_PKEY *key=EVP_RSA_gen(2048);
    if(!key){ printf("keygen failed\n"); return 1; }

    unsigned char sig[512];
    size_t siglen=sizeof sig;

    // sign the SHA-256 digest of msg with the private key
    EVP_MD_CTX *ctx=EVP_MD_CTX_new();
    EVP_DigestSignInit(ctx,NULL,EVP_sha256(),NULL,key);
    EVP_DigestSign(ctx,sig,&siglen,(unsigned char*)msg,strlen(msg));
    EVP_MD_CTX_free(ctx);

    printf("message   : %s\n",msg);
    printf("signature : ");
    for(size_t i=0;i<12;i++) printf("%02x",sig[i]);
    printf("... (%zu bytes)\n",siglen);

    // verify with the public key
    ctx=EVP_MD_CTX_new();
    EVP_DigestVerifyInit(ctx,NULL,EVP_sha256(),NULL,key);
    int ok=EVP_DigestVerify(ctx,sig,siglen,(unsigned char*)msg,strlen(msg));
    EVP_MD_CTX_free(ctx);
    printf(ok==1?"signature valid\n":"signature INVALID\n");

    // tamper: a single changed byte must break verification
    msg[0]='T';
    ctx=EVP_MD_CTX_new();
    EVP_DigestVerifyInit(ctx,NULL,EVP_sha256(),NULL,key);
    int bad=EVP_DigestVerify(ctx,sig,siglen,(unsigned char*)msg,strlen(msg));
    EVP_MD_CTX_free(ctx);
    printf("after tampering: %s\n",bad==1?"valid":"rejected");

    EVP_PKEY_free(key);
    return 0;
}
