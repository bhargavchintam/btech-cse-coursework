// rail fence cipher (zigzag, 3 rails).  cc rail_fence.c -o rail && ./rail
#include<stdio.h>
#include<string.h>

#define RAILS 3

void marks(int n, int *row){
    int r=0, dir=1;
    for(int i=0;i<n;i++){
        row[i]=r;
        if(r==0) dir=1;
        else if(r==RAILS-1) dir=-1;
        r+=dir;
    }
}

void encrypt(char *s, char *out){
    int n = strlen(s), row[256], k=0;
    marks(n, row);
    for(int rr=0; rr<RAILS; rr++)
        for(int i=0;i<n;i++)
            if(row[i]==rr) out[k++]=s[i];
    out[k]='\0';
}

void decrypt(char *s, char *out){
    int n = strlen(s), row[256], k=0;
    marks(n, row);
    for(int rr=0; rr<RAILS; rr++)
        for(int i=0;i<n;i++)
            if(row[i]==rr) out[i]=s[k++];
    out[n]='\0';
}

int main(){
    char msg[] = "WEAREDISCOVERED";
    char ct[128], pt[128];
    encrypt(msg, ct);
    printf("cipher: %s\n", ct);
    decrypt(ct, pt);
    printf("plain:  %s\n", pt);
    return 0;
}
