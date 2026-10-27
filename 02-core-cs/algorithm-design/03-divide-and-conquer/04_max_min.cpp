// find max and min together by divide and conquer, count the comparisons
#include<iostream>
#include<vector>
using namespace std;

int comparisons = 0;

struct Pair {
    int mn;
    int mx;
};

Pair maxMin(vector<int> &a, int lo, int hi)
{
    Pair res;
    if (lo == hi) {
        res.mn = res.mx = a[lo];
        return res;
    }
    if (hi == lo + 1) {
        comparisons++;
        if (a[lo] < a[hi]) {
            res.mn = a[lo];
            res.mx = a[hi];
        } else {
            res.mn = a[hi];
            res.mx = a[lo];
        }
        return res;
    }

    int mid = (lo + hi) / 2;
    Pair left = maxMin(a, lo, mid);
    Pair right = maxMin(a, mid + 1, hi);

    res.mn = left.mn;
    comparisons++;
    if (right.mn < res.mn)
        res.mn = right.mn;
    res.mx = left.mx;
    comparisons++;
    if (right.mx > res.mx)
        res.mx = right.mx;
    return res;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Pair p = maxMin(a, 0, n - 1);
    cout << "Minimum = " << p.mn << endl;
    cout << "Maximum = " << p.mx << endl;
    cout << "Comparisons used = " << comparisons << endl;
    return 0;
}
