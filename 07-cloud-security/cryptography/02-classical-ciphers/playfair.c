// playfair cipher (5x5 square, I/J merged).  cc playfair.c -o playfair && ./playfair
#include<stdio.h>
#include<string.h>
#include<ctype.h>

char mat[5][5];

void build(char *key){
    int used[26] = {0};
    used['J'-'A'] = 1;                 // skip J, merge with I
    int r=0, c=0;
    for(int i=0; key[i]; i++){
        if(!isalpha(key[i])) continue;
        char ch = toupper(key[i]);
        if(ch=='J') ch='I';
        if(!used[ch-'A']){
            used[ch-'A']=1;
            mat[r][c++]=ch;
            if(c==5){c=0;r++;}
        }
    }
    for(char ch='A'; ch<='Z'; ch++)
        if(!used[ch-'A']){
            used[ch-'A']=1;
            mat[r][c++]=ch;
            if(c==5){c=0;r++;}
        }
}

void findpos(char ch, int *r, int *c){
    if(ch=='J') ch='I';
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(mat[i][j]==ch){ *r=i; *c=j; return; }
}

// clean to A-Z, split double letters with X, pad odd tail with X
int prepare(char *s, char *out){
    char clean[256]; int m=0;
    for(int i=0; s[i]; i++)
        if(isalpha(s[i])){
            char ch = toupper(s[i]);
            clean[m++] = (ch=='J') ? 'I' : ch;
        }
    int k=0;
    for(int i=0;i<m;){
        char a = clean[i];
        char b = (i+1<m) ? clean[i+1] : 'X';
        if(a==b){ out[k++]=a; out[k++]='X'; i++; }
        else    { out[k++]=a; out[k++]=b; i+=2; }
    }
    if(k%2) out[k++]='X';
    out[k]='\0';
    return k;
}

void encrypt(char *s, char *out){
    int n = prepare(s, out);
    for(int i=0;i<n;i+=2){
        int r1,c1,r2,c2;
        findpos(out[i],&r1,&c1);
        findpos(out[i+1],&r2,&c2);
        if(r1==r2){
            out[i]  = mat[r1][(c1+1)%5];
            out[i+1]= mat[r2][(c2+1)%5];
        } else if(c1==c2){
            out[i]  = mat[(r1+1)%5][c1];
            out[i+1]= mat[(r2+1)%5][c2];
        } else {
            out[i]  = mat[r1][c2];
            out[i+1]= mat[r2][c1];
        }
    }
}

void decrypt(char *s, char *out){
    strcpy(out, s);
    int n = strlen(out);
    for(int i=0;i<n;i+=2){
        int r1,c1,r2,c2;
        findpos(out[i],&r1,&c1);
        findpos(out[i+1],&r2,&c2);
        if(r1==r2){
            out[i]  = mat[r1][(c1+4)%5];
            out[i+1]= mat[r2][(c2+4)%5];
        } else if(c1==c2){
            out[i]  = mat[(r1+4)%5][c1];
            out[i+1]= mat[(r2+4)%5][c2];
        } else {
            out[i]  = mat[r1][c2];
            out[i+1]= mat[r2][c1];
        }
    }
}

int main(){
    build("MONARCHY");
    char msg[] = "INSTRUMENTS";
    char ct[256], pt[256];
    encrypt(msg, ct);
    printf("cipher: %s\n", ct);
    decrypt(ct, pt);
    printf("plain:  %s\n", pt);     // INSTRUMENTSX (trailing X is padding)
    return 0;
}
