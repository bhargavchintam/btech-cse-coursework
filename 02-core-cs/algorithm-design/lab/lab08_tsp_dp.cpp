/* Lab Program 8
   Travelling salesman problem for a small number of cities by dynamic
   programming (Held-Karp). Find the least cost tour that starts at city 0,
   visits every city exactly once and returns to 0. */
#include<iostream>
#include<climits>
using namespace std;

const int N = 4;

int cost[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int dp[1 << N][N];      // dp[mask][i] = best cost to reach i having visited mask

int main()
{
    int full = (1 << N) - 1;
    for (int m = 0; m <= full; m++)
        for (int i = 0; i < N; i++)
            dp[m][i] = INT_MAX;
    dp[1][0] = 0;

    for (int mask = 1; mask <= full; mask++)
        for (int u = 0; u < N; u++) {
            if (dp[mask][u] == INT_MAX || !(mask & (1 << u))) continue;
            for (int v = 0; v < N; v++) {
                if (mask & (1 << v)) continue;
                int nm = mask | (1 << v);
                if (dp[mask][u] + cost[u][v] < dp[nm][v])
                    dp[nm][v] = dp[mask][u] + cost[u][v];
            }
        }

    int best = INT_MAX;
    for (int u = 1; u < N; u++)
        if (dp[full][u] != INT_MAX && dp[full][u] + cost[u][0] < best)
            best = dp[full][u] + cost[u][0];

    cout << "minimum tour cost = " << best << "\n";
    return 0;
}
