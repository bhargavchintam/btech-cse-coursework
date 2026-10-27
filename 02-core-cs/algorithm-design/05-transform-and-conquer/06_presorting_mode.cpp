// mode by presorting - once sorted the equal values sit together, longest run wins
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

    sort(a.begin(), a.end());

    int mode = a[0], best = 1;
    int cur = a[0], run = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == cur) {
            run++;
        } else {
            cur = a[i];
            run = 1;
        }
        if (run > best) {
            best = run;
            mode = cur;
        }
    }

    cout << "mode = " << mode << "  (appears " << best << " times)\n";
    return 0;
}
