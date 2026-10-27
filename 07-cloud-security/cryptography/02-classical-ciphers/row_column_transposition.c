// columnar transposition cipher with a keyword.  cc row_column_transposition.c -o rct && ./rct
#include<stdio.h>
#include<string.h>

char key[] = "ZEBRAS";

// rank[c] = read order of column c (alphabetical, ties broken left to right)
void colrank(char *k, int *rank){
    int n = strlen(k);
    for(int i=0;i<n;i++){
        int r=0;
        for(int j=0;j<n;j++)
            if(k[j]<k[i] || (k[j]==k[i] && j<i)) r++;
        rank[i]=r;
    }
}

void encrypt(char *s, char *out){
    int cols = strlen(key), n = strlen(s);
    int rows = (n+cols-1)/cols;
    char grid[64][64];
    int rank[64], idx=0, k=0;
    for(int r=0;r<rows;r++)
        for(int c=0;c<cols;c++)
            grid[r][c] = (idx<n) ? s[idx++] : 'X';
    colrank(key, rank);
    for(int want=0; want<cols; want++)
        for(int c=0;c<cols;c++)
            if(rank[c]==want)
                for(int r=0;r<rows;r++)
                    out[k++]=grid[r][c];
    out[k]='\0';
}

void decrypt(char *s, char *out){
    int cols = strlen(key), n = strlen(s);
    int rows = (n+cols-1)/cols;
    char grid[64][64];
    int rank[64], k=0, idx=0;
    colrank(key, rank);
    for(int want=0; want<cols; want++)
        for(int c=0;c<cols;c++)
            if(rank[c]==want)
                for(int r=0;r<rows;r++)
                    grid[r][c]=s[k++];
    for(int r=0;r<rows;r++)
        for(int c=0;c<cols;c++)
            out[idx++]=grid[r][c];
    out[idx]='\0';
}

int main(){
    char msg[] = "WEAREDISCOVEREDFLEEATONCE";
    char ct[128], pt[128];
    encrypt(msg, ct);
    printf("cipher: %s\n", ct);
    decrypt(ct, pt);
    printf("plain:  %s\n", pt);   // trailing X are padding to fill the grid
    return 0;
}
