/* Lab Program 14
   Graph traversal in one program: breadth first search using a queue and depth
   first search using recursion, on an undirected graph stored as an adjacency
   matrix. Both start from vertex 0. */
#include<iostream>
#include<queue>
using namespace std;

const int N = 6;

int g[N][N] = {
    {0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 1},
    {0, 1, 1, 0, 0, 1},
    {0, 0, 0, 1, 1, 0}
};

void bfs(int s)
{
    bool vis[N] = {};
    queue<int> q;
    vis[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v = 0; v < N; v++)
            if (g[u][v] && !vis[v]) {
                vis[v] = true;
                q.push(v);
            }
    }
    cout << "\n";
}

bool visited[N];

void dfs(int u)
{
    visited[u] = true;
    cout << u << " ";
    for (int v = 0; v < N; v++)
        if (g[u][v] && !visited[v])
            dfs(v);
}

int main()
{
    cout << "BFS from 0: ";
    bfs(0);

    cout << "DFS from 0: ";
    dfs(0);
    cout << "\n";
    return 0;
}
