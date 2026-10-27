// count inversions using the merge step  => O(n log n)
#include<iostream>
#include<vector>
using namespace std;

long long merge(vector<int> &a, int lo, int mid, int hi)
{
    vector<int> temp;
    int i = lo, j = mid + 1;
    long long inv = 0;
    while (i <= mid && j <= hi) {
        if (a[i] <= a[j])
            temp.push_back(a[i++]);
        else {
            inv += mid - i + 1;           // a[i..mid] are all greater than a[j]
            temp.push_back(a[j++]);
        }
    }
    while (i <= mid)
        temp.push_back(a[i++]);
    while (j <= hi)
        temp.push_back(a[j++]);
    for (int k = 0; k < (int)temp.size(); k++)
        a[lo + k] = temp[k];
    return inv;
}

long long countInv(vector<int> &a, int lo, int hi)
{
    if (lo >= hi)
        return 0;
    int mid = (lo + hi) / 2;
    long long inv = 0;
    inv += countInv(a, lo, mid);
    inv += countInv(a, mid + 1, hi);
    inv += merge(a, lo, mid, hi);
    return inv;
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

    cout << "Inversions = " << countInv(a, 0, n - 1) << endl;
    return 0;
}
