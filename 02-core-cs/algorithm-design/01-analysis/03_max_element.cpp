// max of an array in one pass - n-1 comparisons
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int big = a[0], comp = 0;
    for (int i = 1; i < n; i++) {
        comp++;
        if (a[i] > big)
            big = a[i];
    }

    cout << "Maximum = " << big << endl;
    cout << "comparisons = " << comp << "  (expected n-1 = " << n - 1 << ")\n";
    return 0;
}
