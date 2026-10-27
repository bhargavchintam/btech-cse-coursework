// dfs traversal using an explicit stack
#include<stdio.h>

int a[20][20], n;

void dfs(int start)
{
    int stack[20], top = -1, visited[20] = {0}, i, v;
    stack[++top] = start;

    while (top >= 0)
    {
        v = stack[top--];
        if (visited[v])
            continue;
        visited[v] = 1;
        printf("%d ", v);

        // push neighbours in reverse so the smaller index comes out first
        for (i = n - 1; i >= 0; i--)
            if (a[v][i] && !visited[i])
                stack[++top] = i;
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

    printf("DFS: ");
    dfs(s);
    printf("\n");
    return 0;
}
