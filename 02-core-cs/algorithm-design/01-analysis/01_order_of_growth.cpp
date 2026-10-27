// orders of growth - watch how fast each column climbs as n grows
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    cout << "  n    log n    n log n     n^2       n^3            2^n\n";
    long long p2 = 1;
    for (int n = 1; n <= 20; n++) {
        p2 *= 2;                       // 2^n
        double logn = log2(n);
        cout << setw(3) << n
             << setw(9) << fixed << setprecision(2) << logn
             << setw(11) << n * logn
             << setw(9) << n * n
             << setw(12) << n * n * n
             << setw(15) << p2 << "\n";
    }
    return 0;
}
