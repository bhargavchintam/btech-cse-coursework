// all subsets of {1..n} by include/exclude recursion - decide one element, recurse on the rest
#include<iostream>
#include<vector>
using namespace std;

int n;

void subsets(int k, vector<int>& chosen)
{
    if (k > n) {
        cout << "{ ";
        for (int x : chosen)
            cout << x << " ";
        cout << "}\n";
        return;
    }
    subsets(k + 1, chosen);            // leave out k
    chosen.push_back(k);
    subsets(k + 1, chosen);            // take k
    chosen.pop_back();
}

int main()
{
    cout << "Enter n: ";
    cin >> n;
    vector<int> chosen;
    subsets(1, chosen);
    return 0;
}
