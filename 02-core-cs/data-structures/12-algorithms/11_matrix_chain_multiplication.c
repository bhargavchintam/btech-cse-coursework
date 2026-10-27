// matrix chain multiplication - minimum scalar multiplications (DP)
#include<stdio.h>

int main()
{
    int n, i, j, k, len;
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    // n matrices need n+1 dimensions
    int p[100];
    printf("Enter %d dimensions:\n", n + 1);
    for(i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    int dp[100][100];
    for(i = 1; i <= n; i++)
        dp[i][i] = 0;

    for(len = 2; len <= n; len++)
    {
        for(i = 1; i <= n - len + 1; i++)
        {
            j = i + len - 1;
            dp[i][j] = 999999999;
            for(k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    printf("Minimum multiplications = %d\n", dp[1][n]);
    return 0;
}
