// lab 7 - link state routing
// every node floods its link costs so all of them end up with the full topology.
// each node then runs Dijkstra on that shared map to build its own shortest path
// table - so here we just run Dijkstra once from every source.
#include<iostream>
#include<climits>
using namespace std;

void dijkstra(int cost[][20], int n, int src)
{
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

    cout << "node " << src << ":";
    for(int i = 0; i < n; i++) cout << "  " << i << "=" << dist[i];
    cout << "\n";
}

int main()
{
    int n;
    cout << "number of nodes: ";
    cin >> n;

    int cost[20][20];
    cout << "cost matrix (0 = no link):\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> cost[i][j];

    for(int i = 0; i < n; i++) dijkstra(cost, n, i);
    return 0;
}
