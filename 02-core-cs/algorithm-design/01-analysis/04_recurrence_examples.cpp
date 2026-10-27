// unfold two recurrences by iteration and print T(n)
#include<iostream>
#include<iomanip>
using namespace std;

// T(n) = T(n-1) + n,  T(0) = 0
long long rec1(int n)
{
    long long t = 0;
    for (int i = 1; i <= n; i++)
        t = t + i;
    return t;
}

// T(n) = 2T(n/2) + n,  T(1) = 1   built bottom up on powers of 2
long long rec2(int n)
{
    long long t = 1;
    for (int size = 2; size <= n; size *= 2)
        t = 2 * t + size;
    return t;
}

int main()
{
    cout << "T(n) = T(n-1) + n,  T(0)=0     [expect n(n+1)/2, Theta(n^2)]\n";
    cout << "  n      T(n)\n";
    for (int n = 0; n <= 10; n++)
        cout << setw(3) << n << setw(10) << rec1(n) << "\n";

    cout << "\nT(n) = 2T(n/2) + n,  T(1)=1    [expect n + n log2 n, Theta(n log n)]\n";
    cout << "  n      T(n)\n";
    for (int n = 1; n <= 64; n *= 2)
        cout << setw(3) << n << setw(10) << rec2(n) << "\n";
    return 0;
}
