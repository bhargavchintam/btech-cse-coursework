// HMAC-SHA256 of a message with a key, OpenSSL.  cc hmac.c -lcrypto -o hmac && ./hmac
#include<stdio.h>
#include<string.h>
#include<openssl/hmac.h>

int main(){
    char key[]="secretkey";
    char msg[]="Hello HMAC";
    unsigned char mac[EVP_MAX_MD_SIZE];
    unsigned int len;

    HMAC(EVP_sha256(),key,strlen(key),(unsigned char*)msg,strlen(msg),mac,&len);

    printf("key = %s\n",key);
    printf("msg = %s\n",msg);
    printf("HMAC-SHA256 = ");
    for(unsigned int i=0;i<len;i++) printf("%02x",mac[i]);
    printf("\n");
    return 0;
}
