// 0/1 knapsack using a dynamic programming table
#include<stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, i, w;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int wt[100], val[100];
    printf("Enter weight and value of each item:\n");
    for(i = 1; i <= n; i++)
        scanf("%d %d", &wt[i], &val[i]);

    int cap;
    printf("Enter capacity: ");
    scanf("%d", &cap);

    int dp[100][100];
    for(i = 0; i <= n; i++) {
        for(w = 0; w <= cap; w++) {
            if(i == 0 || w == 0)
                dp[i][w] = 0;
            else if(wt[i] <= w)
                dp[i][w] = max(val[i] + dp[i - 1][w - wt[i]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("Maximum value = %d\n", dp[n][cap]);
    return 0;
}
