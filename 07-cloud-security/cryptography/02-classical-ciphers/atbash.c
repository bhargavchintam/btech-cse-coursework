// atbash cipher (A<->Z, self-inverse).  cc atbash.c -o atbash && ./atbash
#include<stdio.h>

void code(char *s){
    for(int i=0; s[i]; i++){
        if(s[i]>='A' && s[i]<='Z') s[i] = 'Z' - (s[i]-'A');
        else if(s[i]>='a' && s[i]<='z') s[i] = 'z' - (s[i]-'a');
    }
}

void encrypt(char *s){ code(s); }
void decrypt(char *s){ code(s); }

int main(){
    char msg[] = "HELLO";
    encrypt(msg);
    printf("cipher: %s\n", msg);   // SVOOL
    decrypt(msg);
    printf("plain:  %s\n", msg);
    return 0;
}
