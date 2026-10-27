// lab 5 - shortest path routing using Dijkstra
// reads a cost adjacency matrix (0 means no direct link) and a source node, then
// picks the nearest unvisited node each round and relaxes its neighbours. prints
// the least cost from the source to every node.
#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cout << "number of nodes: ";
    cin >> n;

    int cost[20][20];
    cout << "cost matrix (0 = no link):\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> cost[i][j];

    int src;
    cout << "source: ";
    cin >> src;

    int dist[20];
    bool done[20];
    for(int i = 0; i < n; i++){ dist[i] = INT_MAX; done[i] = false; }
    dist[src] = 0;

    for(int c = 0; c < n; c++){
        int u = -1, best = INT_MAX;
        for(int i = 0; i < n; i++)
            if(!done[i] && dist[i] < best){ best = dist[i]; u = i; }
        if(u < 0) break;
        done[u] = true;
        for(int v = 0; v < n; v++)
            if(cost[u][v] && !done[v] && dist[u] != INT_MAX && dist[u] + cost[u][v] < dist[v])
                dist[v] = dist[u] + cost[u][v];
    }

    for(int i = 0; i < n; i++)
        cout << src << " -> " << i << " = " << dist[i] << "\n";
    return 0;
}
