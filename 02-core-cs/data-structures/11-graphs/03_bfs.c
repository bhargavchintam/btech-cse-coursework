// bfs traversal using a queue
#include<stdio.h>

int a[20][20], n, visited[20];

void bfs(int start)
{
    int queue[20], front = 0, rear = 0, i, v;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        v = queue[front++];
        printf("%d ", v);
        for (i = 0; i < n; i++)
            if (a[v][i] && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
    }
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

    printf("BFS: ");
    bfs(s);
    printf("\n");
    return 0;
}
