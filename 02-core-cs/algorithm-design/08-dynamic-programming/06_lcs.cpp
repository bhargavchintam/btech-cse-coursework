// longest common subsequence - length and the string
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string x, y;
    cout << "Enter first string: ";
    cin >> x;
    cout << "Enter second string: ";
    cin >> y;

    int m = x.size(), n = y.size();
    int L[100][100] = {};

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(x[i-1] == y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = L[i-1][j] > L[i][j-1] ? L[i-1][j] : L[i][j-1];
        }
    }

    cout << "length of LCS = " << L[m][n] << endl;

    string lcs = "";
    int i = m, j = n;
    while(i > 0 && j > 0)
    {
        if(x[i-1] == y[j-1])
        {
            lcs = x[i-1] + lcs;
            i--;
            j--;
        }
        else if(L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }
    cout << "LCS = " << lcs << endl;
    return 0;
}
