// pointer basics
#include<stdio.h>

int main()
{
    int n = 25;
    int *p;
    p = &n;
    printf("Value of n = %d\n", n);
    printf("Address of n = %p\n", (void*)&n);
    printf("Value in p = %p\n", (void*)p);
    printf("Value pointed by p = %d\n", *p);
    return 0;
}
