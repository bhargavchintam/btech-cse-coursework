// SHA-1/224/256/384/512 of an input string, OpenSSL EVP.  cc sha_family.c -lcrypto -o sha_family && ./sha_family
#include<stdio.h>
#include<string.h>
#include<openssl/evp.h>

void digest(const EVP_MD *md,const char *name,const char *msg){
    unsigned char out[EVP_MAX_MD_SIZE];
    unsigned int len;
    EVP_MD_CTX *ctx=EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx,md,NULL);
    EVP_DigestUpdate(ctx,msg,strlen(msg));
    EVP_DigestFinal_ex(ctx,out,&len);
    EVP_MD_CTX_free(ctx);

    printf("%-8s (%3u-bit) ",name,len*8);
    for(unsigned int i=0;i<len;i++) printf("%02x",out[i]);
    printf("\n");
}

int main(){
    char msg[256];
    printf("enter text: ");
    if(!fgets(msg,sizeof msg,stdin)) return 1;
    msg[strcspn(msg,"\n")]=0;

    digest(EVP_sha1(),"SHA-1",msg);
    digest(EVP_sha224(),"SHA-224",msg);
    digest(EVP_sha256(),"SHA-256",msg);
    digest(EVP_sha384(),"SHA-384",msg);
    digest(EVP_sha512(),"SHA-512",msg);
    return 0;
}
