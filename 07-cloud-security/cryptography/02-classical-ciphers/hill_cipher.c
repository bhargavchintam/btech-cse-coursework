// hill cipher, 2x2 key mod 26.  cc hill_cipher.c -o hill && ./hill
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int key[2][2] = {{3,3},{2,5}};       // det = 9, invertible mod 26

int modinv(int a, int m){
    a = ((a%m)+m)%m;
    for(int x=1;x<m;x++)
        if((a*x)%m==1) return x;
    return -1;
}

void inverse(int k[2][2], int inv[2][2]){
    int det = ((k[0][0]*k[1][1] - k[0][1]*k[1][0])%26 + 26)%26;
    int di = modinv(det,26);
    inv[0][0] = ( k[1][1]*di)%26;
    inv[0][1] = ((-k[0][1]%26+26)*di)%26;
    inv[1][0] = ((-k[1][0]%26+26)*di)%26;
    inv[1][1] = ( k[0][0]*di)%26;
}

void apply(int k[2][2], char *s, char *out){
    int n = strlen(s);
    for(int i=0;i<n;i+=2){
        int a = s[i]-'A';
        int b = s[i+1]-'A';
        out[i]   = (k[0][0]*a + k[0][1]*b)%26 + 'A';
        out[i+1] = (k[1][0]*a + k[1][1]*b)%26 + 'A';
    }
    out[n]='\0';
}

int main(){
    char msg[] = "HELP";           // even length, already A-Z
    char ct[64], pt[64];
    int inv[2][2];

    apply(key, msg, ct);
    printf("cipher: %s\n", ct);    // HIAT

    inverse(key, inv);
    apply(inv, ct, pt);
    printf("plain:  %s\n", pt);
    return 0;
}
