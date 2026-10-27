// graph m-colouring by backtracking - no edge may join two same-coloured vertices
#include<iostream>
using namespace std;

int n, m;
int g[20][20];
int color[20];

bool safe(int v, int c)
{
    for(int i = 0; i < n; i++)
        if(g[v][i] && color[i] == c)
            return false;
    return true;
}

bool solve(int v)
{
    if(v == n)
        return true;
    for(int c = 1; c <= m; c++)
        if(safe(v, c))
        {
            color[v] = c;
            if(solve(v + 1))
                return true;
            color[v] = 0;      // undo
        }
    return false;
}

int main()
{
    cout << "Enter vertices and number of colours (n m): ";
    cin >> n >> m;
    cout << "enter adjacency matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];

    for(int i = 0; i < n; i++)
        color[i] = 0;

    if(solve(0))
    {
        cout << "colouring found:\n";
        for(int i = 0; i < n; i++)
            cout << "vertex " << i << " -> colour " << color[i] << "\n";
    }
    else
        cout << "no solution with " << m << " colours\n";
    return 0;
}
