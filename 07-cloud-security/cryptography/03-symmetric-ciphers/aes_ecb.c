// AES-128-ECB with OpenSSL EVP, checked against the FIPS-197 vector.  cc aes_ecb.c -lcrypto -o aes_ecb && ./aes_ecb
#include<stdio.h>
#include<string.h>
#include<openssl/evp.h>

static void hex(const char *tag,const unsigned char *b,int n){
    printf("%s",tag);
    for(int i=0;i<n;i++) printf("%02x",b[i]);
    printf("\n");
}

int main(){
    unsigned char key[16],pt[16],ct[16],out[16];
    for(int i=0;i<16;i++){ key[i]=i; pt[i]=i*0x11; }   // 000102..0f  and  00112233..ff

    EVP_CIPHER_CTX *ctx=EVP_CIPHER_CTX_new();
    int len;

    EVP_EncryptInit_ex(ctx,EVP_aes_128_ecb(),NULL,key,NULL);
    EVP_CIPHER_CTX_set_padding(ctx,0);                  // one raw block, no PKCS pad
    EVP_EncryptUpdate(ctx,ct,&len,pt,16);
    EVP_EncryptFinal_ex(ctx,ct+len,&len);

    EVP_DecryptInit_ex(ctx,EVP_aes_128_ecb(),NULL,key,NULL);
    EVP_CIPHER_CTX_set_padding(ctx,0);
    EVP_DecryptUpdate(ctx,out,&len,ct,16);
    EVP_DecryptFinal_ex(ctx,out+len,&len);

    EVP_CIPHER_CTX_free(ctx);

    hex("key        : ",key,16);
    hex("plaintext  : ",pt,16);
    hex("ciphertext : ",ct,16);
    hex("decrypted  : ",out,16);

    const char *want="69c4e0d86a7b0430d8cdb78070b4c55a";
    char got[33];
    for(int i=0;i<16;i++) sprintf(got+2*i,"%02x",ct[i]);
    printf("FIPS-197   : %s\n", strcmp(got,want)==0 ? "MATCH" : "MISMATCH");
    printf("round trip : %s\n", memcmp(pt,out,16)==0 ? "ok" : "FAILED");
    return 0;
}
