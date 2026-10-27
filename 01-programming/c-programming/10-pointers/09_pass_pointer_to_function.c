#include<stdio.h>

void increment(int *p)
{
    *p = *p + 1;
}

int main()
{
    int n = 10;
    increment(&n);
    printf("n = %d\n", n);
    return 0;
}
