// MD5 of a string with OpenSSL EVP.  cc md5.c -lcrypto -o md5 && ./md5
#include<stdio.h>
#include<string.h>
#include<openssl/evp.h>

int main(){
    char msg[]="abc";
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int len;

    EVP_MD_CTX *ctx=EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx,EVP_md5(),NULL);
    EVP_DigestUpdate(ctx,msg,strlen(msg));
    EVP_DigestFinal_ex(ctx,digest,&len);
    EVP_MD_CTX_free(ctx);

    printf("MD5(\"%s\") = ",msg);
    for(unsigned int i=0;i<len;i++) printf("%02x",digest[i]);
    printf("\n");
    printf("digest is %u bytes (%u bits)\n",len,len*8);
    return 0;
}
