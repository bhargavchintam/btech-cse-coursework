// lab 15 - RSA encryption and decryption with small primes
// build n = p*q and phi = (p-1)(q-1), pick e coprime to phi, and d as its inverse
// mod phi. each character is encrypted as c = m^e mod n and recovered with
// m = c^d mod n. primes are tiny here so it stays readable, not secure.
#include<iostream>
#include<string>
#include<vector>
using namespace std;

long long gcd(long long a, long long b){ return b ? gcd(b, a % b) : a; }

long long modpow(long long base, long long exp, long long mod)
{
    long long r = 1;
    base %= mod;
    while(exp > 0){
        if(exp & 1) r = (r * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return r;
}

int main()
{
    long long p = 61, q = 53;
    long long n = p * q;
    long long phi = (p - 1) * (q - 1);

    long long e = 17;
    while(gcd(e, phi) != 1) e++;

    long long d = 1;
    while((e * d) % phi != 1) d++;

    cout << "public key  (e,n) = (" << e << "," << n << ")\n";
    cout << "private key (d,n) = (" << d << "," << n << ")\n";

    string msg;
    cout << "enter message: ";
    getline(cin, msg);

    vector<long long> cipher;
    for(char c : msg) cipher.push_back(modpow((unsigned char)c, e, n));

    cout << "cipher:";
    for(long long c : cipher) cout << " " << c;
    cout << "\n";

    string dec;
    for(long long c : cipher) dec += (char)modpow(c, d, n);
    cout << "decrypted: " << dec << "\n";
    return 0;
}
