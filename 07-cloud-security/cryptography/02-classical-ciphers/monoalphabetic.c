// monoalphabetic substitution cipher.  cc monoalphabetic.c -o mono && ./mono
#include<stdio.h>
#include<ctype.h>

char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

void encrypt(char *s){
    for(int i=0; s[i]; i++)
        if(isalpha(s[i]))
            s[i] = key[toupper(s[i])-'A'];
}

void decrypt(char *s){
    for(int i=0; s[i]; i++)
        if(isalpha(s[i])){
            char c = toupper(s[i]);
            for(int j=0;j<26;j++)
                if(key[j]==c){ s[i]='A'+j; break; }
        }
}

int main(){
    char msg[] = "HELLO";
    encrypt(msg);
    printf("cipher: %s\n", msg);
    decrypt(msg);
    printf("plain:  %s\n", msg);
    return 0;
}
