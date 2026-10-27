// distance vector routing - each node builds its table by exchanging vectors with neighbours
#include<iostream>
using namespace std;

#define INF 9999
#define MAXN 20

int main()
{
    int n;
    cin >> n;
    int cost[MAXN][MAXN];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> cost[i][j];

    int dist[MAXN][MAXN], nh[MAXN][MAXN];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if(i == j){ dist[i][j] = 0; nh[i][j] = i; }
            else if(cost[i][j] != INF){ dist[i][j] = cost[i][j]; nh[i][j] = j; }
            else { dist[i][j] = INF; nh[i][j] = -1; }
        }

    // keep sweeping until a full round changes nothing
    bool changed = true;
    while(changed){
        changed = false;
        for(int i = 0; i < n; i++)
            for(int k = 0; k < n; k++){
                if(i == k || cost[i][k] == INF) continue;      // k must be a neighbour
                for(int j = 0; j < n; j++){
                    if(dist[k][j] == INF) continue;
                    if(cost[i][k] + dist[k][j] < dist[i][j]){
                        dist[i][j] = cost[i][k] + dist[k][j];
                        nh[i][j] = k;
                        changed = true;
                    }
                }
            }
    }

    for(int i = 0; i < n; i++){
        cout << "routing table for " << char('A' + i) << "\n";
        cout << "dest  cost  next\n";
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            cout << char('A' + j) << "     " << dist[i][j] << "     "
                 << char('A' + nh[i][j]) << "\n";
        }
        cout << "\n";
    }
    return 0;
}
