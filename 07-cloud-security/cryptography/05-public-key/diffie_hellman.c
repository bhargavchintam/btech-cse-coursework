// Diffie-Hellman key exchange.  cc diffie_hellman.c -o dh && ./dh
#include<stdio.h>

long long modexp(long long b,long long e,long long m){
    long long r=1;
    b%=m;
    while(e>0){
        if(e&1) r=(r*b)%m;
        b=(b*b)%m;
        e>>=1;
    }
    return r;
}

int main(){
    long long p=23,g=5;         // public: prime and its generator
    long long a=6,b=15;         // private keys, kept secret

    long long A=modexp(g,a,p);  // Alice sends A = g^a mod p
    long long B=modexp(g,b,p);  // Bob sends   B = g^b mod p

    long long s1=modexp(B,a,p); // Alice computes B^a mod p
    long long s2=modexp(A,b,p); // Bob computes   A^b mod p

    printf("p=%lld  g=%lld\n",p,g);
    printf("Alice: a=%lld -> A=%lld\n",a,A);
    printf("Bob:   b=%lld -> B=%lld\n",b,B);
    printf("Alice shared secret = %lld\n",s1);
    printf("Bob   shared secret = %lld\n",s2);
    printf("agree: %s\n", s1==s2 ? "yes" : "no");
    return 0;
}
