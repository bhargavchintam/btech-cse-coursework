/* Lab Program 4
   Find the minimum cost spanning tree of a connected undirected graph using
   Prim's algorithm. The graph is given as an adjacency matrix (0 = no edge). */
#include<iostream>
#include<climits>
using namespace std;

const int N = 5;

int g[N][N] = {
    {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0}
};

int main()
{
    bool inTree[N] = {};
    int parent[N], key[N];
    for (int i = 0; i < N; i++) { key[i] = INT_MAX; parent[i] = -1; }
    key[0] = 0;

    for (int c = 0; c < N; c++) {
        int u = -1;
        for (int v = 0; v < N; v++)
            if (!inTree[v] && (u == -1 || key[v] < key[u]))
                u = v;
        inTree[u] = true;
        for (int v = 0; v < N; v++)
            if (g[u][v] && !inTree[v] && g[u][v] < key[v]) {
                key[v] = g[u][v];
                parent[v] = u;
            }
    }

    int cost = 0;
    cout << "edge    weight\n";
    for (int v = 1; v < N; v++) {
        cout << parent[v] << " - " << v << "      " << g[parent[v]][v] << "\n";
        cost += g[parent[v]][v];
    }
    cout << "minimum cost = " << cost << "\n";
    return 0;
}
