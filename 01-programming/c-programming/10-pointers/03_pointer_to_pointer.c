// pointer to pointer
#include<stdio.h>

int main()
{
    int n = 10;
    int *p;
    int **pp;
    p = &n;
    pp = &p;
    printf("n = %d\n", n);
    printf("*p = %d\n", *p);
    printf("**pp = %d\n", **pp);
    return 0;
}
