// all permutations of 1..n - fix one position, permute the rest (decrease by one), lexicographic
#include<iostream>
#include<vector>
using namespace std;

int n;

void permute(vector<int>& perm, vector<bool>& used)
{
    if ((int)perm.size() == n) {
        for (int x : perm)
            cout << x << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!used[i]) {
            used[i] = true;
            perm.push_back(i);
            permute(perm, used);
            perm.pop_back();
            used[i] = false;
        }
}

int main()
{
    cout << "Enter n: ";
    cin >> n;
    vector<int> perm;
    vector<bool> used(n + 1, false);
    permute(perm, used);
    return 0;
}
