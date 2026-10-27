// element uniqueness by presorting - sort then check neighbours, O(n log n)
#include<iostream>
#include<vector>
#include<algorithm>
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

    sort(a.begin(), a.end());          // the transform - after this a duplicate is adjacent

    int dup = -1;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] == a[i + 1]) {
            dup = a[i];
            break;
        }
    }

    if (dup == -1)
        cout << "all elements are distinct\n";
    else
        cout << "not unique - " << dup << " is repeated\n";
    return 0;
}
