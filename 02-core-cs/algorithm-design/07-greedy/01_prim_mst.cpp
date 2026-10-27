// prim's minimum spanning tree from a cost matrix
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

    int key[20], parent[20];
    bool inMST[20];
    for(int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
        inMST[i] = false;
    }
    key[0] = 0;

    for(int count = 0; count < n; count++) {
        int u = -1;
        for(int v = 0; v < n; v++)
            if(!inMST[v] && (u == -1 || key[v] < key[u]))
                u = v;
        inMST[u] = true;

        for(int v = 0; v < n; v++)
            if(cost[u][v] != 0 && !inMST[v] && cost[u][v] < key[v]) {
                key[v] = cost[u][v];
                parent[v] = u;
            }
    }

    int total = 0;
    cout << "edges in the MST:\n";
    for(int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << "   weight " << key[i] << "\n";
        total += key[i];
    }
    cout << "total weight = " << total << endl;
    return 0;
}
