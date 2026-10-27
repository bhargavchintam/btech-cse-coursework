// minimum number of coins to make an amount - DP
#include<stdio.h>

int main()
{
    int n, i, j;
    printf("Enter number of denominations: ");
    scanf("%d", &n);

    int coin[100];
    printf("enter %d denominations\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &coin[i]);

    int amount;
    printf("Enter amount: ");
    scanf("%d", &amount);

    int dp[1000];
    dp[0] = 0;
    for(i = 1; i <= amount; i++)
        dp[i] = 999999;

    for(i = 1; i <= amount; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(coin[j] <= i && dp[i - coin[j]] + 1 < dp[i])
                dp[i] = dp[i - coin[j]] + 1;
        }
    }

    if(dp[amount] == 999999)
        printf("Not possible\n");
    else
        printf("Minimum coins = %d\n", dp[amount]);
    return 0;
}
