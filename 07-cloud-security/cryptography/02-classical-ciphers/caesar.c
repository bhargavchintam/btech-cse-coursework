// caesar cipher.  cc caesar.c -o caesar && ./caesar
#include<stdio.h>

void encrypt(char *s, int k){
    for(int i=0; s[i]; i++){
        if(s[i]>='A' && s[i]<='Z')
            s[i] = (s[i]-'A'+k)%26 + 'A';
        else if(s[i]>='a' && s[i]<='z')
            s[i] = (s[i]-'a'+k)%26 + 'a';
    }
}

void decrypt(char *s, int k){
    encrypt(s, 26-(k%26));
}

int main(){
    char msg[] = "HELLO";
    int shift = 3;
    encrypt(msg, shift);
    printf("cipher: %s\n", msg);   // KHOOR
    decrypt(msg, shift);
    printf("plain:  %s\n", msg);
    return 0;
}
