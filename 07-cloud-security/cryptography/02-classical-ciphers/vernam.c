// vernam cipher / one-time pad (XOR).  cc vernam.c -o vernam && ./vernam
#include<stdio.h>
#include<string.h>

void vernam(char *s, char *key, char *out, int n){
    for(int i=0;i<n;i++)
        out[i] = s[i] ^ key[i];      // XOR is its own inverse
}

int main(){
    char msg[] = "HELLO";
    char key[] = "XMCKL";            // pad as long as the message, used once
    int n = strlen(msg);
    char ct[16], pt[16];

    vernam(msg, key, ct, n);
    printf("cipher(hex):");
    for(int i=0;i<n;i++) printf(" %02X", (unsigned char)ct[i]);
    printf("\n");

    vernam(ct, key, pt, n);
    pt[n] = '\0';
    printf("plain: %s\n", pt);
    return 0;
}
