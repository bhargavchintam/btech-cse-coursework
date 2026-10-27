// link state routing - run dijkstra from every node, print each one's routing table
#include<iostream>
using namespace std;

#define INF 9999
#define MAXN 20

int n;
int cost[MAXN][MAXN];

void dijkstra(int src, int dist[], int par[])
{
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
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> cost[i][j];

    for(int s = 0; s < n; s++){
        int dist[MAXN], par[MAXN];
        dijkstra(s, dist, par);

        cout << "routing table for " << char('A' + s) << "\n";
        cout << "dest  cost  next\n";
        for(int d = 0; d < n; d++){
            if(d == s) continue;
            int hop = d;                       // walk back up the tree to the first hop
            while(par[hop] != -1 && par[hop] != s) hop = par[hop];
            cout << char('A' + d) << "     " << dist[d] << "     "
                 << char('A' + hop) << "\n";
        }
        cout << "\n";
    }
    return 0;
}
