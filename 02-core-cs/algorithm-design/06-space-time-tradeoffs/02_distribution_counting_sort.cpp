// distribution counting sort - frequency table then distribution (cumulative) table
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout << "How many numbers? ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int lo = a[0], hi = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < lo) lo = a[i];
        if (a[i] > hi) hi = a[i];
    }

    int range = hi - lo + 1;
    vector<int> d(range, 0);
    for (int i = 0; i < n; i++)
        d[a[i] - lo]++;                 // frequencies
    for (int i = 1; i < range; i++)
        d[i] += d[i - 1];               // distribution

    vector<int> s(n);
    for (int j = n - 1; j >= 0; j--) {  // right to left keeps it stable
        int v = a[j] - lo;
        s[d[v] - 1] = a[j];
        d[v]--;
    }

    cout << "sorted array: ";
    for (int i = 0; i < n; i++)
        cout << s[i] << " ";
    cout << "\n";
    return 0;
}
