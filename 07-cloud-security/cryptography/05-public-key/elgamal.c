// ElGamal encryption from scratch.  cc elgamal.c -o elgamal && ./elgamal
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
    long long p=23,g=5;             // public prime and generator
    long long x=6;                  // private key
    long long y=modexp(g,x,p);      // public key  y = g^x mod p

    long long m=10;                 // message, must be < p
    long long k=3;                  // ephemeral key, fresh per message

    long long c1=modexp(g,k,p);         // c1 = g^k mod p
    long long c2=(m*modexp(y,k,p))%p;   // c2 = m*y^k mod p

    long long s=modexp(c1,x,p);         // shared s = c1^x mod p
    long long sinv=modexp(s,p-2,p);     // s^-1 = s^(p-2) mod p  (Fermat, p prime)
    long long dec=(c2*sinv)%p;          // m = c2 * s^-1 mod p

    printf("p=%lld  g=%lld  y=%lld\n",p,g,y);
    printf("message    = %lld\n",m);
    printf("cipher     = (c1=%lld, c2=%lld)\n",c1,c2);
    printf("decrypted  = %lld\n",dec);
    printf("match: %s\n", dec==m ? "yes" : "no");
    return 0;
}
