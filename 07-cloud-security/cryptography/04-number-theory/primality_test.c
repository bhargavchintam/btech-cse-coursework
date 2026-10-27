// miller-rabin primality test.  cc primality_test.c -o pt && ./pt
#include<stdio.h>

long long mod_exp(long long a,long long e,long long m){
    long long r=1;
    a%=m;
    while(e>0){
        if(e&1) r=(r*a)%m;
        a=(a*a)%m;
        e>>=1;
    }
    return r;
}

// one round: returns 1 if a proves n composite
int witness(long long a,long long n,long long d,int s){
    long long x=mod_exp(a,d,n);
    if(x==1||x==n-1) return 0;
    for(int i=0;i<s-1;i++){
        x=(x*x)%n;
        if(x==n-1) return 0;
    }
    return 1;
}

int is_prime(long long n){
    if(n<2) return 0;
    if(n<4) return 1;
    if(n%2==0) return 0;

    long long d=n-1;
    int s=0;
    while(d%2==0){ d/=2; s++; }

    // these bases are deterministic for every n that fits in long long
    long long base[]={2,3,5,7,11,13,17,19,23,29,31,37};
    for(int i=0;i<12;i++){
        if(base[i]%n==0) continue;
        if(witness(base[i],n,d,s)) return 0;
    }
    return 1;
}

int main(){
    long long n;
    printf("n: ");
    scanf("%lld",&n);
    printf("%lld is %s\n",n,is_prime(n)?"prime":"composite");
    return 0;
}
