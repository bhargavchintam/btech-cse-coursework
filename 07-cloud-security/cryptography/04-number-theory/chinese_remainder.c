// chinese remainder theorem - solve x = a[i] (mod m[i]).  cc chinese_remainder.c -o crt && ./crt
#include<stdio.h>

long long ext_gcd(long long a,long long b,long long *x,long long *y){
    if(b==0){ *x=1; *y=0; return a; }
    long long x1,y1;
    long long g=ext_gcd(b,a%b,&x1,&y1);
    *x=y1;
    *y=x1-(a/b)*y1;
    return g;
}

long long inv(long long a,long long m){
    long long x,y;
    ext_gcd(a,m,&x,&y);
    return (x%m+m)%m;
}

int main(){
    int k;
    printf("number of congruences: ");
    scanf("%d",&k);

    long long a[50],m[50],M=1;
    for(int i=0;i<k;i++){
        printf("a[%d] m[%d]: ",i,i);
        scanf("%lld %lld",&a[i],&m[i]);
        M*=m[i];
    }

    // x = sum( a[i] * Mi * (Mi^-1 mod m[i]) )  mod M,  where Mi = M/m[i]
    long long x=0;
    for(int i=0;i<k;i++){
        long long Mi=M/m[i];
        x=(x+a[i]%m[i]*Mi%M*inv(Mi%m[i],m[i]))%M;
    }
    x=(x%M+M)%M;
    printf("x = %lld (mod %lld)\n",x,M);
    return 0;
}
