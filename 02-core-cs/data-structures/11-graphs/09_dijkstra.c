// dijkstra single source shortest path
#include<stdio.h>
#define INF 9999

int main()
{
    int cost[20][20], dist[20], done[20], n, i, j, u, v, min, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix (0 for no edge)\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }

    printf("Enter source: ");
    scanf("%d", &src);

    for (i = 0; i < n; i++)
    {
        dist[i] = cost[src][i];
        done[i] = 0;
    }
    dist[src] = 0;
    done[src] = 1;

    for (i = 1; i < n; i++)
    {
        min = INF;
        u = -1;
        for (j = 0; j < n; j++)
            if (!done[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        if (u == -1)
            break;
        done[u] = 1;
        for (v = 0; v < n; v++)
            if (!done[v] && dist[u] + cost[u][v] < dist[v])
                dist[v] = dist[u] + cost[u][v];
    }

    printf("Shortest distances from %d\n", src);
    for (i = 0; i < n; i++)
        printf("to %d = %d\n", i, dist[i]);
    return 0;
}
