// SHA-256 of a string with OpenSSL EVP.  cc sha256.c -lcrypto -o sha256 && ./sha256
#include<stdio.h>
#include<string.h>
#include<openssl/evp.h>

int main(){
    char msg[]="abc";
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int len;

    EVP_MD_CTX *ctx=EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx,EVP_sha256(),NULL);
    EVP_DigestUpdate(ctx,msg,strlen(msg));
    EVP_DigestFinal_ex(ctx,digest,&len);
    EVP_MD_CTX_free(ctx);

    printf("SHA-256(\"%s\") = ",msg);
    for(unsigned int i=0;i<len;i++) printf("%02x",digest[i]);
    printf("\n");
    return 0;
}
