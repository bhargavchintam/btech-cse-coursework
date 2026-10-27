// floyd's algorithm - all pairs shortest paths
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    const int INF = 9999;
    int dist[20][20];
    cout << "enter cost matrix (" << INF << " for no edge):\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> dist[i][j];

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    cout << "shortest distance matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(dist[i][j] >= INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
