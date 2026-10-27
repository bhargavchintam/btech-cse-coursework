// diffie-hellman key exchange - both sides end up with the same secret
#include<iostream>
using namespace std;

long long modpow(long long b, long long e, long long m)
{
    long long r = 1;
    b %= m;
    while (e > 0) {
        if (e & 1) r = r * b % m;
        b = b * b % m;
        e >>= 1;
    }
    return r;
}

int main()
{
    long long p, g, a, b;
    cout << "Enter prime p and primitive root g: ";
    cin >> p >> g;
    cout << "Enter Alice private a and Bob private b: ";
    cin >> a >> b;

    long long A = modpow(g, a, p);      // Alice sends A
    long long B = modpow(g, b, p);      // Bob sends B

    long long s1 = modpow(B, a, p);
    long long s2 = modpow(A, b, p);

    cout << "Alice public A = " << A << "\n";
    cout << "Bob   public B = " << B << "\n";
    cout << "Alice secret = " << s1 << "\n";
    cout << "Bob   secret = " << s2 << "\n";
    cout << (s1 == s2 ? "shared key established\n" : "mismatch!\n");
    return 0;
}
