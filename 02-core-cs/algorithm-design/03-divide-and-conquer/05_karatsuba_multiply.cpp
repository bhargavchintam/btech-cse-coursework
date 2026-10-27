// karatsuba - three half-size multiplies instead of four  => O(n^1.585)
#include<iostream>
using namespace std;

int numDigits(long long x)
{
    if (x == 0)
        return 1;
    int d = 0;
    while (x > 0) {
        d++;
        x /= 10;
    }
    return d;
}

long long powTen(int p)
{
    long long r = 1;
    for (int i = 0; i < p; i++)
        r *= 10;
    return r;
}

long long karatsuba(long long x, long long y)
{
    if (x < 10 || y < 10)
        return x * y;

    int n = numDigits(x);
    if (numDigits(y) > n)
        n = numDigits(y);
    int half = n / 2;
    long long p = powTen(half);

    long long a = x / p;      // high half of x
    long long b = x % p;      // low half of x
    long long c = y / p;
    long long d = y % p;

    long long ac = karatsuba(a, c);
    long long bd = karatsuba(b, d);
    long long adbc = karatsuba(a + b, c + d) - ac - bd;

    return ac * powTen(2 * half) + adbc * p + bd;
}

int main()
{
    long long x, y;
    cout << "Enter two integers: ";
    cin >> x >> y;

    long long k = karatsuba(x, y);
    long long normal = x * y;

    cout << "Karatsuba : " << k << endl;
    cout << "Normal    : " << normal << endl;
    if (k == normal)
        cout << "Match\n";
    else
        cout << "MISMATCH\n";
    return 0;
}
