// subset sum by backtracking - print every subset that adds up to target
#include<iostream>
#include<vector>
using namespace std;

int n, target;
vector<int> a;
vector<int> chosen;
int found = 0;

void solve(int i, int sum)
{
    if(sum == target)
    {
        found++;
        cout << "{ ";
        for(int x : chosen)
            cout << x << " ";
        cout << "}\n";
        return;
    }
    if(i == n || sum > target)      // overshot, no point going deeper (values are +ve)
        return;

    chosen.push_back(a[i]);
    solve(i + 1, sum + a[i]);
    chosen.pop_back();

    solve(i + 1, sum);
}

int main()
{
    cout << "Enter number of elements: ";
    cin >> n;
    a.resize(n);
    cout << "Enter " << n << " elements\n";
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter target sum: ";
    cin >> target;

    cout << "subsets summing to " << target << ":\n";
    solve(0, 0);

    if(found == 0)
        cout << "no subset sums to " << target << "\n";
    else
        cout << found << " subset(s) found\n";
    return 0;
}
