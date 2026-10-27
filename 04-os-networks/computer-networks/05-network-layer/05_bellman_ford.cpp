// bellman ford - single source shortest paths by relaxing every edge n-1 times
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

    // pull the edges out of the matrix
    int eu[MAXN * MAXN], ev[MAXN * MAXN], ew[MAXN * MAXN], m = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j && cost[i][j] != INF){
                eu[m] = i; ev[m] = j; ew[m] = cost[i][j]; m++;
            }

    int dist[MAXN];
    for(int i = 0; i < n; i++){ dist[i] = INF; par[i] = -1; }
    dist[src] = 0;

    for(int k = 0; k < n - 1; k++)
        for(int e = 0; e < m; e++)
            if(dist[eu[e]] != INF && dist[eu[e]] + ew[e] < dist[ev[e]]){
                dist[ev[e]] = dist[eu[e]] + ew[e];
                par[ev[e]] = eu[e];
            }

    for(int e = 0; e < m; e++)
        if(dist[eu[e]] != INF && dist[eu[e]] + ew[e] < dist[ev[e]]){
            cout << "negative cycle in the graph\n";
            return 0;
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
