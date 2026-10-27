// minimum number of coins for an amount
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of denominations: ";
    cin >> n;

    int coin[20];
    cout << "enter the denominations: ";
    for(int i = 0; i < n; i++)
        cin >> coin[i];

    int amount;
    cout << "Enter amount: ";
    cin >> amount;

    const int INF = 9999;
    int dp[1000];
    dp[0] = 0;
    for(int a = 1; a <= amount; a++)
    {
        dp[a] = INF;
        for(int i = 0; i < n; i++)
            if(coin[i] <= a && dp[a-coin[i]] + 1 < dp[a])
                dp[a] = dp[a-coin[i]] + 1;
    }

    if(dp[amount] >= INF)
        cout << "amount cannot be made\n";
    else
        cout << "minimum coins = " << dp[amount] << endl;
    return 0;
}
