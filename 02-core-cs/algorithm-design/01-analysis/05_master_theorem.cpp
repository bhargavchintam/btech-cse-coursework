// master theorem classifier for T(n) = a T(n/b) + n^d
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    double a, b, d;
    cout << "T(n) = a T(n/b) + n^d\n";
    cout << "Enter a, b, d: ";
    cin >> a >> b >> d;

    double e = log(a) / log(b);        // log_b(a)
    cout << "log_b(a) = " << e << endl;

    if (d < e - 1e-9)
        cout << "Case 1: d < log_b(a)  =>  T(n) = Theta(n^" << e << ")\n";
    else if (fabs(d - e) <= 1e-9)
        cout << "Case 2: d = log_b(a)  =>  T(n) = Theta(n^" << d << " log n)\n";
    else
        cout << "Case 3: d > log_b(a)  =>  T(n) = Theta(n^" << d << ")\n";
    return 0;
}
