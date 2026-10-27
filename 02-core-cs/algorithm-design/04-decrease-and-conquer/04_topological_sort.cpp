// topological sort by source removal - repeatedly delete a vertex of indegree 0 (decrease by one)
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    int g[20][20] = {};
    cout << "Enter adjacency matrix (directed, 1 = edge i->j)\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    int indeg[20] = {};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (g[i][j])
                indeg[j]++;

    bool removed[20] = {};
    cout << "Topological order: ";
    for (int k = 0; k < n; k++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!removed[i] && indeg[i] == 0) {
                u = i;
                break;
            }
        if (u == -1) {
            cout << "\ngraph has a cycle, no topological order\n";
            return 0;
        }
        removed[u] = true;
        cout << u << " ";
        for (int v = 0; v < n; v++)
            if (g[u][v])
                indeg[v]--;
    }
    cout << endl;
    return 0;
}
