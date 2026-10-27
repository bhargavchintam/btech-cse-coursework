#include<stdio.h>

int main()
{
    int a = 10, b = 20;

    const int *p = &a;
    p = &b;

    int * const q = &a;
    *q = 50;

    // *p = 5 wont compile (p points to a const int), q = &b wont compile (q itself is const)
    printf("%d %d\n", *p, *q);
    return 0;
}
