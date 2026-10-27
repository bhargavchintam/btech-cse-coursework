// extended euclid: gcd plus the modular inverse of a mod m.  cc extended_euclid.c -o ee && ./ee
#include<stdio.h>

long long x,y;

// a*x + b*y = gcd(a,b); leaves the coefficients in globals x,y
long long ext_gcd(long long a,long long b){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    long long g=ext_gcd(b,a%b);
    long long nx=y;
    long long ny=x-(a/b)*y;
    x=nx;
    y=ny;
    return g;
}

int main(){
    long long a,m;
    printf("a and m: ");
    scanf("%lld %lld",&a,&m);

    long long g=ext_gcd(a,m);
    printf("gcd = %lld   (%lld*%lld + %lld*%lld = %lld)\n",g,a,x,m,y,g);

    if(g!=1)
        printf("inverse of %lld mod %lld does not exist (not coprime)\n",a,m);
    else{
        long long inv=(x%m+m)%m;
        printf("inverse of %lld mod %lld = %lld\n",a,m,inv);
    }
    return 0;
}
