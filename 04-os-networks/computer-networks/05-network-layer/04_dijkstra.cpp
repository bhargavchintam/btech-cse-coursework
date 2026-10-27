// dijkstra - single source shortest paths (link state). reads cost matrix, prints dist + path
#include<iostream>
using namespace std;

#define INF 9999
#define MAXN 20

int par[MAXN];

void showpath(int v)
{
    if(v < 0) return;
    showpath(par[v]);
    cout << char('A' + v) << " ";
}

int main()
{
    int n;
    cin >> n;
    int cost[MAXN][MAXN];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> cost[i][j];

    int src;
    cin >> src;

    int dist[MAXN];
    bool done[MAXN];
    for(int i = 0; i < n; i++){ dist[i] = INF; par[i] = -1; done[i] = false; }
    dist[src] = 0;

    for(int c = 0; c < n; c++){
        int u = -1, best = INF;
        for(int i = 0; i < n; i++)
            if(!done[i] && dist[i] < best){ best = dist[i]; u = i; }
        if(u < 0) break;
        done[u] = true;

        for(int v = 0; v < n; v++){
            if(u == v || cost[u][v] == INF) continue;
            if(dist[u] + cost[u][v] < dist[v]){
                dist[v] = dist[u] + cost[u][v];
                par[v] = u;
            }
        }
    }

    cout << "source " << char('A' + src) << "\n";
    cout << "node  cost  path\n";
    for(int i = 0; i < n; i++){
        cout << char('A' + i) << "     " << dist[i] << "     ";
        showpath(i);
        cout << "\n";
    }
    return 0;
}
