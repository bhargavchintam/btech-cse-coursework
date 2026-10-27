// RSA from scratch.  cc rsa.c -o rsa && ./rsa
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

long long gcd(long long a,long long b){
    while(b){ long long t=a%b; a=b; b=t; }
    return a;
}

// d = e^-1 mod phi, by extended euclid
long long modinv(long long e,long long phi){
    long long t=0,nt=1,r=phi,nr=e;
    while(nr){
        long long q=r/nr;
        long long tmp=t-q*nt; t=nt; nt=tmp;
        tmp=r-q*nr; r=nr; nr=tmp;
    }
    if(t<0) t+=phi;
    return t;
}

int main(){
    long long p=61,q=53;
    long long n=p*q;
    long long phi=(p-1)*(q-1);

    long long e=17;                 // 1<e<phi, gcd(e,phi)=1
    if(gcd(e,phi)!=1){
        printf("e not coprime with phi\n");
        return 1;
    }
    long long d=modinv(e,phi);

    printf("p=%lld  q=%lld\n",p,q);
    printf("n=%lld  phi=%lld\n",n,phi);
    printf("public  key (e,n) = (%lld,%lld)\n",e,n);
    printf("private key (d,n) = (%lld,%lld)\n",d,n);

    long long m=65;
    long long c=modexp(m,e,n);      // c = m^e mod n
    long long dec=modexp(c,d,n);    // m = c^d mod n

    printf("plaintext  = %lld\n",m);
    printf("ciphertext = %lld\n",c);
    printf("decrypted  = %lld\n",dec);
    return 0;
}
