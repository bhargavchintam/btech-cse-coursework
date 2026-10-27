// graph as adjacency matrix
#include<stdio.h>

int main()
{
    int a[20][20], n, e, i, j, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            a[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter edges (u v)\n");
    for (i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);
        a[u][v] = 1;
        a[v][u] = 1;        // undirected
    }

    printf("Adjacency matrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}
