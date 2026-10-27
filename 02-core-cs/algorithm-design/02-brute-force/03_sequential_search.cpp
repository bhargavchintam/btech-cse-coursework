// sequential search, plain and the sentinel variant (key parked past the end)
#include<iostream>
#include<vector>
using namespace std;

int seqSearch(vector<int> &a, int n, int key)
{
    for (int i = 0; i < n; i++)
        if (a[i] == key)
            return i;
    return -1;
}

// a has room for n+1; putting the key at a[n] lets the loop drop the i<n test
int seqSearchSentinel(vector<int> &a, int n, int key)
{
    a[n] = key;
    int i = 0;
    while (a[i] != key)
        i++;
    return (i < n) ? i : -1;            // reached the sentinel => not really there
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> a(n + 1);
    cout << "Enter " << n << " elements\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    int p = seqSearch(a, n, key);
    if (p == -1)
        cout << "plain: not found\n";
    else
        cout << "plain: found at index " << p << endl;

    int q = seqSearchSentinel(a, n, key);
    if (q == -1)
        cout << "sentinel: not found\n";
    else
        cout << "sentinel: found at index " << q << endl;
    return 0;
}
