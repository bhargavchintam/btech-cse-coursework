// fast modular exponentiation by square-and-multiply.  cc mod_exp.c -o me && ./me
#include<stdio.h>

long long mod_exp(long long base,long long exp,long long m){
    long long r=1;
    base%=m;
    while(exp>0){
        if(exp&1)           // c = (m^e) mod n, bit by bit
            r=(r*base)%m;
        base=(base*base)%m;
        exp>>=1;
    }
    return r;
}

int main(){
    long long b,e,m;
    printf("base exp mod: ");
    scanf("%lld %lld %lld",&b,&e,&m);
    printf("%lld^%lld mod %lld = %lld\n",b,e,m,mod_exp(b,e,m));
    return 0;
}
