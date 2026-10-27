// calloc initialises the allocated memory to zero
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p;
    int i, n;

    printf("Enter n : ");
    scanf("%d", &n);

    p = (int *)calloc(n, sizeof(int));

    printf("Values after calloc : ");
    for(i = 0; i < n; i++)
        printf("%d ", p[i]);
    printf("\n");

    free(p);
    return 0;
}
