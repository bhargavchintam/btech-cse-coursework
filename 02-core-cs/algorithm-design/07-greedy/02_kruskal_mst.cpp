// kruskal's mst using union-find
#include<iostream>
#include<algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int parent[20];

int find(int x)
{
    while(parent[x] != x)
        x = parent[x];
    return x;
}

int main()
{
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    Edge e[100];
    cout << "enter each edge as u v weight:\n";
    for(int i = 0; i < m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;

    sort(e, e + m, cmp);

    for(int i = 0; i < n; i++)
        parent[i] = i;

    int total = 0, picked = 0;
    cout << "edges in the MST:\n";
    for(int i = 0; i < m && picked < n - 1; i++) {
        int a = find(e[i].u);
        int b = find(e[i].v);
        if(a != b) {
            parent[a] = b;
            cout << e[i].u << " - " << e[i].v << "   weight " << e[i].w << "\n";
            total += e[i].w;
            picked++;
        }
    }
    cout << "total weight = " << total << endl;
    return 0;
}
