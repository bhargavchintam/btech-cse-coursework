/* Lab Program 11
   Subset sum by backtracking. Given a set of positive integers and a target
   sum, print every subset whose elements add up to the target. */
#include<iostream>
#include<vector>
using namespace std;

int a[] = {3, 34, 4, 12, 5, 2};
int n = 6, target = 9;
vector<int> chosen;
int found = 0;

void solve(int i, int sum)
{
    if (sum == target) {
        found++;
        cout << "{ ";
        for (int x : chosen) cout << x << " ";
        cout << "}\n";
        return;
    }
    if (i >= n || sum > target) return;

    chosen.push_back(a[i]);
    solve(i+1, sum + a[i]);
    chosen.pop_back();
    solve(i+1, sum);
}

int main()
{
    cout << "subsets that sum to " << target << ":\n";
    solve(0, 0);
    if (!found) cout << "none\n";
    return 0;
}
