// breadth first search using a queue - visit the graph level by level
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    int g[20][20] = {};
    cout << "Enter adjacency matrix\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    int start;
    cout << "Enter start vertex: ";
    cin >> start;

    bool visited[20] = {};
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "BFS traversal: ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v = 0; v < n; v++)
            if (g[u][v] && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
    }
    cout << endl;
    return 0;
}
