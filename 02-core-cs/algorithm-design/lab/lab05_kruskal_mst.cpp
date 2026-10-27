/* Lab Program 5
   Find the minimum cost spanning tree of a connected undirected graph using
   Kruskal's algorithm. Edges are sorted by weight and cycles are avoided with
   a union-find (disjoint set) structure. */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool byWeight(const Edge &a, const Edge &b)
{
    return a.w < b.w;
}

int parent[20], rnk[20];

int find(int x)
{
    while (parent[x] != x)
        x = parent[x] = parent[parent[x]];
    return x;
}

void unite(int a, int b)
{
    a = find(a); b = find(b);
    if (a == b) return;
    if (rnk[a] < rnk[b]) { int t = a; a = b; b = t; }
    parent[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
}

int main()
{
    int n = 5;
    int g[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    vector<Edge> edges;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (g[i][j])
                edges.push_back({i, j, g[i][j]});

    sort(edges.begin(), edges.end(), byWeight);
    for (int i = 0; i < n; i++) { parent[i] = i; rnk[i] = 0; }

    int cost = 0, taken = 0;
    cout << "edge    weight\n";
    for (Edge e : edges) {
        if (find(e.u) != find(e.v)) {
            unite(e.u, e.v);
            cout << e.u << " - " << e.v << "      " << e.w << "\n";
            cost += e.w;
            if (++taken == n-1) break;
        }
    }
    cout << "minimum cost = " << cost << "\n";
    return 0;
}
