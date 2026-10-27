// is there a path between two vertices - bfs
#include<stdio.h>

int a[20][20], n, visited[20];

int reachable(int src, int dest)
{
    int queue[20], front = 0, rear = 0, i, v;
    visited[src] = 1;
    queue[rear++] = src;

    while (front < rear)
    {
        v = queue[front++];
        if (v == dest)
            return 1;
        for (i = 0; i < n; i++)
            if (a[v][i] && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
    }
    return 0;
}

int main()
{
    int i, j, s, d;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter source and destination: ");
    scanf("%d %d", &s, &d);

    if (reachable(s, d))
        printf("Path exists between %d and %d\n", s, d);
    else
        printf("No path between %d and %d\n", s, d);
    return 0;
}
