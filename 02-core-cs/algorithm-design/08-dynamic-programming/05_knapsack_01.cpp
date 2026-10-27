// 0/1 knapsack using a dp table
#include<iostream>
using namespace std;

int main()
{
    int n, cap;
    cout << "Enter number of items: ";
    cin >> n;

    int wt[50], val[50];
    cout << "enter weight and value of each item:\n";
    for(int i = 1; i <= n; i++)
        cin >> wt[i] >> val[i];

    cout << "Enter knapsack capacity: ";
    cin >> cap;

    int K[50][100] = {};
    for(int i = 1; i <= n; i++)
    {
        for(int w = 0; w <= cap; w++)
        {
            if(wt[i] <= w)
            {
                int take = val[i] + K[i-1][w-wt[i]];
                int leave = K[i-1][w];
                K[i][w] = take > leave ? take : leave;
            }
            else
                K[i][w] = K[i-1][w];
        }
    }

    cout << "maximum value = " << K[n][cap] << endl;

    cout << "items chosen (weight,value): ";
    int w = cap;
    for(int i = n; i >= 1; i--)
    {
        if(K[i][w] != K[i-1][w])
        {
            cout << "(" << wt[i] << "," << val[i] << ") ";
            w -= wt[i];
        }
    }
    cout << "\n";
    return 0;
}
