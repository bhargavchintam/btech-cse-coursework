#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p;
    int i, n, sum = 0;

    printf("Enter n : ");
    scanf("%d", &n);

    p = (int *)malloc(n * sizeof(int));

    printf("Enter %d elements : ", n);
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);

    for(i = 0; i < n; i++)
        sum += p[i];

    printf("Sum = %d\n", sum);

    free(p);
    return 0;
}
