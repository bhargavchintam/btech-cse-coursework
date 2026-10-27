// depth first search on an adjacency matrix - recursion peels off one vertex at a time
#include<iostream>
using namespace std;

int n;
int g[20][20];
bool visited[20];

void dfs(int u)
{
    visited[u] = true;
    cout << u << " ";
    for (int v = 0; v < n; v++)
        if (g[u][v] && !visited[v])
            dfs(v);
}

int main()
{
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter adjacency matrix\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    int start;
    cout << "Enter start vertex: ";
    cin >> start;

    cout << "DFS traversal: ";
    dfs(start);
    cout << endl;
    return 0;
}
