// 0/1 knapsack by exhaustive search - try all 2^n subsets, keep the best that fits
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, cap;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> w(n), v(n);
    cout << "Enter weight and value of each item\n";
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    cout << "Enter knapsack capacity: ";
    cin >> cap;

    int best = 0;
    for (int s = 0; s < (1 << n); s++) {
        int tw = 0, tv = 0;
        for (int i = 0; i < n; i++)
            if (s & (1 << i)) {
                tw += w[i];
                tv += v[i];
            }
        if (tw <= cap && tv > best)
            best = tv;
    }

    cout << "Best value = " << best << endl;
    return 0;
}
