// count connected components in an undirected graph
#include<stdio.h>

int a[20][20], n, visited[20];

void dfs(int v)
{
    int i;
    visited[v] = 1;
    for (i = 0; i < n; i++)
        if (a[v][i] && !visited[i])
            dfs(i);
}

int main()
{
    int i, j, count = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++)
        if (!visited[i])
        {
            dfs(i);
            count++;
        }

    printf("Number of connected components = %d\n", count);
    return 0;
}
