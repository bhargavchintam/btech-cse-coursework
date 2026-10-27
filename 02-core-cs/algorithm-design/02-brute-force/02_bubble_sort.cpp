// bubble sort - swap adjacent out-of-order pairs, largest bubbles to the end each pass
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout << "enter n: ";
    cin >> n;
    vector<int> a(n);
    cout << "enter " << n << " numbers\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }

    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
