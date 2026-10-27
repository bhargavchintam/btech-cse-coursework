// gcd of two numbers by euclid's algorithm.  cc gcd.c -o gcd && ./gcd
#include<stdio.h>

long long gcd(long long a,long long b){
    while(b){
        long long t=a%b;
        a=b;
        b=t;
    }
    return a<0?-a:a;
}

int main(){
    long long a,b;
    printf("enter two numbers: ");
    scanf("%lld %lld",&a,&b);
    printf("gcd(%lld,%lld) = %lld\n",a,b,gcd(a,b));
    if(gcd(a,b)==1)
        printf("%lld and %lld are coprime\n",a,b);
    return 0;
}
