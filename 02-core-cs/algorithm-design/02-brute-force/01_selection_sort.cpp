/* Bindu Bhargava   28-01-19 */
// selection sort - n-1 passes, each finds the min of the unsorted tail. Theta(n^2)
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

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        int t = a[i];
        a[i] = a[min];
        a[min] = t;
    }

    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
