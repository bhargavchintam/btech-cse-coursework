// heap sort - build a max heap (representation change) then pull the max out repeatedly
#include<iostream>
#include<vector>
using namespace std;

// sift a[i] down inside a[0..size-1] so the max-heap property holds
void siftDown(vector<int>& a, int i, int size)
{
    while (true) {
        int l = 2 * i + 1, r = 2 * i + 2, big = i;
        if (l < size && a[l] > a[big]) big = l;
        if (r < size && a[r] > a[big]) big = r;
        if (big == i) break;
        int t = a[i]; a[i] = a[big]; a[big] = t;
        i = big;
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = n / 2 - 1; i >= 0; i--)   // build heap bottom up
        siftDown(a, i, n);

    for (int end = n - 1; end > 0; end--) {
        int t = a[0]; a[0] = a[end]; a[end] = t;   // biggest goes to the back
        siftDown(a, 0, end);
    }

    cout << "sorted: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
