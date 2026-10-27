// dfs traversal, recursive
#include<stdio.h>

int a[20][20], n, visited[20];

void dfs(int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for (i = 0; i < n; i++)
        if (a[v][i] && !visited[i])
            dfs(i);
}

int main()
{
    int i, j, s;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter start vertex: ");
    scanf("%d", &s);

    printf("DFS: ");
    dfs(s);
    printf("\n");
    return 0;
}
