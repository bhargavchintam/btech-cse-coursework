#include<stdio.h>
int main()
{
    int n = 2147483647;
    printf("n = %d\n", n);
    n = n + 1;
    printf("n + 1 = %d\n", n);   // why is it negative
    return 0;
}
