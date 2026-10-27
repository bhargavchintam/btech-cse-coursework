// closest pair of points by checking all C(n,2) pairs. O(n^2)
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of points: ";
    cin >> n;
    vector<double> x(n), y(n);
    cout << "Enter " << n << " points as  x y\n";
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    double best = 1e18;
    int a = 0, b = 1;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++) {
            double dx = x[i] - x[j], dy = y[i] - y[j];
            double d = dx * dx + dy * dy;      // compare squared, sqrt only at the end
            if (d < best) {
                best = d;
                a = i;
                b = j;
            }
        }

    cout << "Closest pair: (" << x[a] << "," << y[a] << ") and ("
         << x[b] << "," << y[b] << ")\n";
    cout << "distance = " << sqrt(best) << endl;
    return 0;
}
