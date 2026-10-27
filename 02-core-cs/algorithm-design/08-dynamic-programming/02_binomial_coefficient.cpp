// binomial coefficient using pascals triangle
#include<iostream>
using namespace std;

int main()
{
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;

    int C[30][30] = {};
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    cout << "pascal triangle:\n";
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= i; j++)
            cout << C[i][j] << " ";
        cout << "\n";
    }

    cout << "C(" << n << "," << k << ") = " << C[n][k] << endl;
    return 0;
}
