// Horner's rule vs naive evaluation - same polynomial, far fewer multiplications
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int deg;
    cout << "Enter degree of polynomial: ";
    cin >> deg;
    vector<long long> c(deg + 1);      // c[0] is coeff of highest power
    cout << "Enter " << deg + 1 << " coefficients, highest power first\n";
    for (int i = 0; i <= deg; i++)
        cin >> c[i];

    long long x;
    cout << "Enter x: ";
    cin >> x;

    long long horner = 0;
    int hmul = 0;
    for (int i = 0; i <= deg; i++) {
        horner = horner * x + c[i];
        if (i > 0) hmul++;             // one multiply per fold, none on the first coeff
    }

    long long naive = 0;
    int nmul = 0;
    for (int i = 0; i <= deg; i++) {
        int power = deg - i;
        long long term = c[i];
        for (int k = 0; k < power; k++) {
            term *= x;
            nmul++;
        }
        naive += term;
    }

    cout << "Horner  value = " << horner << "   multiplications = " << hmul << endl;
    cout << "naive   value = " << naive  << "   multiplications = " << nmul << endl;
    return 0;
}
