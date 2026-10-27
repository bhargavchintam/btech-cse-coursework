// optimal binary search tree - minimum search cost from key frequencies
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of keys: ";
    cin >> n;

    int freq[20];
    cout << "enter frequency of each key: ";
    for(int i = 1; i <= n; i++)
        cin >> freq[i];

    int cost[20][20] = {};
    int sum[20][20] = {};

    for(int i = 1; i <= n; i++)
    {
        cost[i][i] = freq[i];
        sum[i][i] = freq[i];
    }

    for(int len = 2; len <= n; len++)
    {
        for(int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            sum[i][j] = sum[i][j-1] + freq[j];
            cost[i][j] = 9999;
            for(int r = i; r <= j; r++)
            {
                int left = (r > i) ? cost[i][r-1] : 0;
                int right = (r < j) ? cost[r+1][j] : 0;
                int c = left + right + sum[i][j];
                if(c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    cout << "minimum cost of optimal BST = " << cost[1][n] << endl;
    return 0;
}
