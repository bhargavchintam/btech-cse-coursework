// dijkstra single source shortest paths from a cost matrix
#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int cost[20][20];
    cout << "enter cost matrix (0 = no edge):\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> cost[i][j];

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    int dist[20];
    bool done[20];
    for(int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        done[i] = false;
    }
    dist[src] = 0;

    for(int count = 0; count < n; count++) {
        int u = -1;
        for(int v = 0; v < n; v++)
            if(!done[v] && dist[v] != INT_MAX && (u == -1 || dist[v] < dist[u]))
                u = v;
        if(u == -1)
            break;
        done[u] = true;

        for(int v = 0; v < n; v++)
            if(cost[u][v] != 0 && dist[u] + cost[u][v] < dist[v])
                dist[v] = dist[u] + cost[u][v];
    }

    cout << "shortest distances from " << src << ":\n";
    for(int i = 0; i < n; i++) {
        cout << i << " : ";
        if(dist[i] == INT_MAX)
            cout << "unreachable\n";
        else
            cout << dist[i] << "\n";
    }
    return 0;
}
