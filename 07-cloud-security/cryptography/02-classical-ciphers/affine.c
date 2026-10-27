// affine cipher c=(a*x+b) mod 26.  cc affine.c -o affine && ./affine
#include<stdio.h>
#include<ctype.h>

int modinv(int a, int m){
    a %= m;
    for(int x=1;x<m;x++)
        if((a*x)%m==1) return x;
    return -1;
}

void encrypt(char *s, int a, int b){
    for(int i=0; s[i]; i++)
        if(isalpha(s[i])){
            int x = toupper(s[i]) - 'A';
            s[i] = (a*x+b)%26 + 'A';
        }
}

void decrypt(char *s, int a, int b){
    int ai = modinv(a,26);
    for(int i=0; s[i]; i++)
        if(isalpha(s[i])){
            int c = toupper(s[i]) - 'A';
            int x = (ai*((c-b)%26+26))%26;
            s[i] = x + 'A';
        }
}

int main(){
    char msg[] = "HELLO";
    int a=5, b=8;                  // a must be coprime with 26
    encrypt(msg, a, b);
    printf("cipher: %s\n", msg);   // RCLLA
    decrypt(msg, a, b);
    printf("plain:  %s\n", msg);
    return 0;
}
