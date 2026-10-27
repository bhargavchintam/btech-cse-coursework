/* Bindu Bhargava   28-01-19 */
// russian peasant multiplication - halve one number, double the other (decrease by factor 2)
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    int n = a, m = b;
    long long result = 0;
    cout << "   n     m\n";
    while (n >= 1) {
        cout << setw(4) << n << setw(6) << m;
        if (n % 2 == 1) {              // odd row contributes to the answer
            result += m;
            cout << "  +";
        }
        cout << "\n";
        n = n / 2;
        m = m * 2;
    }

    cout << a << " * " << b << " = " << result << endl;
    cout << "check (a*b)   = " << (long long)a * b << endl;
    return 0;
}
