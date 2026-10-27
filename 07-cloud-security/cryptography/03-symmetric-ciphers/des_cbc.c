// DES-CBC with OpenSSL EVP: encrypt a string then decrypt it back.  cc des_cbc.c -lcrypto -o des_cbc && ./des_cbc
#include<stdio.h>
#include<string.h>
#include<openssl/evp.h>
#include<openssl/provider.h>

static void hex(const char *tag,const unsigned char *b,int n){
    printf("%s",tag);
    for(int i=0;i<n;i++) printf("%02x",b[i]);
    printf("\n");
}

int main(){
    OSSL_PROVIDER_load(NULL,"legacy");   // single DES lives in the legacy provider on OpenSSL 3.x
    OSSL_PROVIDER_load(NULL,"default");

    unsigned char key[8]={0x13,0x34,0x57,0x79,0x9b,0xbc,0xdf,0xf1};  // 56 usable bits, 8th of each byte is parity
    unsigned char iv[8] ={0,1,2,3,4,5,6,7};
    const char *msg="DES uses a 64-bit block.";
    int mlen=strlen(msg);

    unsigned char ct[128],pt[128];
    int len,ctlen;

    EVP_CIPHER_CTX *ctx=EVP_CIPHER_CTX_new();

    EVP_EncryptInit_ex(ctx,EVP_des_cbc(),NULL,key,iv);
    EVP_EncryptUpdate(ctx,ct,&len,(unsigned char*)msg,mlen);
    ctlen=len;
    EVP_EncryptFinal_ex(ctx,ct+len,&len);
    ctlen+=len;

    EVP_DecryptInit_ex(ctx,EVP_des_cbc(),NULL,key,iv);
    EVP_DecryptUpdate(ctx,pt,&len,ct,ctlen);
    int ptlen=len;
    EVP_DecryptFinal_ex(ctx,pt+len,&len);
    ptlen+=len;
    pt[ptlen]='\0';

    EVP_CIPHER_CTX_free(ctx);

    printf("plaintext  : %s\n",msg);
    hex("key        : ",key,8);
    hex("iv         : ",iv,8);
    hex("ciphertext : ",ct,ctlen);
    printf("decrypted  : %s\n",pt);
    printf("round trip : %s\n", strcmp(msg,(char*)pt)==0 ? "ok" : "FAILED");
    return 0;
}
