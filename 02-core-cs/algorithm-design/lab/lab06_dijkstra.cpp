/* Lab Program 6
   Single source shortest paths from a given vertex using Dijkstra's algorithm.
   The graph is an undirected weighted adjacency matrix (0 = no edge). Source is
   vertex 0. */
#include<iostream>
#include<climits>
using namespace std;

const int N = 5;

int g[N][N] = {
    {0, 10, 3, 0, 0},
    {10, 0, 1, 2, 0},
    {3, 1, 0, 8, 2},
    {0, 2, 8, 0, 7},
    {0, 0, 2, 7, 0}
};

int main()
{
    int src = 0;
    int dist[N];
    bool done[N] = {};
    for (int i = 0; i < N; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for (int c = 0; c < N; c++) {
        int u = -1;
        for (int v = 0; v < N; v++)
            if (!done[v] && dist[v] != INT_MAX && (u == -1 || dist[v] < dist[u]))
                u = v;
        if (u == -1) break;
        done[u] = true;
        for (int v = 0; v < N; v++)
            if (g[u][v] && dist[u] + g[u][v] < dist[v])
                dist[v] = dist[u] + g[u][v];
    }

    cout << "vertex   distance from " << src << "\n";
    for (int v = 0; v < N; v++)
        cout << "   " << v << "          " << dist[v] << "\n";
    return 0;
}
