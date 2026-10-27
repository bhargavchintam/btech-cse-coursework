// check if a graph is bipartite by 2-colouring (bfs)
#include<stdio.h>

int a[20][20], n, color[20];

int bipartite(int start)
{
    int queue[20], front = 0, rear = 0, i, v;
    color[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        v = queue[front++];
        for (i = 0; i < n; i++)
        {
            if (a[v][i])
            {
                if (color[i] == 0)
                {
                    color[i] = -color[v];   // opposite colour
                    queue[rear++] = i;
                }
                else if (color[i] == color[v])
                    return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int i, j, ok = 1;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++)
        if (color[i] == 0)
            if (!bipartite(i))
            {
                ok = 0;
                break;
            }

    if (ok)
        printf("Graph is bipartite\n");
    else
        printf("Graph is not bipartite\n");
    return 0;
}
