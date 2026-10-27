// vigenere cipher.  cc vigenere.c -o vigenere && ./vigenere
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void encrypt(char *s, char *key){
    int n = strlen(key);
    for(int i=0,j=0; s[i]; i++)
        if(isalpha(s[i])){
            int x = toupper(s[i]) - 'A';
            int k = toupper(key[j%n]) - 'A';
            s[i] = (x+k)%26 + 'A';
            j++;
        }
}

void decrypt(char *s, char *key){
    int n = strlen(key);
    for(int i=0,j=0; s[i]; i++)
        if(isalpha(s[i])){
            int x = toupper(s[i]) - 'A';
            int k = toupper(key[j%n]) - 'A';
            s[i] = (x-k+26)%26 + 'A';
            j++;
        }
}

int main(){
    char msg[] = "HELLO";
    char *key = "KEY";
    encrypt(msg, key);
    printf("cipher: %s\n", msg);   // RIJVS
    decrypt(msg, key);
    printf("plain:  %s\n", msg);
    return 0;
}
