// hamiltonian cycle by backtracking - visit every vertex once, return to the start
#include<iostream>
using namespace std;

int n;
int g[20][20];
int path[20];
bool used[20];

bool solve(int pos)
{
    if(pos == n)
        return g[path[pos - 1]][path[0]] == 1;      // last vertex must link back to start

    for(int v = 1; v < n; v++)          // vertex 0 is fixed as the start
        if(g[path[pos - 1]][v] && !used[v])
        {
            path[pos] = v;
            used[v] = true;
            if(solve(pos + 1))
                return true;
            used[v] = false;
        }
    return false;
}

int main()
{
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "enter adjacency matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];

    for(int i = 0; i < n; i++)
        used[i] = false;
    path[0] = 0;
    used[0] = true;

    if(solve(1))
    {
        cout << "hamiltonian cycle:\n";
        for(int i = 0; i < n; i++)
            cout << path[i] << " -> ";
        cout << path[0] << "\n";
    }
    else
        cout << "none\n";
    return 0;
}
