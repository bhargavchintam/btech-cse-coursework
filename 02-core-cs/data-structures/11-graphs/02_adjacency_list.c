// graph as adjacency list
#include<stdio.h>
#include<stdlib.h>

struct node {
    int vertex;
    struct node *next;
};

int main()
{
    struct node *adj[20] = {NULL};
    int n, e, i, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter edges (u v)\n");
    for (i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);
        struct node *p = malloc(sizeof(struct node));
        p->vertex = v;
        p->next = adj[u];
        adj[u] = p;

        struct node *q = malloc(sizeof(struct node));
        q->vertex = u;
        q->next = adj[v];
        adj[v] = q;
    }

    printf("Adjacency list\n");
    for (i = 0; i < n; i++)
    {
        printf("%d -> ", i);
        struct node *t = adj[i];
        while (t != NULL)
        {
            printf("%d ", t->vertex);
            t = t->next;
        }
        printf("\n");
    }
    return 0;
}
