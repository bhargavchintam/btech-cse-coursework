/* Bindu Bhargava   28-01-19 */
// merge sort  T(n) = 2T(n/2) + n  => O(n log n)
#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &a, int lo, int mid, int hi)
{
    vector<int> temp;
    int i = lo, j = mid + 1;
    while (i <= mid && j <= hi) {
        if (a[i] <= a[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(a[j++]);
    }
    while (i <= mid)
        temp.push_back(a[i++]);
    while (j <= hi)
        temp.push_back(a[j++]);
    for (int k = 0; k < (int)temp.size(); k++)
        a[lo + k] = temp[k];
}

void mergeSort(vector<int> &a, int lo, int hi)
{
    if (lo >= hi)
        return;
    int mid = (lo + hi) / 2;
    mergeSort(a, lo, mid);
    mergeSort(a, mid + 1, hi);
    merge(a, lo, mid, hi);
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

    mergeSort(a, 0, n - 1);

    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
