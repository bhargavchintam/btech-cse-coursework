// lab 6 - distance vector routing
// every node knows only its direct link costs to start with, then keeps taking
// its neighbours' vectors (Bellman-Ford: cost to k + k's cost to j) until nothing
// changes. the final table is each node's least cost to all the others.
#include<iostream>
using namespace std;

const int INF = 9999;

int main()
{
    int n;
    cout << "number of nodes: ";
    cin >> n;

    int cost[20][20], dist[20][20];
    cout << "cost matrix (0 = no link):\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin >> cost[i][j];
            if(i != j && cost[i][j] == 0) cost[i][j] = INF;
            dist[i][j] = cost[i][j];
        }

    int upd = 1;
    while(upd){
        upd = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    if(cost[i][k] < INF && cost[i][k] + dist[k][j] < dist[i][j]){
                        dist[i][j] = cost[i][k] + dist[k][j];
                        upd = 1;
                    }
    }

    for(int i = 0; i < n; i++){
        cout << "node " << i << " table:\n";
        for(int j = 0; j < n; j++)
            cout << "   to " << j << "  cost " << dist[i][j] << "\n";
    }
    return 0;
}
