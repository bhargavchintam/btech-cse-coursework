// comparison counting sort - count how many are smaller, that is the final position
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

    vector<int> count(n, 0);
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j])
                count[j]++;
            else
                count[i]++;
        }

    vector<int> s(n);
    for (int i = 0; i < n; i++)
        s[count[i]] = a[i];

    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
        cout << s[i] << " ";
    cout << endl;
    return 0;
}
