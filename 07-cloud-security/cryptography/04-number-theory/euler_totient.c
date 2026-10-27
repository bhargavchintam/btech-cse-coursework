// euler's totient phi(n) by prime factorisation.  cc euler_totient.c -o et && ./et
#include<stdio.h>

long long phi(long long n){
    long long result=n;
    for(long long p=2;p*p<=n;p++){
        if(n%p==0){
            while(n%p==0)
                n/=p;
            result-=result/p;   // result *= (1 - 1/p)
        }
    }
    if(n>1)
        result-=result/n;       // leftover prime factor
    return result;
}

int main(){
    long long n;
    printf("n: ");
    scanf("%lld",&n);
    printf("phi(%lld) = %lld\n",n,phi(n));
    return 0;
}
