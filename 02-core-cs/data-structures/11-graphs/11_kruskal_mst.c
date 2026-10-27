// kruskal's mst using union-find
#include<stdio.h>

int parent[20];

int find(int x)
{
    while (parent[x] != x)
        x = parent[x];
    return x;
}

int main()
{
    int n, e, i, j, u, v, total = 0, count = 0;
    int eu[100], ev[100], ew[100];

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter edges (u v w)\n");
    for (i = 0; i < e; i++)
        scanf("%d %d %d", &eu[i], &ev[i], &ew[i]);

    // sort edges by weight (simple bubble, e is small)
    for (i = 0; i < e - 1; i++)
        for (j = 0; j < e - 1 - i; j++)
            if (ew[j] > ew[j + 1])
            {
                int t;
                t = ew[j]; ew[j] = ew[j + 1]; ew[j + 1] = t;
                t = eu[j]; eu[j] = eu[j + 1]; eu[j + 1] = t;
                t = ev[j]; ev[j] = ev[j + 1]; ev[j + 1] = t;
            }

    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("Edges in MST\n");
    for (i = 0; i < e && count < n - 1; i++)
    {
        u = find(eu[i]);
        v = find(ev[i]);
        if (u != v)                 // adding this edge won't make a cycle
        {
            printf("%d - %d  weight %d\n", eu[i], ev[i], ew[i]);
            total += ew[i];
            parent[u] = v;
            count++;
        }
    }

    printf("Total weight = %d\n", total);
    return 0;
}
