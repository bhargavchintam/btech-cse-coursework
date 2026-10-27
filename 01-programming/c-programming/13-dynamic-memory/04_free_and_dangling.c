#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p;
    p = (int *)malloc(5 * sizeof(int));

    p[0] = 100;
    printf("p[0] = %d\n", p[0]);

    free(p);
    p = NULL;   // so p no longer points to freed memory

    if(p == NULL)
        printf("pointer is NULL now, no dangling\n");

    return 0;
}
