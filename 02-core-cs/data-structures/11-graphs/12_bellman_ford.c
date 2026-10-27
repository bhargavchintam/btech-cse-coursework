// bellman-ford, handles negative edges, detects negative cycle
#include<stdio.h>
#define INF 9999

int main()
{
    int n, e, i, j, src;
    int eu[100], ev[100], ew[100], dist[20];

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter edges (u v w) - directed\n");
    for (i = 0; i < e; i++)
        scanf("%d %d %d", &eu[i], &ev[i], &ew[i]);

    printf("Enter source: ");
    scanf("%d", &src);

    for (i = 0; i < n; i++)
        dist[i] = INF;
    dist[src] = 0;

    // relax all edges n-1 times
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < e; j++)
            if (dist[eu[j]] != INF && dist[eu[j]] + ew[j] < dist[ev[j]])
                dist[ev[j]] = dist[eu[j]] + ew[j];

    // one more pass - if anything still relaxes, there's a negative cycle
    for (j = 0; j < e; j++)
        if (dist[eu[j]] != INF && dist[eu[j]] + ew[j] < dist[ev[j]])
        {
            printf("Graph contains a negative weight cycle\n");
            return 0;
        }

    printf("Shortest distances from %d\n", src);
    for (i = 0; i < n; i++)
        printf("to %d = %d\n", i, dist[i]);
    return 0;
}
