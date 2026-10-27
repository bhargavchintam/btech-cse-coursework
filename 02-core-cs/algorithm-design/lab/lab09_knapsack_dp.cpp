/* Lab Program 9
   0/1 knapsack: given item weights, values and a sack capacity W, pick a subset
   of items with maximum total value and total weight at most W. Dynamic
   programming builds a table over items and capacity. */
#include<iostream>
using namespace std;

int main()
{
    int wt[]  = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int n = 4, W = 7;

    int dp[5][8] = {};
    for (int i = 1; i <= n; i++)
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i-1][w];
            if (wt[i-1] <= w && dp[i-1][w - wt[i-1]] + val[i-1] > dp[i][w])
                dp[i][w] = dp[i-1][w - wt[i-1]] + val[i-1];
        }

    cout << "maximum value = " << dp[n][W] << "\n";
    return 0;
}
