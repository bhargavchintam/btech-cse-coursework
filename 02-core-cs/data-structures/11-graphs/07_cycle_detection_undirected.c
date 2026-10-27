// detect a cycle in an undirected graph using dfs
#include<stdio.h>

int a[20][20], n, visited[20];

int dfs(int v, int parent)
{
    int i;
    visited[v] = 1;
    for (i = 0; i < n; i++)
    {
        if (a[v][i])
        {
            if (!visited[i])
            {
                if (dfs(i, v))
                    return 1;
            }
            else if (i != parent)   // visited and not the node we came from = back edge
                return 1;
        }
    }
    return 0;
}

int main()
{
    int i, j, cycle = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++)
        if (!visited[i])
            if (dfs(i, -1))
            {
                cycle = 1;
                break;
            }

    if (cycle)
        printf("Graph contains a cycle\n");
    else
        printf("No cycle\n");
    return 0;
}
