// matrix chain multiplication - minimum scalar multiplications
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    int p[20];
    cout << "enter " << n+1 << " dimensions: ";
    for(int i = 0; i <= n; i++)
        cin >> p[i];

    int m[20][20] = {};

    for(int len = 2; len <= n; len++)
    {
        for(int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            m[i][j] = 99999999;
            for(int k = i; k < j; k++)
            {
                int cost = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    cout << "minimum number of multiplications = " << m[1][n] << endl;
    return 0;
}
