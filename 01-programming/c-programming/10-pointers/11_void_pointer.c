// void pointer can hold any address
#include<stdio.h>

int main()
{
    int n = 10;
    float f = 3.5;
    void *p;
    p = &n;
    printf("n = %d\n", *(int*)p);
    p = &f;
    printf("f = %f\n", *(float*)p);
    return 0;
}
