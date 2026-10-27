// AES-128-CBC with OpenSSL EVP: encrypt a string then decrypt it back.  cc aes_cbc.c -lcrypto -o aes_cbc && ./aes_cbc
#include<stdio.h>
#include<string.h>
#include<openssl/evp.h>

static void hex(const char *tag,const unsigned char *b,int n){
    printf("%s",tag);
    for(int i=0;i<n;i++) printf("%02x",b[i]);
    printf("\n");
}

int main(){
    unsigned char key[16]="0123456789abcdef";
    unsigned char iv[16] ="initvector__1234";
    const char *msg="Meet me at the old bridge at dawn.";
    int mlen=strlen(msg);

    unsigned char ct[128],pt[128];
    int len,ctlen;

    EVP_CIPHER_CTX *ctx=EVP_CIPHER_CTX_new();

    EVP_EncryptInit_ex(ctx,EVP_aes_128_cbc(),NULL,key,iv);
    EVP_EncryptUpdate(ctx,ct,&len,(unsigned char*)msg,mlen);
    ctlen=len;
    EVP_EncryptFinal_ex(ctx,ct+len,&len);              // flushes the last padded block
    ctlen+=len;

    EVP_DecryptInit_ex(ctx,EVP_aes_128_cbc(),NULL,key,iv);
    EVP_DecryptUpdate(ctx,pt,&len,ct,ctlen);
    int ptlen=len;
    EVP_DecryptFinal_ex(ctx,pt+len,&len);
    ptlen+=len;
    pt[ptlen]='\0';

    EVP_CIPHER_CTX_free(ctx);

    printf("plaintext  : %s\n",msg);
    hex("key        : ",key,16);
    hex("iv         : ",iv,16);
    hex("ciphertext : ",ct,ctlen);
    printf("decrypted  : %s\n",pt);
    printf("round trip : %s\n", strcmp(msg,(char*)pt)==0 ? "ok" : "FAILED");
    return 0;
}
