// allocate memory for n integers using malloc
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p;
    int i, n;

    printf("Enter n : ");
    scanf("%d", &n);

    p = (int *)malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
        p[i] = i + 1;

    printf("Array : ");
    for(i = 0; i < n; i++)
        printf("%d ", p[i]);
    printf("\n");

    free(p);
    return 0;
}
