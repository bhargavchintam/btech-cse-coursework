// Gaussian elimination with partial pivoting - reduce to upper triangular, back substitute
#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of equations: ";
    cin >> n;
    vector<vector<double>> a(n, vector<double>(n + 1));   // augmented matrix [A | b]
    cout << "Enter each row: " << n << " coefficients then the rhs\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            cin >> a[i][j];

    for (int col = 0; col < n; col++) {
        int piv = col;                 // partial pivoting - biggest |value| in this column
        for (int r = col + 1; r < n; r++)
            if (fabs(a[r][col]) > fabs(a[piv][col]))
                piv = r;
        swap(a[col], a[piv]);

        if (fabs(a[col][col]) < 1e-12) {
            cout << "no unique solution (singular matrix)\n";
            return 0;
        }

        for (int r = col + 1; r < n; r++) {
            double factor = a[r][col] / a[col][col];
            for (int j = col; j <= n; j++)
                a[r][j] -= factor * a[col][j];
        }
    }

    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        double s = a[i][n];
        for (int j = i + 1; j < n; j++)
            s -= a[i][j] * x[j];
        x[i] = s / a[i][i];
    }

    cout << fixed << setprecision(4);
    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " << x[i] << "\n";
    return 0;
}
