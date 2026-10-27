/* Bindu Bhargava   14-11-19 */
// rsa with small primes - keygen, encrypt and decrypt a message
#include<iostream>
#include<string>
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
    long long p = 61, q = 53;
    long long n = p * q;            // 3233
    long long phi = (p - 1) * (q - 1);
    long long e = 17;

    // d = inverse of e mod phi, small enough to just search
    long long d = 0;
    for (long long i = 1; i < phi; i++)
        if (e * i % phi == 1) { d = i; break; }

    cout << "public key  (e,n) = (" << e << "," << n << ")\n";
    cout << "private key (d,n) = (" << d << "," << n << ")\n";

    string msg;
    cout << "Enter message: ";
    getline(cin, msg);

    cout << "cipher: ";
    long long cipher[200];
    for (int i = 0; i < (int)msg.size(); i++) {
        cipher[i] = modpow((long long)msg[i], e, n);
        cout << cipher[i] << " ";
    }
    cout << "\n";

    cout << "decrypted: ";
    for (int i = 0; i < (int)msg.size(); i++)
        cout << (char)modpow(cipher[i], d, n);
    cout << "\n";
    return 0;
}
