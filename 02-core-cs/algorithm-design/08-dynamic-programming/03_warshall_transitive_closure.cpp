// warshall's algorithm - transitive closure of a digraph
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int r[20][20];
    cout << "enter adjacency matrix (0/1):\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> r[i][j];

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(r[i][k] && r[k][j])
                    r[i][j] = 1;

    cout << "transitive closure:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << r[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
