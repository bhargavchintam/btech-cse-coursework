// topological sort of a DAG - Kahn's algorithm
#include<stdio.h>

int main()
{
    int a[20][20], n, i, j, indeg[20] = {0};
    int queue[20], front = 0, rear = 0;
    int order[20], k = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (directed)\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j])
                indeg[j]++;
        }

    for (i = 0; i < n; i++)
        if (indeg[i] == 0)
            queue[rear++] = i;

    while (front < rear)
    {
        int v = queue[front++];
        order[k++] = v;
        for (i = 0; i < n; i++)
            if (a[v][i] && --indeg[i] == 0)
                queue[rear++] = i;
    }

    if (k != n)
    {
        printf("Graph has a cycle, no topological order\n");
        return 0;
    }

    printf("Topological order: ");
    for (i = 0; i < n; i++)
        printf("%d ", order[i]);
    printf("\n");
    return 0;
}
