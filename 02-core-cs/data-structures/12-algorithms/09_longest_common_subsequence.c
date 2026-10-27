// longest common subsequence - DP, also prints the LCS
#include<stdio.h>
#include<string.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    char x[100], y[100];
    printf("Enter first string: ");
    scanf("%s", x);
    printf("Enter second string: ");
    scanf("%s", y);

    int m = strlen(x);
    int n = strlen(y);
    int dp[100][100];
    int i, j;

    for(i = 0; i <= m; i++)
    {
        for(j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(x[i - 1] == y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    printf("Length of LCS = %d\n", dp[m][n]);

    // walk back through the table to recover the actual subsequence
    char lcs[100];
    int index = dp[m][n];
    lcs[index] = '\0';
    i = m;
    j = n;
    while(i > 0 && j > 0)
    {
        if(x[i - 1] == y[j - 1])
        {
            lcs[index - 1] = x[i - 1];
            i--;
            j--;
            index--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    printf("LCS = %s\n", lcs);
    return 0;
}
