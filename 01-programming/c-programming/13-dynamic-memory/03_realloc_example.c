#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p;
    int i, n, m;

    printf("Enter initial size : ");
    scanf("%d", &n);

    p = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
        p[i] = i + 1;

    printf("Enter new size : ");
    scanf("%d", &m);

    p = (int *)realloc(p, m * sizeof(int));
    for(i = n; i < m; i++)
        p[i] = i + 1;

    printf("Array : ");
    for(i = 0; i < m; i++)
        printf("%d ", p[i]);
    printf("\n");

    free(p);
    return 0;
}
