/* Lab Program 11
   Represent a graph using an adjacency matrix and perform BFS and DFS
   traversals from a given source vertex. */

#include<stdio.h>

int adj[20][20];
int visited[20];
int n;

void bfs(int start)
{
    int queue[20], front = 0, rear = 0;
    int i, v;
    for (i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;
    printf("BFS: ");
    while (front < rear) {
        v = queue[front++];
        printf("%d ", v);
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void dfs(int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter start vertex: ");
    scanf("%d", &start);

    bfs(start);

    for (i = 0; i < n; i++)
        visited[i] = 0;
    printf("DFS: ");
    dfs(start);
    printf("\n");

    return 0;
}
