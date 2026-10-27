// fake coin - one lighter coin among n, found by halving the pile (decrease by constant factor 2)
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of coins: ";
    cin >> n;
    int fake;
    cout << "Enter position of the fake (1.." << n << "), it is lighter: ";
    cin >> fake;

    vector<int> w(n + 1, 10);          // a genuine coin weighs 10
    w[fake] = 9;                       // the fake is lighter

    int lo = 1, hi = n, weighings = 0;
    while (lo < hi) {
        int len = hi - lo + 1;
        int half = len / 2;            // each pan gets 'half' coins, odd one sits out
        int leftSum = 0, rightSum = 0;
        for (int i = 0; i < half; i++) {
            leftSum  += w[lo + i];
            rightSum += w[lo + half + i];
        }
        weighings++;
        if (leftSum < rightSum)
            hi = lo + half - 1;        // fake sits in the left pan
        else if (rightSum < leftSum)
            lo = lo + half;            // fake sits in the right pan
        else
            lo = hi = lo + 2 * half;   // pans balance -> fake is the odd coin left out
    }

    cout << "fake coin is at position " << lo << endl;
    cout << "weighings used = " << weighings << endl;
    cout << "floor(log2 n) = " << (int)floor(log2((double)n)) << "  (worst case)\n";
    return 0;
}
