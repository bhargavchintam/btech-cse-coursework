// binary search on a sorted array  T(n) = T(n/2) + 1  => O(log n)
#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &a, int key)
{
    int low = 0, high = a.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    int pos = binarySearch(a, key);
    if (pos == -1)
        cout << key << " not found\n";
    else
        cout << key << " found at index " << pos << endl;
    return 0;
}
